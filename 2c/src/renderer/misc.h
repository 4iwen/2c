#ifndef TWOC_MISC_H
#define TWOC_MISC_H

#include "core/assert.h"

#include <glad/gl.h>

#define TWOC_GL_CHECK_ERROR() { \
    GLenum error; \
    while ((error = glGetError()) != GL_NO_ERROR) { \
        fprintf(stderr, "opengl error in file %s at line %d: %d\n", __FILE__, __LINE__, error); \
    } \
    if (error != GL_NO_ERROR) { \
        TWOC_DEBUG_BREAK(); \
    } \
}


#endif // TWOC_MISC_H
