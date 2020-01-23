/*
** EPITECH PROJECT, 2020
** turn ai
** File description:
** matchstick
*/

#include "my.h"

static void print_msg(game_t *gm)
{
    my_putstr("AI removed ");
    my_put_nbr(gm->dell_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(gm->nb_line);
    my_putchar('\n');
    gm->map = udp_map(gm, gm->map);
}

int *fill_tab(game_t *gm)
{
    int *stock = malloc(gm->max_line * sizeof(int));
    int max = gm->max_line + 1;

    gm->nb_line = 1;
    for (int i = 0; gm->nb_line != max; gm->nb_line++, i++)
        stock[i] = check_pipe_l(gm);
    return (stock);
}

int check_error(game_t *gm, int *tab, int i)
{
    if (tab[i - 1] == 0)
        for (int j = 0; j != gm->max_line; j++) {
            if (tab[j] != 0) {
                gm->nb_line = j + 1;
                gm->dell_match = random() % check_pipe_l(gm);
            }
        }
    else
        gm->dell_match = random() % check_pipe_l(gm);
    while (gm->dell_match > gm->max_match)
        gm->dell_match = random() % check_pipe_l(gm);
    if (gm->dell_match == 0)
        gm->dell_match = 1;
}

int turn_a(game_t *gm)
{
    int *tab = fill_tab(gm);

    if (check_pipe_e(gm) == 2) {
        for (int i = 0; i != gm->max_line; i++)
            if (tab[i] != 0) {
                gm->nb_line = i + 1;
                gm->dell_match = 1;
                break;
            }
    }
    else {
        gm->nb_line = gm->max_line;
        check_error(gm, tab, gm->max_line);
    }
    print_msg(gm);
    free(tab);
    return (SUCCESS);
}
