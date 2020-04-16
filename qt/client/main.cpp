#include <QApplication>
#include "mainwindow.h"



int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 MainWindow window;
 size_t kek = 0;
 kek--;
 qDebug() << kek;


 
 window.show();



 return app.exec();
}
