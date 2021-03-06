#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>

#include "server.h"
#include "../ClientSB/game.h"
#include "../ClientSB/game.cpp"

Server::Server(QWidget *parent)
    : QDialog(parent)
    , statusLabel(new QLabel)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    statusLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, &QNetworkSession::opened, this, &Server::sessionOpened);

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    } else {
        sessionOpened();
    }


    auto quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = nullptr;
    if (QGuiApplication::styleHints()->showIsFullScreen() || QGuiApplication::styleHints()->showIsMaximized()) {
        auto outerVerticalLayout = new QVBoxLayout(this);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
        auto outerHorizontalLayout = new QHBoxLayout;
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        auto groupBox = new QGroupBox(QGuiApplication::applicationDisplayName());
        mainLayout = new QVBoxLayout(groupBox);
        outerHorizontalLayout->addWidget(groupBox);
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        outerVerticalLayout->addLayout(outerHorizontalLayout);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
    } else {
        mainLayout = new QVBoxLayout(this);
    }

    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);

    setWindowTitle(QGuiApplication::applicationDisplayName());
}

void Server::sessionOpened()
{
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen()) {
        QMessageBox::critical(this, tr("Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Client now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
}

void Server::sendFortune()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    out << fortunes[QRandomGenerator::global()->bounded(fortunes.size())];

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);

    clientConnection->write(block);
    clientConnection->disconnectFromHost();
}

void Server::newConnection()
{
    sendAtAll(tr("<em>New client is connected</em>"));

    QTcpSocket *nouveauClient = tcpServer->nextPendingConnection();
    clients << nouveauClient;

    connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
}

void Server::dataReceived()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if (socket == 0)
        return;

    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;

    QString message;
    in >> message;

    if(message.left(10) == "CreateGame"){
        qDebug() << "games test when create";

        QStringList liste = message.split(";");

        Game *g = new Game();
        g->setCurrentPhase(NEW);
        g->setName(liste[1]);
        /*QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(endOfTimer(socket)));
        if(liste[2] == "15 min")
            timer->start(15*60*1000);
        else if(liste[2] == "30 min")
            timer->start(30*60*1000);
        else if(liste[2] == "45 min")
            timer->start(45*60*1000);
        else
            timer->start(120*60*1000); // no limit*/
        games.append(g);
        //QString Send = tr("<strong>") + ui->pseudo->text() +tr("</strong> : ") + ui->message->text();
        nbGames = games.length();
        qint16 i = 0;
        while (i < nbGames) {
            qDebug() << games[i]->getName();
            i += 1;
        }

        QString openNewGame = tr("OpenGame;") + g->getName();
        QString AddNewGame = tr("AddGame;") + g->getName();

        qDebug() << openNewGame;

        QTcpSocket *socketGame = qobject_cast<QTcpSocket *>(sender());
        qDebug() << socketGame;
        if (socket == 0)
            return;

        QByteArray paquet;
        QDataStream out(&paquet, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_10);

        out << (quint16) 0;
        out << openNewGame;
        out.device()->seek(0);
        out << (quint16) (paquet.size() - sizeof(quint16));

        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i] == socketGame){
                qDebug() << openNewGame.left(8);
                clients[i]->write(paquet);
            }
        }

        sendAtAll(AddNewGame);

        //std::array<int, 3> a2 = {1, 2, 3};
        //sendAtAll()
    } else {
        sendAtAll(message);
    }

    tailleMessage = 0;
}

void Server::endOfTimer(QTcpSocket *socket){
    // send the message to close game window
    socket->write("TimerOver");
}

void Server::deconnexionClient()
{
    sendAtAll(tr("<em>A client is disconnected</em>"));

    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void Server::sendAtAll(const QString &message)
{
    qDebug() << "test for send at all";

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    for (int i = 0; i < clients.size(); i++)
    {
        clients[i]->write(paquet);
    }

}
