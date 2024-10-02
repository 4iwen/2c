#ifndef TWOC_WINDOW_H
#define TWOC_WINDOW_H

#include "core/api.h"

TWOC_API void twoc_create_window(int width, int height, const char *title);

TWOC_API void twoc_destroy_window();

TWOC_API void twoc_update_window();

TWOC_API bool twoc_should_window_close();

TWOC_API void twoc_close_window();

TWOC_API void twoc_set_max_fps(unsigned int max_fps);

TWOC_API void twoc_set_vsync(bool enabled);

TWOC_API void twoc_maximize_window();

TWOC_API double twoc_get_time_since_window_creation();

#endif // TWOC_WINDOW_H
