#ifndef PLAYER_H
#define PLAYER_H

#include "battleship.h"

class Player
{
private:
    Grid _ownGrid;
    Grid _enemyGrid;
    ShipType _selectedShip;
    Coordinate _selectedCell;

public:
    Player(int numPlayer);
    int _numPlayer;
    Status shoot(Coordinate target);
    bool placeShip(ShipType t, Coordinate start, Coordinate end);
    Grid getOwnGrid();
    void setOwnGrid(Grid g);
    Grid getEnemyGrid();
    void setEnemyGrid(Grid g);
    ShipType getSelectedShip();
    void selectShip(ShipType st);
    Coordinate getSelectedCell();
    void selectCell(Coordinate c);
    ~Player();
};

#endif // PLAYER_H
