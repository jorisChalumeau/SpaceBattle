#include <QApplication>

#include "server.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationDisplayName(Server::tr("Space battle Server"));
    Server server;
    server.show();
    return app.exec();
}
