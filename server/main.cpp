#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 2)
    {
        qDebug() << "Usage: <port>";
    }
    else
    {
        Server myServer(argv[1]);
    }

    return a.exec();
}
