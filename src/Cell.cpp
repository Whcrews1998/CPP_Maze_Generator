#include "Cell.hpp"

int Cell::cellSize = 16;

Cell::Cell() {
    walls[0] = true;
    walls[1] = true;
    walls[2] = true;
    walls[3] = true;
}
void Cell::init(int x, int y) {
    this->x = x;
    this->y = y;
}

void Cell::render(SDL_Renderer* render) {
    
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    
    // Draw North wall
    if (walls[Direction::NORTH]) {
        SDL_RenderDrawLine(render, x, y, x+cellSize, y);
    }

    // Draw East wall
    if (walls[Direction::EAST]) {
        SDL_RenderDrawLine(render, x+cellSize, y, x+cellSize, y+cellSize);
    }

    // Draw South wall
    if (walls[Direction::SOUTH]) {
        SDL_RenderDrawLine(render, x+cellSize, y+cellSize, x, y+cellSize);
    }

    // Draw West wall
    if (walls[Direction::WEST]) {
        SDL_RenderDrawLine(render, x, y+cellSize, x, y);
    }

}