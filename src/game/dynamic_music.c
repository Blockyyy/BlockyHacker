#include <PR/ultratypes.h>

#include "sm64.h"
#include "audio/external.h"
#include "game/dynamic_music.h"
#include "audio/seqplayer.h"

#define DYNMUSIC_PLAYER SEQ_PLAYER_LEVEL
#define DYN_NONE (-1)

enum DynRegionId { DYN_REGION_INTRO, DYN_REGION_ENDING, DYN_REGION_MAIN, DYN_REGION_COUNT };

static const struct DynMusicSong *sDynSong = NULL;
static u16 sDynPlayCount = 0;
static s8 sDynUnlocked = DYN_NONE;
static s16 sDynInactiveTimer = 0;
static s16 sDynUnlockTimer = 0;
static f32 sDynChanVolume[16];
static u32 sDynJumpAt = 0;
static u32 sDynJumpTo = 0;
static u8 sDynJumpReady = FALSE;

void dynamic_music_unlock(s32 layer) {
    if (sDynSong == NULL) {
        return;
    }
    if (layer >= sDynSong->layerCount) {
        layer = sDynSong->layerCount - 1;
    }
    if (layer > sDynUnlocked) {
        sDynUnlocked = layer;
        sDynUnlockTimer = 0;
    }
}

void dynamic_music_unlock_next(void) {
    dynamic_music_unlock(sDynUnlocked + 1);
}

void dynamic_music_reset_progress(void) {
    sDynUnlocked = DYN_NONE;
    sDynUnlockTimer = 0;
}

static const struct DynMusicRegion *dynamic_music_region(s32 id) {
    switch (id) {
        case DYN_REGION_INTRO:  return &sDynSong->intro;
        case DYN_REGION_ENDING: return &sDynSong->ending;
        default:                return &sDynSong->main;
    }
}

static u8 dynamic_music_region_exists(const struct DynMusicRegion *reg) {
    return reg->end > reg->start;
}

static s32 dynamic_music_find_region(u32 tatum) {
    s32 i;

    for (i = 0; i < DYN_REGION_COUNT; i++) {
        const struct DynMusicRegion *reg = dynamic_music_region(i);
        if (tatum >= reg->start && tatum < reg->end) {
            return i;
        }
    }
    return DYN_NONE;
}

static const struct DynMusicSong *dynamic_music_find_song(u8 seqId) {
    s32 i;

    for (i = 0; i < gDynMusicSongCount; i++) {
        if (gDynMusicSongs[i].seqId == seqId) {
            return &gDynMusicSongs[i];
        }
    }
    return NULL;
}

static u32 dynamic_music_next_boundary(const struct DynMusicRegion *reg, u32 tatum) {
    u32 phrase = (u32) sDynSong->phraseBeats * DYN_TATUMS_PER_BEAT;
    u32 remaining = reg->end - tatum;

    return reg->end - ((remaining - 1) / phrase) * phrase;
}

static void dynamic_music_schedule(u32 at, u32 to) {
    if (!sDynJumpReady || sDynJumpAt != at || sDynJumpTo != to) {
        seq_player_schedule_jump(DYNMUSIC_PLAYER, at, to);
        sDynJumpAt = at;
        sDynJumpTo = to;
        sDynJumpReady = TRUE;
    }
}

static void dynamic_music_unschedule(void) {
    if (sDynJumpReady) {
        seq_player_cancel_jump(DYNMUSIC_PLAYER);
        sDynJumpReady = FALSE;
    }
}

static void dynamic_music_update_layers(u8 active, u8 instant) {
    f32 step = 1.0f / (sDynSong->fadeFrames > 0 ? sDynSong->fadeFrames : 1);
    s32 layer, ch;

    for (layer = 0; layer < sDynSong->layerCount; layer++) {
        u8 on = (layer <= sDynUnlocked) && (active || !(sDynSong->flags & DYN_SONG_MUTE_WHEN_INACTIVE));
        f32 target = on ? 1.0f : 0.0f;

        for (ch = 0; ch < 16; ch++) {
            f32 vol = sDynChanVolume[ch];

            if (!(sDynSong->layerChannels[layer] & DYN_CH(ch))) {
                continue;
            }
            if (instant) {
                vol = target;
            } else if (vol < target) {
                vol = MIN(vol + step, target);
            } else if (vol > target) {
                vol = MAX(vol - step, target);
            }
            if (instant || vol != sDynChanVolume[ch]) {
                sDynChanVolume[ch] = vol;
                seq_player_set_channel_volume(DYNMUSIC_PLAYER, ch, vol);
            }
        }
    }
}

