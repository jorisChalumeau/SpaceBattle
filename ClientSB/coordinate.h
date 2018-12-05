#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <vector>
#include <QString>

enum Coord {NONE = 0, A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8, I = 9, J = 10};
enum Status {MISS = -1, UNKNOWN = 0, HIDDEN = 1, HIT = 2};

class Coordinate
{
public:
    Coord _hCoord;
    Coord _vCoord;
    Status _value;
    Coordinate(Coord h, Coord v);
    Coordinate(Coord h, Coord v, Status val);
    bool isNull();
    ~Coordinate();
};

#endif // COORDINATE_H
