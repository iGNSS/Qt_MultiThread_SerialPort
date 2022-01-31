#include "serialworker.h"
#include <QDebug>
#include <QThread>
#include <QTime>
#include <QApplication>


//第三方库
//SerialWorker::SerialWorker(QextSerialPort *ser,QObject *parent)
//    : QObject(parent),serial(ser)
//{

//}

SerialWorker::SerialWorker(QSerialPort *ser,QObject *parent)
: QObject(parent),serial(ser)
{
}


void SerialWorker::doDataSendWork(const QByteArray data)
{
    //qDebug() <<  "子线程槽函数发送数据：" << data << "线程ID：" << QThread::currentThreadId();

    // 发送数据
    serial->write(data);


}
//#ifdef SERIALPORT
//void SerialWorker::doDataSendWork(const QByteArray data)
//{
//        // 发送数据

//    serial->write(data);
//}
//#endif
//}
void SerialWorker::mySleep(int sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
void SerialWorker::doDataReciveWork()
{

    if(serial !=NULL)
    {
        if(serial->bytesAvailable()>0)
        {
            QByteArray buffertemp = serial->readAll();
            buffertemp = buffertemp.toHex();
            emit sendResultToGui(buffertemp);
        }
        else if(serial->bytesAvailable()==0)
        {
            qDebug()<<"Serial port do not open";
        }
        else if(serial->bytesAvailable()<0)
        {
            qDebug()<<"Serial port error";
        }
    }
}
