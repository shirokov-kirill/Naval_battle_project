#ifndef SERVER_H
#define SERVER_H


#include <QtNetwork>
#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QDebug>
#include "Client.h"

enum ServerState {
    SS_SEARCING_PLAYERS,
    SS_GAME_IN_PROCESS
};

class Server : public QObject {

    Q_OBJECT;

public:
    Server();
    void start();
    void changeState();
    int recipientNumber(QTcpSocket* sender); //по отправителю узнает получателя
    void endGame(); //отключает сокеты и меняет состояние сервера

signals:
    void sig_twoPlayersConnected();

private slots:
    void sl_newUser();
    void sl_handleClient();
    void sl_sendBeginRequest();

private:
    QTcpServer *tcp_server;
    bool alive;
    QVector <Client*> clients;
    ServerState state;
};

#endif // SERVER_H
