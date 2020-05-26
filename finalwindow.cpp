#include "finalwindow.h"
#include "ui_finalwindow.h"

FinalWindow::FinalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FinalWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd;
    if (result == 1) {
        bkgnd = QPixmap(":/img/images/lose.png");
    } else  {
        bkgnd = QPixmap(":/img/images/win.png");
    }
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void FinalWindow::on_pushButton_clicked() {
    this->close();
    exit(0);
}

FinalWindow::~FinalWindow() { delete ui;}
