#include "space_age.h"

float age(planet_t planet, int64_t seconds)
{
    float age;
    float hours = (seconds / 60) / 60;
    float days = hours / 24;
    float planet_days = 365.25;

    switch (planet)
    {
    case MERCURY:
        planet_days = 365.25 * 0.2408467;
        age = days / planet_days;

        break;

    case VENUS:
        planet_days = 365.25 * 0.61519726;
        age = days / planet_days;

        break;

    case EARTH:
        age = days / planet_days;

        break;

    case MARS:
        planet_days = 365.25 * 1.8808158;
        age = days / planet_days;

        break;

    case JUPITER:
        planet_days = 365.25 * 11.862615;
        age = days / planet_days;

        break;

    case SATURN:
        planet_days = 365.25 * 29.447498;
        age = days / planet_days;

        break;

    case URANUS:
        planet_days = 365.25 * 84.016846;
        age = days / planet_days;

        break;

    case NEPTUNE:
        planet_days = 365.25 * 164.79132;
        age = days / planet_days;

        break;

    default:
        return -1;
    }

    return age;
}