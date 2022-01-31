#include "tempcompencoeffdialog.h"
#include "ui_tempcompencoeffdialog.h"
#include "common.h"
#include <QTime>
TempCompenCoeffDialog::TempCompenCoeffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TempCompenCoeffDialog)
{
    ui->setupUi(this);
}

TempCompenCoeffDialog::~TempCompenCoeffDialog()
{
    delete ui;
}

void TempCompenCoeffDialog::on_pushButton_clicked()
{
    QByteArray Sdata;
    union TempUnion_
    {
        quint32 quint32Value;
        float floatValue;
    }TempUnion;

    //X陀螺零偏温补系数0次项
    QString XGyroTempCompenCoeff0FloatStr = ui->lineEdit->text();
//    float XGyroTempCompenCoeff0f = XGyroTempCompenCoeff0FloatStr.toFloat ();
//    quint32 XGyroTempCompenCoeff0uint32 =*(quint32 *)&XGyroTempCompenCoeff0f;

    TempUnion.floatValue = XGyroTempCompenCoeff0FloatStr.toFloat();
    quint32 XGyroTempCompenCoeff0uint32 = TempUnion.quint32Value;
    QString XGyroTempCompenCoeff0float_hex = QString("%1").arg(XGyroTempCompenCoeff0uint32, 8, 16, QLatin1Char('0'));
    QString XGyroTempCompenCoeff0dataStr = XGyroTempCompenCoeff0float_hex.mid(6,2)+" "+XGyroTempCompenCoeff0float_hex.mid(4,2)+" "+XGyroTempCompenCoeff0float_hex.mid(2,2)+" "+XGyroTempCompenCoeff0float_hex.mid(0,2)+" ";
    int XGyroTempCompenCoeff0CheckSumInt = XGyroTempCompenCoeff0float_hex.mid(6,2).toInt(nullptr,16) + XGyroTempCompenCoeff0float_hex.mid(4,2).toInt(nullptr,16)+XGyroTempCompenCoeff0float_hex.mid(2,2).toInt(nullptr,16)+XGyroTempCompenCoeff0float_hex.mid(0,2).toInt(nullptr,16);

    //Y陀螺零偏温补系数0次项
    QString YGyroTempCompenCoeff0FloatStr = ui->lineEdit_2->text();
//    float YGyroTempCompenCoeff0f = YGyroTempCompenCoeff0FloatStr.toFloat ();
//    quint32 YGyroTempCompenCoeff0uint32 =*(quint32 *)&YGyroTempCompenCoeff0f;

    TempUnion.floatValue = YGyroTempCompenCoeff0FloatStr.toFloat();
    quint32 YGyroTempCompenCoeff0uint32 = TempUnion.quint32Value;
    QString YGyroTempCompenCoeff0float_hex = QString("%1").arg(YGyroTempCompenCoeff0uint32, 8, 16, QLatin1Char('0'));
    QString YGyroTempCompenCoeff0dataStr = YGyroTempCompenCoeff0float_hex.mid(6,2)+" "+YGyroTempCompenCoeff0float_hex.mid(4,2)+" "+YGyroTempCompenCoeff0float_hex.mid(2,2)+" "+YGyroTempCompenCoeff0float_hex.mid(0,2)+" ";
    int YGyroTempCompenCoeff0CheckSumInt = YGyroTempCompenCoeff0float_hex.mid(6,2).toInt(nullptr,16) + YGyroTempCompenCoeff0float_hex.mid(4,2).toInt(nullptr,16)+YGyroTempCompenCoeff0float_hex.mid(2,2).toInt(nullptr,16)+YGyroTempCompenCoeff0float_hex.mid(0,2).toInt(nullptr,16);

    //Z陀螺零偏温补系数0次项
    QString ZGyroTempCompenCoeff0FloatStr = ui->lineEdit_3->text();
//    float ZGyroTempCompenCoeff0f = ZGyroTempCompenCoeff0FloatStr.toFloat ();
//    quint32 ZGyroTempCompenCoeff0uint32 =*(quint32 *)&ZGyroTempCompenCoeff0f;

    TempUnion.floatValue = ZGyroTempCompenCoeff0FloatStr.toFloat();
    quint32 ZGyroTempCompenCoeff0uint32 = TempUnion.quint32Value;
    QString ZGyroTempCompenCoeff0float_hex = QString("%1").arg(ZGyroTempCompenCoeff0uint32, 8, 16, QLatin1Char('0'));
    QString ZGyroTempCompenCoeff0dataStr = ZGyroTempCompenCoeff0float_hex.mid(6,2)+" "+ZGyroTempCompenCoeff0float_hex.mid(4,2)+" "+ZGyroTempCompenCoeff0float_hex.mid(2,2)+" "+ZGyroTempCompenCoeff0float_hex.mid(0,2)+" ";
    int ZGyroTempCompenCoeff0CheckSumInt = ZGyroTempCompenCoeff0float_hex.mid(6,2).toInt(nullptr,16) + ZGyroTempCompenCoeff0float_hex.mid(4,2).toInt(nullptr,16)+ZGyroTempCompenCoeff0float_hex.mid(2,2).toInt(nullptr,16)+ZGyroTempCompenCoeff0float_hex.mid(0,2).toInt(nullptr,16);


    //X陀螺零偏温补系数1次项
    QString XGyroTempCompenCoeff1FloatStr = ui->lineEdit_4->text();
//    float XGyroTempCompenCoeff1f = XGyroTempCompenCoeff1FloatStr.toFloat ();
//    quint32 XGyroTempCompenCoeff1uint32 =*(quint32 *)&XGyroTempCompenCoeff1f;

    TempUnion.floatValue = XGyroTempCompenCoeff1FloatStr.toFloat();
    quint32 XGyroTempCompenCoeff1uint32 = TempUnion.quint32Value;
    QString XGyroTempCompenCoeff1float_hex = QString("%1").arg(XGyroTempCompenCoeff1uint32, 8, 16, QLatin1Char('0'));
    QString XGyroTempCompenCoeff1dataStr = XGyroTempCompenCoeff1float_hex.mid(6,2)+" "+XGyroTempCompenCoeff1float_hex.mid(4,2)+" "+XGyroTempCompenCoeff1float_hex.mid(2,2)+" "+XGyroTempCompenCoeff1float_hex.mid(0,2)+" ";
    int XGyroTempCompenCoeff1CheckSumInt = XGyroTempCompenCoeff1float_hex.mid(6,2).toInt(nullptr,16) + XGyroTempCompenCoeff1float_hex.mid(4,2).toInt(nullptr,16)+XGyroTempCompenCoeff1float_hex.mid(2,2).toInt(nullptr,16)+XGyroTempCompenCoeff1float_hex.mid(0,2).toInt(nullptr,16);

    //Y陀螺零偏温补系数1次项
    QString YGyroTempCompenCoeff1FloatStr = ui->lineEdit_5->text();
//    float YGyroTempCompenCoeff1f = YGyroTempCompenCoeff1FloatStr.toFloat ();
//    quint32 YGyroTempCompenCoeff1uint32 =*(quint32 *)&YGyroTempCompenCoeff1f;

    TempUnion.floatValue = YGyroTempCompenCoeff1FloatStr.toFloat();
    quint32 YGyroTempCompenCoeff1uint32 = TempUnion.quint32Value;

    QString YGyroTempCompenCoeff1float_hex = QString("%1").arg(YGyroTempCompenCoeff1uint32, 8, 16, QLatin1Char('0'));
    QString YGyroTempCompenCoeff1dataStr = YGyroTempCompenCoeff1float_hex.mid(6,2)+" "+YGyroTempCompenCoeff1float_hex.mid(4,2)+" "+YGyroTempCompenCoeff1float_hex.mid(2,2)+" "+YGyroTempCompenCoeff1float_hex.mid(0,2)+" ";
    int YGyroTempCompenCoeff1CheckSumInt = YGyroTempCompenCoeff1float_hex.mid(6,2).toInt(nullptr,16) + YGyroTempCompenCoeff1float_hex.mid(4,2).toInt(nullptr,16)+YGyroTempCompenCoeff1float_hex.mid(2,2).toInt(nullptr,16)+YGyroTempCompenCoeff1float_hex.mid(0,2).toInt(nullptr,16);

    //Z陀螺零偏温补系数1次项
    QString ZGyroTempCompenCoeff1FloatStr = ui->lineEdit_6->text();
//    float ZGyroTempCompenCoeff1f = ZGyroTempCompenCoeff1FloatStr.toFloat ();
//    quint32 ZGyroTempCompenCoeff1uint32 =*(quint32 *)&ZGyroTempCompenCoeff1f;

    TempUnion.floatValue = ZGyroTempCompenCoeff1FloatStr.toFloat();
    quint32 ZGyroTempCompenCoeff1uint32 = TempUnion.quint32Value;
    QString ZGyroTempCompenCoeff1float_hex = QString("%1").arg(ZGyroTempCompenCoeff1uint32, 8, 16, QLatin1Char('0'));
    QString ZGyroTempCompenCoeff1dataStr = ZGyroTempCompenCoeff1float_hex.mid(6,2)+" "+ZGyroTempCompenCoeff1float_hex.mid(4,2)+" "+ZGyroTempCompenCoeff1float_hex.mid(2,2)+" "+ZGyroTempCompenCoeff1float_hex.mid(0,2)+" ";
    int ZGyroTempCompenCoeff1CheckSumInt = ZGyroTempCompenCoeff1float_hex.mid(6,2).toInt(nullptr,16) + ZGyroTempCompenCoeff1float_hex.mid(4,2).toInt(nullptr,16)+ZGyroTempCompenCoeff1float_hex.mid(2,2).toInt(nullptr,16)+ZGyroTempCompenCoeff1float_hex.mid(0,2).toInt(nullptr,16);

    //X陀螺零偏温补系数2次项
    QString XGyroTempCompenCoeff2FloatStr = ui->lineEdit_7->text();
//    float XGyroTempCompenCoeff2f = XGyroTempCompenCoeff2FloatStr.toFloat ();
//    quint32 XGyroTempCompenCoeff2uint32 =*(quint32 *)&XGyroTempCompenCoeff2f;

    TempUnion.floatValue = XGyroTempCompenCoeff2FloatStr.toFloat();
    quint32 XGyroTempCompenCoeff2uint32 = TempUnion.quint32Value;
    QString XGyroTempCompenCoeff2float_hex = QString("%1").arg(XGyroTempCompenCoeff2uint32, 8, 16, QLatin1Char('0'));
    QString XGyroTempCompenCoeff2dataStr = XGyroTempCompenCoeff2float_hex.mid(6,2)+" "+XGyroTempCompenCoeff2float_hex.mid(4,2)+" "+XGyroTempCompenCoeff2float_hex.mid(2,2)+" "+XGyroTempCompenCoeff2float_hex.mid(0,2)+" ";
    int XGyroTempCompenCoeff2CheckSumInt = XGyroTempCompenCoeff2float_hex.mid(6,2).toInt(nullptr,16) + XGyroTempCompenCoeff2float_hex.mid(4,2).toInt(nullptr,16)+XGyroTempCompenCoeff2float_hex.mid(2,2).toInt(nullptr,16)+XGyroTempCompenCoeff2float_hex.mid(0,2).toInt(nullptr,16);

    //Y陀螺零偏温补系数2次项
    QString YGyroTempCompenCoeff2FloatStr = ui->lineEdit_8->text();
//    float YGyroTempCompenCoeff2f = YGyroTempCompenCoeff2FloatStr.toFloat ();
//    quint32 YGyroTempCompenCoeff2uint32 =*(quint32 *)&YGyroTempCompenCoeff2f;

    TempUnion.floatValue = YGyroTempCompenCoeff2FloatStr.toFloat();
    quint32 YGyroTempCompenCoeff2uint32 = TempUnion.quint32Value;
    QString YGyroTempCompenCoeff2float_hex = QString("%1").arg(YGyroTempCompenCoeff2uint32, 8, 16, QLatin1Char('0'));
    QString YGyroTempCompenCoeff2dataStr = YGyroTempCompenCoeff2float_hex.mid(6,2)+" "+YGyroTempCompenCoeff2float_hex.mid(4,2)+" "+YGyroTempCompenCoeff2float_hex.mid(2,2)+" "+YGyroTempCompenCoeff2float_hex.mid(0,2)+" ";
    int YGyroTempCompenCoeff2CheckSumInt = YGyroTempCompenCoeff2float_hex.mid(6,2).toInt(nullptr,16) + YGyroTempCompenCoeff2float_hex.mid(4,2).toInt(nullptr,16)+YGyroTempCompenCoeff2float_hex.mid(2,2).toInt(nullptr,16)+YGyroTempCompenCoeff2float_hex.mid(0,2).toInt(nullptr,16);

    //Z陀螺零偏温补系数2次项
    QString ZGyroTempCompenCoeff2FloatStr = ui->lineEdit_9->text();
//    float ZGyroTempCompenCoeff2f = ZGyroTempCompenCoeff2FloatStr.toFloat ();
//    quint32 ZGyroTempCompenCoeff2uint32 =*(quint32 *)&ZGyroTempCompenCoeff2f;

    TempUnion.floatValue = ZGyroTempCompenCoeff2FloatStr.toFloat();
    quint32 ZGyroTempCompenCoeff2uint32 = TempUnion.quint32Value;
    QString ZGyroTempCompenCoeff2float_hex = QString("%1").arg(ZGyroTempCompenCoeff2uint32, 8, 16, QLatin1Char('0'));
    QString ZGyroTempCompenCoeff2dataStr = ZGyroTempCompenCoeff2float_hex.mid(6,2)+" "+ZGyroTempCompenCoeff2float_hex.mid(4,2)+" "+ZGyroTempCompenCoeff2float_hex.mid(2,2)+" "+ZGyroTempCompenCoeff2float_hex.mid(0,2)+" ";
    int ZGyroTempCompenCoeff2CheckSumInt = ZGyroTempCompenCoeff2float_hex.mid(6,2).toInt(nullptr,16) + ZGyroTempCompenCoeff2float_hex.mid(4,2).toInt(nullptr,16)+ZGyroTempCompenCoeff2float_hex.mid(2,2).toInt(nullptr,16)+ZGyroTempCompenCoeff2float_hex.mid(0,2).toInt(nullptr,16);

    //X陀螺零偏温补系数3次项
    QString XGyroTempCompenCoeff3FloatStr = ui->lineEdit_10->text();
//    float XGyroTempCompenCoeff3f = XGyroTempCompenCoeff3FloatStr.toFloat ();
//    quint32 XGyroTempCompenCoeff3uint32 =*(quint32 *)&XGyroTempCompenCoeff3f;

    TempUnion.floatValue = XGyroTempCompenCoeff3FloatStr.toFloat();
    quint32 XGyroTempCompenCoeff3uint32 = TempUnion.quint32Value;

    QString XGyroTempCompenCoeff3float_hex = QString("%1").arg(XGyroTempCompenCoeff3uint32, 8, 16, QLatin1Char('0'));
    QString XGyroTempCompenCoeff3dataStr = XGyroTempCompenCoeff3float_hex.mid(6,2)+" "+XGyroTempCompenCoeff3float_hex.mid(4,2)+" "+XGyroTempCompenCoeff3float_hex.mid(2,2)+" "+XGyroTempCompenCoeff3float_hex.mid(0,2)+" ";
    int XGyroTempCompenCoeff3CheckSumInt = XGyroTempCompenCoeff3float_hex.mid(6,2).toInt(nullptr,16) + XGyroTempCompenCoeff3float_hex.mid(4,2).toInt(nullptr,16)+XGyroTempCompenCoeff3float_hex.mid(2,2).toInt(nullptr,16)+XGyroTempCompenCoeff3float_hex.mid(0,2).toInt(nullptr,16);

    //Y陀螺零偏温补系数3次项
    QString YGyroTempCompenCoeff3FloatStr = ui->lineEdit_11->text();
//    float YGyroTempCompenCoeff3f = YGyroTempCompenCoeff3FloatStr.toFloat ();
//    quint32 YGyroTempCompenCoeff3uint32 =*(quint32 *)&YGyroTempCompenCoeff3f;

    TempUnion.floatValue = YGyroTempCompenCoeff3FloatStr.toFloat();
    quint32 YGyroTempCompenCoeff3uint32 = TempUnion.quint32Value;
    QString YGyroTempCompenCoeff3float_hex = QString("%1").arg(YGyroTempCompenCoeff3uint32, 8, 16, QLatin1Char('0'));
    QString YGyroTempCompenCoeff3dataStr = YGyroTempCompenCoeff3float_hex.mid(6,2)+" "+YGyroTempCompenCoeff3float_hex.mid(4,2)+" "+YGyroTempCompenCoeff3float_hex.mid(2,2)+" "+YGyroTempCompenCoeff3float_hex.mid(0,2)+" ";
    int YGyroTempCompenCoeff3CheckSumInt = YGyroTempCompenCoeff3float_hex.mid(6,2).toInt(nullptr,16) + YGyroTempCompenCoeff3float_hex.mid(4,2).toInt(nullptr,16)+YGyroTempCompenCoeff3float_hex.mid(2,2).toInt(nullptr,16)+YGyroTempCompenCoeff3float_hex.mid(0,2).toInt(nullptr,16);

    //Z陀螺零偏温补系数3次项
    QString ZGyroTempCompenCoeff3FloatStr = ui->lineEdit_12->text();
//    float ZGyroTempCompenCoeff3f = ZGyroTempCompenCoeff3FloatStr.toFloat ();
//    quint32 ZGyroTempCompenCoeff3uint32 =*(quint32 *)&ZGyroTempCompenCoeff3f;

    TempUnion.floatValue = ZGyroTempCompenCoeff3FloatStr.toFloat();
    quint32 ZGyroTempCompenCoeff3uint32 = TempUnion.quint32Value;
    QString ZGyroTempCompenCoeff3float_hex = QString("%1").arg(ZGyroTempCompenCoeff3uint32, 8, 16, QLatin1Char('0'));
    QString ZGyroTempCompenCoeff3dataStr = ZGyroTempCompenCoeff3float_hex.mid(6,2)+" "+ZGyroTempCompenCoeff3float_hex.mid(4,2)+" "+ZGyroTempCompenCoeff3float_hex.mid(2,2)+" "+ZGyroTempCompenCoeff3float_hex.mid(0,2)+" ";
    int ZGyroTempCompenCoeff3CheckSumInt = ZGyroTempCompenCoeff3float_hex.mid(6,2).toInt(nullptr,16) + ZGyroTempCompenCoeff3float_hex.mid(4,2).toInt(nullptr,16)+ZGyroTempCompenCoeff3float_hex.mid(2,2).toInt(nullptr,16)+ZGyroTempCompenCoeff3float_hex.mid(0,2).toInt(nullptr,16);


    //校验和
    int SdataCheckSum = XGyroTempCompenCoeff0CheckSumInt +XGyroTempCompenCoeff1CheckSumInt + XGyroTempCompenCoeff2CheckSumInt+XGyroTempCompenCoeff3CheckSumInt+YGyroTempCompenCoeff0CheckSumInt +YGyroTempCompenCoeff1CheckSumInt + YGyroTempCompenCoeff2CheckSumInt+YGyroTempCompenCoeff3CheckSumInt+ZGyroTempCompenCoeff0CheckSumInt +ZGyroTempCompenCoeff1CheckSumInt + ZGyroTempCompenCoeff2CheckSumInt+ZGyroTempCompenCoeff3CheckSumInt+13;

    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);

    QString  SdataStr= "EB 90 0D "+XGyroTempCompenCoeff0dataStr+YGyroTempCompenCoeff0dataStr+ZGyroTempCompenCoeff0dataStr+XGyroTempCompenCoeff1dataStr+YGyroTempCompenCoeff1dataStr+ZGyroTempCompenCoeff1dataStr+XGyroTempCompenCoeff2dataStr+YGyroTempCompenCoeff2dataStr+ZGyroTempCompenCoeff2dataStr+XGyroTempCompenCoeff3dataStr+YGyroTempCompenCoeff3dataStr+ZGyroTempCompenCoeff3dataStr+SdataCheckSumHexStr;

    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("装订陀螺温补系数：") + tr("X陀螺零偏温度0次项=")+ QString::number(XGyroTempCompenCoeff0FloatStr.toFloat (),'f',2)
                                                + tr(" Y陀螺零偏温度0次项=")+ QString::number(YGyroTempCompenCoeff0FloatStr.toFloat (),'f',2)
                                                + tr(" Z陀螺零偏温度0次项=")+ QString::number(ZGyroTempCompenCoeff0FloatStr.toFloat (),'f',2)
                                                + tr(" X陀螺零偏温度1次项=")+ QString::number(XGyroTempCompenCoeff1FloatStr.toFloat (),'f',2)
                                                + tr(" Y陀螺零偏温度1次项=")+ QString::number(YGyroTempCompenCoeff1FloatStr.toFloat (),'f',2)
                                                + tr(" Z陀螺零偏温度1次项=")+ QString::number(ZGyroTempCompenCoeff1FloatStr.toFloat (),'f',2)
                                                + tr(" X陀螺零偏温度2次项=")+ QString::number(XGyroTempCompenCoeff2FloatStr.toFloat (),'f',2)
                                                + tr(" Y陀螺零偏温度2次项=")+ QString::number(YGyroTempCompenCoeff2FloatStr.toFloat (),'f',2)
                                                + tr(" Z陀螺零偏温度2次项=")+ QString::number(ZGyroTempCompenCoeff2FloatStr.toFloat (),'f',2)
                                                + tr(" X陀螺零偏温度3次项=")+ QString::number(XGyroTempCompenCoeff3FloatStr.toFloat (),'f',2)
                                                + tr(" Y陀螺零偏温度3次项=")+ QString::number(YGyroTempCompenCoeff3FloatStr.toFloat (),'f',2)
                                                + tr(" Z陀螺零偏温度3次项=")+ QString::number(ZGyroTempCompenCoeff3FloatStr.toFloat (),'f',2)
                                                +"\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);

    Sdata = HexStringToByteArray(SdataStr);

    emit GyroTempComCoeffCMD(Sdata);
}

