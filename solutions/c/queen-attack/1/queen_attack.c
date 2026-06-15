#include "queen_attack.h"

bool check_left_diagonal(position_t queen_1, position_t queen_2)
{
    int row = queen_1.row;
    int column = queen_1.column;

    while (column > 0 && row > 0) // check backwards
    {
        if (column == queen_2.column && row == queen_2.row)
            return true;

        column--, row--;
    }

    while (column < 7 && row < 7) // check forwards
    {
        if (column == queen_2.column && row == queen_2.row)
            return true;

        column++, row++;
    }

    return false;
}

bool check_right_diagonal(position_t queen_1, position_t queen_2)
{
    int row = queen_1.row;
    int column = queen_1.column;

    while (row > 0 && column < 7) // check backwards
    {
        if (column == queen_2.column && row == queen_2.row)
            return true;

        column++, row--;
    }

    while (column < 7 && row < 7) // check forwards
    {
        if (column == queen_2.column && row == queen_2.row)
            return true;

        column--, row++;
    }

    return false; // false: queen_2 is not found in any position
}

bool check_vertical(position_t queen_1, position_t queen_2)
{
    return queen_1.row == queen_2.row;
}

bool check_horizontal(position_t queen_1, position_t queen_2)
{
    return queen_1.column == queen_2.column;
}

bool is_valid_position(position_t queen)
{
    return (queen.row > 0 && queen.row < 7) || (queen.column > 0 && queen.row < 7);
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (!is_valid_position(queen_1) || !is_valid_position(queen_2))
    {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
    {
        return INVALID_POSITION;
    }

    if (check_vertical(queen_1, queen_2) ||
        check_horizontal(queen_1, queen_2) ||
        check_left_diagonal(queen_1, queen_2) ||
        check_right_diagonal(queen_1, queen_2))

    {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}