#ifndef TWOC_ASSERT_H
#define TWOC_ASSERT_H

#include "platform.h"

#if defined(TWOC_DEBUG)
#if defined(TWOC_PLATFORM_WINDOWS)
#define TWOC_DEBUG_BREAK() __debugbreak()
#elif defined(TWOC_PLATFORM_MACOS) || defined(TWOC_PLATFORM_LINUX)
#define TWOC_DEBUG_BREAK() __builtin_trap()
#else
#error "debug break not implemented for this platform"
#endif

#include <stdio.h>

#define TWOC_ASSERT(condition, message, ...) { \
    if (!(condition)) { \
        fprintf(stderr, "[%s:%d] Assertion failed: " message "\n",  __FILE__, __LINE__, ##__VA_ARGS__); \
        TWOC_DEBUG_BREAK(); \
    } \
}
#else
#define TWOC_ASSERT(condition, message)
#endif

#endif // TWOC_ASSERT_H
