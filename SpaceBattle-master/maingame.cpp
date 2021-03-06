#include "maingame.h"
#include "ui_maingame.h"

MainGame::MainGame(Game *g, QWidget *parent) :
    _game(g),
    QMainWindow(parent),
    ui(new Ui::MainGame)
{
    ui->setupUi(this);

    fillButtons();
    fillButtonHandlers();
}

void MainGame::fillButtons(){
    // buttons for battleships
    _ships[0] = ui->battleship1;
    _ships[1] = ui->battleship2;
    _ships[2] = ui->battleship3_1;
    _ships[3] = ui->battleship3_2;
    _ships[4] = ui->battleship4;
    _ships[5] = ui->battleship5;
    _ships[0]->setStyleSheet("QPushButton { background-color: "+getColor(FISHBOAT)+" }");
    _ships[1]->setStyleSheet("QPushButton { background-color: "+getColor(DESTROYER)+" }");
    _ships[2]->setStyleSheet("QPushButton { background-color: "+getColor(SUBMARINE)+" }");
    _ships[3]->setStyleSheet("QPushButton { background-color: "+getColor(CRUISER)+" }");
    _ships[4]->setStyleSheet("QPushButton { background-color: "+getColor(BATTLESHIP)+" }");
    _ships[5]->setStyleSheet("QPushButton { background-color: "+getColor(CARRIER)+" }");

    // button for enemyGrid
    _enemy[0][0] = ui->enemyA1;
    _enemy[0][1] = ui->enemyB1;
    _enemy[0][2] = ui->enemyC1;
    _enemy[0][3] = ui->enemyD1;
    _enemy[0][4] = ui->enemyE1;
    _enemy[0][5] = ui->enemyF1;
    _enemy[0][6] = ui->enemyG1;
    _enemy[0][7] = ui->enemyH1;
    _enemy[0][8] = ui->enemyI1;
    _enemy[0][9] = ui->enemyJ1;
    _enemy[1][0] = ui->enemyA2;
    _enemy[1][1] = ui->enemyB2;
    _enemy[1][2] = ui->enemyC2;
    _enemy[1][3] = ui->enemyD2;
    _enemy[1][4] = ui->enemyE2;
    _enemy[1][5] = ui->enemyF2;
    _enemy[1][6] = ui->enemyG2;
    _enemy[1][7] = ui->enemyH2;
    _enemy[1][8] = ui->enemyI2;
    _enemy[1][9] = ui->enemyJ2;
    _enemy[2][0] = ui->enemyA3;
    _enemy[2][1] = ui->enemyB3;
    _enemy[2][2] = ui->enemyC3;
    _enemy[2][3] = ui->enemyD3;
    _enemy[2][4] = ui->enemyE3;
    _enemy[2][5] = ui->enemyF3;
    _enemy[2][6] = ui->enemyG3;
    _enemy[2][7] = ui->enemyH3;
    _enemy[2][8] = ui->enemyI3;
    _enemy[2][9] = ui->enemyJ3;
    _enemy[3][0] = ui->enemyA4;
    _enemy[3][1] = ui->enemyB4;
    _enemy[3][2] = ui->enemyC4;
    _enemy[3][3] = ui->enemyD4;
    _enemy[3][4] = ui->enemyE4;
    _enemy[3][5] = ui->enemyF4;
    _enemy[3][6] = ui->enemyG4;
    _enemy[3][7] = ui->enemyH4;
    _enemy[3][8] = ui->enemyI4;
    _enemy[3][9] = ui->enemyJ4;
    _enemy[4][0] = ui->enemyA5;
    _enemy[4][1] = ui->enemyB5;
    _enemy[4][2] = ui->enemyC5;
    _enemy[4][3] = ui->enemyD5;
    _enemy[4][4] = ui->enemyE5;
    _enemy[4][5] = ui->enemyF5;
    _enemy[4][6] = ui->enemyG5;
    _enemy[4][7] = ui->enemyH5;
    _enemy[4][8] = ui->enemyI5;
    _enemy[4][9] = ui->enemyJ5;
    _enemy[5][0] = ui->enemyA6;
    _enemy[5][1] = ui->enemyB6;
    _enemy[5][2] = ui->enemyC6;
    _enemy[5][3] = ui->enemyD6;
    _enemy[5][4] = ui->enemyE6;
    _enemy[5][5] = ui->enemyF6;
    _enemy[5][6] = ui->enemyG6;
    _enemy[5][7] = ui->enemyH6;
    _enemy[5][8] = ui->enemyI6;
    _enemy[5][9] = ui->enemyJ6;
    _enemy[6][0] = ui->enemyA7;
    _enemy[6][1] = ui->enemyB7;
    _enemy[6][2] = ui->enemyC7;
    _enemy[6][3] = ui->enemyD7;
    _enemy[6][4] = ui->enemyE7;
    _enemy[6][5] = ui->enemyF7;
    _enemy[6][6] = ui->enemyG7;
    _enemy[6][7] = ui->enemyH7;
    _enemy[6][8] = ui->enemyI7;
    _enemy[6][9] = ui->enemyJ7;
    _enemy[7][0] = ui->enemyA8;
    _enemy[7][1] = ui->enemyB8;
    _enemy[7][2] = ui->enemyC8;
    _enemy[7][3] = ui->enemyD8;
    _enemy[7][4] = ui->enemyE8;
    _enemy[7][5] = ui->enemyF8;
    _enemy[7][6] = ui->enemyG8;
    _enemy[7][7] = ui->enemyH8;
    _enemy[7][8] = ui->enemyI8;
    _enemy[7][9] = ui->enemyJ8;
    _enemy[8][0] = ui->enemyA9;
    _enemy[8][1] = ui->enemyB9;
    _enemy[8][2] = ui->enemyC9;
    _enemy[8][3] = ui->enemyD9;
    _enemy[8][4] = ui->enemyE9;
    _enemy[8][5] = ui->enemyF9;
    _enemy[8][6] = ui->enemyG9;
    _enemy[8][7] = ui->enemyH9;
    _enemy[8][8] = ui->enemyI9;
    _enemy[8][9] = ui->enemyJ9;
    _enemy[9][0] = ui->enemyA10;
    _enemy[9][1] = ui->enemyB10;
    _enemy[9][2] = ui->enemyC10;
    _enemy[9][3] = ui->enemyD10;
    _enemy[9][4] = ui->enemyE10;
    _enemy[9][5] = ui->enemyF10;
    _enemy[9][6] = ui->enemyG10;
    _enemy[9][7] = ui->enemyH10;
    _enemy[9][8] = ui->enemyI10;
    _enemy[9][9] = ui->enemyJ10;

    // buttons for allyGrid
    _ally[0][0] = ui->meA1;
    _ally[0][1] = ui->meB1;
    _ally[0][2] = ui->meC1;
    _ally[0][3] = ui->meD1;
    _ally[0][4] = ui->meE1;
    _ally[0][5] = ui->meF1;
    _ally[0][6] = ui->meG1;
    _ally[0][7] = ui->meH1;
    _ally[0][8] = ui->meI1;
    _ally[0][9] = ui->meJ1;
    _ally[1][0] = ui->meA2;
    _ally[1][1] = ui->meB2;
    _ally[1][2] = ui->meC2;
    _ally[1][3] = ui->meD2;
    _ally[1][4] = ui->meE2;
    _ally[1][5] = ui->meF2;
    _ally[1][6] = ui->meG2;
    _ally[1][7] = ui->meH2;
    _ally[1][8] = ui->meI2;
    _ally[1][9] = ui->meJ2;
    _ally[2][0] = ui->meA3;
    _ally[2][1] = ui->meB3;
    _ally[2][2] = ui->meC3;
    _ally[2][3] = ui->meD3;
    _ally[2][4] = ui->meE3;
    _ally[2][5] = ui->meF3;
    _ally[2][6] = ui->meG3;
    _ally[2][7] = ui->meH3;
    _ally[2][8] = ui->meI3;
    _ally[2][9] = ui->meJ3;
    _ally[3][0] = ui->meA4;
    _ally[3][1] = ui->meB4;
    _ally[3][2] = ui->meC4;
    _ally[3][3] = ui->meD4;
    _ally[3][4] = ui->meE4;
    _ally[3][5] = ui->meF4;
    _ally[3][6] = ui->meG4;
    _ally[3][7] = ui->meH4;
    _ally[3][8] = ui->meI4;
    _ally[3][9] = ui->meJ4;
    _ally[4][0] = ui->meA5;
    _ally[4][1] = ui->meB5;
    _ally[4][2] = ui->meC5;
    _ally[4][3] = ui->meD5;
    _ally[4][4] = ui->meE5;
    _ally[4][5] = ui->meF5;
    _ally[4][6] = ui->meG5;
    _ally[4][7] = ui->meH5;
    _ally[4][8] = ui->meI5;
    _ally[4][9] = ui->meJ5;
    _ally[5][0] = ui->meA6;
    _ally[5][1] = ui->meB6;
    _ally[5][2] = ui->meC6;
    _ally[5][3] = ui->meD6;
    _ally[5][4] = ui->meE6;
    _ally[5][5] = ui->meF6;
    _ally[5][6] = ui->meG6;
    _ally[5][7] = ui->meH6;
    _ally[5][8] = ui->meI6;
    _ally[5][9] = ui->meJ6;
    _ally[6][0] = ui->meA7;
    _ally[6][1] = ui->meB7;
    _ally[6][2] = ui->meC7;
    _ally[6][3] = ui->meD7;
    _ally[6][4] = ui->meE7;
    _ally[6][5] = ui->meF7;
    _ally[6][6] = ui->meG7;
    _ally[6][7] = ui->meH7;
    _ally[6][8] = ui->meI7;
    _ally[6][9] = ui->meJ7;
    _ally[7][0] = ui->meA8;
    _ally[7][1] = ui->meB8;
    _ally[7][2] = ui->meC8;
    _ally[7][3] = ui->meD8;
    _ally[7][4] = ui->meE8;
    _ally[7][5] = ui->meF8;
    _ally[7][6] = ui->meG8;
    _ally[7][7] = ui->meH8;
    _ally[7][8] = ui->meI8;
    _ally[7][9] = ui->meJ8;
    _ally[8][0] = ui->meA9;
    _ally[8][1] = ui->meB9;
    _ally[8][2] = ui->meC9;
    _ally[8][3] = ui->meD9;
    _ally[8][4] = ui->meE9;
    _ally[8][5] = ui->meF9;
    _ally[8][6] = ui->meG9;
    _ally[8][7] = ui->meH9;
    _ally[8][8] = ui->meI9;
    _ally[8][9] = ui->meJ9;
    _ally[9][0] = ui->meA10;
    _ally[9][1] = ui->meB10;
    _ally[9][2] = ui->meC10;
    _ally[9][3] = ui->meD10;
    _ally[9][4] = ui->meE10;
    _ally[9][5] = ui->meF10;
    _ally[9][6] = ui->meG10;
    _ally[9][7] = ui->meH10;
    _ally[9][8] = ui->meI10;
    _ally[9][9] = ui->meJ10;
}

