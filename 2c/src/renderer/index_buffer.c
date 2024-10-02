#include "pch.h"

#include "index_buffer.h"
#include "misc.h"

#include <glad/gl.h>

twoc_index_buffer_t *twoc_create_index_buffer(void *data, unsigned int size) {
    twoc_index_buffer_t *index_buffer = malloc(sizeof(twoc_index_buffer_t));
    index_buffer->id = 0;
    index_buffer->count = size / sizeof(int);

    glGenBuffers(1, &index_buffer->id);
    TWOC_GL_CHECK_ERROR();
    twoc_bind_index_buffer(index_buffer);
    twoc_set_index_buffer_data(data, size);

    return index_buffer;
}

void twoc_destroy_index_buffer(twoc_index_buffer_t *index_buffer) {
    glDeleteBuffers(1, &index_buffer->id);
    TWOC_GL_CHECK_ERROR();
}

void twoc_bind_index_buffer(twoc_index_buffer_t *index_buffer) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->id);
    TWOC_GL_CHECK_ERROR();
}

void twoc_unbind_index_buffer() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    TWOC_GL_CHECK_ERROR();
}

void twoc_set_index_buffer_data(void *data, unsigned int size) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    TWOC_GL_CHECK_ERROR();
}
