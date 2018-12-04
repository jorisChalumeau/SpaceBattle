#include "mainwindow.h"
#include "maingame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);
    Game *game = new Game(p1, p2);
    MainGame w(game);
    w.show();
    MainWindow g;
    g.show();

    return a.exec();
}
