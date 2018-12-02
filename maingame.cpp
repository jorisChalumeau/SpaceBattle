#include "maingame.h"
#include "ui_maingame.h"

MainGame::MainGame(Game g, QWidget *parent) :
    _game(g),
    QMainWindow(parent),
    ui(new Ui::MainGame)
{
    ui->setupUi(this);
    //*_selectedShip = NONE;
    //fillButtons();

    fillButtonHandlers();
}

void MainGame::fillButtons(){
    // buttons for battleships
    /*ships[0] = ui->battleship1;
    ships[1] = ui->battleship2;
    ships[2] = ui->battleship3_1;
    ships[3] = ui->battleship3_2;
    ships[4] = ui->battleship4;
    ships[5] = ui->battleship5;

    // button for enemyGrid
    enemy[0][0] = ui->enemyA1;
    enemy[0][1] = ui->enemyB1;
    enemy[0][2] = ui->enemyC1;
    enemy[0][3] = ui->enemyD1;
    enemy[0][4] = ui->enemyE1;
    enemy[0][5] = ui->enemyF1;
    enemy[0][6] = ui->enemyG1;
    enemy[0][7] = ui->enemyH1;
    enemy[0][8] = ui->enemyI1;
    enemy[0][9] = ui->enemyJ1;
    enemy[1][0] = ui->enemyA2;
    enemy[1][1] = ui->enemyB2;
    enemy[1][2] = ui->enemyC2;
    enemy[1][3] = ui->enemyD2;
    enemy[1][4] = ui->enemyE2;
    enemy[1][5] = ui->enemyF2;
    enemy[1][6] = ui->enemyG2;
    enemy[1][7] = ui->enemyH2;
    enemy[1][8] = ui->enemyI2;
    enemy[1][9] = ui->enemyJ2;
    enemy[2][0] = ui->enemyA3;
    enemy[2][1] = ui->enemyB3;
    enemy[2][2] = ui->enemyC3;
    enemy[2][3] = ui->enemyD3;
    enemy[2][4] = ui->enemyE3;
    enemy[2][5] = ui->enemyF3;
    enemy[2][6] = ui->enemyG3;
    enemy[2][7] = ui->enemyH3;
    enemy[2][8] = ui->enemyI3;
    enemy[2][9] = ui->enemyJ3;
    enemy[3][0] = ui->enemyA4;
    enemy[3][1] = ui->enemyB4;
    enemy[3][2] = ui->enemyC4;
    enemy[3][3] = ui->enemyD4;
    enemy[3][4] = ui->enemyE4;
    enemy[3][5] = ui->enemyF4;
    enemy[3][6] = ui->enemyG4;
    enemy[3][7] = ui->enemyH4;
    enemy[3][8] = ui->enemyI4;
    enemy[3][9] = ui->enemyJ4;
    enemy[4][0] = ui->enemyA5;
    enemy[4][1] = ui->enemyB5;
    enemy[4][2] = ui->enemyC5;
    enemy[4][3] = ui->enemyD5;
    enemy[4][4] = ui->enemyE5;
    enemy[4][5] = ui->enemyF5;
    enemy[4][6] = ui->enemyG5;
    enemy[4][7] = ui->enemyH5;
    enemy[4][8] = ui->enemyI5;
    enemy[4][9] = ui->enemyJ5;
    enemy[5][0] = ui->enemyA6;
    enemy[5][1] = ui->enemyB6;
    enemy[5][2] = ui->enemyC6;
    enemy[5][3] = ui->enemyD6;
    enemy[5][4] = ui->enemyE6;
    enemy[5][5] = ui->enemyF6;
    enemy[5][6] = ui->enemyG6;
    enemy[5][7] = ui->enemyH6;
    enemy[5][8] = ui->enemyI6;
    enemy[5][9] = ui->enemyJ6;
    enemy[6][0] = ui->enemyA7;
    enemy[6][1] = ui->enemyB7;
    enemy[6][2] = ui->enemyC7;
    enemy[6][3] = ui->enemyD7;
    enemy[6][4] = ui->enemyE7;
    enemy[6][5] = ui->enemyF7;
    enemy[6][6] = ui->enemyG7;
    enemy[6][7] = ui->enemyH7;
    enemy[6][8] = ui->enemyI7;
    enemy[6][9] = ui->enemyJ7;
    enemy[7][0] = ui->enemyA8;
    enemy[7][1] = ui->enemyB8;
    enemy[7][2] = ui->enemyC8;
    enemy[7][3] = ui->enemyD8;
    enemy[7][4] = ui->enemyE8;
    enemy[7][5] = ui->enemyF8;
    enemy[7][6] = ui->enemyG8;
    enemy[7][7] = ui->enemyH8;
    enemy[7][8] = ui->enemyI8;
    enemy[7][9] = ui->enemyJ8;
    enemy[8][0] = ui->enemyA9;
    enemy[8][1] = ui->enemyB9;
    enemy[8][2] = ui->enemyC9;
    enemy[8][3] = ui->enemyD9;
    enemy[8][4] = ui->enemyE9;
    enemy[8][5] = ui->enemyF9;
    enemy[8][6] = ui->enemyG9;
    enemy[8][7] = ui->enemyH9;
    enemy[8][8] = ui->enemyI9;
    enemy[8][9] = ui->enemyJ9;
    enemy[9][0] = ui->enemyA10;
    enemy[9][1] = ui->enemyB10;
    enemy[9][2] = ui->enemyC10;
    enemy[9][3] = ui->enemyD10;
    enemy[9][4] = ui->enemyE10;
    enemy[9][5] = ui->enemyF10;
    enemy[9][6] = ui->enemyG10;
    enemy[9][7] = ui->enemyH10;
    enemy[9][8] = ui->enemyI10;
    enemy[9][9] = ui->enemyJ10;

    // buttons for allyGrid
    ally[0][0] = ui->meA1;
    ally[0][1] = ui->meB1;
    ally[0][2] = ui->meC1;
    ally[0][3] = ui->meD1;
    ally[0][4] = ui->meE1;
    ally[0][5] = ui->meF1;
    ally[0][6] = ui->meG1;
    ally[0][7] = ui->meH1;
    ally[0][8] = ui->meI1;
    ally[0][9] = ui->meJ1;
    ally[1][0] = ui->meA2;
    ally[1][1] = ui->meB2;
    ally[1][2] = ui->meC2;
    ally[1][3] = ui->meD2;
    ally[1][4] = ui->meE2;
    ally[1][5] = ui->meF2;
    ally[1][6] = ui->meG2;
    ally[1][7] = ui->meH2;
    ally[1][8] = ui->meI2;
    ally[1][9] = ui->meJ2;
    ally[2][0] = ui->meA3;
    ally[2][1] = ui->meB3;
    ally[2][2] = ui->meC3;
    ally[2][3] = ui->meD3;
    ally[2][4] = ui->meE3;
    ally[2][5] = ui->meF3;
    ally[2][6] = ui->meG3;
    ally[2][7] = ui->meH3;
    ally[2][8] = ui->meI3;
    ally[2][9] = ui->meJ3;
    ally[3][0] = ui->meA4;
    ally[3][1] = ui->meB4;
    ally[3][2] = ui->meC4;
    ally[3][3] = ui->meD4;
    ally[3][4] = ui->meE4;
    ally[3][5] = ui->meF4;
    ally[3][6] = ui->meG4;
    ally[3][7] = ui->meH4;
    ally[3][8] = ui->meI4;
    ally[3][9] = ui->meJ4;
    ally[4][0] = ui->meA5;
    ally[4][1] = ui->meB5;
    ally[4][2] = ui->meC5;
    ally[4][3] = ui->meD5;
    ally[4][4] = ui->meE5;
    ally[4][5] = ui->meF5;
    ally[4][6] = ui->meG5;
    ally[4][7] = ui->meH5;
    ally[4][8] = ui->meI5;
    ally[4][9] = ui->meJ5;
    ally[5][0] = ui->meA6;
    ally[5][1] = ui->meB6;
    ally[5][2] = ui->meC6;
    ally[5][3] = ui->meD6;
    ally[5][4] = ui->meE6;
    ally[5][5] = ui->meF6;
    ally[5][6] = ui->meG6;
    ally[5][7] = ui->meH6;
    ally[5][8] = ui->meI6;
    ally[5][9] = ui->meJ6;
    ally[6][0] = ui->meA7;
    ally[6][1] = ui->meB7;
    ally[6][2] = ui->meC7;
    ally[6][3] = ui->meD7;
    ally[6][4] = ui->meE7;
    ally[6][5] = ui->meF7;
    ally[6][6] = ui->meG7;
    ally[6][7] = ui->meH7;
    ally[6][8] = ui->meI7;
    ally[6][9] = ui->meJ7;
    ally[7][0] = ui->meA8;
    ally[7][1] = ui->meB8;
    ally[7][2] = ui->meC8;
    ally[7][3] = ui->meD8;
    ally[7][4] = ui->meE8;
    ally[7][5] = ui->meF8;
    ally[7][6] = ui->meG8;
    ally[7][7] = ui->meH8;
    ally[7][8] = ui->meI8;
    ally[7][9] = ui->meJ8;
    ally[8][0] = ui->meA9;
    ally[8][1] = ui->meB9;
    ally[8][2] = ui->meC9;
    ally[8][3] = ui->meD9;
    ally[8][4] = ui->meE9;
    ally[8][5] = ui->meF9;
    ally[8][6] = ui->meG9;
    ally[8][7] = ui->meH9;
    ally[8][8] = ui->meI9;
    ally[8][9] = ui->meJ9;
    ally[9][0] = ui->meA10;
    ally[9][1] = ui->meB10;
    ally[9][2] = ui->meC10;
    ally[9][3] = ui->meD10;
    ally[9][4] = ui->meE10;
    ally[9][5] = ui->meF10;
    ally[9][6] = ui->meG10;
    ally[9][7] = ui->meH10;
    ally[9][8] = ui->meI10;
    ally[9][9] = ui->meJ10;*/
}

