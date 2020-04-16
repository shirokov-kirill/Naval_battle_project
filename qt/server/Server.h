#ifndef SERVER_H
#define SERVER_H


#include <QtNetwork>
#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <QRegExp>
#include "Client.h"

enum ServerState {
    SS_SEARCHING_PLAYERS,
    SS_GAME_IN_PROCESS,
    SS_AUTHORIZATION
};

class Server : public QObject {

    Q_OBJECT;

public:
    Server();
    ~Server();
    void start();
    void setState(ServerState new_state);
    int recipientNumber(QTcpSocket* sender); //по отправителю узнает получателя
    void endGame(); //отключает сокеты и меняет состояние сервера
    void sendAuthRequest();
    void sendFlags();

signals:
    void sig_twoPlayersConnected();

private slots:
    void sl_newUser();
    void sl_handleClient(QTcpSocket*);

private:
    QTcpServer *tcp_server;
    bool alive;
    QVector <Client*> clients;
    ServerState state;
    int authorizating_player;
};

#endif // SERVER_H
