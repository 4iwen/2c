#ifndef TWOC_PCH_H
#define TWOC_PCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#include "core/platform.h"

#if defined(TWOC_PLATFORM_WINDOWS)
#include <windows.h>
#endif

#if defined(TWOC_PLATFORM_LINUX)
#include <pthread.h>
#endif

#if defined(TWOC_PLATFORM_MACOS)
#include <pthread.h>
#endif

#endif // TWOC_PCH_H
