#include "../include/shader.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/glad/gl.h"

void shader_init(const char* vertex_path, const char* fragment_path, struct Shader* shader) {
    FILE *v_shader_file;
    FILE *f_shader_file;

    v_shader_file = fopen(vertex_path, "r");
    f_shader_file = fopen(fragment_path, "r");

    if(v_shader_file == NULL){
        printf("The vertex shader file could not be opened\n");
        exit(1);
    }

    printf("%s successfully initialized\n", vertex_path);

    if(f_shader_file == NULL){
        printf("The fragment shader file could not be opened\n");
        exit(1);
    }

    printf("%s successfully initialized\n", fragment_path);

    fseek(v_shader_file, 0, SEEK_END);
    fseek(f_shader_file, 0, SEEK_END);

    long v_fsize = ftell(v_shader_file);
    long f_fsize = ftell(f_shader_file);

    fseek(v_shader_file, 0, SEEK_SET);
    fseek(f_shader_file, 0, SEEK_SET);

    char *v_shader_code = malloc(v_fsize + 1);
    char *f_shader_code = malloc(f_fsize + 1);
    fread(v_shader_code, v_fsize, 1, v_shader_file);
    fread(f_shader_code, f_fsize, 1, f_shader_file);
    fclose(v_shader_file);
    fclose(f_shader_file);

    v_shader_code[v_fsize] = 0;
    f_shader_code[f_fsize] = 0;

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    const char *v_shader_code_p = v_shader_code;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &v_shader_code_p, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %s\n", infoLog);
    }

    const char *f_shader_code_p = f_shader_code;

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &f_shader_code_p, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n %s\n", infoLog);
    }

    shader->ID = glCreateProgram();
    glAttachShader(shader->ID, vertex);
    glAttachShader(shader->ID, fragment);
    glLinkProgram(shader->ID);
    glGetProgramiv(shader->ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader->ID, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n %s\n", infoLog);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

void shader_use(struct Shader *shader) {
    glUseProgram(shader->ID);
}


void shader_set_bool(const char* name, int value, struct Shader *shader) {
    glUniform1i(glGetUniformLocation(shader->ID, name), value);
}

void shader_set_int(const char* name, int value, struct Shader* shader) {
    glUniform1i(glGetUniformLocation(shader->ID, name), value);
}

void shader_set_float(const char* name, float value, struct Shader* shader) {
    glUniform1f(glGetUniformLocation(shader->ID, name), value);
}

void shader_set_mat4(const char* name, const GLfloat *value, struct Shader *shader) {
    glUniformMatrix4fv(glGetUniformLocation(shader->ID, name), 1, GL_FALSE, value);
}
