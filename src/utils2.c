/*
** EPITECH PROJECT, 2019
** utils 2
** File description:
** utils
*/

#include "navy.h"

int my_put_nbr_print(int nb)
{
    if (nb >= 10)
        my_put_nbr_print(nb/10);
    my_putchar('0' + (nb % 10));
}

int my_put_nbr(int nb)
{
    if (nb == -2147836348) {
        my_putchar('-');
        my_putchar('2');
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    my_put_nbr_print(nb);
    return (0);
}