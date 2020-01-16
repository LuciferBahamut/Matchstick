/*
** EPITECH PROJECT, 2020
** main
** File description:
** matchstick
*/

#include "my.h"

int main(int ac, char **av)
{
    int lignes;
    int nb_dell_match;

    if (error_handling(ac, av) == ERROR)
        return (ERROR);
    lignes = my_atoi(av[1]);
    nb_dell_match = my_atoi(av[2]);
    display_map(lignes);
    return (SUCCESS);
}
