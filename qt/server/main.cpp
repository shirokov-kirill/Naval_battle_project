#include <QCoreApplication>
#include <Server.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server *server = new Server();
    server->start();

    return a.exec();
}
