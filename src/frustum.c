#include "../include/frustum.h"
#include "../include/plane.h"
#include "../include/camera.h"
#include <math.h>

void create_frustum_from_camera(camera_t *camera, float aspect, float fovY, float zNear, float zFar, frustum_t *frustum) {
    const float halfVSide = zFar * tanf(fovY * .5f);
    const float halfHSide = halfVSide * aspect;

    vec3 frontMultFar;
    vec3 frontMultNear;

    glm_vec3_scale(camera->front, zFar, frontMultFar);
    glm_vec3_scale(camera->front, zNear, frontMultNear);

    vec3 p1;

    glm_vec3_normalize_to(camera->front, frustum->near_face.normal);
    glm_vec3_copy(camera->position, p1);
    glm_vec3_add(p1, frontMultNear, p1);
    frustum->near_face.distance = glm_vec3_dot(frustum->near_face.normal, p1);

    glm_vec3_negate_to(camera->front, frustum->far_face.normal);
    glm_vec3_normalize(frustum->far_face.normal);
    glm_vec3_copy(camera->position, p1);
    glm_vec3_add(p1, frontMultFar, p1);
    frustum->far_face.distance = glm_vec3_dot(frustum->far_face.normal, p1);

    vec3 lhs;
    vec3 rhs;

    glm_vec3_copy(frontMultFar, lhs);
    glm_vec3_copy(camera->right, rhs);
    glm_vec3_scale(rhs, halfHSide, rhs);
    glm_vec3_sub(lhs, rhs, lhs);
    glm_vec3_copy(camera->up, rhs);
    glm_vec3_crossn(lhs, rhs, frustum->right_face.normal);

    frustum->right_face.distance = glm_vec3_dot(frustum->right_face.normal, camera->position);

    glm_vec3_copy(camera->up, lhs);
    glm_vec3_copy(camera->right, rhs);
    glm_vec3_scale(rhs, halfHSide, rhs);
    glm_vec3_add(frontMultFar, rhs, rhs);
    glm_vec3_crossn(lhs, rhs, frustum->left_face.normal);

    frustum->left_face.distance = glm_vec3_dot(frustum->left_face.normal, camera->position);

    glm_vec3_copy(frontMultFar, lhs);
    glm_vec3_copy(camera->up, rhs);
    glm_vec3_scale(rhs, halfVSide, rhs);
    glm_vec3_sub(lhs, rhs, rhs);
    glm_vec3_copy(camera->right, lhs);
    glm_vec3_crossn(lhs, rhs, frustum->top_face.normal);

    frustum->top_face.distance = glm_vec3_dot(frustum->top_face.normal, camera->position);

    glm_vec3_copy(camera->up, lhs);
    glm_vec3_scale(lhs, halfVSide, lhs);
    glm_vec3_add(frontMultFar, lhs, lhs);
    glm_vec3_copy(camera->right, rhs);
    glm_vec3_crossn(lhs, rhs, frustum->bot_face.normal);

    frustum->bot_face.distance = glm_vec3_dot(frustum->bot_face.normal, camera->position);
}

