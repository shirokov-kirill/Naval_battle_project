#include "Server.h"
#include <windows.h>

Server::Server() {
    tcp_server = new QTcpServer();
    alive = false;
    state = SS_SEARCHING_PLAYERS;
    authorizating_player = 0;

    connect(tcp_server, SIGNAL(newConnection()), this, SLOT(sl_newUser()));
}

Server::~Server() {
    delete tcp_server;
    for (int i = 0; i < clients.size(); ++i) {
        delete clients[i];
    }
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
    if (state != SS_SEARCHING_PLAYERS)
        return;
    if (alive) {
        qDebug() << QString::fromUtf8("new connection!");
        clients.push_back(new Client(tcp_server->nextPendingConnection()));

        connect(clients[clients.size() - 1], SIGNAL(sig_dataReceived(QTcpSocket*)), this, SLOT(sl_handleClient(QTcpSocket*)));

        if (clients.size() == 2) {
            setState(SS_AUTHORIZATION);
            sendAuthRequest();
        }
    }
}

void Server::sl_handleClient(QTcpSocket *client_socket) {
//    int recipient = recipientNumber(client_socket);
    QString data = client_socket->readLine();
    if (state == SS_AUTHORIZATION) {
        clients.at(authorizating_player)->client_data = data;
        authorizating_player ^= 1;
        if (authorizating_player == 0) {
            clients[0]->send(clients[1]->client_data);
            clients[1]->send(clients[0]->client_data);
            Sleep(500);
            sendFlags();
            setState(SS_GAME_IN_PROCESS);
            return;
        }
        sendAuthRequest();
    }
    if (state == SS_GAME_IN_PROCESS) {
        int recipient = recipientNumber(client_socket);
        clients.at(recipient)->send(data);
    }
    QStringList kek = data.split(QString(":"));
    qDebug() << kek[0];
    if (data == "zdarova")
        qDebug() << "server: ku!";
}

void Server::sendFlags() {
    clients[0]->send("go:");
    clients[1]->send("wait:");
}

void Server::setState(ServerState new_state) {
    state = new_state;
}

int Server::recipientNumber(QTcpSocket* sender) {
    return (sender == clients[0]->ptr()) ? 0 : 1;
}

void Server::endGame() {
    clients.clear();
    setState(SS_SEARCHING_PLAYERS);
}

void Server::sendAuthRequest() {
    clients[authorizating_player]->send("giveauth:");
}
