/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** main minishell1
*/

#include "navy.h"

int update_enemy_map(int hit)
{
    if (hit == 1)
        GAME.owner.enemy_map[GAME.owner.hit_pos[1] - '0' - 1]\
        [GAME.owner.hit_pos[0] - 'A'] = 'x';
    else
        GAME.owner.enemy_map[GAME.owner.hit_pos[1] - '0' - 1]\
        [GAME.owner.hit_pos[0] - 'A'] = 'o';
    return (0);
}

int init_all(int *player, char **av, int ac, struct sigaction *info)
{
    GAME.win = -1;
    for (int i = 0; i < 9; GAME.shot[i] = '\0', i++);
    GAME.nbr_play = 0;
    GAME.enemy_pid = 0;
    init_sig(info);
    if (ac == 3 && (av[1][0] >= '0' && av[1][0] <= '9')) {
        *player = 1;
        GAME.enemy_pid = my_getnbr(av[1]);
        if (create_map(av[2]) == ERROR_NUM)
            return (ERROR_NUM);
        syncro(1);
    } else if (ac == 2) {
        *player = 2;
        if (create_map(av[1]) == ERROR_NUM)
            return (ERROR_NUM);
        syncro(0);
    } else
        return (ERROR_NUM);
    return (0);
}

int player_hit(struct timespec sleep_time)
{
    my_putstr("\nattack:  \e[3m");
    emit(crypt_f(get_next_line(0)));
    if (nanosleep(&sleep_time, NULL) != 0) {
        if (GAME.shot[my_strlen(GAME.shot) - 1] == '0' &&
        my_strlen(GAME.shot) != 2) {
            my_putstr(GAME.owner.hit_pos);
            my_putstr(":  missed\n");
            update_enemy_map(0);
        } else if (GAME.shot[my_strlen(GAME.shot) - 1] == '1') {
            my_putstr(GAME.owner.hit_pos);
            my_putstr(":  hit\n");
            update_enemy_map(1);
        }
    } else {
        write(2, "timeout\n", 8);
        GAME.win = 84;
    }
    GAME.nbr_play++;
    return (0);
}

int player_recept(struct timespec sleep_time)
{

    my_putstr("\nwaiting for enemy's attack...\n");
    if (nanosleep(&sleep_time, NULL) != 0) {
        usleep(4000);
        if (my_strlen(GAME.shot) == 8)
            hit_the_enemey_map(&GAME.owner, decrypt(GAME.shot));
    } else {
        write(2, "timeout\n", 8);
        GAME.win = 84;
    }
    GAME.nbr_play++;
    verification_victory();
}

int main(int ac, char **av)
{
    struct sigaction info;
    int player = -1;
    struct timespec sleep_time = {60, 0};

    if (init_all(&player, av, ac, &info) == ERROR_NUM)
        return (ERROR_NUM);
    while (GAME.win == -1) {
        if (GAME.nbr_play % 2 == 0)
            display_map(GAME.owner);
        if (player == 2)
            player_hit(sleep_time);
        else
            player_recept(sleep_time);
        for (int i = 0; i < 9; i++)
            GAME.shot[i] = '\0';
        player = (player == 1) ? 2 : 1;
    }
    return (GAME.win);
}
