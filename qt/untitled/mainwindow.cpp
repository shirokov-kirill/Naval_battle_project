#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QDir>
#include <QLineEdit>
#include <QInputDialog>

#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_counter(0)
{
    ui->setupUi(this);
    setFixedSize(800, 600);
    bool ok;
    QString name1 = QString("Player 1"), name2 = QString("PLayer2");
     name1 = QInputDialog::getText(this, tr("Первый игрок"),
                                         tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);

     name2 = QInputDialog::getText(this, tr("Второй игрок"),
                                         tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);

}


MainWindow::~MainWindow()
{
    delete ui;
}

