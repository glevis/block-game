#include "../include/camera.h"

void camera_init(camera_t *camera, vec3 position, vec3 world_up, float yaw, float pitch) {
    glm_vec3_copy(position, camera->position);
    glm_vec3_copy(world_up, camera->world_up);
    camera->yaw = yaw;
    camera->pitch = pitch;
    update_camera_vectors(camera);
}

void camera_scalar_init(camera_t *camera, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) {
    vec3 position = { posX, posY, posZ };
    vec3 world_up = { upX, upY, upZ };
    glm_vec3_copy(position, camera->position);
    glm_vec3_copy(world_up, camera->world_up);
    camera->yaw = yaw;
    camera->pitch = pitch;
    
    vec3 front = {0.0f, 0.0f, -1.0f};

    glm_vec3_copy(front, camera->front);
    camera->move_speed = 2.5f;
    camera->mouse_sensitivity = 1.0f;
}

void camera_get_view_matrix(camera_t* camera, mat4 *dest) {
    vec3 center;
    mat4 src;
    glm_vec3_add(camera->position, camera->front, center);
    glm_lookat(camera->position, center, camera->up, src);
    glm_mat4_copy(src, dest[0]);
}

void update_camera_vectors(camera_t *camera) {
    float x = cos(glm_rad(camera->yaw)) * cos(glm_rad(camera->pitch));
    float y = sin(glm_rad(camera->pitch));
    float z = sin(glm_rad(camera->yaw)) * cos(glm_rad(camera->pitch));

    vec3 front = {x, y, z};

    glm_vec3_normalize(front);
    glm_vec3_copy(front, camera->front);

    glm_vec3_crossn(camera->front, camera->world_up, camera->right);
    glm_vec3_crossn(camera->right, camera->front, camera->up);
}

void process_keyboard(camera_t *camera, CAMERA_MOVEMENT direction, float delta_time) {
    float velocity = camera->move_speed * delta_time;
    vec3 calc;
    switch(direction) {
        case FORWARD:
            glm_vec3_scale(camera->front, velocity, calc);
            glm_vec3_add(camera->position, calc, camera->position);
            break;
        case BACKWARD:
            glm_vec3_scale(camera->front, velocity, calc);
            glm_vec3_sub(camera->position, calc, camera->position);
            break;
        case LEFT:
            glm_vec3_scale(camera->right, velocity, calc);
            glm_vec3_sub(camera->position, calc, camera->position);
            break;
        case RIGHT:
            glm_vec3_scale(camera->right, velocity, calc);
            glm_vec3_add(camera->position, calc, camera->position);
            break;
    }
}

void process_mouse_movement(camera_t* camera, float xoffset, float yoffset, GLboolean constrainPitch) {
    float xoffset_scaled = xoffset * camera->mouse_sensitivity;
    float yoffset_scaled = yoffset * camera->mouse_sensitivity;

    camera->yaw += xoffset_scaled;
    camera->pitch += yoffset_scaled;

    if(constrainPitch) {
        if(camera->pitch > 89.0f) {
            camera->pitch = 89.0f;
        }
        if(camera->pitch < -89.0f) {
            camera->pitch = -89.0f;
        }
    }

    update_camera_vectors(camera);
}
