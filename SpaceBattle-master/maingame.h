#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>
#include <QtWidgets>
#include "game.h"

namespace Ui {
class MainGame;
}

class MainGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGame(Game *g, QWidget *parent = nullptr);
    ~MainGame();
    void fillButtons();
    void fillButtonHandlers();
    void setGame(Game *g);
    void placeShipIhm(ShipType t, Coordinate firstCell, Coordinate newCell);
    void fillShipIhmH(ShipType t, Coordinate start, Coordinate end);
    void fillShipIhmV(ShipType t, Coordinate start, Coordinate end);
    void disableShip(ShipType t);
    QString getColor(ShipType t);
    void shootIhm(Status res, QPushButton *button);
    Coordinate getAllyCoord(QPushButton *b);
    Coordinate getEnemyCoord(QPushButton *b);
public slots:
    void handleShips();
    void handlePositioning();
    void handleAttack();
private:
    Ui::MainGame *ui;
    Game *_game;
    QPushButton *_ships[6];
    QPushButton *_ally[10][10];
    QPushButton *_enemy[10][10];
};

#endif // MAINGAME_H
