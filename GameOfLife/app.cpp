#include "grlib/graph_lib.h"

#include "game_of_life.h"

#define WIDTH 1080
#define HEIGHT 720

extern "C" void app()
{
    uint32_t alpha = ((uint32_t)255 << 24);
    uint32_t green = ((uint32_t)255 << 8);
    uint32_t black = 0;
    uint32_t life_color = green + alpha;
    uint32_t death_color = black + alpha;

    uint8_t buffer1[WIDTH * HEIGHT] { };
    uint8_t buffer2[WIDTH * HEIGHT] { };

    uint8_t *old_buffer = buffer1;
    uint8_t *new_buffer = buffer2;

    grlib_set_random_pixels(WIDTH, HEIGHT, old_buffer, life_color);

    for (; !grlib_check_events(); )
    {
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                int sum = calculate_neighbors_sum(old_buffer, x, y);

                if (sum == 3) {
                    *(new_buffer + WIDTH * y + x) = 1;
                    grlib_set_pixel(x, y, life_color);
                } else if (sum < 2) {
                    *(new_buffer + WIDTH * y + x) = 0;
                    grlib_set_pixel(x, y, death_color);
                } else if (sum > 3) {
                    *(new_buffer + WIDTH * y + x) = 0;
                    grlib_set_pixel(x, y, death_color);
                } else {
                    *(new_buffer + WIDTH * y + x) = *(old_buffer + WIDTH * y + x);
                }
            }
        }
    
        grlib_update_window();
        swap(&old_buffer, &new_buffer);
    }
}
