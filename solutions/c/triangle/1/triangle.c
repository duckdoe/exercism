#include "triangle.h"

bool is_valid_triangle(triangle_t s)
{
    return (s.a + s.b >= s.c) && (s.b + s.c >= s.a) && (s.c + s.a >= s.b) && (s.a > 0) && (s.b > 0) && (s.c > 0);
}

bool is_scalene(triangle_t s)
{
    if (!is_valid_triangle(s))
        return false;

    return (s.a != s.b) && (s.a != s.c) && (s.b != s.c);
}
bool is_isosceles(triangle_t s)
{
    if (!is_valid_triangle(s))
        return false;

    return (s.a == s.b) || (s.a == s.c) || (s.b == s.c);
}
bool is_equilateral(triangle_t s)
{
    if (!is_valid_triangle(s))
        return false;

    return (s.a == s.b) && (s.a == s.c) && (s.b == s.c);
}