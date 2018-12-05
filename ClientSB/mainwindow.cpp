#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    CreateGameScene *scene = new CreateGameScene();
    scene->show();
    this->hide();
}

void MainWindow::joinGame(){
    // join selected game
    QString txt = ui->comboBox->itemText(ui->comboBox->currentIndex());
    if(txt != ""){
        // join game txt
    }
}

void MainWindow::openSettings(){
    // bonus eventuel
}
