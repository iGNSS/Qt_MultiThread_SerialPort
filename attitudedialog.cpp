#include "attitudedialog.h"
#include "ui_attitudedialog.h"
#include <qmath.h>
#include "common.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTime>
AttitudeDialog::AttitudeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttitudeDialog)
{
    ui->setupUi(this);
    QWidget::setTabOrder(ui->lineEdit,ui->lineEdit_2);
    QWidget::setTabOrder(ui->lineEdit_2,ui->lineEdit_3);
    QWidget::setTabOrder(ui->lineEdit_3,ui->lineEdit_4);
    QWidget::setTabOrder(ui->lineEdit_4,ui->lineEdit_5);
    QWidget::setTabOrder(ui->lineEdit_5,ui->lineEdit_6);
    QWidget::setTabOrder(ui->lineEdit_6,ui->lineEdit_7);
    QWidget::setTabOrder(ui->lineEdit_7,ui->lineEdit_8);
    QWidget::setTabOrder(ui->lineEdit_8,ui->lineEdit_9);

    }

AttitudeDialog::~AttitudeDialog()
{
    delete ui;
}

void AttitudeDialog::on_pushButton_3_clicked()
{
    this->close();
}

void AttitudeDialog::on_pushButton_clicked()
{
    QByteArray Sdata;

    //横摇角零位
    QString rollAngleFloatStr = ui->lineEdit->text();
    double rollAnglef = rollAngleFloatStr.toDouble() * qPow(2,31) / 90.0;
    quint32 rollAngleuint32 = qRound64(rollAnglef);
    QString rollAnglefloat_str = QString::number(rollAngleuint32,16);
    QString rollAnglefloat_hex = rollAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString rollAngledataStr = rollAnglefloat_hex.mid(6,2)+" "+rollAnglefloat_hex.mid(4,2)+" "+rollAnglefloat_hex.mid(2,2)+" "+rollAnglefloat_hex.mid(0,2)+" ";
    int rollAngleCheckSumInt = rollAnglefloat_hex.mid(6,2).toInt(nullptr,16) + rollAnglefloat_hex.mid(4,2).toInt(nullptr,16)+rollAnglefloat_hex.mid(2,2).toInt(nullptr,16)+rollAnglefloat_hex.mid(0,2).toInt(nullptr,16);


    //纵摇角零位
    QString pitchAngleFloatStr = ui->lineEdit_2->text();
    double pitchAnglef = pitchAngleFloatStr.toDouble() * qPow(2,31) / 90.0;
    quint32 pitchAngleuint32 = qRound64(pitchAnglef);
    QString pitchAnglefloat_str = QString::number(pitchAngleuint32,16);
    QString pitchAnglefloat_hex = pitchAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString pitchAngledataStr = pitchAnglefloat_hex.mid(6,2)+" "+pitchAnglefloat_hex.mid(4,2)+" "+pitchAnglefloat_hex.mid(2,2)+" "+pitchAnglefloat_hex.mid(0,2)+" ";
    int pitchAngleCheckSumInt = pitchAnglefloat_hex.mid(6,2).toInt(nullptr,16) + pitchAnglefloat_hex.mid(4,2).toInt(nullptr,16)+pitchAnglefloat_hex.mid(2,2).toInt(nullptr,16)+pitchAnglefloat_hex.mid(0,2).toInt(nullptr,16);


    //航向零位
    QString headingAngleFloatStr = ui->lineEdit_3->text();
    double headingAnglef = headingAngleFloatStr.toDouble() * qPow(2,31) / 180.0;
    quint32 headingAngleuint32 = qRound64(headingAnglef);
    QString headingAnglefloat_str = QString::number(headingAngleuint32,16);
    QString headingAnglefloat_hex = headingAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString headingAngledataStr = headingAnglefloat_hex.mid(6,2)+" "+headingAnglefloat_hex.mid(4,2)+" "+headingAnglefloat_hex.mid(2,2)+" "+headingAnglefloat_hex.mid(0,2)+" ";
    int headingAngleCheckSumInt = headingAnglefloat_hex.mid(6,2).toInt(nullptr,16) + headingAnglefloat_hex.mid(4,2).toInt(nullptr,16)+headingAnglefloat_hex.mid(2,2).toInt(nullptr,16)+headingAnglefloat_hex.mid(0,2).toInt(nullptr,16);


    //校验和
    int SdataCheckSum = rollAngleCheckSumInt +pitchAngleCheckSumInt + headingAngleCheckSumInt+10;

    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);

    QString  SdataStr= "EB 90 0A "+rollAngledataStr+pitchAngledataStr+headingAngledataStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订姿态零位：") + tr("横摇角零位=")+ QString::number(rollAngleFloatStr.toDouble(),'f',2)+tr(" 纵摇角零位=")+ QString::number(pitchAngleFloatStr.toDouble(),'f',2)+tr(" 航向零位=")+ QString::number(headingAngleFloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit attitudeDataCMD(Sdata);

}

