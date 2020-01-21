/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** matchstick
*/

#ifndef MY_H_
#define MY_H_

#define SUCCESS 0
#define ERROR 84

#define WINA 2
#define WINP 1

#define LINE "Line: "
#define MATCH "Matches: "

#define TAI "AI's turn...\n"
#define TPLAYER "Your turn:\n"

#define DAI "I lost... snif... but I'll get you next time!!\n"
#define DPLAYER "You lost, too bad...\n"

#define EINPUT "Error: invalid input (positive number expected)\n"
#define ENINPUT "Error: this line is out of range\n"
#define E0INPUT "Error: you have to remove at least one match\n"
#define EMINPUT0 "Error: you cannot remove more than "
#define EMINPUT1 " matches per turn\n"
#define ETINPUT "Error: not enough matches on this line\n"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct game
{
    int max_line;
    int max_match;
    int nb_line;
    int dell_match;
    char **map;
} game_t;

int error_handling(int ac, char **av);
void my_putchar(char c);
int my_putstr(char const *str);
int my_atoi(char const *str);
char **display_map(game_t *gm);
int game(game_t *gm);
int check_line(char *buffer, game_t *gm);
int check_match(char *buffer, game_t *gm);
int turn_p(game_t *gm);
int turn_a(game_t *gm);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char **udp_map(game_t *gm, char **map);
int check_pipe_e(game_t *gm);
int check_pipe_l(game_t *gm);

#endif
