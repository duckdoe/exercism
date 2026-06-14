#include "luhn.h"

bool luhn(const char *num)
{
    int len = strlen(num);
    int total = 0;
    int i = len - 1;
    int checked = 0;

    while (i >= 0)
    {
        char c = *(num + i);

        if (c == ' ')
        {
            i--;
            continue;
        }

        if (c < '0' || c > '9')
            return false;

        int n = c - '0';

        if (checked % 2 == 0)
        {
            total += n; // Add untransformed numbers too

            i--;
            checked++;
            continue;
        }

        int dobl = n * 2;

        if (dobl > 9)
            dobl -= 9;

        total += dobl;
        i--;
        checked++;
    }

    printf("%d\n", checked);

    return total % 10 == 0 && checked > 1;
}