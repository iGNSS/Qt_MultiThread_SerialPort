#include "bookoridatadialog.h"
#include "ui_bookoridatadialog.h"
#include <QDebug>
#include <qmath.h>
#include <QTime>
BookOriDataDialog::BookOriDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookOriDataDialog)
{
    ui->setupUi(this);
}

BookOriDataDialog::~BookOriDataDialog()
{
    delete ui;
}

void BookOriDataDialog::on_pushButton_4_clicked()
{
    this->close();
}

void BookOriDataDialog::on_pushButton_clicked()
{
    QByteArray Sdata;

    QString latFloatStr = ui->lineEdit->text();
    double latf = latFloatStr.toDouble() * qPow(2,31) / 90.0;
    quint32 latuint32 = qRound64(latf);
    //qint64 i = *((qint64 *)&f);
    QString latfloat_str = QString::number(latuint32,16);
    QString latfloat_hex = latfloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString latdataStr = latfloat_hex.mid(6,2)+" "+latfloat_hex.mid(4,2)+" "+latfloat_hex.mid(2,2)+" "+latfloat_hex.mid(0,2)+" ";
    QString astr = latfloat_hex.mid(6,2);


    int latCheckSumInt = latfloat_hex.mid(6,2).toInt(nullptr,16) + latfloat_hex.mid(4,2).toInt(nullptr,16)+latfloat_hex.mid(2,2).toInt(nullptr,16)+latfloat_hex.mid(0,2).toInt(nullptr,16);


    QString lonFloatStr = ui->lineEdit_2->text();
    double lonf = lonFloatStr.toDouble() * qPow(2,31) / 180.0;
    quint32 lonuint32 = qRound64(lonf);
    //qint64 i = *((qint64 *)&f);
    QString lonfloat_str = QString::number(lonuint32,16);
    QString lonfloat_hex = lonfloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString londataStr = lonfloat_hex.mid(6,2)+" "+lonfloat_hex.mid(4,2)+" "+lonfloat_hex.mid(2,2)+" "+lonfloat_hex.mid(0,2)+" ";
    int lonCheckSumInt = lonfloat_hex.mid(6,2).toInt(nullptr,16) + lonfloat_hex.mid(4,2).toInt(nullptr,16)+lonfloat_hex.mid(2,2).toInt(nullptr,16)+lonfloat_hex.mid(0,2).toInt(nullptr,16);

    int SdataCheckSum = latCheckSumInt +lonCheckSumInt + 1;

    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);

    QString  SdataStr= "EB 90 01 "+latdataStr+londataStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订初始数据：") + tr("纬度=")+ QString::number(latFloatStr.toDouble(),'f',2)+tr(" 经度=")+ QString::number(lonFloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);


    emit OriDataCMD(Sdata);
}


void BookOriDataDialog::on_pushButton_2_clicked()
{
    QByteArray Sdata;

    QString speed0FloatStr = ui->lineEdit_3->text();
    double speed0f = speed0FloatStr.toDouble() * qPow(2,32) / 1000.0;
    quint32 speed0uint32 = qRound64(speed0f);
    //qint64 i = *((qint64 *)&f);
    QString speed0float_str = QString::number(speed0uint32,16);
    QString speed0float_hex = speed0float_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString speed0dataStr = speed0float_hex.mid(6,2)+" "+speed0float_hex.mid(4,2)+" "+speed0float_hex.mid(2,2)+" "+speed0float_hex.mid(0,2)+" ";

    int speed0CheckSumInt = speed0float_hex.mid(6,2).toInt(nullptr,16) + speed0float_hex.mid(4,2).toInt(nullptr,16)+speed0float_hex.mid(2,2).toInt(nullptr,16)+speed0float_hex.mid(0,2).toInt(nullptr,16) +3;

    QString SdataCheckSumHexStr= QString::number(speed0CheckSumInt,16).right(2);

    QString  SdataStr= "EB 90 03 "+speed0dataStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订初始数据：") + tr("初始速度=")+ QString::number(speed0FloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit OriDataCMD(Sdata);
}

void BookOriDataDialog::on_pushButton_3_clicked()
{
    QByteArray Sdata;

    QString hang0FloatStr = ui->lineEdit_3->text();
    double hang0Float = hang0FloatStr.toDouble() * qPow(2,32) / 360.0;
    quint32 hang0Floatuint32 = qRound64(hang0Float);
    //qint64 i = *((qint64 *)&f);
    QString hang0Float_str = QString::number(hang0Floatuint32,16);
    QString hang0Float_hex = hang0Float_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString hang0FloatDisStr = hang0Float_hex.mid(6,2)+" "+hang0Float_hex.mid(4,2)+" "+hang0Float_hex.mid(2,2)+" "+hang0Float_hex.mid(0,2)+" ";

    int speed0CheckSumInt = hang0Float_hex.mid(6,2).toInt(nullptr,16) + hang0Float_hex.mid(4,2).toInt(nullptr,16)+hang0Float_hex.mid(2,2).toInt(nullptr,16)+hang0Float_hex.mid(0,2).toInt(nullptr,16) +2;

    QString SdataCheckSumHexStr= QString::number(speed0CheckSumInt,16).right(2);

    QString  SdataStr= "EB 90 02 "+hang0FloatDisStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订初始数据：") + tr("初始航向=")+ QString::number(hang0FloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit OriDataCMD(Sdata);
}
