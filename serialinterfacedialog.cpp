#include "serialinterfacedialog.h"
#include "ui_serialinterfacedialog.h"
#include "common.h"
SerialInterfaceDialog::SerialInterfaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialInterfaceDialog)
{
    ui->setupUi(this);
}

SerialInterfaceDialog::~SerialInterfaceDialog()
{
    delete ui;
}

void SerialInterfaceDialog::on_pushButton_2_clicked()
{
    this->close();
}

void SerialInterfaceDialog::on_pushButton_clicked()
{
    QByteArray Sdata;
    QString byte3;
    QString byte4;
    QString byte5;
    int byte5int = 0;
    QString byte6;
    QString dataStr;
    int SerialInterFaceCheckSum = 0;
    if(ui->comboBox->currentText() == "COMA" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "01";

    }
    else if(ui->comboBox->currentText() == "COMB" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "02";

    }
    else if(ui->comboBox->currentText() == "COMC" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "04";

    }
    else if(ui->comboBox->currentText() == "COMD" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "08";

    }
    else if(ui->comboBox->currentText() == "COME" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "10";

    }
    else if(ui->comboBox->currentText() == "COMF" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "20";

    }
    else if(ui->comboBox->currentText() == "COMG" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "40";

    }
    else if(ui->comboBox->currentText() == "COMA" && ui->comboBox_4->currentText() == "发送")
    {
         byte3 = "81";

    }
    else if(ui->comboBox->currentText() == "COMB" && ui->comboBox_4->currentText() == "接收")
    {
         byte3 = "82";

    }
    else if(ui->comboBox->currentText() == "COMC" && ui->comboBox_4->currentText() == "接收")
    {
         byte3 = "84";

    }
    else if(ui->comboBox->currentText() == "COMD" && ui->comboBox_4->currentText() == "接收")
    {
         byte3 = "88";

    }
    else if(ui->comboBox->currentText() == "COME" && ui->comboBox_4->currentText() == "接收")
    {
         byte3 = "90";

    }
    else if(ui->comboBox->currentText() == "COMF" && ui->comboBox_4->currentText() == "接收")
    {
         byte3 = "A0";

    }
    else if(ui->comboBox->currentText() == "COMG" && ui->comboBox_4->currentText() == "接收")
    {
         byte3 = "C0";

    }

    if(ui->comboBox_2->currentText() == "2400")
    {
         byte4 = "00";
    }
    else if(ui->comboBox_2->currentText() == "4800")
    {
         byte4 = "01";
    }
    else if(ui->comboBox_2->currentText() == "9600")
    {
         byte4 = "02";
    }
    else if(ui->comboBox_2->currentText() == "19200")
    {
         byte4 = "03";
    }
    else if(ui->comboBox_2->currentText() == "38400")
    {
         byte4 = "04";
    }
    else if(ui->comboBox_2->currentText() == "57600")
    {
         byte4 = "05";
    }
    else if(ui->comboBox_2->currentText() == "115200")
    {
         byte4 = "06";
    }
    else if(ui->comboBox_2->currentText() == "230400")
    {
         byte4 = "07";
    }
    else if(ui->comboBox_2->currentText() == "384000")
    {
         byte4 = "08";
    }
    else if(ui->comboBox_2->currentText() == "460800")
    {
         byte4 = "09";
    }

    if(ui->comboBox_6->currentText() == "使能发送")
    {
         byte5int = byte5int+1;

    }
    else if(ui->comboBox_6->currentText() == "禁止发送")
    {
         byte5int = byte5int+0;
    }

    if(ui->comboBox_7->currentText() == "2位停止位")
    {
         byte5int = byte5int+2;

    }
    else if(ui->comboBox_7->currentText() == "1位停止位")
    {
         byte5int = byte5int+0;
    }
    if(ui->comboBox_3->currentText() == "奇校验")
    {
         byte5int = byte5int+4;

    }
    else if(ui->comboBox_3->currentText() == "偶校验")
    {
         byte5int = byte5int+0;
    }
    if(ui->comboBox_8->currentText() == "使能奇偶校验")
    {
         byte5int = byte5int+8;

    }
    else if(ui->comboBox_8->currentText() == "偶校验")
    {
         byte5int = byte5int+0;
    }
    byte5 = QString::number(byte5int,16).rightJustified(2,QLatin1Char('0'));

    if(ui->comboBox_5->currentText() == "发送脉冲数")
    {
         byte6 = "00";

    }
    else if(ui->comboBox_5->currentText() == "发送导航数据")
    {
         byte6 = "01";
    }
    SerialInterFaceCheckSum = byte3.toInt(nullptr,16) + byte4.toInt(nullptr,16) +byte5.toInt(nullptr,16) + byte6.toInt(nullptr,16) + 16;
    QString SdataCheckSumHexStr = QString::number(SerialInterFaceCheckSum,16).right(2);
    dataStr = "EB 90 10 "+byte3+" "+byte4 + " " + byte5 + " " +byte6+" "+ SdataCheckSumHexStr;
    Sdata = HexStringToByteArray(dataStr);
    emit serialInterCMD(Sdata);
}

