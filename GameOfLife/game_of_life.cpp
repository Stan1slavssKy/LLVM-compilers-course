#include "grlib/graph_lib.h"

#include <cstddef>
#include <cstdlib>

size_t calculate_neighbors_summ(window_config *w_conf, uint8_t *buffer, size_t x, size_t y);

int main()
{
    size_t w_width = 1080;
    size_t w_height = 720;
    window_config window_conf {w_width, w_height, "GameOfLife"};

    grlib_window *window = grlib_create_window(&window_conf);

    rgb_config life_cell_color {0, 255, 0};
    rgb_config death_cell_color {0, 0, 0};

    uint8_t *calc_buffer = new uint8_t[w_width * w_height];

    for (size_t x = 0; x < w_width; ++x) {
        for (size_t y = 0; y < w_height; ++y) {
            uint8_t rand_pixel = std::rand() % 2;
            *(calc_buffer + w_width * y + x) = rand_pixel;

            if (rand_pixel == 1) {
                grlib_set_pixel(window, x, y, life_cell_color);
            }
        }
    }

    while (grlib_is_window_open(window))
    {
        grlib_check_events(window);
        for (size_t y = 0; y < w_height; ++y) {
            for (size_t x = 0; x < w_width; ++x) {
                size_t summ = calculate_neighbors_summ(&window_conf, calc_buffer, x, y);

                if (summ == 3) {
                    grlib_set_pixel(window, x, y, life_cell_color);
                }
                if (summ < 2) {
                    grlib_set_pixel(window, x, y, death_cell_color);
                }
                if (summ > 3) {
                    grlib_set_pixel(window, x, y, death_cell_color);
                }
            }
        }

        grlib_copy_image_buffer(window, calc_buffer, life_cell_color, death_cell_color);

        grlib_update_window(window);
    }

    grlib_destroy_window(window);
    delete calc_buffer;

    return 0;
}

size_t calculate_neighbors_summ(window_config *w_conf, uint8_t *buffer, size_t x, size_t y)
{
    size_t summ = 0;
    size_t width = w_conf->width;
    size_t height = w_conf->height;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            summ += *(buffer + width * ((y + j + height) % height) + ((x + i + width) % width));
        }
    }

    summ -= *(buffer + width * y + x);

    return summ;
}
