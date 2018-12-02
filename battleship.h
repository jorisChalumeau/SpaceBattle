#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "grid.h"

enum ShipType {NOSHIP=0, FISHBOAT=1, DESTROYER=2, SUBMARINE=3, CRUISER=3, BATTLESHIP=4, CARRIER=5};

class Battleship
{
public:
    explicit Battleship(ShipType t, Coordinate start, Coordinate end, std::string dir);
    ~Battleship();

private:
    ShipType _type;
    Coordinate _start;
    Coordinate _end;
    std::string _dir;
};

#endif // BATTLESHIP_H
