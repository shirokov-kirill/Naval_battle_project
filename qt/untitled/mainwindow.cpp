#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "ui_mainwindow_2.h"
#include <QPainter>
#include <QImage>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1(new Player())
    , player2(new Player())
    , controller(new Controller(player1, player2))
{
    ui->setupUi(this);
    pictures.load();

    connect( controller, SIGNAL(stateChanged()), this, SLOT(redraw()) );
    connect( controller, SIGNAL(stateLabelChanged()), this, SLOT(changeStateLabel()) );
    connect( controller, SIGNAL(playerChanged()), this, SLOT(changePlayer()) );

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent( QPaintEvent* event )
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

QImage MainWindow::myFieldImage()
{
    return getFieldImage( 0 );
}

QImage MainWindow::enemyFieldImage()
{
    return getFieldImage( 1 );
}

QImage MainWindow::getFieldImage( char fld )
{
    QImage image( FIELD_WIDTH, FIELD_HEIGHT, QImage::Format_ARGB32 );
    Ships cell;
    image.fill( 0 );
    int cur_player = controller->getCurPlayer();
    int other_player = cur_player ^ 1;
    Player* player[2];
    player[0] = player1, player[1] = player2;
    QPainter painter( &image );

    double cfx = 1.0 * FIELD_WIDTH / 10.0;
    double cfy = 1.0 * FIELD_HEIGHT / 10.0;

    for( int i = 0; i < 10; i++ )
        for( int j = 0; j < 10; j++ )
        {
            int i1 = i+1, j1 = j+1;

//            if (cur_player == 0) {
//                if (fld == 0) {
//                    cell = player1->get_cell( i1, j1 );
//                }
//                else {
//                    cell = Ships::water;
//                    if (player2->is_visible(i1, j1, 0)) cell = player2->get_cell(i1, j1);
//                }
//            }

//            else {
//                if (fld == 0) cell = player2->get_cell(i1, j1);
//                else {
//                    cell = Ships::water;
//                    if (player1->is_visible(i1, j1, 1)) cell = player1->get_cell(i1, j1);
//                }
//            }
            if (fld == 0) {
                  cell = player[cur_player]->get_cell( i1, j1 );
            }
            else {
                  cell = Ships::water;
                  if (player[other_player]->is_visible(i1, j1, cur_player)) cell = player[other_player]->get_cell(i1, j1);
            }

            if (cell == Ships::water) {
                if (fld == 0)
                    if (player[cur_player]->is_visible(i1, j1, other_player))
                        painter.drawImage( i * cfx, j * cfy, pictures.get("dot") );
                    else {}
                else
                    if (player[other_player]->is_visible(i1, j1, cur_player))
                        painter.drawImage( i * cfx, j * cfy, pictures.get("dot") );
            }

            else if (cell == Ships::fire) {
                if (fld == 0)
                    painter.drawImage( i * cfx, j * cfy, pictures.get("redhalf") );
                else
                    painter.drawImage( i * cfx, j * cfy, pictures.get("half") );
            }
            else {
                painter.drawImage( i * cfx, j * cfy, pictures.get("full") );
            }
        }

    return image;
}

void MainWindow::mousePressEvent( QMouseEvent* ev )
{
    QPoint pos = ev->pos();
    pos.setY( pos.y() - this->centralWidget()->y() );
    controller->onMousePressed( pos, ev->button() == Qt::LeftButton );
}

void MainWindow::closeEvent( QCloseEvent* event )
{
//    controller->onGameQuit();
    event->accept();
}

void MainWindow::redraw()
{
//    if( controller->getState() == ST_PLACING_SHIPS )
//        ui->labelOpponent->clear();

//    if( controller->getState() == ST_PLACING_SHIPS )
//    {
//        ui->actionStart->setDisabled(false);
//        ui->actionLeave->setDisabled(true);
//        ui->menuField->setDisabled(false);
//    }
//    else
//    {
//        ui->actionStart->setDisabled(true);
//        ui->actionLeave->setDisabled(false);
//        ui->menuField->setDisabled(true);
//    }

    this->update();
}

void MainWindow::showGameResult( GameResult result )
{
    if( result == GR_NONE )
        return;

    QString messageString = result == GR_WON
        ? tr( "You win!" )
        : tr( "You lose!" );

    this->update();
    QMessageBox::information( this, tr("Game result"), messageString );
}

void MainWindow::setStatus( const QString& status )
{
    ui->labelStatus->setText( tr("Status: ") + status );
}

void MainWindow::changeStateLabel() {
    setStatus("making step");
}

MainWindow::MainWindow(const MainWindow &other)
    :ui(other.ui)
    , player1(other.player1)
    , player2(other.player2)
    , controller(other.controller) {}

void MainWindow::setPlayer( const QString& player ) {
    ui->labelPlayer->setText(player);
}

void MainWindow::changePlayer() {
    if (controller->getCurPlayer() == 0) {
        setPlayer("player2");
    }
    else setPlayer("player1");
}




