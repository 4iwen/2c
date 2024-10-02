#ifndef TWOC_VERTEX_BUFFER_H
#define TWOC_VERTEX_BUFFER_H

#include "core/api.h"

typedef enum {
    TWOC_NONE,
    TWOC_FLOAT,
    TWOC_FLOAT2,
    TWOC_FLOAT3,
    TWOC_FLOAT4,
    TWOC_INT,
    TWOC_BOOL,
    TWOC_MAT4
} twoc_vertex_buffer_element_data_type_t;

typedef struct {
    twoc_vertex_buffer_element_data_type_t data_type;
    const char *name;
    bool normalized;
    unsigned long offset;
    unsigned int size;
} twoc_vertex_buffer_element_t;

TWOC_API unsigned int twoc_get_element_component_count(twoc_vertex_buffer_element_t *element);

typedef struct {
    twoc_vertex_buffer_element_t *elements;
    unsigned int element_count;
    unsigned int stride;
} twoc_vertex_buffer_layout_t;

TWOC_API twoc_vertex_buffer_layout_t *twoc_create_vertex_buffer_layout();

TWOC_API void twoc_destroy_vertex_buffer_layout(twoc_vertex_buffer_layout_t *layout);

TWOC_API void twoc_push_vertex_buffer_element(
    twoc_vertex_buffer_layout_t *layout,
    twoc_vertex_buffer_element_data_type_t element_type,
    const char *name,
    bool normalized
);

typedef struct {
    unsigned int id;
    twoc_vertex_buffer_layout_t *layout;
} twoc_vertex_buffer_t;

TWOC_API twoc_vertex_buffer_t *twoc_create_vertex_buffer(void *data, unsigned int size);

TWOC_API void twoc_destroy_vertex_buffer(twoc_vertex_buffer_t *vertex_buffer);

TWOC_API void twoc_bind_vertex_buffer(twoc_vertex_buffer_t *vertex_buffer);

TWOC_API void twoc_unbind_vertex_buffer();

TWOC_API void twoc_set_vertex_buffer_data(void *data, unsigned int size);

TWOC_API void twoc_set_vertex_buffer_layout(twoc_vertex_buffer_t *vertex_buffer, twoc_vertex_buffer_layout_t *layout);

#endif // TWOC_VERTEX_BUFFER_H
