#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QTcpSocket *tcpSocket, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    mainSocket = tcpSocket;
    ui->setupUi(this);
    ui->joinGameButton->setEnabled(false);


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
    connect(mainSocket, SIGNAL(readyRead()), this, SLOT(addGame()));

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
    Game *game = new Game(p1,p2);
    MainGame *w = new MainGame(game);
    w->show();
    /*QString txt = ui->comboBox->itemText(ui->comboBox->currentIndex());
    if(txt != ""){
        // join game txt
    }*/
}

void MainWindow::addGame(){
    qDebug() << "test test write message";

    QDataStream in(mainSocket);

    if (sizeMessage == 0)
    {
        if (mainSocket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> sizeMessage;
    }

    if (mainSocket->bytesAvailable() < sizeMessage)
        return;

    QString messageRecu;
    in >> messageRecu;

    qDebug() << messageRecu;

    if(messageRecu.left(7) == "AddGame"){
        ui->listGames->append(messageRecu);

        sizeMessage = 0;
    }
}

void MainWindow::openSettings(){
    // bonus eventuel
}
