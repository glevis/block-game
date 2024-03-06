#include "../include/block.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../extern/cglm/include/cglm/cglm.h"

static const float vertices[40] = { 
    -0.5f, 0.5f, 0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, 0.5f, 0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, -0.5f, 0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
    -0.5f, -0.5f, 0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
    -0.5f, 0.5f, -0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, 0.5f, -0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 1.0f) / 32.0,
    0.5f, -0.5f, -0.5f, ((620 % 32) + 0.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
    -0.5f, -0.5f, -0.5f, ((620 % 32) + 1.0f) / 32.0, ((672 / 32.0) + 0.0f) / 32.0,
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
    4, 5, 1,
    4, 1, 0,
    7, 2, 6,
    7, 3, 2
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

    memcpy(block->vertices, vertices, 40 * sizeof(float));
    memcpy(block->indices, indices, 36 * sizeof(unsigned int));
    /*
    block->textures[0] = ((620 % 32) + 0.0f) / 32.0;
    block->textures[1] = ((672 / 32.0) + 1.0f) / 32.0;

    block->textures[2] = ((620 % 32) + 1.0f) / 32.0;
    block->textures[3] = ((672 / 32.0) + 1.0f) / 32.0;

    block->textures[4] = ((620 % 32) + 1.0f) / 32.0;
    block->textures[5] = ((672 / 32.0) + 0.0f) / 32.0;

    block->textures[7] = ((620 % 32) + 0.0f) / 32.0;
    block->textures[8] = ((672 / 32.0) + 0.0f) / 32.0;

    block->textures[9] = ((620 % 32) + 1.0f) / 32.0;
    block->textures[10] = ((672 / 32.0) + 1.0f) / 32.0;

    block->textures[11] = ((620 % 32) + 0.0f) / 32.0;
    block->textures[12] = ((672 / 32.0) + 1.0f) / 32.0;

    block->textures[13] = ((620 % 32) + 0.0f) / 32.0;
    block->textures[14] = ((672 / 32.0) + 0.0f) / 32.0;

    block->textures[15] = ((620 % 32) + 1.0f) / 32.0;
    block->textures[16] = ((672 / 32.0) + 0.0f) / 32.0;

    */

    /*
    block->vertices[153] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[154] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[158] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[159] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[163] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[164] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[168] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[169] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[173] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[174] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[178] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[179] = ((672 / 32.0) + 0.0f) / 32.0;


    block->vertices[120] = -0.5f;                             //bottom
    block->vertices[121] = -0.5f; 
    block->vertices[122] = -0.5f; 
    block->vertices[123] = ((616 % 32) + 0.0f) / 32.0;
    block->vertices[124] = ((800 / 32.0) + 0.0f) / 32.0;
    block->vertices[125] = 0.5f; 
    block->vertices[126] = -0.5f; 
    block->vertices[127] = -0.5f; 
    block->vertices[128] = ((616 % 32) + 1.0f) / 32.0;
    block->vertices[129] = ((800 / 32.0) + 0.0f) / 32.0;
    block->vertices[130] = 0.5f; 
    block->vertices[131] = -0.5f; 
    block->vertices[132] = 0.5f; 
    block->vertices[133] = ((616 % 32) + 1.0f) / 32.0;
    block->vertices[134] = ((800 / 32.0) + 1.0f) / 32.0;
    block->vertices[135] = 0.5f; 
    block->vertices[136] = -0.5f; 
    block->vertices[137] = 0.5f; 
    block->vertices[138] = ((616 % 32) + 1.0f) / 32.0;
    block->vertices[139] = ((800 / 32.0) + 1.0f) / 32.0;
    block->vertices[140] = -0.5f; 
    block->vertices[141] = -0.5f; 
    block->vertices[142] = 0.5f; 
    block->vertices[143] = ((616 % 32) + 0.0f) / 32.0;
    block->vertices[144] = ((800 / 32.0) + 1.0f) / 32.0;
    block->vertices[145] = -0.5f; 
    block->vertices[146] = -0.5f; 
    block->vertices[147] = -0.5f; 
    block->vertices[148] = ((616 % 32) + 0.0f) / 32.0;
    block->vertices[149] = ((800 / 32.0) + 0.0f) / 32.0;

    block->vertices[153] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[154] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[158] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[159] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[163] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[164] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[168] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[169] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[173] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[174] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[178] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[179] = ((672 / 32.0) + 0.0f) / 32.0;
    */

    printf("block initialized\n");
}

bool block_is_on_frustum(vec3 pos, block_t *block) {

    return true;
}
