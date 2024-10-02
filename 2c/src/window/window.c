#include "pch.h"

#include "window.h"

#include "core/core.h"
#include "core/assert.h"
#include "timer/timer.h"

#include <GLFW/glfw3.h>
#include <renderer/renderer.h>

static GLFWwindow *instance = NULL;
static twoc_timer_t *frame_timer;
static double target_frame_time = 0.0f;

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "GLFW error %i: %s\n", error, description);
}

void twoc_create_window(int width, int height, const char *title) {
    TWOC_ASSERT(instance == NULL, "trying to create window that already exists");

    TWOC_ASSERT(glfwInit(), "failed to initialize glfw");

    glfwSetErrorCallback(glfw_error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if defined(TWOC_PLATFORM_MACOS)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    instance = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!instance) {
        glfwTerminate();
        TWOC_ASSERT(false, "failed to create window");
    }

    glfwMakeContextCurrent(instance);

    if (!twoc_create_renderer()) {
        glfwDestroyWindow(instance);
        glfwTerminate();
        TWOC_ASSERT(false, "failed to initialize glad");
    }

    frame_timer = twoc_create_timer();
    twoc_start_timer(frame_timer);
}

void twoc_destroy_window() {
    TWOC_ASSERT(instance != NULL, "trying to destroy window that does not exist");

    twoc_destroy_timer(frame_timer);

    glfwDestroyWindow(instance);
    instance = NULL;

    glfwTerminate();
}

void twoc_update_window() {
    double elapsed_time = twoc_get_elapsed_seconds(frame_timer);

    if (elapsed_time < target_frame_time) {
        double sleep_time = target_frame_time - elapsed_time;

        if (sleep_time > 0.0) {
            twoc_sleep(sleep_time);
        }
    }

    twoc_reset_timer(frame_timer);
    twoc_start_timer(frame_timer);

    glfwSwapBuffers(instance);

    glfwPollEvents();
}

bool twoc_should_window_close() {
    return glfwWindowShouldClose(instance);
}

void twoc_close_window() {
    glfwSetWindowShouldClose(instance, GLFW_TRUE);
}

void twoc_set_max_fps(unsigned int max_fps) {
    if (max_fps > 0) {
        target_frame_time = 1.0 / max_fps;
    } else {
        target_frame_time = 0.0;
    }
}

void twoc_set_vsync(bool enabled) {
    glfwSwapInterval(enabled ? 1 : 0);
}

void twoc_maximize_window() {
    glfwMaximizeWindow(instance);
}

double twoc_get_time_since_window_creation() {
    return glfwGetTime();
}
