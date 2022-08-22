#ifndef MAZE_HPP
#define MAZE_HPP
#include "Cell.hpp"

class Maze {
    public:
        Maze(int w, int h);
        void genMaze();
        void render(/*SDL_Renderer*/);

    private:
        Cell** map; 
        const int width;
        const int height;
};

#endif 