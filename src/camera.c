#include "../include/camera.h"

void camera_init(Camera *camera, vec3 position, vec3 world_up, float yaw, float pitch) {
    glm_vec3_copy(position, camera->position);
    glm_vec3_copy(world_up, camera->world_up);
    camera->yaw = yaw;
    camera->pitch = pitch;
}

void camera_scalar_init(Camera *camera, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) {
    vec3 position = { posX, posY, posZ };
    vec3 world_up = { upX, upY, upZ };
    glm_vec3_copy(position, camera->position);
    glm_vec3_copy(world_up, camera->world_up);
    camera->yaw = yaw;
    camera->pitch = pitch;
}

void camera_get_view_matrix(Camera* camera, mat4 *dest) {
    glm_lookat(&camera->pitch, camera->position, camera->world_up, dest[0]);
}
