// castle_floor_trap.inc.c


//
//void bhv_castle_floor_trap_init(void) {
//    struct Object *floorTrapObj;
//    floorTrapObj = spawn_object_relative(0, -358, 0, 0, o, MODEL_CASTLE_BOWSER_TRAP, bhvFloorTrapInCastle);
//    floorTrapObj = spawn_object_relative(0, 358, 0, 0, o, MODEL_CASTLE_BOWSER_TRAP, bhvFloorTrapInCastle);
//    floorTrapObj->oMoveAngleYaw += 0x8000;
//}
//
//void bhv_castle_floor_trap_open_detect(void) {
//    if (gMarioStates[0].action == ACT_SPECIAL_EXIT_AIRBORNE
//        || gMarioStates[0].action == ACT_SPECIAL_DEATH_EXIT) {
//        o->oAction = 4; // rotates trapdoor so it looks always open
//    } else {
//        o->oAngleVelRoll = 0x400;
//        if (o->oInteractStatus & INT_STATUS_TRAP_TURN) {
//            o->oAction = 1; // detects interact then opens the trapdoor
//        }
//    }
//}
//
//void bhv_castle_floor_trap_open(void) {
//    if (o->oTimer == 0) {
//        cur_obj_play_sound_2(SOUND_GENERAL_CASTLE_TRAP_OPEN);
//    }
//
//    o->oAngleVelRoll -= 0x100;
//    o->oFaceAngleRoll += o->oAngleVelRoll;
//
//    if (o->oFaceAngleRoll < -0x4000) {
//        o->oFaceAngleRoll = -0x4000;
//        o->oAction = 2; // after opening is done, enable close detection
//    }
//}
//
//void bhv_castle_floor_trap_close_detect(void) {
//    if (o->oDistanceToMario > 1000.0f) {
//        o->oAction = 3; // close trapdoor
//    }
//}
//
//void bhv_castle_floor_trap_close(void) {
//    o->oFaceAngleRoll += 0x400;
//
//    if (o->oFaceAngleRoll > 0) {
//        o->oFaceAngleRoll = 0;
//        o->oAction = 0; // after closing, reloads open detection
//        o->oInteractStatus &= ~INT_STATUS_TRAP_TURN;
//    }
//}
//
//void bhv_castle_floor_trap_rotate(void) {
//    o->oFaceAngleRoll = -0x3C00;
//}
//
//void bhv_castle_floor_trap_loop(void) {
//    switch (o->oAction) {
//        case 0:
//            bhv_castle_floor_trap_open_detect();
//            break;
//        case 1:
//            bhv_castle_floor_trap_open();
//            break;
//        case 2:
//            bhv_castle_floor_trap_close_detect();
//            break;
//        case 3:
//            bhv_castle_floor_trap_close();
//            break;
//        case 4:
//            bhv_castle_floor_trap_rotate();
//            break;
//    }
//}

void bhv_castle_floor_trap_init(void) {

}

void bhv_floor_trap_in_castle_loop(void) {
    o->oFloorHeight = find_floor(o->oPosX, o->oPosY - 10, o->oPosZ, &o->oFloor);
    if (o->oAction == 0) {
        o->oVelY -= 5;
        o->oPosY += o->oVelY;
        if (o->oPosY <= o->oFloorHeight) {
            o->oAction++;
            cur_obj_shake_screen(SHAKE_POS_MEDIUM);
            cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_LAND);
        }
    }
}

void launch_mario_into_warp(void) {
    if (gMarioState->action != ACT_VERTICAL_WIND && gMarioState->action != ACT_DISAPPEARED) {
        gMarioState->action = ACT_VERTICAL_WIND;
        play_sound(SOUND_MARIO_HERE_WE_GO, gMarioObject->header.gfx.cameraToObject);
    }

    gMarioState->vel[1] = 50;
    spawn_wind_particles(1, 0);
    play_sound(SOUND_ENV_WIND2, gMarioState->marioObj->header.gfx.cameraToObject);
}

void bhv_castle_floor_trap_loop(void) {
    if (o->oAction == 0 && gMarioState->floor && gMarioState->floor->object == o) {
        o->oAction = 1;
        spawn_object_relative(0, 0, 819, 0, o, MODEL_CASTLE_METAL_TRAP, bhvFloorTrapInCastle);
        cur_obj_play_sound_2(SOUND_GENERAL_STAR_DOOR_CLOSE);
    } else if (o->oAction == 1) {
        if (o->oTimer >= 30 && o->oSubAction == 0) {
            o->oSubAction++;
            o->oTimer = 0;
        } else if (o->oSubAction > 0) {
            f32 scale = 1.0f - ((f32) o->oTimer / 20.0f);
    
            obj_scale_xyz(o, scale, 1.0f, 1.0f);
    
            if (o->oTimer >= 20) {
                cur_obj_hide();
            }

            if (gMarioState->floor && gMarioState->floor->object != o) {
                launch_mario_into_warp();
            }
        }
    }
}