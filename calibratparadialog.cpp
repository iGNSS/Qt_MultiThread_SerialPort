#include "calibratparadialog.h"
#include "ui_calibratparadialog.h"
#include "common.h"
#include <QTime>

CalibratParaDialog::CalibratParaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalibratParaDialog)
{
    ui->setupUi(this);
}

CalibratParaDialog::~CalibratParaDialog()
{
    delete ui;
}

void CalibratParaDialog::on_pushButton_clicked()
{
    QByteArray Sdata;

    QString XGyroScaleFloatStr = ui->lineEdit->text();
    double XGyroScalef = XGyroScaleFloatStr.toDouble() * qPow(10,8);
    quint32 XGyroScaleuint32 = qRound64(XGyroScalef);
    QString XGyroScalefloat_str = QString::number(XGyroScaleuint32,16);
    QString XGyroScalefloat_hex = XGyroScalefloat_str.rightJustified(8,QLatin1Char('0'));
    QString XGyroScaledataStr = XGyroScalefloat_hex.mid(6,2)+" "+XGyroScalefloat_hex.mid(4,2)+" "+XGyroScalefloat_hex.mid(2,2)+" "+XGyroScalefloat_hex.mid(0,2)+" ";
    QString astr = XGyroScalefloat_hex.mid(6,2);
    int XGyroScaleCheckSumInt = XGyroScalefloat_hex.mid(6,2).toInt(nullptr,16) + XGyroScalefloat_hex.mid(4,2).toInt(nullptr,16)+XGyroScalefloat_hex.mid(2,2).toInt(nullptr,16)+XGyroScalefloat_hex.mid(0,2).toInt(nullptr,16);


    QString YGyroScaleFloatStr = ui->lineEdit_2->text();
    double YGyroScalef = YGyroScaleFloatStr.toDouble() * qPow(10,8);
    quint32 YGyroScaleuint32 = qRound64(YGyroScalef);
    QString YGyroScalefloat_str = QString::number(YGyroScaleuint32,16);
    QString YGyroScalefloat_hex = YGyroScalefloat_str.rightJustified(8,QLatin1Char('0'));
    QString YGyroScaledataStr = YGyroScalefloat_hex.mid(6,2)+" "+YGyroScalefloat_hex.mid(4,2)+" "+YGyroScalefloat_hex.mid(2,2)+" "+YGyroScalefloat_hex.mid(0,2)+" ";
    int YGyroScaleCheckSumInt = YGyroScalefloat_hex.mid(6,2).toInt(nullptr,16) + YGyroScalefloat_hex.mid(4,2).toInt(nullptr,16)+YGyroScalefloat_hex.mid(2,2).toInt(nullptr,16)+YGyroScalefloat_hex.mid(0,2).toInt(nullptr,16);

    QString ZGyroScaleFloatStr = ui->lineEdit_3->text();
    double ZGyroScalef = ZGyroScaleFloatStr.toDouble() * qPow(10,8);
    quint32 ZGyroScaleuint32 = qRound64(ZGyroScalef);
    QString ZGyroScalefloat_str = QString::number(ZGyroScaleuint32,16);
    QString ZGyroScalefloat_hex = ZGyroScalefloat_str.rightJustified(8,QLatin1Char('0'));
    QString ZGyroScaledataStr = ZGyroScalefloat_hex.mid(6,2)+" "+ZGyroScalefloat_hex.mid(4,2)+" "+ZGyroScalefloat_hex.mid(2,2)+" "+ZGyroScalefloat_hex.mid(0,2)+" ";
    int ZGyroScaleCheckSumInt = ZGyroScalefloat_hex.mid(6,2).toInt(nullptr,16) + ZGyroScalefloat_hex.mid(4,2).toInt(nullptr,16)+ZGyroScalefloat_hex.mid(2,2).toInt(nullptr,16)+ZGyroScalefloat_hex.mid(0,2).toInt(nullptr,16);

    QString XZeroBiasFloatStr = ui->lineEdit_10->text();
    double XZeroBiasf = XZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 XZeroBiasuint32 = qRound64(XZeroBiasf);
    QString XZeroBiasfloat_str = QString::number(XZeroBiasuint32,16);
    QString XZeroBiasfloat_hex = XZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString XZeroBiasdataStr = XZeroBiasfloat_hex.mid(6,2)+" "+XZeroBiasfloat_hex.mid(4,2)+" "+XZeroBiasfloat_hex.mid(2,2)+" "+XZeroBiasfloat_hex.mid(0,2)+" ";
    int XZeroBiasCheckSumInt = XZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + XZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+XZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+XZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    QString YZeroBiasFloatStr = ui->lineEdit_11->text();
    double YZeroBiasf = YZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 YZeroBiasuint32 = qRound64(YZeroBiasf);
    QString YZeroBiasfloat_str = QString::number(YZeroBiasuint32,16);
    QString YZeroBiasfloat_hex = YZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString YZeroBiasdataStr = YZeroBiasfloat_hex.mid(6,2)+" "+YZeroBiasfloat_hex.mid(4,2)+" "+YZeroBiasfloat_hex.mid(2,2)+" "+YZeroBiasfloat_hex.mid(0,2)+" ";
    int YZeroBiasCheckSumInt = YZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + YZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+YZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+YZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    QString ZZeroBiasFloatStr = ui->lineEdit_12->text();
    double ZZeroBiasf = ZZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 ZZeroBiasuint32 = qRound64(ZZeroBiasf);
    QString ZZeroBiasfloat_str = QString::number(ZZeroBiasuint32,16);
    QString ZZeroBiasfloat_hex = ZZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString ZZeroBiasdataStr = ZZeroBiasfloat_hex.mid(6,2)+" "+ZZeroBiasfloat_hex.mid(4,2)+" "+ZZeroBiasfloat_hex.mid(2,2)+" "+ZZeroBiasfloat_hex.mid(0,2)+" ";
    int ZZeroBiasCheckSumInt = ZZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + ZZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+ZZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+ZZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    QString XGyroInstalErrorFloatStr = ui->lineEdit_4->text();
    double XGyroInstalErrorf = XGyroInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 XGyroInstalErroruint32 = qRound64(XGyroInstalErrorf);
    QString XGyroInstalErrorfloat_str = QString::number(XGyroInstalErroruint32,16);
    QString XGyroInstalErrorfloat_hex = XGyroInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString XGyroInstalErrordataStr = XGyroInstalErrorfloat_hex.mid(6,2)+" "+XGyroInstalErrorfloat_hex.mid(4,2)+" "+XGyroInstalErrorfloat_hex.mid(2,2)+" "+XGyroInstalErrorfloat_hex.mid(0,2)+" ";
    int XGyroInstalErrorCheckSumInt = XGyroInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + XGyroInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+XGyroInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+XGyroInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString YGyroInstalErrorFloatStr = ui->lineEdit_5->text();
    double YGyroInstalErrorf = YGyroInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 YGyroInstalErroruint32 = qRound64(YGyroInstalErrorf);
    QString YGyroInstalErrorfloat_str = QString::number(YGyroInstalErroruint32,16);
    QString YGyroInstalErrorfloat_hex = YGyroInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString YGyroInstalErrordataStr = YGyroInstalErrorfloat_hex.mid(6,2)+" "+YGyroInstalErrorfloat_hex.mid(4,2)+" "+YGyroInstalErrorfloat_hex.mid(2,2)+" "+YGyroInstalErrorfloat_hex.mid(0,2)+" ";
    int YGyroInstalErrorCheckSumInt = YGyroInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + YGyroInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+YGyroInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+YGyroInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString ZGyroInstalErrorFloatStr = ui->lineEdit_6->text();
    double ZGyroInstalErrorf = ZGyroInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 ZGyroInstalErroruint32 = qRound64(ZGyroInstalErrorf);
    QString ZGyroInstalErrorfloat_str = QString::number(ZGyroInstalErroruint32,16);
    QString ZGyroInstalErrorfloat_hex = ZGyroInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString ZGyroInstalErrordataStr = ZGyroInstalErrorfloat_hex.mid(6,2)+" "+ZGyroInstalErrorfloat_hex.mid(4,2)+" "+ZGyroInstalErrorfloat_hex.mid(2,2)+" "+ZGyroInstalErrorfloat_hex.mid(0,2)+" ";
    int ZGyroInstalErrorCheckSumInt = ZGyroInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + ZGyroInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+ZGyroInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+ZGyroInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString UGXZGyroInstalErrorFloatStr = ui->lineEdit_8->text();
    double UGXZGyroInstalErrorf = UGXZGyroInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 UGXZGyroInstalErroruint32 = qRound64(UGXZGyroInstalErrorf);
    QString UGXZGyroInstalErrorfloat_str = QString::number(UGXZGyroInstalErroruint32,16);
    QString UGXZGyroInstalErrorfloat_hex = UGXZGyroInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString UGXZGyroInstalErrordataStr = UGXZGyroInstalErrorfloat_hex.mid(6,2)+" "+UGXZGyroInstalErrorfloat_hex.mid(4,2)+" "+UGXZGyroInstalErrorfloat_hex.mid(2,2)+" "+UGXZGyroInstalErrorfloat_hex.mid(0,2)+" ";
    int UGXZGyroInstalErrorCheckSumInt = UGXZGyroInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + UGXZGyroInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+UGXZGyroInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+UGXZGyroInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString UGYZGyroInstalErrorFloatStr = ui->lineEdit_9->text();
    double UGYZGyroInstalErrorf = UGYZGyroInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 UGYZGyroInstalErroruint32 = qRound64(UGYZGyroInstalErrorf);
    QString UGYZGyroInstalErrorfloat_str = QString::number(UGYZGyroInstalErroruint32,16);
    QString UGYZGyroInstalErrorfloat_hex = UGYZGyroInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString UGYZGyroInstalErrordataStr = UGYZGyroInstalErrorfloat_hex.mid(6,2)+" "+UGYZGyroInstalErrorfloat_hex.mid(4,2)+" "+UGYZGyroInstalErrorfloat_hex.mid(2,2)+" "+UGYZGyroInstalErrorfloat_hex.mid(0,2)+" ";
    int UGYZGyroInstalErrorCheckSumInt = UGYZGyroInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + UGYZGyroInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+UGYZGyroInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+UGYZGyroInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString UGZYGyroInstalErrorFloatStr = ui->lineEdit_7->text();
    double UGZYGyroInstalErrorf = UGZYGyroInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 UGZYGyroInstalErroruint32 = qRound64(UGZYGyroInstalErrorf);
    QString UGZYGyroInstalErrorfloat_str = QString::number(UGZYGyroInstalErroruint32,16);
    QString UGZYGyroInstalErrorfloat_hex = UGZYGyroInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString UGZYGyroInstalErrordataStr = UGZYGyroInstalErrorfloat_hex.mid(6,2)+" "+UGZYGyroInstalErrorfloat_hex.mid(4,2)+" "+UGZYGyroInstalErrorfloat_hex.mid(2,2)+" "+UGZYGyroInstalErrorfloat_hex.mid(0,2)+" ";
    int UGZYGyroInstalErrorCheckSumInt = UGZYGyroInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + UGZYGyroInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+UGZYGyroInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+UGZYGyroInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);



    int SdataCheckSum = XGyroScaleCheckSumInt +YGyroScaleCheckSumInt+ ZGyroScaleCheckSumInt+XZeroBiasCheckSumInt+ YZeroBiasCheckSumInt+ZZeroBiasCheckSumInt+XGyroInstalErrorCheckSumInt+YGyroInstalErrorCheckSumInt+ZGyroInstalErrorCheckSumInt+UGXZGyroInstalErrorCheckSumInt+UGYZGyroInstalErrorCheckSumInt+UGZYGyroInstalErrorCheckSumInt+7;
    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);


    QString  SdataStr= "EB 90 07 "+XGyroScaledataStr+YGyroScaledataStr+ZGyroScaledataStr+XZeroBiasdataStr+YZeroBiasdataStr+ZZeroBiasdataStr+XGyroInstalErrordataStr+UGXZGyroInstalErrordataStr+YGyroInstalErrordataStr+UGYZGyroInstalErrordataStr+ZGyroInstalErrordataStr+UGZYGyroInstalErrordataStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订陀螺标定参数：") + tr("X陀螺标度=")+QString::number(XGyroScaleFloatStr.toDouble(),'f',2)
                                                 + tr(" Y陀螺标度=")+ QString::number(YGyroScaleFloatStr.toDouble(),'f',2)
                                                 + tr(" Z陀螺标度=")+ QString::number(ZGyroScaleFloatStr.toDouble(),'f',2)
                                                 + tr(" X陀螺常漂=")+ QString::number(XZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" Y陀螺常漂=")+ QString::number(YZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" Z陀螺常漂=")+ QString::number(ZZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" 陀螺安装误差Uxy=")+ QString::number(XGyroInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 陀螺安装误差Uxz=")+ QString::number(UGXZGyroInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 陀螺安装误差Uyx=")+ QString::number(YGyroInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 陀螺安装误差Uyz=")+ QString::number(UGYZGyroInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 陀螺安装误差Uzx=")+ QString::number(ZGyroInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 陀螺安装误差Uzy=")+ QString::number(UGZYGyroInstalErrorFloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit GyroParaCMD(Sdata);
}

