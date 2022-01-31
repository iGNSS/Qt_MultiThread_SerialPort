#include "querydialog.h"
#include "ui_querydialog.h"
#include <QByteArray>
#include <QTime>
QueryDialog::QueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
}

QueryDialog::~QueryDialog()
{
    delete ui;
}

void QueryDialog::on_pushButton_7_clicked()
{
    this->close();
}

void QueryDialog::on_pushButton_clicked()
{
    QByteArray data;
    if(ui->comboBox->currentText() == "准备")
    {
         data = QByteArray::fromHex("EB900F010010");

    }
    else if(ui->comboBox->currentText() == "自对准")
    {
         data = QByteArray::fromHex("EB900F010111");

    }
    else if(ui->comboBox->currentText() == "传递对准")
    {
         data = QByteArray::fromHex("EB900F010212");

    }
    else if(ui->comboBox->currentText() == "罗经对准")
    {
         data = QByteArray::fromHex("EB900F010313");

    }
    else if(ui->comboBox->currentText() == "自主导航/无阻尼")
    {
         data = QByteArray::fromHex("EB900F010414");

    }
    else if(ui->comboBox->currentText() == "自主导航/水平阻尼")
    {
         data = QByteArray::fromHex("EB900F011424");

    }
    else if(ui->comboBox->currentText() == "自主导航/全阻尼")
    {
         data = QByteArray::fromHex("EB900F012434");

    }
    else if(ui->comboBox->currentText() == "罗经导航")
    {
         data = QByteArray::fromHex("EB900F010515");

    }
    else if(ui->comboBox->currentText() == "组合导航")
    {
         data = QByteArray::fromHex("EB900F010616");

    }
    else if(ui->comboBox->currentText() == "在舰标定")
    {
         data = QByteArray::fromHex("EB900F010717");

    }
    else if(ui->comboBox->currentText() == "组合校准")
    {
         data = QByteArray::fromHex("EB900F012838");

    }

    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("导航状态=")+ ui->comboBox->currentText() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);

    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_2_clicked()
{
    QByteArray data;
    if(ui->comboBox_2->currentText() == "码头")
    {
         data = QByteArray::fromHex("EB900F020011");

    }
    else if(ui->comboBox_2->currentText() == "海上")
    {
         data = QByteArray::fromHex("EB900F024051");

    }

    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("工作地点=")+ ui->comboBox_2->currentText() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);

    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_3_clicked()
{
    QByteArray data;
    if(ui->comboBox_3->currentText() == "自动")
    {
         data = QByteArray::fromHex("EB900F030012");

    }
    else if(ui->comboBox_3->currentText() == "手动")
    {
         data = QByteArray::fromHex("EB900F038092");

    }
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("操作模式=")+ ui->comboBox_3->currentText() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_4_clicked()
{
    QByteArray data;
    if(ui->comboBox_4->currentText() == "XYZ")
    {
         data = QByteArray::fromHex("EB900F041023");

    }
    else if(ui->comboBox_4->currentText() == "Y-XZ")
    {
         data = QByteArray::fromHex("EB900F041124");

    }
    else if(ui->comboBox_4->currentText() == "-X-YZ")
    {
         data = QByteArray::fromHex("EB900F041225");

    }
    else if(ui->comboBox_4->currentText() == "-YXZ")
    {
         data = QByteArray::fromHex("EB900F041326");

    }
    else if(ui->comboBox_4->currentText() == "-XY-Z")
    {
         data = QByteArray::fromHex("EB900F042033");

    }
    else if(ui->comboBox_4->currentText() == "-Y-X-Z")
    {
         data = QByteArray::fromHex("EB900F042134");

    }
    else if(ui->comboBox_4->currentText() == "X-Y-Z")
    {
         data = QByteArray::fromHex("EB900F042235");

    }
    else if(ui->comboBox_4->currentText() == "YX-Z")
    {
         data = QByteArray::fromHex("EB900F042336");

    }
    else if(ui->comboBox_4->currentText() == "XZ-Y")
    {
         data = QByteArray::fromHex("EB900F043043");

    }
    else if(ui->comboBox_4->currentText() == "YZX")
    {
         data = QByteArray::fromHex("EB900F043144");

    }
    else if(ui->comboBox_4->currentText() == "-XZY")
    {
         data = QByteArray::fromHex("EB900F043245");

    }
    else if(ui->comboBox_4->currentText() == "-YZ-X")
    {
         data = QByteArray::fromHex("EB900F043346");

    }
    else if(ui->comboBox_4->currentText() == "X-ZY")
    {
         data = QByteArray::fromHex("EB900F044053");

    }
    else if(ui->comboBox_4->currentText() == "Y-Z-X")
    {
         data = QByteArray::fromHex("EB900F044154");

    }
    else if(ui->comboBox_4->currentText() == "-X-Z-Y")
    {
         data = QByteArray::fromHex("EB900F044255");

    }
    else if(ui->comboBox_4->currentText() == "-Y-ZX")
    {
         data = QByteArray::fromHex("EB900F044356");

    }
    else if(ui->comboBox_4->currentText() == "ZY-X")
    {
         data = QByteArray::fromHex("EB900F045063");

    }
    else if(ui->comboBox_4->currentText() == "Z-X-Y")
    {
         data = QByteArray::fromHex("EB900F045164");

    }
    else if(ui->comboBox_4->currentText() == "Z-YX")
    {
         data = QByteArray::fromHex("EB900F045265");

    }
    else if(ui->comboBox_4->currentText() == "ZXY")
    {
         data = QByteArray::fromHex("EB900F045366");

    }
    else if(ui->comboBox_4->currentText() == "-ZYX")
    {
         data = QByteArray::fromHex("EB900F046073");

    }
    else if(ui->comboBox_4->currentText() == "-Z-XY")
    {
         data = QByteArray::fromHex("EB900F046174");

    }
    else if(ui->comboBox_4->currentText() == "-Z-Y-X")
    {
         data = QByteArray::fromHex("EB900F046275");

    }
    else if(ui->comboBox_4->currentText() == "-ZX-Y")
    {
         data = QByteArray::fromHex("EB900F046376");

    }
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("坐标系切换=")+ ui->comboBox_4->currentText() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_5_clicked()
{
    QByteArray data;
    if(ui->comboBox_5->currentText() == "经纬度")
    {
         data = QByteArray::fromHex("EB900FAAA15A");

    }
    else if(ui->comboBox_5->currentText() == "航向")
    {
         data = QByteArray::fromHex("EB900FAAA25B");

    }
    else if(ui->comboBox_5->currentText() == "速度")
    {
         data = QByteArray::fromHex("EB900FAAA35C");

    }
    else if(ui->comboBox_5->currentText() == "系统编号")
    {
         data = QByteArray::fromHex("EB900FAAA45D");

    }
    else if(ui->comboBox_5->currentText() == "在舰位置")
    {
         data = QByteArray::fromHex("EB900FAAA55E");

    }
    else if(ui->comboBox_5->currentText() == "IP地址")
    {
         data = QByteArray::fromHex("EB900FAAA65F");

    }
    else if(ui->comboBox_5->currentText() == "陀螺标定参数")
    {
         data = QByteArray::fromHex("EB900FAAA760");

    }
    else if(ui->comboBox_5->currentText() == "加速度计标定参数")
    {
         data = QByteArray::fromHex("EB900FAAA861");

    }
    else if(ui->comboBox_5->currentText() == "等效零偏")
    {
         data = QByteArray::fromHex("EB900FAAA962");

    }
    else if(ui->comboBox_5->currentText() == "X-Y-Z")
    {
         data = QByteArray::fromHex("EB900F042235");

    }
    else if(ui->comboBox_5->currentText() == "系统姿态零位")
    {
         data = QByteArray::fromHex("EB900FAAAA63");

    }
    else if(ui->comboBox_5->currentText() == "惯组和输出零位")
    {
         data = QByteArray::fromHex("EB900FAAAB64");

    }
    else if(ui->comboBox_5->currentText() == "杆臂")
    {
         data = QByteArray::fromHex("EB900FAAAC65");

    }
    else if(ui->comboBox_5->currentText() == "陀螺零偏温补系数")
    {
         data = QByteArray::fromHex("EB900FAAAD66");

    }
    else if(ui->comboBox_5->currentText() == "加表零位温补系数")
    {
         data = QByteArray::fromHex("EB900FAAAE67");
    }
    else if(ui->comboBox_5->currentText() == "高度")
    {
         data = QByteArray::fromHex("EB900FAAAF68");
    }
    else if(ui->comboBox_5->currentText() == "基准重力")
    {
         data = QByteArray::fromHex("EB900FAAA053");
    }
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("参数查询=")+ ui->comboBox_5->currentText() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);

}

void QueryDialog::on_pushButton_6_clicked()
{
    QByteArray data = QByteArray::fromHex("EB900F6666DB");
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("FLASH烧写") + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);
}
