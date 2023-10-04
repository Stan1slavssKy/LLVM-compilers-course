#ifndef GAMEOFLIFE_LIB_GRAPH_LIB_H
#define GAMEOFLIFE_LIB_GRAPH_LIB_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GRLIB_DEFAULT_WIDTH 1080
#define GRLIB_DEFAULT_HEIGHT 720
#define DEFAULT_FRAMERATE 60

struct window_config {
    size_t width {0};
    size_t height {0};

    const char *name {nullptr};
};

struct rgb_config {
    uint8_t red {0};
    uint8_t grn {0};
    uint8_t ble {0};
};

struct grlib_window;

grlib_window *grlib_create_window(window_config *window_conf);
void grlib_destroy_window(grlib_window *window);

bool grlib_is_window_open(grlib_window *window);
void grlib_update_window(grlib_window *window);
void grlib_check_events(grlib_window *window);

void grlib_set_pixel(grlib_window *window, size_t x, size_t y, rgb_config rgb);

void grlib_copy_image_buffer(grlib_window *window, uint8_t *buffer, rgb_config life_rgb, rgb_config death_rgb);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // GAMEOFLIFE_LIB_GRAPH_LIB_H
