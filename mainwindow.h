#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QInputDialog>
#include <memory>

#include "project/include/Player.h"
#include "Images.h"
#include "Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Test : public QObject {
    Q_OBJECT
public:
    ~Test() {qDebug() << "Dtor!";}
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setName(QString name);

protected:
    void paintEvent( QPaintEvent* );
    void mousePressEvent( QMouseEvent* ev );
    void closeEvent( QCloseEvent* event );

private slots:
    void redraw();
    void showGameResult( GameResult result );
    void changeStateLabel();
    void on_actionStart_triggered();
    void changeLabelOpponent();
    void on_actionQuit_triggered();

signals:
    void sig_connectToServer();
    void sig_sendAuthData(QString name, QString Field);
    void menu();

private:
    QImage myFieldImage();
    QImage enemyFieldImage();
    QImage getFieldImage( char );
    void setStatus( const QString& status );

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Controller> controller;
    QString name;
};



#endif // MAINWINDOW_H
