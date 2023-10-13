#include "graph_lib.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

struct grlib_window {
    sf::RenderWindow window;
    sf::Image buffer;
};

static grlib_window gwindow;

grlib_window* grlib_get_window() {
    return &gwindow;
}

grlib_window *grlib_init(size_t width, size_t height, const char *window_name, uint8_t rgb)
{
    (void)rgb;
    auto *window = grlib_get_window();

    window->window.create(sf::VideoMode(width, height), window_name);
    window->window.setFramerateLimit(60);
    window->buffer.create(width, height, {0, 0, 0});

    return window;
}

argb_config get_color_from_argb(uint32_t argb)
{
    uint8_t alpha = (argb & 0xFF000000) >> 24;
    uint8_t red   = (argb & 0x00FF0000) >> 16;
    uint8_t green = (argb & 0x0000FF00) >> 8;
    uint8_t blue  = (argb & 0x000000FF) >> 0;

    return argb_config{alpha, red, green, blue};
}

void grlib_update_window()
{
    auto *window = grlib_get_window();

    sf::Texture texture;
    texture.loadFromImage(window->buffer);

    sf::Sprite sprite;
    sprite.setTexture(texture, true);

    window->window.clear();
    window->window.draw(sprite);
    window->window.display();
}

void grlib_set_pixel(size_t x, size_t y, uint32_t argb)
{
    auto *window = grlib_get_window();

    argb_config argb_config = get_color_from_argb(argb);
    
    window->buffer.setPixel(x, y, {argb_config.red, argb_config.grn, argb_config.ble, argb_config.alpha});
}

int grlib_check_events()
{
    auto *window = grlib_get_window();

    sf::Event event;
    while (window->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->window.close();
            return 1;
        }
    }
    return 0;
}

void grlib_set_random_pixels(size_t width, size_t height, uint8_t *buffer, uint32_t argb)
{
    for (size_t x = 0; x < width; ++x) {
        for (size_t y = 0; y < height; ++y) {
            uint8_t rand_pixel = std::rand() % 2;
            *(buffer + width * y + x) = rand_pixel;

            if (rand_pixel == 1) {
                grlib_set_pixel(x, y, argb);
            }
        }
    }
}