static u8 dynamic_music_update_trigger(void) {
    u8 active;

    if (sDynSong->isActive != NULL && sDynSong->isActive()) {
        sDynInactiveTimer = 0;
    } else if (sDynInactiveTimer < sDynSong->graceFrames) {
        sDynInactiveTimer++;
    }
    active = (sDynInactiveTimer < sDynSong->graceFrames);

    if (active) {
        if (sDynUnlocked == DYN_NONE && (sDynSong->flags & DYN_SONG_UNLOCK_ON_ACTIVATE)) {
            dynamic_music_unlock(0);
        }
        if (sDynSong->unlockFrames > 0 && sDynUnlocked < sDynSong->layerCount - 1
            && ++sDynUnlockTimer >= sDynSong->unlockFrames) {
            dynamic_music_unlock_next();
        }
    }
    return active;
}

static u8 dynamic_music_pick_jump(s32 cur, u8 active, u8 atEnd, u32 *to) {
    const struct DynMusicRegion *intro = &sDynSong->intro;
    const struct DynMusicRegion *ending = &sDynSong->ending;
    const struct DynMusicRegion *main = &sDynSong->main;

    switch (cur) {
        case DYN_REGION_INTRO:
        case DYN_REGION_ENDING:
            if (active) {
                *to = main->start;
                return TRUE;
            }
            if (atEnd) {
                *to = dynamic_music_region_exists(intro) ? intro->loopTo : main->start;
                return TRUE;
            }
            return FALSE;

        case DYN_REGION_MAIN:
            if (!active && dynamic_music_region_exists(ending)) {
                *to = ending->start;
                return TRUE;
            }
            if (!active && dynamic_music_region_exists(intro)) {
                *to = intro->loopTo;
                return TRUE;
            }
            if (atEnd) {
                *to = main->loopTo;
                return TRUE;
            }
            return FALSE;
    }
    return FALSE;
}

void dynamic_music_update(void) {
    const struct DynMusicSong *song = dynamic_music_find_song(seq_player_get_seq_id(DYNMUSIC_PLAYER));
    u16 playCount = seq_player_get_play_count(DYNMUSIC_PLAYER);
    const struct DynMusicRegion *reg;
    s32 cur;
    u32 tatum, boundary, to;
    u8 active;

    if (song != sDynSong || playCount != sDynPlayCount) {
        sDynSong = song;
        sDynPlayCount = playCount;
        sDynJumpReady = FALSE;
        sDynInactiveTimer = (song != NULL) ? song->graceFrames : 0;
        dynamic_music_reset_progress();
        if (song != NULL) {
            dynamic_music_update_layers(FALSE, TRUE);
        }
    }
    if (sDynSong == NULL) {
        return;
    }

    active = dynamic_music_update_trigger();
    dynamic_music_update_layers(active, FALSE);

    if (sDynJumpReady && !seq_player_jump_pending(DYNMUSIC_PLAYER)) {
        sDynJumpReady = FALSE;
    }

    tatum = seq_player_get_tatum(DYNMUSIC_PLAYER);
    cur = dynamic_music_find_region(tatum);

    if (sDynJumpReady && tatum == sDynJumpAt) {
        return;
    }
    if (cur == DYN_NONE) {
        dynamic_music_unschedule();
        return;
    }
    if ((sDynSong->flags & DYN_SONG_RESET_ON_EXIT) && cur == DYN_REGION_INTRO && !active) {
        dynamic_music_reset_progress();
    }

    reg = dynamic_music_region(cur);
    boundary = dynamic_music_next_boundary(reg, tatum);

    if (!dynamic_music_pick_jump(cur, active, boundary == reg->end, &to) || to == boundary) {
        dynamic_music_unschedule();
    } else {
        dynamic_music_schedule(boundary, to);
    }
}