void AttitudeDialog::on_pushButton_2_clicked()
{

    QByteArray Sdata;

    //惯组横摇角零位
    QString IMUrollAngleFloatStr = ui->lineEdit_4->text();
    double IMUrollAnglef = IMUrollAngleFloatStr.toDouble() * qPow(2,31) / 90.0;
    quint32 IMUrollAngleuint32 = qRound64(IMUrollAnglef);
    QString IMUrollAnglefloat_str = QString::number(IMUrollAngleuint32,16);
    QString IMUrollAnglefloat_hex = IMUrollAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString IMUrollAngledataStr = IMUrollAnglefloat_hex.mid(6,2)+" "+IMUrollAnglefloat_hex.mid(4,2)+" "+IMUrollAnglefloat_hex.mid(2,2)+" "+IMUrollAnglefloat_hex.mid(0,2)+" ";
    int IMUrollAngleCheckSumInt = IMUrollAnglefloat_hex.mid(6,2).toInt(nullptr,16) + IMUrollAnglefloat_hex.mid(4,2).toInt(nullptr,16)+IMUrollAnglefloat_hex.mid(2,2).toInt(nullptr,16)+IMUrollAnglefloat_hex.mid(0,2).toInt(nullptr,16);


    //惯组纵摇角零位
    QString IMUpitchAngleFloatStr = ui->lineEdit_5->text();
    double IMUpitchAnglef = IMUpitchAngleFloatStr.toDouble() * qPow(2,31) / 90.0;
    quint32 IMUpitchAngleuint32 = qRound64(IMUpitchAnglef);
    QString IMUpitchAnglefloat_str = QString::number(IMUpitchAngleuint32,16);
    QString IMUpitchAnglefloat_hex = IMUpitchAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString IMUpitchAngledataStr = IMUpitchAnglefloat_hex.mid(6,2)+" "+IMUpitchAnglefloat_hex.mid(4,2)+" "+IMUpitchAnglefloat_hex.mid(2,2)+" "+IMUpitchAnglefloat_hex.mid(0,2)+" ";
    int IMUpitchAngleCheckSumInt = IMUpitchAnglefloat_hex.mid(6,2).toInt(nullptr,16) + IMUpitchAnglefloat_hex.mid(4,2).toInt(nullptr,16)+IMUpitchAnglefloat_hex.mid(2,2).toInt(nullptr,16)+IMUpitchAnglefloat_hex.mid(0,2).toInt(nullptr,16);


    //惯组航向角零位
    QString IMUheadingAngleFloatStr = ui->lineEdit_6->text();
    double IMUheadingAnglef = IMUheadingAngleFloatStr.toDouble() * qPow(2,31) / 180.0;
    quint32 IMUheadingAngleuint32 = qRound64(IMUheadingAnglef);
    QString IMUheadingAnglefloat_str = QString::number(IMUheadingAngleuint32,16);
    QString IMUheadingAnglefloat_hex = IMUheadingAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString IMUheadingAngledataStr = IMUheadingAnglefloat_hex.mid(6,2)+" "+IMUheadingAnglefloat_hex.mid(4,2)+" "+IMUheadingAnglefloat_hex.mid(2,2)+" "+IMUheadingAnglefloat_hex.mid(0,2)+" ";
    int IMUheadingAngleCheckSumInt = IMUheadingAnglefloat_hex.mid(6,2).toInt(nullptr,16) + IMUheadingAnglefloat_hex.mid(4,2).toInt(nullptr,16)+IMUheadingAnglefloat_hex.mid(2,2).toInt(nullptr,16)+IMUheadingAnglefloat_hex.mid(0,2).toInt(nullptr,16);

    //输出横摇角零位
    QString outputRollAngleFloatStr = ui->lineEdit_7->text();
    double outputRollAnglef = outputRollAngleFloatStr.toDouble() * qPow(2,31) / 90.0;
    quint32 outputRollAngleuint32 = qRound64(outputRollAnglef);
    QString outputRollAnglefloat_str = QString::number(outputRollAngleuint32,16);
    QString outputRollAnglefloat_hex = outputRollAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString outputRollAngledataStr = outputRollAnglefloat_hex.mid(6,2)+" "+outputRollAnglefloat_hex.mid(4,2)+" "+outputRollAnglefloat_hex.mid(2,2)+" "+outputRollAnglefloat_hex.mid(0,2)+" ";
    int outputRollAngleCheckSumInt = outputRollAnglefloat_hex.mid(6,2).toInt(nullptr,16) + outputRollAnglefloat_hex.mid(4,2).toInt(nullptr,16)+outputRollAnglefloat_hex.mid(2,2).toInt(nullptr,16)+outputRollAnglefloat_hex.mid(0,2).toInt(nullptr,16);


    //输出纵摇角零位
    QString outputPitchAngleFloatStr = ui->lineEdit_8->text();
    double outputPitchAnglef = outputPitchAngleFloatStr.toDouble() * qPow(2,31) / 90.0;
    quint32 outputPitchAngleuint32 = qRound64(outputPitchAnglef);
    QString outputPitchAnglefloat_str = QString::number(outputPitchAngleuint32,16);
    QString outputPitchAnglefloat_hex = outputPitchAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString outputPitchAngledataStr = outputPitchAnglefloat_hex.mid(6,2)+" "+outputPitchAnglefloat_hex.mid(4,2)+" "+outputPitchAnglefloat_hex.mid(2,2)+" "+outputPitchAnglefloat_hex.mid(0,2)+" ";
    int outputPitchAngleCheckSumInt = outputPitchAnglefloat_hex.mid(6,2).toInt(nullptr,16) + outputPitchAnglefloat_hex.mid(4,2).toInt(nullptr,16)+outputPitchAnglefloat_hex.mid(2,2).toInt(nullptr,16)+outputPitchAnglefloat_hex.mid(0,2).toInt(nullptr,16);


    //输出航向角零位
    QString outputHeadingAngleFloatStr = ui->lineEdit_9->text();
    double outputHeadingAnglef = outputHeadingAngleFloatStr.toDouble() * qPow(2,31) / 180.0;
    quint32 outputHeadingAngleuint32 = qRound64(outputHeadingAnglef);
    QString outputHeadingAnglefloat_str = QString::number(outputHeadingAngleuint32,16);
    QString outputHeadingAnglefloat_hex = outputHeadingAnglefloat_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString outputHeadingAngledataStr = outputHeadingAnglefloat_hex.mid(6,2)+" "+outputHeadingAnglefloat_hex.mid(4,2)+" "+outputHeadingAnglefloat_hex.mid(2,2)+" "+outputHeadingAnglefloat_hex.mid(0,2)+" ";
    int outputHeadingAngleCheckSumInt = outputHeadingAnglefloat_hex.mid(6,2).toInt(nullptr,16) + outputHeadingAnglefloat_hex.mid(4,2).toInt(nullptr,16)+outputHeadingAnglefloat_hex.mid(2,2).toInt(nullptr,16)+outputHeadingAnglefloat_hex.mid(0,2).toInt(nullptr,16);



    //校验和
    int SdataCheckSum = IMUrollAngleCheckSumInt +IMUpitchAngleCheckSumInt + IMUheadingAngleCheckSumInt+outputRollAngleCheckSumInt+outputPitchAngleCheckSumInt+outputHeadingAngleCheckSumInt+11;

    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);

    QString  SdataStr= "EB 90 0B "+IMUrollAngledataStr+IMUpitchAngledataStr+IMUheadingAngledataStr+SdataCheckSumHexStr +outputRollAngledataStr + outputPitchAngledataStr + outputHeadingAngledataStr + SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订惯组和输出姿态零位：") + tr("惯组横摇角零位=")+ QString::number(IMUrollAngleFloatStr.toDouble(),'f',2)+tr(" 惯组纵摇角零位=")+ QString::number(IMUpitchAngleFloatStr.toDouble(),'f',2)+tr(" 惯组航向角零位=")+ QString::number(IMUheadingAngleFloatStr.toDouble(),'f',2)+tr(" 输出横摇角零位=")+ QString::number(outputRollAngleFloatStr.toDouble(),'f',2)+tr(" 输出纵摇角零位=")+ QString::number(outputPitchAngleFloatStr.toDouble(),'f',2)+tr(" 输出航向角零位=")+QString::number(outputHeadingAngleFloatStr.toDouble(),'f',2)+"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;


    emit attitudeDataCMD(Sdata);
    emit bookLogCMD(sendBookDataStr);
}
