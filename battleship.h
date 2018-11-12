#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Coordinate.h"

class Battleship
{
public:
    Battleship(int size, Coordinate start, Coordinate end);
    ~Battleship();

private:
    int _size;
    Coordinate _start;
    Coordinate _end;
};

#endif // BATTLESHIP_H
