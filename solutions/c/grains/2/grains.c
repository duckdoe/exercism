#include "grains.h"
#include <stdio.h>

uint64_t square(uint8_t index)
{
    uint64_t out = 1;

    if (index < 1 || index > 64)
        return 0;

    return out << (index - 1);
}

uint64_t total(void)
{
    uint64_t total = 0;

    for (int i = 1; i <= 64; i++)
    {
        total += square(i);
    }

    return total;
}