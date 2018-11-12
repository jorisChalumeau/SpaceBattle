#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"

class Player
{
public:
    Player(int numPlayer, Grid ownGrid, Grid enemyGrid);
    int _numPlayer;
    Grid _ownGrid;
    Grid _enemyGrid;
    void shoot(Coord hCoord, Coord vCoord);
    ~Player();
};

#endif // PLAYER_H
