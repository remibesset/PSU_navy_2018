/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** CPool functions
*/

#include "../include/navy.h"

char *my_strcat(char *dest, char *src)
{
    char *result =
    malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int i = 0;
    int j = 0;

    while (src[i] != '\0') {
        result[i] = src[i];
        i++;
    }
    while (dest[j] != '\0')
        result[i++] = dest[j++];
    result[i] = '\0';
    free(dest);
    free(src);
    return (result);
}

int my_getnbr(char *str)
{
    int result = 0;
    int i = 0;
    int sub = 0;
    int size = my_strlen(str);

    if (str[i] == '-')
        return (-1);
    while (i < size) {
        if (sub == 1)
            result = result * 10 - (str[i] - '0');
        else
            result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

char *int_to_str(int nbr)
{
    char *str;
    int size = 0;
    int nbr2 = nbr;
    int i = 0;

    for (size; nbr2 != 0; size++)
        nbr2 /= 10;
    str = malloc(sizeof(char) * (size + 1));
    for (i = 0; nbr != 0; i++) {
        str[i] = nbr % 10 + 48;
        nbr /= 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

char *my_revstr(char *str)
{
    int i = 0;
    int max = my_strlen(str);
    int j = max - 1;
    char *temp = malloc(sizeof(char) * (max + 1));

    while (i < max) {
        temp[i] = str[j];
        i++;
        j--;
    }
    temp[i] = '\0';
    free(str);
    return (temp);
}