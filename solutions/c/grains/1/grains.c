#include "grains.h"
#include <stdio.h>

uint64_t square(uint8_t index)
{
    uint64_t base = 2;
    int i;

    if (index == 1)
        return 1;
    else if (index == 0)
        return 0;

    i = index - base;
    return base << i;
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