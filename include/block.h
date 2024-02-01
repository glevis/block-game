#pragma once

typedef enum {
    dirt = 0,
    grass = 1
}block_type_t;

struct block_t {
    block_type_t type;
    float vertices[180];
};

void block_init(struct block_t *block, 
                block_type_t type);
