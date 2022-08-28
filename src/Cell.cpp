#include "Cell.hpp"

int Cell::cellSize = 16;

Cell::Cell() {
    walls[0] = true;
    walls[1] = true;
    walls[2] = true;
    walls[3] = true;
    visited = false;
}
void Cell::init(int x, int y) {
    this->x = x;
    this->y = y;
}

void Cell::render(SDL_Renderer* render) {
    
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    int xRenderPos = x * cellSize;
    int yRenderPos = y * cellSize;
    
    // Draw North wall
    if (walls[Direction::NORTH]) {
        SDL_RenderDrawLine(render, xRenderPos, yRenderPos, xRenderPos + cellSize, yRenderPos);
    }

    // Draw East wall
    if (walls[Direction::EAST]) {
        SDL_RenderDrawLine(render, xRenderPos + cellSize, yRenderPos, xRenderPos + cellSize, y* cellSize + cellSize);
    }

    // Draw South wall
    if (walls[Direction::SOUTH]) {
        SDL_RenderDrawLine(render, xRenderPos +cellSize, y* cellSize + cellSize, xRenderPos, yRenderPos + cellSize);
    }

    // Draw West wall
    if (walls[Direction::WEST]) {
        SDL_RenderDrawLine(render, xRenderPos, y* cellSize+cellSize, xRenderPos, y* cellSize);
    }

}