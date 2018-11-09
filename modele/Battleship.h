//
// Created by 43cb886c4537 on 09/11/2018.
//

#ifndef SPACEBATTLE_BATTLESHIP_H
#define SPACEBATTLE_BATTLESHIP_H

#include "Coordinate.h"

class Battleship {
public:
    Battleship(int size, Coordinate start, Coordinate end);
    ~Battleship();

private:
    int _size;
    Coordinate _start;
    Coordinate _end;
};


#endif //SPACEBATTLE_BATTLESHIP_H
