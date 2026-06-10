#include "leap.h"

bool leap_year(int year)

{
    bool leap_year = year % 4 == 0 && year % 100 != 0;

    if (leap_year)
        return true;
    else
        return year % 400 == 0;
}