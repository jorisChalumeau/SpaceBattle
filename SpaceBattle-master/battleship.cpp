#include "battleship.h"

Battleship::Battleship(ShipType t, Coordinate start, Coordinate end, std::string dir) : _type(t), _start(start),
    _end(end), _dir(dir) {}

Battleship::~Battleship() = default;
