#ifndef TWOC_VERTEX_ARRAY_H
#define TWOC_VERTEX_ARRAY_H

#include "core/api.h"
#include "vertex_buffer.h"
#include "index_buffer.h"

typedef struct {
    unsigned int id;
    twoc_vertex_buffer_t *vertex_buffer;
    twoc_index_buffer_t *index_buffer;
} twoc_vertex_array_t;

TWOC_API twoc_vertex_array_t *twoc_create_vertex_array();

TWOC_API void twoc_destroy_vertex_array(twoc_vertex_array_t *vertex_array);

TWOC_API void twoc_bind_vertex_array(twoc_vertex_array_t *vertex_array);

TWOC_API void twoc_unbind_vertex_array();

TWOC_API void twoc_add_vertex_buffer_to_vertex_array(
    twoc_vertex_array_t *vertex_array, twoc_vertex_buffer_t *vertex_buffer
);

TWOC_API void twoc_add_index_buffer_to_vertex_array(
    twoc_vertex_array_t *vertex_array, twoc_index_buffer_t *index_buffer
);

#endif // TWOC_VERTEX_ARRAY_H
