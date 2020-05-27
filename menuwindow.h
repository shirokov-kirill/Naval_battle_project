#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "Images.h"
#include "Server.h"

#include <botwindow.h>
#include <mainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_startGameButton_clicked();
    void on_startBotButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::MenuWindow *ui;
    MainWindow *game;
    BotWindow *pve_game;
    Server* server;
};
#endif // MENUWINDOW_H
