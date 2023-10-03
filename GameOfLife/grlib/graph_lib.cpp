#include "graph_lib.h"

#include <cassert>
#include <cstring>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

struct grlib_window {
    sf::RenderWindow window;
    sf::Image buffer;
};

grlib_window *grlib_create_window(window_config *window_conf)
{
    assert(window_conf);

    auto *window = new grlib_window;
    assert(window);

    window->window.create(sf::VideoMode(window_conf->width, window_conf->height), window_conf->name);
    window->buffer.create(window_conf->width, window_conf->height);

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

void grlib_set_pixel(grlib_window *window, uint8_t x, uint8_t y, rgb_config rgb)
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