#include "game.h"

Game::Game(Player *p1, Player *p2) : _player1(p1), _player2(p2), _currentPhase(PLACEMENT), _numCurrPlayer(1) {}

void Game::switchPlayer(){
    if(this->_numCurrPlayer == 0 || this->_numCurrPlayer==2)
        this->_numCurrPlayer=1;
    else
        this->_numCurrPlayer=2;
}

Player* Game::getCurrentPlayer(){
    if(this->_numCurrPlayer==2)
        return this->_player2;
    return this->_player1;
}

Phase Game::getCurrentPhase(){
    return _currentPhase;
}

void Game::setCurrentPhase(Phase p){
    _currentPhase = p;
}
