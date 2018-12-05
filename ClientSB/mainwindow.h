#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "creategamescene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void buttonHandlers();
    ~MainWindow();
public slots:
    void createGame();
    void joinGame();
    void openSettings();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
