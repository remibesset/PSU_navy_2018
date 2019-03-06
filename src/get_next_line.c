/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** get next line
*/

#include "navy.h"

char *put_in_save(char *save, char *buffer, int j)
{
    j += 1;
    int i = 0;
    char *new_save = malloc(sizeof(char) * (READ_SIZE - j + 2));

    if (new_save == NULL)
        return (NULL);
    for (j; buffer[j] != '\0'; j++)
        new_save[i++] = buffer[j];
    new_save[i] = '\0';
    free(save);
    return (new_save);
}

int verification_save(char **save, char **str, int *i)
{
    int j = 0;

    if (*save == NULL)
        return (0);
    for (j; (*save)[j] != '\0'; j++) {
        if ((*save)[j] != '\n' && (*save)[j] != '\r') {
            (*str)[*i] = (*save)[j];
            (*i)++;
        } else if ((*save)[j] == '\n') {
            (*str)[*i] = '\0';
            *save = put_in_save(*save, *save, j);
            return (1);
        }
    }
    (*str)[(*i)] = '\0';
    return (0);
}

int complete_str(char **str, char *buffer, int *i, char **save)
{
    int passed = 0;

    for (int j = 0; j < READ_SIZE && passed == 0; j++) {
        if ((*str = (buffer[j] != '\n') ? my_realloc(*str) : *str) == NULL)
            return (-1);
        (*str)[(*i)++] = (buffer[j] != '\n' && buffer[j] != '\r')\
        ? buffer[j] : '\0';
        *save = (buffer[j] == '\n') ? put_in_save(*save, buffer, j) : *save;
        passed = (buffer[j] == '\n' || buffer[j] == '\0') ? 1 : 0;
    }
    if (passed == 1)
        return (1);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * READ_SIZE + 1);
    static char *save;
    static char buffer[READ_SIZE];
    int i = 0;
    int static rd = 0;
    int passed = 0;

    for (int j = 0; str != NULL && j < READ_SIZE && passed == 0; j++) {
        str[j] = '\0';
        buffer[j] = '\0';
    }
    if (rd > 0 && verification_save(&save, &str, &i) == 1 && str != NULL)
        return (str);
    while (rd = read(fd, buffer, READ_SIZE) > 0 && fd >= 0 && str != NULL) {
        if ((passed = complete_str(&str, buffer, &i, &save)) == -1)
            return (NULL);
        for (int j = 0; j < READ_SIZE && passed == 0; j++) {buffer[j] = '\0';}
        if (passed == 1)
            break;
    }
    return (str = (rd == 0 || fd == -1 || str == NULL) ? NULL : str);
}