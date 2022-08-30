#ifndef CELL_HPP
#define CELL_HPP
#include <iostream>
#include <SDL.h>
#include "config.hpp"

class Cell {
    public:

        Cell();

        bool visited;
        bool walls[4];
        static int cellSize;

        enum Direction {
            NORTH,
            EAST,
            SOUTH,
            WEST
        };

        void init(int x, int y);
        void render(SDL_Renderer* render);
        bool getWall(Direction dir) { return walls[dir]; };
        void setWall(Direction dir, bool val) { walls[dir] = val; };

        int x;
        int y;

    private:
        
        
};

#endif 