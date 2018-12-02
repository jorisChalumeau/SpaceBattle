#include "mainwindow.h"
#include "maingame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);
    Game *game = new Game(*p1, *p2);
    game->switchPlayer();
    MainGame w(*game);
    w.show();

    return a.exec();
    /*Grid *g1 = new Grid();
    Grid *g2 = new Grid();
    g1->display();
    g2->display();
    return EXIT_SUCCESS;*/
}
