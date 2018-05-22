#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    button1 = new QPushButton("LED 1", this);
    button1->setCheckable(true);
    label1 = new QLabel("Off", this);
    label1->move(button1->pos() + QPoint(button1->width() + 5, 0));
    connect(button1, SIGNAL(toggled(bool)), this, SLOT(onbutton1Press(bool)));

    button2 = new QPushButton("LED 2", this);
    button2->setCheckable(true);
    label2 = new QLabel("Off", this);
    button2->move(0, 30);
    label2->move(button2->pos() + QPoint(button2->width() + 5, 0));
    connect(button2, SIGNAL(toggled(bool)), this, SLOT(onbutton2Press(bool)));

    button3 = new QPushButton("LED 3", this);
    button3->setCheckable(true);
    label3 = new QLabel("Off", this);
    button3->move(0, 60);
    label3->move(button3->pos() + QPoint(button3->width() + 5, 0));
    connect(button3, SIGNAL(toggled(bool)), this, SLOT(onbutton3Press(bool)));
}

void MainWindow::onbutton1Press(bool toggled)
{
    qDebug() << toggled;
    if(toggled)
    {
        label1->setText("on");
    }
    else
    {
        label1->setText("off");
    }
}

void MainWindow::onbutton2Press(bool toggled)
{
    qDebug() << toggled;
    if(toggled)
    {
        label2->setText("on");
    }
    else
    {
        label2->setText("off");
    }
}

void MainWindow::onbutton3Press(bool toggled)
{
    qDebug() << toggled;
    if(toggled)
    {
        label3->setText("on");
    }
    else
    {
        label3->setText("off");
    }
}

