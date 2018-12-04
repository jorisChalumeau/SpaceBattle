#include "coordinate.h"

Coordinate::Coordinate(Coord h, Coord v) {
    _hCoord = h;
    _vCoord = v;
    _value = UNKNOWN;
}

Coordinate::Coordinate(Coord h, Coord v, Status val) {
    _hCoord = h;
    _vCoord = v;
    _value = val;
}

bool Coordinate::isNull()
{
    if(_hCoord == NONE || _vCoord == NONE)
        return true;
    return false;
}

Coordinate::~Coordinate() = default;
