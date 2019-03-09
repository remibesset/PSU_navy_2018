/*
** EPITECH PROJECT, 2019
** parse map
** File description:
** parsing the map of positionboat
*/

#include "navy.h"

void change_map_parsing(char *line, char cara_same)
{
    int i = 0;
    int j = 0;
    int max_i = 0;
    int max_j = 0;
    char carra1 = (cara_same >= '0' && cara_same <= '8') ? line[2] : line[3];
    char carra2 = (cara_same >= '0' && cara_same <= '8') ? line[5] : line[6];

    if (cara_same >= '0' && cara_same <= '8') {
        i = cara_same - 49;
        j = carra1 - 65;
        max_j = carra2 - 65;
        for (j; j <= max_j; j++)
            GAME.owner.my_map[i][j] = line[0];
    } else if (cara_same >= 'A' && cara_same <= 'H') {
        j = cara_same - 65;
        i = carra1 - 49;
        max_i = carra2 - 49;
        for (i; i <= max_i; i++)
            GAME.owner.my_map[i][j] = line[0];
    }
}

int verification_nomber_of_case(char *tab_of_number_boat, char *line)
{
    for (int j = 0; tab_of_number_boat[j] != '\0'; j++)
        if (tab_of_number_boat[j] == line[0])
            return (ERROR_NUM);
    return (0);
}

int line_to_parsing(char *line, int i)
{
    static char tab_of_number_boat[4] = {0};

    if (verification_nomber_of_case(tab_of_number_boat, line) == ERROR_NUM)
        return (ERROR_NUM);
    tab_of_number_boat[i - 1] = line[0];
    if (my_strlen(line) == 8 && line[0] >= '2' && line[0] <= '5' && i + '1'\
        != line[0] || (line[1] != ':' || line[4] != ':'))
        return (ERROR_NUM);
    if (line[2] >= 'A' && line[2] <= 'H' && line[5] >= 'A' && line[5] <= 'H' &&
    line[3] >= '0' && line[3] <= '8' && line[6] >= '0' && line[6] <= '8') {
        if (line[2] == line[5] && line[6] == (line[3] + line[0] - '1') &&
            line[3] < line[6])
            change_map_parsing(line, line[2]);
        else if (line[3] == line[6] && line[5] == (line[2] + line[0] - '1') &&
            line[2] < line[5])
            change_map_parsing(line, line[3]);
        else
            return (ERROR_NUM);
    } else
        return (ERROR_NUM);
    return (0);
}

int parse_file_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *s = NULL;
    int i = 0;

    if (fd == -1)
        return (ERROR_NUM);
    s = get_next_line(fd);
    while (s) {
        i++;
        if (line_to_parsing(s, i) == 84)
            return (ERROR_NUM);
        free(s);
        s = get_next_line(fd);
    }
    free(s);
    if (i != 4)
        return (ERROR_NUM);
}

int create_map(char *filepath)
{
    for (int i = 0; i < 9; i++)
        GAME.owner.hit_pos[i] = '\0';
    for (int i = 0; i < NBR_LINE; i++)
        for (int j = 0; j < NBR_COL; j++) {
            GAME.owner.my_map[i][j] = '.';
            GAME.owner.enemy_map[i][j] = '.';
        }
    if (parse_file_map(filepath) == 84)
        return (ERROR_NUM);
}