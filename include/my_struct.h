/*
** EPITECH PROJECT, 2019
** struct of navy
** File description:
** structure
*/

#ifndef MYSTRUCT_H
#define MYSTRUCT_H

#define NBR_LINE 8
#define NBR_COL 8
#define GAME game_t
#define ERROR_NUM 84

typedef struct hit_s
{
    int x;
    int y;
    int hit;
}hit_t;

typedef struct player_s
{
    char my_map[8][9];
    char enemy_map[8][9];
}player_t;

struct game_s
{
    player_t enemy;
    player_t owner;
    char *filepath;
}game_t;

#endif