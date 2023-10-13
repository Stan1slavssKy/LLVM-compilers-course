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

struct argb_config {
    uint8_t alpha {0};
    uint8_t red   {0};
    uint8_t grn   {0};
    uint8_t ble   {0};
};

struct grlib_window;

grlib_window *grlib_get_window();

void grlib_init(size_t width, size_t height, const char *window_name, uint8_t rgb);

argb_config get_color_from_argb(uint32_t argb); 

void grlib_set_pixel(size_t x, size_t y, uint32_t argb);

void grlib_set_random_pixels(size_t width, size_t height, uint8_t *buffer, uint32_t argb);

void grlib_update_window();
int grlib_check_events();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // GAMEOFLIFE_LIB_GRAPH_LIB_H
