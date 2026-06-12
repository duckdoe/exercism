#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number)
{
    unsigned int total_square = 0;
    unsigned int i;

    for (i = 1; i <= number; i++)
    {
        unsigned int square = i * i;
        total_square += square;
    }

    return total_square;
}

unsigned int square_of_sum(unsigned int number)
{
    unsigned int total = (number * (number + 1) / 2);

    unsigned int square = total * total;
    return square;
}

unsigned int difference_of_squares(unsigned int number)
{
    return square_of_sum(number) - sum_of_squares(number);
}