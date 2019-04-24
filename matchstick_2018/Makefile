##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Makefile for matchstick project
##

NAME	=	matchstick

SRC	=	sources/draw_map.c	\
		sources/gtl.c		\
		sources/round.c		\
		sources/my_putnbr.c	\
		sources/my_getnbr.c	\
		sources/my_strlen.c	\
		sources/matchstick.c

CFLAGS	=	-g3 -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
