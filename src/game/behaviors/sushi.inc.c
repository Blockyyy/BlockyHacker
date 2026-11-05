// sushi.inc.c

void bhv_sushi_shark_loop(void) {
    f32 waterLevel = find_water_level(o->oPosX, o->oPosZ);

    o->oPosX = o->oHomeX + sins(o->oSushiSharkAngleFromHome) * 1700.0f;
    o->oPosZ = o->oHomeZ + coss(o->oSushiSharkAngleFromHome) * 1700.0f;
    o->oPosY = waterLevel + o->oHomeY + sins(o->oSushiSharkAngleFromHome) * 200.0f;

    o->oMoveAngleYaw = o->oSushiSharkAngleFromHome + 0x4000;
    o->oSushiSharkAngleFromHome += 0x80;

    if (gMarioObject->oPosY - waterLevel > -500.0f) {
        if (o->oPosY - waterLevel > -200.0f) {
            spawn_object_with_scale(o, MODEL_WAVE_TRAIL, bhvObjectWaveTrail, 4.0f);
        }
    }
    if (!(o->oTimer & 0x0F)) {
        cur_obj_play_sound_2(SOUND_OBJ_SUSHI_SHARK_WATER_SOUND);
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

//thanks Peachy
void bhv_sa_sushi_shark_loop(void) {
    f32 halfSquareSide = o->oBehParams2ndByte * 50.0f;
    f32 edgeSize = 1000.0f;

    f32 xPrev = o->oPosX;
    f32 zPrev = o->oPosZ;
    f32 radius = halfSquareSide * 1.414f;
    f32 edgeDisplacement = (halfSquareSide - edgeSize);

    o->oPosX = o->oHomeX + sins(o->oSushiSharkAngleFromHome) * radius;
    o->oPosZ = o->oHomeZ + coss(o->oSushiSharkAngleFromHome) * radius;
    o->oPosX = CLAMP(o->oPosX, o->oHomeX - halfSquareSide, o->oHomeX + halfSquareSide);
    o->oPosZ = CLAMP(o->oPosZ, o->oHomeZ - halfSquareSide, o->oHomeZ + halfSquareSide);

    if ((o->oPosX > o->oHomeX + edgeDisplacement || o->oPosX < o->oHomeX - edgeDisplacement)
        && (o->oPosZ > o->oHomeZ + edgeDisplacement || o->oPosZ < o->oHomeZ - edgeDisplacement)) {
        f32 length = edgeDisplacement * 1.414f;
        s16 quadrantAngle = ((u16)o->oSushiSharkAngleFromHome / DEGREES(90)) * DEGREES(90) + DEGREES(45);
        f32 px = o->oHomeX + length * sins(quadrantAngle);
        f32 pz = o->oHomeZ + length * coss(quadrantAngle);
        Vec3f d = {o->oPosX - px, 0, o->oPosZ - pz};
        vec3f_normalize(d);
        o->oPosX = d[0] * edgeSize + px;
        o->oPosZ = d[2] * edgeSize + pz;
    }

    o->oPosY = o->oHomeY + sins(o->oSushiSharkAngleFromHome * 1.5f) * 400.0f;

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, atan2s(o->oPosZ - zPrev, o->oPosX - xPrev), DEGREES(5));
    if ((o->oBehParams >> 24) & 0xFF) {
        o->oSushiSharkAngleFromHome -= 0x80;
    } else {
        o->oSushiSharkAngleFromHome += 0x80;
    }

    if (!(o->oTimer & 0x0F)) {
        cur_obj_play_sound_2(SOUND_OBJ_SUSHI_SHARK_WATER_SOUND);
    }

    o->oInteractStatus = INT_STATUS_NONE;
}