void MainGame::fillButtonHandlers() {
    // button handlers for battleships
    connect(ui->battleship1, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship2, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship3_1, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship3_2, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship4, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship5, SIGNAL (released()), this, SLOT (handleShips()));

    // button handlers for enemyGrid
    connect(ui->enemyA1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ1, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ2, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ3, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ4, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ5, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ6, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ7, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ8, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ9, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyA10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyB10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyC10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyD10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyE10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyF10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyG10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyH10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyI10, SIGNAL (released()), this, SLOT (handleAttack()));
    connect(ui->enemyJ10, SIGNAL (released()), this, SLOT (handleAttack()));

    // button handlers for playerGrid
    connect(ui->meA1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ1, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ2, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ3, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ4, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ5, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ6, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ7, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ8, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ9, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meA10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meB10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meC10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meD10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meE10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meF10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meG10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meH10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meI10, SIGNAL (released()), this, SLOT (handlePositioning()));
    connect(ui->meJ10, SIGNAL (released()), this, SLOT (handlePositioning()));
}

void MainGame::handleShips()
{
    QPushButton* button = static_cast<QPushButton*>(sender());
    std::string name = button->objectName().toLocal8Bit().constData();
    Player *p = _game->getCurrentPlayer();
    Coordinate *c = new Coordinate(NONE, NONE);
    p->selectCell(*c);
    if(name == "battleship1")
        p->selectShip(FISHBOAT);
    else if(name == "battleship2")
        p->selectShip(DESTROYER);
    else if(name == "battleship3_1")
        p->selectShip(SUBMARINE);
    else if(name == "battleship3_2")
        p->selectShip(CRUISER);
    else if(name == "battleship4")
        p->selectShip(BATTLESHIP);
    else if(name == "battleship5")
        p->selectShip(CARRIER);
    else
        p->selectShip(NOSHIP); //locking ship position if all ships are placed
}

