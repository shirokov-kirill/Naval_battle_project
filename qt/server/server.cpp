#include "Server.h"

Server::Server() {
    tcp_server = new QTcpServer();
    alive = false;
    state = SS_SEARCING_PLAYERS;
    connect(tcp_server, SIGNAL(newConnection()), this, SLOT(sl_newUser()));
    connect(this, SIGNAL(sig_twoPlayersConnected()), this, SLOT(sl_sendBeginRequest()));
}

void Server::start() {
    if (!tcp_server->listen(QHostAddress("127.0.0.1"), 23))
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcp_server->errorString());
    else {
        qDebug() << QString::fromUtf8("server started!");
        alive = true;
    }
}

void Server::sl_newUser() {
    if (state != SS_SEARCING_PLAYERS)
        return;
    if (alive) {
        qDebug() << QString::fromUtf8("new connection!");
        QTcpSocket* client_socket=tcp_server->nextPendingConnection();
        clients.push_back(new Client(client_socket));
        connect(clients[clients.size() - 1], SIGNAL(sig_dataReceived()), this, SLOT(sl_handleClient()));

        if (clients.size() == 2)
            emit sig_twoPlayersConnected();
            changeState();
    }
}

void Server::sl_handleClient() {
    auto client_socket = (QTcpSocket*)sender();
    int recipient = recipientNumber(client_socket);
    QString data = client_socket->readLine();
    clients[recipient]->send(data);
    qDebug() << data;

    if (data == "close\n")
        endGame();
}

void Server::sl_sendBeginRequest() {
    clients[0]->send("name"), clients[0]->send("field");
    clients[1]->send("name"), clients[1]->send("field");
}

void Server::changeState() {
    state = (state == SS_SEARCING_PLAYERS) ? SS_GAME_IN_PROCESS : SS_SEARCING_PLAYERS;
}

int Server::recipientNumber(QTcpSocket* sender) {
    return (sender == clients[0]->ptr()) ? 0 : 1;
}

void Server::endGame() {
    clients.clear();
    changeState();
}
