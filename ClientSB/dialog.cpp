#include <QtWidgets>
#include <QtNetwork>
#include <QApplication>
#include <QTcpSocket>

#include "game.h"
#include "mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"

dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog),
    tcpSocket(new QTcpSocket(this))

{
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->hostCombo->setEditable(true);
    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty()) {
        ui->hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            ui->hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QLatin1String("localhost"))
        ui->hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (!ipAddressesList.at(i).isLoopback())
            ui->hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i).isLoopback())
            ui->hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    ui->portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    ui->statusLabel->setText("You must to connect to the server.");

    ui->getFortuneButton->setDefault(true);
    ui->getFortuneButton->setEnabled(false);



    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    //connect(okButton, SIGNAL(clicked()), this, SLOT(checkValues()));

    connect(ui->portLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT (enableGetFortuneButton()));
    //connect(ui->getFortuneButton, SIGNAL(clicked()), this, SLOT(requestNewFortune()));
    connect(ui->getFortuneButton, SIGNAL(clicked()), this, SLOT(connection()));
    connect(ui->boutonEnvoyer, SIGNAL(clicked()), this, SLOT(on_boutonEnvoyer_clicked()));
    connect(ui->buttonGame, SIGNAL(clicked()), this, SLOT(lanchGamePortal()));
    connect(ui->decoButton, SIGNAL(clicked()), this, SLOT(disconnectUser()));


    //connect(tcpSocket, &QIODevice::readyRead, this, &dialog::readFortune);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &dialog::displayError);


    setWindowTitle(QGuiApplication::applicationDisplayName());
    ui->portLineEdit->setFocus();

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
        connect(networkSession, &QNetworkSession::opened, this, &dialog::sessionOpened);

        ui->getFortuneButton->setEnabled(false);
        ui->statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }

}
void dialog::requestNewFortune()
{

    ui->getFortuneButton->setEnabled(false);
    tcpSocket->abort();
    tcpSocket->connectToHost(ui->hostCombo->currentText(), ui->portLineEdit->text().toInt());
}

void dialog::readFortune()
{
    in.startTransaction();

    QString nextFortune;
    in >> nextFortune;

    if (!in.commitTransaction())
        return;

    if (nextFortune == currentFortune) {
        QTimer::singleShot(0, this, &dialog::requestNewFortune);
        return;
    }

    currentFortune = nextFortune;
    qDebug() << currentFortune;

    ui->statusLabel->setText(currentFortune);
    ui->getFortuneButton->setEnabled(true);
}

void dialog::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Connection Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Connection Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Connection Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }

    ui->getFortuneButton->setEnabled(true);
}

void dialog::enableGetFortuneButton()
{
    qDebug() << "enter in enable get fortune";

    ui->getFortuneButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                 !ui->hostCombo->currentText().isEmpty() &&
                                 !ui->portLineEdit->text().isEmpty());
}

void dialog::sessionOpened()
{
    // Save the used configuration
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

    ui->statusLabel->setText(tr("You must to connect to the server."));

    enableGetFortuneButton();
}


void dialog::connection()
{
    ui->listeMessages->append(tr("<em>Tentative de connexion en cours...</em>"));
    ui->getFortuneButton->setEnabled(false);

    qDebug() << "Verif connection";

    serverPort = ui->portLineEdit->text().toInt();
    qDebug() << serverPort;

    serverName = ui->hostCombo->currentText();
    qDebug() << serverName;


    tcpSocket->abort();
    tcpSocket->connectToHost(serverName, serverPort);
}

// Envoi d'un message au serveur
void dialog::on_boutonEnvoyer_clicked()
{

    qDebug() << "test but envoyer";

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    QString messageAEnvoyer = tr("<strong>") + ui->pseudo->text() +tr("</strong> : ") + ui->message->text();

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    tcpSocket->write(paquet); // On envoie le paquet

    ui->message->clear();
    ui->message->setFocus();
}

void dialog::on_message_returnPressed()
{
    on_boutonEnvoyer_clicked();
}

void dialog::donneesRecues()
{
    qDebug() << "test test write message";

    QDataStream in(tcpSocket);

    if (sizeMessage == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> sizeMessage;
    }

    if (tcpSocket->bytesAvailable() < sizeMessage)
        return;

    QString messageRecu;
    in >> messageRecu;

    qDebug() << messageRecu;

    ui->listeMessages->append(messageRecu);

    sizeMessage = 0;
}

void dialog::connecte()
{
    ui->listeMessages->append(tr("<em>Connectionion succesful !</em>"));
    ui->getFortuneButton->setEnabled(true);
}


void dialog::disconnectUser()
{
    tcpSocket->abort();
}

void dialog::deconnecte()
{
    ui->listeMessages->append(tr("<em>Disconnected</em>"));
}

// Ce slot est appel� lorsqu'on est d�connect� du serveur
void dialog::lanchGamePortal()
{
    qDebug() << serverPort;

    qDebug() << serverName;

    mainW = new MainWindow(&serverName, &serverPort); // Be sure to destroy your window somewhere
    mainW->show();
}

dialog::~dialog()
{
    delete ui;
}
