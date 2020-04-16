#include "Controller.h"
#include <unistd.h>

Controller::Controller()
    : my_player(new Player())
    , enemy_player(new Player())
    , state(ST_PLACING_SHIPS)
    , ships_number(4) {}

void Controller::onMousePressed( const QPoint& pos ) {

    if(getState() == State::ST_PLACING_SHIPS)
    {
        QPoint point = getMyFieldCoord(pos);

        if( point.x() == -1 || point.y() == -1 )
            return;

        qDebug() << "Ship at" << point.x() + 1 << point.y() + 1;

        ShipPlacement pos;
        pos.x = point.x() + 1, pos.y = point.y() + 1;
        pos.orient = orientation::vertical;
        pos.type = Ships(ships_number);

        if (myPlayer()->place_ship(pos)) {
            --ships_number;
            qDebug() << "ok :)";
        }

        else
            qDebug() << "not ok :(";

        if (ships_number <= 0)
            setState(ST_WAITING_STEP);

        emit stateChanged();
        return;
    }

    if(getState() == ST_MAKING_STEP)
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
        emit stateChanged();
        return;
    }
}

State Controller::getState() {
    return state;
}

void Controller::setState(State new_state) {
    state = new_state;
    emit stateLabelChanged();
}

Player* Controller::myPlayer() {
    return my_player;
}

Player* Controller::enemyPlayer() {
    return enemy_player;
}

