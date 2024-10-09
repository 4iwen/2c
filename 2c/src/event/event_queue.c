#include "pch.h"

#include "event/event_queue.h"
#include "core/assert.h"

#define INITIAL_QUEUE_CAPACITY 16
#define SHRINK_THRESHOLD 4

/*static twoc_event_queue_t *instance = NULL;

void twoc_create_event_queue() {
    TWOC_ASSERT(instance == NULL, "trying to create event queue that already exists");

    instance = malloc(sizeof(twoc_event_queue_t));
    instance->events = malloc(sizeof(twoc_event_t) * INITIAL_QUEUE_CAPACITY);
    instance->count = 0;
    instance->capacity = INITIAL_QUEUE_CAPACITY;
}

void twoc_destroy_event_queue() {
    TWOC_ASSERT(instance != NULL, "trying to destroy event queue that does not exist");

    free(instance->events);
    free(instance);
    instance = NULL;
}

void twoc_resize_event_queue(unsigned int capacity) {
    TWOC_ASSERT(instance != NULL, "trying to resize event queue that does not exist");

    twoc_event_t *new_events = realloc(instance->events, sizeof(twoc_event_t) * capacity);
    TWOC_ASSERT(new_events != NULL, "failed to resize event queue to capacity %u", capacity);

    instance->capacity = capacity;
    instance->events = new_events;
}*/
