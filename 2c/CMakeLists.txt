# ============ library =============
set(
        SOURCE_FILES

        src/core/window.c
)

if (TWOC_BUILD_SHARED)
    add_library(2c SHARED ${SOURCE_FILES})
else ()
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

        src
        ${CMAKE_SOURCE_DIR}/deps/glfw/include
        ${CMAKE_SOURCE_DIR}/deps/glad/include

)

target_link_libraries(
        2c

        glfw
        glad
)
# ==================================

