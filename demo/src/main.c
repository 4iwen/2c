#include <2c/2c.h>

int main() {
    twoc_create_window(800, 600, "2c demo");

    twoc_set_max_fps(144);
    twoc_set_vsync(false);

    // twoc_texture_t texture = twoc_load_texture("assets/texture.png");

    while (!twoc_should_window_close()) {
        double time = twoc_get_time_since_window_creation();

        double red = (sin(time * 0.5) + 1.0) / 2.0;
        double green = (sin(time * 0.5 + 2.0) + 1.0) / 2.0;
        double blue = (sin(time * 0.5 + 4.0) + 1.0) / 2.0;

        twoc_begin_drawing(); {
            twoc_clear_background(TWOC_RGB_F(red, green, blue));

            // twoc_draw_rectangle(100, 100, 200, 200, TWOC_RGB(255, 0, 0));
            //
            // twoc_draw_circle(400, 300, 100, TWOC_RGB(0, 255, 0));
            //
            // twoc_draw_line(0, 0, 800, 600, TWOC_RGB(0, 0, 255));
            //
            // twoc_draw_text("2c test", 10, 10, 20, TWOC_RGB(255, 255, 255));
            //
            // twoc_draw_texture(texture, 500, 400, 100, 100, TWOC_RGB(255, 255, 255));
        }
        twoc_end_drawing();

        twoc_update_window();
    }

    twoc_destroy_window();

    return 0;
}
