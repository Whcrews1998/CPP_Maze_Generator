#ifndef CELL_HPP
#define CELL_HPP

class Cell {
    public:
        bool walls[4];
        enum Direction {
            NORTH,
            EAST,
            SOUTH,
            WEST
        };

        void render(/*SDL_Renderer*/);
        bool getWall(Direction dir);
        void setWall(Direction dir, bool val);
        

    private:
        // SDL_Rect rect
        static int cellSize;
};

#endif 