#pragma once
#include "../extern/cglm/include/cglm/cglm.h"
#include "../include/glad/gl.h"

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
} typedef camera_t;

enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
} typedef CAMERA_MOVEMENT;

void camera_init(camera_t *camera, vec3 position, vec3 world_up, float yaw, float pitch);
void camera_scalar_init(camera_t *camera, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
void camera_get_view_matrix(camera_t *camera, mat4 *dest);
void update_camera_vectors(camera_t *camera);

void process_keyboard(camera_t *camera, CAMERA_MOVEMENT direction, float delta_time);
void process_mouse_movement(camera_t *camera, float xoffset, float yoffset, GLboolean constrainPitch);
