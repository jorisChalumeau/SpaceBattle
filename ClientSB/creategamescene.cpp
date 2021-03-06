#include "creategamescene.h"
#include "ui_creategamescene.h"

CreateGameScene::CreateGameScene(QTcpSocket *tcpSocket, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGameScene)
{
    gameSocket = tcpSocket;

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
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    QString msgToSend = "CreateGame;"+this->name+";"+this->time;

    out << (quint16) 0;
    out << msgToSend;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    qDebug() << "paquet game value";
    qDebug() << paquet;

    gameSocket->write(paquet);
}

CreateGameScene::~CreateGameScene()
{
    delete ui;
}
