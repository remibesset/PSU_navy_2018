/*
** EPITECH PROJECT, 2019
** hit function
** File description:
** hit and verif
*/

#include "navy.h"

int position_it_on_map(player_t *ot_player, player_t *player, hit_t pos)
{
    if (pos.hit == 1) {
        ot_player->my_map[pos.y][pos.x] = 'x';
        player->enemy_map[pos.y][pos.x] = 'x';
        my_putstr(": hit\n");
    } else if (pos.hit == 0) {
        ot_player->my_map[pos.y][pos.x] = 'o';
        player->enemy_map[pos.y][pos.x] = 'o';
        my_putstr(": missed\n");
    }
}

int hit_the_enemey_map(player_t *ot_player, player_t *player, char *str,
int my_turn)
{
    int x = 0;
    int y = 0;
    hit_t hit_pos;

    if (my_strlen(str) == 2 && str[0] >= 'A' && str[0] <= 'H' &&
    str[1] >= '1' && str[1] <= '8') {
        x = str[0] - 'A';
        y = str[1] - '1';
        my_putstr(str);
        if (ot_player->my_map[y][x] >= '2' && ot_player->my_map[y][x] <= '5') {
            hit_pos = (hit_t) {x, y, 1};
            position_it_on_map(ot_player, player, hit_pos);
        } else if (ot_player->my_map[y][x] == '.') {
            hit_pos = (hit_t) {x, y, 0};
            position_it_on_map(ot_player, player, hit_pos);
        } else {
            my_putstr(": already hit\n ");
            turn_display(my_turn);
        }
    } else {
        my_putstr("wrong position\n");
        turn_display(my_turn);
    }
}