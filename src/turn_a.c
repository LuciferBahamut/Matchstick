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
}

int *fill_tab(game_t *gm)
{
    int *stock = malloc(gm->max_line * sizeof(int));
    int max = gm->max_line + 1;

    gm->nb_line = 1;
    for (int i = 0; nb_line != max; gm->nb_line++, i++)
        stock[i] = check_pipe_l(gm);
    return (stock);
}

void compute_win(game_t *gm)
{

}

int turn_a(game_t *gm)
{
    int *tab = fill_tab(gm);

    if (check_pipe_e == 2) {
        for (int i = 0; i != gm->max_line; i++)
            if (tab[i] != 0) {
                gm->nb_line = i;
                gm->dell_match = 1;
                break;
            }
    }
    else if (check_pipe_e <= gm->max_match + 1) {
        compute_win(gm);
    }
    else {
        gm->nb_line = gm->max_line;
        gm->dell_match = rand(check_pipe_l(gm));
    }
    print_msg(gm);
    free(tab);
    return (SUCCESS);
}
