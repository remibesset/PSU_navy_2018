/*
** EPITECH PROJECT, 2018
** my
** File description:
** .h
*/

#ifndef NAVY_H
#define NAVY_H

#define NBR_LINE 8
#define NBR_COL 9

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "get_next_line.h"
#include "struct.h"

int my_strlen(char *str);
void my_putstr(char *str);
int my_atoi(char *str);
void *xmalloc(int size);
char *my_strcat(char *dest, char *src);
int my_getnbr(char *str);
char *int_to_str(int nbr);
char *my_revstr(char *str);
char *my_realloc(char *src);
char *put_in_save(char *save, char *buffer, int j);
int verification_save(char **save, char **str, int *i);
int complete_str(char **str, char *buffer, int *i, char **save);
char *get_next_line(int fd);
void header_display_map(int my_pos);
void display_map(player_t player, int disp_en_map);
char **create_map(char *filepath, int host);
char *format(char *binary);
char *dec_to_bin(int nbr);
int bin_to_dec(char *str);
char *crypt(char *str);
char decrypt_letter(char *letter);
char *decrypt(char *str);

#endif
