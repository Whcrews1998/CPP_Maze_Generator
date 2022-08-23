#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL.h>
#include "Cell.hpp"

class Game {
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() {return isRunning;};
    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;

};

#endif