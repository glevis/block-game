#pragma once
#include "../extern/cglm/include/cglm/cglm.h"

struct {
    vec3 position;
    vec3 front;
    vec3 up;
    vec3 right;
    vec3 world_up;

    float yaw;
    float pitch;

    float move_speed;
    float mouse_sensitivity;
    float zoom;
} typedef Camera;

void camera_init(Camera *camera, vec3 position, vec3 world_up, float yaw, float pitch);
void camera_scalar_init(Camera *camera, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
void camera_get_view_matrix(Camera *camera, mat4 *dest);
