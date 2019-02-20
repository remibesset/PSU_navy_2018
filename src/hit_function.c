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
            count_player1 += (GAME.owner.my_map[i][j] >= '2' &&\
            GAME.owner.my_map[i][j] <= '5') ? 1 : 0;
            count_player2 += (GAME.enemy.my_map[i][j] >= '2' &&\
            GAME.enemy.my_map[i][j] <= '5') ? 1 : 0;
        }
    if (count_player1 == 0) {
        my_putstr("\nEnemy won\n\n");
        GAME.win = 1;
    } else if (count_player2 == 0) {
        my_putstr("\nI won\n\n");
        GAME.win = 0;
    }
    return (0);
}

int change_hit_on_map(player_t *ot_player, player_t *player, hit_t pos)
{
    if (pos.hit == 1) {
        ot_player->my_map[pos.y][pos.x] = 'x';
        player->enemy_map[pos.y][pos.x] = 'x';
        my_putstr(": hit\n\n");
    } else if (pos.hit == 0) {
        ot_player->my_map[pos.y][pos.x] = 'o';
        player->enemy_map[pos.y][pos.x] = 'o';
        my_putstr(": missed\n\n");
    }
    return (0);
}

int reach_to_hit(player_t *ot_player, player_t *player, hit_t pos)
{
    hit_t hit_pos;

    if (ot_player->my_map[pos.y][pos.x] >= '2' &&
    ot_player->my_map[pos.y][pos.x] <= '5') {
        hit_pos = (hit_t) {pos.x, pos.y, 1};
        change_hit_on_map(ot_player, player, hit_pos);
    } else if (ot_player->my_map[pos.y][pos.x] == '.') {
        hit_pos = (hit_t) {pos.x, pos.y, 0};
        change_hit_on_map(ot_player, player, hit_pos);
    } else {
        my_putstr(": already hit\n ");
        turn_display(pos.hit);
    }
    return (0);
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
        hit_pos = (hit_t) {x, y, my_turn};
        reach_to_hit(ot_player, player, hit_pos);
    } else {
        my_putstr("wrong position\n");
        turn_display(my_turn);
    }
    return (0);
}