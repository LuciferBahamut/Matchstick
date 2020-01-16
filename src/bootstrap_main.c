/*
** EPITECH PROJECT, 2020
** main
** File description:
** matchstick
*/

#include "my.h"

char **upd_str(char **str, int line, int nb_matches)
{
    int nb_m = 0;

    for (int i = 0; str[line][i] != '\0'; i++)
        if (str[line][i] == '|')
            nb_m++;
    if (nb_m == 0 || nb_m < nb_matches) {
        my_putstr("Invalid nb_matches or line\n");
        return (str);
    }
    for (int i = 0; i != nb_matches; i++) {
        printf("i = %d\n", i);
        for (int j = 8; j != 0; j--) {
            printf("j = %d\nstr = %c\n", j, str[line][j]);
            if (str[line][j] == '|') {
                printf("HEY\n");
                str[line][j] = ' ';
                printf("IS GOOD\n");
                break;
            }
        }
    }
    return (str);
}
