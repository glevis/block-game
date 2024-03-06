#pragma once
#include "../extern/cglm/include/cglm/cglm.h"

struct plane_t {
    vec3 normal;

    float distance;
} typedef plane_t;

inline void plane_init(plane_t *plane) {
    vec3 normal = { 0.f, 1.f, 0.f};
    glm_vec3_copy(normal, plane->normal);
}
