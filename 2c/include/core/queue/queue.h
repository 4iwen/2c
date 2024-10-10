#ifndef TWOC_QUEUE_H
#define TWOC_QUEUE_H

typedef struct {
    void *data;
    size_t size;
} twoc_queue_item_t;

typedef struct {
    twoc_queue_item_t *items;
    size_t size;
    size_t capacity;
    size_t head;
    size_t tail;
} twoc_queue_t;

#endif // TWOC_QUEUE_H
