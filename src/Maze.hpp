#ifndef MAZE_HPP
#define MAZE_HPP
#include "Cell.hpp"
#include <SDL.h>
class Maze {
    public:
        Maze(int numColumns, int numRows); // width, height
        void genMaze();
        void render(SDL_Renderer* render);

    private:
        Cell** map; 
        int width;
        int height;
};

#endif 