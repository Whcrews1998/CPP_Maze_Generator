#ifndef MAZE_HPP
#define MAZE_HPP
#include "Cell.hpp"
#include <SDL.h>
class Maze {
    public:
        Maze(int numColumns, int numRows); // width, height
        void genMaze();
        void render(SDL_Renderer* render);

        int getWidth(){return width;};
        int getHeight(){return height;};

    private:
        Cell** map; 
        int width;
        int height;
};

#endif 