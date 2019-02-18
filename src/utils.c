/*
** EPITECH PROJECT, 2019
** utils function
** File description:
** utils
*/

#include "navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_atoi(char *str)
{
    int result = 0;
    int i = 0;
    int sub = 0;

    for (i; str[i] != '\n' && str[i] != '\0'; i++);
    str[i] = '\0';
    i = 0;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        if (sub == 1)
            result = result * 10 - (str[i] - '0');
        else
            result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

char *my_realloc(char *src)
{
    char *str = NULL;
    int i = 0;

    for (i = 0; src[i] != '\0'; i++);
    str = malloc(sizeof(char) * (i + 2));
    i = 0;
    if (str == NULL)
        return (NULL);
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    str[i + 1] = '\0';
    free(src);
    return (str);
}