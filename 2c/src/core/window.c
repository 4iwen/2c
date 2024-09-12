#include "pch.h"

#include "window.h"

#include "assert.h"

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

static GLFWwindow *instance = NULL;

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "GLFW error: %s\n", description);
}

void twoc_window_create(unsigned int width, unsigned int height, const char *title) {
    TWOC_ASSERT(instance == NULL, "trying to create window that already exists");

    TWOC_ASSERT(glfwInit(), "failed to initialize glfw");

    glfwSetErrorCallback(glfw_error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
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

    gladLoadGL(glfwGetProcAddress);

    glfwSwapInterval(1); // Enable vsync TODO: temporary - remove
}

void twoc_window_destroy() {
    TWOC_ASSERT(instance != NULL, "trying to destroy window that does not exist");

    glfwDestroyWindow(instance);
    instance = NULL;

    glfwTerminate();
}

void twoc_window_update() {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(instance);

    glfwPollEvents();
}

bool twoc_window_should_close() {
    return glfwWindowShouldClose(instance);
}
