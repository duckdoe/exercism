#include "clock.h"

const int minute_in_hour = 60;
const int hour_in_day = 24;

int wrap_int(int n, int rate)
{
    bool is_negative = false;

    if (n < 0)
    {
        n *= -1;
        is_negative = true;
    }

    while (n >= rate)
        n %= rate;

    if (n == 0)
        return n;

    return !is_negative ? n : rate - n;
}

clock_type clock_create(int hour, int minute)
{
    clock_type clock;

    int h = wrap_int(hour, hour_in_day);
    int m = wrap_int(minute, minute_in_hour);

    if (minute >= 60)
    {
        int added_hours = minute / minute_in_hour;
        h += added_hours;
    }
    else if (minute < 0)
    {
        int time_before_next_hour = minute_in_hour - wrap_int(minute, minute_in_hour);

        if (time_before_next_hour == minute_in_hour)
            time_before_next_hour = 0;

        int total = time_before_next_hour + (minute * -1);
        int res = (int)round((double)total / minute_in_hour);

        h -= res;
        printf("hour: %d, res: %d, total: %d\n", h, res, total);
    }

    h = wrap_int(h, hour_in_day);

    snprintf(clock.text, MAX_STR_LEN + 1, (h >= 10 && m >= 10) ? "%d:%d" : (h < 10 && m >= 10) ? "0%d:%d"
                                                                       : (h >= 10 && m < 10)   ? "%d:0%d"
                                                                                               : "0%d:0%d",
             h, m);

    return clock;
}

clock_type clock_add(clock_type clock, int minute_add)
{

    char h[3] = {clock.text[0], clock.text[1], '\0'};
    char m[3] = {clock.text[3], clock.text[4], '\0'};

    int hour = atoi(h);

    int min = atoi(m);

    min += minute_add;

    if (min >= 60)
    {
        int added_hours = min / minute_in_hour;
        hour += added_hours;
    }

    min = wrap_int(min, minute_in_hour);
    hour = wrap_int(hour, hour_in_day);

    clock_type new_clock; // Creates a new clock
    snprintf(new_clock.text, MAX_STR_LEN + 1, (hour >= 10 && min >= 10) ? "%d:%d" : (hour < 10 && min >= 10) ? "0%d:%d"
                                                                                : (hour >= 10 && min < 10)   ? "%d:0%d"
                                                                                                             : "0%d:0%d",
             hour, min);

    return new_clock;
}

clock_type clock_subtract(clock_type clock, int minute_subtract)
{
    char h[3] = {clock.text[0], clock.text[1], '\0'};
    char m[3] = {clock.text[3], clock.text[4], '\0'};

    int hour = atoi(h);
    int min = atoi(m);

    int time_left_before_next_hour = minute_in_hour - min;

    min -= minute_subtract;

    if (min < 0)
    {
        int subtracted_hours = (time_left_before_next_hour + minute_subtract) / minute_in_hour;
        hour = atoi(h) - subtracted_hours;
    }

    min = wrap_int(min, minute_in_hour);
    hour = wrap_int(hour, hour_in_day);

    printf("%d\n", hour);

    clock_type new_clock; // Creates a new clock
    snprintf(new_clock.text, MAX_STR_LEN + 1, (hour >= 10 && min >= 10) ? "%d:%d" : (hour < 10 && min >= 10) ? "0%d:%d"
                                                                                : (hour >= 10 && min < 10)   ? "%d:0%d"
                                                                                                             : "0%d:0%d",
             hour, min);

    return new_clock;
}

bool clock_is_equal(clock_type a, clock_type b)
{
    char ah[3] = {a.text[0], a.text[1], '\0'};
    char am[3] = {a.text[3], a.text[4], '\0'};

    char bh[3] = {b.text[0], b.text[1], '\0'};
    char bm[3] = {b.text[3], b.text[4], '\0'};

    int int_ah = atoi(ah);
    int int_am = atoi(am);

    int int_bh = atoi(bh);
    int int_bm = atoi(bm);

    int_ah = wrap_int(int_ah, hour_in_day);
    int_am = wrap_int(int_am, minute_in_hour);

    // int time_left_before_next_hour = minute_in_hour - int_am;

    int_bh = wrap_int(int_bh, hour_in_day);
    int_bm = wrap_int(int_bm, minute_in_hour);

    printf("int ah: %d, int am: %d, int bh: %d, int bm: %d\n", int_ah, int_am, int_bh, int_bm);

    return int_ah == int_bh && int_am == int_bm;
}