#include <string>
#include <iostream>

#define HEADER_HPP

const int GRID_SIZE = 10;
const int alive_cells = 1;
const int dead_cells = 0;
const int Screen_size = 800;
const int CELL_SIZE = Screen_size / GRID_SIZE;

struct RoomPosition {
    int x_cord;
    int y_cord;
};

struct Position
{
    int x_cord;
    int y_cord;
};