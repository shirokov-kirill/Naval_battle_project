#include "Controller.h"
#include "project/include/Bot.h"

#include <unistd.h>
#include <vector>

std::vector<Ships> ships = {Ships::carrier, Ships::regular, Ships::regular, Ships::middle, Ships::middle, Ships::middle, Ships::small, Ships::small, Ships::small, Ships::small};

Controller::Controller()
    : my_player(new Player())
    , enemy_player(new Player())
    , state(ST_PLACING_SHIPS)
    , client(new QTcpSocket(this))
    , ships_number(0){
    connect(client.get(), SIGNAL(readyRead()), this, SLOT(on_dataRecieved()));
    connect(client.get(), SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_errorRecieved(QAbstractSocket::SocketError)));
}

Controller::Controller(bool need_bot)
    : my_player(new Player())
    , enemy_player( need_bot ? new Bot : new Player())
    , state(ST_PLACING_SHIPS)
    , client(new QTcpSocket(this))
    , ships_number(0){
    connect(client.get(), SIGNAL(readyRead()), this, SLOT(on_dataRecieved()));
    connect(client.get(), SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_errorRecieved(QAbstractSocket::SocketError)));
}

void Controller::onMousePressed( const QPoint& pos, orientation ori ) {
    if(getState() == State::ST_PLACING_SHIPS) {
        QPoint point = getMyFieldCoord(pos);

        if( point.x() == -1 || point.y() == -1 ) return;

        qDebug() << "Ship at" << point.x() + 1 << point.y() + 1;

        ShipPlacement pos(point.x() + 1, point.y() + 1, ori, ships.at(ships_number));

        if (myPlayer()->can_place_ship(pos)) {
            myPlayer()->place_ship(pos);
            ships_number++;
            qDebug() << "ok :)";
        } else qDebug() << "not ok :(";

        if (ships_number == 10) {
            setState(ST_WAITING_STEP);
            qDebug() << "all ships placed";
            if (enemyPlayer()->is_bot()) {
                dynamic_cast<Bot*>(enemyPlayer())->make_placement();
                setState(ST_MAKING_STEP);
            }
        } else emit stateChanged();
        return;
    }

    if (getState() == ST_MAKING_STEP) {
        QPoint point = getEnemyFieldCoord(pos);

        if( point.x() == -1 || point.y() == -1 ) return;

        qDebug() << "Going to" << point.x() + 1 << point.y() + 1;

        bool marked = enemyPlayer()->is_visible( point.x()+1, point.y()+1,  0);
        if( marked ) return;

        QString cmd;
        cmd = QString( "step:%1:%2:" ).arg( point.x() + 1 ).arg( point.y() + 1 );
        qDebug() << cmd;

        if (enemyPlayer()->get_cell(point.x()+1, point.y()+1) == Ships::water) {
            setState(ST_WAITING_STEP);
        }

        enemyPlayer()->get_shot(point.x()+1, point.y()+1, 0);
        qDebug() << "cell fired: " << point.x()+1 << ' ' <<  point.y()+1;
        qDebug() << "cell state now: " << (int)(enemyPlayer()->get_cell(point.x()+1,  point.y()+1));
        if (enemyPlayer()->get_cell(point.x()+1,  point.y()+1) == Ships::fire || enemyPlayer()->get_cell(point.x()+1,  point.y()+1) == Ships::drownen_ship) setState(State::ST_MAKING_STEP);
        else setState(State::ST_WAITING_STEP);

        if (!enemyPlayer()->is_alive()) {
/*            finwin = new FinalWindow;
            finwin->result = 1;
            finwin->show();
            this->close();

            qDebug() << "game ended";
            */
            return;
        }

        if (state == State::ST_WAITING_STEP && enemyPlayer()->is_bot()) {
            qDebug() << "bot turn ------------";
            std::pair<int, int> bot_step = dynamic_cast<Bot*>(enemyPlayer())->make_fight_step(myPlayer());
            myPlayer()->get_shot(bot_step.first, bot_step.second, 1);
            qDebug() << "i got shot to: " << bot_step.first << ' ' <<  bot_step.second;
            qDebug() << "cell state now: " << (int)(myPlayer()->get_cell(bot_step.first,  bot_step.second));
            while (myPlayer()->get_cell(bot_step.first, bot_step.second) == Ships::fire || myPlayer()->get_cell(bot_step.first, bot_step.second) == Ships::drownen_ship) {
                bot_step = dynamic_cast<Bot*>(enemyPlayer())->make_fight_step(myPlayer());
                myPlayer()->get_shot(bot_step.first, bot_step.second, 1);
                qDebug() << "i got shot to: " << bot_step.first << ' ' <<  bot_step.second;
                qDebug() << "cell state now: " << (int)(myPlayer()->get_cell(bot_step.first,  bot_step.second));
                if (!myPlayer()->is_alive()) {
  /*                  finwin = new FinalWindow;
                    finwin->result = -1;
                    finwin->show();
                    this->close();
*/
                    qDebug() << "game ended";
                    return;
                }
            }
            setState(ST_MAKING_STEP);
        }
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

