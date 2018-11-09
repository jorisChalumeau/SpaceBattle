//
// Created by 43cb886c4537 on 09/11/2018.
//

#include "Player.h"

Player::Player(int numPlayer, Grid ownGrid, Grid enemyGrid)
        : _numPlayer(numPlayer), _enemyGrid(enemyGrid), _ownGrid(ownGrid) {}

void Player::shoot(Coord hCoord, Coord vCoord) {
    std::cout << "\nshot in (" << hCoord << "," << vCoord << ")";
}

Player::~Player() = default;