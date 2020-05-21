#include "menuwindow.h"
#include "ui_menuwindow.h"

#include <QPainter>
#include <QImage>

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    pictures.load();

/*
    game = new MainWindow();
    connect(game, &MainWindow::menu, this, &MenuWindow::show);
*/
    QPixmap bkgnd(":/img/images/zastavka.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

MenuWindow::~MenuWindow()
{
    delete ui;
    delete server;
}

void MenuWindow::on_startGameButton_clicked()
{
    int ret = QMessageBox::warning(this, tr("Choice"),
                                   tr("To start new server press Ok.\n"
                                      "To connect to existing press Discard"),
                                   QMessageBox::Ok | QMessageBox::Discard
                                   | QMessageBox::Cancel,
                                   QMessageBox::Ok);
    switch (ret) {
        case QMessageBox::Ok:
        {
            server = new Server();
            server->start();
            game = new MainWindow();
            connect(game, &MainWindow::menu, this, &MenuWindow::show);
            game->show();
            this->close();
        }
        case QMessageBox::Cancel:
            return;
        case QMessageBox::Discard:
        {
            game = new MainWindow();
            connect(game, &MainWindow::menu, this, &MenuWindow::show);
            game->show();
            this->close();
        }
    }
}

void MenuWindow::on_startBotButton_clicked()
{
    pve_game = new BotWindow();
    connect(pve_game, &BotWindow::back_menu, this, &MenuWindow::show);
    pve_game->show();
    this->close();
}

void MenuWindow::on_exitButton_clicked()
{
    this->close();
}
