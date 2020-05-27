##
## EPITECH PROJECT, 2019
## makefile
## File description:
## matchstick
##

NAME	=	matchstick

SRC	=	src/main.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/error_handling.c \
		src/my_atoi.c \
		src/display_map.c \
		src/game.c \
		src/check_value.c \
		src/turn_p.c \
		src/my_put_nbr.c \
		src/my_strlen.c \
		src/udp_map.c \
		src/turn_a.c

CC	=	gcc


DEFLAGS	=	-W -Wextra -Wall -g3

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(DEFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

TU	:
		$(CC) -o unit_tests lib/my/*.c $(CFFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *#
		rm -f *~
		rm -f src/*~
		rm -f include/*~
		rm -f *.gcda
		rm -f *.gcno

re	:	fclean all

.PHONY	:	all TU clean fclean re
