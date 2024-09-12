#ifndef TWOC_ASSERT_H
#define TWOC_ASSERT_H

#if defined(TWOC_DEBUG)
#include <stdio.h>
#include <stdlib.h>

#define TWOC_ASSERT(condition, message) \
    if (!(condition)) { \
        fprintf(stderr, "assertion failed: %s\n", message); \
        exit(1); \
    }
#else
#define TWOC_ASSERT(condition, message)
#endif

#endif // TWOC_ASSERT_H
