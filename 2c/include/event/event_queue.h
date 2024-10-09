#ifndef TWOC_EVENT_QUEUE_H
#define TWOC_EVENT_QUEUE_H

#include "event.h"

typedef struct {
    twoc_event_t *events;
    unsigned int count;
    unsigned int capacity;
} twoc_event_queue_t;

twoc_event_queue_t *twoc_create_event_queue();

void twoc_destroy_event_queue(twoc_event_queue_t *event_queue);

void twoc_resize_event_queue(unsigned int capacity);

#endif // TWOC_EVENT_QUEUE_H
