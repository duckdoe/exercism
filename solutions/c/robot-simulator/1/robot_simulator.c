#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_position_t position = {x, y};
    robot_status_t robot = {direction, position};

    return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    int command_length = strlen(commands);
    int direction = robot->direction;

    for (int i = 0; i < command_length; i++)
    {
        char command = commands[i];

        switch (command)
        {

        case 'R':
            // For wrapping the direction around
            direction = (direction + 1) % 4;
            robot->direction = (robot_direction_t)direction; // Turns it into a robot_direction_t enum

            break;

        case 'L':
            // Also for wrapping the direction around
            direction = direction > 0 ? (direction - 1) % 4 : (direction - 1) + 4; // avoids *native* integer wrapping for C
            robot->direction = (robot_direction_t)direction;                       // Turns it into a robot_direction_t enum

            break;

        case 'A':
            // One from the x, y coordinates have to be changed
            // based on where the robot is facing

            if (robot->direction == DIRECTION_NORTH)
                robot->position.y++;
            else if (robot->direction == DIRECTION_EAST)
                robot->position.x++;
            else if (robot->direction == DIRECTION_SOUTH)
                robot->position.y--;
            else if (robot->direction == DIRECTION_WEST)
                robot->position.x--;

            break;

        default:
            break;
        }
    }
}