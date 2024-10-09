#ifndef TWOC_EVENT_H
#define TWOC_EVENT_H

typedef enum {
    TWOC_EVENT_NONE,
    TWOC_EVENT_KEY_PRESS,
    TWOC_EVENT_KEY_RELEASE,
    TWOC_EVENT_MOUSE_MOVE,
    TWOC_EVENT_MOUSE_BUTTON_PRESS,
    TWOC_EVENT_MOUSE_BUTTON_RELEASE,
    TWOC_EVENT_WINDOW_RESIZE,
    TWOC_EVENT_WINDOW_CLOSE
} twoc_event_type_t;

typedef struct {
    twoc_event_type_t type;

    union {
        struct {
            int key;
            int scancode;
            int action;
            int mods;
        } key;

        struct {
            double xpos;
            double ypos;
        } mouse_move;

        struct {
            int button;
            int action;
            int mods;
        } mouse_button;

        struct {
            int width;
            int height;
        } window_resize;
    } data;
} twoc_event_t;

typedef struct GLFWwindow GLFWwindow;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

void mouse_position_callback(GLFWwindow *window, double xpos, double ypos);

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

void window_resize_callback(GLFWwindow *window, int width, int height);

void window_close_callback(GLFWwindow *window);

#endif // TWOC_EVENT_H
