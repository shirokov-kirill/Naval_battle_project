#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>

class Client : public QObject {
    Q_OBJECT
public:
    Client(QTcpSocket* socket);
    void send(QString data);
    QTcpSocket* ptr();
    void close();
signals:
    void sig_dataReceived();
private slots:
    void sl_dataReceived();
private:
    QTcpSocket *client;
};


#endif // CLIENT_H
