#ifndef SKYBOX_H
#define SKYBOX_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

Gfx *create_skybox_facing_camera(s8 player, s8 background, f32 fov, Vec3f pos, Vec3f focus);
void skybox_set_flash_alpha(u8 alpha);

#endif // SKYBOX_H
