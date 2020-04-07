#include "Controller.h"
#include <unistd.h>

Controller::Controller( Player *player1, Player *player2 )
    : player1(player1)
    , player2(player2)
    , cur_player(0) {player[0] = player1, player[1] = player2;}

void Controller::onMousePressed( const QPoint& pos, bool )
{
//    Player* player[2];
//    player[0] = player1;
//    player[1] = player2;

    if( player[cur_player]->getState() == State::ST_PLACING_SHIPS )
    {
        QPoint point = getMyFieldCoord( pos );

        if( point.x() == -1 || point.y() == -1 )
            return;

        qDebug() << "Ship at" << point.x() + 1<< point.y() + 1;

        ShipPlacement pos;
        pos.x = point.x() + 1, pos.y = point.y() + 1;
        pos.orient = orientation::vertical;
        pos.type = Ships(player[cur_player]->get_cur_ship());

        if (player[cur_player]->place_ship(pos)) {
            player[cur_player]->inc_ship();
        }
        else {
            qDebug() << "HUI TEBE";
        }

        if (player[cur_player]->get_cur_ship() > 4) {
            emit playerChanged();
            cur_player ^= 1;
        }

        if (cur_player == 0 && player[cur_player]->get_cur_ship() > 4) {
            player[cur_player]->setState(State::ST_MAKING_STEP);
            player[cur_player ^ 1]->setState(State::ST_WAITING_STEP);
            emit stateLabelChanged();

        }



        emit stateChanged();
        return;
    }

    if( player[cur_player]->getState() == ST_MAKING_STEP )
    {
        QPoint point = getEnemyFieldCoord( pos );

        if( point.x() == -1 || point.y() == -1 )
            return;

        qDebug() << "Going to" << point.x() << point.y();
        bool cell = player[cur_player ^ 1]->is_visible( point.x()+1, point.y()+1,  cur_player);

        if( cell )
            return;

        player[cur_player ^ 1]->get_shot(point.x()+1, point.y()+1, cur_player);

        QString cmd;
        cmd = QString( "step:%1:%2:" ).arg( point.x() ).arg( point.y() );
        qDebug() << cmd;

        player[cur_player]->setState(State::ST_WAITING_STEP);
        player[cur_player^1]->setState(State::ST_MAKING_STEP);

        emit playerChanged();
        cur_player ^= 1;


        emit stateChanged();
        return;
    }
}

int  Controller::getCurPlayer() {
    return cur_player;
}
