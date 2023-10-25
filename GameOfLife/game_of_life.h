#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <stddef.h>
#include <stdint.h>

#define WIDTH 1080
#define HEIGHT 720

#ifdef __cplusplus
extern "C" {
#endif

int calculate_neighbors_sum(uint8_t *buffer, int x, int y);
void swap(uint8_t **lhs, uint8_t **rhs);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // GAME_OF_LIFE_H
