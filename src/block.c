#include "../include/block.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../extern/cglm/include/cglm/cglm.h"

static const float vertices[80] = { 
    -0.5f, 0.5f, 0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, 0.5f, 0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, -0.5f, 0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
    -0.5f, -0.5f, 0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
    -0.5f, 0.5f, -0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, 0.5f, -0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, -0.5f, -0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
    -0.5f, -0.5f, -0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,

    -0.5f, 0.5f, -0.5f, ((623 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, 0.5f, -0.5f, ((623 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, 0.5f, 0.5f, ((623 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
    -0.5f, 0.5f, 0.5f, ((623 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,

    -0.5f, -0.5f, -0.5f, ((616 % 32) + 0.0f) / 32.0, ((800 / 32.0) + 1.0f) / 32.0,
    0.5f, -0.5f, -0.5f, ((616 % 32) + 1.0f) / 32.0, ((800 / 32.0) + 1.0f) / 32.0,
    0.5f, -0.5f, 0.5f, ((616 % 32) + 1.0f) / 32.0, ((800 / 32.0) + 0.0f) / 32.0,
    -0.5f, -0.5f, 0.5f, ((616 % 32) + 0.0f) / 32.0, ((800 / 32.0) + 0.0f) / 32.0,

};

static const unsigned int indices[36] = {
    0, 1, 2,
    0, 2, 3,
    4, 0, 3,
    4, 3, 7,
    5, 4, 7,
    5, 7, 6,
    1, 5, 6,
    1, 6, 2,

    8,9,10,
    8,10,11,
    12,14,13,
    12,15,14,

    /*
    4, 5, 1,
    4, 1, 0,
    7, 2, 6,
    7, 3, 2
    */
};


void block_init(struct block_t *block, block_type_t type) {

    //TODO: Change texture based on block type.
   
    vec3 center = { 0.f, 0.f, 0.f};
    glm_vec3_copy(center, block->center);

    block->extent = 0.f;

    //((32 * (int) type) % 32) + 0.0 / 32.0;
    float side_texture_pos = ((620 % 32) + 0.0) / 32.0;
    float top_texture_pos = ((620 % 32) + 0.0) / 32.0;
    float bot_texture_pos = ((620 % 32) + 0.0) / 32.0;

    if (type != grass) {
        top_texture_pos = side_texture_pos;
        bot_texture_pos = side_texture_pos;
    }

    memcpy(block->vertices, vertices, 80 * sizeof(float));
    memcpy(block->indices, indices, 36 * sizeof(unsigned int));

    printf("block initialized\n");
}

bool block_is_on_frustum(vec3 pos, block_t *block) {

    return true;
}
