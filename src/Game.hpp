#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SDL.h>
#include "Maze.hpp"

class Game {
    public:
        Game();
        ~Game();

        void loadMaze(Maze* newMaze) {maze = newMaze;};
        void init(const char* title, int xpos, int ypos, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() {return isRunning;};
    private:
        int width;
        int height;
        bool isRunning;

        Maze* maze;
        SDL_Window* window;
        SDL_Renderer* renderer;

};

#endif