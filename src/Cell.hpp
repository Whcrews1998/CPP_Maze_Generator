#ifndef CELL_HPP
#define CELL_HPP
#include <iostream>
#include <SDL.h>

class Cell {
    public:

        Cell();

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
        

    private:
        int x;
        int y;
};

#endif 