void MainGame::handlePositioning()
{
    // if a ship was selected
    QPushButton* button = static_cast<QPushButton*>(sender());
    Player *p = _game->getCurrentPlayer();
    if(p->getSelectedShip() != NOSHIP){
        Coordinate cell = getAllyCoord(button);
        if(p->getSelectedCell().isNull()){
            p->selectCell(cell);
        } else {
            //ShipType t, Coord hStart, Coord vStart, Coord hEnd, Coord vEnd
            if(p->placeShip(p->getSelectedShip(), p->getSelectedCell(), cell)){
                placeShipIhm(p->getSelectedShip(), p->getSelectedCell(), cell);
                p->selectShip(NOSHIP);
            }
            p->selectCell(*new Coordinate(NONE, NONE));
        }
    } else {
        std::cout << "you either need to select a ship or all ships are placed already\n";
    }
}

void MainGame::placeShipIhm(ShipType t, Coordinate start, Coordinate end)
{
    ShipType a = t;
    if(t == 6)
        a=SUBMARINE;
    if(end._hCoord - start._hCoord == a-1 && end._vCoord - start._vCoord == 0)
        fillShipIhmH(t, start, end);
    else if (start._hCoord - end._hCoord == a-1 && start._vCoord - end._vCoord == 0)
        fillShipIhmH(t, end, start);
    else if(end._hCoord - start._hCoord == 0 && end._vCoord - start._vCoord == a-1)
        fillShipIhmV(t, start, end);
    else if (start._hCoord - end._hCoord == 0 && start._vCoord - end._vCoord == a-1)
        fillShipIhmV(t, end, start);
    disableShip(t);
}

