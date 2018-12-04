#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QTcpSocket>

#include "../ClientSB/game.h"

class QLabel;
class QTcpServer;
class QNetworkSession;

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);

private slots:
    void sessionOpened();
    void sendFortune();
    void newConnection();
    void dataReceived();
    void deconnexionClient();
    void sendAtAll(const QString &message);

private:
    QLabel *statusLabel = nullptr;
    QTcpServer *tcpServer = nullptr;
    QVector<QString> fortunes;
    QNetworkSession *networkSession = nullptr;
    QList<QTcpSocket *> clients;
    QVector<Game *> games;
    quint16 tailleMessage;
};

#endif
