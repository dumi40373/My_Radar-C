##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC	=	execute.c	\
		create_window.c	\
		create_texture.c	\
		create_sprite.c	\
		initialize.c	\
		analyse_events.c	\
		destroy.c	\
		set_images.c	\
		read_file.c	\
		file_info.c	\
		draw_crafts.c	\
		intersecting.c	\
		draw_towers.c	\
		create_rect.c	\
		create_circle.c

OBJ	=	$(SRC:.c=.o)

all: exe

exe: $(OBJ)
	ar rc libmy.a $(OBJ)
	cp my.h ../include/

$(OBJ): $(SRC)
	epiclang -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a

re: fclean all