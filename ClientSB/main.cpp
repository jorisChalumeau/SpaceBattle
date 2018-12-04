#include <QApplication>
#include "dialog.h"
#include "mainwindow.h"
#include "maingame.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QApplication::setApplicationDisplayName(dialog::tr("Connection Client"));
    dialog dialog;
    dialog.show();

    return app.exec();

}

