
##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## Makefile for MY_PROJECT
##

NAME	=	push_swap

SRC	=	push_swap.c	\

OBJ	=	$(SRC)

CFLAGS	=	-g3 -Wall -Wextra

LDFLAGS	=	-L./lib/my -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(MAKE) -C lib/my/ clean

fclean:		clean
		rm -f $(NAME)
		$(MAKE) -C lib/my/ fclean

re:		fclean all

.PHONY:		all clean fclean re
