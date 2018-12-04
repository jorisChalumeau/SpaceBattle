#ifndef GAME_H
#define GAME_H
#include "player.h"

enum Phase {NEW, WAITING_FOR_PLAYER, WAITING_FOR_LAUNCH, IN_PROGRESS, FINISH};

class Game
{
private:
    Player *_player1;
    Player *_player2;
    int _numCurrPlayer;
    Phase _currentPhase;

public:
    explicit Game(Player *p1, Player *p2);
    Player* getCurrentPlayer();
    void switchPlayer();
    Phase getCurrentPhase();
    void setCurrentPhase(Phase p);
};

#endif // GAME_H
