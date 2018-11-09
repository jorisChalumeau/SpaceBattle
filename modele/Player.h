//
// Created by 43cb886c4537 on 09/11/2018.
//

#ifndef SPACEBATTLE_PLAYER_H
#define SPACEBATTLE_PLAYER_H

#include "Grid.h"

class Player {
public:
    Player(int numPlayer, Grid ownGrid, Grid enemyGrid);
    int _numPlayer;
    Grid _ownGrid;
    Grid _enemyGrid;
    void shoot(Coord hCoord, Coord vCoord);
    ~Player();
};


#endif //SPACEBATTLE_PLAYER_H
