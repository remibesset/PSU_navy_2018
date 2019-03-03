/*
** EPITECH PROJECT, 2019
** navy
** File description:
** crypt and decrypt positions
*/

#include "navy.h"

char *crypt_f(char *str)
{
    char *crypted;

    my_putstr("\e[0m");
    GAME.owner.hit_pos[0] = str[0];
    GAME.owner.hit_pos[1] = str[1];
    usleep(100);
    str[1] -= 1;
    if (str[0] < 65 || str[0] > 72) {
        my_putstr("wrong position\n");
        write(1, "attack:  ", 10);
        crypted = crypt_f(get_next_line(0));
    } else if (str[1] < 48 || str[1] >= 56 || my_strlen(str) != 2) {
        my_putstr("\nwrong position\n");
        write(1, "attack:  ", 10);
        crypted = crypt_f(get_next_line(0));
    } else
        crypted = my_strcat(dec_to_bin(str[1] - 48), dec_to_bin(str[0] - 65));
    free(str);
    return (crypted);
}

char decrypt_letter(char *letter)
{
    char col;

    col = bin_to_dec(letter) + 65;
    free(letter);
    return (col);
}

char *decrypt(char *str)
{
    char *decrypt = malloc(sizeof(char) * 3);
    char *letter = malloc(sizeof(char) * 5);
    int i = 0;

    if (my_strlen(str) == 9)
        str += 1;
    for (i = 0; i < 4; i++)
        letter[i] = str[i];
    letter[i] = '\0';
    decrypt[0] = decrypt_letter(letter);
    decrypt[1] = bin_to_dec(str + 4) + 49;
    decrypt[2] = '\0';
    return (decrypt);
}
