#include "player.h"

Player::Player(int numPlayer, Grid ownGrid, Grid enemyGrid)
        : _numPlayer(numPlayer), _ownGrid(ownGrid), _enemyGrid(enemyGrid) {}

void Player::shoot(Coord hCoord, Coord vCoord) {
    std::cout << "\nshot in (" << hCoord << "," << vCoord << ")";
}

Player::~Player() = default;
