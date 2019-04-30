##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Makefile for matchstick project
##

NAME	=	matchstick

SRC	=	sources/draw_map.c	\
		sources/get_next_line.c	\
		sources/round.c		\
		sources/my_putnbr.c	\
		sources/my_getnbr.c	\
		sources/my_strlen.c	\
		sources/matchstick.c

NOM	=	$(basename $(notdir $(SRC)))

OBJ	=	$(addprefix objects/, $(addsuffix .o, $(NOM)))

CFLAGS	=	-g3 -Iinclude

RED	=\033[0m\e[1m\e[31m
GREEN	=\033[0m\e[1m\e[32m
NC	=\033[0m
GREY	=\033[43m
BG_CL	=\033[42m####\033[40m

all:		$(NAME)

$(NAME):	$(OBJ) | objects/
	@$(CC) -o $(NAME) $(OBJ)
	@echo  -e '${BG_CL}| Flags  : $(CFLAGS)${NC}'
	@echo  -e '${GREEN}╰ Create${NC} : ${GREY}./n4s_package/$(NAME)${NC}'

objects/%.o:	sources/%.c | objects
	@mkdir -p objects
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "${GREEN}|  [OK]\033[0m\e[1m\e[32m   " $< "\033[0m" || echo -e "\e[91;5m|  [KO]\e[25m   " $< "\033[0m"

objects:
	@mkdir -p $@
	@echo  -e '${GREEN}╭ Object${NC} : objects/ dir create'
clean:
	@rm    -f $(OBJ)
	@echo  -e '${RED}╭ Clean${NC}  : OK'

fclean:		clean
	@$(RM) -r objects
	@$(RM) $(NAME)
	@echo  -e '${RED}| Fclean${NC} : $(NAME) removed'
	@echo  -e '${RED}| Fclean${NC} : n4s_package/$(NAME) removed'
	@echo  -e '${RED}╰ Fclean${NC} : objects/ dir removed'

re:		fclean all

.PHONY:		all clean fclean re
