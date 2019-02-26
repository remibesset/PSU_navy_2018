/*
** EPITECH PROJECT, 2019
** navy
** File description:
** change bases
*/

#include "navy.h"

int bin_to_dec(char *str)
{
    int i = 0;
    int nbr = 0;

    for (i; str[i] != '\0'; i++) {
        nbr *= 2;
        nbr += str[i] - 48;
    }
    return (nbr);
}

char *dec_to_bin(int nbr)
{
    char *binary;
    int i = 0;
    int size = 0;
    int nbr4size = nbr;

    for (size; nbr4size != 0; size++)
        nbr4size /= 2;
    binary = malloc(sizeof(char) * size + 1);
    for (i; nbr != 0; i++) {
        binary[i] = 48 + nbr % 2;
        nbr /= 2;
    }
    binary[i] = '\0';
    binary = my_revstr(binary);
    binary = format(binary);
    return (binary);
}

char *format(char *binary)
{
    char *formated;
    int i = 0;

    if (my_strlen(binary) != 4) {
        formated = malloc(sizeof(char) * 5);
        for (i; i < 4 - my_strlen(binary); i++)
            formated[i] = '0';
    }
    for (int j = 0; i < 4; j++)
        formated[i++] = binary[j];
    formated[i] = 0;
    free(binary);
    return (formated);
}