void MainGame::fillShipIhmH(ShipType t, Coordinate start, Coordinate end){
    for(int i=start._hCoord ; i<=end._hCoord ; i++){
        _ally[start._vCoord-1][i-1]->setStyleSheet("QPushButton { background-color: "+getColor(t)+" }");
    }
}

void MainGame::fillShipIhmV(ShipType t, Coordinate start, Coordinate end){
    for(int i=start._vCoord ; i<=end._vCoord ; i++){
        _ally[i-1][start._hCoord-1]->setStyleSheet("QPushButton { background-color: "+getColor(t)+"; }");
    }
}

QString MainGame::getColor(ShipType t){
    switch(t){
    case FISHBOAT: return *new QString("rgb(0, 191, 255)");
    case DESTROYER: return *new QString("rgb(0, 210, 180)");
    case SUBMARINE: return *new QString("rgb(200, 10, 10)");
    case CRUISER: return *new QString("rgb(200, 150, 10)");
    case BATTLESHIP: return *new QString("rgb(100, 60, 120)");
    case CARRIER: return *new QString("rgb(100, 60, 10)");
    default: return *new QString("rgb(50, 50, 50)");
    }
}

void MainGame::disableShip(ShipType t){
    switch(t){
    case FISHBOAT: _ships[0]->setEnabled(false);_ships[0]->setStyleSheet("QPushButton { background-color: #888; }");break;
    case DESTROYER: _ships[1]->setEnabled(false);_ships[1]->setStyleSheet("QPushButton { background-color: #888; }");break;
    case SUBMARINE: _ships[2]->setEnabled(false);_ships[2]->setStyleSheet("QPushButton { background-color: #888; }");break;
    case CRUISER: _ships[3]->setEnabled(false);_ships[3]->setStyleSheet("QPushButton { background-color: #888; }");break;
    case BATTLESHIP: _ships[4]->setEnabled(false);_ships[4]->setStyleSheet("QPushButton { background-color: #888; }");break;
    case CARRIER: _ships[5]->setEnabled(false);_ships[5]->setStyleSheet("QPushButton { background-color: #888; }");break;
    default:;
    }
}

