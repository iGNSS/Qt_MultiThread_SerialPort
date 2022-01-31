#include "leverarmdialog.h"
#include "ui_leverarmdialog.h"
#include "qmath.h"
#include "common.h"
#include <QTime>
LeverArmDialog::LeverArmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeverArmDialog)
{
    ui->setupUi(this);
}

LeverArmDialog::~LeverArmDialog()
{
    delete ui;
}

void LeverArmDialog::on_pushButton_clicked()
{

    QByteArray Sdata;
    //X1(GPS1)
    QString X1GPS1FloatStr = ui->lineEdit->text();
    double X1GPS1f = X1GPS1FloatStr.toDouble() * qPow(10,2);
    quint16 X1GPS1uint32 = qRound(X1GPS1f);
    QString X1GPS1float_str = QString::number(X1GPS1uint32,16);
    QString X1GPS1float_hex = X1GPS1float_str.rightJustified(4,QLatin1Char('0'));
    QString X1GPS1dataStr = X1GPS1float_hex.mid(2,2)+" "+X1GPS1float_hex.mid(0,2)+" ";
    int X1GPS1CheckSumInt = X1GPS1float_hex.mid(2,2).toInt(nullptr,16)+X1GPS1float_hex.mid(0,2).toInt(nullptr,16);

    //Y1(GPS1)
    QString Y1GPS1FloatStr = ui->lineEdit_2->text();
    double Y1GPS1f = Y1GPS1FloatStr.toDouble() * qPow(10,2);
    quint16  Y1GPS1uint32 = qRound64(Y1GPS1f);
    QString Y1GPS1float_str = QString::number(Y1GPS1uint32,16);
    QString Y1GPS1float_hex = Y1GPS1float_str.rightJustified(4,QLatin1Char('0'));
    QString Y1GPS1dataStr = Y1GPS1float_hex.mid(2,2)+" "+Y1GPS1float_hex.mid(0,2)+" ";
    int Y1GPS1CheckSumInt = Y1GPS1float_hex.mid(2,2).toInt(nullptr,16)+Y1GPS1float_hex.mid(0,2).toInt(nullptr,16);

    //Z1(GPS1)
    QString Z1GPS1FloatStr = ui->lineEdit_3->text();
    double Z1GPS1f = Z1GPS1FloatStr.toDouble() * qPow(10,2);
    quint16  Z1GPS1uint32 = qRound64(Z1GPS1f);
    QString Z1GPS1float_str = QString::number(Z1GPS1uint32,16);
    QString Z1GPS1float_hex = Z1GPS1float_str.rightJustified(4,QLatin1Char('0'));
    QString Z1GPS1dataStr = Z1GPS1float_hex.mid(2,2)+" "+Z1GPS1float_hex.mid(0,2)+" ";
    int Z1GPS1CheckSumInt = Z1GPS1float_hex.mid(2,2).toInt(nullptr,16)+Z1GPS1float_hex.mid(0,2).toInt(nullptr,16);


    //X2(GPS2)
    QString X2GPS2FloatStr = ui->lineEdit_4->text();
    double X2GPS2f = X2GPS2FloatStr.toDouble() * qPow(10,2);
    quint16  X2GPS2uint32 = qRound64(X2GPS2f);
    QString X2GPS2float_str = QString::number(X2GPS2uint32,16);
    QString X2GPS2float_hex = X2GPS2float_str.rightJustified(4,QLatin1Char('0'));
    QString X2GPS2dataStr = X2GPS2float_hex.mid(2,2)+" "+X2GPS2float_hex.mid(0,2)+" ";
    int X2GPS2CheckSumInt = X2GPS2float_hex.mid(2,2).toInt(nullptr,16)+X2GPS2float_hex.mid(0,2).toInt(nullptr,16);

    //Y2(GPS2)
    QString Y2GPS2FloatStr = ui->lineEdit_5->text();
    double Y2GPS2f = Y2GPS2FloatStr.toDouble() * qPow(10,2);
    quint16  Y2GPS2uint32 = qRound64(Y2GPS2f);
    QString Y2GPS2float_str = QString::number(Y2GPS2uint32,16);
    QString Y2GPS2float_hex = Y2GPS2float_str.rightJustified(4,QLatin1Char('0'));
    QString Y2GPS2dataStr = Y2GPS2float_hex.mid(2,2)+" "+Y2GPS2float_hex.mid(0,2)+" ";
    int Y2GPS2CheckSumInt = Y2GPS2float_hex.mid(2,2).toInt(nullptr,16)+Y2GPS2float_hex.mid(0,2).toInt(nullptr,16);

    //Z2(GPS2)
    QString Z2GPS2FloatStr = ui->lineEdit_6->text();
    double Z2GPS2f = Z2GPS2FloatStr.toDouble() * qPow(10,2);
    quint16  Z2GPS2uint32 = qRound64(Z2GPS2f);
    QString Z2GPS2float_str = QString::number(Z2GPS2uint32,16);
    QString Z2GPS2float_hex = Z2GPS2float_str.rightJustified(4,QLatin1Char('0'));
    QString Z2GPS2dataStr = Z2GPS2float_hex.mid(2,2)+" "+Z2GPS2float_hex.mid(0,2)+" ";
    int Z2GPS2CheckSumInt = Z2GPS2float_hex.mid(2,2).toInt(nullptr,16)+Z2GPS2float_hex.mid(0,2).toInt(nullptr,16);

    //X3(DOPPLER)
    QString X3DOPPLERFloatStr = ui->lineEdit_7->text();
    double X3DOPPLERf = X3DOPPLERFloatStr.toDouble() * qPow(10,2);
    quint16  X3DOPPLERuint32 = qRound64(X3DOPPLERf);
    QString X3DOPPLERfloat_str = QString::number(X3DOPPLERuint32,16);
    QString X3DOPPLERfloat_hex = X3DOPPLERfloat_str.rightJustified(4,QLatin1Char('0'));
    QString X3DOPPLERdataStr = X3DOPPLERfloat_hex.mid(2,2)+" "+X3DOPPLERfloat_hex.mid(0,2)+" ";
    int X3DOPPLERCheckSumInt = X3DOPPLERfloat_hex.mid(2,2).toInt(nullptr,16)+X3DOPPLERfloat_hex.mid(0,2).toInt(nullptr,16);

    //Y3(DOPPLER)
    QString Y3DOPPLERFloatStr = ui->lineEdit_8->text();
    double Y3DOPPLERf = Y3DOPPLERFloatStr.toDouble() * qPow(10,2);
    quint16  Y3DOPPLERuint32 = qRound64(Y3DOPPLERf);
    QString Y3DOPPLERfloat_str = QString::number(Y3DOPPLERuint32,16);
    QString Y3DOPPLERfloat_hex = Y3DOPPLERfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Y3DOPPLERdataStr = Y3DOPPLERfloat_hex.mid(2,2)+" "+Y3DOPPLERfloat_hex.mid(0,2)+" ";
    int Y3DOPPLERCheckSumInt = Y3DOPPLERfloat_hex.mid(2,2).toInt(nullptr,16)+Y3DOPPLERfloat_hex.mid(0,2).toInt(nullptr,16);

    //Z3(DOPPLER)
    QString Z3DOPPLERFloatStr = ui->lineEdit_9->text();
    double Z3DOPPLERf = Z3DOPPLERFloatStr.toDouble() * qPow(10,2);
    quint16  Z3DOPPLERuint32 = qRound64(Z3DOPPLERf);
    QString Z3DOPPLERfloat_str = QString::number(Z3DOPPLERuint32,16);
    QString Z3DOPPLERfloat_hex = Z3DOPPLERfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Z3DOPPLERdataStr = Z3DOPPLERfloat_hex.mid(2,2)+" "+Z3DOPPLERfloat_hex.mid(0,2)+" ";
    int Z3DOPPLERCheckSumInt = Z3DOPPLERfloat_hex.mid(2,2).toInt(nullptr,16)+Z3DOPPLERfloat_hex.mid(0,2).toInt(nullptr,16);

    //X4(LOG_EM)
    QString X4LOG_EMFloatStr = ui->lineEdit_16->text();
    double X4LOG_EMf = X4LOG_EMFloatStr.toDouble() * qPow(10,2);
    quint16  X4LOG_EMuint32 = qRound64(X4LOG_EMf);
    QString X4LOG_EMfloat_str = QString::number(X4LOG_EMuint32,16);
    QString X4LOG_EMfloat_hex = X4LOG_EMfloat_str.rightJustified(4,QLatin1Char('0'));
    QString X4LOG_EMdataStr = X4LOG_EMfloat_hex.mid(2,2)+" "+X4LOG_EMfloat_hex.mid(0,2)+" ";
    int X4LOG_EMCheckSumInt = X4LOG_EMfloat_hex.mid(2,2).toInt(nullptr,16)+X4LOG_EMfloat_hex.mid(0,2).toInt(nullptr,16);

    //Y4(LOG_EM)
    QString Y4LOG_EMFloatStr = ui->lineEdit_17->text();
    double Y4LOG_EMf = Y4LOG_EMFloatStr.toDouble() * qPow(10,2);
    quint16  Y4LOG_EMuint32 = qRound64(Y4LOG_EMf);
    QString Y4LOG_EMfloat_str = QString::number(Y4LOG_EMuint32,16);
    QString Y4LOG_EMfloat_hex = Y4LOG_EMfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Y4LOG_EMdataStr = Y4LOG_EMfloat_hex.mid(2,2)+" "+Y4LOG_EMfloat_hex.mid(0,2)+" ";
    int Y4LOG_EMCheckSumInt = Y4LOG_EMfloat_hex.mid(2,2).toInt(nullptr,16)+Y4LOG_EMfloat_hex.mid(0,2).toInt(nullptr,16);

    //Z4(LOG_EM)
    QString Z4LOG_EMFloatStr = ui->lineEdit_18->text();
    double Z4LOG_EMf = Z4LOG_EMFloatStr.toDouble() * qPow(10,2);
    quint16  Z4LOG_EMuint32 = qRound64(Z4LOG_EMf);
    QString Z4LOG_EMfloat_str = QString::number(Z4LOG_EMuint32,16);
    QString Z4LOG_EMfloat_hex = Z4LOG_EMfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Z4LOG_EMdataStr = Z4LOG_EMfloat_hex.mid(2,2)+" "+Z4LOG_EMfloat_hex.mid(0,2)+" ";
    int Z4LOG_EMCheckSumInt = Z4LOG_EMfloat_hex.mid(2,2).toInt(nullptr,16)+Z4LOG_EMfloat_hex.mid(0,2).toInt(nullptr,16);

    //X5(MAIN_INS)
    QString X5MAIN_INSFloatStr = ui->lineEdit_13->text();
    double X5MAIN_INSf = X5MAIN_INSFloatStr.toDouble() * qPow(10,2);
    quint16  X5MAIN_INSuint32 = qRound64(X5MAIN_INSf);
    QString X5MAIN_INSfloat_str = QString::number(X5MAIN_INSuint32,16);
    QString X5MAIN_INSfloat_hex = X5MAIN_INSfloat_str.rightJustified(4,QLatin1Char('0'));
    QString X5MAIN_INSdataStr = X5MAIN_INSfloat_hex.mid(2,2)+" "+X5MAIN_INSfloat_hex.mid(0,2)+" ";
    int X5MAIN_INSCheckSumInt = X5MAIN_INSfloat_hex.mid(2,2).toInt(nullptr,16)+X5MAIN_INSfloat_hex.mid(0,2).toInt(nullptr,16);

    //Y5(MAIN_INS)
    QString Y5MAIN_INSFloatStr = ui->lineEdit_14->text();
    double Y5MAIN_INSf = Y5MAIN_INSFloatStr.toDouble() * qPow(10,2);
    quint16  Y5MAIN_INSuint32 = qRound64(Y5MAIN_INSf);
    QString Y5MAIN_INSfloat_str = QString::number(Y5MAIN_INSuint32,16);
    QString Y5MAIN_INSfloat_hex = Y5MAIN_INSfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Y5MAIN_INSdataStr = Y5MAIN_INSfloat_hex.mid(2,2)+" "+Y5MAIN_INSfloat_hex.mid(0,2)+" ";
    int Y5MAIN_INSCheckSumInt = Y5MAIN_INSfloat_hex.mid(2,2).toInt(nullptr,16)+Y5MAIN_INSfloat_hex.mid(0,2).toInt(nullptr,16);

    //Z5(MAIN_INS)
    QString Z5MAIN_INSFloatStr = ui->lineEdit_15->text();
    double Z5MAIN_INSf = Z5MAIN_INSFloatStr.toDouble() * qPow(10,2);
    quint16  Z5MAIN_INSuint32 = qRound64(Z5MAIN_INSf);
    QString Z5MAIN_INSfloat_str = QString::number(Z5MAIN_INSuint32,16);
    QString Z5MAIN_INSfloat_hex = Z5MAIN_INSfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Z5MAIN_INSdataStr = Z5MAIN_INSfloat_hex.mid(2,2)+" "+Z5MAIN_INSfloat_hex.mid(0,2)+" ";
    int Z5MAIN_INSCheckSumInt = Z5MAIN_INSfloat_hex.mid(2,2).toInt(nullptr,16)+Z5MAIN_INSfloat_hex.mid(0,2).toInt(nullptr,16);

    //X6(ACC)
    QString X6ACCFloatStr = ui->lineEdit_10->text();
    double X6ACCf = X6ACCFloatStr.toDouble() * qPow(10,2);
    quint16  X6ACCuint32 = qRound64(X6ACCf);
    QString X6ACCfloat_str = QString::number(X6ACCuint32,16);
    QString X6ACCfloat_hex = X6ACCfloat_str.rightJustified(4,QLatin1Char('0'));
    QString X6ACCdataStr = X6ACCfloat_hex.mid(2,2)+" "+X6ACCfloat_hex.mid(0,2)+" ";
    int X6ACCCheckSumInt = X6ACCfloat_hex.mid(2,2).toInt(nullptr,16)+X6ACCfloat_hex.mid(0,2).toInt(nullptr,16);

    //Y6(ACC)
    QString Y6ACCFloatStr = ui->lineEdit_11->text();
    double Y6ACCf = Y6ACCFloatStr.toDouble() * qPow(10,2);
    quint16  Y6ACCuint32 = qRound64(Y6ACCf);
    QString Y6ACCfloat_str = QString::number(Y6ACCuint32,16);
    QString Y6ACCfloat_hex = Y6ACCfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Y6ACCdataStr = Y6ACCfloat_hex.mid(2,2)+" "+Y6ACCfloat_hex.mid(0,2)+" ";
    int Y6ACCCheckSumInt = Y6ACCfloat_hex.mid(2,2).toInt(nullptr,16)+Y6ACCfloat_hex.mid(0,2).toInt(nullptr,16);

    //Z6(ACC)
    QString Z6ACCFloatStr = ui->lineEdit_12->text();
    double Z6ACCf = Z6ACCFloatStr.toDouble() * qPow(10,2);
    quint16  Z6ACCuint32 = qRound64(Z6ACCf);
    QString Z6ACCfloat_str = QString::number(Z6ACCuint32,16);
    QString Z6ACCfloat_hex = Z6ACCfloat_str.rightJustified(4,QLatin1Char('0'));
    QString Z6ACCdataStr = Z6ACCfloat_hex.mid(2,2)+" "+Z6ACCfloat_hex.mid(0,2)+" ";
    int Z6ACCCheckSumInt = Z6ACCfloat_hex.mid(2,2).toInt(nullptr,16)+Z6ACCfloat_hex.mid(0,2).toInt(nullptr,16);

    //校验和
    int SdataCheckSum = Z6ACCCheckSumInt +Y6ACCCheckSumInt + X6ACCCheckSumInt+Z5MAIN_INSCheckSumInt+Y5MAIN_INSCheckSumInt+X5MAIN_INSCheckSumInt+Z4LOG_EMCheckSumInt+Y4LOG_EMCheckSumInt+X4LOG_EMCheckSumInt+Z3DOPPLERCheckSumInt+Y3DOPPLERCheckSumInt
            +X3DOPPLERCheckSumInt+Z2GPS2CheckSumInt+Y2GPS2CheckSumInt+X2GPS2CheckSumInt+X1GPS1CheckSumInt+Y1GPS1CheckSumInt+Z1GPS1CheckSumInt+12;

    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);

    QString  SdataStr= "EB 90 0C "+X1GPS1dataStr+Y1GPS1dataStr+Z1GPS1dataStr+X2GPS2dataStr+Y2GPS2dataStr+Z2GPS2dataStr+X3DOPPLERdataStr+Y3DOPPLERdataStr+Z3DOPPLERdataStr
                        + X4LOG_EMdataStr+Y4LOG_EMdataStr+Z4LOG_EMdataStr+X5MAIN_INSdataStr+Y5MAIN_INSdataStr+Z5MAIN_INSdataStr+X6ACCdataStr+Y6ACCdataStr+Z6ACCdataStr
                        + SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订杆臂数据：") + tr("X1(GPS1)=")+ QString::number(X1GPS1FloatStr.toDouble(),'f',2)
                                                 + tr(" Y1(GPS1)=")+ QString::number(Y1GPS1FloatStr.toDouble(),'f',2)
                                                 + tr(" Z1(GPS1)=")+ QString::number(Z1GPS1FloatStr.toDouble(),'f',2)
                                                 + tr(" X2(GPS2)=")+ QString::number(X2GPS2FloatStr.toDouble(),'f',2)
                                                 + tr(" Y2(GPS2)=")+ QString::number(Y2GPS2FloatStr.toDouble(),'f',2)
                                                 + tr(" Z2(GPS2)=")+ QString::number(Z2GPS2FloatStr.toDouble(),'f',2)
                                                 + tr(" X3(DOPPLER)=")+ QString::number(X3DOPPLERFloatStr.toDouble(),'f',2)
                                                 + tr(" Y3(DOPPLER)=")+ QString::number(Y3DOPPLERFloatStr.toDouble(),'f',2)
                                                 + tr(" Z3(DOPPLER)=")+ QString::number(Z3DOPPLERFloatStr.toDouble(),'f',2)
                                                 + tr(" X4(LOG_EM)=")+ QString::number(X4LOG_EMFloatStr.toDouble(),'f',2)
                                                 + tr(" Y4(LOG_EM)=")+ QString::number(Y4LOG_EMFloatStr.toDouble(),'f',2)
                                                 + tr(" Z4(LOG_EM)=")+ QString::number(Z4LOG_EMFloatStr.toDouble(),'f',2)
                                                 + tr(" X5(MAIN_INS)=")+ QString::number(X5MAIN_INSFloatStr.toDouble(),'f',2)
                                                 + tr(" Y5(MAIN_INS)=")+ QString::number(Y5MAIN_INSFloatStr.toDouble(),'f',2)
                                                 + tr(" Z5(MAIN_INS)=")+ QString::number(Z5MAIN_INSFloatStr.toDouble(),'f',2)
                                                 + tr(" X6(ACC)=")+ QString::number(X6ACCFloatStr.toDouble(),'f',2)
                                                 + tr(" Y6(ACC)=")+ QString::number(Y6ACCFloatStr.toDouble(),'f',2)
                                                 + tr(" Z6(ACC)=")+ QString::number(Z6ACCFloatStr.toDouble(),'f',2)
                                                 +"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit leverArmDataCMD(Sdata);
}

void LeverArmDialog::on_pushButton_2_clicked()
{
    this->close();
}