void TempCompenCoeffDialog::on_pushButton_2_clicked()
{
    QByteArray Sdata;

    union TempUnion_
    {
        quint32 quint32Value;
        float floatValue;
    }TempUnion;
    //X加计零偏温补系数0次项
    QString XAccelerometerComCoeff0FloatStr = ui->lineEdit_13->text();
//    float XAccelerometerComCoeff0f = XAccelerometerComCoeff0FloatStr.toFloat ();
//    quint32 XAccelerometerComCoeff0uint32 =*(quint32 *)&XAccelerometerComCoeff0f;

    TempUnion.floatValue = XAccelerometerComCoeff0FloatStr.toFloat();
    quint32 XAccelerometerComCoeff0uint32 = TempUnion.quint32Value;

    QString XAccelerometerComCoeff0float_hex = QString("%1").arg(XAccelerometerComCoeff0uint32, 8, 16, QLatin1Char('0'));
    QString XAccelerometerComCoeff0dataStr = XAccelerometerComCoeff0float_hex.mid(6,2)+" "+XAccelerometerComCoeff0float_hex.mid(4,2)+" "+XAccelerometerComCoeff0float_hex.mid(2,2)+" "+XAccelerometerComCoeff0float_hex.mid(0,2)+" ";
    int XAccelerometerComCoeff0CheckSumInt = XAccelerometerComCoeff0float_hex.mid(6,2).toInt(nullptr,16) + XAccelerometerComCoeff0float_hex.mid(4,2).toInt(nullptr,16)+XAccelerometerComCoeff0float_hex.mid(2,2).toInt(nullptr,16)+XAccelerometerComCoeff0float_hex.mid(0,2).toInt(nullptr,16);

    //Y加计零偏温补系数0次项
    QString YAccelerometerComCoeff0FloatStr = ui->lineEdit_14->text();
//    float YAccelerometerComCoeff0f = YAccelerometerComCoeff0FloatStr.toFloat();
//    quint32 YAccelerometerComCoeff0uint32 =*(quint32 *)&YAccelerometerComCoeff0f;

    TempUnion.floatValue = YAccelerometerComCoeff0FloatStr.toFloat();
    quint32 YAccelerometerComCoeff0uint32 = TempUnion.quint32Value;

    QString YAccelerometerComCoeff0float_hex = QString("%1").arg(YAccelerometerComCoeff0uint32, 8, 16, QLatin1Char('0'));
    QString YAccelerometerComCoeff0dataStr = YAccelerometerComCoeff0float_hex.mid(6,2)+" "+YAccelerometerComCoeff0float_hex.mid(4,2)+" "+YAccelerometerComCoeff0float_hex.mid(2,2)+" "+YAccelerometerComCoeff0float_hex.mid(0,2)+" ";
    int YAccelerometerComCoeff0CheckSumInt = YAccelerometerComCoeff0float_hex.mid(6,2).toInt(nullptr,16) + YAccelerometerComCoeff0float_hex.mid(4,2).toInt(nullptr,16)+YAccelerometerComCoeff0float_hex.mid(2,2).toInt(nullptr,16)+YAccelerometerComCoeff0float_hex.mid(0,2).toInt(nullptr,16);

    //Z加计零偏温补系数0次项
    QString ZAccelerometerComCoeff0FloatStr = ui->lineEdit_15->text();
//    float ZAccelerometerComCoeff0f = ZAccelerometerComCoeff0FloatStr.toFloat();
//    quint32 ZAccelerometerComCoeff0uint32 =*(quint32 *)&ZAccelerometerComCoeff0f;

    TempUnion.floatValue = ZAccelerometerComCoeff0FloatStr.toFloat();
    quint32 ZAccelerometerComCoeff0uint32 = TempUnion.quint32Value;
    QString ZAccelerometerComCoeff0float_hex = QString("%1").arg(ZAccelerometerComCoeff0uint32, 8, 16, QLatin1Char('0'));
    QString ZAccelerometerComCoeff0dataStr = ZAccelerometerComCoeff0float_hex.mid(6,2)+" "+ZAccelerometerComCoeff0float_hex.mid(4,2)+" "+ZAccelerometerComCoeff0float_hex.mid(2,2)+" "+ZAccelerometerComCoeff0float_hex.mid(0,2)+" ";
    int ZAccelerometerComCoeff0CheckSumInt = ZAccelerometerComCoeff0float_hex.mid(6,2).toInt(nullptr,16) + ZAccelerometerComCoeff0float_hex.mid(4,2).toInt(nullptr,16)+ZAccelerometerComCoeff0float_hex.mid(2,2).toInt(nullptr,16)+ZAccelerometerComCoeff0float_hex.mid(0,2).toInt(nullptr,16);


    //X加计零偏温补系数1次项
    QString XAccelerometerComCoeff1FloatStr = ui->lineEdit_16->text();
//    float XAccelerometerComCoeff1f = XAccelerometerComCoeff1FloatStr.toFloat();
//    quint32 XAccelerometerComCoeff1uint32 =*(quint32 *)&XAccelerometerComCoeff1f;

    TempUnion.floatValue = XAccelerometerComCoeff1FloatStr.toFloat();
    quint32 XAccelerometerComCoeff1uint32 = TempUnion.quint32Value;
    QString XAccelerometerComCoeff1float_hex = QString("%1").arg(XAccelerometerComCoeff1uint32, 8, 16, QLatin1Char('0'));
    QString XAccelerometerComCoeff1dataStr = XAccelerometerComCoeff1float_hex.mid(6,2)+" "+XAccelerometerComCoeff1float_hex.mid(4,2)+" "+XAccelerometerComCoeff1float_hex.mid(2,2)+" "+XAccelerometerComCoeff1float_hex.mid(0,2)+" ";
    int XAccelerometerComCoeff1CheckSumInt = XAccelerometerComCoeff1float_hex.mid(6,2).toInt(nullptr,16) + XAccelerometerComCoeff1float_hex.mid(4,2).toInt(nullptr,16)+XAccelerometerComCoeff1float_hex.mid(2,2).toInt(nullptr,16)+XAccelerometerComCoeff1float_hex.mid(0,2).toInt(nullptr,16);

    //Y加计零偏温补系数1次项
    QString YAccelerometerComCoeff1FloatStr = ui->lineEdit_17->text();
//    float YAccelerometerComCoeff1f = YAccelerometerComCoeff1FloatStr.toFloat();
//    quint32 YAccelerometerComCoeff1uint32 =*(quint32 *)&YAccelerometerComCoeff1f;

    TempUnion.floatValue = YAccelerometerComCoeff1FloatStr.toFloat();
    quint32 YAccelerometerComCoeff1uint32 = TempUnion.quint32Value;
    QString YAccelerometerComCoeff1float_hex = QString("%1").arg(YAccelerometerComCoeff1uint32, 8, 16, QLatin1Char('0'));
    QString YAccelerometerComCoeff1dataStr = YAccelerometerComCoeff1float_hex.mid(6,2)+" "+YAccelerometerComCoeff1float_hex.mid(4,2)+" "+YAccelerometerComCoeff1float_hex.mid(2,2)+" "+YAccelerometerComCoeff1float_hex.mid(0,2)+" ";
    int YAccelerometerComCoeff1CheckSumInt = YAccelerometerComCoeff1float_hex.mid(6,2).toInt(nullptr,16) + YAccelerometerComCoeff1float_hex.mid(4,2).toInt(nullptr,16)+YAccelerometerComCoeff1float_hex.mid(2,2).toInt(nullptr,16)+YAccelerometerComCoeff1float_hex.mid(0,2).toInt(nullptr,16);

    //Z加计零偏温补系数1次项
    QString ZAccelerometerComCoeff1FloatStr = ui->lineEdit_18->text();
//    float ZAccelerometerComCoeff1f = ZAccelerometerComCoeff1FloatStr.toFloat();
//    quint32 ZAccelerometerComCoeff1uint32 =*(quint32 *)&ZAccelerometerComCoeff1f;

    TempUnion.floatValue = ZAccelerometerComCoeff1FloatStr.toFloat();
    quint32 ZAccelerometerComCoeff1uint32 = TempUnion.quint32Value;
    QString ZAccelerometerComCoeff1float_hex = QString("%1").arg(ZAccelerometerComCoeff1uint32, 8, 16, QLatin1Char('0'));
    QString ZAccelerometerComCoeff1dataStr = ZAccelerometerComCoeff1float_hex.mid(6,2)+" "+ZAccelerometerComCoeff1float_hex.mid(4,2)+" "+ZAccelerometerComCoeff1float_hex.mid(2,2)+" "+ZAccelerometerComCoeff1float_hex.mid(0,2)+" ";
    int ZAccelerometerComCoeff1CheckSumInt = ZAccelerometerComCoeff1float_hex.mid(6,2).toInt(nullptr,16) + ZAccelerometerComCoeff1float_hex.mid(4,2).toInt(nullptr,16)+ZAccelerometerComCoeff1float_hex.mid(2,2).toInt(nullptr,16)+ZAccelerometerComCoeff1float_hex.mid(0,2).toInt(nullptr,16);

    //X加计零偏温补系数2次项
    QString XAccelerometerComCoeff2FloatStr = ui->lineEdit_19->text();
//    float XAccelerometerComCoeff2f = XAccelerometerComCoeff2FloatStr.toFloat();
//    quint32 XAccelerometerComCoeff2uint32 =*(quint32 *)&XAccelerometerComCoeff2f;

    TempUnion.floatValue = XAccelerometerComCoeff2FloatStr.toFloat();
    quint32 XAccelerometerComCoeff2uint32 = TempUnion.quint32Value;
    QString XAccelerometerComCoeff2float_hex = QString("%1").arg(XAccelerometerComCoeff2uint32, 8, 16, QLatin1Char('0'));
    QString XAccelerometerComCoeff2dataStr = XAccelerometerComCoeff2float_hex.mid(6,2)+" "+XAccelerometerComCoeff2float_hex.mid(4,2)+" "+XAccelerometerComCoeff2float_hex.mid(2,2)+" "+XAccelerometerComCoeff2float_hex.mid(0,2)+" ";
    int XAccelerometerComCoeff2CheckSumInt = XAccelerometerComCoeff2float_hex.mid(6,2).toInt(nullptr,16) + XAccelerometerComCoeff2float_hex.mid(4,2).toInt(nullptr,16)+XAccelerometerComCoeff2float_hex.mid(2,2).toInt(nullptr,16)+XAccelerometerComCoeff2float_hex.mid(0,2).toInt(nullptr,16);

    //Y加计零偏温补系数2次项
    QString YAccelerometerComCoeff2FloatStr = ui->lineEdit_20->text();
//    float YAccelerometerComCoeff2f = YAccelerometerComCoeff2FloatStr.toFloat();
//    quint32 YAccelerometerComCoeff2uint32 =*(quint32 *)&YAccelerometerComCoeff2f;

    TempUnion.floatValue = YAccelerometerComCoeff2FloatStr.toFloat();
    quint32 YAccelerometerComCoeff2uint32 = TempUnion.quint32Value;
    QString YAccelerometerComCoeff2float_hex = QString("%1").arg(YAccelerometerComCoeff2uint32, 8, 16, QLatin1Char('0'));
    QString YAccelerometerComCoeff2dataStr = YAccelerometerComCoeff2float_hex.mid(6,2)+" "+YAccelerometerComCoeff2float_hex.mid(4,2)+" "+YAccelerometerComCoeff2float_hex.mid(2,2)+" "+YAccelerometerComCoeff2float_hex.mid(0,2)+" ";
    int YAccelerometerComCoeff2CheckSumInt = YAccelerometerComCoeff2float_hex.mid(6,2).toInt(nullptr,16) + YAccelerometerComCoeff2float_hex.mid(4,2).toInt(nullptr,16)+YAccelerometerComCoeff2float_hex.mid(2,2).toInt(nullptr,16)+YAccelerometerComCoeff2float_hex.mid(0,2).toInt(nullptr,16);

    //Z加计零偏温补系数2次项
    QString ZAccelerometerComCoeff2FloatStr = ui->lineEdit_21->text();
//    float ZAccelerometerComCoeff2f = ZAccelerometerComCoeff2FloatStr.toFloat ();
//    quint32 ZAccelerometerComCoeff2uint32 =*(quint32 *)&ZAccelerometerComCoeff2f;

    TempUnion.floatValue = ZAccelerometerComCoeff2FloatStr.toFloat();
    quint32 ZAccelerometerComCoeff2uint32 = TempUnion.quint32Value;
    QString ZAccelerometerComCoeff2float_hex = QString("%1").arg(ZAccelerometerComCoeff2uint32, 8, 16, QLatin1Char('0'));
    QString ZAccelerometerComCoeff2dataStr = ZAccelerometerComCoeff2float_hex.mid(6,2)+" "+ZAccelerometerComCoeff2float_hex.mid(4,2)+" "+ZAccelerometerComCoeff2float_hex.mid(2,2)+" "+ZAccelerometerComCoeff2float_hex.mid(0,2)+" ";
    int ZAccelerometerComCoeff2CheckSumInt = ZAccelerometerComCoeff2float_hex.mid(6,2).toInt(nullptr,16) + ZAccelerometerComCoeff2float_hex.mid(4,2).toInt(nullptr,16)+ZAccelerometerComCoeff2float_hex.mid(2,2).toInt(nullptr,16)+ZAccelerometerComCoeff2float_hex.mid(0,2).toInt(nullptr,16);

    //X加计零偏温补系数3次项
    QString XAccelerometerComCoeff3FloatStr = ui->lineEdit_22->text();
//    float XAccelerometerComCoeff3f = XAccelerometerComCoeff3FloatStr.toFloat();
//    quint32 XAccelerometerComCoeff3uint32 =*(quint32 *)&XAccelerometerComCoeff3f;

    TempUnion.floatValue = XAccelerometerComCoeff3FloatStr.toFloat();
    quint32 XAccelerometerComCoeff3uint32 = TempUnion.quint32Value;
    QString XAccelerometerComCoeff3float_hex = QString("%1").arg(XAccelerometerComCoeff3uint32, 8, 16, QLatin1Char('0'));
    QString XAccelerometerComCoeff3dataStr = XAccelerometerComCoeff3float_hex.mid(6,2)+" "+XAccelerometerComCoeff3float_hex.mid(4,2)+" "+XAccelerometerComCoeff3float_hex.mid(2,2)+" "+XAccelerometerComCoeff3float_hex.mid(0,2)+" ";
    int XAccelerometerComCoeff3CheckSumInt = XAccelerometerComCoeff3float_hex.mid(6,2).toInt(nullptr,16) + XAccelerometerComCoeff3float_hex.mid(4,2).toInt(nullptr,16)+XAccelerometerComCoeff3float_hex.mid(2,2).toInt(nullptr,16)+XAccelerometerComCoeff3float_hex.mid(0,2).toInt(nullptr,16);

    //Y加计零偏温补系数3次项
    QString YAccelerometerComCoeff3FloatStr = ui->lineEdit_23->text();
    //    float YAccelerometerComCoeff3f = YAccelerometerComCoeff3FloatStr.toFloat();
    //    quint32 YAccelerometerComCoeff3uint32 =*(quint32 *)&YAccelerometerComCoeff3f;

    TempUnion.floatValue = YAccelerometerComCoeff3FloatStr.toFloat();
    quint32 YAccelerometerComCoeff3uint32 = TempUnion.quint32Value;
    QString YAccelerometerComCoeff3float_hex = QString("%1").arg(YAccelerometerComCoeff3uint32, 8, 16, QLatin1Char('0'));
    QString YAccelerometerComCoeff3dataStr = YAccelerometerComCoeff3float_hex.mid(6,2)+" "+YAccelerometerComCoeff3float_hex.mid(4,2)+" "+YAccelerometerComCoeff3float_hex.mid(2,2)+" "+YAccelerometerComCoeff3float_hex.mid(0,2)+" ";
    int YAccelerometerComCoeff3CheckSumInt = YAccelerometerComCoeff3float_hex.mid(6,2).toInt(nullptr,16) + YAccelerometerComCoeff3float_hex.mid(4,2).toInt(nullptr,16)+YAccelerometerComCoeff3float_hex.mid(2,2).toInt(nullptr,16)+YAccelerometerComCoeff3float_hex.mid(0,2).toInt(nullptr,16);

    //Z加计零偏温补系数3次项
    QString ZAccelerometerComCoeff3FloatStr = ui->lineEdit_24->text();
//    float ZAccelerometerComCoeff3f = ZAccelerometerComCoeff3FloatStr.toFloat();
//    quint32 ZAccelerometerComCoeff3uint32 =*(quint32 *)&ZAccelerometerComCoeff3f;

    TempUnion.floatValue = ZAccelerometerComCoeff3FloatStr.toFloat();
    quint32 ZAccelerometerComCoeff3uint32 = TempUnion.quint32Value;
    QString ZAccelerometerComCoeff3float_hex = QString("%1").arg(ZAccelerometerComCoeff3uint32, 8, 16, QLatin1Char('0'));
    QString ZAccelerometerComCoeff3dataStr = ZAccelerometerComCoeff3float_hex.mid(6,2)+" "+ZAccelerometerComCoeff3float_hex.mid(4,2)+" "+ZAccelerometerComCoeff3float_hex.mid(2,2)+" "+ZAccelerometerComCoeff3float_hex.mid(0,2)+" ";
    int ZAccelerometerComCoeff3CheckSumInt = ZAccelerometerComCoeff3float_hex.mid(6,2).toInt(nullptr,16) + ZAccelerometerComCoeff3float_hex.mid(4,2).toInt(nullptr,16)+ZAccelerometerComCoeff3float_hex.mid(2,2).toInt(nullptr,16)+ZAccelerometerComCoeff3float_hex.mid(0,2).toInt(nullptr,16);



    //校验和
    int SdataCheckSum = XAccelerometerComCoeff0CheckSumInt +XAccelerometerComCoeff1CheckSumInt + XAccelerometerComCoeff2CheckSumInt+XAccelerometerComCoeff3CheckSumInt+YAccelerometerComCoeff0CheckSumInt +YAccelerometerComCoeff1CheckSumInt + YAccelerometerComCoeff2CheckSumInt+YAccelerometerComCoeff3CheckSumInt+ZAccelerometerComCoeff0CheckSumInt +ZAccelerometerComCoeff1CheckSumInt + ZAccelerometerComCoeff2CheckSumInt+ZAccelerometerComCoeff3CheckSumInt+14;

    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);

    QString  SdataStr= "EB 90 0E "+XAccelerometerComCoeff0dataStr+YAccelerometerComCoeff0dataStr+ZAccelerometerComCoeff0dataStr+XAccelerometerComCoeff1dataStr+YAccelerometerComCoeff1dataStr+ZAccelerometerComCoeff1dataStr+XAccelerometerComCoeff2dataStr+YAccelerometerComCoeff2dataStr+ZAccelerometerComCoeff2dataStr+XAccelerometerComCoeff3dataStr+YAccelerometerComCoeff3dataStr+ZAccelerometerComCoeff3dataStr+SdataCheckSumHexStr;

    Sdata = HexStringToByteArray(SdataStr);


    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("装订加速度计温补系数：") + tr("X加速度计零偏温度0次项=")+ QString::number(XAccelerometerComCoeff0FloatStr.toFloat (),'f',2)
                                                + tr(" Y加速度计零偏温度0次项=")+ QString::number(YAccelerometerComCoeff0FloatStr.toFloat (),'f',2)
                                                + tr(" Z加速度计零偏温度0次项=")+ QString::number(ZAccelerometerComCoeff0FloatStr.toFloat (),'f',2)
                                                + tr(" X加速度计零偏温度1次项=")+ QString::number(XAccelerometerComCoeff1FloatStr.toFloat (),'f',2)
                                                + tr(" Y加速度计零偏温度1次项=")+ QString::number(YAccelerometerComCoeff1FloatStr.toFloat (),'f',2)
                                                + tr(" Z加速度计零偏温度1次项=")+ QString::number(ZAccelerometerComCoeff1FloatStr.toFloat (),'f',2)
                                                + tr(" X加速度计零偏温度2次项=")+ QString::number(XAccelerometerComCoeff2FloatStr.toFloat (),'f',2)
                                                + tr(" Y加速度计零偏温度2次项=")+ QString::number(YAccelerometerComCoeff2FloatStr.toFloat (),'f',2)
                                                + tr(" Z加速度计零偏温度2次项=")+ QString::number(ZAccelerometerComCoeff2FloatStr.toFloat (),'f',2)
                                                + tr(" X加速度计零偏温度3次项=")+ QString::number(XAccelerometerComCoeff3FloatStr.toFloat (),'f',2)
                                                + tr(" Y加速度计零偏温度3次项=")+ QString::number(YAccelerometerComCoeff3FloatStr.toFloat (),'f',2)
                                                + tr(" Z加速度计零偏温度3次项=")+ QString::number(ZAccelerometerComCoeff3FloatStr.toFloat (),'f',2)
                                                +"\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);


    emit AccelerometerComCoeffCMD(Sdata);
}


void TempCompenCoeffDialog::on_pushButton_3_clicked()
{
    this->close();
}
