#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/sa/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript fast64_sa_loads[] = {
	LOAD_MODEL_FROM_GEO(MODEL_SA_SQUARE_FLOATING_PLATFORM, sa_square_floating_platform_geo), 
	RETURN(), 
};

const LevelScript level_sa_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _storm_floor_skybox_mio0SegmentRomStart, _storm_floor_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group4_mio0SegmentRomStart, _group4_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(fast64_sa_loads), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sa_area_1),
		WARP_NODE(0x0A, LEVEL_SA, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x27, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x28, WARP_NO_CHECKPOINT),
		MARIO_POS(1, 90, 0, -1535, 0),
		OBJECT(MODEL_NONE, 0, -4250, 0, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_SA_SQUARE_FLOATING_PLATFORM, 0, -3128, 2250, 0, 0, 0, (55 << 16), bhvSaSquareFloatingPlatform),
		OBJECT(MODEL_SA_SQUARE_FLOATING_PLATFORM, -2250, -3128, 0, 0, 0, 0, (55 << 16), bhvSaSquareFloatingPlatform),
		OBJECT(MODEL_SA_SQUARE_FLOATING_PLATFORM, 0, -3128, -2250, 0, 0, 0, (55 << 16), bhvSaSquareFloatingPlatform),
		OBJECT(MODEL_SA_SQUARE_FLOATING_PLATFORM, 2250, -3128, 0, 0, 0, 0, (55 << 16), bhvSaSquareFloatingPlatform),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 0, 0, (55 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 0, 0, (1 << 24) | (50 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 0, 0, (40 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 0, 0, (1 << 24) | (30 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 0, 0, (20 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 0, 0, (1 << 24) | (55 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 0, 0, (50 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 0, 0, (1 << 24) | (40 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 0, 0, (30 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 0, 0, (1 << 24) | (20 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 120, 0, (55 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 120, 0, (1 << 24) | (50 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 120, 0, (40 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 120, 0, (1 << 24) | (30 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, 120, 0, (20 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 120, 0, (1 << 24) | (55 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 120, 0, (50 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 120, 0, (1 << 24) | (40 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 120, 0, (30 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, 120, 0, (1 << 24) | (20 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, -120, 0, (55 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, -120, 0, (1 << 24) | (50 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, -120, 0, (40 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, -120, 0, (1 << 24) | (30 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -3617, 0, 0, -120, 0, (20 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, -120, 0, (1 << 24) | (55 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, -120, 0, (50 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, -120, 0, (1 << 24) | (40 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, -120, 0, (30 << 16), bhvSaSushiShark),
		OBJECT(MODEL_SUSHI, 0, -4112, 0, 0, -120, 0, (1 << 24) | (20 << 16), bhvSaSushiShark),
		OBJECT(MODEL_NONE, 0, -1535, 0, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(sa_area_1_collision),
		MACRO_OBJECTS(sa_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x0000, SEQ_LEVEL_DDD),
		TERRAIN_TYPE(TERRAIN_WATER),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 90, 0, -1535, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};