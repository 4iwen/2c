#ifndef TWOC_PLATFORM_H
#define TWOC_PLATFORM_H

#if defined(__APPLE__)
#define TWOC_PLATFORM_MACOS
#elif defined(_WIN32)
#define TWOC_PLATFORM_WINDOWS
#elif defined(__linux__)
#define TWOC_PLATFORM_LINUX
#else
#error "unknown platform"
#endif

#endif // TWOC_PLATFORM_H