void CalibratParaDialog::on_pushButton_2_clicked()
{
    QByteArray Sdata;

    QString XAccelerometerScaleFloatStr = ui->lineEdit_22->text();
    double XAccelerometerScalef = XAccelerometerScaleFloatStr.toDouble() * qPow(10,6);
    quint32 XAccelerometerScaleuint32 = qRound64(XAccelerometerScalef);
    QString XAccelerometerScalefloat_str = QString::number(XAccelerometerScaleuint32,16);
    QString XAccelerometerScalefloat_hex = XAccelerometerScalefloat_str.rightJustified(8,QLatin1Char('0'));
    QString XAccelerometerScaledataStr = XAccelerometerScalefloat_hex.mid(6,2)+" "+XAccelerometerScalefloat_hex.mid(4,2)+" "+XAccelerometerScalefloat_hex.mid(2,2)+" "+XAccelerometerScalefloat_hex.mid(0,2)+" ";
    QString astr = XAccelerometerScalefloat_hex.mid(6,2);
    int XAccelerometerScaleCheckSumInt = XAccelerometerScalefloat_hex.mid(6,2).toInt(nullptr,16) + XAccelerometerScalefloat_hex.mid(4,2).toInt(nullptr,16)+XAccelerometerScalefloat_hex.mid(2,2).toInt(nullptr,16)+XAccelerometerScalefloat_hex.mid(0,2).toInt(nullptr,16);


    QString YAccelerometerScaleFloatStr = ui->lineEdit_23->text();
    double YAccelerometerScalef = YAccelerometerScaleFloatStr.toDouble() * qPow(10,6);
    quint32 YAccelerometerScaleuint32 = qRound64(YAccelerometerScalef);
    QString YAccelerometerScalefloat_str = QString::number(YAccelerometerScaleuint32,16);
    QString YAccelerometerScalefloat_hex = YAccelerometerScalefloat_str.rightJustified(8,QLatin1Char('0'));
    QString YAccelerometerScaledataStr = YAccelerometerScalefloat_hex.mid(6,2)+" "+YAccelerometerScalefloat_hex.mid(4,2)+" "+YAccelerometerScalefloat_hex.mid(2,2)+" "+YAccelerometerScalefloat_hex.mid(0,2)+" ";
    int YAccelerometerScaleCheckSumInt = YAccelerometerScalefloat_hex.mid(6,2).toInt(nullptr,16) + YAccelerometerScalefloat_hex.mid(4,2).toInt(nullptr,16)+YAccelerometerScalefloat_hex.mid(2,2).toInt(nullptr,16)+YAccelerometerScalefloat_hex.mid(0,2).toInt(nullptr,16);

    QString ZAccelerometerScaleFloatStr = ui->lineEdit_24->text();
    double ZAccelerometerScalef = ZAccelerometerScaleFloatStr.toDouble() * qPow(10,6);
    quint32 ZAccelerometerScaleuint32 = qRound64(ZAccelerometerScalef);
    QString ZAccelerometerScalefloat_str = QString::number(ZAccelerometerScaleuint32,16);
    QString ZAccelerometerScalefloat_hex = ZAccelerometerScalefloat_str.rightJustified(8,QLatin1Char('0'));
    QString ZAccelerometerScaledataStr = ZAccelerometerScalefloat_hex.mid(6,2)+" "+ZAccelerometerScalefloat_hex.mid(4,2)+" "+ZAccelerometerScalefloat_hex.mid(2,2)+" "+ZAccelerometerScalefloat_hex.mid(0,2)+" ";
    int ZAccelerometerScaleCheckSumInt = ZAccelerometerScalefloat_hex.mid(6,2).toInt(nullptr,16) + ZAccelerometerScalefloat_hex.mid(4,2).toInt(nullptr,16)+ZAccelerometerScalefloat_hex.mid(2,2).toInt(nullptr,16)+ZAccelerometerScalefloat_hex.mid(0,2).toInt(nullptr,16);

    QString XAccelerometerZeroBiasFloatStr = ui->lineEdit_13->text();
    double XAccelerometerZeroBiasf = XAccelerometerZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 XAccelerometerZeroBiasuint32 = qRound64(XAccelerometerZeroBiasf);
    QString XAccelerometerZeroBiasfloat_str = QString::number(XAccelerometerZeroBiasuint32,16);
    QString XAccelerometerZeroBiasfloat_hex = XAccelerometerZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString XAccelerometerZeroBiasdataStr = XAccelerometerZeroBiasfloat_hex.mid(6,2)+" "+XAccelerometerZeroBiasfloat_hex.mid(4,2)+" "+XAccelerometerZeroBiasfloat_hex.mid(2,2)+" "+XAccelerometerZeroBiasfloat_hex.mid(0,2)+" ";
    int XAccelerometerZeroBiasCheckSumInt = XAccelerometerZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + XAccelerometerZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+XAccelerometerZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+XAccelerometerZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    QString YAccelerometerZeroBiasFloatStr = ui->lineEdit_14->text();
    double YAccelerometerZeroBiasf = YAccelerometerZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 YAccelerometerZeroBiasuint32 = qRound64(YAccelerometerZeroBiasf);
    QString YAccelerometerZeroBiasfloat_str = QString::number(YAccelerometerZeroBiasuint32,16);
    QString YAccelerometerZeroBiasfloat_hex = YAccelerometerZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString YAccelerometerZeroBiasdataStr = YAccelerometerZeroBiasfloat_hex.mid(6,2)+" "+YAccelerometerZeroBiasfloat_hex.mid(4,2)+" "+YAccelerometerZeroBiasfloat_hex.mid(2,2)+" "+YAccelerometerZeroBiasfloat_hex.mid(0,2)+" ";
    int YAccelerometerZeroBiasCheckSumInt = YAccelerometerZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + YAccelerometerZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+YAccelerometerZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+YAccelerometerZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    QString ZAccelerometerZeroBiasFloatStr = ui->lineEdit_15->text();
    double ZAccelerometerZeroBiasf = ZAccelerometerZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 ZAccelerometerZeroBiasuint32 = qRound64(ZAccelerometerZeroBiasf);
    QString ZAccelerometerZeroBiasfloat_str = QString::number(ZAccelerometerZeroBiasuint32,16);
    QString ZAccelerometerZeroBiasfloat_hex = ZAccelerometerZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString ZAccelerometerZeroBiasdataStr = ZAccelerometerZeroBiasfloat_hex.mid(6,2)+" "+ZAccelerometerZeroBiasfloat_hex.mid(4,2)+" "+ZAccelerometerZeroBiasfloat_hex.mid(2,2)+" "+ZAccelerometerZeroBiasfloat_hex.mid(0,2)+" ";
    int ZAccelerometerZeroBiasCheckSumInt = ZAccelerometerZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + ZAccelerometerZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+ZAccelerometerZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+ZAccelerometerZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    QString XAccelerometerInstalErrorFloatStr = ui->lineEdit_16->text();
    double XAccelerometerInstalErrorf = XAccelerometerInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 XAccelerometerInstalErroruint32 = qRound64(XAccelerometerInstalErrorf);
    QString XAccelerometerInstalErrorfloat_str = QString::number(XAccelerometerInstalErroruint32,16);
    QString XAccelerometerInstalErrorfloat_hex = XAccelerometerInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString XAccelerometerInstalErrordataStr = XAccelerometerInstalErrorfloat_hex.mid(6,2)+" "+XAccelerometerInstalErrorfloat_hex.mid(4,2)+" "+XAccelerometerInstalErrorfloat_hex.mid(2,2)+" "+XAccelerometerInstalErrorfloat_hex.mid(0,2)+" ";
    int XAccelerometerInstalErrorCheckSumInt = XAccelerometerInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + XAccelerometerInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+XAccelerometerInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+XAccelerometerInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString YAccelerometerInstalErrorFloatStr = ui->lineEdit_18->text();
    double YAccelerometerInstalErrorf = YAccelerometerInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 YAccelerometerInstalErroruint32 = qRound64(YAccelerometerInstalErrorf);
    QString YAccelerometerInstalErrorfloat_str = QString::number(YAccelerometerInstalErroruint32,16);
    QString YAccelerometerInstalErrorfloat_hex = YAccelerometerInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString YAccelerometerInstalErrordataStr = YAccelerometerInstalErrorfloat_hex.mid(6,2)+" "+YAccelerometerInstalErrorfloat_hex.mid(4,2)+" "+YAccelerometerInstalErrorfloat_hex.mid(2,2)+" "+YAccelerometerInstalErrorfloat_hex.mid(0,2)+" ";
    int YAccelerometerInstalErrorCheckSumInt = YAccelerometerInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + YAccelerometerInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+YAccelerometerInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+YAccelerometerInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString ZAccelerometerInstalErrorFloatStr = ui->lineEdit_20->text();
    double ZAccelerometerInstalErrorf = ZAccelerometerInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 ZAccelerometerInstalErroruint32 = qRound64(ZAccelerometerInstalErrorf);
    QString ZAccelerometerInstalErrorfloat_str = QString::number(ZAccelerometerInstalErroruint32,16);
    QString ZAccelerometerInstalErrorfloat_hex = ZAccelerometerInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString ZAccelerometerInstalErrordataStr = ZAccelerometerInstalErrorfloat_hex.mid(6,2)+" "+ZAccelerometerInstalErrorfloat_hex.mid(4,2)+" "+ZAccelerometerInstalErrorfloat_hex.mid(2,2)+" "+ZAccelerometerInstalErrorfloat_hex.mid(0,2)+" ";
    int ZAccelerometerInstalErrorCheckSumInt = ZAccelerometerInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + ZAccelerometerInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+ZAccelerometerInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+ZAccelerometerInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString UGXZAccelerometerInstalErrorFloatStr = ui->lineEdit_17->text();
    double UGXZAccelerometerInstalErrorf = UGXZAccelerometerInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 UGXZAccelerometerInstalErroruint32 = qRound64(UGXZAccelerometerInstalErrorf);
    QString UGXZAccelerometerInstalErrorfloat_str = QString::number(UGXZAccelerometerInstalErroruint32,16);
    QString UGXZAccelerometerInstalErrorfloat_hex = UGXZAccelerometerInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString UGXZAccelerometerInstalErrordataStr = UGXZAccelerometerInstalErrorfloat_hex.mid(6,2)+" "+UGXZAccelerometerInstalErrorfloat_hex.mid(4,2)+" "+UGXZAccelerometerInstalErrorfloat_hex.mid(2,2)+" "+UGXZAccelerometerInstalErrorfloat_hex.mid(0,2)+" ";
    int UGXZAccelerometerInstalErrorCheckSumInt = UGXZAccelerometerInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + UGXZAccelerometerInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+UGXZAccelerometerInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+UGXZAccelerometerInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString UGYZAccelerometerInstalErrorFloatStr = ui->lineEdit_19->text();
    double UGYZAccelerometerInstalErrorf = UGYZAccelerometerInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 UGYZAccelerometerInstalErroruint32 = qRound64(UGYZAccelerometerInstalErrorf);
    QString UGYZAccelerometerInstalErrorfloat_str = QString::number(UGYZAccelerometerInstalErroruint32,16);
    QString UGYZAccelerometerInstalErrorfloat_hex = UGYZAccelerometerInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString UGYZAccelerometerInstalErrordataStr = UGYZAccelerometerInstalErrorfloat_hex.mid(6,2)+" "+UGYZAccelerometerInstalErrorfloat_hex.mid(4,2)+" "+UGYZAccelerometerInstalErrorfloat_hex.mid(2,2)+" "+UGYZAccelerometerInstalErrorfloat_hex.mid(0,2)+" ";
    int UGYZAccelerometerInstalErrorCheckSumInt = UGYZAccelerometerInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + UGYZAccelerometerInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+UGYZAccelerometerInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+UGYZAccelerometerInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);

    QString UGZYAccelerometerInstalErrorFloatStr = ui->lineEdit_21->text();
    double UGZYAccelerometerInstalErrorf = UGZYAccelerometerInstalErrorFloatStr.toDouble() * qPow(10,4);
    quint32 UGZYAccelerometerInstalErroruint32 = qRound64(UGZYAccelerometerInstalErrorf);
    QString UGZYAccelerometerInstalErrorfloat_str = QString::number(UGZYAccelerometerInstalErroruint32,16);
    QString UGZYAccelerometerInstalErrorfloat_hex = UGZYAccelerometerInstalErrorfloat_str.rightJustified(8,QLatin1Char('0'));
    QString UGZYAccelerometerInstalErrordataStr = UGZYAccelerometerInstalErrorfloat_hex.mid(6,2)+" "+UGZYAccelerometerInstalErrorfloat_hex.mid(4,2)+" "+UGZYAccelerometerInstalErrorfloat_hex.mid(2,2)+" "+UGZYAccelerometerInstalErrorfloat_hex.mid(0,2)+" ";
    int UGZYAccelerometerInstalErrorCheckSumInt = UGZYAccelerometerInstalErrorfloat_hex.mid(6,2).toInt(nullptr,16) + UGZYAccelerometerInstalErrorfloat_hex.mid(4,2).toInt(nullptr,16)+UGZYAccelerometerInstalErrorfloat_hex.mid(2,2).toInt(nullptr,16)+UGZYAccelerometerInstalErrorfloat_hex.mid(0,2).toInt(nullptr,16);



    int SdataCheckSum = XAccelerometerScaleCheckSumInt +YAccelerometerScaleCheckSumInt+ ZAccelerometerScaleCheckSumInt+XAccelerometerZeroBiasCheckSumInt+ YAccelerometerZeroBiasCheckSumInt+ZAccelerometerZeroBiasCheckSumInt+XAccelerometerInstalErrorCheckSumInt+YAccelerometerInstalErrorCheckSumInt+ZAccelerometerInstalErrorCheckSumInt+UGXZAccelerometerInstalErrorCheckSumInt+UGYZAccelerometerInstalErrorCheckSumInt+UGZYAccelerometerInstalErrorCheckSumInt+8;
    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);


    QString  SdataStr= "EB 90 08 "+XAccelerometerScaledataStr+YAccelerometerScaledataStr+ZAccelerometerScaledataStr+XAccelerometerZeroBiasdataStr+YAccelerometerZeroBiasdataStr+ZAccelerometerZeroBiasdataStr+XAccelerometerInstalErrordataStr+UGXZAccelerometerInstalErrordataStr+YAccelerometerInstalErrordataStr+UGYZAccelerometerInstalErrordataStr+ZAccelerometerInstalErrordataStr+UGZYAccelerometerInstalErrordataStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订加速度计标定参数：") + tr("X加速度计标度=")+ QString::number(XAccelerometerScaleFloatStr.toDouble(),'f',2)
                                                 + tr(" Y加速度计标度=")+ QString::number(YAccelerometerScaleFloatStr.toDouble(),'f',2)
                                                 + tr(" Z加速度计标度=")+ QString::number(ZAccelerometerScaleFloatStr.toDouble(),'f',2)
                                                 + tr(" X加速度计常漂=")+ QString::number(XAccelerometerZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" Y加速度计常漂=")+ QString::number(YAccelerometerZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" Z加速度计常漂=")+ QString::number(ZAccelerometerZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" 加速度计安装误差Uxy=")+ QString::number(XAccelerometerInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 加速度计安装误差Uxz=")+ QString::number(UGXZAccelerometerInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 加速度计安装误差Uyx=")+ QString::number(YAccelerometerInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 加速度计安装误差Uyz=")+ QString::number(UGYZAccelerometerInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 加速度计安装误差Uzx=")+ QString::number(ZAccelerometerInstalErrorFloatStr.toDouble(),'f',2)
                                                 + tr(" 加速度计安装误差Uzy=")+ QString::number(UGZYAccelerometerInstalErrorFloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit AccelerometerParaCMD(Sdata);
}

