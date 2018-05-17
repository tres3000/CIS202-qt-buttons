#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QSerialPort>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void openSerialPort();
    void closeSerialPort();
    void handleError(QSerialPort::SerialPortError error);
    void readData();

public slots:
    void onbutton1Press(bool toggled);


private:
    QPushButton *button1;
    QLabel *label1;
    QSerialPort *m_serial = nullptr;

    void writeData(const char *data);
};

#endif // MAINWINDOW_H
