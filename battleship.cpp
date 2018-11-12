#include "battleship.h"

Battleship::Battleship(int size, Coordinate start, Coordinate end) {
    _size = size;
    _start = start;
    _end = end;
}

Battleship::~Battleship() = default;
