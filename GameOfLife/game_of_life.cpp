#include "grlib/graph_lib.h"

#include <cassert>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

size_t calculate_neighbors_summ(window_config *w_conf, uint8_t *buffer, size_t x, size_t y);

int main()
{
    size_t w_width = 1080;
    size_t w_height = 720;
    window_config window_conf {w_width, w_height, "GameOfLife"};

    grlib_window *window = grlib_create_window(&window_conf);

    rgb_config life_cell_color {0, 255, 0};
    rgb_config death_cell_color {0, 0, 0};

    uint8_t *calc_buffer = new uint8_t[1080 * 720];
    assert(calc_buffer);

    for (size_t x = 0; x < w_width; ++x) {
        for (size_t y = 0; y < w_height; ++y) {
            uint8_t rand_pixel = std::rand() % 2;
            *(calc_buffer + w_width * y + x) = rand_pixel;

            if (rand_pixel == 1) {
                grlib_set_pixel(window, x, y, life_cell_color);
            }
        }
    }

    // *(calc_buffer + w_width * (0) + 2) = 1;
    // *(calc_buffer + w_width * (1) + 2) = 1;
    // *(calc_buffer + w_width * (2) + 2) = 1;
    // *(calc_buffer + w_width * (2) + 1) = 1;
    // *(calc_buffer + w_width * (1) + 0) = 1;

    // grlib_set_pixel(window, 2, 0, life_cell_color);
    // grlib_set_pixel(window, 2, 1, life_cell_color);
    // grlib_set_pixel(window, 2, 2, life_cell_color);
    // grlib_set_pixel(window, 1, 2, life_cell_color);
    // grlib_set_pixel(window, 0, 1, life_cell_color);

    while (grlib_is_window_open(window))
    {
        grlib_check_events(window);
        
        for (size_t x = 0; x < w_width; ++x) {
            for (size_t y = 0; y < w_height; ++y) {
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

    return 0;
}

size_t calculate_neighbors_summ(window_config *w_conf, uint8_t *buffer, size_t x, size_t y)
{
    assert(buffer);
    assert(w_conf);

    size_t summ = 0;
    
    int i = -1;
    int j = -1;
    
    if (x == 0) i = 0;
    if (y == 0) j = 0;

    for (; i <= 1; ++i) {
        for (; j <= 1; ++j) {
            if (y + j >= w_conf->height || 
                x + i >= w_conf->width) {
                continue;
            }
            if (i == 0 && j == 0) {
                continue;
            }
            summ += *(buffer + w_conf->width * (y + j) + (x + i));
            // printf("buffer = %d; i = %d, j = %d, x = %lu, y = %lu\n", *(buffer + w_conf->width * (y + j) + (x + i)), i, j, x, y);
        }

        j = -1;
        if (y == 0) j = 0;
    }

    return summ;
}