#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
   CAN_NOT_ATTACK,
   CAN_ATTACK,
   INVALID_POSITION
} attack_status_t;

typedef struct
{
   uint8_t row;
   uint8_t column;
} position_t;

bool check_left_diagonal(position_t queen_1, position_t queen_2);
bool check_right_diagonal(position_t queen_1, position_t queen_2);
bool check_vertical(position_t queen_1, position_t queen_2);
bool check_horizontal(position_t queen_1, position_t queen_2);
bool is_valid_position(position_t queen);

attack_status_t can_attack(position_t queen_1, position_t queen_2);

#endif
