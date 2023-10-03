#include "grlib/graph_lib.h"

#include <cassert>
#include <cstddef>

int main()
{
    window_config window_conf {1080, 720, "GameOfLife"};
    grlib_window *window = grlib_create_window(&window_conf);

    grlib_set_random_pixels(window, {255, 0, 0});

    while (grlib_is_window_open(window))
    {
        grlib_check_events(window);
        
        grlib_update_window(window);
    }

    grlib_destroy_window(window);

    return 0;
}
