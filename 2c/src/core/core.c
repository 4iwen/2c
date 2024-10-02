#include "pch.h"

#include "core.h"

#include "assert.h"

void twoc_sleep(double seconds) {
    if (seconds > 0.0) {
#if defined(TWOC_PLATFORM_WINDOWS)
        Sleep((DWORD)(seconds * 1000.0));
#elif defined(TWOC_PLATFORM_LINUX) || defined(TWOC_PLATFORM_MACOS)
        struct timespec time;
        time.tv_sec = (time_t) seconds;
        time.tv_nsec = (long) ((seconds - (double) time.tv_sec) * 1000000000.0);
        nanosleep(&time, NULL);
#else
#error "platform not supported"
#endif
    }
}

double twoc_get_fps() {
    TWOC_ASSERT(false, "not implemented");
}

double twoc_get_delta_time() {
    TWOC_ASSERT(false, "not implemented");
}
