#include "Client.h"


Client::Client(QTcpSocket* socket)
    :client(socket) {}

void Client::send(QString data) {
    QTextStream os(client);
    os.setAutoDetectUnicode(true);
    os << data;
}

void Client::sl_dataReceived() {
    emit sig_dataReceived();
}

QTcpSocket* Client::ptr() {
    return client;
}

