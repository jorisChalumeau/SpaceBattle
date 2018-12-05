#ifndef DIALOG_H
#define DIALOG_H

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>
#include <QObject>
#include <QWidget>

#include "mainwindow.h"

class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);    
    ~dialog();

private slots:
    void requestNewFortune();
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetFortuneButton();
    void sessionOpened();

    void connection();
    void on_boutonEnvoyer_clicked();
    void on_message_returnPressed();
    void donneesRecues();
    void connecte();
    void disconnectUser();
    void deconnecte();
    void lanchGamePortal();

private:
    Ui::dialog *ui;

    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QString currentFortune;

    QString serverName;
    quint32 serverPort;

    QNetworkSession *networkSession = nullptr;
    quint16 sizeMessage;
    MainWindow *mainW;

};

#endif // DIALOG_H
