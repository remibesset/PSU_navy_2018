/*
** EPITECH PROJECT, 2018
** my
** File description:
** .h
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// typedef struct linked_list_a
// {
//     char *data;
//     linked_list_t next;
// }linked_list_t;


typedef struct minishell_s
{
    char *previous_pwd;
    char *pwd;
    char **env;
    char **path;
    int nb_arg_path;
    int pass;
    int run;
    char *buffer;
}minishell_t;


void *xmalloc(int size);
char *my_strcat(char *dest, char *src);
int my_getnbr(char *str);
char *int_to_str(int nbr);
char *my_revstr(char *str);
int my_strlen(char *str);

#endif
