#include "sysbasegdialog.h"
#include "ui_sysbasegdialog.h"
#include "common.h"
sysBaseGDialog::sysBaseGDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sysBaseGDialog)
{
    ui->setupUi(this);
}

sysBaseGDialog::~sysBaseGDialog()
{
    delete ui;
}

void sysBaseGDialog::on_pushButton_clicked()
{
    QByteArray Sdata;

    QString sysBaseGStr = ui->lineEdit->text();
    double sysBaseGf = sysBaseGStr.toDouble() * qPow(10,12);
    quint64 sysBaseGUint64 = qRound64(sysBaseGf);
    //qint64 i = *((qint64 *)&f);
    QString sysBaseG_str = QString::number(sysBaseGUint64,16);
    QString sysBaseG_hex = sysBaseG_str.rightJustified(16,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString sysBaseGDisStr = sysBaseG_hex.mid(14,2)+" "+sysBaseG_hex.mid(12,2)+" "+sysBaseG_hex.mid(10,2)+" "+sysBaseG_hex.mid(8,2)+" "+ sysBaseG_hex.mid(6,2)+" "+sysBaseG_hex.mid(4,2)+" "+sysBaseG_hex.mid(2,2)+" "+sysBaseG_hex.mid(0,2)+" ";

    int sysBaseGCheckSumInt = sysBaseG_hex.mid(14,2).toInt(nullptr,16) + sysBaseG_hex.mid(12,2).toInt(nullptr,16)+sysBaseG_hex.mid(10,2).toInt(nullptr,16)+sysBaseG_hex.mid(8,2).toInt(nullptr,16) + sysBaseG_hex.mid(6,2).toInt(nullptr,16) + sysBaseG_hex.mid(4,2).toInt(nullptr,16)+sysBaseG_hex.mid(2,2).toInt(nullptr,16)+sysBaseG_hex.mid(0,2).toInt(nullptr,16) +2;

    QString SdataCheckSumHexStr= QString::number(sysBaseGCheckSumInt,16).right(2);

    QString  SdataStr= "EB 90 08 "+sysBaseGDisStr+SdataCheckSumHexStr;

    Sdata = HexStringToByteArray(SdataStr);

    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("装订系统基准重力：") + tr("系统基准重力=")+ QString::number(sysBaseGStr.toFloat(),'f',2)+"\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);

    emit sysBaseGDataCMD(Sdata);
}

void sysBaseGDialog::on_pushButton_2_clicked()
{
    this->close();
}
