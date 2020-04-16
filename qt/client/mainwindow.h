#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include "../../project/include/Player.h"
#include "Images.h"
#include "Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(const MainWindow &other);
    ~MainWindow();

protected:
    void paintEvent( QPaintEvent* );
    void mousePressEvent( QMouseEvent* ev );
    void closeEvent( QCloseEvent* event );

private slots:
    void redraw();
    void showGameResult( GameResult result );
    void changeStateLabel();
    void changePlayer();

private:
    QImage myFieldImage();
    QImage enemyFieldImage();
    QImage getFieldImage( char );
    void setStatus( const QString& status );
    void setPlayer( const QString& player );

private:
    Ui::MainWindow *ui;
    Player *player1;
    Player *player2;
    Controller *controller;

};



#endif // MAINWINDOW_H
