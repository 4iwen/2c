#ifndef TWOC_WINDOW_H
#define TWOC_WINDOW_H

#include "api.h"

void TWOC_API twoc_window_create(unsigned int width, unsigned int height, const char *title);

void TWOC_API twoc_window_destroy();

void TWOC_API twoc_window_update();

bool TWOC_API twoc_window_should_close();


#endif // TWOC_WINDOW_H
