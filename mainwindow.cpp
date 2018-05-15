#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    button1 = new QPushButton("Click Me",this);
    label1 = new QLabel("Label 1",this);
    label1->move(button1->pos()+QPoint(button1->width()+5,0));
}