void CalibratParaDialog::on_pushButton_4_clicked()
{
    this->close();
}

void CalibratParaDialog::on_pushButton_3_clicked()
{
    QByteArray Sdata;

    QString XGyroEqZeroBiasFloatStr = ui->lineEdit_25->text();
    double XGyroEqZeroBiasf = XGyroEqZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 XGyroEqZeroBiasuint32 = qRound64(XGyroEqZeroBiasf);
    QString XGyroEqZeroBiasfloat_str = QString::number(XGyroEqZeroBiasuint32,16);
    QString XGyroEqZeroBiasfloat_hex = XGyroEqZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString XGyroEqZeroBiasdataStr = XGyroEqZeroBiasfloat_hex.mid(6,2)+" "+XGyroEqZeroBiasfloat_hex.mid(4,2)+" "+XGyroEqZeroBiasfloat_hex.mid(2,2)+" "+XGyroEqZeroBiasfloat_hex.mid(0,2)+" ";
    QString astr = XGyroEqZeroBiasfloat_hex.mid(6,2);
    int XGyroEqZeroBiasCheckSumInt = XGyroEqZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + XGyroEqZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+XGyroEqZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+XGyroEqZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);


    QString YGyroEqZeroBiasFloatStr = ui->lineEdit_26->text();
    double YGyroEqZeroBiasf = YGyroEqZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 YGyroEqZeroBiasuint32 = qRound64(YGyroEqZeroBiasf);
    QString YGyroEqZeroBiasfloat_str = QString::number(YGyroEqZeroBiasuint32,16);
    QString YGyroEqZeroBiasfloat_hex = YGyroEqZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString YGyroEqZeroBiasdataStr = YGyroEqZeroBiasfloat_hex.mid(6,2)+" "+YGyroEqZeroBiasfloat_hex.mid(4,2)+" "+YGyroEqZeroBiasfloat_hex.mid(2,2)+" "+YGyroEqZeroBiasfloat_hex.mid(0,2)+" ";
    int YGyroEqZeroBiasCheckSumInt = YGyroEqZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + YGyroEqZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+YGyroEqZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+YGyroEqZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    QString ZGyroEqZeroBiasFloatStr = ui->lineEdit_27->text();
    double ZGyroEqZeroBiasf = ZGyroEqZeroBiasFloatStr.toDouble() * qPow(10,6);
    quint32 ZGyroEqZeroBiasuint32 = qRound64(ZGyroEqZeroBiasf);
    QString ZGyroEqZeroBiasfloat_str = QString::number(ZGyroEqZeroBiasuint32,16);
    QString ZGyroEqZeroBiasfloat_hex = ZGyroEqZeroBiasfloat_str.rightJustified(8,QLatin1Char('0'));
    QString ZGyroEqZeroBiasdataStr = ZGyroEqZeroBiasfloat_hex.mid(6,2)+" "+ZGyroEqZeroBiasfloat_hex.mid(4,2)+" "+ZGyroEqZeroBiasfloat_hex.mid(2,2)+" "+ZGyroEqZeroBiasfloat_hex.mid(0,2)+" ";
    int ZGyroEqZeroBiasCheckSumInt = ZGyroEqZeroBiasfloat_hex.mid(6,2).toInt(nullptr,16) + ZGyroEqZeroBiasfloat_hex.mid(4,2).toInt(nullptr,16)+ZGyroEqZeroBiasfloat_hex.mid(2,2).toInt(nullptr,16)+ZGyroEqZeroBiasfloat_hex.mid(0,2).toInt(nullptr,16);

    int SdataCheckSum = XGyroEqZeroBiasCheckSumInt +YGyroEqZeroBiasCheckSumInt+ ZGyroEqZeroBiasCheckSumInt+9;
    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);


    QString  SdataStr= "EB 90 09 "+XGyroEqZeroBiasdataStr+YGyroEqZeroBiasdataStr+ZGyroEqZeroBiasdataStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订陀螺等效零偏：") + tr("X陀螺等效零偏=")+ QString::number(XGyroEqZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" Y陀螺等效零偏=")+ QString::number(YGyroEqZeroBiasFloatStr.toDouble(),'f',2)
                                                 + tr(" Z陀螺等效零偏=")+ QString::number(ZGyroEqZeroBiasFloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit GyroEqZeroBiasCMD(Sdata);
}
