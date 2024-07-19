##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Nothing
##

F	= 	./src/my_paint.c \
		./src/game.c \
		./src/paint_button.c \
		./src/main.c

OBJ	=	$(F:.c=.o)

N	=	my_paint

A 	=	-o $(N)

$(N):	$(OBJ)
	gcc -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio $(F) $(A)

all:	$(N)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(N)

re:	fclean	all
	rm -f $(OBJ)
