#include "player.h"

Player::Player(int numPlayer) : _numPlayer(numPlayer), _selectedCell(*new Coordinate(NONE,NONE)), _selectedShip(NOSHIP) {}

Status Player::shoot(Coord hCoord, Coord vCoord) {
    std::cout << "\nshot in (" << hCoord << "," << vCoord << ")";
    if(hCoord < A || hCoord > J || vCoord < A || vCoord > J)
        return MISS;
    if (_enemyGrid._table[vCoord][hCoord]->_value == UNKNOWN
            || _enemyGrid._table[vCoord][hCoord]->_value == MISS)
        _enemyGrid._table[vCoord][hCoord]->_value = MISS; // color white cell
    else
        _enemyGrid._table[vCoord][hCoord]->_value = HIT; // color red cell
    return _enemyGrid._table[vCoord][hCoord]->_value;
}

bool Player::placeShip(ShipType t, Coordinate start, Coordinate end) {
    if(end._hCoord - start._hCoord == t+1 && end._vCoord - start._vCoord == 0){
        new Battleship(t, start, end, "h");
        _ownGrid.fillShipH(start, end);
        _ownGrid.display();
        return true;
    } else if (start._hCoord - end._hCoord == t+1 && start._vCoord - end._vCoord == 0){
        new Battleship(t, end, start, "h");
        _ownGrid.fillShipH(end, start);
        _ownGrid.display();
        return true;
    } else if(end._hCoord - start._hCoord == 0 && end._vCoord - start._vCoord == t+1){
        new Battleship(t, start, end, "v");
        _ownGrid.fillShipV(start, end);
        _ownGrid.display();
        return true;
    } else if (start._hCoord - end._hCoord == 0 && start._vCoord - end._vCoord == t+1){
        new Battleship(t, end, start, "v");
        _ownGrid.fillShipV(end, start);
        _ownGrid.display();
        return true;
    }
    return false;
}

void Player::setOwnGrid(Grid g){
    _ownGrid = g;
}

void Player::setEnemyGrid(Grid g){
    _enemyGrid = g;
}

Grid Player::getOwnGrid(){
    return this->_ownGrid;
}

Grid Player::getEnemyGrid(){
    return this->_enemyGrid;
}

ShipType Player::getSelectedShip(){
    return this->_selectedShip;
}

void Player::selectShip(ShipType st){
    this->_selectedShip = st;
}

Coordinate Player::getSelectedCell(){
    return this->_selectedCell;
}

void Player::selectCell(Coordinate c){
    this->_selectedCell = c;
}

Player::~Player() = default;