Coordinate MainGame::getAllyCoord(QPushButton *b)
{
    Coord h;
    Coord v;
    std::string cell = b->objectName().toLocal8Bit().constData();

    if(cell.substr(2,1)=="A")
        h=A;
    else if(cell.substr(2,1)=="B")
        h=B;
    else if(cell.substr(2,1)=="C")
        h=C;
    else if(cell.substr(2,1)=="D")
        h=D;
    else if(cell.substr(2,1)=="E")
        h=E;
    else if(cell.substr(2,1)=="F")
        h=F;
    else if(cell.substr(2,1)=="G")
        h=G;
    else if(cell.substr(2,1)=="H")
        h=H;
    else if(cell.substr(2,1)=="I")
        h=I;
    else if(cell.substr(2,1)=="J")
        h=J;
    else
        h=NONE;

    if(cell.substr(3,2)=="1")
        v=A;
    else if(cell.substr(3,2)=="2")
        v=B;
    else if(cell.substr(3,2)=="3")
        v=C;
    else if(cell.substr(3,2)=="4")
        v=D;
    else if(cell.substr(3,2)=="5")
        v=E;
    else if(cell.substr(3,2)=="6")
        v=F;
    else if(cell.substr(3,2)=="7")
        v=G;
    else if(cell.substr(3,2)=="8")
        v=H;
    else if(cell.substr(3,2)=="9")
        v=I;
    else if(cell.substr(3,2)=="10")
        v=J;
    else
        v=NONE;

    return *new Coordinate(h, v);
}

Coordinate MainGame::getEnemyCoord(QPushButton *b)
{
    Coord h;
    Coord v;
    std::string cell = b->objectName().toLocal8Bit().constData();

    if(cell.substr(5,1)=="A")
        h=A;
    else if(cell.substr(5,1)=="B")
        h=B;
    else if(cell.substr(5,1)=="C")
        h=C;
    else if(cell.substr(5,1)=="D")
        h=D;
    else if(cell.substr(5,1)=="E")
        h=E;
    else if(cell.substr(5,1)=="F")
        h=F;
    else if(cell.substr(5,1)=="G")
        h=G;
    else if(cell.substr(5,1)=="H")
        h=H;
    else if(cell.substr(5,1)=="I")
        h=I;
    else if(cell.substr(5,1)=="J")
        h=J;
    else
        h=NONE;

    if(cell.substr(6,2)=="1")
        v=A;
    else if(cell.substr(6,2)=="2")
        v=B;
    else if(cell.substr(6,2)=="3")
        v=C;
    else if(cell.substr(6,2)=="4")
        v=D;
    else if(cell.substr(6,2)=="5")
        v=E;
    else if(cell.substr(6,2)=="6")
        v=F;
    else if(cell.substr(6,2)=="7")
        v=G;
    else if(cell.substr(6,2)=="8")
        v=H;
    else if(cell.substr(6,2)=="9")
        v=I;
    else if(cell.substr(6,2)=="10")
        v=J;
    else
        v=NONE;

    return *new Coordinate(h, v);
}

void MainGame::handleAttack()
{
    QPushButton* button = static_cast<QPushButton*>(sender());
    Player *p = _game->getCurrentPlayer();
    if(_game->getCurrentPhase() == BATTLING){
        shootIhm(p->shoot(getEnemyCoord(button)), button);
    } else {
        _game->setCurrentPhase(BATTLING);
        std::cout << "you first need to place all your ships or it is your opponent's turn";
    }
}

void MainGame::shootIhm(Status res, QPushButton *button){
    if(res == MISS)
        button->setStyleSheet("QPushButton { background-color: #FFF; }");
    else
        button->setStyleSheet("QPushButton { background-color: #F22; }");
}

void MainGame::setGame(Game *g)
{
    _game = g;
}

MainGame::~MainGame()
{
    delete ui;
}
