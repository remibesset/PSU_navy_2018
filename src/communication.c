/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** main
*/

#include "navy.h"

int enemy_pid;
char shot[9];
int nbr_sig = 0;

void detect(int index_sig, siginfo_t *info, void *context)
{
    if (index_sig == SIGUSR1) {
        add_bin(shot, '0');
    } else if (index_sig == SIGUSR2) {
        add_bin(shot, '1');
    }
    enemy_pid = info->si_pid;
    usleep(105);
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

void syncro(int player)
{
    struct timespec sleep_time = {60, 0};

    if (player == 0) {
        my_putstr("my_pid:   ");
        my_put_nbr(getpid());
        my_putstr("\nwaiting for enemy connection...\n\n");
        if (nanosleep(&sleep_time, NULL) != 0) {
            my_putstr("enemy connected\n");
	    } else {
            write(2, "Timeout\n", 9);
        }
    }
    if (player == 1) {
        kill(enemy_pid, SIGUSR1);
        my_putstr("my_pid:   ");
        my_put_nbr(getpid());
        my_putstr("\nsuccessfully connected\n");
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

void add_bin(char *str, char bin)
{
    int i = 0;

    while (str[i] != '\0' && i < 8)
        i++;
    str[i] = bin;
}