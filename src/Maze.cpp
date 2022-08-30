#include <stack>
#include <vector>
#include <cstdlib>
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
            map[i][j].init(i, j);
        }
    }

}

void Maze::genMaze() {

    

    int xPos = 0;
    int yPos = 0;
    std::stack<Cell*> stack;

    // 1. Choose the initial cell, mark it as visited and push it to the stack
    Cell* current = &map[0][0];
    current->visited = true;
    stack.push(current);

    // 2. While the stack is not empty
    while (!stack.empty()) {
        // 1. Pop a cell from the stack and make it a current cell
        current = stack.top();
        stack.pop();

        // 2. If the current cell has any neighbours which have not been visited
        std::vector<Cell::Direction> neighbors = unvisitedNeighbors(current->x, current->y);

        if (!neighbors.empty()) {
            // 1. Push the current cell to the stack
            stack.push(current);
            // 2. Choose one of the unvisited neighbours and remove wall between them
            int choice = rand() % neighbors.size();
            Cell::Direction dir = neighbors.at(choice);

            if (dir == Cell::NORTH) {
                current->setWall(Cell::NORTH, false);
                current = &map[current->x][current->y - 1];
                current->setWall(Cell::SOUTH, false);
            }
            if (dir == Cell::EAST) {
                current->setWall(Cell::EAST, false);
                current = &map[current->x+1][current->y];
                current->setWall(Cell::WEST, false);
                
            }
            if (dir == Cell::SOUTH) {
                current->setWall(Cell::SOUTH, false);
                current = &map[current->x][current->y + 1];
                current->setWall(Cell::NORTH, false);
                
            }
            if (dir == Cell::WEST) {
                current->setWall(Cell::WEST, false);
                current = &map[current->x-1][current->y];
                current->setWall(Cell::EAST, false);
            }
            // 3. Mark the chosen cell as visited and push it to the stack
            current->visited = true;
            stack.push(current);
        }
    }
}


// Return a vector<Cell::Direction> then use rand() % vect.size() to chooose
// wall to remove. 
// If vector.size() == 0, skip;
std::vector<Cell::Direction> Maze::unvisitedNeighbors(int x, int y) {
    
    bool hasNeighbors = false;
    std::vector<Cell::Direction> options;

    // Check NORTH
    if (y > 0 && !map[x][y-1].visited) {
        options.push_back(Cell::NORTH);
    }
    // Check EAST
    if (x < width - 1 && !map[x+1][y].visited) {
        options.push_back(Cell::EAST);
    }
    // Check SOUTH
    if (y < height - 1 && !map[x][y+1].visited) {
        options.push_back(Cell::SOUTH);
    } 
    // Check WEST
    if (x > 0 && !map[x-1][y].visited) {
        options.push_back(Cell::WEST);
    }

    return options;
}

void Maze::render(SDL_Renderer* render) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            map[i][j].render(render);
        }
    }
}
