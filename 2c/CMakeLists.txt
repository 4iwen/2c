# ============ library =============
set(
        SOURCE_FILES

        src/core/core.c
        src/core/thread/thread.c
        src/core/thread/mutex.c
        src/window/window.c
        src/core/time/timer.c
        src/core/queue/queue.c
        src/event/event.c
        src/event/event_queue.c
        src/renderer/renderer.c
        src/renderer/vertex_array.c
        src/renderer/vertex_buffer.c
        src/renderer/index_buffer.c
        src/renderer/shader.c
)

if (TWOC_BUILD_SHARED)
    message(STATUS "building 2c as shared library")
    add_library(2c SHARED ${SOURCE_FILES})
else ()
    message(STATUS "building 2c as static library")
    add_library(2c STATIC ${SOURCE_FILES})
endif ()
# ==================================

# =========== definitions ==========
if (CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug")
    target_compile_definitions(
            2c PRIVATE

            TWOC_DEBUG
    )
endif ()

target_compile_definitions(
        2c PRIVATE

        TWOC_EXPORTS
)

if (TWOC_BUILD_SHARED)
    target_compile_definitions(
            2c PRIVATE

            TWOC_BUILD_SHARED
    )
endif ()
# ==================================

# =========== properties ===========
set_target_properties(
        2c PROPERTIES

        C_VISIBILITY_PRESET hidden
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES
)
# ==================================

# ====== precompiled headers =======
target_precompile_headers(
        2c PUBLIC

        src/pch.h
)
# ==================================

# ========== dependencies ==========
target_include_directories(
        2c PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/deps/glfw/include
        ${CMAKE_SOURCE_DIR}/deps/glad/include

)

target_link_libraries(
        2c PUBLIC

        glfw
        glad
)
# ==================================
