#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <QString>
#include <QTimer>

enum Phase {NEW, WAITING_FOR_PLAYERS, WAITING_FOR_LAUNCH, IN_PROGRESS, FINISHs};

class Game
{
private:
    Player *_player1;
    Player *_player2;
    int _numCurrPlayer;
    Phase _currentPhase;
    QString _name;
    QTimer _timer;

public:
    explicit Game(Player *p1, Player *p2);
    explicit Game();
    Player* getCurrentPlayer();
    void switchPlayer();
    Phase getCurrentPhase();
    void setCurrentPhase(Phase p);
    QString getName();
    void setName(QString n);
};

#endif // GAME_H
