/*
** EPITECH PROJECT, 2020
** udp map
** File description:
** matchsticks
*/

#include "my.h"

char **udp_map(game_t *gm, char **map)
{
    for (int k = 0, j = my_strlen(map[gm->nb_line]); j != 0; j--)
        if (map[gm->nb_line][j] == '|' && k != gm->dell_match) {
            map[gm->nb_line][j] = ' ';
            k++;
        }
    for (int i = 0; i != gm->max_line + 2; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return (map);
}
