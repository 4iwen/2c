#include "pch.h"

#include "event/event.h"

#include <GLFW/glfw3.h>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    twoc_event_t event;
    event.type = action == GLFW_PRESS ? TWOC_EVENT_KEY_PRESS : TWOC_EVENT_KEY_RELEASE;
    event.data.key.key = key;
    event.data.key.scancode = scancode;
    event.data.key.action = action;
    event.data.key.mods = mods;

    printf("key event: %i %i %i %i\n", key, scancode, action, mods);
}

void mouse_position_callback(GLFWwindow *window, double xpos, double ypos) {
    twoc_event_t event;
    event.type = TWOC_EVENT_MOUSE_MOVE;
    event.data.mouse_move.xpos = xpos;
    event.data.mouse_move.ypos = ypos;

    printf("mouse move event: %f %f\n", xpos, ypos);
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    twoc_event_t event;
    event.type = action == GLFW_PRESS ? TWOC_EVENT_MOUSE_BUTTON_PRESS : TWOC_EVENT_MOUSE_BUTTON_RELEASE;
    event.data.mouse_button.button = button;
    event.data.mouse_button.action = action;
    event.data.mouse_button.mods = mods;

    printf("mouse button event: %i %i %i\n", button, action, mods);
}

void window_resize_callback(GLFWwindow *window, int width, int height) {
    twoc_event_t event;
    event.type = TWOC_EVENT_WINDOW_RESIZE;
    event.data.window_resize.width = width;
    event.data.window_resize.height = height;

    printf("window resize event: %i %i\n", width, height);
}

void window_close_callback(GLFWwindow *window) {
    twoc_event_t event;
    event.type = TWOC_EVENT_WINDOW_CLOSE;

    printf("window close event\n");
}
