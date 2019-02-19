/*
** EPITECH PROJECT, 2019
** display map
** File description:
** display map
*/

#include "navy.h"

int turn_display(int my_turn)
{
    char *s = NULL;

    my_putstr("attack: ");
    s = get_next_line(0);
    if (s == NULL)
        return (1);
    if (my_strlen(s) < 2 || my_strlen(s) > 2) {
        my_putstr("wrong position\n");
        turn_display(my_turn);
    }
    if (my_turn == 0)
        hit_the_enemey_map(&GAME.enemy, &GAME.owner, s, my_turn);
    else if (my_turn == 1)
        hit_the_enemey_map(&GAME.owner, &GAME.enemy, s, my_turn);
    else
        return (ERROR_NUM);
}

void header_display_map(int my_pos)
{
    my_putstr((my_pos == 0) ? "my positions:\n" : "\n\nenemy’s positions:\n");
    my_putstr(" |A B C D E F G H\n-+---------------\n");
}

void display_map(player_t player)
{
    header_display_map(0);
    for (int i = 0; i < NBR_LINE; i++) {
        my_putchar(i + 49);
        my_putstr("|");
        for (int j = 0; j < NBR_COL; j++) {
            my_putchar(player.my_map[i][j]);
            my_putstr(" ");
        }
        my_putchar('\n');
    }
    header_display_map(1);
    for (int i = 0; i < NBR_LINE; i++) {
        my_putchar(i + 49);
        my_putstr("|");
        for (int j = 0; j < NBR_COL; j++) {
            my_putchar(player.enemy_map[i][j]);
            my_putstr(" ");
        }
        my_putchar('\n');
    }
}