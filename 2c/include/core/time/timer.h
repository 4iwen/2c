#ifndef TWOC_TIMER_H
#define TWOC_TIMER_H

#include "core/api.h"
#include "core/thread/mutex.h"

typedef struct {
    bool is_running;
    double start_time;
    double elapsed_time;
    mutex_t mutex;
} twoc_timer_t;

TWOC_API twoc_timer_t *twoc_create_timer();

TWOC_API void twoc_destroy_timer(twoc_timer_t *timer);

TWOC_API void twoc_start_timer(twoc_timer_t *timer);

TWOC_API void twoc_stop_timer(twoc_timer_t *timer);

TWOC_API void twoc_reset_timer(twoc_timer_t *timer);

TWOC_API void twoc_pause_timer(twoc_timer_t *timer);

TWOC_API void twoc_resume_timer(twoc_timer_t *timer);

TWOC_API double twoc_get_elapsed_seconds(twoc_timer_t *timer);

TWOC_API double twoc_get_elapsed_milliseconds(twoc_timer_t *timer);

#endif // TWOC_TIMER_H
