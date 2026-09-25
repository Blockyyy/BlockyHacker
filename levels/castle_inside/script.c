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
#include "levels/castle_inside/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0x05, _group10_mio0SegmentRomStart, _group10_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_TRAP, metal_trap_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP, castle_fake_floor_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND, castle_geo_001530), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND, castle_geo_001548), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM, castle_geo_001518), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_inside_area_1),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x03, WARP_NO_CHECKPOINT),
		WARP_NODE(0x00, LEVEL_BITDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, -180, 7, -486, 1502),
		OBJECT(MODEL_CASTLE_STAR_DOOR_8_STARS, -935, 512, -1067, 0, 45, 0, (8 << 16), bhvStarDoor),
		OBJECT(MODEL_CASTLE_STAR_DOOR_8_STARS, -826, 512, -1176, 0, -135, 0, (8 << 16), bhvStarDoor),
		OBJECT(MODEL_NONE, -3686, -885, 897, 0, -54, 0, 0x00000000, bhvBubbleParticleSpawner),
		OBJECT(MODEL_NONE, -5196, -1252, 1633, 0, -54, 0, 0x00000000, bhvBubbleParticleSpawner),
		OBJECT(MODEL_NONE, -4253, -1042, 312, 0, -54, 0, 0x00000000, bhvBubbleParticleSpawner),
		OBJECT(MODEL_BUTTERFLY, -4664, -695, 3185, 0, -177, 0, 0x00000000, bhvTripletButterfly),
		OBJECT(MODEL_BUTTERFLY, -4567, -695, -1097, 0, -177, 0, 0x00000000, bhvTripletButterfly),
		OBJECT(MODEL_BUTTERFLY, -5264, -695, -1272, 0, -177, 0, 0x00000000, bhvTripletButterfly),
		OBJECT(MODEL_BUTTERFLY, -5195, -695, 3352, 0, -177, 0, 0x00000000, bhvTripletButterfly),
		OBJECT(MODEL_YELLOW_COIN, -307, -74, 594, 0, 3, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 326, -74, 594, 0, 3, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_CASTLE_DOOR_0_STARS, 2106, 0, 951, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_DOOR_1_STAR, -1272, -588, 2303, 0, -180, 0, (1 << 16), bhvDoor),
		OBJECT(MODEL_CASTLE_DOOR_1_STAR, 858, 512, -1085, 0, -45, 0, (1 << 16), bhvDoor),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, -1272, -588, 1160, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, 1287, -588, 1160, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, 15, -1063, -4014, 0, 0, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_CASTLE_DOOR_3_STARS, 1286, -588, 2303, 0, -180, 0, (3 << 16), bhvDoor),
		OBJECT(MODEL_CASTLE_DOOR_3_STARS, -2090, 0, 951, 0, 90, 0, (3 << 16), bhvDoor),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, -64, -486, 1691, 0, 0, 0, (8 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_CASTLE_DOOR, 90, -486, 1691, 0, -180, 0, (8 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_BOWSER_TRAP, -3270, 307, -4016, 0, -45, 0, (25 << 24) | (0 << 16), bhvCastleFloorTrap),
		OBJECT(MODEL_FISH, -5111, -718, 946, 0, -177, 0, 0x00000000, bhvBlueFish),
		OBJECT(MODEL_FISH, -4277, -847, 1605, 0, -103, 0, 0x00000000, bhvBlueFish),
		OBJECT(MODEL_FISH, -4586, -777, 314, 0, -72, 0, 0x00000000, bhvBlueFish),
		OBJECT(MODEL_FISH, -3956, -588, 248, 0, -78, 0, 0x00000000, bhvBlueFish),
		OBJECT(MODEL_FISH, -3686, -796, 897, 0, -54, 0, 0x00000000, bhvBlueFish),
		OBJECT(MODEL_RED_FLAME, 2747, 484, 1608, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 3600, 484, 1608, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 2747, 484, -366, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 3600, 484, -366, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1740, -351, 3011, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 838, -351, 3011, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -734, -351, 3011, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1810, -351, 3011, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 325, 37, 1580, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1994, 452, 646, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1521, 717, -277, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1512, 718, -285, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -2001, 454, 646, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_RED_FLAME, -326, 37, 1580, 0, -180, 0, (8 << 16), bhvFlame),
		OBJECT(MODEL_TOAD, 498, 512, -1288, 0, -29, 0, 0x00000000, bhvToadMessage),
		OBJECT(MODEL_TOAD, 169, -486, 1564, 0, -177, 0, 0x00000000, bhvToadMessage),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -4182, -780, -946, 0, -177, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -5251, -780, -1563, 0, -177, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -5102, -859, 2969, 0, -177, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -4172, -859, 3405, 0, -177, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_KEY_DOOR, -70, 512, -1990, 0, 0, 0, (8 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_KEY_DOOR, 84, 512, -1990, 0, -180, 0, (8 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_KEY_DOOR, -62, -1780, 1948, 0, 0, 0, (8 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_KEY_DOOR, 92, -1780, 1948, 0, -180, 0, (8 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -3732, 1537, -3996, 0, 0, 0, (25 << 24), bhvWarp),
		TERRAIN(castle_inside_area_1_collision),
		ROOMS(castle_inside_area_1_collision_rooms),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x0001, SEQ_LEVEL_FELL_CASTLE),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 7, -486, 1502),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};