/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** main minishell1
*/

#include "navy.h"

int enemy_pid = 0;
char shot[9] = {0};

int main(int ac, char **av)
{
    struct sigaction info;
    int player = -1;
    struct timespec sleep_time = {60, 0};

    init_sig(&info);
    if (ac == 3 && (av[1][0] >= '0' && av[1][0] <= '9')) {
        player = 1;
        enemy_pid = my_getnbr(av[1]);
        syncro(1);
    } else {
        syncro(0);
        player = 2;
    }
    if (player == 1)
        create_map(av[2]);
    if (player == 2)
        create_map(av[1]);
    while (1) {
        if (player == 1) {
            display_map(GAME.owner);
            write(1, "attack:  ", 10);
            emit(crypt_f(get_next_line(0)));
            if (nanosleep(&sleep_time, NULL) != 0) {
                if (shot[0] == '0')
                    my_putstr("Missed");
                else if (shot[0] == '1')
                    my_putstr("Touché");
            } else
                write(2, "timeout\n", 8);
        } else {
            if (nanosleep(&sleep_time, NULL) != 0) {
                my_putstr(decrypt(shot));
                hit_the_enemey_map(&GAME.owner, decrypt(shot));
            } else
                write(2, "timeout\n", 8);
        }
        for (int i = 0; i < 9; i++)
            shot[i] = 0;
        player = (player == 1) ? 2 : 1;
    }
    return (0);
}
