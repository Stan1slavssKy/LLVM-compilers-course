#include "grlib/graph_lib.h"

int main()
{
    window_config window_conf {1080, 720, "GameOfLife"};
    grlib_window *window = grlib_create_window(&window_conf);

    while (true)
    {
        grlib_check_events(window);
        
        grlib_set_pixel(window, 10, 10, {255, 0, 255});
        grlib_update_window(window);
    }

    grlib_destroy_window(window);

    return 0;
}
