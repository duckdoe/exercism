#include "armstrong_numbers.h"

int ipow(int base, int exp)
{
    int result = 1;

    for (int i = 0; i < exp; i++)
        result *= base;

    return result;
}

bool is_armstrong_number(int candidate)
{
    char s[10];
    int len = snprintf(s, sizeof(s), "%d", candidate);

    int t = 0;
    for (int i = 0; i < len; i++)
    {
        int c = s[i] - '0';
        t += ipow(c, len);
    }
    return candidate == t;
}