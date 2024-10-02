#include "pch.h"

#include "renderer.h"

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "shader.h"
#include "misc.h"

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

static twoc_vertex_array_t *quad_vertex_array = NULL;
static twoc_vertex_buffer_t *quad_vertex_buffer = NULL;
static twoc_index_buffer_t *quad_index_buffer = NULL;
static twoc_shader_t *quad_shader = NULL;

bool twoc_create_renderer() {
    if (!gladLoadGL(glfwGetProcAddress)) {
        return false;
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_STENCIL_TEST);

    glEnable(GL_SCISSOR_TEST);

    float quad_vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f,
    };

    unsigned int quad_indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    const char *quad_vertex_shader_source =
            "#version 330 core\n"
            "layout (location = 0) in vec3 a_pos;\n"
            "layout (location = 1) in vec3 a_color;\n"
            "\n"
            "out vec3 color;\n"
            "\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(a_pos, 1.0f);\n"
            "   color = a_color;\n"
            "}\n";

    const char *quad_fragment_shader_source =
            "#version 330 core\n"
            "out vec4 frag_color;\n"
            "\n"
            "in vec3 color;\n"
            "\n"
            "void main()\n"
            "{\n"
            "   frag_color = vec4(color, 1.0f);\n"
            "}\n";


    quad_shader = twoc_create_shader(quad_vertex_shader_source, quad_fragment_shader_source);

    quad_vertex_array = twoc_create_vertex_array();
    quad_vertex_buffer = twoc_create_vertex_buffer(quad_vertices, sizeof(quad_vertices));
    quad_index_buffer = twoc_create_index_buffer(quad_indices, sizeof(quad_indices));

    twoc_vertex_buffer_layout_t *quad_vertex_buffer_layout = twoc_create_vertex_buffer_layout();
    twoc_push_vertex_buffer_element(quad_vertex_buffer_layout, TWOC_FLOAT3, "a_pos");
    twoc_push_vertex_buffer_element(quad_vertex_buffer_layout, TWOC_FLOAT3, "a_color");
    twoc_set_vertex_buffer_layout(quad_vertex_buffer, quad_vertex_buffer_layout);

    twoc_add_vertex_buffer_to_vertex_array(quad_vertex_array, quad_vertex_buffer);
    twoc_add_index_buffer_to_vertex_array(quad_vertex_array, quad_index_buffer);

    return true;
}

void twoc_clear_background(twoc_color_t color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void twoc_begin_drawing() {
}

void twoc_end_drawing() {
    twoc_bind_shader(quad_shader);
    twoc_bind_vertex_array(quad_vertex_array);
    glDrawElements(GL_TRIANGLES, (GLsizei) quad_index_buffer->count, GL_UNSIGNED_INT, 0);
    TWOC_GL_CHECK_ERROR();
    twoc_unbind_vertex_array();
}
