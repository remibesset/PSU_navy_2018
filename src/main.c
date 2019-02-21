/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** main minishell1
*/

#include "navy.h"

int enemy_pid = 0;
char shot[9] = {0};

int update_enemy_map(int hit) {
    if (hit == 1)
        GAME.owner.enemy_map[GAME.owner.hit_pos[1] - '0' - 1][GAME.owner.hit_pos[0] - 'A'] = 'x';
    else
        GAME.owner.enemy_map[GAME.owner.hit_pos[1] - '0' - 1][GAME.owner.hit_pos[0] - 'A'] = 'o';
    return (0);
}

int main(int ac, char **av)
{
    struct sigaction info;
    int player = -1;
    struct timespec sleep_time = {60, 0};
    GAME.win = -1;

    init_sig(&info);
    if (ac == 3 && (av[1][0] >= '0' && av[1][0] <= '9')) {
        player = 1;
        enemy_pid = my_getnbr(av[1]);
        syncro(1);
    } else {
        player = 2;
        syncro(0);
    }
    if (player == 1)
        create_map(av[2]);
    if (player == 2)
        create_map(av[1]);
    while (GAME.win == -1) {
        if (player == 1) {
            my_putstr("\nattack:  \e[3m");
            emit(crypt_f(get_next_line(0)));
            if (nanosleep(&sleep_time, NULL) != 0) {
                if (shot[0] == '0') {
                    my_putstr(GAME.owner.hit_pos);
                    my_putstr(":  missed\n\n");
                    update_enemy_map(0);
                } else if (shot[0] == '1') {
                    my_putstr(GAME.owner.hit_pos);
                    my_putstr(":  hit\n\n");
                    update_enemy_map(1);
                }
            } else
                write(2, "timeout\n", 8);
            display_map(GAME.owner);
        } else {
            my_putstr("\n\nwaiting for enemy's attack...\n");
            if (nanosleep(&sleep_time, NULL) != 0) {
                hit_the_enemey_map(&GAME.owner, decrypt(shot));
            } else
                write(2, "timeout\n", 8);
        }
        for (int i = 0; i < 9; i++)
            shot[i] = 0;
        player = (player == 1) ? 2 : 1;
    }
    return(GAME.win);
    return (0);
}
