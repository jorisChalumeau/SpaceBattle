#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QTcpSocket *tcpSocket, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    mainSocket = tcpSocket;
    ui->setupUi(this);

    buttonHandlers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonHandlers(){
    connect(ui->createGameButton, SIGNAL (clicked()), this, SLOT (createGame()));
    connect(ui->joinGameButton, SIGNAL (clicked()), this, SLOT (joinGame()));
    connect(ui->settingsButton, SIGNAL (clicked()), this, SLOT (openSettings()));
}

void MainWindow::createGame(){
    CreateGameScene *scene = new CreateGameScene(mainSocket);
    scene->show();
    this->hide();
}

void MainWindow::joinGame(){
    // join selected game
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);
    Game *g = new Game(p1, p2);
    mg = new MainGame(g);
    mg->show();
    this->hide();
    /*QString txt = ui->comboBox->itemText(ui->comboBox->currentIndex());
    if(txt != ""){
        // join game txt
    }*/
}

void MainWindow::openSettings(){
    // bonus eventuel
}
