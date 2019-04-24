##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## Makefile for infinadd
##

SRC	=	node.c		\
		swap_pa.c	\
		swap_pb.c	\
		swap_ra.c	\
		my_getnbr.c	\
		alternate_node.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

INC	= 	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ./../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
