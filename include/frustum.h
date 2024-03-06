#pragma once
#include "plane.h"
#include "camera.h"

struct {
    plane_t top_face;
    plane_t bot_face;

    plane_t right_face;
    plane_t left_face;

    plane_t far_face;
    plane_t near_face;
} typedef frustum_t;

void create_frustum_from_camera(camera_t *camera, float aspect, float fovY, float zNear, float zFar, frustum_t *frustum);
