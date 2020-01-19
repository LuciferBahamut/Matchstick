/*
** EPITECH PROJECT, 2020
** game
** File description:
** match_stick
*/

#include "my.h"

int game(game_t *gm)
{
    turn_p(gm);
    if (check_pipe_e(gm) == 0) {
        my_putstr(DPLAYER);
        return (WINA);
    }
    else
        my_putstr("\n\n");
//    turn_ai(gm);
//    if (check_pipe_e(gm) == 0) {
//        my_putstr(DAI);
//        return (WINP);
//    }
//    else {
//        my_putstr("\n\n");
//        game(gm);
//    }
    return (SUCCESS);
}
