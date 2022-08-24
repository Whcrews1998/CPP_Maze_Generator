#include "Maze.hpp"

Maze::Maze(int numColumns, int numRows) { // width, height
    
    width = numColumns;
    height = numRows;

    map = new Cell*[width];
    for (int i = 0; i < width; i++) {
        map[i] = new Cell[height];
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            map[i][j].init(Cell::cellSize * i, Cell::cellSize * j);
        }
    }

}

void Maze::genMaze() {

}

void Maze::render(SDL_Renderer* render) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            map[i][j].render(render);
        }
    }
}