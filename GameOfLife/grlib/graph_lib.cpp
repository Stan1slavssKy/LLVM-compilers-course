#include "graph_lib.h"

#include <cassert>
#include <cstring>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

struct grlib_window {
    window_config *window_conf {nullptr};
    
    sf::RenderWindow window;
    sf::Image buffer;
};

grlib_window *grlib_create_window(window_config *window_conf)
{
    assert(window_conf);

    auto *window = new grlib_window;
    assert(window);

    window->window_conf = window_conf;
    window->window.create(sf::VideoMode(window_conf->width, window_conf->height), window_conf->name);
    window->buffer.create(window_conf->width, window_conf->height, {0, 0, 0});

    return window;
}

void grlib_destroy_window(grlib_window *window)
{
    delete window;
}

void grlib_update_window(grlib_window *window)
{
    assert(window);

    sf::Texture texture;
    texture.loadFromImage(window->buffer);

    sf::Sprite sprite;
    sprite.setTexture(texture, true);

    window->window.clear();
    window->window.draw(sprite);
    window->window.display();
}

void grlib_set_pixel(grlib_window *window, size_t x, size_t y, rgb_config rgb)
{
    assert(window);
    window->buffer.setPixel(x, y, {rgb.red, rgb.grn, rgb.ble});
}

bool grlib_is_window_open(grlib_window *window)
{
    assert(window);
    return window->window.isOpen();
}

void grlib_check_events(grlib_window *window)
{
    assert(window);

    sf::Event event;
    while (window->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->window.close();   
        }
    }
}

void grlib_set_random_pixels(grlib_window *window, rgb_config rgb)
{
    assert(window);

    for (size_t y = 0; y < window->window_conf->height; ++y) {
        for (size_t x = 0; x < window->window_conf->width; ++x) {
            if (std::rand() % 2 == 0) {
                grlib_set_pixel(window, x, y, rgb);
            }
        }
    }
}

static sf::Color rgb_to_color(rgb_config rgb)
{
    return sf::Color {rgb.red, rgb.grn, rgb.ble};
}

void grlib_copy_image_buffer(grlib_window *window, uint8_t *buffer, rgb_config life_rgb, rgb_config death_rgb)
{
    for (size_t x = 0; x < window->window_conf->width; ++x) {
        for (size_t y = 0; y < window->window_conf->height; ++y) {
            if (window->buffer.getPixel(x, y) == rgb_to_color(death_rgb)) {
                *(buffer + window->window_conf->width * y + x) = 0;
            } else if (window->buffer.getPixel(x, y) == rgb_to_color(life_rgb)) {
                *(buffer + window->window_conf->width * y + x) = 1;
            }
        }
    }
}
