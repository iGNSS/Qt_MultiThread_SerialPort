#include "sysheightdialog.h"
#include "ui_sysheightdialog.h"
#include "common.h"
sysHeightDialog::sysHeightDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sysHeightDialog)
{
    ui->setupUi(this);
}

sysHeightDialog::~sysHeightDialog()
{
    delete ui;
}

void sysHeightDialog::on_pushButton_clicked()
{
    QByteArray Sdata;

    QString sysHeightStr = ui->lineEdit->text();
    double sysHeightf = sysHeightStr.toDouble() * qPow(2,32) / 1000.0;
    quint32 sysHeightUint32 = qRound64(sysHeightf);
    //qint64 i = *((qint64 *)&f);
    QString sysHeight_str = QString::number(sysHeightUint32,16);
    QString sysHeight_hex = sysHeight_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString sysHeightDisStr = sysHeight_hex.mid(6,2)+" "+sysHeight_hex.mid(4,2)+" "+sysHeight_hex.mid(2,2)+" "+sysHeight_hex.mid(0,2)+" ";

    int sysHeightCheckSumInt = sysHeight_hex.mid(6,2).toInt(nullptr,16) + sysHeight_hex.mid(4,2).toInt(nullptr,16)+sysHeight_hex.mid(2,2).toInt(nullptr,16)+sysHeight_hex.mid(0,2).toInt(nullptr,16) +2;

    QString SdataCheckSumHexStr= QString::number(sysHeightCheckSumInt,16).right(2);

    QString  SdataStr= "EB 90 07 "+sysHeightDisStr+SdataCheckSumHexStr;

    Sdata = HexStringToByteArray(SdataStr);

    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("装订系统高度数据：") + tr("系统高度=")+ QString::number(sysHeightStr.toFloat(),'f',2)+"\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);

    emit sysHeightDataCMD(Sdata);
}

void sysHeightDialog::on_pushButton_2_clicked()
{
    this->close();
}
