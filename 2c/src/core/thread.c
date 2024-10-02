#include "pch.h"

#include "thread.h"

#include "platform.h"

#if defined(TWOC_PLATFORM_WINDOWS)
bool twoc_create_thread(thread_t *thread, thread_func_t func, void *arg) {
    *thread = CreateThread(NULL, 0, func, arg, 0, NULL);
    return *thread != NULL;
}

bool twoc_join_thread(thread_t thread) {
    WaitForSingleObject(thread, INFINITE);
    return CloseHandle(thread) != 0;
}
#endif

#if defined(TWOC_PLATFORM_MACOS) || defined(TWOC_PLATFORM_LINUX)
bool twoc_create_thread(thread_t *thread, thread_func_t func, void *arg) {
    return pthread_create(thread, NULL, func, arg) == 0;
}

bool twoc_join_thread(thread_t thread) {
    return pthread_join(thread, NULL) == 0;
}
#endif
