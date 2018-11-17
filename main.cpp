#include "mainwindow.h"
#include <QApplication>
#include "grid.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    /*Grid *g1 = new Grid();
    Grid *g2 = new Grid();
    g1->display();
    g2->display();
    return EXIT_SUCCESS;*/
}
