#include <2c/2c.h>

int main() {
    twoc_window_create(800, 600, "2c demo");

    while (!twoc_window_should_close()) {

    }

    twoc_window_destroy();

    return 0;
}
