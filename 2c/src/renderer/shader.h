#ifndef TWOC_SHADER_H
#define TWOC_SHADER_H

#include "core/api.h"

typedef struct {
    unsigned int id;
} twoc_shader_t;

TWOC_API twoc_shader_t *twoc_create_shader(const char *vertex_shader_source, const char *fragment_shader_source);

TWOC_API twoc_shader_t *twoc_create_shader_from_file(const char *vertex_shader_path, const char *fragment_shader_path);

TWOC_API void twoc_destroy_shader(twoc_shader_t *shader);

TWOC_API void twoc_bind_shader(twoc_shader_t *shader);

TWOC_API void twoc_unbind_shader();

#endif // TWOC_SHADER_H
