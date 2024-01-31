enum {
    dirt = 0,
    grass = 1
}typedef block_type_t;

struct block_t {
    block_type_t type;
    char *texture_side_path;
    char *texture_top_path;
    char *texture_bottom_path;
};

void block_init(struct block_t *block, 
                block_type_t type,
                char *texture_side_path,
                char *texture_top_path,
                char *texture_bottom_path);
