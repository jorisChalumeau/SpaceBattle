#ifndef CREATEGAMESCENE_H
#define CREATEGAMESCENE_H

#include <QDialog>
#include <QTcpSocket>

#include "maingame.h"


namespace Ui {
class CreateGameScene;
}

class CreateGameScene : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGameScene(QTcpSocket *tcpSocket, QWidget *parent = nullptr);
    ~CreateGameScene();
    void buttonHandlers();
public slots:
    void editName(QString name);
    void editTimeLimit(int index);
    void editViewers(bool);
    void cancel();
    void submit();
private:
    Ui::CreateGameScene *ui;
    QString name;
    QString time;
    bool viewers;
    QTcpSocket *gameSocket = nullptr;
    quint16 sizeMessage;

};

#endif // CREATEGAMESCENE_H
