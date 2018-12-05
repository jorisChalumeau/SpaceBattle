#ifndef CREATEGAMESCENE_H
#define CREATEGAMESCENE_H

#include <QDialog>
#include <QTcpSocket>


namespace Ui {
class CreateGameScene;
}

class CreateGameScene : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGameScene(QString *serverName, quint32 *serverPort, QWidget *parent = nullptr);
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

};

#endif // CREATEGAMESCENE_H
