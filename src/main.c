/*
** EPITECH PROJECT, 2020
** main
** File description:
** matchstick
*/

#include "my.h"

void multi_free(char **map, game_t *gm)
{
    for (int i = 0; i != gm->max_line + 2; i++)
        free(map[i]);
    free(map);
}

int main(int ac, char **av)
{
    game_t *gm = malloc(sizeof(int) * 4 + sizeof(char**));
    int ret;

    if (error_handling(ac, av) == ERROR)
        return (ERROR);
    gm->max_line = my_atoi(av[1]);
    gm->max_match = my_atoi(av[2]);
    gm->map = display_map(gm);
    my_putchar('\n');
    ret = game(gm);
    multi_free(gm->map, gm);
    free(gm);
    return (ret);
    return (SUCCESS);
}
