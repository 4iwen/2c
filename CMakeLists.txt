cmake_minimum_required(VERSION 3.21)
project(2c C)

# ======== cmake settings ==========
set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
# ==================================

# ============ options =============
option(TWOC_BUILD_SHARED "build the shared library" ON)
option(TWOC_BUILD_DEMO "build the demo" ON)
# ==================================

# ============ library =============
add_subdirectory(2c)

if (TWOC_BUILD_DEMO)
    add_subdirectory(demo)
endif ()
# ==================================

# ========== dependencies ==========
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(deps/glfw)

add_subdirectory(deps/glad)
# ==================================

