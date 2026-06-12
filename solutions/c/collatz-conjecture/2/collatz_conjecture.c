#include "collatz_conjecture.h"
#include <stdio.h>

int steps(int start)
{
    int count = 0;

    if (start < 1)
        return ERROR_VALUE;

    while (start > 1)
    {
        count++;

        if ((start % 2) == 0)
            start /= 2;
        else
            start = (start * 3) + 1;
    }

    return count;
}