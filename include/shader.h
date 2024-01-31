#ifndef SHADER_H
#define SHADER_H

#include "../include/glad/gl.h"

struct Shader {
    unsigned int ID;
};

void shader_init(const char* vertex_path, const char* fragment_path, struct Shader* shader);
void shader_use(struct Shader *shader);
void shader_set_bool(const char* name, int value, struct Shader* shader);
void shader_set_int(const char* name, int value, struct Shader* shader);
void shader_set_float(const char* name, float value, struct Shader* shader);
void shader_set_mat4(const char* name, const GLfloat *value, struct Shader *shader);
#endif
