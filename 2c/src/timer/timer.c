#include "pch.h"

#include "timer.h"

#include "core/assert.h"
#include "core/thread.h"
#include "core/mutex.h"

#if defined(TWOC_PLATFORM_WINDOWS)
static LARGE_INTEGER frequency;
static void init_frequency() {
    QueryPerformanceFrequency(&frequency);
}
#endif

static double get_current_time() {
#if defined(TWOC_PLATFORM_WINDOWS)
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)frequency.QuadPart;
#elif defined(TWOC_PLATFORM_MACOS) || defined(TWOC_PLATFORM_LINUX)
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double) ts.tv_sec + (double) ts.tv_nsec / 1.0e9;
#else
#error "platform not supported"
#endif
}


twoc_timer_t *twoc_create_timer() {
    twoc_timer_t *timer = malloc(sizeof(twoc_timer_t));
    TWOC_ASSERT(timer != NULL, "failed to allocate timer");

    timer->is_running = false;
    timer->start_time = 0.0;
    timer->elapsed_time = 0.0;
    bool result = twoc_create_mutex(&timer->mutex);
    TWOC_ASSERT(result, "failed to initialize timer mutex");

#if defined(TWOC_PLATFORM_WINDOWS)
    init_frequency();
#endif

    return timer;
}

void twoc_destroy_timer(twoc_timer_t *timer) {
    TWOC_ASSERT(timer != NULL, "timer is NULL");

    bool result = twoc_destroy_mutex(&timer->mutex);
    TWOC_ASSERT(result, "failed to destroy timer mutex");

    free(timer);
}

void twoc_start_timer(twoc_timer_t *timer) {
    TWOC_ASSERT(timer != NULL, "timer is NULL");

    twoc_lock_mutex(&timer->mutex);

    if (!timer->is_running) {
        timer->start_time = get_current_time();
        timer->is_running = true;
    }

    twoc_unlock_mutex(&timer->mutex);
}

void twoc_stop_timer(twoc_timer_t *timer) {
    TWOC_ASSERT(timer != NULL, "timer is NULL");

    twoc_lock_mutex(&timer->mutex);

    if (timer->is_running) {
        double current_time = get_current_time();
        timer->elapsed_time += current_time - timer->start_time;
        timer->is_running = false;
    }

    twoc_unlock_mutex(&timer->mutex);
}

void twoc_reset_timer(twoc_timer_t *timer) {
    TWOC_ASSERT(timer != NULL, "timer is NULL");

    twoc_lock_mutex(&timer->mutex);

    timer->start_time = 0.0;
    timer->elapsed_time = 0.0;
    timer->is_running = false;

    twoc_unlock_mutex(&timer->mutex);
}

void twoc_pause_timer(twoc_timer_t *timer) {
    TWOC_ASSERT(timer != NULL, "timer is NULL");

    twoc_lock_mutex(&timer->mutex);

    if (timer->is_running) {
        double current_time = get_current_time();
        timer->elapsed_time += current_time - timer->start_time;
        timer->is_running = false;
    }

    twoc_unlock_mutex(&timer->mutex);
}

void twoc_resume_timer(twoc_timer_t *timer) {
    TWOC_ASSERT(timer != NULL, "timer is NULL");

    twoc_lock_mutex(&timer->mutex);

    if (!timer->is_running) {
        timer->start_time = get_current_time();
        timer->is_running = true;
    }

    twoc_unlock_mutex(&timer->mutex);
}

double twoc_get_elapsed_seconds(twoc_timer_t *timer) {
    TWOC_ASSERT(timer != NULL, "timer is NULL");

    twoc_lock_mutex(&timer->mutex);

    double elapsed = timer->elapsed_time;

    if (timer->is_running) {
        double current_time = get_current_time();
        elapsed += current_time - timer->start_time;
    }

    twoc_unlock_mutex(&timer->mutex);

    return elapsed;
}

double twoc_get_elapsed_milliseconds(twoc_timer_t *timer) {
    return twoc_get_elapsed_seconds(timer) * 1000.0;
}
