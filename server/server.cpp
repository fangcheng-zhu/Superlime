#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if (!server->listen(QHostAddress::Any, 12345))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started";
    }
}

void Server::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->waitForReadyRead(3000);

    QFile sFile("hello.java");
    if (sFile.open(QFile::WriteOnly | QFile::Text))
    {
        sFile.write(socket->readAll());
        sFile.flush();
        sFile.close();
    }

    socket->write("hello client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
}
