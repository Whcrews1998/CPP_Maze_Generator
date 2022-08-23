#include <iostream>
#include <SDL.h>
#include "Game.hpp"

int main(int argc, char* argv[]) {

const int FPS = 20;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    Game* game = nullptr;
    game = new Game();

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

    return 0;
}