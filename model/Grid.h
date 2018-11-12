//
// Created by 43cb886c4537 on 09/11/2018.
//

#ifndef SPACEBATTLE_GRID_H
#define SPACEBATTLE_GRID_H

#include "Coordinate.h"

class Grid {
public:
    explicit Grid();
    Coordinate _table[10][10];
    void display();
    ~Grid();
};


#endif //SPACEBATTLE_GRID_H
