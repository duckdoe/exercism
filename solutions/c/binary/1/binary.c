#include "binary.h"
#include <string.h>
#include <stdio.h>

#define BASE 2

int power(int base, int p)
{
    int total = base;

    if (p == 0)
        return 1;

    for (; p > 1; p--)
    {
        total *= base;
    }

    return total;
}

int convert(const char *input)
{
    int len = strlen(input) - 1; // zero-based length

    int tmp = len; // copy value for power operations later
    int total = 0;

    for (; len > -1; len--)
    {
        char c = input[len];
        int n = c - '0'; // gets us the '1' '0' number

        if (n > 1 || n < 0)
            return INVALID;

        int pow = tmp - len;

        total += n * power(BASE, pow);
    }

    return total;
}