void MainGame::fillButtonHandlers() {
    // button handlers for battleships
    connect(ui->battleship1, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship2, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship3_1, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship3_2, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship4, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->battleship5, SIGNAL (released()), this, SLOT (handleShips()));
    connect(ui->lockShips, SIGNAL (released()), this, SLOT (handleShips()));

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
    Player p = _game.getCurrentPlayer();
    Coordinate *c = new Coordinate(NONE, NONE);
    p.selectCell(*c);
    if(name == "battleship1")
        p.selectShip(FISHBOAT);
    else if(name == "battleship2")
        p.selectShip(DESTROYER);
    else if(name == "battleship3_1")
        p.selectShip(SUBMARINE);
    else if(name == "battleship3_2")
        p.selectShip(CRUISER);
    else if(name == "battleship4")
        p.selectShip(BATTLESHIP);
    else if(name == "battleship5")
        p.selectShip(CARRIER);
    else
        p.selectShip(NOSHIP); //locking ship position if all ships are placed
}

void MainGame::handlePositioning()
{
    // if a ship was selected
    QPushButton* button = static_cast<QPushButton*>(sender());
    Player p = _game.getCurrentPlayer();
    if(p.getSelectedShip() != NOSHIP){
        Coordinate cell = getCoord(button);
        if(p.getSelectedCell().isNull()){
            p.selectCell(cell);
            std::cout << "selected first cell\n";
        } else {
            //ShipType t, Coord hStart, Coord vStart, Coord hEnd, Coord vEnd
            p.placeShip(p.getSelectedShip(), p.getSelectedCell(), cell);
            std::cout << "selected second cell\n";
        }
    } else {
        std::cout << "you either need to select a ship or all ships are placed already";
    }
}

Coordinate MainGame::getCoord(QPushButton *b)
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

void MainGame::placeShip(Coordinate firstCell, Coordinate newCell)
{

}

void MainGame::handleAttack()
{
    /*if(*selectedShip == NONE){// && currentPhase=BATTLING){
        QPushButton* button = static_cast<QPushButton*>(sender());
        button->setText("test");
    } else {
        std::cout << "you first need to lock the ships or it is your opponent's turn";
    }*/
}

void MainGame::setGame(Game g)
{
    _game = g;
}

MainGame::~MainGame()
{
    delete ui;
}
