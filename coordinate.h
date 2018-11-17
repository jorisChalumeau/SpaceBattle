#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

enum Coord {A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8, I = 9, J = 10};
enum Status {MISS = -1, UNKNOWN = 0, HIT = 1};

class Coordinate
{
public:
    Coord _hCoord;
    Coord _vCoord;
    Status _value;
    Coordinate(Coord h, Coord v);
    Coordinate(Coord h, Coord v, Status val);
    ~Coordinate();
};

#endif // COORDINATE_H
