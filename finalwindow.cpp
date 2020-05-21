#include "finalwindow.h"
#include "ui_finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);
    if (result == 1) {
        QPixmap bkgnd(":/img/images/won.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    } else {
        QPixmap bkgnd(":/img/images/lose.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
}

FinalWindow::~FinalWindow()
{
    delete ui;
}
