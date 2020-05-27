#include "botwindow.h"
#include "ui_botwindow.h"
#include "project/include/Bot.h"

#include <QPainter>
#include <QImage>

#include <windows.h>


BotWindow::BotWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BotWindow)
    , controller(new Controller(true))
{
    ui->setupUi(this);
    pictures.load();

    connect( controller, SIGNAL(stateChanged()), this, SLOT(redraw()) );
    connect( controller, SIGNAL(stateLabelChanged()), this, SLOT(changeStateLabel()) );
    connect( controller, SIGNAL(labelOpponentChanged()), this, SLOT(changeLabelOpponent()));
    connect( controller, SIGNAL(GameResult(GameResult)), this, SLOT(showGameResult(GameResult)));
//    connect(this, SIGNAL(sig_connectToServer()), controller, SLOT(sl_connectToServer()));
//    connect(this, SIGNAL(sig_sendData()), controller, SLOT(sl_sendAuthData()));

}


BotWindow::~BotWindow()
{
    delete controller;
    delete ui;
}

void BotWindow::paintEvent( QPaintEvent* event )
{
    Q_UNUSED( event );

    const int deltaY = this->centralWidget()->y();

    QPainter painter( this );
    painter.drawImage(
        0,
        deltaY,
        pictures.get("field")
    );

    painter.drawImage( MYFIELD_X, MYFIELD_Y + deltaY, myFieldImage() );
    painter.drawImage( ENEMYFIELD_X, ENEMYFIELD_Y + deltaY, enemyFieldImage() );
}

QImage BotWindow::myFieldImage()
{
    return getFieldImage( 0 );
}

QImage BotWindow::enemyFieldImage()
{
    return getFieldImage( 1 );
}

QImage BotWindow::getFieldImage( char fld )
{
    QImage image( FIELD_WIDTH, FIELD_HEIGHT, QImage::Format_ARGB32 );
    Ships cell;
    image.fill( 0 );
    QPainter painter( &image );

    double cfx = 1.0 * FIELD_WIDTH / 10.0;
    double cfy = 1.0 * FIELD_HEIGHT / 10.0;

    for( int i = 0; i < 10; i++ )
        for( int j = 0; j < 10; j++ )
        {
            int i1 = i+1, j1 = j+1;

            if (fld == 0) {
                  cell = controller->myPlayer()->get_cell( i1, j1 );
            }
            else {
                  cell = Ships::water;
                  if (controller->enemyPlayer()->is_visible(i1, j1, 0) ||
                          controller->enemyPlayer()->get_cell(i1, j1) == Ships::fire ||
                          controller->enemyPlayer()->get_cell(i1, j1) == Ships::drownen_ship)
                      cell = controller->enemyPlayer()->get_cell(i1, j1);
            }

            if (cell == Ships::water) {
                if (fld == 0)
                    if (controller->myPlayer()->is_visible(i1, j1, 1))
                        painter.drawImage( i * cfx, j * cfy, pictures.get("dot") );
                    else {}
                else
                    if (controller->enemyPlayer()->is_visible(i1, j1, 0))
                        painter.drawImage( i * cfx, j * cfy, pictures.get("dot") );
            }

            else if (cell == Ships::fire) {
                if (fld == 0)
                    painter.drawImage( i * cfx, j * cfy, pictures.get("redhalf") );
                else
                    painter.drawImage( i * cfx, j * cfy, pictures.get("redhalf") );
            }
            else if (cell == Ships::drownen_ship) {
                    painter.drawImage( i * cfx, j * cfy, pictures.get("redfull") );
            }
            else {
                painter.drawImage( i * cfx, j * cfy, pictures.get("full") );
            }
        }

    return image;
}

void BotWindow::mousePressEvent( QMouseEvent* ev ) {
    QPoint pos = ev->pos();
    orientation ori = orientation::vertical;
    if (ev->button() == Qt::RightButton) ori = orientation::horizontal;
    pos.setY( pos.y() - this->centralWidget()->y() );
    int res = controller->onMousePressed( pos, ori );
    if (res != 0) {
        finwin = new FinalWindow(res);
        finwin->show();
        this->close();
    }
}

void BotWindow::closeEvent( QCloseEvent* event )
{
//    controller->onGameQuit();
    event->accept();
}

void BotWindow::redraw()
{
    if( controller->getState() == ST_PLACING_SHIPS )
        ui->labelOpponent->clear();

    if( controller->getState() == ST_PLACING_SHIPS )
    {
        ui->actionStart->setDisabled(false);
        ui->actionLeave->setDisabled(true);
        ui->menuField->setDisabled(false);
    }
    else
    {
        ui->actionStart->setDisabled(true);
        ui->actionLeave->setDisabled(false);
        ui->menuField->setDisabled(true);
    }
    qDebug() << "updating!";

    this->update();
}

void BotWindow::showGameResult( GameResult result )
{
    /*
    int res = result == GR_WON ? 1 : 0;
    finwin = new FinalWindow;
    finwin->result = res;
    finwin->show();
    this->close();
    qDebug() << "ending!";
*/
    if( result == GR_NONE ) return;
    qDebug() << "ending!";
    QString messageString = result == GR_WON
        ? tr( "You win!" )
        : tr( "You lose!" );

    this->update();
    QMessageBox::information( this, tr("Game result"), messageString );

}

void BotWindow::setStatus( const QString& status )
{
    ui->labelStatus->setText( tr("Status: ") + status );
}

void BotWindow::changeStateLabel() {
    if (controller->getState() == ST_PLACING_SHIPS)
        setStatus("placing ships");
    if (controller->getState() == ST_WAITING_STEP)
        setStatus("waiting step");
    if (controller->getState() == ST_MAKING_STEP)
        setStatus("making step");
}

void BotWindow::setName(QString new_name) {
    name = new_name;
}

void BotWindow::changeLabelOpponent() {
    ui->labelOpponent->setText(QString::fromStdString(controller->enemyPlayer()->get_name()));
}

void BotWindow::on_actionStart_triggered() {
    bool ok;
    QString name = QInputDialog::getText(this, tr("Ввод"),
                            tr("Ваше имя:"), QLineEdit::Normal,
                            "Player", &ok);
    if (!ok || controller->getState() == ST_PLACING_SHIPS) {
        qDebug() << "Nope";
        return;
    }
    controller->myPlayer()->set_name(name.toStdString());
    controller->connectToServer();
//    controller->sendAuthData(name, "010101010");
}


void BotWindow::on_actionQuit_triggered()
{
    this->close();
    // here shoul be some more logic
    emit back_menu();
}

