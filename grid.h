#ifndef GRID_H
#define GRID_H

#include "coordinate.h"

class Grid
{
public:
    explicit Grid();
    Coordinate _table[10][10];
    void display();
    ~Grid();
};

#endif // GRID_H
