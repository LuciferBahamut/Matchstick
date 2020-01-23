/*
** EPITECH PROJECT, 2020
** game
** File description:
** match_stick
*/

#include "my.h"

int game(game_t *gm)
{
    my_putstr(TPLAYER);
    if (turn_p(gm) == CEOF)
        return (SUCCESS);
    if (check_pipe_e(gm) == 0) {
        my_putstr(DPLAYER);
        return (WINA);
    }
    else
        my_putchar('\n');
    my_putstr(TAI);
    turn_a(gm);
    if (check_pipe_e(gm) == 0) {
        my_putstr(DAI);
        return (WINP);
    }
    else {
        my_putchar('\n');
        game(gm);
    }
    return (SUCCESS);
}
