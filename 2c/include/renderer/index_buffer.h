#ifndef TWOC_INDEX_BUFFER_H
#define TWOC_INDEX_BUFFER_H

#include "core/api.h"

typedef struct {
    unsigned int id;
    unsigned int count;
} twoc_index_buffer_t;

TWOC_API twoc_index_buffer_t *twoc_create_index_buffer(void *data, unsigned int size);

TWOC_API void twoc_destroy_index_buffer(twoc_index_buffer_t *index_buffer);

TWOC_API void twoc_bind_index_buffer(twoc_index_buffer_t *index_buffer);

TWOC_API void twoc_unbind_index_buffer();

TWOC_API void twoc_set_index_buffer_data(void *data, unsigned int size);

#endif // TWOC_INDEX_BUFFER_H