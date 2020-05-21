#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QMainWindow>
#include "Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FinalWindow; }
QT_END_NAMESPACE

class FinalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FinalWindow(QWidget *parent = nullptr);
    ~FinalWindow();
    int result;

private:
    Ui::FinalWindow *ui;
};


#endif // FINALWINDOW_H
