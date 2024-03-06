#ifndef SHADER_H
#define SHADER_H

#include "../include/glad/gl.h"

struct shader_t {
    unsigned int ID;
} typedef shader_t;

void shader_init(const char* vertex_path, const char* fragment_path,  shader_t* shader);
void shader_use( shader_t *shader);
void shader_set_bool(const char* name, int value,  shader_t* shader);
void shader_set_int(const char* name, int value,  shader_t* shader);
void shader_set_float(const char* name, float value,  shader_t* shader);
void shader_set_mat4(const char* name, const GLfloat* value, shader_t* shader);
#endif
