#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPoint>
#include <QRegExp>
#include <QMessageBox>
#include <QFile>
#include <QRegExp>
#include "../../project/include/Player.h"
#include "Utility.h"

enum GameResult
{
    GR_NONE = 0,
    GR_WON = 1,
    GR_LOST = -1
};

//enum State
//{
//    ST_PLACING_SHIPS,
//    ST_WAITING_STEP,
//    ST_MAKING_STEP
//};

class Controller: public QWidget
{
    Q_OBJECT
public:
    Controller( Player *player1, Player *player2 );
//    ~Controller();
    void onMousePressed( const QPoint& position, bool setShip = true );
    int  getCurPlayer();


signals:
    void stateChanged();
    void gameResult( GameResult result );
    void gameOpponent( const QString& name );
    void stateLabelChanged();
    void playerChanged();

private:



private:
    Player *player1;
    Player *player2;
    int cur_player;
    Player* player[2];
};

#endif // CONTROLLER_H
