#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_serial(new QSerialPort(this))
{
    button1 = new QPushButton("LED 1",this);
    button1->setCheckable(true);
    label1 = new QLabel("Off",this);
    label1->move(button1->pos()+QPoint(button1->width()+5,0));
    connect(button1,&QPushButton::toggled,this,&MainWindow::onbutton1Press);
    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    openSerialPort();
}

void MainWindow::onbutton1Press(bool toggled)
{
    if(toggled) {
        label1->setText("on");
        writeData("0 0 0\r");
    }
    else {
        label1->setText("off");
        writeData("255 255 255\r");
    }
}

void MainWindow::writeData(const char* data)
{
    m_serial->write(data);
}

void MainWindow::readData()
{
    const QByteArray data = m_serial->readAll();
    qDebug() << data;
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::openSerialPort()
{
    m_serial->setPortName("tty.usbmodem1411");
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Opened";
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());
    }
}

void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    qDebug() << "Closed";
}
