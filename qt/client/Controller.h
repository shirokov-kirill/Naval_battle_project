#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPoint>
#include <QRegExp>
#include <QMessageBox>
#include <QFile>
#include <QRegExp>

#include <QtNetwork>
#include <QTcpSocket>

#include "../../project/include/Player.h"
#include "Utility.h"

enum GameResult
{
    GR_NONE = 0,
    GR_WON = 1,
    GR_LOST = -1
};

enum State
{
    ST_PLACING_SHIPS,
    ST_WAITING_STEP,
    ST_MAKING_STEP
};

class Controller: public QWidget
{
    Q_OBJECT
public:
    Controller();
//    ~Controller();
    void onMousePressed( const QPoint& pos );
    Player* myPlayer();
    Player* enemyPlayer();
    State getState();
    void setState(State new_state);
public:
    void parse(const QString &data);
    void parseGo(const QStringList &args);
    void parseAuth(const QStringList &args);
    void parseWait(const QStringList &args);
    void parseStep(const QStringList &args);
    void parseGiveAuth(const QStringList &args);


signals:
    void stateChanged();
    void gameResult( GameResult result );
    void gameOpponent( const QString& name );
    void stateLabelChanged();
    void playerChanged();
    void labelOpponentChanged();

public:
    void connectToServer();
    void sendAuthData(const QString &name, const QString &field);
    void sendOk();

private slots:
    void on_dataRecieved();
    void on_errorRecieved(QAbstractSocket::SocketError);

private:
    std::unique_ptr<Player> my_player;
    std::unique_ptr<Player> enemy_player;

    State state;
    std::unique_ptr<QTcpSocket> client;
    QQueue <QString> cmds;
    int ships_number;
};

#endif // CONTROLLER_H
