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

void print_game_board(char **str)
{
    for (int i = 0; i != 6; i++) {
        for (int j = 0; str[i][j] != '\0'; j++)
            my_putchar(str[i][j]);
        my_putchar('\n');
    }
}

char **fill_str(char **str)
{
    for (int i = 0; i != 6; i++)
        str[i] = malloc((8 + 1) * sizeof(char));
    str[0] = "*********";
    str[1] = "*   |   *";
    str[2] = "*  |||  *";
    str[3] = "* ||||| *";
    str[4] = "*|||||||*";
    str[5] = "*********";
    return (str);
}

int main(int ac, char **av)
{
    char **str = malloc((6 + 1) * sizeof(char *));

    str = fill_str(str);
    print_game_board(str);
    str = upd_str(str, 3, 2);
    print_game_board(str);
    free(str);
    return (0);
}
