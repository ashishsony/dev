#CC = gcc -Wall -ansi
CC = g++
all:
	$(CC) myGame.cpp -o myGame -lGL -lGLU -lSDL_ttf -lSDL_mixer `sdl-config --cflags --libs` 

clean:
	@echo Cleaning up...
	@rm myGame 
	@echo Done.
