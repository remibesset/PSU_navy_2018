/*
** EPITECH PROJECT, 2019
** hit function
** File description:
** hit and verif
*/

#include "navy.h"

int verification_victory(void)
{
    int count_player1 = 0;
    int count_player2 = 0;

    for (int i = 0; i < NBR_LINE; i++)
        for (int j = 0; j < NBR_COL; j++) {
            count_player1 += (GAME.owner.my_map[i][j] == 'x') ? 1 : 0;
            count_player2 += (GAME.owner.enemy_map[i][j] == 'x') ? 1 : 0;
        }
    if (count_player1 == 15) {
        my_putstr("\nEnemy won\n\n");
        GAME.win = 1;
    } else if (count_player2 == 15) {
        my_putstr("\nI won\n\n");
        GAME.win = 0;
    }
    return (0);
}

int change_hit_on_map(player_t *player, hit_t pos)
{
    if (pos.hit == 1) {
        player->my_map[pos.y][pos.x] = 'x';
        my_putchar(pos.x + 'A');
        my_putchar(pos.y + '1');
        my_putstr(":  hit\n");
        emit("1");
    } else if (pos.hit == 0) {
        player->my_map[pos.y][pos.x] = 'o';
        my_putchar(pos.x + 'A');
        my_putchar(pos.y + '1');
        my_putstr(":  missed\n");
        emit("0");
    }
    return (0);
}

int reach_to_hit(player_t *player, hit_t pos)
{
    hit_t hit_pos;

    if (player->my_map[pos.y][pos.x] >= '2' &&
    player->my_map[pos.y][pos.x] <= '5') {
        hit_pos = (hit_t) {pos.x, pos.y, 1};
        change_hit_on_map(player, hit_pos);
    } else if (player->my_map[pos.y][pos.x] == '.') {
        hit_pos = (hit_t) {pos.x, pos.y, 0};
        change_hit_on_map(player, hit_pos);
    } else {
        my_putstr(": already hit\n ");
    }
    return (0);
}

int hit_the_enemey_map(player_t *player, char *str)
{
    int x = 0;
    int y = 0;
    hit_t hit_pos;

    if (my_strlen(str) == 2 && str[0] >= 'A' && str[0] <= 'H' &&
    str[1] >= '1' && str[1] <= '8') {
        x = str[0] - 'A';
        y = str[1] - '1';
        hit_pos = (hit_t) {x, y};
        reach_to_hit(player, hit_pos);
    } else {
        my_putstr("wrong position\n");
    }
    return (0);
}