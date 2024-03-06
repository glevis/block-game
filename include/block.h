#pragma once
#include "../extern/cglm/include/cglm/cglm.h"

typedef enum {
    dirt = 0,
    grass = 1
}block_type_t;

struct block_t {
    block_type_t type;
    vec3 center;

    float extent;

    //move to blockmesh
    float vertices[40];
    unsigned int indices[36];
    float textures[16];
    

}typedef block_t;

void block_init(struct block_t *block, 
                block_type_t type);

bool block_is_on_frustum(vec3 pos, block_t *block);
