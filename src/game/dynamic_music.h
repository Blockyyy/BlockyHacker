#ifndef DYNAMIC_MUSIC_H
#define DYNAMIC_MUSIC_H

#include <PR/ultratypes.h>

#define DYN_TATUMS_PER_BEAT 48
#define DYN_BAR(n)          ((u32) ((n) - 1) * 4 * DYN_TATUMS_PER_BEAT)
#define DYN_BAR_3_4(n)      ((u32) ((n) - 1) * 3 * DYN_TATUMS_PER_BEAT)
#define DYN_CH(n)           (1 << (n))
#define DYN_NO_REGION       { 0, 0, 0 }

struct DynMusicRegion {
    u32 start;
    u32 end;
    u32 loopTo;
};

#define DYN_SONG_UNLOCK_ON_ACTIVATE (1 << 0)
#define DYN_SONG_RESET_ON_EXIT      (1 << 1)
#define DYN_SONG_MUTE_WHEN_INACTIVE (1 << 2)

struct DynMusicSong {
    u8 seqId;
    u8 flags;
    u8 phraseBeats;
    u8 graceFrames;
    u16 unlockFrames;
    u16 fadeFrames;
    struct DynMusicRegion intro;
    struct DynMusicRegion ending;
    struct DynMusicRegion main;
    const u16 *layerChannels;
    u8 layerCount;
    u8 (*isActive)(void);
};

extern const struct DynMusicSong gDynMusicSongs[];
extern const s32 gDynMusicSongCount;

void dynamic_music_update(void);

void dynamic_music_unlock(s32 layer);
void dynamic_music_unlock_next(void);
void dynamic_music_reset_progress(void);

#endif