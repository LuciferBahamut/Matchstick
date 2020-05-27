/*
** EPITECH PROJECT, 2020
** display map
** File description:
** matchsticks
*/

#include "my.h"

char *fill_map(int i, int col, char *map)
{
    int mid = (col / 2) - i + 1;
    static int nb_match = 1;

    for (int j = 0; j != col; j++)
        if (j == mid)
            for (int k = 0; k != nb_match; k++, j++)
                map[j] = '|';
    nb_match = nb_match + 2;
    return (map);
}

char **display_map(game_t *gm)
{
    int nb_line = gm->max_line + 2;
    int nb_col = 2 * gm->max_line + 1;
    char **map = malloc((nb_line) * sizeof(char *));

    for (int i = 0; i != nb_line; i++) {
        map[i] = malloc((nb_col + 1) * sizeof(char));
        for (int j = 0; j != nb_col; j++)
            if (i == 0 || i == nb_line - 1)
                map[i][j] = '*';
            else if (j == 0 || j == nb_col - 1)
                map[i][j] = '*';
            else
                map[i][j] = ' ';
    }
    for (int k = 1; k != nb_line - 1; k++)
        map[k] = fill_map(k, nb_col, map[k]);
    for (int i = 0; i != nb_line; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return (map);
}
