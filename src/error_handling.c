/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** matchstick
*/

#include "my.h"

int error_handling(int ac, char **av)
{
    int arg1;
    int arg2;

    if (ac != 3)
        return (ERROR);
    if (av[1][0] == '-' || av[2][0] == '-')
        return (ERROR);
    for (int i = 1; i != ac; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9')
                return (ERROR);
    arg1 = my_atoi(av[1]);
    arg2 = my_atoi(av[2]);
    if (arg1 < 1 || arg1 > 100)
        return (ERROR);
    if (arg2 <= 0)
        return (ERROR);
    return (SUCCESS);
}
