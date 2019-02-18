/*
** EPITECH PROJECT, 2019
** error
** File description:
** eroor
*/

#include "navy.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}