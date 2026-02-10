##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CPPFLAGS += -I include -I src

SRC =	main.c	\

OBJ =	$(SRC:.c=.o)

NAME = my_radar

LIB_DIR = src
LIB = $(LIB_DIR)/libmy.a

LIB_DIR2 = lib/my
LIB2 = $(LIB_DIR2)/libmy2.a

all: $(LIB) $(LIB2) $(NAME)

$(LIB):
		$(MAKE) -C $(LIB_DIR)

$(LIB2):
		$(MAKE) -C $(LIB_DIR2)

$(NAME): $(OBJ)
		epiclang $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio src/libmy.a lib/my/libmy2.a -lm -g

clean:
		rm -f $(OBJ)
		$(MAKE) -C $(LIB_DIR) clean
		$(MAKE) -C $(LIB_DIR2) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIB_DIR) fclean
		$(MAKE) -C $(LIB_DIR2) fclean
		rm -f lib/libmy.a

re: fclean all

.PHONY: all re clean fclean