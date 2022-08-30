#include <iostream>
#include <SDL.h>
#include "Game.hpp"
#include "config.hpp"


int main(int argc, char* argv[]) {

const int FPS = 20;



    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    Maze* maze = nullptr;
    Game* game = nullptr;

    game = new Game();
    maze = new Maze(MAZE_WIDTH, MAZE_HEIGHT);
    maze->genMaze();

    game->loadMaze(maze);
    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, false);

    while (game->running()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;

}