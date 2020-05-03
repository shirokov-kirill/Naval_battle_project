#include "Controller.h"

#include <unistd.h>

Controller::Controller()
    : my_player(new Player())
    , enemy_player(new Player())
    , state(ST_PLACING_SHIPS)
    , ships_number(4)
    , client(new QTcpSocket(this)){
    connect(client.get(), SIGNAL(readyRead()), this, SLOT(on_dataRecieved()));
    connect(client.get(), SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_errorRecieved(QAbstractSocket::SocketError)));
}

void Controller::onMousePressed( const QPoint& pos ) {

    if(getState() == State::ST_PLACING_SHIPS)
    {
        QPoint point = getMyFieldCoord(pos);

        if( point.x() == -1 || point.y() == -1 )
            return;

        qDebug() << "Ship at" << point.x() + 1 << point.y() + 1;

        ShipPlacement pos(point.x() + 1, point.y() + 1, orientation::vertical, Ships(ships_number));

        if (myPlayer()->place_ship(pos)) {
            --ships_number;
            qDebug() << "ok :)";
        }

        else
            qDebug() << "not ok :(";

        if (ships_number <= 0)
            setState(ST_WAITING_STEP);

        else emit stateChanged();
        return;
    }

    if (getState() == ST_MAKING_STEP)
    {
        QPoint point = getEnemyFieldCoord(pos);

        if( point.x() == -1 || point.y() == -1 )
            return;

        qDebug() << "Going to" << point.x() << point.y();

        bool marked = enemyPlayer()->is_visible( point.x()+1, point.y()+1,  0);
        if( marked )
            return;

        enemyPlayer()->get_shot(point.x()+1, point.y()+1, 0);

        QString cmd;
        cmd = QString( "step:%1:%2:" ).arg( point.x() ).arg( point.y() );
        qDebug() << cmd;

        setState(ST_WAITING_STEP);
//        emit stateChanged();
        return;
    }
}

State Controller::getState() {
    return state;
}

void Controller::setState(State new_state) {
    state = new_state;
    emit stateChanged();
    emit stateLabelChanged();
}

Player* Controller::myPlayer() {
    return my_player.get();
}

Player* Controller::enemyPlayer() {
    return enemy_player.get();
}

void Controller::connectToServer() {
    client->connectToHost(QHostAddress("127.0.0.1"), 23);
}

void Controller::sendAuthData(const QString &name, const QString &field) {
    QTextStream os(client.get());
    os.setAutoDetectUnicode(true);
    os <<  QString("auth:" + name + ":" + field);
    client->flush();

}

void Controller::parse(const QString &data) {
    QStringList args = data.split(":");
    parseGo(args);
    parseAuth(args);
    parseWait(args);
    parseStep(args);
    parseGiveAuth(args);
}

void Controller::parseGo(const QStringList &args) {
    if (args[0] != QString("go"))
        return;
    setState(ST_MAKING_STEP);
}

void Controller::parseWait(const QStringList &args) {
    if (args[0] != QString("wait"))
        return;
    setState(ST_WAITING_STEP);
}

void Controller::parseAuth(const QStringList &args) {
    if (args[0] != QString("auth"))
        return;
    enemyPlayer()->set_name(args[1].toStdString());
//    enemyPlayer()->setField(args[2].toStdString());

    emit labelOpponentChanged();
//    sendOk();
}

void Controller::parseStep(const QStringList &args) {
    if (args[0] != QString("step"))
        return;
// todo

}

void Controller::parseGiveAuth(const QStringList &args) {
    if (args[0] != QString("giveauth"))
        return;
    sendAuthData(QString::fromStdString(myPlayer()->get_name()), "0101023049304");
}

void Controller::sendOk() {
    QTextStream os(client.get());
    os.setAutoDetectUnicode(true);
    os << "ok";
    client->flush();
}



//slots

void Controller::on_dataRecieved() {
    QString data = client->readLine();
    qDebug() << data;
    parse(data);
// todo
}

void Controller::on_errorRecieved(QAbstractSocket::SocketError err) {
    QString strError =
            "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                         "The host was not found." :
                         err == QAbstractSocket::RemoteHostClosedError ?
                         "The remote host is closed." :
                         err == QAbstractSocket::ConnectionRefusedError ?
                         "The connection was refused." :
                         QString(client->errorString())
                        );
    qDebug() << strError;
}
