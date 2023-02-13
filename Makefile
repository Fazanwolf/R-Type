CC			=	g++

SFLAGS		= -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SRC			=	src/test_Archi/main.cpp	\
				src/Window.cpp	\
				src/Draw.cpp	\
				src/Event.cpp	\
				src/StateManager.cpp	\
				src/EntitiesManager.cpp	\
				src/Bullets.cpp

NAME		=	r-type

all:
	$(CC) $(SRC) $(SFLAGS) -o $(NAME) -I ./include/Engine -I ./include/Entities -I ./include/Components -I ./include/system -I ./include/Utils  -I ./include/system/gameState

clean:
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all