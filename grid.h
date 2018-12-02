#ifndef GRID_H
#define GRID_H

#include "coordinate.h"

class Grid
{
public:
    Grid();
    Coordinate *_table[10][10];
    void display();
    void fillShipH(Coordinate start, Coordinate end);
    void fillShipV(Coordinate start, Coordinate end);
    ~Grid();
};

#endif // GRID_H
