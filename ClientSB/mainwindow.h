#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>
#include <QObject>
#include <QWidget>
#include <QMainWindow>

#include <QMainWindow>
#include <QComboBox>
#include "creategamescene.h"

class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString *serverName, quint32 *serverPort, QWidget *parent = nullptr);
    void buttonHandlers();
    ~MainWindow();
public slots:
    void createGame();
    void joinGame();
    void openSettings();
private:
    Ui::MainWindow *ui;
    CreateGameScene *cgs;
    QString serverNameVal;
    quint32 serverPortVal;
};

#endif // MAINWINDOW_H
