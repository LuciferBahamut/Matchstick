/*
** EPITECH PROJECT, 2020
** check value
** File description:
** matchsticks
*/

#include "my.h"

int check_pipe_l(game_t *gm)
{
    char **str = gm->map;
    int nb = 0;

    for (int j = 1; str[gm->nb_line][j] != '*'; j++)
        if (str[gm->nb_line][j] == '|')
            nb++;
    return (nb);
}

int check_pipe_e(game_t *gm)
{
    char **str = gm->map;
    int nb = 0;

    for (int i = 1; i != gm->max_line + 1; i++)
        for (int j = 1; str[i][j] != '*'; j++)
            if (str[i][j] == '|')
                nb++;
    return (nb);
}

int check_line(char *buffer, game_t *gm)
{
    for (int i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] < '0' || buffer[i] > '9') {
            my_putstr(EINPUT);
            return (ERROR);
        }
    gm->nb_line = my_atoi(buffer);
    if (gm->nb_line == 0 || gm->nb_line > gm->max_line) {
        my_putstr(ENINPUT);
        return (ERROR);
    }
}

int check_match2(game_t *gm)
{
    if (gm->dell_match > gm->max_match) {
        my_putstr(EMINPUT0);
        my_put_nbr(gm->max_match);
        my_putstr(EMINPUT1);
        return (ERROR);
    }
    if (gm->dell_match > check_pipe_l(gm)) {
        my_putstr(ETINPUT);
        return (ERROR);
    }
}

int check_match(char *buffer, game_t *gm)
{
    for (int i = 0; buffer[i] != '\n'; i++)
        if (buffer[i] < '0' || buffer[i] > '9') {
            my_putstr(EINPUT);
            return (ERROR);
        }
    gm->dell_match = my_atoi(buffer);
    if (gm->dell_match == 0) {
        my_putstr(E0INPUT);
        return (ERROR);
    }
    if (check_match2(gm) == ERROR)
        return (ERROR);
}
