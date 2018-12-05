#include "creategamescene.h"
#include "ui_creategamescene.h"

CreateGameScene::CreateGameScene(QString *serverName, quint32 *serverPort, QWidget *parent) :
    QDialog(parent),
    _serverName(serverName),
    _serverPort(serverPort),
    ui(new Ui::CreateGameScene),
    gameSocket(new QTcpSocket(this))

{
    ui->setupUi(this);
    buttonHandlers();
}

void CreateGameScene::buttonHandlers(){
    ui->timeLimitCombo->addItem("no limit");
    ui->timeLimitCombo->addItem("15 min");
    ui->timeLimitCombo->addItem("30 min");
    ui->timeLimitCombo->addItem("45 min");
    ui->timeLimitCombo->setCurrentIndex(0);
    this->time = "no limit";

    ui->viewersCheckBox->setChecked(false);
    this->viewers = false;

    ui->nameLineEdit->setText("player");
    this->name = "player";

    connect(ui->nameLineEdit, SIGNAL (textChanged(QString)), this, SLOT (editName(QString)));
    connect(ui->timeLimitCombo, SIGNAL (currentIndexChanged(int)), this, SLOT (editTimeLimit(int)));
    connect(ui->viewersCheckBox, SIGNAL (clicked(bool)), this, SLOT (editViewers(bool)));
    connect(ui->okButton, SIGNAL (clicked()), this, SLOT (submit()));
    connect(ui->cancelButton, SIGNAL (clicked()), this, SLOT (cancel()));
}

void CreateGameScene::editName(QString name){
    this->name = name;
}

void CreateGameScene::editTimeLimit(int index){
    this->time = ui->timeLimitCombo->itemText(index);
}

void CreateGameScene::editViewers(bool state){
    this->viewers = state;
}

void CreateGameScene::cancel(){
    this->close();
}

void CreateGameScene::submit(){
    //submit game with defined settings
    gameSocket->abort();
    gameSocket->connectToHost(*_serverName, *_serverPort);
    QString msgToSend = "CreateGame;"+this->name+";"+this->time;
    gameSocket->write(msgToSend.toStdString().c_str(), msgToSend.length());
}

CreateGameScene::~CreateGameScene()
{
    delete ui;
}
