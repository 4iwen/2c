#ifndef TWOC_RENDERER_H
#define TWOC_RENDERER_H

#include "core/api.h"

typedef struct {
    float r;
    float g;
    float b;
    float a;
} twoc_color_t;

#define TWOC_COLOR_BLACK (twoc_color_t) {0.0f, 0.0f, 0.0f, 1.0f}
#define TWOC_COLOR_WHITE (twoc_color_t) {1.0f, 1.0f, 1.0f, 1.0f}
#define TWOC_COLOR_RED (twoc_color_t) {1.0f, 0.0f, 0.0f, 1.0f}
#define TWOC_COLOR_GREEN (twoc_color_t) {0.0f, 1.0f, 0.0f, 1.0f}
#define TWOC_COLOR_BLUE (twoc_color_t) {0.0f, 0.0f, 1.0f, 1.0f}
#define TWOC_COLOR_YELLOW (twoc_color_t) {1.0f, 1.0f, 0.0f, 1.0f}
#define TWOC_COLOR_CYAN (twoc_color_t) {0.0f, 1.0f, 1.0f, 1.0f}
#define TWOC_COLOR_MAGENTA (twoc_color_t) {1.0f, 0.0f, 1.0f, 1.0f}

#define TWOC_RGB_F(r, g, b) (twoc_color_t) {r, g, b, 1.0f}
#define TWOC_RGBA_F(r, g, b, a) (twoc_color_t) {r, g, b, a}
#define TWOC_RGB_255(r, g, b) (twoc_color_t) {r / 255.0f, g / 255.0f, b / 255.0f, 1.0f}
#define TWOC_RGBA_255(r, g, b, a) (twoc_color_t) {r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f}

TWOC_API void twoc_create_renderer();

TWOC_API void twoc_destroy_renderer();

TWOC_API void twoc_clear_background(twoc_color_t color);

TWOC_API void twoc_begin_drawing();

TWOC_API void twoc_end_drawing();

#endif // TWOC_RENDERER_H
