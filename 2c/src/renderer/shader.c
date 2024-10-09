#include "pch.h"

#include "renderer/shader.h"

#include "core/assert.h"

#include <glad/gl.h>

typedef enum {
    SHADER,
    PROGRAM
} error_check_type_t;

void check_for_errors(unsigned int id, error_check_type_t error_check_type) {
    GLint success;
    if (error_check_type == SHADER) {
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE) {
            GLsizei message_length = 0;
            GLchar message[1024];
            glGetShaderInfoLog(id, 1024, &message_length, message);
            fprintf(stderr, "shader compilation error: %s", message);
        }
    } else {
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (success == GL_FALSE) {
            GLsizei message_length = 0;
            GLchar message[1024];
            glGetProgramInfoLog(id, 1024, &message_length, message);
            fprintf(stderr, "program linking error: %s", message);
        }
    }
}

void compile_shaders(unsigned int *id, const char *vertex_shader_source, const char *fragment_shader_source) {
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    check_for_errors(vertex_shader, SHADER);

    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    check_for_errors(vertex_shader, SHADER);

    *id = glCreateProgram();
    glAttachShader(*id, vertex_shader);
    glAttachShader(*id, fragment_shader);
    glLinkProgram(*id);
    check_for_errors(*id, PROGRAM);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

twoc_shader_t *twoc_create_shader(const char *vertex_shader_source, const char *fragment_shader_source) {
    twoc_shader_t *shader = malloc(sizeof(twoc_shader_t));
    shader->id = 0;

    compile_shaders(&shader->id, vertex_shader_source, fragment_shader_source);

    return shader;
}

void twoc_destroy_shader(twoc_shader_t *shader) {
    glDeleteProgram(shader->id);
    free(shader);
}

void twoc_bind_shader(twoc_shader_t *shader) {
    glUseProgram(shader->id);
}

void twoc_unbind_shader() {
    glUseProgram(0);
}
