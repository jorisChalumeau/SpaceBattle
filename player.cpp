#include "player.h"

Player::Player(int numPlayer) : _numPlayer(numPlayer), _selectedCell(*new Coordinate(NONE,NONE)), _selectedShip(NOSHIP) {}

Status Player::shoot(Coordinate target){
    if (_enemyGrid._table[target._vCoord-1][target._hCoord-1]->_value != HIDDEN
            && _enemyGrid._table[target._vCoord-1][target._hCoord-1]->_value != HIT)
        _enemyGrid._table[target._vCoord-1][target._hCoord-1]->_value = MISS; // color white cell
    else
        _enemyGrid._table[target._vCoord-1][target._hCoord-1]->_value = HIT; // color red cell
    return _enemyGrid._table[target._vCoord-1][target._hCoord-1]->_value;
}

bool Player::placeShip(ShipType t, Coordinate start, Coordinate end) {
    ShipType a = t;
    if (t==6)
        a = SUBMARINE;
    if(end._hCoord - start._hCoord == a-1 && end._vCoord - start._vCoord == 0){
        if(_ownGrid.fillShipH(start, end))
            return true;
        return false;
    } else if (start._hCoord - end._hCoord == a-1 && start._vCoord - end._vCoord == 0){
        if(_ownGrid.fillShipH(end, start))
            return true;
        return false;
    } else if(end._hCoord - start._hCoord == 0 && end._vCoord - start._vCoord == a-1){
        if(_ownGrid.fillShipV(start, end))
            return true;
        return false;
    } else if (start._hCoord - end._hCoord == 0 && start._vCoord - end._vCoord == a-1){
        if(_ownGrid.fillShipV(end, start))
            return true;
        return false;
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
