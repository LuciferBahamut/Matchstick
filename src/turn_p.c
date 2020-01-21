/*
** EPITECH PROJECT, 2020
** turn player
** File description:
** matchsticks
*/

#include "my.h"

void f_match(game_t *gm, size_t size, char *buffer)
{
    my_putstr(MATCH);
    while (1) {
        getline(&buffer, &size, stdin);
        break;
    }
    if (check_match(buffer, gm) == ERROR)
        f_match(gm, size, buffer);
}

void f_line(game_t *gm, size_t size, char *buffer)
{
    my_putstr(LINE);
    while (1) {
        getline(&buffer, &size, stdin);
        break;
    }
    if (check_line(buffer, gm) == ERROR)
        f_line(gm, size, buffer);
}

static void print_msg(game_t *gm)
{
    my_putstr("Player removed ");
    my_put_nbr(gm->dell_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(gm->nb_line);
    my_putchar('\n');
}

int turn_p(game_t *gm)
{
    int i = 0;
    size_t size = gm->max_line;
    char *buffer = malloc(sizeof(char) * gm->max_line);

    my_putstr(TPLAYER);
    f_line(gm, size, buffer);
    f_match(gm, size, buffer);
    print_msg(gm);
    gm->map = udp_map(gm, gm->map);
    free(buffer);
    return (SUCCESS);
}
