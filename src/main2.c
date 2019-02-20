/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** main
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "get_next_line.h"

int enemy_pid = 0;
char shot[9] = {0};

void add_bin(char *str, char bin)
{
    int i = 0;

    while (str[i] != '\0' && i < 8)
        i++;
    str[i] = bin;
}

void detect(int index_sig, siginfo_t *info, void *context)
{
    if (index_sig == SIGUSR1) {
        add_bin(shot, '0');
    } else if (index_sig == SIGUSR2)
        add_bin(shot, '1');
    usleep(100);
    enemy_pid = info->si_pid;
}

void syncro(int player)
{
    struct timespec sleep_time = {60, 0};

    if (player == 0) {
        printf("my_pid:   %d\nwaiting for enemy connection...\n\n", getpid());
        if (nanosleep(&sleep_time, NULL) != 0) {
            printf("enemy connected\n");
        } else {
            perror("timeout");
        }
    }
    if (player == 1)
        kill(enemy_pid, SIGUSR1);
}

void emit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0')
            kill(enemy_pid, SIGUSR1);
        else if (str[i] == '1')
            kill(enemy_pid, SIGUSR2);
        usleep(100);
    }
}

void init_sig(struct sigaction *info)
{
    sigemptyset(&info->sa_mask);
    info->sa_handler = NULL;
    info->sa_restorer = NULL;
    info->sa_flags = SA_SIGINFO;
    info->sa_sigaction = detect;
    if (sigaction(SIGUSR1, info, NULL) == -1)
        write(2, "Troubles when receiving signal\n", 33);
    if (sigaction(SIGUSR2, info, NULL) == -1)
        write(2, "Troubles when receiving signal\n", 33);
}

int game(int ac, char **av)
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
    } while (GAME.win == -1) {
        if (player == 1) {
            write(1, "attack:  ", 10);
            emit(crypte(get_next_line(0)));
        } else {
            if (nanosleep(&sleep_time, NULL) != 0) {
                my_putstr(decrypt(shot));
            } else
                write(2, "timeout\n", 8);
        }
        for (int i = 0; i < 9; i++)
            shot[i] = 0;
        player = (player == 1) ? 2 : 1;
    }
    return (0);
}
