#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>
#include <QtWidgets>
#include "game.h"

enum Phase {POSITIONING, BATTLING};

namespace Ui {
class MainGame;
}

class MainGame : public QMainWindow
{
    Q_OBJECT
private:
    Game _game;
public:
    explicit MainGame(Game g, QWidget *parent = nullptr);
    ~MainGame();
    void fillButtons();
    void fillButtonHandlers();
    void setGame(Game g);
    void placeShip(Coordinate firstCell, Coordinate newCell);
    Coordinate getCoord(QPushButton *b);
public slots:
    void handleShips();
    void handlePositioning();
    void handleAttack();
private:
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
