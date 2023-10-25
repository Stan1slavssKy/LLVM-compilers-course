#include "grlib/graph_lib.h"

#include "game_of_life.h"

extern "C" void app();

int main()
{
    grlib_init(WIDTH, HEIGHT, "GameOfLife", 0);
    app();

    return 0;
}

void swap(uint8_t **lhs, uint8_t **rhs)
{
    uint8_t *temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int calculate_neighbors_sum(uint8_t *buffer, int x, int y)
{
    int sum = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            sum += *(buffer + WIDTH * ((y + j + HEIGHT) % HEIGHT) + ((x + i + WIDTH) % WIDTH));
        }
    }

    sum -= *(buffer + WIDTH * y + x);

    return sum;
}
