/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** main minishell1
*/

#include "navy.h"

void helper(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\nDESCRIPTION\n\
\tfirst_player_pid: only for the 2nd player. pid of the first player.\n\
\tnavy_positions: file representing the positions of the ships.\n");
}

int main(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2)
        helper();
    else if (ac == 2 || ac == 3) {
        if (ac == 2) {
            GAME.filepath = av[1];
            create_map(GAME.filepath, 0);
            create_map("pos2", 1);
            while (1 == 1) {
                my_putstr("\n\n\n#########################################################\n");
                turn_display(0);
                display_map(GAME.owner);
                display_map(GAME.enemy);
            }
        } else if (ac == 3) {
            GAME.filepath = av[2];
            create_map(GAME.filepath, 1);
        }
    } else
        return (84);
    return (0);
}
