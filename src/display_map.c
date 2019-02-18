/*
** EPITECH PROJECT, 2019
** display map
** File description:
** display map
*/

#include "navy.h"

void header_display_map(int my_pos)
{
    my_putstr((my_pos == 0) ? "my positions:\n" : "\n\nenemy’s positions:\n");
    my_putstr("|A B C D E F G H\n-+---------------\n");
}

void display_map(player_t player, int disp_en_map)
{
    header_display_map(0);
    for (int i = 0; i < NBR_LINE; i++) {
        my_putstr(i);
        my_putstr("|");
        my_putstr(player.my_map[i]);
    }
    header_display_map(1);
    for (int i = 0; i < NBR_LINE; i++) {
        my_putstr(i);
        my_putstr("|");
        my_putstr(player.enemy_map[i]);
    }
}