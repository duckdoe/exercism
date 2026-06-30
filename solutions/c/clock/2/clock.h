#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN sizeof("##:##")

typedef struct
{
   char text[MAX_STR_LEN];
} clock_type;

int wrap_int(int n, int rate);

clock_type clock_create(int hour, int minute);
clock_type clock_add(clock_type clock, int minute_add);
clock_type clock_subtract(clock_type clock, int minute_subtract);
bool clock_is_equal(clock_type a, clock_type b);

#endif
