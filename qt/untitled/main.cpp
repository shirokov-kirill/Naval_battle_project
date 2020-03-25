#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QProgressBar>
#include <QObject>
#include <QInputDialog>
#include <QDir>
#include "SignalHelper.h"
#include "mainwindow.h"



int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 MainWindow window;
 
 window.show();

 return app.exec();
}
