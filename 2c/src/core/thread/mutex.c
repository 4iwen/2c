#include "pch.h"

#include "core/thread/mutex.h"

#include "core/platform.h"

#if defined(TWOC_PLATFORM_WINDOWS)
bool twoc_create_mutex(mutex_t *mutex) {
    *mutex = CreateMutex(NULL, FALSE, NULL);
    return *mutex != NULL;
}

bool twoc_destroy_mutex(mutex_t *mutex) {
    return CloseHandle(mutex) != 0;
}

bool twoc_lock_mutex(mutex_t *mutex) {
    return WaitForSingleObject(mutex, INFINITE) == WAIT_OBJECT_0;
}

bool twoc_unlock_mutex(mutex_t *mutex) {
    return ReleaseMutex(mutex) != 0;
}
#endif

#if defined(TWOC_PLATFORM_MACOS) || defined(TWOC_PLATFORM_LINUX)
bool twoc_create_mutex(mutex_t *mutex) {
    return pthread_mutex_init(mutex, NULL) == 0;
}

bool twoc_destroy_mutex(mutex_t *mutex) {
    return pthread_mutex_destroy(mutex) == 0;
}

bool twoc_lock_mutex(mutex_t *mutex) {
    return pthread_mutex_lock(mutex) == 0;
}

bool twoc_unlock_mutex(mutex_t *mutex) {
    return pthread_mutex_unlock(mutex) == 0;
}
#endif
