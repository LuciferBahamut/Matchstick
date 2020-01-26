/*
** EPITECH PROJECT, 2020
** turn player
** File description:
** matchsticks
*/

#include "my.h"

int f_line(game_t *gm, size_t size, char *buffer)
{
    my_putstr(LINE);
    while (1) {
        if (getline(&buffer, &size, stdin) == EOF) {
            my_putchar('\n');
            return (CEOF);
        }
        else {
            if (check_line(buffer, gm) == ERROR)
                f_line(gm, size, buffer);
        }
        break;
    }
}

int f_match(game_t *gm, size_t size, char *buffer)
{
    my_putstr(MATCH);
    while (1) {
        if (getline(&buffer, &size, stdin) == EOF) {
            my_putchar('\n');
            return (CEOF);
        }
        else {
            if (check_match(buffer, gm) == ERROR)
                check_gm(gm, size, buffer);
        }
        break;
    }
}

static void print_msg(game_t *gm)
{
    my_putstr("Player removed ");
    my_put_nbr(gm->dell_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(gm->nb_line);
    my_putchar('\n');
}

static int check_gm(game_t *gm, size_t size, char *buffer)
{
    if (f_line(gm, size, buffer) == CEOF)
        return (CEOF);
    if (f_match(gm, size, buffer) == CEOF)
        return (CEOF);
}

int turn_p(game_t *gm)
{
    int i = 0;
    size_t size = gm->max_line;
    char *buffer = malloc(sizeof(char) * gm->max_line);

    if (check_gm(gm, size, buffer) == CEOF)
        return (CEOF);
    print_msg(gm);
    gm->map = udp_map(gm, gm->map);
    free(buffer);
}
