/*
** EPITECH PROJECT, 2019
** parse map
** File description:
** parsing the map of positionboat
*/

#include "navy.h"

void change_map(int host, int i, int j, char *line)
{
    if (host == 0)
        GAME.owner.my_map[i][j] = line[0];
    else if (host == 1)
        GAME.enemy.my_map[i][j] = line[0];
}

void change_map_parsing(char *line, char cara_same, int host)
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
            change_map(host, i, j, line);
    } else if (cara_same >= 'A' && cara_same <= 'H') {
        j = cara_same - 65;
        i = carra1 - 49;
        max_i = carra2 - 49;
        for (i; i <= max_i; i++)
            change_map(host, i, j, line);
    }
}

int line_to_parsing(char *line, int host, int i)
{
    if (my_strlen(line) == 8 && line[0] >= '2' && line[0] <= '5' && i + '1'\
        != line[0])
        return (ERROR_NUM);
    if (line[2] >= 'A' && line[2] <= 'H' && line[5] >= 'A' && line[5] <= 'H' &&
    line[3] >= '0' && line[3] <= '8' && line[6] >= '0' && line[6] <= '8') {
        if (line[2] == line[5] && line[6] == (line[3] + line[0] - '1'))
            change_map_parsing(line, line[2], host);
        else if (line[3] == line[6] && line[5] == (line[2] + line[0] - '1'))
            change_map_parsing(line, line[3], host);
        else
            return (ERROR_NUM);
    } else {
        my_puterror("Your map have a wrong format");
        return (ERROR_NUM);
    }
    return (0);
}

int parse_file_map(char *filepath, int host)
{
   int fd = open(filepath, O_RDONLY);
    char *s = NULL;
    int i = 0;

    if (fd > 0)
        s = get_next_line(fd);
    else
        return (ERROR_NUM);
    while (s) {
        i++;
        if (line_to_parsing(s, host, i) == 84)
            return (ERROR_NUM);
        free(s);
        s = get_next_line(fd);
    }
    free(s);
    if (i > 4)
        return (ERROR_NUM);
}

int create_map(char *filepath, int host)
{
    for (int i = 0; host == 0 && i < NBR_LINE; i++)
        for (int j = 0; j < NBR_COL; j++) {
            GAME.owner.my_map[i][j] = '.';
            GAME.owner.enemy_map[i][j] = '.';
        }
    for (int i = 0; host == 1 && i < NBR_LINE; i++)
        for (int j = 0; j < NBR_COL; j++) {
            GAME.enemy.my_map[i][j] = '.';
            GAME.enemy.enemy_map[i][j] = '.';
        }
    if (parse_file_map(filepath, host) == 84)
        return (ERROR_NUM);
    if (host == 0)
        display_map(GAME.owner);
    else if (host == 1)
        display_map(GAME.enemy);
}