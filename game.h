#ifndef GAME_H
#define GAME_H
#include "player.h"

class Game
{
private:
    Player _player1;
    Player _player2;
    int _numCurrPlayer;

public:
    explicit Game(Player p1, Player p2);
    Player getCurrentPlayer();
    void switchPlayer();
};

#endif // GAME_H
