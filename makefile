CC=g++
CFLAGS=-c -Wall

SDL-I=-I./frameworks/SDL2.framework/Headers
SDL-F=-F./frameworks -framework SDL2

SDL-IMAGE-I=-I./frameworks/SDL2_image.framework/Headers
SDL-IMAGE-F=-F./frameworks -framework SDL2_image

all: Maze_Generator

Maze_Generator: main.o Game.o Maze.o Cell.o
	$(CC) -o Maze_Generator main.o Game.o Maze.o Cell.o $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

main.o: 
	$(CC) $(CFLAGS) ./src/main.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

Game.o: 
	$(CC) $(CFLAGS) ./src/Game.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

Maze.o: 
	$(CC) $(CFLAGS) ./src/Maze.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

Cell.o: 
	$(CC) $(CFLAGS) ./src/Cell.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

clean:
	rm -rf *o Maze_Generator

