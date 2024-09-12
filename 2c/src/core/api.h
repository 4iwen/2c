#ifndef TWOC_API_H
#define TWOC_API_H

#include "core/platform.h"

#if defined(TWOC_BUILD_SHARED)
#if defined(TWOC_PLATFORM_WINDOWS)
#if defined(TWOC_EXPORTS)
#define TWOC_API __declspec(dllexport)
#else
#define TWOC_API __declspec(dllimport)
#endif
#else
#if defined(TWOC_EXPORTS)
#define TWOC_API __attribute__((visibility("default")))
#else
#define TWOC_API
#endif
#endif
#else
#define TWOC_API
#endif

#endif // TWOC_API_H
