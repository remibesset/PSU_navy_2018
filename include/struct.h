/*
** EPITECH PROJECT, 2019
** struct of navy
** File description:
** structure
*/

#ifndef STRUCT_H
#define STRUCT_H

#define GAME game_t

typedef struct player_s
{
    char my_map[8][9];
    char enemy_map[8][9];
}player_t;

typedef struct game_s
{
    player_t enemy;
    player_t owner;
    char *filepath;
}game_t;


#endif