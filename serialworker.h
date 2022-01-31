#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QObject>
#include <QSerialPort>
#include "qextserialport.h"

struct SnavMessage
{

};

class SerialWorker : public QObject
{
    Q_OBJECT
public:
    //第三方库
    //explicit SerialWorker(QextSerialPort *ser,QObject *parent = nullptr);
    explicit SerialWorker(QSerialPort *ser,QObject *parent = nullptr);
    void mySleep(int sec);
signals:
    void sendResultToGui(QByteArray result);

public slots:
    void doDataSendWork(const QByteArray data);
    void doDataReciveWork();

private:
    //第三方库
    //QextSerialPort *serial;
    //QByteArray buffer;
    QSerialPort *serial;
};

#endif // SERIALWORKER_H
