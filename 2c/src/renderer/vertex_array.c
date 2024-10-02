#include "pch.h"

#include "vertex_array.h"
#include "misc.h"

#include <core/assert.h>
#include <glad/gl.h>

GLenum element_type_to_opengl_type(twoc_vertex_buffer_element_data_type_t type) {
    switch (type) {
        default:
        case TWOC_NONE:
            return GL_NONE;
        case TWOC_FLOAT:
        case TWOC_FLOAT2:
        case TWOC_FLOAT3:
        case TWOC_FLOAT4:
        case TWOC_MAT4:
            return GL_FLOAT;
        case TWOC_INT:
            return GL_INT;
        case TWOC_BOOL:
            return GL_BOOL;
    }
}

twoc_vertex_array_t *twoc_create_vertex_array() {
    twoc_vertex_array_t *vertex_array = malloc(sizeof(twoc_vertex_array_t));

    glGenVertexArrays(1, &vertex_array->id);
    TWOC_GL_CHECK_ERROR();

    return vertex_array;
}

void twoc_destroy_vertex_array(twoc_vertex_array_t *vertex_array) {
    glDeleteVertexArrays(1, &vertex_array->id);
    TWOC_GL_CHECK_ERROR();
}

void twoc_bind_vertex_array(twoc_vertex_array_t *vertex_array) {
    glBindVertexArray(vertex_array->id);
    TWOC_GL_CHECK_ERROR();
}

void twoc_unbind_vertex_array() {
    glBindVertexArray(0);
    TWOC_GL_CHECK_ERROR();
}

void twoc_add_vertex_buffer_to_vertex_array(twoc_vertex_array_t *vertex_array, twoc_vertex_buffer_t *vertex_buffer) {
    bool has_layout = vertex_buffer->layout != NULL;
    TWOC_ASSERT(has_layout, "vertex buffer must have a layout");

    vertex_array->vertex_buffer = vertex_buffer;

    twoc_bind_vertex_array(vertex_array);
    twoc_bind_vertex_buffer(vertex_buffer);

    twoc_vertex_buffer_layout_t *layout = vertex_buffer->layout;

    for (unsigned int i = 0; i < layout->element_count; i++) {
        twoc_vertex_buffer_element_t element = layout->elements[i];

        glEnableVertexAttribArray(i);
        TWOC_GL_CHECK_ERROR();
        glVertexAttribPointer(
            i,
            (GLint) twoc_get_element_component_count(&element),
            element_type_to_opengl_type(element.data_type),
            element.normalized,
            (GLsizei) layout->stride,
            (const void *) element.offset
        );
        TWOC_GL_CHECK_ERROR();
    }

    twoc_unbind_vertex_array();
}

void twoc_add_index_buffer_to_vertex_array(
    twoc_vertex_array_t *vertex_array, twoc_index_buffer_t *index_buffer
) {
    vertex_array->index_buffer = index_buffer;

    twoc_bind_vertex_array(vertex_array);
    twoc_bind_index_buffer(index_buffer);
    twoc_unbind_vertex_array();
}
