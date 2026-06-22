#include "darts.h"

int score(coordinate_t landing_position)
{
    float a = landing_position.x * landing_position.x;
    float b = landing_position.y * landing_position.y;

    float c = sqrt(a + b);

    if (c <= 1)
        return 10;
    else if (c <= 5)
        return 5;
    else if (c <= 10)
        return 1;
    else
        return 0;
}