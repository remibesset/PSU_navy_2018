/*
** EPITECH PROJECT, 2019
** display map
** File description:
** display map
*/

#include "navy.h"

void header_display_map(int my_pos)
{
    my_putstr((my_pos == 0) ? "\nmy positions:\n" : "\nenemy’s positions:\n");
    my_putstr(" |A B C D E F G H\n-+---------------\n");
}

void display_map(player_t player)
{
    header_display_map(0);
    for (int i = 0; i < NBR_LINE; i++) {
        my_putchar(i + 49);
        my_putchar('|');
        for (int j = 0; j < NBR_COL; j++) {
            my_putchar(player.my_map[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
    header_display_map(1);
    for (int i = 0; i < NBR_LINE; i++) {
        my_putchar(i + 49);
        my_putchar('|');
        for (int j = 0; j < NBR_COL; j++) {
            my_putchar(player.enemy_map[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}