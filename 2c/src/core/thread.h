#ifndef TWOC_THREAD_H
#define TWOC_THREAD_H

#include "core/api.h"

#if defined(TWOC_PLATFORM_WINDOWS)
typedef HANDLE thread_t;
#elif defined(TWOC_PLATFORM_MACOS) || defined(TWOC_PLATFORM_LINUX)
typedef pthread_t thread_t;
#else
#error "platform not supported"
#endif

typedef void *(*thread_func_t)(void *);

TWOC_API bool twoc_create_thread(thread_t *thread, thread_func_t func, void *arg);

TWOC_API bool twoc_join_thread(thread_t thread);

#endif // TWOC_THREAD_H
