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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int error_handling(int ac, char **av);
void my_putchar(char c);
int my_putstr(char const *str);
int my_atoi(char const *str);
char **display_map(int lignes);

#endif
