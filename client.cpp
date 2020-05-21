#include <QObject>
#include "Client.h"



Client::Client(QTcpSocket* socket)
    : client(socket) {
//    qDebug() << client_data;
    connect(client, SIGNAL(readyRead()), this, SLOT(sl_dataReceived()));
}

Client::~Client() {
    delete client;
}

void Client::send(QString data) {
    QTextStream os(client);
    os.setAutoDetectUnicode(true);
    os << data << "\n";
    client->flush();
}

void Client::sl_dataReceived() {
    emit sig_dataReceived(client);
}

QTcpSocket* Client::ptr() {
    return client;
}
