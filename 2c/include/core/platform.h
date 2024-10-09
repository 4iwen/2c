#ifndef TWOC_PLATFORM_H
#define TWOC_PLATFORM_H

#if defined(__APPLE__)
#define TWOC_PLATFORM_MACOS
#elif defined(_WIN32) || defined(_WIN64)
#define TWOC_PLATFORM_WINDOWS
#elif defined(__linux__)
#define TWOC_PLATFORM_LINUX
#else
#error "platform not supported"
#endif

#endif // TWOC_PLATFORM_H
