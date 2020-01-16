/*
** EPITECH PROJECT, 2020
** main
** File description:
** matchstick
*/

#include "my.h"

void multi_free(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

int main(int ac, char **av)
{
    int lignes;
    int nb_dell_match;
    char **map;

    if (error_handling(ac, av) == ERROR)
        return (ERROR);
    lignes = my_atoi(av[1]);
    nb_dell_match = my_atoi(av[2]);
    map = display_map(lignes);
    multi_free(map);
    return (SUCCESS);
}
