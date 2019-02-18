/*
** EPITECH PROJECT, 2019
** parse map
** File description:
** parsing the map of positionboat
*/

#include "navy.h"

char **create_map(char *filepath, int host)
{
    for (int i = 0; host == 0 && i < NBR_LINE; i++)
        for (int j = 0; j < NBR_COL; j++) {
            GAME.owner.my_map[i][j] = '.';
            GAME.owner.enemy_map[i][j] = '.';
        }
    for (int i = 0; host == 1 && i < NBR_LINE; i++)
        for (int j = 0; j < NBR_COL; j++) {
            GAME.enemy.my_map[i][j] = '.';
            GAME.enemy.enemy_map[i][j] = '.';
        }
}