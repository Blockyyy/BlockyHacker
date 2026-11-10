#include <PR/ultratypes.h>

#include "sm64.h"
#include "seq_ids.h"
#include "game/level_update.h"
#include "game/dynamic_music.h"
#include "game/dynamic_music_songs.h"

static u8 dyn_trigger_mario_underwater(void) {
    struct MarioState *m = gMarioState;

    return (m->action & ACT_GROUP_MASK) == ACT_GROUP_SUBMERGED || m->pos[1] < m->waterLevel - 100;
}

static const u16 sDddLayerChannels[DDD_LAYER_COUNT] = {
    [DDD_PIANO]   = DYN_CH(5),               // Electric Piano
    [DDD_MELODY]  = DYN_CH(6),               // Strings
    [DDD_STRINGS] = DYN_CH(7),               // Strings 2
    [DDD_DRUMS]   = DYN_CH(8)  | DYN_CH(9),  // Bowser Drums, Crash Cymbal
    [DDD_ORGAN]   = DYN_CH(10) | DYN_CH(11), // Church Organ, Bowser Guitar
};

const struct DynMusicSong gDynMusicSongs[] = {
    {
        .seqId         = SEQ_LEVEL_DDD,
        .flags         = DYN_SONG_UNLOCK_ON_ACTIVATE,
        .phraseBeats   = 16,
        .graceFrames   = 45,
        .unlockFrames  = 10 * 30,
        .fadeFrames    = 15,
        .intro         = { DYN_BAR(1),  DYN_BAR(17), DYN_BAR(9)  },
        .ending        = { DYN_BAR(17), DYN_BAR(25), DYN_BAR(17) },
        .main          = { DYN_BAR(25), DYN_BAR(73), DYN_BAR(25) },
        .layerChannels = sDddLayerChannels,
        .layerCount    = DDD_LAYER_COUNT,
        .isActive      = dyn_trigger_mario_underwater,
    },
};

const s32 gDynMusicSongCount = sizeof(gDynMusicSongs) / sizeof(gDynMusicSongs[0]);
