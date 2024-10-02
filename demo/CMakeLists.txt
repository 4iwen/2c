# =========== executable ===========
set(
        SOURCE_FILES

        src/main.c
)

add_executable(demo ${SOURCE_FILES})
# ==================================

# ========== dependencies ==========
target_include_directories(
        demo PUBLIC

        ${CMAKE_SOURCE_DIR}/2c/include
)

target_link_libraries(
        demo PRIVATE

        2c
)
# ==================================