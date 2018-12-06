#include "game.h"

Game::Game(Player *p1, Player *p2) : _player1(p1), _player2(p2), _currentPhase(WAITING_FOR_LAUNCH), _numCurrPlayer(1) {}

Game::Game() : _numCurrPlayer(1), _currentPhase(NEW) {}

//Game::Game() {}

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

QString Game::getName(){
    return _name;
}

void Game::setName(QString n){
    _name = n;
}

/*QTimer Game::getTimer(){
    return _timer;
}

void Game::setTimer(QTimer t){
    _timer = t;
}*/


