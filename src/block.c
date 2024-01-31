#include "../include/block.h"

void block_init(struct block_t *block, 
                block_type_t type,
                char *texture_side_path,
                char *texture_top_path,
                char *texture_bottom_path) {

    block->texture_side_path = texture_side_path;
    block->texture_top_path = texture_top_path;
    block->texture_bottom_path = texture_bottom_path;

}
