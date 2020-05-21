#ifndef CLIENT_H
#define CLIENT_H
#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>

class Client : public QObject {
    Q_OBJECT
public:
    Client(QTcpSocket* socket);
    ~Client();
    void send(QString data);
    QTcpSocket* ptr();
    void close();
public:
    QString client_data;
signals:
    void sig_dataReceived(QTcpSocket *client);
private slots:
    void sl_dataReceived();
private:
    QTcpSocket *client;
};


#endif // CLIENT_H
