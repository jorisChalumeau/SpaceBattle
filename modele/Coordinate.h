//
// Created by 43cb886c4537 on 09/11/2018.
//

#ifndef SPACEBATTLE_COORDINATE_H
#define SPACEBATTLE_COORDINATE_H

#include <iostream>

enum Coord {A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8, I = 9, J = 10};
enum Status {MISS = -1, UNKOWN = 0, HIT = 1};

class Coordinate {
public:
    Coord hCoord;
    Coord vCoord;
    Status value;
};


#endif //SPACEBATTLE_COORDINATE_H
