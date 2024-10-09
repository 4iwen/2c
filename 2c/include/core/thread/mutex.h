#ifndef TWOC_MUTEX_H
#define TWOC_MUTEX_H

#include "core/api.h"

#if defined(TWOC_PLATFORM_WINDOWS)
typedef HANDLE mutex_t;
#elif defined(TWOC_PLATFORM_MACOS) || defined(TWOC_PLATFORM_LINUX)
typedef pthread_mutex_t mutex_t;
#else
#error "platform not supported"
#endif

TWOC_API bool twoc_create_mutex(mutex_t *mutex);

TWOC_API bool twoc_destroy_mutex(mutex_t *mutex);

TWOC_API bool twoc_lock_mutex(mutex_t *mutex);

TWOC_API bool twoc_unlock_mutex(mutex_t *mutex);

#endif // TWOC_MUTEX_H
