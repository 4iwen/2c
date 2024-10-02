#include "pch.h"

#include "vertex_buffer.h"

#include <core/assert.h>
#include <glad/gl.h>

#include "misc.h"

unsigned int twoc_get_element_component_count(twoc_vertex_buffer_element_t *element) {
    switch (element->data_type) {
        default:
        case TWOC_NONE:
            return 0;
        case TWOC_FLOAT:
        case TWOC_INT:
        case TWOC_BOOL:
            return 1;
        case TWOC_FLOAT2:
            return 2;
        case TWOC_FLOAT3:
            return 3;
        case TWOC_FLOAT4:
            return 4;
        case TWOC_MAT4:
            return 4 * 4;
    }
}

twoc_vertex_buffer_layout_t *twoc_create_vertex_buffer_layout() {
    twoc_vertex_buffer_layout_t *layout = malloc(sizeof(twoc_vertex_buffer_layout_t));
    layout->element_count = 0;
    layout->stride = 0;
    layout->elements = NULL;

    return layout;
}

void twoc_destroy_vertex_buffer_layout(twoc_vertex_buffer_layout_t *layout) {
    free(layout->elements);
    free(layout);
}

void twoc_push_vertex_buffer_element(
    twoc_vertex_buffer_layout_t *layout, twoc_vertex_buffer_element_type_t element_type, const char *name
) {
    twoc_vertex_buffer_element_t *element = realloc(
        layout->elements,
        sizeof(twoc_vertex_buffer_element_t) * (layout->element_count + 1)
    );

    unsigned int offset = 0;
    layout->stride = 0;


    for (unsigned int i = 0; i < layout->element_count; i++) {
        twoc_vertex_buffer_element_t element = layout->elements[i];

        element.offset = offset;
        offset += element.size;
        layout->stride += element.size;
    }

    element[layout->element_count].offset = layout->element_count;
    element[layout->element_count].size = 0;
    element[layout->element_count].data_type = element_type;
    element[layout->element_count].normalized = false;
    element[layout->element_count].name = name;

    layout->elements = element;
    layout->element_count++;
}

twoc_vertex_buffer_t *twoc_create_vertex_buffer(void *data, unsigned int size) {
    twoc_vertex_buffer_t *vertex_buffer = malloc(sizeof(twoc_vertex_buffer_t));
    vertex_buffer->id = 0;

    glGenBuffers(1, &vertex_buffer->id);
    TWOC_GL_CHECK_ERROR();
    twoc_bind_vertex_buffer(vertex_buffer);
    twoc_set_vertex_buffer_data(data, size);

    return vertex_buffer;
}

void twoc_destroy_vertex_buffer(twoc_vertex_buffer_t *vertex_buffer) {
    glDeleteBuffers(1, &vertex_buffer->id);
    TWOC_GL_CHECK_ERROR();
}

void twoc_bind_vertex_buffer(twoc_vertex_buffer_t *vertex_buffer) {
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->id);
    TWOC_GL_CHECK_ERROR();
}

void twoc_unbind_vertex_buffer() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    TWOC_GL_CHECK_ERROR();
}

void twoc_set_vertex_buffer_data(void *data, unsigned int size) {
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    TWOC_GL_CHECK_ERROR();
}

void twoc_set_vertex_buffer_layout(twoc_vertex_buffer_t *vertex_buffer, twoc_vertex_buffer_layout_t *layout) {
    TWOC_ASSERT(layout->element_count != 0, "vertex buffer layout must not be empty");
    vertex_buffer->layout = layout;
}
