#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialworker.h"

#define addDataPeri  1000
#define drawDataPeri 1000
#define handleResultDelay  200



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_xLength(0),SaveFileRecord(400000),dataInvaildRecord(0),isDegree(1),latitude(0),C1latitudeCurveRun(0),headingAngle(0),C1headingAngleRun(0),longitude(0),C1longitudeRun(0),rollAngle(0),C1rollAngleRun(0),pitchAngle(0),C1pitchAngleRun(0),northSpeed(0),C1northSpeedRun(0),eastSpeed(0),C1eastSpeedRun(0),headingAngularSpeed(0),C1headingAngularSpeedRun(0),rollAngleSpeed(0),C1rollAngleSpeedRun(0),pitchAngleSpeed(0),C1pitchAngleSpeedRun(0),
      heave(0),C1heaveRun(0),verticalVelocity(0),C1verticalVelocityRun(0),sway(0),C1swayRun(0),transverseVelocity(0),C1transverseVelocityRun(0),surge(0),C1surgeRun(0),longitudinalVelocity(0),C1longitudinalVelocityRun(0),C5XGyroAngleIncreaseFloat(0),C5XGyroAngleIncreaseFloatRun(0),C5YGyroAngleIncreaseFloat(0),C5YGyroAngleIncreaseFloatRun(0),C5ZGyroAngleIncreaseFloat(0),C5ZGyroAngleIncreaseFloatRun(0),
      C5XAccelerometerSpeedIncrementFloat(0),C5XAccelerometerSpeedIncrementFloatRun(0),C5YAccelerometerSpeedIncrementFloat(0),C5YAccelerometerSpeedIncrementFloatRun(0),C5ZAccelerometerSpeedIncrementFloat(0),C5ZAccelerometerSpeedIncrementFloatRun(0),
      C5XgyroCompensatedAngleIncrementFloat(0),C5XgyroCompensatedAngleIncrementFloatRun(0),C5YgyroCompensatedAngleIncrementFloat(0),C5YgyroCompensatedAngleIncrementFloatRun(0),C5ZgyroCompensatedAngleIncrementFloat(0),C5ZgyroCompensatedAngleIncrementFloatRun(0),
      C5XAccVelocityIncrementFloat(0),C5XAccVelocityIncrementFloatRun(0),C5YAccVelocityIncrementFloat(0),C5YAccVelocityIncrementFloatRun(0),C5ZAccVelocityIncrementFloat(0),C5ZAccVelocityIncrementFloatRun(0),
      C5XgyroDifFrequency(0),C5XgyroDifFrequencyRun(0),C5YgyroDifFrequency(0),C5YgyroDifFrequencyRun(0),C5ZgyroDifFrequency(0),C5ZgyroDifFrequencyRun(0),
      C5XaccelerometerDifFre(0),C5XaccelerometerDifFreRun(0),C5YaccelerometerDifFre(0),C5YaccelerometerDifFreRun(0),C5ZaccelerometerDifFre(0),C5ZaccelerometerDifFreRun(0),
      C5XgyroTemp1(0),C5XgyroTemp1Run(0),C5YgyroTemp1(0),C5YgyroTemp1Run(0),C5ZgyroTemp1(0),C5ZgyroTemp1Run(0),
      C5XAccelerometerTemperture(0),C5XAccelerometerTempertureRun(0),C5YAccelerometerTemperture(0),C5YAccelerometerTempertureRun(0),C5ZAccelerometerTemperture(0),C5ZAccelerometerTempertureRun(0),
      C5XgyroTemp2(0),C5XgyroTemp2Run(0),C5YgyroTemp2(0),C5YgyroTemp2Run(0),C5ZgyroTemp2(0),C5ZgyroTemp2Run(0),
      C5XgyroAmplitudeJitter(0),C5XgyroAmplitudeJitterRun(0),C5YgyroAmplitudeJitter(0),C5YgyroAmplitudeJitterRun(0),C5ZgyroAmplitudeJitter(0),C5ZgyroAmplitudeJitterRun(0),
      C5XgyroAmpl1itudeFre(0),C5XgyroAmpl1itudeFreRun(0),C5YgyroAmpl1itudeFre(0),C5YgyroAmpl1itudeFreRun(0),C5ZgyroAmpl1itudeFre(0),C5ZgyroAmpl1itudeFreRun(0),
      C3longitude(0),C3longitudeRun(0),C3GPSlatitude(0),C3GPSlatitudeRun(0),
      C3togetherSpeed(0),C3togetherSpeedRun(0),C3headingAngle(0),C3headingAngleRun(0),C3combinedEastSpeed(0),C3combinedEastSpeedRun(0),C3combinedNorthSpeed(0),C3combinedNorthSpeedRun(0),
      C3waterX(0),C3waterXRun(0),C3waterY(0),C3waterYRun(0),C3bottomX(0),C3bottomXRun(0),C3bottomY(0),C3bottomYRun(0),C3electromagnetismSpeed(0),C3electromagnetismSpeedRun(0),C6UndampedRollAngleFloatRun(0),C6UndampedPitchAngleFloatRun(0),C6UndampedHeadingAngularFloatRun(0),C6UndampedNorthSpeedFloatRun(0),C6UndampedEastSpeedFloatRun(0),C6VerticalVelocityFloatRun(0),C6UndampedLatFloatRun(0),C6UndampedLongFloatRun(0),C6UndampedHeightFloatRun(0),
      C6XGroyFloat(0),C6XGroyFloatRun(0),C6YGroyFloat(0),C6YGroyFloatRun(0),C6ZGroyFloat(0),C6ZGroyFloatRun(0),C6XAccelerometerFloat(0),C6XAccelerometerFloatRun(0),C6YAccelerometerFloat(0),C6YAccelerometerFloatRun(0),C6ZAccelerometerFloat(0),C6ZAccelerometerFloatRun(0),
      eastSpeedError(0),eastSpeedErrorRun(0),northSpeedError(0),northSpeedErrorRun(0),togetherSpeedError(0),togetherSpeedErrorRun(0),latitudeError(0),latitudeErrorRun(0),longitudeError(0),longitudeErrorRun(0),positionError(0),positionErrorRun(0),nonMessage(0)

{
    ui->setupUi(this);
    this->setLED1(ui->label_69,1,15);
    ui->lineEdit_7->setStyleSheet( " color:blue; " );
    ui->lineEdit_8->setStyleSheet( " color:blue; " );
    ui->lineEdit_9->setStyleSheet( " color:blue; " );
    ui->lineEdit_10->setStyleSheet( " color:blue; " );
    ui->lineEdit_11->setStyleSheet( " color:blue; " );
    ui->lineEdit_12->setStyleSheet( " color:blue; " );
    ui->lineEdit_13->setStyleSheet( " color:blue; " );
    ui->lineEdit_14->setStyleSheet( " color:blue; " );
    ui->lineEdit_15->setStyleSheet( " color:blue; " );
    ui->lineEdit_16->setStyleSheet( " color:blue; " );
    ui->lineEdit_17->setStyleSheet( " color:blue; " );
    ui->lineEdit_18->setStyleSheet( " color:blue; " );
    ui->lineEdit_19->setStyleSheet( " color:blue; " );
    ui->lineEdit_20->setStyleSheet( " color:blue; " );
    ui->lineEdit_21->setStyleSheet( " color:blue; " );
    ui->lineEdit_22->setStyleSheet( " color:blue; " );
    ui->lineEdit_23->setStyleSheet( " color:blue; " );
    ui->customPlot2->showTracer(true);
    ui->customPlot3->showTracer(true);
    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if (!dir.exists("./curve"))
    {
        bool res = dir.mkpath("./curve");
        if(!res)
        {
            QMessageBox::warning(NULL, "提示", "创建曲线文件夹失败！");
        }
    }

    // 检查目录是否存在，若不存在则新建
    QDir dir2;
    if (!dir2.exists("./history"))
    {
        bool res = dir2.mkpath("./history");
        if(!res)
        {
            QMessageBox::warning(NULL, "提示", "创建历史数据文件夹失败！");
            return;
        }
    }

    paraQuery = new QueryDialog(this);              //状态切换
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    paraQuery->setWindowFlags(flags);
    //paraQuery->setFixedSize(350,380);

    bookOriData = new BookOriDataDialog(this);      //原始数据
    bookOriData->setWindowFlags(flags);
    //bookOriData->setFixedSize(300,320);

    attitudeData = new AttitudeDialog(this);        //姿态零位

    attitudeData->setWindowFlags(flags);
    //attitudeData->setFixedSize(400,180);

    shipLoadData = new ShopLoadDialog(this);            //装舰参数
    shipLoadData->setWindowFlags(flags);
    //shipLoadData->setFixedSize(280,220);

    calbratParaData = new CalibratParaDialog(this);     //标定参数
    calbratParaData->setWindowFlags(flags);
    //calbratParaData->setFixedSize(650,420);

    tempCompenCoeffData = new TempCompenCoeffDialog(this);     //温补系数
    tempCompenCoeffData->setWindowFlags(flags);
    //tempCompenCoeffData->setFixedSize(635,265);

    leverArmData = new LeverArmDialog(this);     //杆臂装订
    leverArmData->setWindowFlags(flags);
    //leverArmData->setFixedSize(390,265);

    serialInterfaceData = new SerialInterfaceDialog(this);     //串口接口装订,暂时不需要实现
    serialInterfaceData->setWindowFlags(flags);
    //serialInterfaceData->setFixedSize(337,220);

    sysHeightData = new sysHeightDialog(this);     //系统高度装订
    sysHeightData->setWindowFlags(flags);

    sysBaseGData = new sysBaseGDialog(this);
    sysBaseGData->setWindowFlags(flags);

    //this->resize(QSize(1195,720));
    qtime = new QTimer(this);
    qtime->setInterval(50);

    qGetdataTime = new QTimer(this);
    qGetdataTime->setInterval(addDataPeri);

    qDrawTime = new QTimer(this);
    qDrawTime->setInterval(drawDataPeri);

    //serial_1->setQueryMode(QextSerialPort::EventDriven);
    if(1)
    {
        ui->tableWidget->setStyleSheet("QTableWidget{background-color.rgb(200,200,200)}");
        ui->tableWidget->verticalHeader()->setVisible(true);
        ui->tableWidget->horizontalHeader()->setVisible(true);

        ui->tableWidget->setColumnWidth(0, 125);
        ui->tableWidget->setColumnWidth(1, 125);
        ui->tableWidget->setColumnWidth(2, 125);
        ui->tableWidget->setColumnWidth(3, 125);
        ui->tableWidget->setColumnWidth(4, 125);
        ui->tableWidget->setColumnWidth(5, 125);
        ui->tableWidget->setColumnWidth(6, 125);
        ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_2->horizontalHeader()->setDefaultSectionSize(139);
        ui->tableWidget_3->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_3->horizontalHeader()->setDefaultSectionSize(102);
        ui->tableWidget_4->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_4->horizontalHeader()->setDefaultSectionSize(117);
        ui->tableWidget_6->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_6->horizontalHeader()->setDefaultSectionSize(167);
        ui->tableWidget_7->verticalHeader()->setDefaultSectionSize(24);
        ui->tableWidget_7->horizontalHeader()->setDefaultSectionSize(140);

        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       // ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_8->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableWidget_9->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableWidget_10->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableWidget_11->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableWidget_12->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableWidget_13->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ui->checkBox->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_2->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_3->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_4->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_5->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_6->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_7->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_8->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_9->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_10->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_11->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_12->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_13->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_14->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_15->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_16->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_17->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_18->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_19->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_20->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_21->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_22->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_23->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_24->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_25->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_26->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_27->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_28->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_29->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_31->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_30->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_32->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_33->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_34->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_37->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_35->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_36->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_40->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_38->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_39->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_42->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_43->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_41->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_45->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_46->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_44->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_48->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_49->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_47->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_51->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_54->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_50->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_52->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_53->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_60->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");

        ui->checkBox_59->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_56->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_57->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_55->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_58->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

        ui->checkBox_61->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_63->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_62->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_65->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_64->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_66->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_67->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_69->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_68->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_70->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");
        ui->checkBox_72->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");
        ui->checkBox_71->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

        ui->checkBox_73->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_74->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_75->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

        ui->checkBox_76->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");
        ui->checkBox_77->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_78->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

        ui->checkBox_79->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");
        ui->checkBox_80->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");
        ui->checkBox_81->setStyleSheet("QCheckBox{color:rgb(0,0,255)}");
    }


    InitSerialPortName();

#ifdef SERIALPORT
    // 1.新建串口处理子线程
    SerialWorker *serialWorker = new SerialWorker(&serial_1);
    serialWorker->moveToThread(&serialThread_1);
    //2.连接信号和槽

    //线程结束，自动删除对象
    connect(&serialThread_1, &QThread::finished,serialWorker, &QObject::deleteLater);


    // 状态切换装订和日志打印
    connect(paraQuery, &QueryDialog::statesChangeCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(paraQuery, &QueryDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 初始数据装订和日志打印
    connect(bookOriData, &BookOriDataDialog::OriDataCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(bookOriData, &BookOriDataDialog::bookLogCMD,this, &MainWindow::bookLog);


    // 姿态零位装订和日志打印
    connect(attitudeData, &AttitudeDialog::attitudeDataCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(attitudeData, &AttitudeDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 舰艇参数装订和日志打印
    connect(shipLoadData, &ShopLoadDialog::systemIDCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(shipLoadData, &ShopLoadDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 陀螺标定参数装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::GyroParaCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(calbratParaData, &CalibratParaDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 加速度计标定参数装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::AccelerometerParaCMD,serialWorker, &SerialWorker::doDataSendWork);

    // 陀螺等效零偏装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::GyroEqZeroBiasCMD,serialWorker, &SerialWorker::doDataSendWork);

    //陀螺温补系数装订和日志打印
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::GyroTempComCoeffCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::bookLogCMD,this, &MainWindow::bookLog);

    //加计温补系数装订和日志打印
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::AccelerometerComCoeffCMD,serialWorker, &SerialWorker::doDataSendWork);

    //杆臂装订和日志打印
    connect(leverArmData, &LeverArmDialog::leverArmDataCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(leverArmData, &LeverArmDialog::bookLogCMD,this, &MainWindow::bookLog);

    //串口接口装订
    connect(serialInterfaceData, &SerialInterfaceDialog::serialInterCMD,serialWorker, &SerialWorker::doDataSendWork);

    //系统高度装订和日志打印
    connect(sysHeightData, &sysHeightDialog::sysHeightDataCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(sysHeightData, &sysHeightDialog::bookLogCMD,this, &MainWindow::bookLog);

    //系统基准重力值装订和日志打印
    connect(sysBaseGData, &sysBaseGDialog::sysBaseGDataCMD,serialWorker, &SerialWorker::doDataSendWork);
    connect(sysBaseGData, &sysBaseGDialog::bookLogCMD,this, &MainWindow::bookLog);

    connect(&serial_1, &QSerialPort::readyRead, this, &MainWindow::startTimer); // 启动定时器延时，确保接收数据完整
    connect(qtime, SIGNAL(timeout()),serialWorker, SLOT(doDataReciveWork())); // 主线程通知子线程接收数据的信号
    connect(serialWorker,&SerialWorker::sendResultToGui,this,&MainWindow::handleResults);
    connect(qGetdataTime,SIGNAL(timeout()),this,SLOT(getCurveData()));   //每秒存储数据到向量
    connect(qDrawTime,SIGNAL(timeout()),this,SLOT(drawCurveLatitude()));   //每秒绘图

    // 3.开始运行子线程
    serialThread_1.start();                   // 线程开始运行

#endif

#ifdef QEXTSERIALPORT
    // 状态切换装订和日志打印
    connect(paraQuery, &QueryDialog::statesChangeCMD,this, &MainWindow::doDataSendWork);
    connect(paraQuery, &QueryDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 初始数据装订和日志打印
    connect(bookOriData, &BookOriDataDialog::OriDataCMD,this, &MainWindow::doDataSendWork);
    connect(bookOriData, &BookOriDataDialog::bookLogCMD,this, &MainWindow::bookLog);


    // 姿态零位装订和日志打印
    connect(attitudeData, &AttitudeDialog::attitudeDataCMD,this, &MainWindow::doDataSendWork);
    connect(attitudeData, &AttitudeDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 舰艇参数装订和日志打印
    connect(shipLoadData, &ShopLoadDialog::systemIDCMD,this, &MainWindow::doDataSendWork);
    connect(shipLoadData, &ShopLoadDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 陀螺标定参数装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::GyroParaCMD,this, &MainWindow::doDataSendWork);
    connect(calbratParaData, &CalibratParaDialog::bookLogCMD,this, &MainWindow::bookLog);

    // 加速度计标定参数装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::AccelerometerParaCMD,this, &MainWindow::doDataSendWork);

    // 陀螺等效零偏装订和日志打印
    connect(calbratParaData, &CalibratParaDialog::GyroEqZeroBiasCMD,this, &MainWindow::doDataSendWork);

    //陀螺温补系数装订和日志打印
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::GyroTempComCoeffCMD,this, &MainWindow::doDataSendWork);
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::bookLogCMD,this, &MainWindow::bookLog);

    //加计温补系数装订和日志打印
    connect(tempCompenCoeffData, &TempCompenCoeffDialog::AccelerometerComCoeffCMD,this, &MainWindow::doDataSendWork);

    //杆臂装订和日志打印
    connect(leverArmData, &LeverArmDialog::leverArmDataCMD,this, &MainWindow::doDataSendWork);
    connect(leverArmData, &LeverArmDialog::bookLogCMD,this, &MainWindow::bookLog);

    //系统高度装订和日志打印
    connect(sysHeightData, &sysHeightDialog::sysHeightDataCMD,this, &MainWindow::doDataSendWork);
    connect(sysHeightData, &sysHeightDialog::bookLogCMD,this, &MainWindow::bookLog);

    //系统基准重力值装订和日志打印
    connect(sysBaseGData, &sysBaseGDialog::sysBaseGDataCMD,this, &MainWindow::doDataSendWork);
    connect(sysBaseGData, &sysBaseGDialog::bookLogCMD,this, &MainWindow::bookLog);

    //串口接口装订
    connect(serialInterfaceData, &SerialInterfaceDialog::serialInterCMD,this, &MainWindow::doDataSendWork);



    //读取数据(采用定时器读取数据，不采用事件，方便移植到linux)
    connect(qtime,SIGNAL(timeout()),this,SLOT(handleResults()));
    connect(qGetdataTime,SIGNAL(timeout()),this,SLOT(getCurveData()));   //每秒存储数据到向量
    connect(qDrawTime,SIGNAL(timeout()),this,SLOT(drawCurveLatitude()));   //每秒绘图
#endif

    this->setStyleSheet("QMainWindow{color:rgb(200,200,200)}");
    init_darw2();
}

void MainWindow::getCurveData()
{
    C1Vlatitude.append(latitude);
    curveX.append(m_xLength);
    C1VheadingAngle.append(headingAngle);
    C1Vlongitude.append(longitude);
    C1VrollAngle.append(rollAngle);
    C1VpitchAngle.append(pitchAngle);
    C1VnorthSpeed.append(northSpeed);
    C1VeastSpeed.append(eastSpeed);

    C1VheadingAngularSpeed.append(headingAngularSpeed);
    C1VrollAngleSpeed.append(rollAngleSpeed);
    C1VpitchAngleSpeed.append(pitchAngleSpeed);

    C1Vheave.append(heave);
    C1VverticalVelocity.append(verticalVelocity);
    C1Vsway.append(sway);
    C1VtransverseVelocity.append(transverseVelocity);
    C1Vsurge.append(surge);
    C1VlongitudinalVelocity.append(longitudinalVelocity);

    if(0)//不显示增量和补偿增量2022-01-20
    {
        C5VXGyroAngleIncreaseFloat.append(C5XGyroAngleIncreaseFloat);
        C5VYGyroAngleIncreaseFloat.append(C5YGyroAngleIncreaseFloat);
        C5VZGyroAngleIncreaseFloat.append(C5ZGyroAngleIncreaseFloat);

        C5VXAccelerometerSpeedIncrementFloat.append(C5XAccelerometerSpeedIncrementFloat);
        C5VYAccelerometerSpeedIncrementFloat.append(C5YAccelerometerSpeedIncrementFloat);
        C5VZAccelerometerSpeedIncrementFloat.append(C5ZAccelerometerSpeedIncrementFloat);

        C5VXgyroCompensatedAngleIncrementFloat.append(C5XgyroCompensatedAngleIncrementFloat);
        C5VYgyroCompensatedAngleIncrementFloat.append(C5YgyroCompensatedAngleIncrementFloat);
        C5VZgyroCompensatedAngleIncrementFloat.append(C5ZgyroCompensatedAngleIncrementFloat);

        C5VXAccVelocityIncrementFloat.append(C5XAccVelocityIncrementFloat);
        C5VYAccVelocityIncrementFloat.append(C5YAccVelocityIncrementFloat);
        C5VZAccVelocityIncrementFloat.append(C5ZAccVelocityIncrementFloat);
    }
    if(0)//不显示差频（原始脉冲）2022-01-20
    {
        C5VXgyroDifFrequency.append(C5XgyroDifFrequency);
        C5VYgyroDifFrequency.append(C5YgyroDifFrequency);
        C5VZgyroDifFrequency.append(C5ZgyroDifFrequency);

        C5VXaccelerometerDifFre.append(C5XaccelerometerDifFre);
        C5VYaccelerometerDifFre.append(C5YaccelerometerDifFre);
        C5VZaccelerometerDifFre.append(C5ZaccelerometerDifFre);
    }
    C5VXgyroTemp1.append(C5XgyroTemp1);
    C5VYgyroTemp1.append(C5YgyroTemp1);
    C5VZgyroTemp1.append(C5ZgyroTemp1);

    C5VXAccelerometerTemperture.append(C5XAccelerometerTemperture);
    C5VYAccelerometerTemperture.append(C5YAccelerometerTemperture);
    C5VZAccelerometerTemperture.append(C5ZAccelerometerTemperture);

    C5VXgyroTemp2.append(C5XgyroTemp2);
    C5VYgyroTemp2.append(C5YgyroTemp2);
    C5VZgyroTemp2.append(C5ZgyroTemp2);

    C5VXgyroAmplitudeJitter.append(C5XgyroAmplitudeJitter);
    C5VYgyroAmplitudeJitter.append(C5YgyroAmplitudeJitter);
    C5VZgyroAmplitudeJitter.append(C5ZgyroAmplitudeJitter);

    C5VXgyroAmpl1itudeFre.append(C5XgyroAmpl1itudeFre);
    C5VYgyroAmpl1itudeFre.append(C5YgyroAmpl1itudeFre);
    C5VZgyroAmpl1itudeFre.append(C5ZgyroAmpl1itudeFre);

    C3Vlongitude.append(C3longitude);
    C3VGPSlatitude.append(C3GPSlatitude);
    C3VtogetherSpeed.append(C3togetherSpeed);
    C3VheadingAngle.append(C3headingAngle);
    C3VcombinedEastSpeed.append(C3combinedEastSpeed);
    C3VcombinedNorthSpeed.append(C3combinedNorthSpeed);

    C3VwaterX.append(C3waterX);
    C3VwaterY.append(C3waterY);
    C3VbottomX.append(C3bottomX);
    C3VbottomY.append(C3bottomY);

    C3VelectromagnetismSpeed.append(C3electromagnetismSpeed);

    C6VC6UndampedRollAngleFloat.append(C6UndampedRollAngleFloat);
    C6VC6UndampedPitchAngleFloat.append(C6UndampedPitchAngleFloat);
    C6VC6UndampedHeadingAngularFloat.append(C6UndampedHeadingAngularFloat);
    C6VC6UndampedNorthSpeedFloat.append(C6UndampedNorthSpeedFloat);
    C6VC6UndampedEastSpeedFloat.append(C6UndampedEastSpeedFloat);
    C6VC6VerticalVelocityFloat.append(C6VerticalVelocityFloat);
    C6VC6UndampedLatFloat.append(C6UndampedLatFloat);
    C6VC6UndampedLongFloat.append(C6UndampedLongFloat);
    C6VC6UndampedHeightFloat.append(C6UndampedHeightFloat);


        C6VC6XGroyFloat.append(C6XGroyFloat);
        C6VC6YGroyFloat.append(C6YGroyFloat);
        C6VC6ZGroyFloat.append(C6ZGroyFloat);
        C6VC6XAccelerometerFloat.append(C6XAccelerometerFloat);
        C6VC6YAccelerometerFloat.append(C6YAccelerometerFloat);
        C6VC6ZAccelerometerFloat.append(C6ZAccelerometerFloat);




    VeastSpeedError.append(eastSpeedError);
    VnorthSpeedError.append(northSpeedError);
    VtogetherSpeedError.append(togetherSpeedError);
    VlatitudeError.append(latitudeError);
    VlongitudeError.append(longitudeError);
    VpositionError.append(positionError);

    m_xLength++;
}

MainWindow::~MainWindow()
{
    delete qtime;
    qtime = NULL;
    delete qGetdataTime;
    qGetdataTime = NULL;
    delete qDrawTime;
    qDrawTime = NULL;
#ifdef SERIALPORT
    // 退出串口1子线程
    serialThread_1.quit();
    serialThread_1.wait();
#endif
    C1fileSave.close();
    C2fileSave.close();
    C3fileSave.close();
    C5fileSave.close();
    delete ui;
}

void MainWindow::startTimer()
{
    if(!qtime->isActive())
    {
        qtime->start(handleResultDelay);
    }
}

void MainWindow::drawCurveLatitude()
{

    QCustomPlot* customPlot = ui->customPlot2;

    /*************************************绘制C1纬度曲线****************************************/
    if(ui->checkBox->isChecked())
    {

        if(C1latitudeCurveRun == 0)
        {           
            QPen pen;
            C1latitudeGraphNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1latitudeGraphNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1latitudeGraphNum)->setData(curveX,C1Vlatitude);
            customPlot->graph(C1latitudeGraphNum)->rescaleAxes(true);                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            //customPlot->xAxis->setRange(0, curveX.size(), Qt::AlignLeft);
            customPlot->replot(QCustomPlot::rpQueuedReplot);

            C1latitudeCurveRun = 1;
            set_checkBox_1_2_73_74_75();

            //customPlot->graph(C1latitudeGraphNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
        }
        else
        {
           // customPlot->graph(C1latitudeGraphNum)->setVisible(true);
            customPlot->graph(C1latitudeGraphNum)->setData(curveX,C1Vlatitude);
             //customPlot->xAxis->setRange(key, m_nXlength, Qt::AlignRight);
             //customPlot->xAxis->setRange(0, curveX.size(), Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1latitudeCurveRun == 1)
        {
            C1latitudeCurveRun = 0;
            C1longitudeRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedLongFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
             ui->customPlot2->clearGraphs();
             //customPlot->xAxis->setRange(0, curveX.size(), Qt::AlignLeft);
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /*************************************绘制C1经度曲线****************************************/
    if(ui->checkBox_2->isChecked())
    {

        if(C1longitudeRun == 0)
        {

            QPen pen;
            C1longitudeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1longitudeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1longitudeNum)->setData(curveX,C1Vlongitude);
            customPlot->graph(C1longitudeNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1longitudeRun = 1;
            //customPlot->graph(C1longitudeNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_1_2_73_74_75();
        }
        else
        {
           // customPlot->graph(C1longitudeNum)->setVisible(true);
            customPlot->graph(C1longitudeNum)->setData(curveX,C1Vlongitude);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1longitudeRun == 1)
        {
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedLongFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /*************************************绘制C6无阻尼纬度曲线****************************************/
    if(ui->checkBox_73->isChecked())
    {

        if(C6UndampedLatFloatRun == 0)
        {

            QPen pen;
            C6UndampedLatFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C6UndampedLatFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedLatFloatNum)->setData(curveX,C6VC6UndampedLatFloat);
            customPlot->graph(C6UndampedLatFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedLatFloatRun = 1;
            //customPlot->graph(C6UndampedLatFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_1_2_73_74_75();
        }
        else
        {
           // customPlot->graph(C6UndampedLatFloatNum)->setVisible(true);
            customPlot->graph(C6UndampedLatFloatNum)->setData(curveX,C6VC6UndampedLatFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedLatFloatRun == 1)
        {
            C6UndampedLatFloatRun = 0;
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C6UndampedLongFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /*************************************绘制C6无阻尼经度曲线****************************************/
    if(ui->checkBox_74->isChecked())
    {

        if(C6UndampedLongFloatRun == 0)
        {

            QPen pen;
            C6UndampedLongFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C6UndampedLongFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedLongFloatNum)->setData(curveX,C6VC6UndampedLongFloat);
            customPlot->graph(C6UndampedLongFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedLongFloatRun = 1;
            //customPlot->graph(C6UndampedLongFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_1_2_73_74_75();
        }
        else
        {
           // customPlot->graph(C6UndampedLongFloatNum)->setVisible(true);
            customPlot->graph(C6UndampedLongFloatNum)->setData(curveX,C6VC6UndampedLongFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedLongFloatRun == 1)
        {
            C6UndampedLongFloatRun = 0;
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedHeightFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /*************************************绘制C6无阻尼高度曲线****************************************/
    if(ui->checkBox_75->isChecked())
    {

        if(C6UndampedHeightFloatRun == 0)
        {

            QPen pen;
            C6UndampedHeightFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C6UndampedHeightFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedHeightFloatNum)->setData(curveX,C6VC6UndampedHeightFloat);
            customPlot->graph(C6UndampedHeightFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            customPlot->xAxis->setRange(0, curveX.size()*1.2, Qt::AlignLeft);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedHeightFloatRun = 1;
            //customPlot->graph(C6UndampedHeightFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_1_2_73_74_75();
        }
        else
        {
           // customPlot->graph(C6UndampedHeightFloatNum)->setVisible(true);
            customPlot->graph(C6UndampedHeightFloatNum)->setData(curveX,C6VC6UndampedHeightFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedHeightFloatRun == 1)
        {
            C6UndampedHeightFloatRun = 0;
            C1longitudeRun = 0;
            C1latitudeCurveRun = 0;
            C6UndampedLatFloatRun = 0;
            C6UndampedLongFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }


     if(ui->checkBox_5->isChecked())
     {
         if(C1headingAngleRun == 0)
         {
             QPen pen;
             C1headingAngleNum = customPlot->graphCount();
             customPlot->addGraph();
             pen.setColor(QColor(0,143,122));
             customPlot->graph(C1headingAngleNum)->setPen(pen);
             customPlot->yAxis->setNumberPrecision(7);
             customPlot->graph(C1headingAngleNum)->setData(curveX,C1VheadingAngle);
             customPlot->graph(C1headingAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
             //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
             //重绘
             customPlot->replot(QCustomPlot::rpQueuedReplot);
             C1headingAngleRun = 1;
             //customPlot->graph(C1headingAngleNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
             set_checkBox_5_3_4_79_80_81();
         }
         else
         {
             customPlot->graph(C1headingAngleNum)->setData(curveX,C1VheadingAngle);
             //重绘
             customPlot->replot(QCustomPlot::rpQueuedReplot);

         }
     }
     else
     {
         if(C1headingAngleRun == 1)
         {
             C1headingAngleRun = 0;
             C1rollAngleRun = 0;
             C1pitchAngleRun = 0;
             C6UndampedRollAngleFloatRun = 0;
             C6UndampedPitchAngleFloatRun = 0;
             C6UndampedHeadingAngularFloatRun = 0;
             //ui->customPlot2->removeGraph(C1headingAngleNum);
             ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);


         }
     }
        /**********************************横摇角曲线****************************************/
        if(ui->checkBox_3->isChecked())
        {
            if(C1rollAngleRun == 0)
            {
                QPen pen;
                C1rollAngleNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C1rollAngleNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C1rollAngleNum)->setData(curveX,C1VrollAngle);
                customPlot->graph(C1rollAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C1rollAngleRun = 1;
                //customPlot->graph(C1rollAngleNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
                customPlot->graph(C1rollAngleNum)->setData(curveX,C1VrollAngle);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C1rollAngleRun == 1)
            {
                C1rollAngleRun = 0;
                C1headingAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                 //ui->customPlot2->removeGraph(C1rollAngleNum);
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************纵摇角曲线****************************************/
        if(ui->checkBox_4->isChecked())
        {
            if(C1pitchAngleRun == 0)
            {
                QPen pen;
                C1pitchAngleNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                 customPlot->graph(C1pitchAngleNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C1pitchAngleNum)->setData(curveX,C1VpitchAngle);
                customPlot->graph(C1pitchAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C1pitchAngleRun = 1;
                //customPlot->graph(C1pitchAngleNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
               // customPlot->graph(C1pitchAngleNum)->setVisible(true);
                customPlot->graph(C1pitchAngleNum)->setData(curveX,C1VpitchAngle);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C1pitchAngleRun == 1)
            {
                C1pitchAngleRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                 //ui->customPlot2->removeGraph(C1pitchAngleNum);
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6无阻尼横摇角曲线****************************************/
        if(ui->checkBox_79->isChecked())
        {
            if(C6UndampedRollAngleFloatRun == 0)
            {
                QPen pen;
                C6UndampedRollAngleFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,128));
                customPlot->graph(C6UndampedRollAngleFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6UndampedRollAngleFloatNum)->setData(curveX,C6VC6UndampedRollAngleFloat);
                customPlot->graph(C6UndampedRollAngleFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6UndampedRollAngleFloatRun = 1;
                //customPlot->graph(C6UndampedRollAngleFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
               // customPlot->graph(C6UndampedRollAngleFloatNum)->setVisible(true);
                customPlot->graph(C6UndampedRollAngleFloatNum)->setData(curveX,C6VC6UndampedRollAngleFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C6UndampedRollAngleFloatRun == 1)
            {
                C6UndampedRollAngleFloatRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                 //ui->customPlot2->removeGraph(C6UndampedRollAngleFloatNum);
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************无阻尼纵摇角曲线****************************************/
        if(ui->checkBox_80->isChecked())
        {
            if(C6UndampedPitchAngleFloatRun == 0)
            {
                QPen pen;
                C6UndampedPitchAngleFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C6UndampedPitchAngleFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6UndampedPitchAngleFloatNum)->setData(curveX,C6VC6UndampedPitchAngleFloat);
                customPlot->graph(C6UndampedPitchAngleFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6UndampedPitchAngleFloatRun = 1;
                //customPlot->graph(C6UndampedPitchAngleFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
               // customPlot->graph(C6UndampedPitchAngleFloatNum)->setVisible(true);
                customPlot->graph(C6UndampedPitchAngleFloatNum)->setData(curveX,C6VC6UndampedPitchAngleFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C6UndampedPitchAngleFloatRun == 1)
            {
                C6UndampedPitchAngleFloatRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedHeadingAngularFloatRun = 0;
                 //ui->customPlot2->removeGraph(C6UndampedPitchAngleFloatNum);
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************无阻尼航向角曲线****************************************/
        if(ui->checkBox_81->isChecked())
        {
            if(C6UndampedHeadingAngularFloatRun == 0)
            {
                QPen pen;
                C6UndampedHeadingAngularFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,0,255));
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->setData(curveX,C6VC6UndampedHeadingAngularFloat);
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6UndampedHeadingAngularFloatRun = 1;
                //customPlot->graph(C6UndampedHeadingAngularFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_5_3_4_79_80_81();
            }
            else
            {
               // customPlot->graph(C6UndampedHeadingAngularFloatNum)->setVisible(true);
                customPlot->graph(C6UndampedHeadingAngularFloatNum)->setData(curveX,C6VC6UndampedHeadingAngularFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        else
        {
            if(C6UndampedHeadingAngularFloatRun == 1)
            {
                C6UndampedHeadingAngularFloatRun = 0;
                C1headingAngleRun = 0;
                C1rollAngleRun = 0;
                C1pitchAngleRun = 0;
                C6UndampedRollAngleFloatRun = 0;
                C6UndampedPitchAngleFloatRun = 0;
                 //ui->customPlot2->removeGraph(C6UndampedHeadingAngularFloatNum);
                ui->customPlot2->clearGraphs();
                 customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }


    /**********************************绘北速曲线****************************************/
    if(ui->checkBox_9->isChecked())
    {
        if(C1northSpeedRun == 0)
        {
            QPen pen;
            C1northSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1northSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1northSpeedNum)->setData(curveX,C1VnorthSpeed);
            customPlot->graph(C1northSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1northSpeedRun = 1;
            //customPlot->graph(C1northSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_9_10_76_77_78();
        }
        else
        {
           // customPlot->graph(C1northSpeedNum)->setVisible(true);
            customPlot->graph(C1northSpeedNum)->setData(curveX,C1VnorthSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1northSpeedRun == 1)
        {
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘东速曲线****************************************/
    if(ui->checkBox_10->isChecked())
    {
        if(C1eastSpeedRun == 0)
        {
            QPen pen;
            C1eastSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1eastSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1eastSpeedNum)->setData(curveX,C1VeastSpeed);
            customPlot->graph(C1eastSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1eastSpeedRun = 1;
            //customPlot->graph(C1eastSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_9_10_76_77_78();
        }
        else
        {
           // customPlot->graph(C1eastSpeedNum)->setVisible(true);
            customPlot->graph(C1eastSpeedNum)->setData(curveX,C1VeastSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1eastSpeedRun == 1)
        {
            C1eastSpeedRun = 0;
            C1northSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘C6的无阻尼北速曲线****************************************/
    if(ui->checkBox_76->isChecked())
    {
        if(C6UndampedNorthSpeedFloatRun == 0)
        {
            QPen pen;
            C6UndampedNorthSpeedFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->setData(curveX,C6VC6UndampedNorthSpeedFloat);
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedNorthSpeedFloatRun = 1;
            //customPlot->graph(C6UndampedNorthSpeedFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_9_10_76_77_78();
        }
        else
        {
           // customPlot->graph(C6UndampedNorthSpeedFloatNum)->setVisible(true);
            customPlot->graph(C6UndampedNorthSpeedFloatNum)->setData(curveX,C6VC6UndampedNorthSpeedFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedNorthSpeedFloatRun == 1)
        {
            C6UndampedNorthSpeedFloatRun = 0;
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘C6的无阻尼东速曲线****************************************/
    if(ui->checkBox_77->isChecked())
    {
        if(C6UndampedEastSpeedFloatRun == 0)
        {
            QPen pen;
            C6UndampedEastSpeedFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C6UndampedEastSpeedFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6UndampedEastSpeedFloatNum)->setData(curveX,C6VC6UndampedEastSpeedFloat);
            customPlot->graph(C6UndampedEastSpeedFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6UndampedEastSpeedFloatRun = 1;
            //customPlot->graph(C6UndampedEastSpeedFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_9_10_76_77_78();
        }
        else
        {
           // customPlot->graph(C6UndampedEastSpeedFloatNum)->setVisible(true);
            customPlot->graph(C6UndampedEastSpeedFloatNum)->setData(curveX,C6VC6UndampedEastSpeedFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6UndampedEastSpeedFloatRun == 1)
        {
            C6UndampedEastSpeedFloatRun = 0;
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6VerticalVelocityFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘C6的无阻尼垂速曲线****************************************/
    if(ui->checkBox_78->isChecked())
    {
        if(C6VerticalVelocityFloatRun == 0)
        {
            QPen pen;
            C6VerticalVelocityFloatNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C6VerticalVelocityFloatNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C6VerticalVelocityFloatNum)->setData(curveX,C6VC6VerticalVelocityFloat);
            customPlot->graph(C6VerticalVelocityFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C6VerticalVelocityFloatRun = 1;
            //customPlot->graph(C6VerticalVelocityFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_9_10_76_77_78();
        }
        else
        {
           // customPlot->graph(C6VerticalVelocityFloatNum)->setVisible(true);
            customPlot->graph(C6VerticalVelocityFloatNum)->setData(curveX,C6VC6VerticalVelocityFloat);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C6VerticalVelocityFloatRun == 1)
        {
            C6VerticalVelocityFloatRun = 0;
            C1northSpeedRun = 0;
            C1eastSpeedRun = 0;
            C6UndampedNorthSpeedFloatRun = 0;
            C6UndampedEastSpeedFloatRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************绘航向角速度曲线****************************************/
    if(ui->checkBox_6->isChecked())
    {
        if(C1headingAngularSpeedRun == 0)
        {
            QPen pen;
            C1headingAngularSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1headingAngularSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1headingAngularSpeedNum)->setData(curveX,C1VheadingAngularSpeed);
            customPlot->graph(C1headingAngularSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1headingAngularSpeedRun = 1;
            //customPlot->graph(C1headingAngularSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_6_7_8();
        }
        else
        {
           // customPlot->graph(C1headingAngularSpeedNum)->setVisible(true);
            customPlot->graph(C1headingAngularSpeedNum)->setData(curveX,C1VheadingAngularSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1headingAngularSpeedRun == 1)
        {
            C1headingAngularSpeedRun = 0;
            C1pitchAngleSpeedRun = 0;
            C1rollAngleSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************绘横摇角速度曲线****************************************/
    if(ui->checkBox_7->isChecked())
    {
        if(C1rollAngleSpeedRun == 0)
        {
            QPen pen;
            C1rollAngleSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1rollAngleSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1rollAngleSpeedNum)->setData(curveX,C1VrollAngleSpeed);
            customPlot->graph(C1rollAngleSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1rollAngleSpeedRun = 1;
            //customPlot->graph(C1rollAngleSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_6_7_8();
        }
        else
        {
           // customPlot->graph(C1rollAngleSpeedNum)->setVisible(true);
            customPlot->graph(C1rollAngleSpeedNum)->setData(curveX,C1VrollAngleSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1rollAngleSpeedRun == 1)
        {
            C1rollAngleSpeedRun = 0;
             C1headingAngularSpeedRun = 0;
             C1pitchAngleSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************绘纵摇角速度曲线****************************************/
    if(ui->checkBox_8->isChecked())
    {
        if(C1pitchAngleSpeedRun == 0)
        {
            QPen pen;
            C1pitchAngleSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C1pitchAngleSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1pitchAngleSpeedNum)->setData(curveX,C1VpitchAngleSpeed);
            customPlot->graph(C1pitchAngleSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1pitchAngleSpeedRun = 1;
            //customPlot->graph(C1pitchAngleSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_6_7_8();
        }
        else
        {
           // customPlot->graph(C1pitchAngleSpeedNum)->setVisible(true);
            customPlot->graph(C1pitchAngleSpeedNum)->setData(curveX,C1VpitchAngleSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1pitchAngleSpeedRun == 1)
        {
            C1pitchAngleSpeedRun = 0;
            C1rollAngleSpeedRun = 0;
            C1headingAngularSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************垂荡曲线****************************************/
    if(ui->checkBox_12->isChecked())
    {
        if(C1heaveRun == 0)
        {
            QPen pen;
            C1heaveNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C1heaveNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1heaveNum)->setData(curveX,C1Vheave);
            customPlot->graph(C1heaveNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1heaveRun = 1;
            //customPlot->graph(C1heaveNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1heaveNum)->setData(curveX,C1Vheave);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1heaveRun == 1)
        {
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************垂速曲线****************************************/
    if(ui->checkBox_13->isChecked())
    {
        if(C1verticalVelocityRun == 0)
        {
            QPen pen;
            C1verticalVelocityNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C1verticalVelocityNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1verticalVelocityNum)->setData(curveX,C1VverticalVelocity);
            customPlot->graph(C1verticalVelocityNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1verticalVelocityRun = 1;
            //customPlot->graph(C1verticalVelocityNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
            customPlot->graph(C1verticalVelocityNum)->setData(curveX,C1VverticalVelocity);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1verticalVelocityRun == 1)
        {
            C1verticalVelocityRun = 0;
            C1heaveRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************横荡曲线****************************************/
    if(ui->checkBox_11->isChecked())
    {
        if(C1swayRun == 0)
        {
            QPen pen;
            C1swayNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
             customPlot->graph(C1swayNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1swayNum)->setData(curveX,C1Vsway);
            customPlot->graph(C1swayNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1swayRun = 1;
            //customPlot->graph(C1swayNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
           // customPlot->graph(C1swayNum)->setVisible(true);
            customPlot->graph(C1swayNum)->setData(curveX,C1Vsway);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1swayRun == 1)
        {
            C1swayRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************横速曲线****************************************/
    if(ui->checkBox_15->isChecked())
    {
        if(C1transverseVelocityRun == 0)
        {
            QPen pen;
            C1transverseVelocityNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C1transverseVelocityNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1transverseVelocityNum)->setData(curveX,C1VtransverseVelocity);
            customPlot->graph(C1transverseVelocityNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1transverseVelocityRun = 1;
            //customPlot->graph(C1transverseVelocityNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
           // customPlot->graph(C1transverseVelocityNum)->setVisible(true);
            customPlot->graph(C1transverseVelocityNum)->setData(curveX,C1VtransverseVelocity);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1transverseVelocityRun == 1)
        {
            C1transverseVelocityRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1surgeRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************纵荡曲线****************************************/
    if(ui->checkBox_16->isChecked())
    {
        if(C1surgeRun == 0)
        {
            QPen pen;
            C1surgeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C1surgeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1surgeNum)->setData(curveX,C1Vsurge);
            customPlot->graph(C1surgeNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1surgeRun = 1;
            //customPlot->graph(C1surgeNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
           // customPlot->graph(C1surgeNum)->setVisible(true);
            customPlot->graph(C1surgeNum)->setData(curveX,C1Vsurge);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1surgeRun == 1)
        {
            C1surgeRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1longitudinalVelocityRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************纵速曲线****************************************/
    if(ui->checkBox_14->isChecked())
    {
        if(C1longitudinalVelocityRun == 0)
        {
            QPen pen;
            C1longitudinalVelocityNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,0,255));
            customPlot->graph(C1longitudinalVelocityNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C1longitudinalVelocityNum)->setData(curveX,C1VlongitudinalVelocity);
            customPlot->graph(C1longitudinalVelocityNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C1longitudinalVelocityRun = 1;
            //customPlot->graph(C1longitudinalVelocityNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_12_13_11_15_16_14();
        }
        else
        {
           // customPlot->graph(C1longitudinalVelocityNum)->setVisible(true);
            customPlot->graph(C1longitudinalVelocityNum)->setData(curveX,C1VlongitudinalVelocity);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C1longitudinalVelocityRun == 1)
        {
            C1longitudinalVelocityRun = 0;
            C1heaveRun = 0;
            C1verticalVelocityRun = 0;
            C1swayRun = 0;
            C1transverseVelocityRun = 0;
            C1surgeRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    if(0)//增量曲线和原始脉冲曲线不显示2022-01-20
    {
        /**********************************X陀螺增量曲线****************************************/
        if(ui->checkBox_19->isChecked())
        {
            if(C5XGyroAngleIncreaseFloatRun == 0)
            {
                QPen pen;
                C5XGyroAngleIncreaseFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XGyroAngleIncreaseFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XGyroAngleIncreaseFloatNum)->setData(curveX,C5VXGyroAngleIncreaseFloat);
                 customPlot->graph(C5XGyroAngleIncreaseFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XGyroAngleIncreaseFloatRun = 1;
                //customPlot->graph(C5XGyroAngleIncreaseFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_19_18_17();
            }
            else
            {
                // customPlot->graph(C5XGyroAngleIncreaseFloatNum)->setVisible(true);
                customPlot->graph(C5XGyroAngleIncreaseFloatNum)->setData(curveX,C5VXGyroAngleIncreaseFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XGyroAngleIncreaseFloatRun == 1)
            {
                C5XGyroAngleIncreaseFloatRun = 0;
                C5YGyroAngleIncreaseFloatRun = 0;
                C5ZGyroAngleIncreaseFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************Y陀螺增量曲线****************************************/
        if(ui->checkBox_18->isChecked())
        {
            if(C5YGyroAngleIncreaseFloatRun == 0)
            {
                QPen pen;
                C5YGyroAngleIncreaseFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->setData(curveX,C5VYGyroAngleIncreaseFloat);
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YGyroAngleIncreaseFloatRun = 1;
                //customPlot->graph(C5YGyroAngleIncreaseFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_19_18_17();
            }
            else
            {
                // customPlot->graph(C5YGyroAngleIncreaseFloatNum)->setVisible(true);
                customPlot->graph(C5YGyroAngleIncreaseFloatNum)->setData(curveX,C5VYGyroAngleIncreaseFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YGyroAngleIncreaseFloatRun == 1)
            {
                C5YGyroAngleIncreaseFloatRun = 0;
                C5ZGyroAngleIncreaseFloatRun = 0;
                C5XGyroAngleIncreaseFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************Z陀螺增量曲线****************************************/
        if(ui->checkBox_17->isChecked())
        {
            if(C5ZGyroAngleIncreaseFloatRun == 0)
            {
                QPen pen;
                C5ZGyroAngleIncreaseFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->setData(curveX,C5VZGyroAngleIncreaseFloat);
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZGyroAngleIncreaseFloatRun = 1;
                //customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_19_18_17();
            }
            else
            {
                // customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->setVisible(true);
                customPlot->graph(C5ZGyroAngleIncreaseFloatNum)->setData(curveX,C5VZGyroAngleIncreaseFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZGyroAngleIncreaseFloatRun == 1)
            {
                C5ZGyroAngleIncreaseFloatRun = 0;
                C5YGyroAngleIncreaseFloatRun = 0;
                C5XGyroAngleIncreaseFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************X加表增量曲线****************************************/
        if(ui->checkBox_20->isChecked())
        {
            if(C5XAccelerometerSpeedIncrementFloatRun == 0)
            {
                QPen pen;
                C5XAccelerometerSpeedIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->setData(curveX,C5VXAccelerometerSpeedIncrementFloat);
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XAccelerometerSpeedIncrementFloatRun = 1;
                //customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_20_21_22();
            }
            else
            {
                // customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5XAccelerometerSpeedIncrementFloatNum)->setData(curveX,C5VXAccelerometerSpeedIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XAccelerometerSpeedIncrementFloatRun == 1)
            {
                C5XAccelerometerSpeedIncrementFloatRun = 0;
                C5YAccelerometerSpeedIncrementFloatRun = 0;
                C5ZAccelerometerSpeedIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************Y加表增量曲线****************************************/
        if(ui->checkBox_21->isChecked())
        {
            if(C5YAccelerometerSpeedIncrementFloatRun == 0)
            {
                QPen pen;
                C5YAccelerometerSpeedIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->setData(curveX,C5VYAccelerometerSpeedIncrementFloat);
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YAccelerometerSpeedIncrementFloatRun = 1;
                //customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_20_21_22();
            }
            else
            {
                // customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5YAccelerometerSpeedIncrementFloatNum)->setData(curveX,C5VYAccelerometerSpeedIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YAccelerometerSpeedIncrementFloatRun == 1)
            {
                C5YAccelerometerSpeedIncrementFloatRun = 0;
                C5ZAccelerometerSpeedIncrementFloatRun = 0;
                C5XAccelerometerSpeedIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Z加表增量曲线****************************************/
        if(ui->checkBox_22->isChecked())
        {
            if(C5ZAccelerometerSpeedIncrementFloatRun == 0)
            {
                QPen pen;
                C5ZAccelerometerSpeedIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->setData(curveX,C5VZAccelerometerSpeedIncrementFloat);
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZAccelerometerSpeedIncrementFloatRun = 1;
                // customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_20_21_22();
            }
            else
            {
                // customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5ZAccelerometerSpeedIncrementFloatNum)->setData(curveX,C5VZAccelerometerSpeedIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZAccelerometerSpeedIncrementFloatRun == 1)
            {
                C5ZAccelerometerSpeedIncrementFloatRun = 0;
                C5YAccelerometerSpeedIncrementFloatRun = 0;
                C5XAccelerometerSpeedIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************x陀螺1s补偿后角增量曲线****************************************/
        if(ui->checkBox_23->isChecked())
        {
            if(C5XgyroCompensatedAngleIncrementFloatRun == 0)
            {
                QPen pen;
                C5XgyroCompensatedAngleIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->setData(curveX,C5VXgyroCompensatedAngleIncrementFloat);
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XgyroCompensatedAngleIncrementFloatRun = 1;
                //customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_23_24_25();
            }
            else
            {
                // customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5XgyroCompensatedAngleIncrementFloatNum)->setData(curveX,C5VXgyroCompensatedAngleIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XgyroCompensatedAngleIncrementFloatRun == 1)
            {
                C5XgyroCompensatedAngleIncrementFloatRun = 0;
                C5YgyroCompensatedAngleIncrementFloatRun = 0;
                C5ZgyroCompensatedAngleIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Y陀螺1s补偿后角增量曲线****************************************/
        if(ui->checkBox_24->isChecked())
        {
            if(C5YgyroCompensatedAngleIncrementFloatRun == 0)
            {
                QPen pen;
                C5YgyroCompensatedAngleIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->setData(curveX,C5VYgyroCompensatedAngleIncrementFloat);
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YgyroCompensatedAngleIncrementFloatRun = 1;
                //customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_23_24_25();
            }
            else
            {
                // customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5YgyroCompensatedAngleIncrementFloatNum)->setData(curveX,C5VYgyroCompensatedAngleIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YgyroCompensatedAngleIncrementFloatRun == 1)
            {
                C5YgyroCompensatedAngleIncrementFloatRun = 0;
                C5XgyroCompensatedAngleIncrementFloatRun = 0;
                C5ZgyroCompensatedAngleIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Z陀螺1s补偿后角增量曲线****************************************/
        if(ui->checkBox_25->isChecked())
        {
            if(C5ZgyroCompensatedAngleIncrementFloatRun == 0)
            {
                QPen pen;
                C5ZgyroCompensatedAngleIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->setData(curveX,C5VZgyroCompensatedAngleIncrementFloat);
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZgyroCompensatedAngleIncrementFloatRun = 1;
                //customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_23_24_25();
            }
            else
            {
                // customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5ZgyroCompensatedAngleIncrementFloatNum)->setData(curveX,C5VZgyroCompensatedAngleIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZgyroCompensatedAngleIncrementFloatRun == 1)
            {
                C5ZgyroCompensatedAngleIncrementFloatRun = 0;
                C5XgyroCompensatedAngleIncrementFloatRun = 0;
                C5YgyroCompensatedAngleIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************x加表1s补偿后角增量曲线****************************************/
        if(ui->checkBox_26->isChecked())
        {
            if(C5XAccVelocityIncrementFloatRun == 0)
            {
                QPen pen;
                C5XAccVelocityIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->setData(curveX,C5VXAccVelocityIncrementFloat);
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5XAccVelocityIncrementFloatRun = 1;
                //customPlot->graph(C5XAccVelocityIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_26_27_28();
            }
            else
            {
                // customPlot->graph(C5XAccVelocityIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5XAccVelocityIncrementFloatNum)->setData(curveX,C5VXAccVelocityIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5XAccVelocityIncrementFloatRun == 1)
            {
                C5XAccVelocityIncrementFloatRun = 0;
                C5YAccVelocityIncrementFloatRun = 0;
                C5ZAccVelocityIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Y加表1s补偿后角增量曲线****************************************/
        if(ui->checkBox_27->isChecked())
        {
            if(C5YAccVelocityIncrementFloatRun == 0)
            {
                QPen pen;
                C5YAccVelocityIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->setData(curveX,C5VYAccVelocityIncrementFloat);
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5YAccVelocityIncrementFloatRun = 1;
                //customPlot->graph(C5YAccVelocityIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_26_27_28();
            }
            else
            {
                // customPlot->graph(C5YAccVelocityIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5YAccVelocityIncrementFloatNum)->setData(curveX,C5VYAccVelocityIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5YAccVelocityIncrementFloatRun == 1)
            {
                C5YAccVelocityIncrementFloatRun = 0;
                C5XAccVelocityIncrementFloatRun = 0;
                C5ZAccVelocityIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
        /**********************************Z加表1s补偿后角增量曲线****************************************/
        if(ui->checkBox_28->isChecked())
        {
            if(C5ZAccVelocityIncrementFloatRun == 0)
            {
                QPen pen;
                C5ZAccVelocityIncrementFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->setData(curveX,C5VZAccVelocityIncrementFloat);
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C5ZAccVelocityIncrementFloatRun = 1;
                //customPlot->graph(C5ZAccVelocityIncrementFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_26_27_28();
            }
            else
            {
                // customPlot->graph(C5ZAccVelocityIncrementFloatNum)->setVisible(true);
                customPlot->graph(C5ZAccVelocityIncrementFloatNum)->setData(curveX,C5VZAccVelocityIncrementFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C5ZAccVelocityIncrementFloatRun == 1)
            {
                C5ZAccVelocityIncrementFloatRun = 0;
                C5XAccVelocityIncrementFloatRun = 0;
                C5YAccVelocityIncrementFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
    }
    /**********************************C5的X陀螺差频曲线****************************************/
    if(ui->checkBox_29->isChecked())
    {
        if(C5XgyroDifFrequencyRun == 0)
        {
            QPen pen;
            C5XgyroDifFrequencyNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroDifFrequencyNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroDifFrequencyNum)->setData(curveX,C5VXgyroDifFrequency);
            customPlot->graph(C5XgyroDifFrequencyNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroDifFrequencyRun = 1;
            //customPlot->graph(C5XgyroDifFrequencyNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_29_30_31();
        }
        else
        {
           // customPlot->graph(C5XgyroDifFrequencyNum)->setVisible(true);
            customPlot->graph(C5XgyroDifFrequencyNum)->setData(curveX,C5VXgyroDifFrequency);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroDifFrequencyRun == 1)
        {
            C5XgyroDifFrequencyRun = 0;
            C5YgyroDifFrequencyRun = 0;
            C5ZgyroDifFrequencyRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺差频曲线****************************************/
    if(ui->checkBox_31->isChecked())
    {
        if(C5YgyroDifFrequencyRun == 0)
        {
            QPen pen;
            C5YgyroDifFrequencyNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroDifFrequencyNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroDifFrequencyNum)->setData(curveX,C5VYgyroDifFrequency);
            customPlot->graph(C5YgyroDifFrequencyNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroDifFrequencyRun = 1;
            //customPlot->graph(C5YgyroDifFrequencyNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_29_30_31();
        }
        else
        {
           // customPlot->graph(C5YgyroDifFrequencyNum)->setVisible(true);
            customPlot->graph(C5YgyroDifFrequencyNum)->setData(curveX,C5VYgyroDifFrequency);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroDifFrequencyRun == 1)
        {
            C5YgyroDifFrequencyRun = 0;
            C5XgyroDifFrequencyRun = 0;
            C5ZgyroDifFrequencyRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺差频曲线****************************************/
    if(ui->checkBox_30->isChecked())
    {
        if(C5ZgyroDifFrequencyRun == 0)
        {
            QPen pen;
            C5ZgyroDifFrequencyNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroDifFrequencyNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroDifFrequencyNum)->setData(curveX,C5VZgyroDifFrequency);
            customPlot->graph(C5ZgyroDifFrequencyNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroDifFrequencyRun = 1;
            //customPlot->graph(C5ZgyroDifFrequencyNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_29_30_31();
        }
        else
        {
           // customPlot->graph(C5ZgyroDifFrequencyNum)->setVisible(true);
            customPlot->graph(C5ZgyroDifFrequencyNum)->setData(curveX,C5VZgyroDifFrequency);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroDifFrequencyRun == 1)
        {
            C5ZgyroDifFrequencyRun = 0;
            C5XgyroDifFrequencyRun = 0;
            C5YgyroDifFrequencyRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X加表差频曲线****************************************/
    if(ui->checkBox_32->isChecked())
    {
        if(C5XaccelerometerDifFreRun == 0)
        {
            QPen pen;
            C5XaccelerometerDifFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XaccelerometerDifFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XaccelerometerDifFreNum)->setData(curveX,C5VXaccelerometerDifFre);
            customPlot->graph(C5XaccelerometerDifFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XaccelerometerDifFreRun = 1;
            //customPlot->graph(C5XaccelerometerDifFreNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_32_33_34();
        }
        else
        {
           // customPlot->graph(C5XaccelerometerDifFreNum)->setVisible(true);
            customPlot->graph(C5XaccelerometerDifFreNum)->setData(curveX,C5VXaccelerometerDifFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XaccelerometerDifFreRun == 1)
        {
            C5XaccelerometerDifFreRun = 0;
            C5YaccelerometerDifFreRun = 0;
            C5ZaccelerometerDifFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y加表差频曲线****************************************/
    if(ui->checkBox_33->isChecked())
    {
        if(C5YaccelerometerDifFreRun == 0)
        {
            QPen pen;
            C5YaccelerometerDifFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YaccelerometerDifFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YaccelerometerDifFreNum)->setData(curveX,C5VYaccelerometerDifFre);
            customPlot->graph(C5YaccelerometerDifFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YaccelerometerDifFreRun = 1;
            //customPlot->graph(C5YaccelerometerDifFreNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_32_33_34();
        }
        else
        {
           // customPlot->graph(C5YaccelerometerDifFreNum)->setVisible(true);
            customPlot->graph(C5YaccelerometerDifFreNum)->setData(curveX,C5VYaccelerometerDifFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YaccelerometerDifFreRun == 1)
        {
            C5YaccelerometerDifFreRun = 0;
            C5XaccelerometerDifFreRun = 0;
            C5ZaccelerometerDifFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z加表差频曲线****************************************/
    if(ui->checkBox_34->isChecked())
    {
        if(C5ZaccelerometerDifFreRun == 0)
        {
            QPen pen;
            C5ZaccelerometerDifFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZaccelerometerDifFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZaccelerometerDifFreNum)->setData(curveX,C5VZaccelerometerDifFre);
            customPlot->graph(C5ZaccelerometerDifFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZaccelerometerDifFreRun = 1;
            //customPlot->graph(C5ZaccelerometerDifFreNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_32_33_34();
        }
        else
        {
           // customPlot->graph(C5ZaccelerometerDifFreNum)->setVisible(true);
            customPlot->graph(C5ZaccelerometerDifFreNum)->setData(curveX,C5VZaccelerometerDifFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZaccelerometerDifFreRun == 1)
        {
            C5ZaccelerometerDifFreRun = 0;
            C5XaccelerometerDifFreRun = 0;
            C5YaccelerometerDifFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺温度1曲线****************************************/
    if(ui->checkBox_37->isChecked())
    {
        if(C5XgyroTemp1Run == 0)
        {
            QPen pen;
             C5XgyroTemp1Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroTemp1Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroTemp1Num)->setData(curveX,C5VXgyroTemp1);
            customPlot->graph(C5XgyroTemp1Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroTemp1Run = 1;
            //customPlot->graph(C5XgyroTemp1Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_37_35_36();
        }
        else
        {
           // customPlot->graph(C5XgyroTemp1Num)->setVisible(true);
            customPlot->graph(C5XgyroTemp1Num)->setData(curveX,C5VXgyroTemp1);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroTemp1Run == 1)
        {
            C5XgyroTemp1Run = 0;
            C5YgyroTemp1Run = 0;
            C5ZgyroTemp1Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺温度1曲线****************************************/
    if(ui->checkBox_35->isChecked())
    {
        if(C5YgyroTemp1Run == 0)
        {
            QPen pen;
            C5YgyroTemp1Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroTemp1Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroTemp1Num)->setData(curveX,C5VYgyroTemp1);
            customPlot->graph(C5YgyroTemp1Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroTemp1Run = 1;
            //customPlot->graph(C5YgyroTemp1Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_37_35_36();
        }
        else
        {
           // customPlot->graph(C5YgyroTemp1Num)->setVisible(true);
            customPlot->graph(C5YgyroTemp1Num)->setData(curveX,C5VYgyroTemp1);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroTemp1Run == 1)
        {
            C5YgyroTemp1Run = 0;
            C5XgyroTemp1Run = 0;
            C5ZgyroTemp1Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺温度1曲线****************************************/
    if(ui->checkBox_36->isChecked())
    {
        if(C5ZgyroTemp1Run == 0)
        {
            QPen pen;
            C5ZgyroTemp1Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroTemp1Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroTemp1Num)->setData(curveX,C5VZgyroTemp1);
            customPlot->graph(C5ZgyroTemp1Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroTemp1Run = 1;
            //customPlot->graph(C5ZgyroTemp1Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_37_35_36();
        }
        else
        {
           // customPlot->graph(C5ZgyroTemp1Num)->setVisible(true);
            customPlot->graph(C5ZgyroTemp1Num)->setData(curveX,C5VZgyroTemp1);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroTemp1Run == 1)
        {
            C5ZgyroTemp1Run = 0;
            C5XgyroTemp1Run = 0;
            C5YgyroTemp1Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X加表温度1曲线****************************************/
    if(ui->checkBox_40->isChecked())
    {
        if(C5XAccelerometerTempertureRun == 0)
        {
            QPen pen;
             C5XAccelerometerTempertureNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XAccelerometerTempertureNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XAccelerometerTempertureNum)->setData(curveX,C5VXAccelerometerTemperture);
            customPlot->graph(C5XAccelerometerTempertureNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XAccelerometerTempertureRun = 1;
            //customPlot->graph(C5XAccelerometerTempertureNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_40_38_39();
        }
        else
        {
           // customPlot->graph(C5XAccelerometerTempertureNum)->setVisible(true);
            customPlot->graph(C5XAccelerometerTempertureNum)->setData(curveX,C5VXAccelerometerTemperture);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XAccelerometerTempertureRun == 1)
        {
            C5XAccelerometerTempertureRun = 0;
            C5YAccelerometerTempertureRun = 0;
            C5ZAccelerometerTempertureRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y加表温度1曲线****************************************/
    if(ui->checkBox_38->isChecked())
    {
        if(C5YAccelerometerTempertureRun == 0)
        {
            QPen pen;
            C5YAccelerometerTempertureNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YAccelerometerTempertureNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YAccelerometerTempertureNum)->setData(curveX,C5VYAccelerometerTemperture);
            customPlot->graph(C5YAccelerometerTempertureNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YAccelerometerTempertureRun = 1;
            //customPlot->graph(C5YAccelerometerTempertureNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_40_38_39();
        }
        else
        {
           // customPlot->graph(C5YAccelerometerTempertureNum)->setVisible(true);
            customPlot->graph(C5YAccelerometerTempertureNum)->setData(curveX,C5VYAccelerometerTemperture);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YAccelerometerTempertureRun == 1)
        {
            C5YAccelerometerTempertureRun = 0;
            C5XAccelerometerTempertureRun = 0;
            C5ZAccelerometerTempertureRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z加表温度1曲线****************************************/
    if(ui->checkBox_39->isChecked())
    {
        if(C5ZAccelerometerTempertureRun == 0)
        {
            QPen pen;
            C5ZAccelerometerTempertureNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZAccelerometerTempertureNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZAccelerometerTempertureNum)->setData(curveX,C5VZAccelerometerTemperture);
            customPlot->graph(C5ZAccelerometerTempertureNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZAccelerometerTempertureRun = 1;
            //customPlot->graph(C5ZAccelerometerTempertureNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_40_38_39();
        }
        else
        {
           // customPlot->graph(C5ZAccelerometerTempertureNum)->setVisible(true);
            customPlot->graph(C5ZAccelerometerTempertureNum)->setData(curveX,C5VZAccelerometerTemperture);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZAccelerometerTempertureRun == 1)
        {
            C5ZAccelerometerTempertureRun = 0;
            C5XAccelerometerTempertureRun = 0;
            C5YAccelerometerTempertureRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺温度2曲线****************************************/
    if(ui->checkBox_42->isChecked())
    {
        if(C5XgyroTemp2Run == 0)
        {
            QPen pen;
             C5XgyroTemp2Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroTemp2Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroTemp2Num)->setData(curveX,C5VXgyroTemp2);
            customPlot->graph(C5XgyroTemp2Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroTemp2Run = 1;
            //customPlot->graph(C5XgyroTemp2Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_42_43_41();
        }
        else
        {
           // customPlot->graph(C5XgyroTemp2Num)->setVisible(true);
            customPlot->graph(C5XgyroTemp2Num)->setData(curveX,C5VXgyroTemp2);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroTemp2Run == 1)
        {
            C5XgyroTemp2Run = 0;
            C5YgyroTemp2Run = 0;
            C5ZgyroTemp2Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺温度2曲线****************************************/
    if(ui->checkBox_43->isChecked())
    {
        if(C5YgyroTemp2Run == 0)
        {
            QPen pen;
            C5YgyroTemp2Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroTemp2Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroTemp2Num)->setData(curveX,C5VYgyroTemp2);
            customPlot->graph(C5YgyroTemp2Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroTemp2Run = 1;
            //customPlot->graph(C5YgyroTemp2Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_42_43_41();
        }
        else
        {
           // customPlot->graph(C5YgyroTemp2Num)->setVisible(true);
            customPlot->graph(C5YgyroTemp2Num)->setData(curveX,C5VYgyroTemp2);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroTemp2Run == 1)
        {
            C5YgyroTemp2Run = 0;
            C5XgyroTemp2Run = 0;
            C5ZgyroTemp2Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺温度2曲线****************************************/
    if(ui->checkBox_41->isChecked())
    {
        if(C5ZgyroTemp2Run == 0)
        {
            QPen pen;
            C5ZgyroTemp2Num = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroTemp2Num)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroTemp2Num)->setData(curveX,C5VZgyroTemp2);
            customPlot->graph(C5ZgyroTemp2Num)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroTemp2Run = 1;
            //customPlot->graph(C5ZgyroTemp2Num)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_42_43_41();
        }
        else
        {
           // customPlot->graph(C5ZgyroTemp2Num)->setVisible(true);
            customPlot->graph(C5ZgyroTemp2Num)->setData(curveX,C5VZgyroTemp2);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroTemp2Run == 1)
        {
            C5ZgyroTemp2Run = 0;
            C5XgyroTemp2Run = 0;
            C5YgyroTemp2Run = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺抖幅曲线****************************************/
    if(ui->checkBox_45->isChecked())
    {
        if(C5XgyroAmplitudeJitterRun == 0)
        {
            QPen pen;
             C5XgyroAmplitudeJitterNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroAmplitudeJitterNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroAmplitudeJitterNum)->setData(curveX,C5VXgyroAmplitudeJitter);
            customPlot->graph(C5XgyroAmplitudeJitterNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroAmplitudeJitterRun = 1;
            //customPlot->graph(C5XgyroAmplitudeJitterNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_45_46_44();
        }
        else
        {
           // customPlot->graph(C5XgyroAmplitudeJitterNum)->setVisible(true);
            customPlot->graph(C5XgyroAmplitudeJitterNum)->setData(curveX,C5VXgyroAmplitudeJitter);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroAmplitudeJitterRun == 1)
        {
            C5XgyroAmplitudeJitterRun = 0;
            C5YgyroAmplitudeJitterRun = 0;
            C5ZgyroAmplitudeJitterRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺抖幅曲线****************************************/
    if(ui->checkBox_46->isChecked())
    {
        if(C5YgyroAmplitudeJitterRun == 0)
        {
            QPen pen;
            C5YgyroAmplitudeJitterNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroAmplitudeJitterNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroAmplitudeJitterNum)->setData(curveX,C5VYgyroAmplitudeJitter);
            customPlot->graph(C5YgyroAmplitudeJitterNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroAmplitudeJitterRun = 1;
            //customPlot->graph(C5YgyroAmplitudeJitterNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_45_46_44();
        }
        else
        {
           // customPlot->graph(C5YgyroAmplitudeJitterNum)->setVisible(true);
            customPlot->graph(C5YgyroAmplitudeJitterNum)->setData(curveX,C5VYgyroAmplitudeJitter);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroAmplitudeJitterRun == 1)
        {
            C5YgyroAmplitudeJitterRun = 0;
            C5XgyroAmplitudeJitterRun = 0;
            C5ZgyroAmplitudeJitterRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺抖幅曲线****************************************/
    if(ui->checkBox_44->isChecked())
    {
        if(C5ZgyroAmplitudeJitterRun == 0)
        {
            QPen pen;
            C5ZgyroAmplitudeJitterNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->setData(curveX,C5VZgyroAmplitudeJitter);
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroAmplitudeJitterRun = 1;
            //customPlot->graph(C5ZgyroAmplitudeJitterNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_45_46_44();
        }
        else
        {
           // customPlot->graph(C5ZgyroAmplitudeJitterNum)->setVisible(true);
            customPlot->graph(C5ZgyroAmplitudeJitterNum)->setData(curveX,C5VZgyroAmplitudeJitter);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroAmplitudeJitterRun == 1)
        {
            C5ZgyroAmplitudeJitterRun = 0;
            C5XgyroAmplitudeJitterRun = 0;
            C5YgyroAmplitudeJitterRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C5的X陀螺抖频曲线****************************************/
    if(ui->checkBox_48->isChecked())
    {
        if(C5XgyroAmpl1itudeFreRun == 0)
        {
            QPen pen;
             C5XgyroAmpl1itudeFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->setData(curveX,C5VXgyroAmpl1itudeFre);
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5XgyroAmpl1itudeFreRun = 1;
            //customPlot->graph(C5XgyroAmpl1itudeFreNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_48_49_47();
        }
        else
        {
           // customPlot->graph(C5XgyroAmpl1itudeFreNum)->setVisible(true);
            customPlot->graph(C5XgyroAmpl1itudeFreNum)->setData(curveX,C5VXgyroAmpl1itudeFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5XgyroAmpl1itudeFreRun == 1)
        {
            C5XgyroAmpl1itudeFreRun = 0;
            C5YgyroAmpl1itudeFreRun = 0;
            C5ZgyroAmpl1itudeFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Y陀螺抖频曲线****************************************/
    if(ui->checkBox_49->isChecked())
    {
        if(C5YgyroAmpl1itudeFreRun == 0)
        {
            QPen pen;
            C5YgyroAmpl1itudeFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->setData(curveX,C5VYgyroAmpl1itudeFre);
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5YgyroAmpl1itudeFreRun = 1;
            //customPlot->graph(C5YgyroAmpl1itudeFreNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_48_49_47();
        }
        else
        {
           // customPlot->graph(C5YgyroAmpl1itudeFreNum)->setVisible(true);
            customPlot->graph(C5YgyroAmpl1itudeFreNum)->setData(curveX,C5VYgyroAmpl1itudeFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5YgyroAmpl1itudeFreRun == 1)
        {
            C5YgyroAmpl1itudeFreRun = 0;
            C5XgyroAmpl1itudeFreRun = 0;
            C5ZgyroAmpl1itudeFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C5的Z陀螺抖频曲线****************************************/
    if(ui->checkBox_47->isChecked())
    {
        if(C5ZgyroAmpl1itudeFreRun == 0)
        {
            QPen pen;
            C5ZgyroAmpl1itudeFreNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->setData(curveX,C5VZgyroAmpl1itudeFre);
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C5ZgyroAmpl1itudeFreRun = 1;
            //customPlot->graph(C5ZgyroAmpl1itudeFreNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_48_49_47();
        }
        else
        {
           // customPlot->graph(C5ZgyroAmpl1itudeFreNum)->setVisible(true);
            customPlot->graph(C5ZgyroAmpl1itudeFreNum)->setData(curveX,C5VZgyroAmpl1itudeFre);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C5ZgyroAmpl1itudeFreRun == 1)
        {
            C5ZgyroAmpl1itudeFreRun = 0;
            C5XgyroAmpl1itudeFreRun = 0;
            C5YgyroAmpl1itudeFreRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS纬度曲线****************************************/
    if(ui->checkBox_51->isChecked())
    {
        if(C3GPSlatitudeRun == 0)
        {
            QPen pen;
            C3GPSlatitudeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C3GPSlatitudeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3GPSlatitudeNum)->setData(curveX,C3VGPSlatitude);
            customPlot->graph(C3GPSlatitudeNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3GPSlatitudeRun = 1;
            //customPlot->graph(C3GPSlatitudeNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
           // customPlot->graph(C3GPSlatitudeNum)->setVisible(true);
            customPlot->graph(C3GPSlatitudeNum)->setData(curveX,C3VGPSlatitude);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3GPSlatitudeRun == 1)
        {
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS经度曲线****************************************/
    if(ui->checkBox_54->isChecked())
    {
        if(C3longitudeRun == 0)
        {
            QPen pen;
            C3longitudeNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C3longitudeNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3longitudeNum)->setData(curveX,C3Vlongitude);
            customPlot->graph(C3longitudeNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3longitudeRun = 1;
            //customPlot->graph(C3longitudeNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
           // customPlot->graph(C3longitudeNum)->setVisible(true);
            customPlot->graph(C3longitudeNum)->setData(curveX,C3Vlongitude);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3longitudeRun == 1)
        {
            C3longitudeRun = 0;
            C3GPSlatitudeRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS合速曲线****************************************/
    if(ui->checkBox_50->isChecked())
    {
        if(C3togetherSpeedRun == 0)
        {
            QPen pen;
            C3togetherSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C3togetherSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3togetherSpeedNum)->setData(curveX,C3VtogetherSpeed);
            customPlot->graph(C3togetherSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3togetherSpeedRun = 1;
            //customPlot->graph(C3togetherSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
           // customPlot->graph(C3togetherSpeedNum)->setVisible(true);
            customPlot->graph(C3togetherSpeedNum)->setData(curveX,C3VtogetherSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3togetherSpeedRun == 1)
        {
            C3togetherSpeedRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS航向曲线****************************************/
    if(ui->checkBox_52->isChecked())
    {
        if(C3headingAngleRun == 0)
        {
            QPen pen;
            C3headingAngleNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C3headingAngleNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3headingAngleNum)->setData(curveX,C3VheadingAngle);
            customPlot->graph(C3headingAngleNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3headingAngleRun = 1;
            //customPlot->graph(C3headingAngleNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
           // customPlot->graph(C3headingAngleNum)->setVisible(true);
            customPlot->graph(C3headingAngleNum)->setData(curveX,C3VheadingAngle);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3headingAngleRun == 1)
        {
            C3headingAngleRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C3togetherSpeedRun = 0;
            C3combinedEastSpeedRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS东速曲线****************************************/
    if(ui->checkBox_53->isChecked())
    {
        if(C3combinedEastSpeedRun == 0)
        {
            QPen pen;
            C3combinedEastSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C3combinedEastSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3combinedEastSpeedNum)->setData(curveX,C3VcombinedEastSpeed);
            customPlot->graph(C3combinedEastSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3combinedEastSpeedRun = 1;
            //customPlot->graph(C3combinedEastSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
           // customPlot->graph(C3combinedEastSpeedNum)->setVisible(true);
            customPlot->graph(C3combinedEastSpeedNum)->setData(curveX,C3VcombinedEastSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3combinedEastSpeedRun == 1)
        {
            C3combinedEastSpeedRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedNorthSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的GPS北速曲线****************************************/
    if(ui->checkBox_60->isChecked())
    {
        if(C3combinedNorthSpeedRun == 0)
        {
            QPen pen;
            C3combinedNorthSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,0,255));
            customPlot->graph(C3combinedNorthSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3combinedNorthSpeedNum)->setData(curveX,C3VcombinedNorthSpeed);
            customPlot->graph(C3combinedNorthSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3combinedNorthSpeedRun = 1;
            //customPlot->graph(C3combinedNorthSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_51_54_50_52_53_60();
        }
        else
        {
           // customPlot->graph(C3combinedNorthSpeedNum)->setVisible(true);
            customPlot->graph(C3combinedNorthSpeedNum)->setData(curveX,C3VcombinedNorthSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3combinedNorthSpeedRun == 1)
        {
            C3combinedNorthSpeedRun = 0;
            C3GPSlatitudeRun = 0;
            C3longitudeRun = 0;
            C3togetherSpeedRun = 0;
            C3headingAngleRun = 0;
            C3combinedEastSpeedRun = 0;

            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3的C3多普勒对水横向速度曲线****************************************/
    if(ui->checkBox_59->isChecked())
    {
        if(C3waterXRun == 0)
        {
            QPen pen;
            C3waterXNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(C3waterXNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3waterXNum)->setData(curveX,C3VwaterX);
            customPlot->graph(C3waterXNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3waterXRun = 1;
            //customPlot->graph(C3waterXNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_59_56_57_55_58();
        }
        else
        {
           // customPlot->graph(C3waterXNum)->setVisible(true);
            customPlot->graph(C3waterXNum)->setData(curveX,C3VwaterX);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3waterXRun == 1)
        {
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3bottomXRun = 0;
            C3bottomYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3多普勒对水纵向速度曲线****************************************/
    if(ui->checkBox_56->isChecked())
    {
        if(C3waterYRun == 0)
        {
            QPen pen;
            C3waterYNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(C3waterYNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3waterYNum)->setData(curveX,C3VwaterY);
            customPlot->graph(C3waterYNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3waterYRun = 1;
            //customPlot->graph(C3waterYNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_59_56_57_55_58();
        }
        else
        {
           // customPlot->graph(C3waterYNum)->setVisible(true);
            customPlot->graph(C3waterYNum)->setData(curveX,C3VwaterY);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3waterYRun == 1)
        {
            C3waterYRun = 0;
            C3waterXRun = 0;
            C3bottomXRun = 0;
            C3bottomYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    /**********************************C3的C3多普勒对底横向速度曲线****************************************/
    if(ui->checkBox_57->isChecked())
    {
        if(C3bottomXRun == 0)
        {
            QPen pen;
            C3bottomXNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(C3bottomXNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3bottomXNum)->setData(curveX,C3VbottomX);
            customPlot->graph(C3bottomXNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3bottomXRun = 1;
            //customPlot->graph(C3bottomXNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_59_56_57_55_58();
        }
        else
        {
           // customPlot->graph(C3bottomXNum)->setVisible(true);
            customPlot->graph(C3bottomXNum)->setData(curveX,C3VbottomX);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3bottomXRun == 1)
        {
            C3bottomXRun = 0;
            C3bottomYRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3多普勒对底纵向速度曲线****************************************/
    if(ui->checkBox_55->isChecked())
    {
        if(C3bottomYRun == 0)
        {
            QPen pen;
            C3bottomYNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,128));
            customPlot->graph(C3bottomYNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3bottomYNum)->setData(curveX,C3VbottomY);
            customPlot->graph(C3bottomYNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3bottomYRun = 1;
            //customPlot->graph(C3bottomYNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_59_56_57_55_58();
        }
        else
        {
           // customPlot->graph(C3bottomYNum)->setVisible(true);
            customPlot->graph(C3bottomYNum)->setData(curveX,C3VbottomY);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3bottomYRun == 1)
        {
            C3bottomYRun = 0;
            C3bottomXRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3electromagnetismSpeedRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************C3电磁速度曲线****************************************/
    if(ui->checkBox_58->isChecked())
    {
        if(C3electromagnetismSpeedRun == 0)
        {
            QPen pen;
            C3electromagnetismSpeedNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(147,108,0));
            customPlot->graph(C3electromagnetismSpeedNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(C3electromagnetismSpeedNum)->setData(curveX,C3VelectromagnetismSpeed);
            customPlot->graph(C3electromagnetismSpeedNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            C3electromagnetismSpeedRun = 1;
            //customPlot->graph(C3electromagnetismSpeedNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_59_56_57_55_58();
        }
        else
        {
           // customPlot->graph(C3electromagnetismSpeedNum)->setVisible(true);
            customPlot->graph(C3electromagnetismSpeedNum)->setData(curveX,C3VelectromagnetismSpeed);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(C3electromagnetismSpeedRun == 1)
        {
            C3electromagnetismSpeedRun = 0;
            C3bottomXRun = 0;
            C3waterXRun = 0;
            C3waterYRun = 0;
            C3bottomYRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
    if(0)//不显示零偏曲线2022-1-20
    {
        /**********************************C6X陀螺零偏****************************************/
        if(ui->checkBox_61->isChecked())
        {
            if(C6XGroyFloatRun == 0)
            {
                QPen pen;
                C6XGroyFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C6XGroyFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6XGroyFloatNum)->setData(curveX,C6VC6XGroyFloat);
                customPlot->graph(C6XGroyFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6XGroyFloatRun = 1;
                //customPlot->graph(C6XGroyFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_61_63_62();
            }
            else
            {
                // customPlot->graph(C6XGroyFloatNum)->setVisible(true);
                customPlot->graph(C6XGroyFloatNum)->setData(curveX,C6VC6XGroyFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6XGroyFloatRun == 1)
            {
                C6XGroyFloatRun = 0;
                C6YGroyFloatRun = 0;
                C6ZGroyFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Y陀螺零偏****************************************/
        if(ui->checkBox_63->isChecked())
        {
            if(C6YGroyFloatRun == 0)
            {
                QPen pen;
                C6YGroyFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C6YGroyFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6YGroyFloatNum)->setData(curveX,C6VC6YGroyFloat);
                customPlot->graph(C6YGroyFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6YGroyFloatRun = 1;
                //customPlot->graph(C6YGroyFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_61_63_62();
            }
            else
            {
                // customPlot->graph(C6YGroyFloatNum)->setVisible(true);
                customPlot->graph(C6YGroyFloatNum)->setData(curveX,C6VC6YGroyFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6YGroyFloatRun == 1)
            {
                C6YGroyFloatRun = 0;
                C6XGroyFloatRun = 0;
                C6ZGroyFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Z陀螺零偏****************************************/
        if(ui->checkBox_62->isChecked())
        {
            if(C6ZGroyFloatRun == 0)
            {
                QPen pen;
                C6ZGroyFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C6ZGroyFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6ZGroyFloatNum)->setData(curveX,C6VC6ZGroyFloat);
                customPlot->graph(C6ZGroyFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6ZGroyFloatRun = 1;
                //customPlot->graph(C6ZGroyFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_61_63_62();
            }
            else
            {
                // customPlot->graph(C6ZGroyFloatNum)->setVisible(true);
                customPlot->graph(C6ZGroyFloatNum)->setData(curveX,C6VC6ZGroyFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6ZGroyFloatRun == 1)
            {
                C6ZGroyFloatRun = 0;
                C6XGroyFloatRun = 0;
                C6YGroyFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6X加速度计零偏****************************************/
        if(ui->checkBox_65->isChecked())
        {
            if(C6XAccelerometerFloatRun == 0)
            {
                QPen pen;
                C6XAccelerometerFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(255,0,0));
                customPlot->graph(C6XAccelerometerFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6XAccelerometerFloatNum)->setData(curveX,C6VC6XAccelerometerFloat);
                customPlot->graph(C6XAccelerometerFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6XAccelerometerFloatRun = 1;
                //customPlot->graph(C6XAccelerometerFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_65_64_66();
            }
            else
            {
                // customPlot->graph(C6XAccelerometerFloatNum)->setVisible(true);
                customPlot->graph(C6XAccelerometerFloatNum)->setData(curveX,C6VC6XAccelerometerFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6XAccelerometerFloatRun == 1)
            {
                C6XAccelerometerFloatRun = 0;
                C6YAccelerometerFloatRun = 0;
                C6ZAccelerometerFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Y加速度计零偏****************************************/
        if(ui->checkBox_64->isChecked())
        {
            if(C6YAccelerometerFloatRun == 0)
            {
                QPen pen;
                C6YAccelerometerFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(128,0,255));
                customPlot->graph(C6YAccelerometerFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6YAccelerometerFloatNum)->setData(curveX,C6VC6YAccelerometerFloat);
                customPlot->graph(C6YAccelerometerFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6YAccelerometerFloatRun = 1;
                //customPlot->graph(C6YAccelerometerFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_65_64_66();
            }
            else
            {
                // customPlot->graph(C6YAccelerometerFloatNum)->setVisible(true);
                customPlot->graph(C6YAccelerometerFloatNum)->setData(curveX,C6VC6YAccelerometerFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6YAccelerometerFloatRun == 1)
            {
                C6YAccelerometerFloatRun = 0;
                C6XAccelerometerFloatRun = 0;
                C6ZAccelerometerFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }

        /**********************************C6Z加速度计零偏****************************************/
        if(ui->checkBox_66->isChecked())
        {
            if(C6ZAccelerometerFloatRun == 0)
            {
                QPen pen;
                C6ZAccelerometerFloatNum = customPlot->graphCount();
                customPlot->addGraph();
                pen.setColor(QColor(0,143,122));
                customPlot->graph(C6ZAccelerometerFloatNum)->setPen(pen);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(C6ZAccelerometerFloatNum)->setData(curveX,C6VC6ZAccelerometerFloat);
                customPlot->graph(C6ZAccelerometerFloatNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
                C6ZAccelerometerFloatRun = 1;
                //customPlot->graph(C6ZAccelerometerFloatNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
                set_checkBox_65_64_66();
            }
            else
            {
                // customPlot->graph(C6ZAccelerometerFloatNum)->setVisible(true);
                customPlot->graph(C6ZAccelerometerFloatNum)->setData(curveX,C6VC6ZAccelerometerFloat);
                //重绘
                customPlot->replot(QCustomPlot::rpQueuedReplot);
            }
        }
        else
        {
            if(C6ZAccelerometerFloatRun == 1)
            {
                C6ZAccelerometerFloatRun = 0;
                C6XAccelerometerFloatRun = 0;
                C6YAccelerometerFloatRun = 0;
                ui->customPlot2->clearGraphs();
                customPlot->replot(QCustomPlot::rpQueuedReplot);

            }
        }
    }

    /**********************************东速误差****************************************/
    if(ui->checkBox_67->isChecked())
    {
        if(eastSpeedErrorRun == 0)
        {
            QPen pen;
            eastSpeedErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(eastSpeedErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(eastSpeedErrorNum)->setData(curveX,VeastSpeedError);
            customPlot->graph(eastSpeedErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            eastSpeedErrorRun = 1;
            //customPlot->graph(eastSpeedErrorNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_67_69_68();
        }
        else
        {
           // customPlot->graph(eastSpeedErrorNum)->setVisible(true);
            customPlot->graph(eastSpeedErrorNum)->setData(curveX,VeastSpeedError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(eastSpeedErrorRun == 1)
        {
            eastSpeedErrorRun = 0;
            northSpeedErrorRun = 0;
            togetherSpeedErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************北速误差****************************************/
    if(ui->checkBox_69->isChecked())
    {
        if(northSpeedErrorRun == 0)
        {
            QPen pen;
            northSpeedErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(northSpeedErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(northSpeedErrorNum)->setData(curveX,VnorthSpeedError);
            customPlot->graph(northSpeedErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            northSpeedErrorRun = 1;
            //customPlot->graph(northSpeedErrorNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_67_69_68();
        }
        else
        {
           // customPlot->graph(northSpeedErrorNum)->setVisible(true);
            customPlot->graph(northSpeedErrorNum)->setData(curveX,VnorthSpeedError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(northSpeedErrorRun == 1)
        {
            northSpeedErrorRun = 0;
            togetherSpeedErrorRun = 0;
            eastSpeedErrorRun = 0;
            ui->customPlot2->clearGraphs();
            customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************合速误差****************************************/
    if(ui->checkBox_68->isChecked())
    {
        if(togetherSpeedErrorRun == 0)
        {
            QPen pen;
            togetherSpeedErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(togetherSpeedErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(7);
            customPlot->graph(togetherSpeedErrorNum)->setData(curveX,VtogetherSpeedError);
            customPlot->graph(togetherSpeedErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            togetherSpeedErrorRun = 1;
            //customPlot->graph(togetherSpeedErrorNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_67_69_68();
        }
        else
        {
           // customPlot->graph(togetherSpeedErrorNum)->setVisible(true);
            customPlot->graph(togetherSpeedErrorNum)->setData(curveX,VtogetherSpeedError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(togetherSpeedErrorRun == 1)
        {
            togetherSpeedErrorRun = 0;
            northSpeedErrorRun = 0;
            eastSpeedErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************纬度误差****************************************/
    if(ui->checkBox_70->isChecked())
    {
        if(latitudeErrorRun == 0)
        {
            QPen pen;
            latitudeErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(255,0,0));
            customPlot->graph(latitudeErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(5);
            customPlot->graph(latitudeErrorNum)->setData(curveX,VlatitudeError);
            customPlot->graph(latitudeErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            latitudeErrorRun = 1;
            //customPlot->graph(latitudeErrorNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_70_72_71();
        }
        else
        {
           // customPlot->graph(latitudeErrorNum)->setVisible(true);
            customPlot->graph(latitudeErrorNum)->setData(curveX,VlatitudeError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(latitudeErrorRun == 1)
        {
            latitudeErrorRun = 0;
            longitudeErrorRun = 0;
            positionErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************经度误差****************************************/
    if(ui->checkBox_72->isChecked())
    {
        if(longitudeErrorRun == 0)
        {
            QPen pen;
            longitudeErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(128,0,255));
            customPlot->graph(longitudeErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(5);
            customPlot->graph(longitudeErrorNum)->setData(curveX,VlongitudeError);
            customPlot->graph(longitudeErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            longitudeErrorRun = 1;
            //customPlot->graph(longitudeErrorNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_70_72_71();
        }
        else
        {
           // customPlot->graph(longitudeErrorNum)->setVisible(true);
            customPlot->graph(longitudeErrorNum)->setData(curveX,VlongitudeError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(longitudeErrorRun == 1)
        {
            longitudeErrorRun = 0;
            latitudeErrorRun = 0;
            positionErrorRun = 0;
            ui->customPlot2->clearGraphs();
            customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }

    /**********************************合速误差****************************************/
    if(ui->checkBox_71->isChecked())
    {
        if(positionErrorRun == 0)
        {
            QPen pen;
            positionErrorNum = customPlot->graphCount();
            customPlot->addGraph();
            pen.setColor(QColor(0,143,122));
            customPlot->graph(positionErrorNum)->setPen(pen);
            customPlot->yAxis->setNumberPrecision(5);
            customPlot->graph(positionErrorNum)->setData(curveX,VpositionError);
            customPlot->graph(positionErrorNum)->rescaleAxes();                   //使曲线平铺整个画面
            //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
            positionErrorRun = 1;
            //customPlot->graph(positionErrorNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
            set_checkBox_70_72_71();
        }
        else
        {
           // customPlot->graph(positionErrorNum)->setVisible(true);
            customPlot->graph(positionErrorNum)->setData(curveX,VpositionError);
            //重绘
            customPlot->replot(QCustomPlot::rpQueuedReplot);
        }
    }
    else
    {
        if(positionErrorRun == 1)
        {
            positionErrorRun = 0;
            latitudeErrorRun = 0;
            longitudeErrorRun = 0;
            ui->customPlot2->clearGraphs();
             customPlot->replot(QCustomPlot::rpQueuedReplot);

        }
    }
}

/*b
 * @breif 设置LED灯，通讯正常为绿色，通讯失败为红色
 */
void MainWindow::setLED1(QLabel* label, int color, int size)
{
    // 将label中的文字清空
       label->setText("");
       // 先设置矩形大小
       // 如果ui界面设置的label大小比最小宽度和高度小，矩形将被设置为最小宽度和最小高度；
       // 如果ui界面设置的label大小比最小宽度和高度大，矩形将被设置为最大宽度和最大高度；
       QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
       QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
       QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
       QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
       // 再设置边界形状及边框
       QString border_radius = QString("border-radius: %1px;").arg(size/2);    // 边框是圆角，半径为size/2
       QString border = QString("border:1px solid black;");                    // 边框为1px黑色
       // 最后设置背景颜色
       QString background = "background-color:";
       switch (color) {
       case 0:
           // 灰色
           background += "rgb(190,190,190)";
           break;
       case 1:
           // 红色
           background += "rgb(255,0,0)";
           break;
       case 2:
           // 绿色
           background += "rgb(0,255,0)";
           break;
       case 3:
           // 黄色
           background += "rgb(255,255,0)";
           break;
       default:
           break;
       }

       const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
       label->setStyleSheet(SheetStyle);

}
#ifdef QEXTSERIALPORT
void MainWindow::InitSerialPortName()
{
    // 清空下拉框
    ui->box_portName->clear();
    QStringList comList;//串口号
    comList<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6"
          <<"COM7"<<"COM8"<<"COM9"<<"COM10"<<"COM11"<<"COM12"
         <<"COM13"<<"COM14"<<"COM15";
    //通过QSerialPortInfo查找可用串口
     ui->box_portName->addItems(comList);
}
#endif
#ifdef SERIALPORT
void MainWindow::InitSerialPortName()
{
    // 清空下拉框
    ui->box_portName->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString showName = info.portName();
        // QString showName = info.portName()+":"+info.description();
        ui->box_portName->addItem(showName);
    }
}
#endif
/*
 * @breif 将16进制字符串转换为对应的字节序列
 */
QByteArray MainWindow::HexStringToByteArray(QString HexString)
{
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");

    foreach (QString s, sl) {
        if(!s.isEmpty())
        {
            char c = s.toInt(&ok,16)&0xFF;
            if(ok){
                ret.append(c);
            }else{
                //qDebug()<<"非法的16进制字符："<<s;
                //QMessageBox::warning(0,tr("错误："),QString("非法的16进制字符: \"%1\"").arg(s));
            }
        }
    }
    //qDebug()<<ret;
    return ret;
}

/*
 * @breif 将字节序列转换为对应的16进制字符串
 */
QString MainWindow::ByteArrayToHexString(QByteArray data)
{
    QString ret(data.toHex().toUpper());
    int len = ret.length()/2;
    //qDebug()<<len;
    for(int i=1;i<len;i++)
    {
        //qDebug()<<i;
        ret.insert(2*i+i-1," ");
    }

    return ret;
}



#ifdef SERIALPORT
void MainWindow::handleResults(QByteArray result)
{
    qtime->stop();

#endif

#ifdef QEXTSERIALPORT
void MainWindow::handleResults()
{

    QByteArray result;
    if(serial_1 !=NULL)
    {
        if(serial_1->bytesAvailable()<=0)
        {
            nonMessage++;
            if(nonMessage >= 100)
            {
                if(qGetdataTime->isActive())
                    qGetdataTime->stop();
            }
            return;
        }
        else
        {
            nonMessage = 0;
            if(!qGetdataTime->isActive())
                qGetdataTime->start(addDataPeri);
            mySleep(handleResultDelay);
            QByteArray buffertemp = serial_1->readAll();
            buffertemp = buffertemp.toHex();
            result = buffertemp;
        }

    }
#endif
    union C5ValueUnion_
    {
        qint32 qint32Value;
        float floatValue;
    }C5ValueUnion;
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("yyyy-MM-dd hh:mm:ss");

    ui->lineEdit_4->setText(dateStr);  //显示界面的北京时间
    QString bufferStr = QString(result);


    if(1)   //新建历史数据文件
    {
        if(dataInvaildRecord > SaveFileRecord)
        {
            C1fileSave.close();
            C2fileSave.close();
            C3fileSave.close();
            C5fileSave.close();
            fileSaveNum++;
            QString fileSaveNumStr = QString::number(fileSaveNum,10);
            SaveFileRecord = SaveFileRecord + 400000;
            QDateTime current_date_time =QDateTime::currentDateTime();
            QString dateStr =current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
            QString C1HisDataName = "./history/nav1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C2HisDataName = "./history/cond1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C3HisDataName = "./history/ref1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
            QString C5HisDataName = "./history/imu1s_"+ dateStr+"_"+fileSaveNumStr+".csv";

             C1fileSave.setFileName(C1HisDataName);
            if(!C1fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C1文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC1(&C1fileSave);
            QString headStr1 = "时间序号,标识号,系统时间,状态时间,纬度°,经度°,东速kn,北速kn,航向角°,横摇角°,纵摇角°,航向角速度°/s,横摇角速度°/s,纵摇角速度°/s,垂荡m,垂速m/s,横荡m,横速m/s,纵荡m,纵速m/s,时码有效,经纬度有效,东北速有效,航向有效,纵横摇有效,角速度有效,升沉有效,纵横荡有效,导航状态,工作位置,切换模式,时码,参考纬度°,参考经度°,参考组合东速kn,参考组合北速kn,参考阻尼东速kn,参考阻尼北速kn,参考航向°,参考经纬度,参考组合速度,参考阻尼,参考航向";
            dataOutC1<<headStr1.toUtf8();

            C2fileSave.setFileName(C2HisDataName);
            if(!C2fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C2文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC2(&C2fileSave);
            QString headStr2 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到陀螺标定参数,收到加速度计标定参数,收到陀螺零偏温补系数,收到加速度计零位温补系数,收到装订航向,收到等效零偏,收到漂移补偿,收到状态切换命令,收到系统姿态零位,收到惯组和输出姿态零位,收到杆臂,收到显控参考信息,收到1PPS信号,收到录取同步信号,收到主惯导信息,收到系统编号,收到在舰位置,收到IP地址,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GX漂移估计补偿,GY漂移估计补偿,GZ漂移估计补偿,AX零偏估计补偿,AY零偏估计补偿,AZ零偏估计补偿,水平姿态误差估计补偿,航向误差估计补偿,速度误差估计补偿,位置误差估计补偿,直航状态,静止状态,锚泊状态,振动状态,冲击状态,主惯导位置有效,主惯导速度有效,主惯导姿态有效,主惯导角速度有效,陀螺故障,加速度计故障,IF板故障,采集板故障,通信板故障,接口板故障,解算异常故障,备用电源故障,GX陀螺常值漂移°/h,GY陀螺常值漂移°/h,GZ陀螺常值漂移°/h,AX加速度计零偏mg,AY加速度计零偏mg,AZ加速度计零偏mg";
            dataOutC2<<headStr2.toUtf8();

            C3fileSave.setFileName(C3HisDataName);
            if(!C3fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C3文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC3(&C3fileSave);
            QString headStr3 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到1PPS信号,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GPS纬度°,GPS经度°,GPS合速kn,GPS航向°,GPS东速kn,GPS北速kn,电磁速度kn,多普勒对水横向速度kn,多普勒对水纵向速度kn,多普勒对底横向速度kn,多普勒对底纵向速度kn,时码：日月年,时码：天秒s,插值时间us,GPS卫星数,GPS水平精度因子";
            dataOutC3<<headStr3.toUtf8();

             C5fileSave.setFileName(C5HisDataName);
            if(!C5fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的C5文件失败，请检查文件名和是否具有写入权限！"));
                return;
            }
            QTextStream dataOutC5(&C5fileSave);
            QString headStr5 = "时间序号,标识号,系统时间,X陀螺1s角增量°/h,Y陀螺1s角增量°/h,Z陀螺1s角增量°/h,X加速度计1s速度增量m/s/s,Y加速度计1s速度增量m/s/s,Z加速度计1s速度增量m/s/s,X陀螺1s补偿后角增量°/h,Y陀螺1s补偿后角增量°/h,Z陀螺1s补偿后角增量°/h,X加速度计1s补偿后速度增量m/s/s,Y加速度计1s补偿后速度增量m/s/s,Z加速度计1s补偿后速度增量m/s/s,X陀螺差频p/s,Y陀螺差频p/s,Z陀螺差频p/s,X加速度计差频p/s,Y加速度计差频p/s,Z加速度计差频p/s,X陀螺抖幅p/s,Y陀螺抖幅p/s,Z陀螺抖幅p/s,X陀螺抖频Hz,Y陀螺抖频Hz,Z陀螺抖频Hz,X陀螺温度1°C,X陀螺温度2°C,Y陀螺温度1°C,Y陀螺温度2°C,Z陀螺温度1°C,Z陀螺温度2°C,IF板温度°C,X加速度计温度°C,Y加速度计温度°C,Z加速度计温度°C,采集板温度°C";
            dataOutC5<<headStr5.toUtf8();
        }


    }

    /***********************************************解析周期数据**************************************************/

    if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&& bufferStr.length()==944)
    {
        dataInvaildRecord++;
        int C1checkNumInt = 0;
        QString C1checkNumStr;
        for(int i= 4;i<182;i=i+2)
        {
            C1checkNumInt = C1checkNumInt + bufferStr.mid(i,2).toInt(nullptr,16);
        }
        C1checkNumStr = QString::number(C1checkNumInt,16).right(2);
        if(bufferStr[4] == 'c' && bufferStr[5] == '1')
        {
            if(C1checkNumStr == bufferStr.mid(182,2))
            {
                /****************************************解析导航信息有效位**********************************************/
                QString bufferStrC1Vaild = QString(bufferStr);
                QString bufferStrC1 = QString(bufferStr);
                bufferStrC1Vaild.remove(0,126); //定位到导航信息有效位置
                //quint8 NavVaild = quint8(bufferStrC1Vaild.left(2).toUInt(nullptr,16)); //暂时不采用有效位
                quint8 NavVaild = 0xFF;
                QString timeFramesVaild = QString::number((NavVaild) >> (1-1)&1);           //时码有效标志位     Bit0
                QString longitudeLatitudeVaild = QString::number((NavVaild) >> (2-1)&1);    //经纬度有效标志位   Bit1
                QString northeastSpeed = QString::number((NavVaild) >> (3-1)&1);            //东北速有效标志位   Bit2
                QString headingVaild = QString::number((NavVaild) >> (4-1)&1);              //航向有效标志位     Bit3
                QString verHorShakVaild = QString::number((NavVaild) >> (5-1)&1);           //纵横摇有效标志位   Bit4
                QString angulaVelocityVaild = QString::number((NavVaild) >> (6-1)&1);       //角速度有效标志位   Bit5
                QString heaveVaild = QString::number((NavVaild) >> (7-1)&1);                //升沉有效标志位     Bit6
                QString swayVaild = QString::number((NavVaild) >> (8-1)&1);                 //纵横荡有效标志位    Bit7

                /****************************************解析系统时间3-6字节*********************************************/
                bufferStrC1.remove(0,6);
                //QString SysTimeStrTemp = bufferStrC1.left(8);

                QString SysTimeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);

                quint32 sysTimeMs = quint32(SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒

                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                //int dayInt = houInt * 24;
                int dayInt = houInt * 24;

                //long day = ms / dayInt;
                long day = 0;
                long hour = (sysTimeMs - day * dayInt) / houInt;
                long minute = (sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                //QString dayQStr  = QString::number(day,10);
                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;

                ui->lineEdit_5->setText(sysTimeStr);

                /****************************************解析状态时间7-10字节*********************************************/
                bufferStrC1.remove(0,8);
                QString stateMsStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);

                quint32 stateMs = quint32(stateMsStr.toUInt(nullptr,16));   //状态时间，毫秒

                hour = (stateMs - day * dayInt) / houInt;
                minute = (stateMs - day * dayInt- hour * houInt) / minInt ;
                second = (stateMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                milliSecond = stateMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;
                houQStr  = QString::number(hour,10);
                minQStr  = QString::number(minute,10);
                secQStr  = QString::number(second,10);
                msecQStr = QString::number(milliSecond,10);
                QString stateTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;
                ui->lineEdit_6->setText(stateTimeStr);

                /****************************************解析纬度11-14字节*********************************************/
                bufferStrC1.remove(0,8);
                QString latitudeStrDis;
                QString latitudeStrDis_D;
                if(longitudeLatitudeVaild == "1")
                {
                    QString latitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 latitudeInt32 = qint32(latitudeStr.toUInt(nullptr,16));   //状态时间，毫秒
                    //qreal a= qPow(2,-31);
                    latitude = latitudeInt32 * 90.0 * qPow(2,-31);
                    char NS = 'N';
                    if(latitude > 0){
                        NS = 'N';
                    }
                    else{
                        NS= 'S';
                    }
                    QString latStr = QString::number(latitude,'f',4);
                    qreal latitudeAbs = fabs(latStr.toFloat());
                    double latitudeAbsDeg =  floor(latitudeAbs);
                    QString latitudeDegStr = QString("%1").arg(latitudeAbsDeg);
                    double latitudeAbsMin  =  (latitudeAbs - latitudeAbsDeg)* 60.0;

                    //QString latitudeMinStr = QString::asprintf("%.3f",latitudeAbsMin);
                    QString latitudeMinStr = QString::number(latitudeAbsMin,'f',3);
                    //QString latitudeMinStr = QString("%1").arg(latitudeAbsMin);
                    latitudeStrDis = NS+latitudeDegStr+"°"+latitudeMinStr+"′";
                    latitudeStrDis_D = latStr;
                    //ui->lineEdit_7->setPlainText(latitudeStrDis);
                    //ui->lineEdit_7->setTextColor(Qt::blue);

                    if(isDegree == 0)
                        ui->lineEdit_7->setText(latitudeStrDis);
                    else
                         ui->lineEdit_7->setText(NS+latStr+"°");


                }

                /****************************************解析经度15-18字节*********************************************/
                bufferStrC1.remove(0,8);
                QString longitudeStrDis;
                QString longitudeStrDis_D;
                if(longitudeLatitudeVaild == "1")
                {
                    QString longitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 longitudeInt32 = qint32(longitudeStr.toUInt(nullptr,16));   //状态时间，毫秒
                    //qreal a= qPow(2,-31);
                    longitude = longitudeInt32 * 180.0 * qPow(2,-31);
                    char WE = 'E';
                    if(longitudeInt32 > 0){
                        WE = 'E';
                    }
                    else{
                        WE= 'W';
                    }
                    QString lontStr = QString::number(longitude,'f',4);
                    qreal longitudeAbs = fabs(lontStr.toFloat());
                    double longitudeAbsDeg =  floor(longitudeAbs);
                    QString longitudeDegStr = QString("%1").arg(longitudeAbsDeg);
                    double longitudeAbsMin  =  (longitudeAbs - longitudeAbsDeg)* 60.0;
                    QString longitudeMinStr = QString::number(longitudeAbsMin,'f',3);
                    //QString longitudeMinStr = QString("%1").arg(longitudeAbsMin);
                    longitudeStrDis = WE+longitudeDegStr+"°"+longitudeMinStr+"′";
                    longitudeStrDis_D = lontStr;

                   //ui->lineEdit_8->setTextColor(Qt::blue);

                   if(isDegree == 0)
                       ui->lineEdit_8->setText(longitudeStrDis);
                   else
                       ui->lineEdit_8->setText(WE+lontStr+"°");

                }

                /****************************************解析东速19-22字节*********************************************/
                bufferStrC1.remove(0,8);
                QString eastSpeedStrDis;
                QString eastSpeedStrDis_D;
                if(northeastSpeed == "1")
                {
                    QString eastSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 eastSpeedInt32 = qint32(eastSpeedStr.toUInt(nullptr,16));
                    eastSpeed = eastSpeedInt32 * 1000.0 * qPow(2,-31);
                    //QString eastSpeedStrDis = QString("%1").arg(eastSpeed)+"kn";
                    eastSpeedStrDis = QString::number(eastSpeed,'f',4)+"kn";
                    //ui->lineEdit_16->setPlainText(eastSpeedStrDis);
                    eastSpeedStrDis_D = QString::number(eastSpeed,'f',4);
                    //ui->textEdit_7->setTextColor(Qt::blue);

                    ui->lineEdit_16->setText(eastSpeedStrDis);
                }

                /****************************************解析北速23-26字节*********************************************/
                bufferStrC1.remove(0,8);
                QString northSpeedStrDis;
                QString northSpeedStrDis_D;
                if(northeastSpeed == "1")
                {
                    QString northSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 northSpeedInt32 = qint32(northSpeedStr.toUInt(nullptr,16));
                    northSpeed = northSpeedInt32 * 1000.0 * qPow(2,-31);
                    //QString northSpeedStrDis = QString("%1").arg(northSpeed)+"kn";
                    northSpeedStrDis = QString::number(northSpeed,'f',4)+"kn";
                    northSpeedStrDis_D = QString::number(northSpeed,'f',4);
                    //ui->lineEdit_15->setPlainText(northSpeedStrDis);

                        //ui->textEdit_6->setTextColor(Qt::blue);

                    ui->lineEdit_15->setText(northSpeedStrDis);
                }

                /*******************************************计算合速*********************************************************/
                qreal togetherSpeed = sqrt(qPow(northSpeed,2) + qPow(eastSpeed,2));
                QString togetherSpeedStrDis = QString::number(togetherSpeed,'f',4)+"kn";

                    //ui->textEdit_8->setTextColor(Qt::blue);

                ui->lineEdit_17->setText(togetherSpeedStrDis);

                /****************************************解析航向角27-30字节*********************************************/
                bufferStrC1.remove(0,8);
                QString headingAngleStrDis;
                QString headingAngleStrDis_D;
                if(headingVaild == "1")
                {

                    QString headingAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    quint32 headingAngleInt32 = quint32(headingAngleStr.toUInt(nullptr,16));
                    headingAngle = headingAngleInt32 * 360.0 * qPow(2,-32);
                    QString headingStr = QString::number(headingAngle,'f',4);
                    double headingAngleAbsDeg =  floor(headingStr.toFloat());
                    QString headingAngleAbsStr = QString("%1").arg(headingAngleAbsDeg);
                    double headingAngleMin  =  (headingAngle - headingAngleAbsDeg)* 60.0;
                    QString headingAngleMinStr = QString::number(headingAngleMin,'f',3);
                    //QString headingAngleMinStr = QString("%1").arg(headingAngleMin);
                    headingAngleStrDis = headingAngleAbsStr+"°"+headingAngleMinStr+"′";
                   headingAngleStrDis_D = headingStr;
                    // ui->lineEdit_9->setPlainText(headingAngleStrDis);


                        //ui->textEdit_3->setTextColor(Qt::blue);
                     if(isDegree == 0)
                         ui->lineEdit_9->setText(headingAngleStrDis);
                     else
                         ui->lineEdit_9->setText(headingStr+"°");
                }

                /****************************************解析横摇角31-34字节*********************************************/
                bufferStrC1.remove(0,8);
                QString rollAngleStrDis;
                QString rollAngleStrDis_D;
                if(verHorShakVaild == "1")
                {
                    QString rollAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 rollAngleInt32 = qint32(rollAngleStr.toUInt(nullptr,16));
                    rollAngle = rollAngleInt32 * 180.0 * qPow(2,-31);
                    QString rolStr = QString::number(rollAngle,'f',4);
                    double rollAngleAbsDegTemp =fabs(rolStr.toFloat());
                    double rollAngleAbsDeg =  floor(rollAngleAbsDegTemp);
                    QString rollAngleAbsStr = QString("%1").arg(rollAngleAbsDeg);
                    double rollAngleMin  =  (rollAngleAbsDegTemp - rollAngleAbsDeg)* 60.0;
                    QString rollAngleMinStr = QString::number(rollAngleMin,'f',3);
                    //QString rollAngleMinStr = QString("%1").arg(rollAngleMin);
                    rollAngleStrDis_D = rolStr;
                    if(rollAngle <0){
                        rollAngleStrDis = "-" + rollAngleAbsStr+"°"+rollAngleMinStr+"′";
                    }
                    else{
                        rollAngleStrDis = rollAngleAbsStr+"°"+rollAngleMinStr+"′";
                    }
                    //ui->lineEdit_10->setPlainText(rollAngleStrDis);

                    //ui->textEdit_4->setTextColor(Qt::blue);

                    if(isDegree == 0)
                        ui->lineEdit_10->setText(rollAngleStrDis);
                    else
                         ui->lineEdit_10->setText(rolStr+"°");
                }


                /****************************************解析纵摇角35-38字节*********************************************/
                bufferStrC1.remove(0,8);
                QString pitchAngleStrDis;
                QString pitchAngleStrDis_D;
                if(verHorShakVaild == "1")
                {
                    QString pitchAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 pitchAngleInt32 = qint32(pitchAngleStr.toUInt(nullptr,16));
                    pitchAngle = pitchAngleInt32 * 180.0 * qPow(2,-31);
                    QString pitchStr = QString::number(pitchAngle,'f',4);
                    double pitchAngleAbsDegTemp =fabs(pitchStr.toFloat());
                    double pitchAngleAbsDeg =  floor(pitchAngleAbsDegTemp);
                    QString pitchAngleAbsStr = QString("%1").arg(pitchAngleAbsDeg);
                    double pitchAngleMin  =  (pitchAngleAbsDegTemp - pitchAngleAbsDeg)* 60.0;
                    QString pitchAngleMinStr = QString::number(pitchAngleMin,'f',3);
                    //QString pitchAngleMinStr = QString("%1").arg(pitchAngleMin);
                    pitchAngleStrDis_D = pitchStr;
                    if(pitchAngle <0){
                        pitchAngleStrDis = "-" + pitchAngleAbsStr+"°"+pitchAngleMinStr+"′";
                    }
                    else{
                        pitchAngleStrDis = pitchAngleAbsStr+"°"+pitchAngleMinStr+"′";
                    }
                    //ui->lineEdit_11->setPlainText(pitchAngleStrDis);

                        //ui->textEdit_5->setTextColor(Qt::blue);
                    if(isDegree == 0)
                        ui->lineEdit_11->setText(pitchAngleStrDis);
                    else
                        ui->lineEdit_11->setText(pitchStr+"°");
                }


                /****************************************解析航向角速度39-42字节*********************************************/
                bufferStrC1.remove(0,8);
                QString headingAngularSpeedStrDis;
                QString headingAngularSpeedStrDis_D;
                if(angulaVelocityVaild == "1")
                {
                    QString headingAngularSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 headingAngularSpeedInt32 = qint32(headingAngularSpeedStr.toUInt(nullptr,16));
                    qreal headingAngularSpeed = headingAngularSpeedInt32 * 400.0 * qPow(2,-31);
                    headingAngularSpeedStrDis = QString::number(headingAngularSpeed,'f',4)+ "°/s";
                    headingAngularSpeedStrDis_D = QString::number(headingAngularSpeed,'f',4);
                    //ui->lineEdit_12->setPlainText(headingAngularSpeedStrDis);

                        //ui->textEdit_9->setTextColor(Qt::blue);

                    ui->lineEdit_12->setText(headingAngularSpeedStrDis);
                }

                /****************************************解析横摇角速度43-46字节*********************************************/
                bufferStrC1.remove(0,8);
                QString rollAngleSpeedStrDis;
                QString rollAngleSpeedStrDis_D;
                if(angulaVelocityVaild == "1")
                {
                    QString rollAngleSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 rollAngleSpeedInt32 = qint32(rollAngleSpeedStr.toUInt(nullptr,16));
                    qreal rollAngleSpeed = rollAngleSpeedInt32 * 400.0 * qPow(2,-31);
                    rollAngleSpeedStrDis = QString::number(rollAngleSpeed,'f',4)+ "°/s";
                   rollAngleSpeedStrDis_D = QString::number(rollAngleSpeed,'f',4);
                    //ui->lineEdit_13->setPlainText(rollAngleSpeedStrDis);

                        //ui->textEdit_10->setTextColor(Qt::blue);

                    ui->lineEdit_13->setText(rollAngleSpeedStrDis);
                }

                /****************************************解析纵摇角速度37-50字节*********************************************/
                bufferStrC1.remove(0,8);
                QString pitchAngleSpeedStrDis;
                QString pitchAngleSpeedStrDis_D;
                if(angulaVelocityVaild == "1")
                {
                    QString pitchAngleSpeedStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    qint32 pitchAngleSpeedInt32 = qint32(pitchAngleSpeedStr.toUInt(nullptr,16));
                    qreal pitchAngleSpeed = pitchAngleSpeedInt32 * 400.0 * qPow(2,-31);
                    pitchAngleSpeedStrDis = QString::number(pitchAngleSpeed,'f',4) + "°/s";
                    pitchAngleSpeedStrDis_D = QString::number(pitchAngleSpeed,'f',4);
                    //ui->lineEdit_14->setPlainText(pitchAngleSpeedStrDis);
                      //ui->textEdit_11->setTextColor(Qt::blue);

                    ui->lineEdit_14->setText(pitchAngleSpeedStrDis);
                }

                /****************************************解析垂荡51-52字节*********************************************/
                bufferStrC1.remove(0,8);
                QString heaveStrDis;
                QString heaveStrDis_D;
                if(heaveVaild == "1")
                {
                    QString heaveStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 heaveInt16 = qint16(heaveStr.toUInt(nullptr,16));
                    heave = heaveInt16 * 100.0 * qPow(2,-15);
                    heaveStrDis = QString::number(heave,'f',2) + "m";
                    heaveStrDis_D = QString::number(heave,'f',2);
                    //ui->lineEdit_18->setPlainText(heaveStrDis);

                        //ui->textEdit_12->setTextColor(Qt::blue);

                    ui->lineEdit_18->setText(heaveStrDis);
                }

                /****************************************解析垂速53-54字节*********************************************/
                QString verticalVelocityStrDis;
                QString verticalVelocityStrDis_D;
                if(heaveVaild == "1")

                {
                    bufferStrC1.remove(0,4);
                    QString verticalVelocityStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 verticalVelocityInt16 = qint16(verticalVelocityStr.toUInt(nullptr,16));
                    qreal verticalVelocity = verticalVelocityInt16 * 100.0 * qPow(2,-15);
                    verticalVelocityStrDis = QString::number(verticalVelocity,'f',2) + "m/s";
                    verticalVelocityStrDis_D = QString::number(verticalVelocity,'f',2);
                    //ui->lineEdit_19->setPlainText(verticalVelocityStrDis);

                        //ui->textEdit_13->setTextColor(Qt::blue);

                    ui->lineEdit_19->setText(verticalVelocityStrDis);
                }

                /****************************************解析横荡55-56字节*********************************************/
                bufferStrC1.remove(0,4);
                QString swayStrDis;
                QString swayStrDis_D;
                if(swayVaild == "1")
                {
                    QString swayStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 swayInt16 = qint16(swayStr.toUInt(nullptr,16));
                    sway = swayInt16 * 100.0 * qPow(2,-15);
                    swayStrDis = QString::number(sway,'f',2) + "m";
                    //ui->lineEdit_20->setPlainText(swayStrDis);
                    swayStrDis_D = QString::number(sway,'f',2);
                        //ui->textEdit_14->setTextColor(Qt::blue);

                    ui->lineEdit_20->setText(swayStrDis);
                }

                /****************************************解析横速57-58字节*********************************************/
                bufferStrC1.remove(0,4);
                QString transverseVelocityStrDis;
                QString transverseVelocityStrDis_D;
                if(swayVaild == "1")
                {
                    QString transverseVelocityStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 transverseVelocityInt16 = qint16(transverseVelocityStr.toUInt(nullptr,16));
                    qreal transverseVelocity = transverseVelocityInt16 * 100.0 * qPow(2,-15);
                    transverseVelocityStrDis = QString::number(transverseVelocity,'f',2) + "m/s";
                    //ui->lineEdit_21->setPlainText(transverseVelocityStrDis);
                    transverseVelocityStrDis_D = QString::number(transverseVelocity,'f',2);
                        //ui->textEdit_15->setTextColor(Qt::blue);

                    ui->lineEdit_21->setText(transverseVelocityStrDis);
                }

                /****************************************解析纵荡59-60字节*********************************************/
                bufferStrC1.remove(0,4);
                QString surgeStrDis;
                QString surgeStrDis_D;
                if(swayVaild == "1")
                {
                    QString surgeStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 surgeInt16 = qint16(surgeStr.toUInt(nullptr,16));
                    qreal surge = surgeInt16 * 100.0 * qPow(2,-15);
                    surgeStrDis = QString::number(surge,'f',2) + "m";
                    // ui->lineEdit_22->setPlainText(surgeStrDis);
                    surgeStrDis_D= QString::number(surge,'f',2);
                        //ui->textEdit_16->setTextColor(Qt::blue);

                    ui->lineEdit_22->setText(surgeStrDis);
                }

                /****************************************解析纵速61-62字节*********************************************/
                bufferStrC1.remove(0,4);
                QString longitudinalVelocityStrDis;
                QString longitudinalVelocityStrDis_D;
                if(swayVaild == "1")
                {
                    QString longitudinalVelocityStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                    qint16 longitudinalVelocityInt16 = qint16(longitudinalVelocityStr.toUInt(nullptr,16));
                    qreal longitudinalVelocity = longitudinalVelocityInt16 * 100.0 * qPow(2,-15);
                    longitudinalVelocityStrDis = QString::number(longitudinalVelocity,'f',2) + "m/s";
                    // ui->lineEdit_23->setPlainText(longitudinalVelocityStrDis);
                    longitudinalVelocityStrDis_D = QString::number(longitudinalVelocity,'f',2);
                        //ui->textEdit_17->setTextColor(Qt::blue);

                    ui->lineEdit_23->setText(longitudinalVelocityStrDis);
                }

                /****************************************去除导航信息有效位63字节*********************************************/
                bufferStrC1.remove(0,4);

                /****************************************解析系统状态64字节*********************************************/
                bufferStrC1.remove(0,2);
                quint8 sysState = quint8(bufferStrC1.left(2).toUInt(nullptr,16)) & 0x3F ;
                if(sysState == 0) //准备
                {
                    ui->lineEdit_3->setText("准备") ;
                }
                else if(sysState == 1) //自对准/粗阶段0x01
                {
                    ui->lineEdit_3->setText("自对准/粗阶段");
                }
                else if(sysState == 17) //自对准/精阶段0x11
                {
                    ui->lineEdit_3->setText("自对准/精阶段");
                }
                else if(sysState == 2) //传递对准/粗阶段0x02
                {
                    ui->lineEdit_3->setText("传递对准/粗阶段");
                }
                else if(sysState == 18) //传递对准/精阶段0x12
                {
                    ui->lineEdit_3->setText("传递对准/精阶段");
                }
                else if(sysState == 3) //罗经对准/粗阶段0x3
                {
                    ui->lineEdit_3->setText("传递对准/粗阶段");
                }
                else if(sysState == 19) //罗经对准/方位阶段0x13
                {
                    ui->lineEdit_3->setText("罗经对准/方位阶段");
                }
                else if(sysState == 4) //自主导航/无阻尼0x04
                {
                    ui->lineEdit_3->setText("自主导航/无阻尼");
                }
                else if(sysState == 20) //自主导航/水平阻尼0x14
                {
                    ui->lineEdit_3->setText("自主导航/水平阻尼");
                }
                else if(sysState == 36) //自主导航/全阻尼0x24
                {
                    ui->lineEdit_3->setText("自主导航/全阻尼");
                }
                else if(sysState == 5) //罗经导航0x05
                {
                    ui->lineEdit_3->setText("罗经导航");
                }
                else if(sysState == 6) //组合导航/卫导x06
                {
                    ui->lineEdit_3->setText("组合导航/卫导");
                }
                else if(sysState == 22) //组合导航/多普勒0x16
                {
                    ui->lineEdit_3->setText("组合导航/多普勒");
                }
                else if(sysState == 38) //组合导航/天文0x26
                {
                    ui->lineEdit_3->setText("组合导航/天文");
                }
                else if(sysState == 54) //组合导航/超短基线0x36
                {
                    ui->lineEdit_3->setText("组合导航/超短基线");
                }

                else if(sysState == 7) //在舰标定/粗对准0x07
                {
                    ui->lineEdit_3->setText("在舰标定/粗对准");
                }
                else if(sysState == 23) //在舰标定/位置1 0x17
                {
                    ui->lineEdit_3->setText("在舰标定/位置1");
                }
                else if(sysState == 39) //在舰标定/位置2 0x27
                {
                    ui->lineEdit_3->setText("在舰标定/位置2");
                }
                else if(sysState == 8) //零速校准0x08
                {
                    ui->lineEdit_3->setText("零速校准");
                }
                else if(sysState == 24) //点位置校准0x18
                {
                    ui->lineEdit_3->setText("点位置校准");
                }
                else if(sysState == 40) //综合校准0x28
                {
                    ui->lineEdit_3->setText("综合校准");
                }

                /****************************************解析系统状态64字节*********************************************/
                quint8 workPlace = quint8(bufferStrC1.left(2).toUInt(nullptr,16)) & 0x40;
                if(workPlace == 0)
                {
                    ui->lineEdit->setText("码头");
                }
                else
                    ui->lineEdit->setText("海上");

                quint8 toggleMode = quint8(bufferStrC1.left(2).toUInt(nullptr,16)) & 0x80;
                if(toggleMode == 0)
                {
                    ui->lineEdit_2->setText("自动");
                }
                else
                    ui->lineEdit_2->setText("手动");

                /****************************************解析时码65-68字节，时码没有放在北京时间进行显示*********************************************/
                bufferStrC1.remove(0,2);
                quint32 timeFramesInt32;
                //if(timeFramesVaild== "1")
                {
                    QString timeFramesStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                    timeFramesInt32 = quint32(timeFramesStr.toUInt(nullptr,16)); //得到距离1970-1-1号的秒数
                    QDateTime dateTime = QDateTime::fromTime_t(timeFramesInt32);            //得到UTC时间
                    //ui->lineEdit_4->setPlainText(dateTime.toString( Qt::ISODate));         //得到的UTC时间没有放到界面显示
                    //目前北京时间用的是计算机当前时间
                }

                /****************************************解析参考纬度69-72字节*********************************************/
                bufferStrC1.remove(0,8);

                QString refLatitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                qint32 refLatitudeInt32 = qint32(refLatitudeStr.toUInt(nullptr,16));

                qreal refLatitude = refLatitudeInt32 * 90.0 * qPow(2,-31);
                char NS = 'N';
                if(refLatitude > 0){
                    NS = 'N';
                }
                else{
                    NS= 'S';
                }
                QString refLatStr = QString::number(refLatitude,'f',4);
                qreal refLatitudeAbs = fabs(refLatStr.toFloat());
                double refLatitudeAbsDeg =  floor(refLatitudeAbs);
                QString refLatitudeDegStr = QString("%1").arg(refLatitudeAbsDeg);
                double refLatitudeAbsMin  =  (refLatitudeAbs - refLatitudeAbsDeg)* 60.0;
                QString refLatitudeMinStr = QString::number(refLatitudeAbsMin,'f',3);
                QString refLatitudeStrDis = NS+refLatitudeDegStr+"°"+refLatitudeMinStr+"′";
                QString refLatitudeStrDis_D = refLatStr;
                //ui->lineEdit_24->setPlainText(refLatitudeStrDis);



                    //ui->textEdit_18->setTextColor(Qt::blue);

                if(isDegree == 0)
                    ui->lineEdit_24->setText(refLatitudeStrDis);
                else
                    ui->lineEdit_24->setText(NS+refLatStr+"°");

                /****************************************解析参考经度73-76字节*********************************************/
                bufferStrC1.remove(0,8);

                QString reflongitudeStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                qint32 reflongitudeInt32 = qint32(reflongitudeStr.toUInt(nullptr,16));   //状态时间，毫秒
                //qreal a= qPow(2,-31);
                qreal reflongitude = reflongitudeInt32 * 180.0 * qPow(2,-31);
                char WE = 'E';
                if(reflongitudeInt32 > 0){
                    WE = 'E';
                }
                else{
                    WE= 'W';
                }
                QString reflongStr = QString::number(reflongitude,'f',4);
                qreal reflongitudeAbs = fabs(reflongStr.toFloat());
                double reflongitudeAbsDeg =  floor(reflongitudeAbs);
                QString reflongitudeDegStr = QString("%1").arg(reflongitudeAbsDeg);
                double reflongitudeAbsMin  =  (reflongitudeAbs - reflongitudeAbsDeg)* 60.0;
                QString reflongitudeMinStr = QString::number(reflongitudeAbsMin,'f',3);
                QString reflongitudeStrDis = WE+reflongitudeDegStr+"°"+reflongitudeMinStr+"′";
                QString reflongitudeStrDis_D = reflongStr;
                // ui->lineEdit_25->setPlainText(reflongitudeStrDis);
                if(isDegree == 0)
                    ui->lineEdit_25->setText(reflongitudeStrDis);
                else
                    ui->lineEdit_25->setText(WE+reflongStr+"°");

                /****************************************解析参考组合东速77-78字节*********************************************/
                bufferStrC1.remove(0,8);

                QString combinedEastSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 combinedEastSpeedInt16 = qint16(combinedEastSpeedStr.toUInt(nullptr,16));
                qreal combinedEastSpeed = combinedEastSpeedInt16 * 100.0 * qPow(2,-15);
                QString combinedEastSpeedStrDis = QString::number(combinedEastSpeed,'f',2)+"kn";
                QString combinedEastSpeedStrDis_D = QString::number(combinedEastSpeed,'f',2);
                //ui->lineEdit_27->setPlainText(combinedEastSpeedStrDis);

                ui->lineEdit_27->setText(combinedEastSpeedStrDis);

                /****************************************解析参考组合北速79-80字节*********************************************/
                bufferStrC1.remove(0,4);
                QString combinedNorthSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 combinedNorthSpeedInt16 = qint16(combinedNorthSpeedStr.toUInt(nullptr,16));
                qreal combinedNorthSpeed = combinedNorthSpeedInt16 * 100.0 * qPow(2,-15);
                QString combinedNorthSpeedStrDis = QString::number(combinedNorthSpeed,'f',2)+"kn";
                QString combinedNorthSpeedStrDis_D = QString::number(combinedNorthSpeed,'f',2);
                //ui->lineEdit_28->setPlainText(combinedNorthSpeedStrDis);

                ui->lineEdit_28->setText(combinedNorthSpeedStrDis);


                /****************************************解析参考阻尼东速81-82字节*********************************************/
                bufferStrC1.remove(0,4);
                QString dampedEastSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 dampedEastSpeedInt16 = qint16(dampedEastSpeedStr.toUInt(nullptr,16));
                qreal dampedEastSpeed = dampedEastSpeedInt16 * 100.0 * qPow(2,-15);
                QString dampedEastSpeedStrDis = QString::number(dampedEastSpeed,'f',2)+"kn";
                QString dampedEastSpeedStrDis_D = QString::number(dampedEastSpeed,'f',2);
                // ui->lineEdit_30->setPlainText(dampedEastSpeedStrDis);

                ui->lineEdit_29->setText(dampedEastSpeedStrDis);


                /****************************************解析参考阻尼北速83-84字节*********************************************/
                bufferStrC1.remove(0,4);
                QString dampedNorthSpeedStr = bufferStrC1.left(4).mid(2,2)+bufferStrC1.left(4).mid(0,2);
                qint16 dampedNorthSpeedInt16 = qint16(dampedNorthSpeedStr.toUInt(nullptr,16));
                qreal dampedNorthSpeed = dampedNorthSpeedInt16 * 100.0 * qPow(2,-15);
                QString dampedNorthSpeedStrDis = QString::number(dampedNorthSpeed,'f',2)+"kn";
                QString dampedNorthSpeedStrDis_D = QString::number(dampedNorthSpeed,'f',2);
                // ui->lineEdit_29->setPlainText(dampedNorthSpeedStrDis);

                ui->lineEdit_30->setText(dampedNorthSpeedStrDis);

                /****************************************解析参考航向85-88字节*********************************************/
                bufferStrC1.remove(0,4);
                QString reHeadingAngleStr = bufferStrC1.left(8).mid(6,2)+bufferStrC1.left(8).mid(4,2)+bufferStrC1.left(8).mid(2,2)+bufferStrC1.left(8).mid(0,2);
                quint32 reHeadingAngleInt32 = quint32(reHeadingAngleStr.toUInt(nullptr,16));
                qreal reHeadingAngle = reHeadingAngleInt32 * 360.0 * qPow(2,-32);
                QString reHeadingStr = QString::number(reHeadingAngle,'f',4);
                double reHeadingAngleAbsDeg =  floor(reHeadingStr.toFloat());
                QString reHeadingAngleAbsStr = QString("%1").arg(reHeadingAngleAbsDeg);
                double reHeadingAngleMin  =  (reHeadingAngle - reHeadingAngleAbsDeg)* 60.0;
                QString reHeadingAngleMinStr = QString::number(reHeadingAngleMin,'f',3);
                //QString reHeadingAngleMinStr = QString("%1").arg(reHeadingAngleMin);
                QString reHeadingAngleStrDis = reHeadingAngleAbsStr+"°"+reHeadingAngleMinStr+"′";
                QString reHeadingAngleStrDis_D = reHeadingStr;
                //ui->lineEdit_26->setPlainText(reHeadingAngleStrDis);
                if(isDegree == 0)
                    ui->lineEdit_26->setText(reHeadingAngleStrDis);
                else
                    ui->lineEdit_26->setText(reHeadingStr+"°");

                /****************************************解析参考信息有效位89-90**********************************************/
                bufferStrC1.remove(0,8);
                qint16 RefLatiLongi = qint16(bufferStrC1.left(4).toUInt(nullptr,16)) &0x0F;
                if(RefLatiLongi == 0)
                {
                    ui->lineEdit_31->setText("装订位置");
                }
                else if(RefLatiLongi == 1)
                {
                    ui->lineEdit_31->setText("GPS位置");
                }
                else if(RefLatiLongi == 2)
                {
                    ui->lineEdit_31->setText("主惯导位置");
                }
                qint16 RefComspeed = qint16(bufferStrC1.left(4).toUInt(nullptr,16)) &0xF0;
                if(RefComspeed == 0)
                {
                    ui->lineEdit_32->setText("装订速度");
                }
                else if(RefComspeed == 1)
                {
                    ui->lineEdit_32->setText("GPS速度");
                }
                else if(RefComspeed == 2)
                {
                    ui->lineEdit_32->setText("电磁速度");
                }
                else if(RefComspeed == 3)
                {
                    ui->lineEdit_32->setText("多普勒对水速度");
                }
                else if(RefComspeed == 4)
                {
                    ui->lineEdit_32->setText("多普勒对底速度");
                }
                else if(RefComspeed == 5)
                {
                    ui->lineEdit_32->setText("主惯导速度");
                }
                qint16 RefDamSpeed = qint16(bufferStrC1.left(4).toUInt(nullptr,16)) &0x0F00;
                if(RefDamSpeed == 0)
                {
                    ui->lineEdit_33->setText("装订速度");
                }
                else if(RefDamSpeed == 1)
                {
                    ui->lineEdit_33->setText("GPS速度");
                }
                else if(RefDamSpeed == 2)
                {
                    ui->lineEdit_33->setText("电磁速度");
                }
                else if(RefDamSpeed == 3)
                {
                    ui->lineEdit_33->setText("多普勒对水速度");
                }
                else if(RefDamSpeed == 4)
                {
                    ui->lineEdit_33->setText("多普勒对底速度");
                }
                else if(RefDamSpeed == 5)
                {
                    ui->lineEdit_33->setText("主惯导速度");
                }
                qint16 Referencehead = qint16(bufferStrC1.left(4).toUInt(nullptr,16)) &0xF000;
                if(Referencehead == 0)
                {
                    ui->lineEdit_34->setText("装订航向");
                }
                else if(Referencehead == 1)
                {
                    ui->lineEdit_34->setText("GPS航迹向");
                }
                else if(Referencehead == 2)
                {
                    ui->lineEdit_34->setText("主惯导航向");
                }

                /****************************************解析校验和91**********************************************/
//                bufferStrC1.remove(0,4);
//                QString ChecksumStr = bufferStrC1.left(2);
//                qint8 Checksumint8 = qint8(bufferStrC1.left(2).toUInt(nullptr,16));

                /******************************************计算误差*******************************************/
                //东速误差
                eastSpeedError = eastSpeed - combinedEastSpeed;
                //北速误差
                northSpeedError = northSpeed - combinedNorthSpeed;
                //合速度误差
                togetherSpeedError = sqrt(qPow(eastSpeedError,2) + qPow(northSpeedError,2));
                //纬度误差
                latitudeError = (latitude - refLatitude)*60.0;
                //经度误差
                longitudeError = (longitude - reflongitude) * 60.0*qCos(latitude);
                //位置误差
                positionError = sqrt(qPow(latitudeError,2) + qPow(longitudeError,2));

                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC1(&C1fileSave);

                QString dataStr1 = "\n"+ dataInvaildRecordStr + ","+"C1"+","+sysTimeStr+","+stateTimeStr+","+latitudeStrDis_D+","+longitudeStrDis_D+","+eastSpeedStrDis_D+","+northSpeedStrDis_D+","+headingAngleStrDis_D+","+rollAngleStrDis_D+","+pitchAngleStrDis_D+","+headingAngularSpeedStrDis_D+","+rollAngleSpeedStrDis_D+","+pitchAngleSpeedStrDis_D+","+heaveStrDis_D+","+verticalVelocityStrDis_D+","+swayStrDis_D+","+transverseVelocityStrDis_D+","+surgeStrDis_D+","+longitudinalVelocityStrDis_D+","+timeFramesVaild+","+longitudeLatitudeVaild+","+northeastSpeed+","+headingVaild+","+verHorShakVaild+","+angulaVelocityVaild+","+heaveVaild+","+swayVaild+","+ui->lineEdit_3->text()+","+ui->lineEdit->text()+","+ui->lineEdit_2->text()+","+timeFramesInt32+","+refLatitudeStrDis_D+","+reflongitudeStrDis_D+","+combinedEastSpeedStrDis_D+","+combinedNorthSpeedStrDis_D+","+dampedEastSpeedStrDis_D+","+dampedNorthSpeedStrDis_D+","+reHeadingAngleStrDis_D+","+ui->lineEdit_31->text()+","+ui->lineEdit_32->text()+","+ui->lineEdit_33->text()+","+ui->lineEdit_34->text();
                dataOutC1<<dataStr1.toUtf8();
            }
            else
            {
               qDebug() <<  "错误：导航信息C1报文校验和错误！" << bufferStr;
            }

        }
        else
        {
           qDebug() <<  "错误：导航信息C1报文格式错误！" << bufferStr;
        }

        /**********************************************解析工况信息C2******************************************************************/
       // if(bufferStr[4] == 'c' && bufferStr[5] == '2' && bufferStr.length()==88)
        QString bufferStrC2 = QString(bufferStr);
        bufferStrC2.remove(0,184);
        if(bufferStrC2[4] == 'c' && bufferStrC2[5] == '2')
        {
            int C2checkNumInt = 0;
            QString C2checkNumStr;
            for(int i= 4;i<86;i=i+2)
            {
                C2checkNumInt = C2checkNumInt + bufferStrC2.mid(i,2).toInt(nullptr,16);
            }
            C2checkNumStr = QString::number(C2checkNumInt,16).right(2);
            if(C2checkNumStr == bufferStrC2.mid(86,2))
            {

                bufferStrC2.remove(0,6);
                //QString SysTimeStrTemp = bufferStrC1.left(8);

                QString SysTimeStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);

                quint32 sysTimeMs = quint32(SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒

                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                //int dayInt = houInt * 24;
                int dayInt = houInt * 24;

                //long day = ms / dayInt;
                long day = 0;
                long hour = (sysTimeMs - day * dayInt) / houInt;
                long minute = (sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                //QString dayQStr  = QString::number(day,10);
                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;
                /********************************************解析信息传输标志**************************************/
                bufferStrC2.remove(0,8);
                QString informationTransStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);

                quint32 informationTransUnit32 = quint32(informationTransStr.toUInt(nullptr,16));

                QString C2bookPosetion = QString::number((informationTransUnit32) >> (1-1)&1);           //收到装订位置有效     Bit0
                QString C2GPSPosetion = QString::number((informationTransUnit32) >> (2-1)&1);    //收到GPS位置有效   Bit1
                QString C2bookSpeed = QString::number((informationTransUnit32) >> (3-1)&1);            //收到装订速度有效   Bit2
                QString C2GPSSpeed = QString::number((informationTransUnit32) >> (4-1)&1);              //收到GPS速度有效     Bit3
                QString C2ElecSpeed = QString::number((informationTransUnit32) >> (5-1)&1);           //收到电磁计程仪速度有效位   Bit4
                QString C2DopplerSpeed = QString::number((informationTransUnit32) >> (6-1)&1);       //收到多普勒计程仪速度有效   Bit5
                QString C2timeCode = QString::number((informationTransUnit32) >> (7-1)&1);                //收到时码     Bit6
                QString C2gyroScaleParameters = QString::number((informationTransUnit32) >> (8-1)&1);                 //收到陀螺标定参数    Bit7
                QString C2accoParameters = QString::number((informationTransUnit32) >> (9-1)&1);                 //收到加速度计标定参数    Bit8
                QString C2gyroTemp = QString::number((informationTransUnit32) >> (10-1)&1);                 //收到陀螺零偏温补系数    Bit9
                QString C2accoTemp = QString::number((informationTransUnit32) >> (11-1)&1);                 //收到加速度计零位温补系数    Bit10
                QString C2bookHand = QString::number((informationTransUnit32) >> (12-1)&1);                 //收到装订航向    Bit11
                QString C2equal0 = QString::number((informationTransUnit32) >> (13-1)&1);                 //收到等效零偏    Bit12
                QString C2driftCompen = QString::number((informationTransUnit32) >> (14-1)&1);                 //收到漂移补偿    Bit13
                QString C2retain = QString::number((informationTransUnit32) >> (15-1)&1);                 //保留    Bit14
                QString C2stateChange = QString::number((informationTransUnit32) >> (16-1)&1);                 //收到状态切换命令    Bit15
                QString C2sysAttitude0 = QString::number((informationTransUnit32) >> (17-1)&1);                 //收到系统姿态零位   Bit16
                QString C2inertialAttitude0 = QString::number((informationTransUnit32) >> (18-1)&1);                 //收到惯组和输出姿态零位    Bit17
                QString C2leverArm = QString::number((informationTransUnit32) >> (19-1)&1);                 //收到杆臂    Bit18
                QString C2disCtrReferInf = QString::number((informationTransUnit32) >> (20-1)&1);                 //收到显控参考信息    Bit19
                QString C2PPS = QString::number((informationTransUnit32) >> (21-1)&1);                 //收到1PPS信号    Bit20
                QString C2synSignal = QString::number((informationTransUnit32) >> (22-1)&1);                 //收到录取同步信号    Bit21
                QString C2mainInertialNav = QString::number((informationTransUnit32) >> (23-1)&1);                 //收到主惯导信息    Bit22
                QString C2sysCode = QString::number((informationTransUnit32) >> (24-1)&1);                 //收到系统编号    Bit23
                QString C2posetion = QString::number((informationTransUnit32) >> (25-1)&1);                 //收到在舰位置    Bit24
                QString C2IP = QString::number((informationTransUnit32) >> (26-1)&1);                 //收到IP地址    Bit25

                /********************************************解析信息有效标志**************************************/
                bufferStrC2.remove(0,8);
                QString informationValidStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);

                quint32 informationValidUnit32 = quint32(informationValidStr.toUInt(nullptr,16));

                QString C2bookPosetionValid = QString::number((informationValidUnit32) >> (1-1)&1);           //收到装订位置有效     Bit0
                QString C2GPSPosetionValid = QString::number((informationValidUnit32) >> (2-1)&1);    //收到GPS位置有效   Bit1
                QString C2bookSpeedValid = QString::number((informationValidUnit32) >> (3-1)&1);            //收到装订速度有效   Bit2
                QString C2GPSSpeedValid = QString::number((informationValidUnit32) >> (4-1)&1);              //收到GPS速度有效     Bit3
                QString C2ElecSpeedValid = QString::number((informationValidUnit32) >> (5-1)&1);           //收到电磁计程仪速度有效位   Bit4
                QString C2DopplerXValid = QString::number((informationValidUnit32) >> (6-1)&1);      //收到多普勒计程仪速度有效   Bit5
                QString C2DopplerYValid = QString::number((informationValidUnit32) >> (7-1)&1);      //收到多普勒计程仪速度有效   Bit5
                QString C2timeCodeValid = QString::number((informationValidUnit32) >> (8-1)&1);                //收到时码有效     Bit6
                QString C2retain8 = QString::number((informationValidUnit32) >> (9-1)&1);                //收到时码有效     Bit6

                QString C2GXDriftValid = QString::number((informationValidUnit32) >> (10-1)&1);
                QString C2GYDriftValid = QString::number((informationValidUnit32) >> (11-1)&1);
                QString C2GZDriftValid = QString::number((informationValidUnit32) >> (12-1)&1);
                QString C2AX0Valid = QString::number((informationValidUnit32) >> (13-1)&1);
                QString C2AY0Valid = QString::number((informationValidUnit32) >> (14-1)&1);
                QString C2AZ0Valid = QString::number((informationValidUnit32) >> (15-1)&1);
                QString C2HorAttErrorValid = QString::number((informationValidUnit32) >> (16-1)&1);
                QString C2HeadErrorcomValid = QString::number((informationValidUnit32) >> (17-1)&1);
                QString C2SpeedErrorcomValid = QString::number((informationValidUnit32) >> (18-1)&1);
                QString C2posetionErrorcomValid = QString::number((informationValidUnit32) >> (19-1)&1);
                QString C2DirFlightValid = QString::number((informationValidUnit32) >> (20-1)&1);
                QString C2StaticValid = QString::number((informationValidUnit32) >> (21-1)&1);
                QString C2MooringValid = QString::number((informationValidUnit32) >> (22-1)&1);
                QString C2ShockValid = QString::number((informationValidUnit32) >> (23-1)&1);
                QString C2AttackValid = QString::number((informationValidUnit32) >> (24-1)&1);
                QString C2retain24 = QString::number((informationValidUnit32) >> (25-1)&1);
                QString C2retain25 = QString::number((informationValidUnit32) >> (26-1)&1);
                QString C2retain26 = QString::number((informationValidUnit32) >> (27-1)&1);
                QString C2retain27 = QString::number((informationValidUnit32) >> (28-1)&1);
                QString C2INSpositionValid = QString::number((informationValidUnit32) >> (29-1)&1);
                QString C2INSSpeedValid = QString::number((informationValidUnit32) >> (30-1)&1);
                QString C2INSAttitudeValid = QString::number((informationValidUnit32) >> (31-1)&1);
                QString C2INSArgSpeedValid = QString::number((informationValidUnit32) >> (32-1)&1);


                /*****************************************跳转到故障码进行解析**************************************/
                //QString bufferStrC2Vaild = QString(bufferStrC2);
                bufferStrC2.remove(0,8);
                QString C2errorCodeStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                quint32 errorCode = quint32(C2errorCodeStr.toUInt(nullptr,16));
                //quint8 errorCode = 0xFF;
                QString groyErrorCode = QString::number((errorCode) >> (1-1)&1);              //陀螺     Bit0
                QString accErrorCode = QString::number((errorCode) >> (2-1)&1);               //加速度计   Bit1
                QString IFErrorCode = QString::number((errorCode) >> (3-1)&1);                //IF板   Bit2
                QString AcqBoardErrorCode = QString::number((errorCode) >> (4-1)&1);          //采集板     Bit3
                QString retain1ErrorCode = QString::number((errorCode) >> (5-1)&1);           //保留   Bit4
                QString commuErrorCode= QString::number((errorCode) >> (6-1)&1);              //通信板   Bit5
                QString retain2ErrorCode = QString::number((errorCode) >> (7-1)&1);           //保留     Bit6
                QString interfaceErrorCode = QString::number((errorCode) >> (8-1)&1);         //接口板故障码    Bit7
                QString solAbnormalErrorCode = QString::number((errorCode) >> (9-1)&1);       //解算异常故障码    Bit8
                QString backPowerErrorCode = QString::number((errorCode) >> (10-1)&1);         //备用电源故障码    Bit9
                if(groyErrorCode == "1")
                {

                    ui->label_13->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_13->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(accErrorCode == "1")
                {

                    ui->label_20->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_20->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(IFErrorCode == "1")
                {

                    ui->label_14->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_14->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(AcqBoardErrorCode == "1")
                {

                    ui->label_19->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_19->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                if(solAbnormalErrorCode == "1")
                {

                    ui->label_21->setStyleSheet("font:bold;color:Red");
                }
                else
                {
                     ui->label_21->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }

                /****************************************解析GX陀螺常值漂移19-22字节*********************************************/
                bufferStrC2.remove(0,8);
                QString GXGyroConstantDriftStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 GXGyroConstantDriftInt32 = qint32(GXGyroConstantDriftStr.toUInt(nullptr,16));
                qreal GXGyroConstantDrift = GXGyroConstantDriftInt32 * qPow(10,-6);
                QString GXGyroConstantDriftStrDis = QString::number(GXGyroConstantDrift,'f',4);

                /****************************************解析GY陀螺常值漂移23-26字节*********************************************/
                bufferStrC2.remove(0,8);
                QString GYGyroConstantDriftStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 GYGyroConstantDriftInt32 = qint32(GYGyroConstantDriftStr.toUInt(nullptr,16));
                qreal GYGyroConstantDrift = GYGyroConstantDriftInt32 * qPow(10,-6);
                QString GYGyroConstantDriftStrDis = QString::number(GYGyroConstantDrift,'f',4);

                /****************************************解析GZ陀螺常值漂移27-30字节*********************************************/
                bufferStrC2.remove(0,8);
                QString GZGyroConstantDriftStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 GZGyroConstantDriftInt32 = qint32(GZGyroConstantDriftStr.toUInt(nullptr,16));
                qreal GZGyroConstantDrift = GZGyroConstantDriftInt32 * qPow(10,-6);
                QString GZGyroConstantDriftStrDis = QString::number(GZGyroConstantDrift,'f',4);

                /****************************************解析AX加速度计零偏31-34字节*********************************************/
                bufferStrC2.remove(0,8);
                QString AXAccelerometerBiasStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 AXAccelerometerBiasInt32 = qint32(AXAccelerometerBiasStr.toUInt(nullptr,16));
                qreal AXAccelerometerBias = AXAccelerometerBiasInt32 * qPow(10,-6);
                QString AXAccelerometerBiasStrDis = QString::number(AXAccelerometerBias,'f',4);

                /****************************************解析AY加速度计零偏35-38字节*********************************************/
                bufferStrC2.remove(0,8);
                QString  AYAccelerometerBiasStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32  AYAccelerometerBiasInt32 = qint32(AYAccelerometerBiasStr.toUInt(nullptr,16));
                qreal  AYAccelerometerBias =  AYAccelerometerBiasInt32 * qPow(10,-6);
                QString  AYAccelerometerBiasStrDis = QString::number(AYAccelerometerBias,'f',4);

                /****************************************解析AZ加速度计零偏39-42字节*********************************************/
                bufferStrC2.remove(0,8);
                QString AZAccelerometerBiasStr = bufferStrC2.left(8).mid(6,2)+bufferStrC2.left(8).mid(4,2)+bufferStrC2.left(8).mid(2,2)+bufferStrC2.left(8).mid(0,2);
                qint32 AZAccelerometerBiasInt32 = qint32(AZAccelerometerBiasStr.toUInt(nullptr,16));
                qreal AZAccelerometerBias = AZAccelerometerBiasInt32 * qPow(10,-6);
                QString AZAccelerometerBiasStrDis = QString::number(AZAccelerometerBias,'f',4);


                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC2(&C2fileSave);

                QString dataStr2 = "\n" + dataInvaildRecordStr +","+"C2"+","+sysTimeStr+","+C2bookPosetion+","+C2GPSPosetion+","+C2bookSpeed+","+C2GPSSpeed+","
                                        +C2ElecSpeed+","+C2DopplerSpeed+","+C2timeCode+","+C2gyroScaleParameters+","+C2accoParameters+","+C2gyroTemp+","+C2accoTemp+","
                                        +C2bookHand+","+C2equal0+","+C2driftCompen+","+C2stateChange+","+C2sysAttitude0+","+C2inertialAttitude0+","+C2leverArm+","+C2disCtrReferInf+","
                                        +C2PPS+","+C2synSignal+","+C2mainInertialNav+","+C2sysCode+","+C2posetion+","+C2IP+","+C2bookPosetionValid+","+C2GPSPosetionValid+","+C2bookSpeedValid+","
                                        +C2GPSSpeedValid+","+C2ElecSpeedValid+","+C2DopplerXValid+","+C2DopplerYValid+","+C2timeCodeValid+","+C2GXDriftValid+","+C2GYDriftValid+","+C2GZDriftValid+","
                                        +C2AX0Valid+","+C2AY0Valid+","+C2AZ0Valid+","+C2HorAttErrorValid+","+C2HeadErrorcomValid+","+C2SpeedErrorcomValid+","+C2posetionErrorcomValid+","+C2DirFlightValid+","
                                        +C2StaticValid+","+C2MooringValid+","+C2ShockValid+","+C2AttackValid+","+C2INSpositionValid+","+C2INSSpeedValid+","+C2INSAttitudeValid+","+C2INSArgSpeedValid+","
                                        +groyErrorCode+","+accErrorCode+","+IFErrorCode+","+AcqBoardErrorCode+","+commuErrorCode+","+interfaceErrorCode+","+solAbnormalErrorCode+","+backPowerErrorCode+","
                                        +GXGyroConstantDriftStrDis+","+GYGyroConstantDriftStrDis+","+GZGyroConstantDriftStrDis+","+AXAccelerometerBiasStrDis+","+AYAccelerometerBiasStrDis+","+AZAccelerometerBiasStrDis;
                dataOutC2<<dataStr2.toUtf8();
            }
        }
        else
        {
            //qDebug() <<  "错误：工况信息C2报文错误，无法解析！";
        }


       /**********************************************解析参考信息C3******************************************************************/
        //if(bufferStr[4] == 'c' && bufferStr[5] == '3' && bufferStr.length()==116)
        QString bufferStrC3 = QString(bufferStr);
        bufferStrC3.remove(0,272);

        if(bufferStrC3[0] == 'e' && bufferStrC3[1] == 'b'&&bufferStrC3[4] == 'c' && bufferStrC3[5] == '3')
        {
            int C3checkNumInt = 0;
            QString C3checkNumStr;
            for(int i= 4;i<114;i=i+2)
            {
                C3checkNumInt = C3checkNumInt + bufferStrC3.mid(i,2).toInt(nullptr,16);
            }
            C3checkNumStr = QString::number(C3checkNumInt,16).right(2);
            if(C3checkNumStr == bufferStrC3.mid(114,2))
            {
                /**************************************解析系统时间***************************************************/
                bufferStrC3.remove(0,6);

                QString C3SysTimeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);

                quint32 C3sysTimeMs = quint32(C3SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒
                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                //int dayInt = houInt * 24;
                int dayInt = houInt * 24;

                //long day = ms / dayInt;
                long day = 0;
                long hour = (C3sysTimeMs - day * dayInt) / houInt;
                long minute = (C3sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (C3sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = C3sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                //QString dayQStr  = QString::number(day,10);
                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;

                /**************************************解析信息收到标识***************************************************/
                bufferStrC3.remove(0,8);

                QString C3informationTransStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);

                quint32 C3informationTransUnit32 = quint32(C3informationTransStr.toUInt(nullptr,16));

                QString C3bookPosetion = QString::number((C3informationTransUnit32) >> (1-1)&1);           //收到装订位置有效     Bit0
                QString C3GPSPosetion = QString::number((C3informationTransUnit32) >> (2-1)&1);    //收到GPS位置有效   Bit1
                QString C3bookSpeed = QString::number((C3informationTransUnit32) >> (3-1)&1);            //收到装订速度有效   Bit2
                QString C3GPSSpeed = QString::number((C3informationTransUnit32) >> (4-1)&1);              //收到GPS速度有效     Bit3
                QString C3ElecSpeed = QString::number((C3informationTransUnit32) >> (5-1)&1);           //收到电磁计程仪速度有效位   Bit4
                QString C3DopplerSpeed = QString::number((C3informationTransUnit32) >> (6-1)&1);       //收到多普勒计程仪速度有效   Bit5
                QString C3timeCode = QString::number((C3informationTransUnit32) >> (7-1)&1);                //收到时码     Bit6
                QString C3PPS = QString::number((C3informationTransUnit32) >> (8-1)&1);                 //收到PPS信号    Bit7

                /**************************************解析信息有效标识***************************************************/
                bufferStrC3.remove(0,8);

                QString bufferStrC3Vaild = QString(bufferStrC3);
                QString C3VaildCodeStr = bufferStrC3Vaild.left(8).mid(6,2)+bufferStrC3Vaild.left(8).mid(4,2)+bufferStrC3Vaild.left(8).mid(2,2)+bufferStrC3Vaild.left(8).mid(0,2);
                quint32 VaildCode = quint32(C3VaildCodeStr.toUInt(nullptr,16));
                QString bookPositionCode = QString::number((VaildCode) >> (1-1)&1);              //装订位置有效    Bit0
                QString GPSPositionCode = QString::number((VaildCode) >> (2-1)&1);               //GPS位置有效   Bit1
                QString bookSpeedCode = QString::number((VaildCode) >> (3-1)&1);                //装订速度有效   Bit2
                QString GPSSpeedCode = QString::number((VaildCode) >> (4-1)&1);          //GPS速度有效     Bit3
                QString electrSpeedCode = QString::number((VaildCode) >> (5-1)&1);           //电磁速度有效   Bit4
                QString waterCode= QString::number((VaildCode) >> (6-1)&1);              //多普勒对水有效   Bit5
                QString bottonCode = QString::number((VaildCode) >> (7-1)&1);           //多普勒对底有效     Bit6
                QString timeCode = QString::number((VaildCode) >> (8-1)&1);         //时码有效    Bit7
                QString PPSCode = QString::number((VaildCode) >> (9-1)&1);       //PPS有效    Bit8
                QString MainINSCode = QString::number((VaildCode) >> (10-1)&1);         //主惯导有效   Bit9
                if(GPSPositionCode == "1" || GPSSpeedCode == '1')
                {

                    ui->label_17->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_17->setStyleSheet("font:bold;color:Red");
                }

                if(waterCode == "1" || bottonCode == '1')
                {

                    ui->label_27->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_27->setStyleSheet("font:bold;color:Red");
                }

                if(PPSCode == "1")
                {

                    ui->label_16->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_16->setStyleSheet("font:bold;color:Red");
                }
                if(electrSpeedCode == "1")
                {

                    ui->label_25->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_25->setStyleSheet("font:bold;color:Red");
                }
                if(MainINSCode == "1")
                {

                    ui->label_28->setStyleSheet("font:bold;color:rgb(0,200,50)");
                }
                else
                {
                     ui->label_28->setStyleSheet("font:bold;color:Red");
                }
                /**************************************解析GPS纬度***************************************************/
                bufferStrC3.remove(0,8);
                QString C3GPSlatitudeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);

                qint32 C3GPSlatitudeInt32 = qint32(C3GPSlatitudeStr.toUInt(nullptr,16));

                C3GPSlatitude = C3GPSlatitudeInt32 * 90.0 * qPow(2,-31);
                char NS = 'N';
                if(C3GPSlatitude >= 0){
                    NS = 'N';
                }
                else{
                    NS= 'S';
                }
                QString C3GPSlattStr = QString::number(C3GPSlatitude,'f',4);
                qreal C3GPSlatitudeAbs = fabs(C3GPSlattStr.toFloat());
                double C3GPSlatitudeAbsDeg =  floor(C3GPSlatitudeAbs);
                QString C3GPSlatitudeDegStr= QString("%1").arg(C3GPSlatitudeAbsDeg);
                QString C3GPSlatitudeMinStr;
                double C3GPSlatitudeAbsMin  =  (C3GPSlatitudeAbs - C3GPSlatitudeAbsDeg)* 60.0;

                if(C3GPSlatitudeAbsMin == 0)
                    C3GPSlatitudeMinStr = QString("0%1.000").arg(C3GPSlatitudeAbsMin);
                else
                    C3GPSlatitudeMinStr = QString("%1").arg(C3GPSlatitudeAbsMin);

                //QString C3GPSlatitudeMinStr = QString("%1").arg(C3GPSlatitudeAbsMin);
                QString C3GPSlatitudeStrDis = NS+C3GPSlatitudeDegStr+"°"+C3GPSlatitudeMinStr+"′";
                QString C3GPSlatitudeStrDis_D = C3GPSlattStr;

                if(isDegree == 0)
                    ui->lineEdit_35->setText(C3GPSlatitudeStrDis);
                else
                    ui->lineEdit_35->setText(NS+C3GPSlattStr+"°");
                /**************************************解析GPS经度19-22***************************************************/
                bufferStrC3.remove(0,8);

                QString C3longitudeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                qint32 C3longitudeInt32 = qint32(C3longitudeStr.toUInt(nullptr,16));
                C3longitude = C3longitudeInt32 * 180.0 * qPow(2,-31);
                char WE = 'E';
                if(C3longitudeInt32 >= 0){
                    WE = 'E';
                }
                else{
                    WE= 'W';
                }
                QString C3longStr = QString::number(C3longitude,'f',4);
                qreal C3longitudeAbs = fabs(C3longStr.toFloat());
                double C3longitudeAbsDeg =  floor(C3longitudeAbs);
                QString C3longitudeDegStr = QString("%1").arg(C3longitudeAbsDeg);
                double C3longitudeAbsMin  =  (C3longitudeAbs - C3longitudeAbsDeg)* 60.0;
                QString C3longitudeMinStr;
                if(C3longitudeAbsMin == 0)
                {
                    C3longitudeMinStr = QString("0%1.000").arg(C3longitudeAbsMin);
                }
                else
                    C3longitudeMinStr = QString::number(C3longitudeAbsMin,'f',3);
                //C3longitudeMinStr = QString("%1").arg(C3longitudeAbsMin);
                QString C3longitudeStrDis = WE+C3longitudeDegStr+"°"+C3longitudeMinStr+"′";
                QString C3longitudeStrDis_D = C3longStr;

                if(isDegree == 0)
                    ui->lineEdit_36->setText(C3longitudeStrDis);
                else
                    ui->lineEdit_36->setText(WE+C3longStr+"°");

                /****************************************解析GPS合速23-24字节*********************************************/
                bufferStrC3.remove(0,8);

                QString C3togetherSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                quint16 C3togetherSpeedInt16 = quint16(C3togetherSpeedStr.toUInt(nullptr,16));
                C3togetherSpeed = C3togetherSpeedInt16 * 100.0 * qPow(2,-16);

                QString C3togetherSpeedStrtemp = QString::number(C3togetherSpeed,'f',2);
                QString C3togetherSpeedStrDis = C3togetherSpeedStrtemp+"kn";
                // ui->lineEdit_9->setPlainText(C3togetherSpeedStrDis);


                ui->lineEdit_38->setText(C3togetherSpeedStrDis);

                /****************************************解析航向25-28字节*********************************************/
                bufferStrC3.remove(0,4);

                QString C3headingAngleStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint32 C3headingAngleInt32 = quint32(C3headingAngleStr.toUInt(nullptr,16));
                C3headingAngle = C3headingAngleInt32 * 360.0 * qPow(2,-32);
                QString C3headingStr = QString::number(C3headingAngle,'f',4);
                double C3headingAngleAbsDeg =  floor(C3headingStr.toFloat());
                QString C3headingAngleAbsStr = QString("%1").arg(C3headingAngleAbsDeg);
                double C3headingAngleMin  =  (C3headingAngle - C3headingAngleAbsDeg)* 60.0;
                QString C3headingAngleMinStr = QString::number(C3headingAngleMin,'f',3);
                //QString C3headingAngleMinStr = QString("%1").arg(C3headingAngleMin);
                QString C3headingAngleStrDis = C3headingAngleAbsStr+"°"+C3headingAngleMinStr+"′";
                QString C3headingAngleStrDis_D = C3headingStr;
                // ui->lineEdit_9->setPlainText(C3headingAngleStrDis);

                if(isDegree ==0)
                 ui->lineEdit_37->setText(C3headingAngleStrDis);
                else
                      ui->lineEdit_37->setText(C3headingStr+"°");


                /****************************************解析C3GPS东速29-30字节*********************************************/
                bufferStrC3.remove(0,8);

                QString C3combinedEastSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3combinedEastSpeedInt16 = qint16(C3combinedEastSpeedStr.toUInt(nullptr,16));
                C3combinedEastSpeed = C3combinedEastSpeedInt16 * 100.0 * qPow(2,-15);
                QString C3combinedEastSpeedStrDis = QString::number(C3combinedEastSpeed,'f',2)+"kn";
                QString C3combinedEastSpeedStrDis_D = QString::number(C3combinedEastSpeed,'f',2);
//                if(QString::compare(ui->textEdit_34->toPlainText(),C3combinedEastSpeedStrDis))
//                {
//                    ui->textEdit_34->setTextColor(Qt::blue);
//                }
//                else
//                {
//                    ui->textEdit_34->setTextColor(Qt::black);
//                }
                ui->lineEdit_40->setText(C3combinedEastSpeedStrDis);

                /****************************************解析参考组合北速79-80字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3combinedNorthSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3combinedNorthSpeedInt16 = qint16(C3combinedNorthSpeedStr.toUInt(nullptr,16));
                C3combinedNorthSpeed = C3combinedNorthSpeedInt16 * 100.0 * qPow(2,-15);
                QString C3combinedNorthSpeedStrDis = QString::number(C3combinedNorthSpeed,'f',2)+"kn";
                QString C3combinedNorthSpeedStrDis_D = QString::number(C3combinedNorthSpeed,'f',2);
                //ui->lineEdit_28->setPlainText(C3combinedNorthSpeedStrDis);
//                if(QString::compare(ui->textEdit_33->toPlainText(),C3combinedNorthSpeedStrDis))
//                {
//                    ui->textEdit_33->setTextColor(Qt::blue);
//                }
//                else
//                {
//                    ui->textEdit_33->setTextColor(Qt::black);
//                }
                ui->lineEdit_39->setText(C3combinedNorthSpeedStrDis);

                /****************************************解析C3电磁速度33-34字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3electromagnetismSpeedStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3electromagnetismSpeedInt16 = qint16(C3electromagnetismSpeedStr.toUInt(nullptr,16));
                C3electromagnetismSpeed = C3electromagnetismSpeedInt16 * 100.0 * qPow(2,-15);
                QString C3electromagnetismSpeedStrDis = QString::number(C3electromagnetismSpeed,'f',2)+"kn";
                QString C3electromagnetismSpeedStrDis_D = QString::number(C3electromagnetismSpeed,'f',2);
//                if(QString::compare(ui->textEdit_39->toPlainText(),C3electromagnetismSpeedStrDis))
//                {
//                    ui->textEdit_39->setTextColor(Qt::blue);
//                }
//                else
//                {
//                    ui->textEdit_39->setTextColor(Qt::black);
//                }
                ui->lineEdit_49->setText(C3electromagnetismSpeedStrDis);

                /****************************************解析C3多普勒对水横向速度35-36字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3waterXStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3waterXInt16 = qint16(C3waterXStr.toUInt(nullptr,16));
                C3waterX = C3waterXInt16 * 100.0 * qPow(2,-15);
                QString C3waterXStrDis = QString::number(C3waterX,'f',2)+"kn";
                QString C3waterXStrDis_D = QString::number(C3waterX,'f',2);
//                if(QString::compare(ui->textEdit_35->toPlainText(),C3waterXStrDis))
//                {
//                    ui->textEdit_35->setTextColor(Qt::blue);
//                }
//                else
//                {
//                    ui->textEdit_35->setTextColor(Qt::black);
//                }
                ui->lineEdit_41->setText(C3waterXStrDis);

                /****************************************解析C3多普勒对水纵向速度37-38字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3waterYStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3waterYInt16 = qint16(C3waterYStr.toUInt(nullptr,16));
                C3waterY = C3waterYInt16 * 100.0 * qPow(2,-15);
                QString C3waterYStrDis = QString::number(C3waterY,'f',2)+"kn";
                QString C3waterYStrDis_D = QString::number(C3waterY,'f',2);
//                if(QString::compare(ui->textEdit_36->toPlainText(),C3waterYStrDis))
//                {
//                    ui->textEdit_36->setTextColor(Qt::blue);
//                }
//                else
//                {
//                    ui->textEdit_36->setTextColor(Qt::black);
//                }
                ui->lineEdit_42->setText(C3waterYStrDis);

                /****************************************解析C3多普勒对底横向速度39-40字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3bottomXStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3bottomXInt16 = qint16(C3bottomXStr.toUInt(nullptr,16));
                C3bottomX = C3bottomXInt16 * 100.0 * qPow(2,-15);
                QString C3bottomXStrDis = QString::number(C3bottomX,'f',2)+"kn";
                QString C3bottomXStrDis_D = QString::number(C3bottomX,'f',2);
//                if(QString::compare(ui->textEdit_37->toPlainText(),C3bottomXStrDis))
//                {
//                    ui->textEdit_37->setTextColor(Qt::blue);
//                }
//                else
//                {
//                    ui->textEdit_37->setTextColor(Qt::black);
//                }
                ui->lineEdit_43->setText(C3bottomXStrDis);

                /****************************************解析C3多普勒对底纵向速度41-42字节*********************************************/
                bufferStrC3.remove(0,4);
                QString C3bottomYStr = bufferStrC3.left(4).mid(2,2)+bufferStrC3.left(4).mid(0,2);
                qint16 C3bottomYInt16 = qint16(C3bottomYStr.toUInt(nullptr,16));
                C3bottomY = C3bottomYInt16 * 100.0 * qPow(2,-15);
                QString C3bottomYStrDis = QString::number(C3bottomY,'f',2)+"kn";
                QString C3bottomYStrDis_D = QString::number(C3bottomY,'f',2);
//                if(QString::compare(ui->textEdit_38->toPlainText(),C3bottomYStrDis))
//                {
//                    ui->textEdit_38->setTextColor(Qt::blue);
//                }
//                else
//                {
//                    ui->textEdit_38->setTextColor(Qt::black);
//                }
                ui->lineEdit_44->setText(C3bottomYStrDis);

                /****************************************解析时码43-46字节*********************************************/
                bufferStrC3.remove(0,4);
                QString timeCodeStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint32 C3TimeCodeDay = quint32(timeCodeStr.toUInt(nullptr,16)) & 0x000000FF; //得到距离1970-1-1号的秒数
                quint32 C3TimeCodeMonth = quint32(timeCodeStr.toUInt(nullptr,16)) & 0x0000FF00; //得到距离1970-1-1号的秒数
                quint32 C3TimeCodeYear = quint32(timeCodeStr.toUInt(nullptr,16)) & 0xFFFF0000; //得到距离1970-1-1号的秒数
                QString C3timeCodeStr = QString::number(C3TimeCodeYear,10) + QString::number(C3TimeCodeMonth,10)+QString::number(C3TimeCodeDay,10);

                /****************************************解析时码:天秒47-50字节*********************************************/
                bufferStrC3.remove(0,8);
                QString timeCodeDaySecStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint32 timeCodeDaySecUnit32 = quint32(timeCodeDaySecStr.toUInt(nullptr,16));
                QString timeCodeDaySecDisStr = QString::number(timeCodeDaySecUnit32,10);

                /****************************************解析插值时间51-52字节*********************************************/
                bufferStrC3.remove(0,8);
                QString insertValueStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint16 insertValueUnit32 = quint16(insertValueStr.toUInt(nullptr,16));
                QString insertValueDisStr = QString::number(insertValueUnit32,10);

                /****************************************解析GPS卫星数53-54字节*********************************************/
                bufferStrC3.remove(0,4);
                QString GPSNumStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint16 GPSNumUnit32 = quint16(GPSNumStr.toUInt(nullptr,16));
                QString GPSNumDisStr = QString::number(GPSNumUnit32,10);


                /****************************************解析GPS水平精度因子字节*********************************************/
                bufferStrC3.remove(0,4);
                QString HDOPStr = bufferStrC3.left(8).mid(6,2)+bufferStrC3.left(8).mid(4,2)+bufferStrC3.left(8).mid(2,2)+bufferStrC3.left(8).mid(0,2);
                quint16 HDOPUnit32 = quint16(HDOPStr.toUInt(nullptr,16));
                QString HDOPDisStr = QString::number(HDOPUnit32,10);


                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC3(&C3fileSave);

                QString dataStr3 = "\n"+ dataInvaildRecordStr+","+"C3"+","+sysTimeStr+","+C3bookPosetion+","+C3GPSPosetion+","+C3bookSpeed+","+C3GPSSpeed+","+C3ElecSpeed+","+C3DopplerSpeed+","+C3timeCode+","+C3PPS+","+bookPositionCode+","+GPSPositionCode+","+bookSpeedCode+","+GPSSpeedCode+","+electrSpeedCode+","+waterCode+","+bottonCode+","+timeCode+","+C3GPSlatitudeStrDis_D+","+C3longitudeStrDis_D+","+C3togetherSpeedStrtemp+","+C3headingAngleStrDis_D+","+C3combinedEastSpeedStrDis_D+","+C3combinedNorthSpeedStrDis_D+","+C3electromagnetismSpeedStrDis_D+","+C3waterXStrDis_D+","+C3waterYStrDis_D+","+C3bottomXStrDis_D+","+C3bottomYStrDis_D+","+C3timeCodeStr+","+timeCodeDaySecDisStr+","+insertValueDisStr+","+GPSNumDisStr+","+HDOPDisStr;
                        dataOutC3<<dataStr3.toUtf8();

            }
            else
            {
                qDebug() <<  "错误：参考信息C3校验和错误！";
            }
        }
        else
        {
            qDebug() <<  "错误：参考信息C3报文错误，无法解析！";
        }

        /**********************************************解析惯性信息C5******************************************************************/
        //if(bufferStr[4] == 'c' && bufferStr[5] == '5' && bufferStr.length()==284)
        QString bufferStrC5 = QString(bufferStr);
        bufferStrC5.remove(0,388);
        if(bufferStrC5[0] == 'e' && bufferStrC5[1] == 'b'&&bufferStrC5[4] == 'c' && bufferStrC5[5] == '5')
        {

            int C5checkNumInt = 0;
            QString C5checkNumStr;
            for(int i= 4;i<282;i=i+2)
            {
                C5checkNumInt = C5checkNumInt + bufferStrC5.mid(i,2).toInt(nullptr,16);
            }
            C5checkNumStr = QString::number(C5checkNumInt,16).right(2);
            if(C5checkNumStr == bufferStrC5.mid(282,2))
            {
                /**************************************C5解析系统时间3-6***************************************************/

                bufferStrC5.remove(0,6);

                QString C5SysTimeStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);

                quint32 C5sysTimeMs = quint32(C5SysTimeStr.toUInt(nullptr,16));   //系统时间，毫秒

                int secInt = 1000;
                int minInt = secInt * 60;
                int houInt = minInt * 60;
                //int dayInt = houInt * 24;
                int dayInt = houInt * 24;

                //long day = ms / dayInt;
                long day = 0;
                long hour = (C5sysTimeMs - day * dayInt) / houInt;
                long minute = (C5sysTimeMs - day * dayInt- hour * houInt) / minInt ;
                long second = (C5sysTimeMs - day * dayInt- hour * houInt - minute * minInt ) / secInt;
                long milliSecond = C5sysTimeMs - day * dayInt - hour * houInt - minute * minInt - second * secInt;

                //QString dayQStr  = QString::number(day,10);
                QString houQStr  = QString::number(hour,10);
                QString minQStr  = QString::number(minute,10);
                QString secQStr  = QString::number(second,10);
                QString msecQStr = QString::number(milliSecond,10);
                QString sysTimeStr = houQStr+":"+minQStr+":"+secQStr+":"+msecQStr;

                ui->tableWidget->clearContents();
                /**************************************C5解析X陀螺1s角增量7-10字节***************************************************/
                bufferStrC5.remove(0,8);


                QString C5XGyroAngleIncreasetr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5XGyroAngleIncreaseInt32 = qint32(C5XGyroAngleIncreasetr.toUInt(nullptr,16));
//                C5XGyroAngleIncreaseFloat = *(float*)&C5XGyroAngleIncreaseInt32;

                C5ValueUnion.qint32Value = qint32(C5XGyroAngleIncreasetr.toUInt(nullptr,16));
                C5XGyroAngleIncreaseFloat = C5ValueUnion.floatValue;

                QString C5XGyroAngleIncreasetrDis = QString::number(C5XGyroAngleIncreaseFloat,'f',4);

                ui->tableWidget->setItem(0,0,new QTableWidgetItem(C5XGyroAngleIncreasetrDis));
                ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺1s角增量11-14字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YGyroAngleIncreaseStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5YGyroAngleIncreaseInt32 = qint32(C5YGyroAngleIncreaseStr.toUInt(nullptr,16));
//                C5YGyroAngleIncreaseFloat = *(float*)&C5YGyroAngleIncreaseInt32;

                C5ValueUnion.qint32Value = qint32(C5YGyroAngleIncreaseStr.toUInt(nullptr,16));
                C5YGyroAngleIncreaseFloat = C5ValueUnion.floatValue;

                QString C5YGyroAngleIncreasetrDis = QString::number(C5YGyroAngleIncreaseFloat,'f',4);

                ui->tableWidget->setItem(1,0,new QTableWidgetItem(C5YGyroAngleIncreasetrDis));
                ui->tableWidget->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析z陀螺1s角增量15-18字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZGyroAngleIncreaseStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5ZGyroAngleIncreaseInt32 = qint32(C5ZGyroAngleIncreaseStr.toUInt(nullptr,16));
//                C5ZGyroAngleIncreaseFloat = *(float*)&C5ZGyroAngleIncreaseInt32;

                C5ValueUnion.qint32Value = qint32(C5ZGyroAngleIncreaseStr.toUInt(nullptr,16));
                C5ZGyroAngleIncreaseFloat = C5ValueUnion.floatValue;

                QString C5ZGyroAngleIncreasetrDis = QString::number(C5ZGyroAngleIncreaseFloat,'f',4);

                ui->tableWidget->setItem(2,0,new QTableWidgetItem(C5ZGyroAngleIncreasetrDis));
                ui->tableWidget->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X加速度计1s速度增量19-22字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XAccelerometerSpeedIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                //qint32 C5XAccelerometerSpeedIncrementInt32 = qint32(C5XAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
                //C5XAccelerometerSpeedIncrementFloat = *(float*)&C5XAccelerometerSpeedIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5XAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
                C5XAccelerometerSpeedIncrementFloat = C5ValueUnion.floatValue;

                QString C5XAccelerometerSpeedIncrementtrDis = QString::number(C5XAccelerometerSpeedIncrementFloat,'f',4);

                ui->tableWidget->setItem(3,0,new QTableWidgetItem(C5XAccelerometerSpeedIncrementtrDis));
                ui->tableWidget->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析y加速度计1s速度增量23-26字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YAccelerometerSpeedIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5YAccelerometerSpeedIncrementInt32 = qint32(C5YAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
//                C5YAccelerometerSpeedIncrementFloat = *(float*)&C5YAccelerometerSpeedIncrementInt32;


                C5ValueUnion.qint32Value = qint32(C5YAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
                C5YAccelerometerSpeedIncrementFloat = C5ValueUnion.floatValue;

                QString C5YAccelerometerSpeedIncrementtrDis = QString::number(C5YAccelerometerSpeedIncrementFloat,'f',4);

                ui->tableWidget->setItem(4,0,new QTableWidgetItem(C5YAccelerometerSpeedIncrementtrDis));
                ui->tableWidget->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计1s速度增量27-30字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZAccelerometerSpeedIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5ZAccelerometerSpeedIncrementInt32 = qint32(C5ZAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
//                C5ZAccelerometerSpeedIncrementFloat = *(float*)&C5ZAccelerometerSpeedIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5ZAccelerometerSpeedIncrementStr.toUInt(nullptr,16));
                C5ZAccelerometerSpeedIncrementFloat = C5ValueUnion.floatValue;

                QString C5ZAccelerometerSpeedIncrementtrDis = QString::number(C5ZAccelerometerSpeedIncrementFloat,'f',4);

                ui->tableWidget->setItem(5,0,new QTableWidgetItem(C5ZAccelerometerSpeedIncrementtrDis));
                ui->tableWidget->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析x陀螺1s补偿后角增量31-34字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroCompensatedAngleIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5XgyroCompensatedAngleIncrementInt32 = qint32(C5XgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
//                C5XgyroCompensatedAngleIncrementFloat = *(float*)&C5XgyroCompensatedAngleIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5XgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
                C5XgyroCompensatedAngleIncrementFloat = C5ValueUnion.floatValue;

                QString C5XgyroCompensatedAngleIncrementtrDis = QString::number(C5XgyroCompensatedAngleIncrementFloat,'f',4);

                ui->tableWidget->setItem(0,1,new QTableWidgetItem(C5XgyroCompensatedAngleIncrementtrDis));
                ui->tableWidget->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺1s补偿后角增量35-38字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroCompensatedAngleIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5YgyroCompensatedAngleIncrementInt32 = qint32(C5YgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
//                C5YgyroCompensatedAngleIncrementFloat = *(float*)&C5YgyroCompensatedAngleIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5YgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
                C5YgyroCompensatedAngleIncrementFloat = C5ValueUnion.floatValue;

                QString C5YgyroCompensatedAngleIncrementtrDis = QString::number(C5YgyroCompensatedAngleIncrementFloat,'f',4);

                ui->tableWidget->setItem(1,1,new QTableWidgetItem(C5YgyroCompensatedAngleIncrementtrDis));
                ui->tableWidget->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析z陀螺1s补偿后角增量39-42字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroCompensatedAngleIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5ZgyroCompensatedAngleIncrementInt32 = qint32(C5ZgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
//                C5ZgyroCompensatedAngleIncrementFloat = *(float*)&C5ZgyroCompensatedAngleIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5ZgyroCompensatedAngleIncrementStr.toUInt(nullptr,16));
                C5ZgyroCompensatedAngleIncrementFloat = C5ValueUnion.floatValue;

                QString C5ZgyroCompensatedAngleIncrementtrDis = QString::number(C5ZgyroCompensatedAngleIncrementFloat,'f',4);

                ui->tableWidget->setItem(2,1,new QTableWidgetItem(C5ZgyroCompensatedAngleIncrementtrDis));
                ui->tableWidget->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析x加速度计1s补偿后速度增量43-46字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XAccVelocityIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5XAccVelocityIncrementInt32 = qint32(C5XAccVelocityIncrementStr.toUInt(nullptr,16));
//                C5XAccVelocityIncrementFloat = *(float*)&C5XAccVelocityIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5XAccVelocityIncrementStr.toUInt(nullptr,16));
                C5XAccVelocityIncrementFloat = C5ValueUnion.floatValue;

                QString C5XAccVelocityIncrementtrDis = QString::number(C5XAccVelocityIncrementFloat,'f',4);

                ui->tableWidget->setItem(3,1,new QTableWidgetItem(C5XAccVelocityIncrementtrDis));
                ui->tableWidget->item(3,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y加速度计1s补偿后速度增量47-50字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YAccVelocityIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5YAccVelocityIncrementInt32 = qint32(C5YAccVelocityIncrementStr.toUInt(nullptr,16));
//                C5YAccVelocityIncrementFloat = *(float*)&C5YAccVelocityIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5YAccVelocityIncrementStr.toUInt(nullptr,16));
                C5YAccVelocityIncrementFloat = C5ValueUnion.floatValue;

                QString C5YAccVelocityIncrementtrDis = QString::number(C5YAccVelocityIncrementFloat,'f',4);

                ui->tableWidget->setItem(4,1,new QTableWidgetItem(C5YAccVelocityIncrementtrDis));
                ui->tableWidget->item(4,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计1s补偿后速度增量51-54字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZAccVelocityIncrementStr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
//                qint32 C5ZAccVelocityIncrementInt32 = qint32(C5ZAccVelocityIncrementStr.toUInt(nullptr,16));
//                C5ZAccVelocityIncrementFloat = *(float*)&C5ZAccVelocityIncrementInt32;

                C5ValueUnion.qint32Value = qint32(C5ZAccVelocityIncrementStr.toUInt(nullptr,16));
                C5ZAccVelocityIncrementFloat = C5ValueUnion.floatValue;

                QString C5ZAccVelocityIncrementtrDis = QString::number(C5ZAccVelocityIncrementFloat,'f',4);

                ui->tableWidget->setItem(5,1,new QTableWidgetItem(C5ZAccVelocityIncrementtrDis));
                ui->tableWidget->item(5,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


                /**************************************C5解析X陀螺差频55-58字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroDifFrequencytr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroDifFrequencyInt32 = qint32(C5XgyroDifFrequencytr.toUInt(nullptr,16));
                C5XgyroDifFrequency = C5XgyroDifFrequencyInt32 * qPow(10,-3);
                QString C5XgyroDifFrequencytrDis = QString::number(C5XgyroDifFrequency,'f',4);

                ui->tableWidget->setItem(0,2,new QTableWidgetItem(C5XgyroDifFrequencytrDis));
                ui->tableWidget->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺差频59-62字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroDifFrequencystr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroDifFrequencyInt32 = qint32(C5YgyroDifFrequencystr.toUInt(nullptr,16));
                C5YgyroDifFrequency = C5YgyroDifFrequencyInt32 * qPow(10,-3);
                QString C5YgyroDifFrequencytrDis = QString::number(C5YgyroDifFrequency,'f',4);

                ui->tableWidget->setItem(1,2,new QTableWidgetItem(C5YgyroDifFrequencytrDis));
                ui->tableWidget->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺差频63-66字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroDifFrequencystr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroDifFrequencyInt32 = qint32(C5ZgyroDifFrequencystr.toUInt(nullptr,16));
                C5ZgyroDifFrequency = C5ZgyroDifFrequencyInt32 * qPow(10,-3);
                QString C5ZgyroDifFrequencytrDis = QString::number(C5ZgyroDifFrequency,'f',4);
                ui->tableWidget->setItem(2,2,new QTableWidgetItem(C5ZgyroDifFrequencytrDis));
                ui->tableWidget->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X加速度计差频67-70字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XaccelerometerDifFrestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XaccelerometerDifFreInt32 = qint32(C5XaccelerometerDifFrestr.toUInt(nullptr,16));
                C5XaccelerometerDifFre = C5XaccelerometerDifFreInt32 * qPow(10,-3);
                QString C5XaccelerometerDifFretrDis = QString::number(C5XaccelerometerDifFre,'f',4);

                ui->tableWidget->setItem(3,2,new QTableWidgetItem(C5XaccelerometerDifFretrDis));
                ui->tableWidget->item(3,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y加速度计差频71-74字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YaccelerometerDifFrestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YaccelerometerDifFreInt32 = qint32(C5YaccelerometerDifFrestr.toUInt(nullptr,16));
                C5YaccelerometerDifFre = C5YaccelerometerDifFreInt32 * qPow(10,-3);
                QString C5YaccelerometerDifFretrDis = QString::number(C5YaccelerometerDifFre,'f',4);

                ui->tableWidget->setItem(4,2,new QTableWidgetItem(C5YaccelerometerDifFretrDis));
                ui->tableWidget->item(4,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计差频75-78字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZaccelerometerDifFrestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZaccelerometerDifFreInt32 = qint32(C5ZaccelerometerDifFrestr.toUInt(nullptr,16));
                C5ZaccelerometerDifFre = C5ZaccelerometerDifFreInt32 * qPow(10,-3);
                QString C5ZaccelerometerDifFretrDis = QString::number(C5ZaccelerometerDifFre,'f',4);

                ui->tableWidget->setItem(5,2,new QTableWidgetItem(C5ZaccelerometerDifFretrDis));
                ui->tableWidget->item(5,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺抖幅79-82字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroAmplitudeJitterstr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroAmplitudeJitterInt32 = qint32(C5XgyroAmplitudeJitterstr.toUInt(nullptr,16));
                C5XgyroAmplitudeJitter = C5XgyroAmplitudeJitterInt32;
                QString C5XgyroAmplitudeJittertrDis = QString::number(C5XgyroAmplitudeJitter,'f',0);

                ui->tableWidget->setItem(0,5,new QTableWidgetItem(C5XgyroAmplitudeJittertrDis));
                ui->tableWidget->item(0,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺抖幅83-86字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroAmplitudeJitterstr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroAmplitudeJitterInt32 = qint32(C5YgyroAmplitudeJitterstr.toUInt(nullptr,16));
                C5YgyroAmplitudeJitter = C5YgyroAmplitudeJitterInt32;
                QString C5YgyroAmplitudeJittertrDis = QString::number(C5YgyroAmplitudeJitter,'f',0);

                ui->tableWidget->setItem(1,5,new QTableWidgetItem(C5YgyroAmplitudeJittertrDis));
                ui->tableWidget->item(1,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺抖幅87-90字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroAmplitudeJitterstr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroAmplitudeJitterInt32 = qint32(C5ZgyroAmplitudeJitterstr.toUInt(nullptr,16));
                C5ZgyroAmplitudeJitter = C5ZgyroAmplitudeJitterInt32;
                QString C5ZgyroAmplitudeJittertrDis = QString::number(C5ZgyroAmplitudeJitter,'f',0);

                ui->tableWidget->setItem(2,5,new QTableWidgetItem(C5ZgyroAmplitudeJittertrDis));
                ui->tableWidget->item(2,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺抖频91-92字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroAmplitudeFrestr = bufferStrC5.left(4).mid(2,2)+bufferStrC5.left(4).mid(0,2);
                quint16 C5XgyroAmplitudeFreInt32 = quint16(C5XgyroAmplitudeFrestr.toUInt(nullptr,16));
                C5XgyroAmpl1itudeFre = C5XgyroAmplitudeFreInt32;
                QString C5XgyroAmplitudeFretrDis = QString::number(C5XgyroAmpl1itudeFre,'f',0);

                ui->tableWidget->setItem(0,6,new QTableWidgetItem(C5XgyroAmplitudeFretrDis));
                ui->tableWidget->item(0,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺抖频93-94字节***************************************************/
                bufferStrC5.remove(0,4);
                QString C5YgyroAmplitudeFrestr = bufferStrC5.left(4).mid(2,2)+bufferStrC5.left(4).mid(0,2);
                quint16 C5YgyroAmplitudeFreInt32 = quint16(C5YgyroAmplitudeFrestr.toUInt(nullptr,16));
                C5YgyroAmpl1itudeFre = C5YgyroAmplitudeFreInt32;
                QString C5YgyroAmplitudeFretrDis = QString::number(C5YgyroAmpl1itudeFre,'f',0);

                ui->tableWidget->setItem(1,6,new QTableWidgetItem(C5YgyroAmplitudeFretrDis));
                ui->tableWidget->item(1,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺抖频95-96字节***************************************************/
                bufferStrC5.remove(0,4);
                QString C5ZgyroAmplitudeFrestr = bufferStrC5.left(4).mid(2,2)+bufferStrC5.left(4).mid(0,2);
                quint16 C5ZgyroAmplitudeFreInt32 = quint16(C5ZgyroAmplitudeFrestr.toUInt(nullptr,16));
                C5ZgyroAmpl1itudeFre = C5ZgyroAmplitudeFreInt32;
                QString C5ZgyroAmplitudeFretrDis = QString::number(C5ZgyroAmpl1itudeFre,'f',0);

                ui->tableWidget->setItem(2,6,new QTableWidgetItem(C5ZgyroAmplitudeFretrDis));
                ui->tableWidget->item(2,6)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺温度1，97-100字节***************************************************/
                bufferStrC5.remove(0,4);
                QString C5XgyroTemp1str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroTemp1Int32 = qint32(C5XgyroTemp1str.toUInt(nullptr,16));
                C5XgyroTemp1 = C5XgyroTemp1Int32 * qPow(10,-4);
                QString C5XgyroTemp1trDis = QString::number(C5XgyroTemp1,'f',4);

                ui->tableWidget->setItem(0,3,new QTableWidgetItem(C5XgyroTemp1trDis));
                ui->tableWidget->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X陀螺温度2，101-104字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XgyroTemp2str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XgyroTemp2Int32 = qint32(C5XgyroTemp2str.toUInt(nullptr,16));
                C5XgyroTemp2 = C5XgyroTemp2Int32 * qPow(10,-4);
                QString C5XgyroTemp2trDis = QString::number(C5XgyroTemp2,'f',4);

                ui->tableWidget->setItem(0,4,new QTableWidgetItem(C5XgyroTemp2trDis));
                ui->tableWidget->item(0,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺温度1，105-108字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroTemp1str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroTemp1Int32 = qint32(C5YgyroTemp1str.toUInt(nullptr,16));
                C5YgyroTemp1 = C5YgyroTemp1Int32 * qPow(10,-4);
                QString C5YgyroTemp1trDis = QString::number(C5YgyroTemp1,'f',4);

                ui->tableWidget->setItem(1,3,new QTableWidgetItem(C5YgyroTemp1trDis));
                ui->tableWidget->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y陀螺温度2，109-112字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YgyroTemp2str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YgyroTemp2Int32 = qint32(C5YgyroTemp2str.toUInt(nullptr,16));
                C5YgyroTemp2 = C5YgyroTemp2Int32 * qPow(10,-4);
                QString C5YgyroTemp2trDis = QString::number(C5YgyroTemp2,'f',4);

                ui->tableWidget->setItem(1,4,new QTableWidgetItem(C5YgyroTemp2trDis));
                ui->tableWidget->item(1,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺温度1，113-116字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroTemp1str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroTemp1Int32 = qint32(C5ZgyroTemp1str.toUInt(nullptr,16));
                C5ZgyroTemp1 = C5ZgyroTemp1Int32 * qPow(10,-4);
                QString C5ZgyroTemp1trDis = QString::number(C5ZgyroTemp1,'f',4);

                ui->tableWidget->setItem(2,3,new QTableWidgetItem(C5ZgyroTemp1trDis));
                ui->tableWidget->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z陀螺温度2，117-120字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZgyroTemp2str = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZgyroTemp2Int32 = qint32(C5ZgyroTemp2str.toUInt(nullptr,16));
                C5ZgyroTemp2 = C5ZgyroTemp2Int32 * qPow(10,-4);
                QString C5ZgyroTemp2trDis = QString::number(C5ZgyroTemp2,'f',4);

                ui->tableWidget->setItem(2,4,new QTableWidgetItem(C5ZgyroTemp2trDis));
                ui->tableWidget->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析IF板温度，121-124字节--没有在界面显示***************************************************/
                bufferStrC5.remove(0,8);
                QString C5IFtemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5IFtempertureInt32 = qint32(C5IFtemperturestr.toUInt(nullptr,16));
                qreal C5IFtemperture = C5IFtempertureInt32 * qPow(10,-4);
                QString C5IFtemperturetrDis = QString::number(C5IFtemperture,'f',4);

        //        ui->tableWidget->setItem(2,4,new QTableWidgetItem(C5IFtemperturetrDis));
        //        ui->tableWidget->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析X加速度计温度，125-128字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5XAccelerometerTemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5XAccelerometerTempertureInt32 = qint32(C5XAccelerometerTemperturestr.toUInt(nullptr,16));
                C5XAccelerometerTemperture = C5XAccelerometerTempertureInt32 * qPow(10,-4);
                QString C5XAccelerometerTemperturetrDis = QString::number(C5XAccelerometerTemperture,'f',4);

                ui->tableWidget->setItem(3,3,new QTableWidgetItem(C5XAccelerometerTemperturetrDis));
                ui->tableWidget->item(3,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Y加速度计温度，129-132字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5YAccelerometerTemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5YAccelerometerTempertureInt32 = qint32(C5YAccelerometerTemperturestr.toUInt(nullptr,16));
                C5YAccelerometerTemperture = C5YAccelerometerTempertureInt32 * qPow(10,-4);
                QString C5YAccelerometerTemperturetrDis = QString::number(C5YAccelerometerTemperture,'f',4);

                ui->tableWidget->setItem(4,3,new QTableWidgetItem(C5YAccelerometerTemperturetrDis));
                ui->tableWidget->item(4,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5解析Z加速度计温度，133-136字节***************************************************/
                bufferStrC5.remove(0,8);
                QString C5ZAccelerometerTemperturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5ZAccelerometerTempertureInt32 = qint32(C5ZAccelerometerTemperturestr.toUInt(nullptr,16));
                C5ZAccelerometerTemperture = C5ZAccelerometerTempertureInt32 * qPow(10,-4);
                QString C5ZAccelerometerTemperturetrDis = QString::number(C5ZAccelerometerTemperture,'f',4);

                ui->tableWidget->setItem(5,3,new QTableWidgetItem(C5ZAccelerometerTemperturetrDis));
                ui->tableWidget->item(5,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C5采集表温度137-140字节，暂时没显示在界面***************************************************/
                bufferStrC5.remove(0,8);
                QString C5AcquisitionMeterTemperaturestr = bufferStrC5.left(8).mid(6,2)+bufferStrC5.left(8).mid(4,2)+bufferStrC5.left(8).mid(2,2)+bufferStrC5.left(8).mid(0,2);
                qint32 C5AcquisitionMeterTemperatureInt32 = qint32(C5AcquisitionMeterTemperaturestr.toUInt(nullptr,16));
                qreal C5AcquisitionMeterTemperature = C5AcquisitionMeterTemperatureInt32 * qPow(10,-4);
                QString C5AcquisitionMeterTemperaturetrDis = QString::number(C5AcquisitionMeterTemperature,'f',4);


                QString dataInvaildRecordStr =  QString::number(dataInvaildRecord,10);
                QTextStream dataOutC5(&C5fileSave);

                QString dataStr5 = "\n"+ dataInvaildRecordStr+","+"C5"+","+sysTimeStr+","+C5XGyroAngleIncreasetrDis+","+C5YGyroAngleIncreasetrDis+","+C5ZGyroAngleIncreasetrDis+","+C5XAccelerometerSpeedIncrementtrDis+","+C5YAccelerometerSpeedIncrementtrDis+","+C5ZAccelerometerSpeedIncrementtrDis+","+C5XgyroCompensatedAngleIncrementtrDis+","+C5YgyroCompensatedAngleIncrementtrDis+","+C5ZgyroCompensatedAngleIncrementtrDis+","+C5XAccVelocityIncrementtrDis+","+C5YAccVelocityIncrementtrDis+","+C5ZAccVelocityIncrementtrDis+","+C5XgyroDifFrequencytrDis+","+C5YgyroDifFrequencytrDis+","+C5ZgyroDifFrequencytrDis+","+C5XaccelerometerDifFretrDis+","+C5YaccelerometerDifFretrDis+","+C5ZaccelerometerDifFretrDis+","+C5XgyroAmplitudeJittertrDis+","+C5YgyroAmplitudeJittertrDis+","+C5ZgyroAmplitudeJittertrDis+","+C5XgyroAmplitudeFretrDis+","+C5YgyroAmplitudeFretrDis+","+C5ZgyroAmplitudeFretrDis+","+C5XgyroTemp1trDis+","+C5XgyroTemp2trDis+","+C5YgyroTemp1trDis+","+C5YgyroTemp2trDis+","+C5ZgyroTemp1trDis+","+C5ZgyroTemp2trDis+","+C5IFtemperturetrDis+","+C5XAccelerometerTemperturetrDis+","+C5YAccelerometerTemperturetrDis+","+C5ZAccelerometerTemperturetrDis+","+C5AcquisitionMeterTemperaturetrDis;
                        dataOutC5<<dataStr5.toUtf8();

                /**************************************C5解析校验和141字节，暂时没校验***************************************************/
//                bufferStrC5.remove(0,8);
//                QString C5Checksumstr = bufferStrC5.left(2);
//                quint8 C5ChecksumInt8 = quint8(C5Checksumstr.toUInt(nullptr,16));
//                //qreal C5Checksum = C5ChecksumInt32 * qPow(10,-4);
                //QString C5ChecksumtrDis = QString::number(C5Checksum,'f',4);
            }
            else
            {
                qDebug() <<  "错误：参考信息C5校验和错误！";
            }
        }
        else
        {
            qDebug() <<  "错误：参考信息C5报文格式错误，无法解析！";
        }

        /**********************************************解析解算信息C6******************************************************************/
        QString bufferStrC6 = QString(bufferStr);
        bufferStrC6.remove(0,672);
        if(bufferStrC6[0] == 'e' && bufferStrC6[1] == 'b'&&bufferStrC6[4] == 'c' && bufferStrC6[5] == '6')
        {
            int C6checkNumInt = 0;
            QString C6checkNumStr;
            for(int i= 4;i<134;i=i+2)
            {
                C6checkNumInt = C6checkNumInt + bufferStrC6.mid(i,2).toInt(nullptr,16);
            }
            C6checkNumStr = QString::number(C6checkNumInt,16).right(2);
            if(C6checkNumStr == bufferStrC6.mid(134,2))
            {
                ui->tableWidget_3->clearContents();
                /**************************************C6无阻尼横摇角7-10字节***************************************************/
                bufferStrC6.remove(0,14);
                QString C6UndampedRollAngletr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedRollAngleInt32 = qint32(C6UndampedRollAngletr.toUInt(nullptr,16));
//                float C6UndampedRollAngleFloat = *(float*)&C6UndampedRollAngleInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedRollAngletr.toUInt(nullptr,16));
                C6UndampedRollAngleFloat = C5ValueUnion.floatValue;

                QString C6UndampedRollAngletrDis = QString::number(C6UndampedRollAngleFloat,'f',4);

                ui->tableWidget_3->setItem(0,0,new QTableWidgetItem(C6UndampedRollAngletrDis));
                ui->tableWidget_3->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼纵摇角11-14字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedPitchAngletr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedPitchAngleInt32 = qint32(C6UndampedPitchAngletr.toUInt(nullptr,16));
//                float C6UndampedPitchAngleFloat = *(float*)&C6UndampedPitchAngleInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedPitchAngletr.toUInt(nullptr,16));
                C6UndampedPitchAngleFloat = C5ValueUnion.floatValue;

                QString C6UndampedPitchAngletrDis = QString::number(C6UndampedPitchAngleFloat,'f',4);

                ui->tableWidget_3->setItem(1,0,new QTableWidgetItem(C6UndampedPitchAngletrDis));
                ui->tableWidget_3->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼航向角15-18字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedHeadingAngulartr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedHeadingAngularInt32 = qint32(C6UndampedHeadingAngulartr.toUInt(nullptr,16));
//                float C6UndampedHeadingAngularFloat = *(float*)&C6UndampedHeadingAngularInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedHeadingAngulartr.toUInt(nullptr,16));
                C6UndampedHeadingAngularFloat = C5ValueUnion.floatValue;

                QString C6UndampedHeadingAngulartrDis = QString::number(C6UndampedHeadingAngularFloat,'f',4);

                ui->tableWidget_3->setItem(2,0,new QTableWidgetItem(C6UndampedHeadingAngulartrDis));
                ui->tableWidget_3->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼北速19-22字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedNorthSpeedtr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedNorthSpeedInt32 = qint32(C6UndampedNorthSpeedtr.toUInt(nullptr,16));
//                float C6UndampedNorthSpeedFloat = *(float*)&C6UndampedNorthSpeedInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedNorthSpeedtr.toUInt(nullptr,16));
                C6UndampedNorthSpeedFloat = C5ValueUnion.floatValue;


                QString C6UndampedNorthSpeedtrDis = QString::number(C6UndampedNorthSpeedFloat,'f',4);

                ui->tableWidget_3->setItem(4,0,new QTableWidgetItem(C6UndampedNorthSpeedtrDis));
                ui->tableWidget_3->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼东速23-26字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedEastSpeedtr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedEastSpeedInt32 = qint32(C6UndampedEastSpeedtr.toUInt(nullptr,16));
//                float C6UndampedEastSpeedFloat = *(float*)&C6UndampedEastSpeedInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedEastSpeedtr.toUInt(nullptr,16));
                C6UndampedEastSpeedFloat = C5ValueUnion.floatValue;

                QString C6UndampedEastSpeedtrDis = QString::number(C6UndampedEastSpeedFloat,'f',4);

                ui->tableWidget_3->setItem(3,0,new QTableWidgetItem(C6UndampedEastSpeedtrDis));
                ui->tableWidget_3->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼垂速27-30字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6VerticalVelocitytr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6VerticalVelocityInt32 = qint32(C6VerticalVelocitytr.toUInt(nullptr,16));
//                float C6VerticalVelocityFloat = *(float*)&C6VerticalVelocityInt32;

                C5ValueUnion.qint32Value = qint32(C6VerticalVelocitytr.toUInt(nullptr,16));
                C6VerticalVelocityFloat = C5ValueUnion.floatValue;

                QString C6VerticalVelocitytrDis = QString::number(C6VerticalVelocityFloat,'f',4);

                ui->tableWidget_3->setItem(5,0,new QTableWidgetItem(C6VerticalVelocitytrDis));
                ui->tableWidget_3->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼纬度31-34字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedLatStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedLatInt32 = qint32(C6UndampedLatStr.toUInt(nullptr,16));
//                float C6UndampedLatFloat = *(float*)&C6UndampedLatInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedLatStr.toUInt(nullptr,16));
                C6UndampedLatFloat = C5ValueUnion.floatValue;

                QString C6UndampedLattrDis = QString::number(C6UndampedLatFloat,'f',4);

                ui->tableWidget_3->setItem(6,0,new QTableWidgetItem(C6UndampedLattrDis));
                ui->tableWidget_3->item(6,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼经度35-38字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedLongStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedLongInt32 = qint32(C6UndampedLongStr.toUInt(nullptr,16));
//                float C6UndampedLongFloat = *(float*)&C6UndampedLongInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedLongStr.toUInt(nullptr,16));
                C6UndampedLongFloat = C5ValueUnion.floatValue;

                QString C6UndampedLongtrDis = QString::number(C6UndampedLongFloat,'f',4);

                ui->tableWidget_3->setItem(7,0,new QTableWidgetItem(C6UndampedLongtrDis));
                ui->tableWidget_3->item(7,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6无阻尼高度39-42字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6UndampedHeightStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6UndampedHeightInt32 = qint32(C6UndampedHeightStr.toUInt(nullptr,16));
//                float C6UndampedHeightFloat = *(float*)&C6UndampedHeightInt32;

                C5ValueUnion.qint32Value = qint32(C6UndampedHeightStr.toUInt(nullptr,16));
                float C6UndampedHeightFloat = C5ValueUnion.floatValue;

                QString C6UndampedHeighttrDis = QString::number(C6UndampedHeightFloat,'f',4);

                ui->tableWidget_3->setItem(8,0,new QTableWidgetItem(C6UndampedHeighttrDis));
                ui->tableWidget_3->item(8,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6X陀螺零偏43-46字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6XGroyStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6XGroyInt32 = qint32(C6XGroyStr.toUInt(nullptr,16));
//                float C6XGroyFloat = *(float*)&C6XGroyInt32;

                C5ValueUnion.qint32Value = qint32(C6XGroyStr.toUInt(nullptr,16));
                C6XGroyFloat = C5ValueUnion.floatValue;

                QString C6XGroyStrDis = QString::number(C6XGroyFloat,'f',4);

                ui->tableWidget_3->setItem(9,0,new QTableWidgetItem(C6XGroyStrDis));
                ui->tableWidget_3->item(9,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Y陀螺零偏47-50字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6YGroyStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6YGroyInt32 = qint32(C6YGroyStr.toUInt(nullptr,16));
//                C6YGroyFloat = *(float*)&C6YGroyInt32;

                C5ValueUnion.qint32Value = qint32(C6YGroyStr.toUInt(nullptr,16));
                C6YGroyFloat = C5ValueUnion.floatValue;

                QString C6YGroyStrDis = QString::number(C6YGroyFloat,'f',4);

                ui->tableWidget_3->setItem(10,0,new QTableWidgetItem(C6YGroyStrDis));
                ui->tableWidget_3->item(10,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Z陀螺零偏51-54字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6ZGroyStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6ZGroyInt32 = qint32(C6ZGroyStr.toUInt(nullptr,16));
//                C6ZGroyFloat = *(float*)&C6ZGroyInt32;

                C5ValueUnion.qint32Value = qint32(C6ZGroyStr.toUInt(nullptr,16));
                C6ZGroyFloat = C5ValueUnion.floatValue;
                QString C6ZGroyStrDis = QString::number(C6ZGroyFloat,'f',4);

                ui->tableWidget_3->setItem(11,0,new QTableWidgetItem(C6ZGroyStrDis));
                ui->tableWidget_3->item(11,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6X加速度计零位55-58字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6XAccelerometerStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6XAccelerometerInt32 = qint32(C6XAccelerometerStr.toUInt(nullptr,16));
//                C6XAccelerometerFloat = *(float*)&C6XAccelerometerInt32;

                C5ValueUnion.qint32Value = qint32(C6XAccelerometerStr.toUInt(nullptr,16));
                C6XAccelerometerFloat = C5ValueUnion.floatValue;

                QString C6XAccelerometerStrDis = QString::number(C6XAccelerometerFloat,'f',4);

                ui->tableWidget_3->setItem(12,0,new QTableWidgetItem(C6XAccelerometerStrDis));
                ui->tableWidget_3->item(12,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Y加速度计零位59-62字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6YAccelerometerStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6YAccelerometerInt32 = qint32(C6YAccelerometerStr.toUInt(nullptr,16));
//                C6YAccelerometerFloat = *(float*)&C6YAccelerometerInt32;

                C5ValueUnion.qint32Value = qint32(C6YAccelerometerStr.toUInt(nullptr,16));
                C6YAccelerometerFloat = C5ValueUnion.floatValue;

                QString C6YAccelerometerStrDis = QString::number(C6YAccelerometerFloat,'f',4);

                ui->tableWidget_3->setItem(13,0,new QTableWidgetItem(C6YAccelerometerStrDis));
                ui->tableWidget_3->item(13,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                /**************************************C6Z加速度计零位63-66字节***************************************************/
                bufferStrC6.remove(0,8);
                QString C6ZAccelerometerStr = bufferStrC6.left(8).mid(6,2)+bufferStrC6.left(8).mid(4,2)+bufferStrC6.left(8).mid(2,2)+bufferStrC6.left(8).mid(0,2);
//                qint32 C6ZAccelerometerInt32 = qint32(C6ZAccelerometerStr.toUInt(nullptr,16));
//                C6ZAccelerometerFloat = *(float*)&C6ZAccelerometerInt32;

                C5ValueUnion.qint32Value = qint32(C6ZAccelerometerStr.toUInt(nullptr,16));
                C6ZAccelerometerFloat = C5ValueUnion.floatValue;

                QString C6ZAccelerometerStrDis = QString::number(C6ZAccelerometerFloat,'f',4);

                ui->tableWidget_3->setItem(14,0,new QTableWidgetItem(C6ZAccelerometerStrDis));
                ui->tableWidget_3->item(14,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            }
            else
            {
                qDebug() <<  "错误：工况信息C6校验和错误！";
            }
        }
        else
        {
            qDebug() <<  "错误：工况信息C6报文错误，无法解析！";
        }


        /**********************************************解析工况信息C7******************************************************************/
        //if(bufferStr[4] == 'c' && bufferStr[5] == '7' && bufferStr.length()==136)
        QString bufferStrC7 = QString(bufferStr);
        bufferStrC7.remove(0,808);
        if(bufferStrC7[4] == 'c' && bufferStrC7[5] == '7')
        {

        }
        else
        {
            //qDebug() <<  "错误：工况信息C7报文错误，无法解析！";
        }

         //qDebug()<<"成功：数据解析完毕！";
    }

    /***********************************************发出查询命令后解析返回的数据,且有52个字节的包**************************************************/
    //陀螺和加速度计标定参数，陀螺和加速度计温补系数
    else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&& bufferStr.length()==1048)
    {
        QString bufferStrTemp = QString(bufferStr);
        bufferStrTemp.remove(0,944);

        /***********************************************发出查询命令后解析返回的陀螺标定数据**************************************************/
        if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == '7')
        {

            bufferStrTemp.remove(0,6);
            QString XGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XGyroScaleInt32 = qint32(XGyroScaleStr.toUInt(nullptr,16));
            qreal XGyroScale = XGyroScaleInt32 * qPow(10,-8);
            //QString XGyroScaleStrDis = QString("%1").arg(XGyroScale)+"kn";
            QString XGyroScaleStrDis = QString::number(XGyroScale,'f',4);
            ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(XGyroScaleStrDis));
            ui->tableWidget_2->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************Y陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YGyroScaleInt32 = qint32(YGyroScaleStr.toUInt(nullptr,16));
            qreal YGyroScale = YGyroScaleInt32 * qPow(10,-8);
            //QString YGyroScaleStrDis = QString("%1").arg(YGyroScale)+"kn";
            QString YGyroScaleStrDis = QString::number(YGyroScale,'f',4);
            ui->tableWidget_2->setItem(1,0,new QTableWidgetItem(YGyroScaleStrDis));
            ui->tableWidget_2->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZGyroScaleInt32 = qint32(ZGyroScaleStr.toUInt(nullptr,16));
            qreal ZGyroScale = ZGyroScaleInt32 * qPow(10,-8);
            //QString ZGyroScaleStrDis = QString("%1").arg(ZGyroScale)+"kn";
            QString ZGyroScaleStrDis = QString::number(ZGyroScale,'f',4);
            ui->tableWidget_2->setItem(2,0,new QTableWidgetItem(ZGyroScaleStrDis));
            ui->tableWidget_2->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString XZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XZeroBiasInt32 = qint32(XZeroBiasStr.toUInt(nullptr,16));
            qreal XZeroBias = XZeroBiasInt32 * qPow(10,-6);
            //QString XZeroBiasStrDis = QString("%1").arg(XZeroBias)+"kn";
            QString XZeroBiasStrDis = QString::number(XZeroBias,'f',4);
            ui->tableWidget_2->setItem(0,3,new QTableWidgetItem(XZeroBiasStrDis));
            ui->tableWidget_2->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString YZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YZeroBiasInt32 = qint32(YZeroBiasStr.toUInt(nullptr,16));
            qreal YZeroBias = YZeroBiasInt32 * qPow(10,-6);
            //QString YZeroBiasStrDis = QString("%1").arg(YZeroBias)+"kn";
            QString YZeroBiasStrDis = QString::number(YZeroBias,'f',4);
            ui->tableWidget_2->setItem(1,3,new QTableWidgetItem(YZeroBiasStrDis));
            ui->tableWidget_2->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZZeroBiasInt32 = qint32(ZZeroBiasStr.toUInt(nullptr,16));
            qreal ZZeroBias = ZZeroBiasInt32 * qPow(10,-6);
            //QString ZZeroBiasStrDis = QString("%1").arg(ZZeroBias)+"kn";
            QString ZZeroBiasStrDis = QString::number(ZZeroBias,'f',4);
            ui->tableWidget_2->setItem(2,3,new QTableWidgetItem(ZZeroBiasStrDis));
            ui->tableWidget_2->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uxy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUxyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUxyInt32 = qint32(GyroInstallErrorUxyStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUxy = GyroInstallErrorUxyInt32 * qPow(10,-4);
            //QString GyroInstallErrorUxyStrDis = QString("%1").arg(GyroInstallErrorUxy)+"kn";
            QString GyroInstallErrorUxyStrDis = QString::number(GyroInstallErrorUxy,'f',4);
            ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(GyroInstallErrorUxyStrDis));
            ui->tableWidget_2->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uxz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUxzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUxzInt32 = qint32(GyroInstallErrorUxzStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUxz = GyroInstallErrorUxzInt32 * qPow(10,-4);
            //QString GyroInstallErrorUxzStrDis = QString("%1").arg(GyroInstallErrorUxz)+"kn";
            QString GyroInstallErrorUxzStrDis = QString::number(GyroInstallErrorUxz,'f',4);
            ui->tableWidget_2->setItem(0,2,new QTableWidgetItem(GyroInstallErrorUxzStrDis));
            ui->tableWidget_2->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uyx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUyxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUyxInt32 = qint32(GyroInstallErrorUyxStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUyx = GyroInstallErrorUyxInt32 * qPow(10,-4);
            //QString GyroInstallErrorUyxStrDis = QString("%1").arg(GyroInstallErrorUyx)+"kn";
            QString GyroInstallErrorUyxStrDis = QString::number(GyroInstallErrorUyx,'f',4);
            ui->tableWidget_2->setItem(1,1,new QTableWidgetItem(GyroInstallErrorUyxStrDis));
            ui->tableWidget_2->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uyz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUyzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUyzInt32 = qint32(GyroInstallErrorUyzStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUyz = GyroInstallErrorUyzInt32 * qPow(10,-4);
            //QString GyroInstallErrorUyzStrDis = QString("%1").arg(GyroInstallErrorUyz)+"kn";
            QString GyroInstallErrorUyzStrDis = QString::number(GyroInstallErrorUyz,'f',4);
            ui->tableWidget_2->setItem(1,2,new QTableWidgetItem(GyroInstallErrorUyzStrDis));
            ui->tableWidget_2->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uzx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUzxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUzxInt32 = qint32(GyroInstallErrorUzxStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUzx = GyroInstallErrorUzxInt32 * qPow(10,-4);
            //QString GyroInstallErrorUzxStrDis = QString("%1").arg(GyroInstallErrorUzx)+"kn";
            QString GyroInstallErrorUzxStrDis = QString::number(GyroInstallErrorUzx,'f',4);
            ui->tableWidget_2->setItem(2,1,new QTableWidgetItem(GyroInstallErrorUzxStrDis));
            ui->tableWidget_2->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************陀螺安装误差Uzy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString GyroInstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 GyroInstallErrorUzyInt32 = qint32(GyroInstallErrorUzyStr.toUInt(nullptr,16));
            qreal GyroInstallErrorUzy = GyroInstallErrorUzyInt32 * qPow(10,-4);
            //QString GyroInstallErrorUzyStrDis = QString("%1").arg(GyroInstallErrorUzy)+"kn";
            QString GyroInstallErrorUzyStrDis = QString::number(GyroInstallErrorUzy,'f',4);
            ui->tableWidget_2->setItem(2,2,new QTableWidgetItem(GyroInstallErrorUzyStrDis));
            ui->tableWidget_2->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

        /***********************************************发出查询命令后解析返回的加速度计标定数据**************************************************/
        else if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == '8')
        {

            bufferStrTemp.remove(0,6);
            QString XAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XAccelerometerScaleInt32 = qint32(XAccelerometerScaleStr.toUInt(nullptr,16));
            qreal XAccelerometerScale = XAccelerometerScaleInt32 * qPow(10,-6);
            //QString XAccelerometerScaleStrDis = QString("%1").arg(XAccelerometerScale)+"kn";
            QString XAccelerometerScaleStrDis = QString::number(XAccelerometerScale,'f',4);
            ui->tableWidget_2->setItem(3,0,new QTableWidgetItem(XAccelerometerScaleStrDis));
            ui->tableWidget_2->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************Y加速度计标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YAccelerometerScaleInt32 = qint32(YAccelerometerScaleStr.toUInt(nullptr,16));
            qreal YAccelerometerScale = YAccelerometerScaleInt32 * qPow(10,-6);
            //QString YAccelerometerScaleStrDis = QString("%1").arg(YAccelerometerScale)+"kn";
            QString YAccelerometerScaleStrDis = QString::number(YAccelerometerScale,'f',4);
            ui->tableWidget_2->setItem(4,0,new QTableWidgetItem(YAccelerometerScaleStrDis));
            ui->tableWidget_2->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerometerScaleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZAccelerometerScaleInt32 = qint32(ZAccelerometerScaleStr.toUInt(nullptr,16));
            qreal ZAccelerometerScale = ZAccelerometerScaleInt32 * qPow(10,-6);
            //QString ZAccelerometerScaleStrDis = QString("%1").arg(ZAccelerometerScale)+"kn";
            QString ZAccelerometerScaleStrDis = QString::number(ZAccelerometerScale,'f',4);
            ui->tableWidget_2->setItem(5,0,new QTableWidgetItem(ZAccelerometerScaleStrDis));
            ui->tableWidget_2->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString XZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XZeroBiasInt32 = qint32(XZeroBiasStr.toUInt(nullptr,16));
            qreal XZeroBias = XZeroBiasInt32 * qPow(10,-6);
            //QString XZeroBiasStrDis = QString("%1").arg(XZeroBias)+"kn";
            QString XZeroBiasStrDis = QString::number(XZeroBias,'f',4);
            ui->tableWidget_2->setItem(3,3,new QTableWidgetItem(XZeroBiasStrDis));
            ui->tableWidget_2->item(3,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString YZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YZeroBiasInt32 = qint32(YZeroBiasStr.toUInt(nullptr,16));
            qreal YZeroBias = YZeroBiasInt32 * qPow(10,-6);
            //QString YZeroBiasStrDis = QString("%1").arg(YZeroBias)+"kn";
            QString YZeroBiasStrDis = QString::number(YZeroBias,'f',4);
            ui->tableWidget_2->setItem(4,3,new QTableWidgetItem(YZeroBiasStrDis));
            ui->tableWidget_2->item(4,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZZeroBiasInt32 = qint32(ZZeroBiasStr.toUInt(nullptr,16));
            qreal ZZeroBias = ZZeroBiasInt32 * qPow(10,-6);
            //QString ZZeroBiasStrDis = QString("%1").arg(ZZeroBias)+"kn";
            QString ZZeroBiasStrDis = QString::number(ZZeroBias,'f',4);
            ui->tableWidget_2->setItem(5,3,new QTableWidgetItem(ZZeroBiasStrDis));
            ui->tableWidget_2->item(5,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uxy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUxyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUxyInt32 = qint32(AccelerometerInstallErrorUxyStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUxy = AccelerometerInstallErrorUxyInt32 * qPow(10,-4);
            //QString AccelerometerInstallErrorUxyStrDis = QString("%1").arg(AccelerometerInstallErrorUxy)+"kn";
            QString AccelerometerInstallErrorUxyStrDis = QString::number(AccelerometerInstallErrorUxy,'f',4);
            ui->tableWidget_2->setItem(3,1,new QTableWidgetItem(AccelerometerInstallErrorUxyStrDis));
            ui->tableWidget_2->item(3,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uxz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUxzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUxzInt32 = qint32(AccelerometerInstallErrorUxzStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUxz = AccelerometerInstallErrorUxzInt32 * qPow(10,-4);
            //QString AccelerometerInstallErrorUxzStrDis = QString("%1").arg(AccelerometerInstallErrorUxz)+"kn";
            QString AccelerometerInstallErrorUxzStrDis = QString::number(AccelerometerInstallErrorUxz,'f',4);
            ui->tableWidget_2->setItem(3,2,new QTableWidgetItem(AccelerometerInstallErrorUxzStrDis));
            ui->tableWidget_2->item(3,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uyx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUyxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUyxInt32 = qint32(AccelerometerInstallErrorUyxStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUyx = AccelerometerInstallErrorUyxInt32 * qPow(10,-4);
            //QString AccelerometerInstallErrorUyxStrDis = QString("%1").arg(AccelerometerInstallErrorUyx)+"kn";
            QString AccelerometerInstallErrorUyxStrDis = QString::number(AccelerometerInstallErrorUyx,'f',4);
            ui->tableWidget_2->setItem(4,1,new QTableWidgetItem(AccelerometerInstallErrorUyxStrDis));
            ui->tableWidget_2->item(4,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uyz常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUyzStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUyzInt32 = qint32(AccelerometerInstallErrorUyzStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUyz = AccelerometerInstallErrorUyzInt32 * qPow(10,-4);
            //QString AccelerometerInstallErrorUyzStrDis = QString("%1").arg(AccelerometerInstallErrorUyz)+"kn";
            QString AccelerometerInstallErrorUyzStrDis = QString::number(AccelerometerInstallErrorUyz,'f',4);
            ui->tableWidget_2->setItem(4,2,new QTableWidgetItem(AccelerometerInstallErrorUyzStrDis));
            ui->tableWidget_2->item(4,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uzx常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUzxStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUzxInt32 = qint32(AccelerometerInstallErrorUzxStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUzx = AccelerometerInstallErrorUzxInt32 * qPow(10,-4);
            //QString AccelerometerInstallErrorUzxStrDis = QString("%1").arg(AccelerometerInstallErrorUzx)+"kn";
            QString AccelerometerInstallErrorUzxStrDis = QString::number(AccelerometerInstallErrorUzx,'f',4);
            ui->tableWidget_2->setItem(5,1,new QTableWidgetItem(AccelerometerInstallErrorUzxStrDis));
            ui->tableWidget_2->item(5,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************加速度计安装误差Uzy常漂***********************************************/
            bufferStrTemp.remove(0,8);

            QString AccelerometerInstallErrorUzyStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 AccelerometerInstallErrorUzyInt32 = qint32(AccelerometerInstallErrorUzyStr.toUInt(nullptr,16));
            qreal AccelerometerInstallErrorUzy = AccelerometerInstallErrorUzyInt32 * qPow(10,-4);
            //QString AccelerometerInstallErrorUzyStrDis = QString("%1").arg(AccelerometerInstallErrorUzy)+"kn";
            QString AccelerometerInstallErrorUzyStrDis = QString::number(AccelerometerInstallErrorUzy,'f',4);
            ui->tableWidget_2->setItem(5,2,new QTableWidgetItem(AccelerometerInstallErrorUzyStrDis));
            ui->tableWidget_2->item(5,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

        /***********************************************发出查询命令后解析返回的陀螺温补系数**************************************************/
        else if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == 'd')
        {

            /***************************************X陀螺零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,6);
            QString XGyroTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XGyroTempCompenCoeff0Int32 = qint32(XGyroTempCompenCoeff0Str.toUInt(nullptr,16));
//            qreal XGyroTempCompenCoeff0 = *(float*)&XGyroTempCompenCoeff0Int32;

            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff0Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff0 = C5ValueUnion.floatValue;

            //QString XGyroTempCompenCoeff0StrDis = QString("%1").arg(XGyroTempCompenCoeff0)+"kn";
            QString XGyroTempCompenCoeff0StrDis = QString::number(XGyroTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(0,0,new QTableWidgetItem(XGyroTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YGyroTempCompenCoeff0Int32 = qint32(YGyroTempCompenCoeff0Str.toUInt(nullptr,16));
//            qreal YGyroTempCompenCoeff0 = *(float*)&YGyroTempCompenCoeff0Int32;

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff0Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff0 = C5ValueUnion.floatValue;

            //QString YGyroTempCompenCoeff0StrDis = QString("%1").arg(YGyroTempCompenCoeff0)+"kn";
            QString YGyroTempCompenCoeff0StrDis = QString::number(YGyroTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(1,0,new QTableWidgetItem(YGyroTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZGyroTempCompenCoeff0Int32 = qint32(ZGyroTempCompenCoeff0Str.toUInt(nullptr,16));
//            qreal ZGyroTempCompenCoeff0 = *(float*)&ZGyroTempCompenCoeff0Int32;

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff0Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff0 = C5ValueUnion.floatValue;

            //QString ZGyroTempCompenCoeff0StrDis = QString("%1").arg(ZGyroTempCompenCoeff0)+"kn";
            QString ZGyroTempCompenCoeff0StrDis = QString::number(ZGyroTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(2,0,new QTableWidgetItem(ZGyroTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XGyroTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XGyroTempCompenCoeff1Int32 = qint32(XGyroTempCompenCoeff1Str.toUInt(nullptr,16));
//            qreal XGyroTempCompenCoeff1 = *(float*)&XGyroTempCompenCoeff1Int32;

            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff1Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff1 = C5ValueUnion.floatValue;

            //QString XGyroTempCompenCoeff1StrDis = QString("%1").arg(XGyroTempCompenCoeff1)+"kn";
            QString XGyroTempCompenCoeff1StrDis = QString::number(XGyroTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(0,1,new QTableWidgetItem(XGyroTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YGyroTempCompenCoeff1Int32 = qint32(YGyroTempCompenCoeff1Str.toUInt(nullptr,16));
//            qreal YGyroTempCompenCoeff1 = *(float*)&YGyroTempCompenCoeff1Int32;

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff1Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff1 = C5ValueUnion.floatValue;

            //QString YGyroTempCompenCoeff1StrDis = QString("%1").arg(YGyroTempCompenCoeff1)+"kn";
            QString YGyroTempCompenCoeff1StrDis = QString::number(YGyroTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(1,1,new QTableWidgetItem(YGyroTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZGyroTempCompenCoeff1Int32 = qint32(ZGyroTempCompenCoeff1Str.toUInt(nullptr,16));
//            qreal ZGyroTempCompenCoeff1 = *(float*)&ZGyroTempCompenCoeff1Int32;

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff1Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff1 = C5ValueUnion.floatValue;


            //QString ZGyroTempCompenCoeff1StrDis = QString("%1").arg(ZGyroTempCompenCoeff1)+"kn";
            QString ZGyroTempCompenCoeff1StrDis = QString::number(ZGyroTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(2,1,new QTableWidgetItem(ZGyroTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XGyroTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XGyroTempCompenCoeff2Int32 = qint32(XGyroTempCompenCoeff2Str.toUInt(nullptr,16));
//            qreal XGyroTempCompenCoeff2 = *(float*)&XGyroTempCompenCoeff2Int32;

            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff2Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff2 = C5ValueUnion.floatValue;

            //QString XGyroTempCompenCoeff2StrDis = QString("%1").arg(XGyroTempCompenCoeff2)+"kn";
            QString XGyroTempCompenCoeff2StrDis = QString::number(XGyroTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(0,2,new QTableWidgetItem(XGyroTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YGyroTempCompenCoeff2Int32 = qint32(YGyroTempCompenCoeff2Str.toUInt(nullptr,16));
//            qreal YGyroTempCompenCoeff2 = *(float*)&YGyroTempCompenCoeff2Int32;

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff2Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff2 = C5ValueUnion.floatValue;

            //QString YGyroTempCompenCoeff2StrDis = QString("%1").arg(YGyroTempCompenCoeff2)+"kn";
            QString YGyroTempCompenCoeff2StrDis = QString::number(YGyroTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(1,2,new QTableWidgetItem(YGyroTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZGyroTempCompenCoeff2Int32 = qint32(ZGyroTempCompenCoeff2Str.toUInt(nullptr,16));
//            qreal ZGyroTempCompenCoeff2 = *(float*)&ZGyroTempCompenCoeff2Int32;

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff2Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff2 = C5ValueUnion.floatValue;

            //QString ZGyroTempCompenCoeff2StrDis = QString("%1").arg(ZGyroTempCompenCoeff2)+"kn";
            QString ZGyroTempCompenCoeff2StrDis = QString::number(ZGyroTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(2,2,new QTableWidgetItem(ZGyroTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X陀螺零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XGyroTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XGyroTempCompenCoeff3Int32 = qint32(XGyroTempCompenCoeff3Str.toUInt(nullptr,16));
//            qreal XGyroTempCompenCoeff3 = *(float*)&XGyroTempCompenCoeff3Int32;

            C5ValueUnion.qint32Value = qint32(XGyroTempCompenCoeff3Str.toUInt(nullptr,16));
            float XGyroTempCompenCoeff3 = C5ValueUnion.floatValue;

            //QString XGyroTempCompenCoeff3StrDis = QString("%1").arg(XGyroTempCompenCoeff3)+"kn";
            QString XGyroTempCompenCoeff3StrDis = QString::number(XGyroTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(0,3,new QTableWidgetItem(XGyroTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y陀螺零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YGyroTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YGyroTempCompenCoeff3Int32 = qint32(YGyroTempCompenCoeff3Str.toUInt(nullptr,16));
//            qreal YGyroTempCompenCoeff3 = *(float*)&YGyroTempCompenCoeff3Int32;

            C5ValueUnion.qint32Value = qint32(YGyroTempCompenCoeff3Str.toUInt(nullptr,16));
            float YGyroTempCompenCoeff3 = C5ValueUnion.floatValue;

            //QString YGyroTempCompenCoeff3StrDis = QString("%1").arg(YGyroTempCompenCoeff3)+"kn";
            QString YGyroTempCompenCoeff3StrDis = QString::number(YGyroTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(1,3,new QTableWidgetItem(YGyroTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZGyroTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZGyroTempCompenCoeff3Int32 = qint32(ZGyroTempCompenCoeff3Str.toUInt(nullptr,16));
//            qreal ZGyroTempCompenCoeff3 = *(float*)&ZGyroTempCompenCoeff3Int32;

            C5ValueUnion.qint32Value = qint32(ZGyroTempCompenCoeff3Str.toUInt(nullptr,16));
            float ZGyroTempCompenCoeff3 = C5ValueUnion.floatValue;

            //QString ZGyroTempCompenCoeff3StrDis = QString("%1").arg(ZGyroTempCompenCoeff3)+"kn";
            QString ZGyroTempCompenCoeff3StrDis = QString::number(ZGyroTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(2,3,new QTableWidgetItem(ZGyroTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }


        /***********************************************发出查询命令后解析返回的加速度计温补系数**************************************************/
        else if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == 'e')
        {

            /***************************************X加速度计零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,6);
            QString XAccelerTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XAccelerTempCompenCoeff0Int32 = qint32(XAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
//            qreal XAccelerTempCompenCoeff0 = *(float*)&XAccelerTempCompenCoeff0Int32;

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff0 = C5ValueUnion.floatValue;

            //QString XAccelerTempCompenCoeff0StrDis = QString("%1").arg(XAccelerTempCompenCoeff0)+"kn";
            QString XAccelerTempCompenCoeff0StrDis = QString::number(XAccelerTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(3,0,new QTableWidgetItem(XAccelerTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(3,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YAccelerTempCompenCoeff0Int32 = qint32(YAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
//            qreal YAccelerTempCompenCoeff0 = *(float*)&YAccelerTempCompenCoeff0Int32;

            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff0 = C5ValueUnion.floatValue;

            //QString YAccelerTempCompenCoeff0StrDis = QString("%1").arg(YAccelerTempCompenCoeff0)+"kn";
            QString YAccelerTempCompenCoeff0StrDis = QString::number(YAccelerTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(4,0,new QTableWidgetItem(YAccelerTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(4,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度0次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff0Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZAccelerTempCompenCoeff0Int32 = qint32(ZAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
//            qreal ZAccelerTempCompenCoeff0 = *(float*)&ZAccelerTempCompenCoeff0Int32;

            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff0Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff0 = C5ValueUnion.floatValue;

            //QString ZAccelerTempCompenCoeff0StrDis = QString("%1").arg(ZAccelerTempCompenCoeff0)+"kn";
            QString ZAccelerTempCompenCoeff0StrDis = QString::number(ZAccelerTempCompenCoeff0,'f',4);
            ui->tableWidget_6->setItem(5,0,new QTableWidgetItem(ZAccelerTempCompenCoeff0StrDis));
            ui->tableWidget_6->item(5,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XAccelerTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XAccelerTempCompenCoeff1Int32 = qint32(XAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
//            qreal XAccelerTempCompenCoeff1 = *(float*)&XAccelerTempCompenCoeff1Int32;

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff1 = C5ValueUnion.floatValue;

            //QString XAccelerTempCompenCoeff1StrDis = QString("%1").arg(XAccelerTempCompenCoeff1)+"kn";
            QString XAccelerTempCompenCoeff1StrDis = QString::number(XAccelerTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(3,1,new QTableWidgetItem(XAccelerTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(3,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YAccelerTempCompenCoeff1Int32 = qint32(YAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
//            qreal YAccelerTempCompenCoeff1 = *(float*)&YAccelerTempCompenCoeff1Int32;

            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff1 = C5ValueUnion.floatValue;

            //QString YAccelerTempCompenCoeff1StrDis = QString("%1").arg(YAccelerTempCompenCoeff1)+"kn";
            QString YAccelerTempCompenCoeff1StrDis = QString::number(YAccelerTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(4,1,new QTableWidgetItem(YAccelerTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(4,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度1次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff1Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZAccelerTempCompenCoeff1Int32 = qint32(ZAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
//            qreal ZAccelerTempCompenCoeff1 = *(float*)&ZAccelerTempCompenCoeff1Int32;

            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff1Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff1 = C5ValueUnion.floatValue;

            //QString ZAccelerTempCompenCoeff1StrDis = QString("%1").arg(ZAccelerTempCompenCoeff1)+"kn";
            QString ZAccelerTempCompenCoeff1StrDis = QString::number(ZAccelerTempCompenCoeff1,'f',4);
            ui->tableWidget_6->setItem(5,1,new QTableWidgetItem(ZAccelerTempCompenCoeff1StrDis));
            ui->tableWidget_6->item(5,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XAccelerTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XAccelerTempCompenCoeff2Int32 = qint32(XAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
//            qreal XAccelerTempCompenCoeff2 = *(float*)&XAccelerTempCompenCoeff2Int32;

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff2 = C5ValueUnion.floatValue;

            //QString XAccelerTempCompenCoeff2StrDis = QString("%1").arg(XAccelerTempCompenCoeff2)+"kn";
            QString XAccelerTempCompenCoeff2StrDis = QString::number(XAccelerTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(3,2,new QTableWidgetItem(XAccelerTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(3,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YAccelerTempCompenCoeff2Int32 = qint32(YAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
//            qreal YAccelerTempCompenCoeff2 = *(float*)&YAccelerTempCompenCoeff2Int32;

            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff2 = C5ValueUnion.floatValue;

            //QString YAccelerTempCompenCoeff2StrDis = QString("%1").arg(YAccelerTempCompenCoeff2)+"kn";
            QString YAccelerTempCompenCoeff2StrDis = QString::number(YAccelerTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(4,2,new QTableWidgetItem(YAccelerTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(4,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度2次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff2Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZAccelerTempCompenCoeff2Int32 = qint32(ZAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
//            qreal ZAccelerTempCompenCoeff2 = *(float*)&ZAccelerTempCompenCoeff2Int32;

            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff2Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff2 = C5ValueUnion.floatValue;

            //QString ZAccelerTempCompenCoeff2StrDis = QString("%1").arg(ZAccelerTempCompenCoeff2)+"kn";
            QString ZAccelerTempCompenCoeff2StrDis = QString::number(ZAccelerTempCompenCoeff2,'f',4);
            ui->tableWidget_6->setItem(5,2,new QTableWidgetItem(ZAccelerTempCompenCoeff2StrDis));
            ui->tableWidget_6->item(5,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X加速度计零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString XAccelerTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 XAccelerTempCompenCoeff3Int32 = qint32(XAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
//            qreal XAccelerTempCompenCoeff3 = *(float*)&XAccelerTempCompenCoeff3Int32;

            C5ValueUnion.qint32Value = qint32(XAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
            float XAccelerTempCompenCoeff3 = C5ValueUnion.floatValue;

            //QString XAccelerTempCompenCoeff3StrDis = QString("%1").arg(XAccelerTempCompenCoeff3)+"kn";
            QString XAccelerTempCompenCoeff3StrDis = QString::number(XAccelerTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(3,3,new QTableWidgetItem(XAccelerTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(3,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y加速度计零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString YAccelerTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 YAccelerTempCompenCoeff3Int32 = qint32(YAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
//            qreal YAccelerTempCompenCoeff3 = *(float*)&YAccelerTempCompenCoeff3Int32;

            C5ValueUnion.qint32Value = qint32(YAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
            float YAccelerTempCompenCoeff3 = C5ValueUnion.floatValue;

            //QString YAccelerTempCompenCoeff3StrDis = QString("%1").arg(YAccelerTempCompenCoeff3)+"kn";
            QString YAccelerTempCompenCoeff3StrDis = QString::number(YAccelerTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(4,3,new QTableWidgetItem(YAccelerTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(4,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z加速度计零偏温度3次项***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZAccelerTempCompenCoeff3Str = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
//            qint32 ZAccelerTempCompenCoeff3Int32 = qint32(ZAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
//            qreal ZAccelerTempCompenCoeff3 = *(float*)&ZAccelerTempCompenCoeff3Int32;

            C5ValueUnion.qint32Value = qint32(ZAccelerTempCompenCoeff3Str.toUInt(nullptr,16));
            float ZAccelerTempCompenCoeff3 = C5ValueUnion.floatValue;

            //QString ZAccelerTempCompenCoeff3StrDis = QString("%1").arg(ZAccelerTempCompenCoeff3)+"kn";
            QString ZAccelerTempCompenCoeff3StrDis = QString::number(ZAccelerTempCompenCoeff3,'f',4);
            ui->tableWidget_6->setItem(5,3,new QTableWidgetItem(ZAccelerTempCompenCoeff3StrDis));
            ui->tableWidget_6->item(5,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

    }

    /***********************************************发出查询命令后解析返回的数据,且有16个字节的包**************************************************/
    //等效零偏，系统姿态零位
    else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&& bufferStr.length()==976)
    {
        QString bufferStrTemp = QString(bufferStr);
        bufferStrTemp.remove(0,944);

        /***********************************************发出查询命令后解析返回的等效零偏**************************************************/
        if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == '9')
        {

            bufferStrTemp.remove(0,6);
            QString XEqZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 XEqZeroBiasInt32 = qint32(XEqZeroBiasStr.toUInt(nullptr,16));
            qreal XEqZeroBias = XEqZeroBiasInt32 * qPow(10,-6);
            //QString XEqZeroBiasStrDis = QString("%1").arg(XEqZeroBias)+"kn";
            QString XEqZeroBiasStrDis = QString::number(XEqZeroBias,'f',4);
            ui->tableWidget_2->setItem(0,4,new QTableWidgetItem(XEqZeroBiasStrDis));
            ui->tableWidget_2->item(0,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);


            /***************************************Y陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString YEqZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 YEqZeroBiasInt32 = qint32(YEqZeroBiasStr.toUInt(nullptr,16));
            qreal YEqZeroBias = YEqZeroBiasInt32 * qPow(10,-6);
            //QString YEqZeroBiasStrDis = QString("%1").arg(YEqZeroBias)+"kn";
            QString YEqZeroBiasStrDis = QString::number(YEqZeroBias,'f',4);
            ui->tableWidget_2->setItem(1,4,new QTableWidgetItem(YEqZeroBiasStrDis));
            ui->tableWidget_2->item(1,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z陀螺标度***********************************************/
            bufferStrTemp.remove(0,8);

            QString ZEqZeroBiasStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 ZEqZeroBiasInt32 = qint32(ZEqZeroBiasStr.toUInt(nullptr,16));
            qreal ZEqZeroBias = ZEqZeroBiasInt32 * qPow(10,-6);
            //QString ZEqZeroBiasStrDis = QString("%1").arg(ZEqZeroBias)+"kn";
            QString ZEqZeroBiasStrDis = QString::number(ZEqZeroBias,'f',4);
            ui->tableWidget_2->setItem(2,4,new QTableWidgetItem(ZEqZeroBiasStrDis));
            ui->tableWidget_2->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

        /***********************************************发出查询命令后解析返回的姿态零位**************************************************/
        //系统姿态零位
        else if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == 'a')
        {


            bufferStrTemp.remove(0,6);
            /***************************************系统横摇角零位***********************************************/
            QString sysRollAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 sysRollAngleInt32 = qint32(sysRollAngleStr.toUInt(nullptr,16));
            qreal sysRollAngle = sysRollAngleInt32 * 90*qPow(2,-31);
            //QString sysRollAngleStrDis = QString("%1").arg(sysRollAngle)+"kn";
            QString sysRollAngleStrDis = QString::number(sysRollAngle,'f',4);
            ui->tableWidget_7->setItem(0,0,new QTableWidgetItem(sysRollAngleStrDis));
            ui->tableWidget_7->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************系统纵摇角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString sysPitchAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 sysPitchAngleInt32 = qint32(sysPitchAngleStr.toUInt(nullptr,16));
            qreal sysPitchAngle = sysPitchAngleInt32 * 90*qPow(2,-31);
            //QString sysPitchAngleStrDis = QString("%1").arg(sysPitchAngle)+"kn";
            QString sysPitchAngleStrDis = QString::number(sysPitchAngle,'f',4);
            ui->tableWidget_7->setItem(1,0,new QTableWidgetItem(sysPitchAngleStrDis));
            ui->tableWidget_7->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************系统航向角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString sysHeadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 sysHeadingAngleInt32 = qint32(sysHeadingAngleStr.toUInt(nullptr,16));
            qreal sysHeadingAngle = sysHeadingAngleInt32 * 180*qPow(2,-31);
            //QString sysHeadingAngleStrDis = QString("%1").arg(sysHeadingAngle)+"kn";
            QString sysHeadingAngleStrDis = QString::number(sysHeadingAngle,'f',4);
            ui->tableWidget_7->setItem(2,0,new QTableWidgetItem(sysHeadingAngleStrDis));
            ui->tableWidget_7->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

    }

    /***********************************************发出查询命令后解析返回的数据,且有40个字节的包**************************************************/
    //杆臂
    else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&& bufferStr.length()==1024)
    {
        QString bufferStrTemp = QString(bufferStr);
        bufferStrTemp.remove(0,944);

        /***********************************************发出查询命令后解析返回的杆臂**************************************************/
        if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == 'c')
        {

            bufferStrTemp.remove(0,6);
            /***************************************X1GPS1***********************************************/
            QString X1GPS1Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X1GPS1Int32 = qint16(X1GPS1Str.toUInt(nullptr,16));
            qreal X1GPS1 = X1GPS1Int32 * qPow(10,-2);
            //QString X1GPS1StrDis = QString("%1").arg(X1GPS1)+"kn";
            QString X1GPS1StrDis = QString::number(X1GPS1,'f',4);
            ui->tableWidget_4->setItem(0,0,new QTableWidgetItem(X1GPS1StrDis));
            ui->tableWidget_4->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y1GPS1***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y1GPS1Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y1GPS1Int32 = qint16(Y1GPS1Str.toUInt(nullptr,16));
            qreal Y1GPS1 = Y1GPS1Int32 * qPow(10,-2);
            //QString Y1GPS1StrDis = QString("%1").arg(Y1GPS1)+"kn";
            QString Y1GPS1StrDis = QString::number(Y1GPS1,'f',4);
            ui->tableWidget_4->setItem(1,0,new QTableWidgetItem(Y1GPS1StrDis));
            ui->tableWidget_4->item(1,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z1GPS1***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z1GPS1Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z1GPS1Int32 = qint16(Z1GPS1Str.toUInt(nullptr,16));
            qreal Z1GPS1 = Z1GPS1Int32 * qPow(10,-2);
            //QString Z1GPS1StrDis = QString("%1").arg(Z1GPS1)+"kn";
            QString Z1GPS1StrDis = QString::number(Z1GPS1,'f',4);
            ui->tableWidget_4->setItem(2,0,new QTableWidgetItem(Z1GPS1StrDis));
            ui->tableWidget_4->item(2,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X2GPS2***********************************************/
            bufferStrTemp.remove(0,4);
            QString X2GPS2Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X2GPS2Int32 = qint16(X2GPS2Str.toUInt(nullptr,16));
            qreal X2GPS2 = X2GPS2Int32 * qPow(10,-2);
            //QString X2GPS2StrDis = QString("%1").arg(X2GPS2)+"kn";
            QString X2GPS2StrDis = QString::number(X2GPS2,'f',4);
            ui->tableWidget_4->setItem(0,1,new QTableWidgetItem(X2GPS2StrDis));
            ui->tableWidget_4->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y2GPS2***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y2GPS2Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y2GPS2Int32 = qint16(Y2GPS2Str.toUInt(nullptr,16));
            qreal Y2GPS2 = Y2GPS2Int32 * qPow(10,-2);
            //QString Y2GPS2StrDis = QString("%1").arg(Y2GPS2)+"kn";
            QString Y2GPS2StrDis = QString::number(Y2GPS2,'f',4);
            ui->tableWidget_4->setItem(1,1,new QTableWidgetItem(Y2GPS2StrDis));
            ui->tableWidget_4->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z2GPS2***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z2GPS2Str = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z2GPS2Int32 = qint16(Z2GPS2Str.toUInt(nullptr,16));
            qreal Z2GPS2 = Z2GPS2Int32 * qPow(10,-2);
            //QString Z2GPS2StrDis = QString("%1").arg(Z2GPS2)+"kn";
            QString Z2GPS2StrDis = QString::number(Z2GPS2,'f',4);
            ui->tableWidget_4->setItem(2,1,new QTableWidgetItem(Z2GPS2StrDis));
            ui->tableWidget_4->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X3DOPPLER***********************************************/
            bufferStrTemp.remove(0,4);
            QString X3DOPPLERStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X3DOPPLERInt32 = qint16(X3DOPPLERStr.toUInt(nullptr,16));
            qreal X3DOPPLER = X3DOPPLERInt32 * qPow(10,-2);
            //QString X3DOPPLERStrDis = QString("%1").arg(X3DOPPLER)+"kn";
            QString X3DOPPLERStrDis = QString::number(X3DOPPLER,'f',4);
            ui->tableWidget_4->setItem(0,2,new QTableWidgetItem(X3DOPPLERStrDis));
            ui->tableWidget_4->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y3DOPPLER***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y3DOPPLERStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y3DOPPLERInt32 = qint16(Y3DOPPLERStr.toUInt(nullptr,16));
            qreal Y3DOPPLER = Y3DOPPLERInt32 * qPow(10,-2);
            //QString Y3DOPPLERStrDis = QString("%1").arg(Y3DOPPLER)+"kn";
            QString Y3DOPPLERStrDis = QString::number(Y3DOPPLER,'f',4);
            ui->tableWidget_4->setItem(1,2,new QTableWidgetItem(Y3DOPPLERStrDis));
            ui->tableWidget_4->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z3DOPPLER***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z3DOPPLERStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z3DOPPLERInt32 = qint16(Z3DOPPLERStr.toUInt(nullptr,16));
            qreal Z3DOPPLER = Z3DOPPLERInt32 * qPow(10,-2);
            //QString Z3DOPPLERStrDis = QString("%1").arg(Z3DOPPLER)+"kn";
            QString Z3DOPPLERStrDis = QString::number(Z3DOPPLER,'f',4);
            ui->tableWidget_4->setItem(2,2,new QTableWidgetItem(Z3DOPPLERStrDis));
            ui->tableWidget_4->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X4LOG_EM*******************************************/
            bufferStrTemp.remove(0,4);
            QString X4LOG_EMStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X4LOG_EMInt32 = qint16(X4LOG_EMStr.toUInt(nullptr,16));
            qreal X4LOG_EM = X4LOG_EMInt32 * qPow(10,-2);
            //QString X4LOG_EMStrDis = QString("%1").arg(X4LOG_EM)+"kn";
            QString X4LOG_EMStrDis = QString::number(X4LOG_EM,'f',4);
            ui->tableWidget_4->setItem(0,3,new QTableWidgetItem(X4LOG_EMStrDis));
            ui->tableWidget_4->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y4LOG_EM***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y4LOG_EMStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y4LOG_EMInt32 = qint16(Y4LOG_EMStr.toUInt(nullptr,16));
            qreal Y4LOG_EM = Y4LOG_EMInt32 * qPow(10,-2);
            //QString Y4LOG_EMStrDis = QString("%1").arg(Y4LOG_EM)+"kn";
            QString Y4LOG_EMStrDis = QString::number(Y4LOG_EM,'f',4);
            ui->tableWidget_4->setItem(1,3,new QTableWidgetItem(Y4LOG_EMStrDis));
            ui->tableWidget_4->item(1,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z4LOG_EM***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z4LOG_EMStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z4LOG_EMInt32 = qint16(Z4LOG_EMStr.toUInt(nullptr,16));
            qreal Z4LOG_EM = Z4LOG_EMInt32 * qPow(10,-2);
            //QString Z4LOG_EMStrDis = QString("%1").arg(Z4LOG_EM)+"kn";
            QString Z4LOG_EMStrDis = QString::number(Z4LOG_EM,'f',4);
            ui->tableWidget_4->setItem(2,3,new QTableWidgetItem(Z4LOG_EMStrDis));
            ui->tableWidget_4->item(2,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X5MAIN_INS*******************************************/
            bufferStrTemp.remove(0,4);
            QString X5MAIN_INSStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X5MAIN_INSInt32 = qint16(X5MAIN_INSStr.toUInt(nullptr,16));
            qreal X5MAIN_INS = X5MAIN_INSInt32 * qPow(10,-2);
            //QString X5MAIN_INSStrDis = QString("%1").arg(X5MAIN_INS)+"kn";
            QString X5MAIN_INSStrDis = QString::number(X5MAIN_INS,'f',4);
            ui->tableWidget_4->setItem(0,4,new QTableWidgetItem(X5MAIN_INSStrDis));
            ui->tableWidget_4->item(0,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y5MAIN_INS***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y5MAIN_INSStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y5MAIN_INSInt32 = qint16(Y5MAIN_INSStr.toUInt(nullptr,16));
            qreal Y5MAIN_INS = Y5MAIN_INSInt32 * qPow(10,-2);
            //QString Y5MAIN_INSStrDis = QString("%1").arg(Y5MAIN_INS)+"kn";
            QString Y5MAIN_INSStrDis = QString::number(Y5MAIN_INS,'f',4);
            ui->tableWidget_4->setItem(1,4,new QTableWidgetItem(Y5MAIN_INSStrDis));
            ui->tableWidget_4->item(1,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z5MAIN_INS***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z5MAIN_INSStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z5MAIN_INSInt32 = qint16(Z5MAIN_INSStr.toUInt(nullptr,16));
            qreal Z5MAIN_INS = Z5MAIN_INSInt32 * qPow(10,-2);
            //QString Z5MAIN_INSStrDis = QString("%1").arg(Z5MAIN_INS)+"kn";
            QString Z5MAIN_INSStrDis = QString::number(Z5MAIN_INS,'f',4);
            ui->tableWidget_4->setItem(2,4,new QTableWidgetItem(Z5MAIN_INSStrDis));
            ui->tableWidget_4->item(2,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************X6ACC*******************************************/
            bufferStrTemp.remove(0,4);
            QString X6ACCStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 X6ACCInt32 = qint16(X6ACCStr.toUInt(nullptr,16));
            qreal X6ACC = X6ACCInt32 * qPow(10,-2);
            //QString X6ACCStrDis = QString("%1").arg(X6ACC)+"kn";
            QString X6ACCStrDis = QString::number(X6ACC,'f',4);
            ui->tableWidget_4->setItem(0,5,new QTableWidgetItem(X6ACCStrDis));
            ui->tableWidget_4->item(0,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Y6ACC***********************************************/
            bufferStrTemp.remove(0,4);
            QString Y6ACCStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Y6ACCInt32 = qint16(Y6ACCStr.toUInt(nullptr,16));
            qreal Y6ACC = Y6ACCInt32 * qPow(10,-2);
            //QString Y6ACCStrDis = QString("%1").arg(Y6ACC)+"kn";
            QString Y6ACCStrDis = QString::number(Y6ACC,'f',4);
            ui->tableWidget_4->setItem(1,5,new QTableWidgetItem(Y6ACCStrDis));
            ui->tableWidget_4->item(1,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************Z6ACC***********************************************/
            bufferStrTemp.remove(0,4);
            QString Z6ACCStr = bufferStrTemp.left(4).mid(2,2)+bufferStrTemp.left(4).mid(0,2);
            qint16 Z6ACCInt32 = qint16(Z6ACCStr.toUInt(nullptr,16));
            qreal Z6ACC = Z6ACCInt32 * qPow(10,-2);
            //QString Z6ACCStrDis = QString("%1").arg(Z6ACC)+"kn";
            QString Z6ACCStrDis = QString::number(Z6ACC,'f',4);
            ui->tableWidget_4->setItem(2,5,new QTableWidgetItem(Z6ACCStrDis));
            ui->tableWidget_4->item(2,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

    }

    /***********************************************发出查询命令后解析返回的数据,且有16个字节的包**************************************************/
    //惯组姿态零位与输出姿态零位
    else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&& bufferStr.length()==1000)
    {
        QString bufferStrTemp = QString(bufferStr);
        bufferStrTemp.remove(0,944);

        /***********************************************发出查询命令后解析返回的姿态零位**************************************************/
        if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == 'b')
        {


            bufferStrTemp.remove(0,6);
            /***************************************惯组横摇角零位***********************************************/
            QString IMUrollAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 IMUrollAngleInt32 = qint32(IMUrollAngleStr.toUInt(nullptr,16));
            qreal IMUrollAngle = IMUrollAngleInt32 * 90*qPow(2,-31);
            //QString IMUrollAngleStrDis = QString("%1").arg(IMUrollAngle)+"kn";
            QString IMUrollAngleStrDis = QString::number(IMUrollAngle,'f',4);
            ui->tableWidget_7->setItem(0,1,new QTableWidgetItem(IMUrollAngleStrDis));
            ui->tableWidget_7->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************惯组纵摇角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString IMUpitchAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 IMUpitchAngleInt32 = qint32(IMUpitchAngleStr.toUInt(nullptr,16));
            qreal IMUpitchAngle = IMUpitchAngleInt32 * 90*qPow(2,-31);
            //QString IMUpitchAngleStrDis = QString("%1").arg(IMUpitchAngle)+"kn";
            QString IMUpitchAngleStrDis = QString::number(IMUpitchAngle,'f',4);
            ui->tableWidget_7->setItem(1,1,new QTableWidgetItem(IMUpitchAngleStrDis));
            ui->tableWidget_7->item(1,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************惯组航向角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString IMUheadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 IMUheadingAngleInt32 = qint32(IMUheadingAngleStr.toUInt(nullptr,16));
            qreal IMUheadingAngle = IMUheadingAngleInt32 * 180*qPow(2,-31);
            //QString IMUheadingAngleStrDis = QString("%1").arg(IMUheadingAngle)+"kn";
            QString IMUheadingAngleStrDis = QString::number(IMUheadingAngle,'f',4);
            ui->tableWidget_7->setItem(2,1,new QTableWidgetItem(IMUheadingAngleStrDis));
            ui->tableWidget_7->item(2,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************输出横摇角零位***********************************************/
            QString outputRollAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 outputRollAngleInt32 = qint32(outputRollAngleStr.toUInt(nullptr,16));
            qreal outputRollAngle = outputRollAngleInt32 * 90*qPow(2,-31);
            //QString outputRollAngleStrDis = QString("%1").arg(outputRollAngle)+"kn";
            QString outputRollAngleStrDis = QString::number(outputRollAngle,'f',4);
            ui->tableWidget_7->setItem(0,2,new QTableWidgetItem(outputRollAngleStrDis));
            ui->tableWidget_7->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************输出纵摇角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString outputPitchAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 outputPitchAngleInt32 = qint32(outputPitchAngleStr.toUInt(nullptr,16));
            qreal outputPitchAngle = outputPitchAngleInt32 * 90*qPow(2,-31);
            //QString outputPitchAngleStrDis = QString("%1").arg(outputPitchAngle)+"kn";
            QString outputPitchAngleStrDis = QString::number(outputPitchAngle,'f',4);
            ui->tableWidget_7->setItem(1,2,new QTableWidgetItem(outputPitchAngleStrDis));
            ui->tableWidget_7->item(1,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************输出航向角零位***********************************************/
            bufferStrTemp.remove(0,8);
            QString outputHeadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 outputHeadingAngleInt32 = qint32(outputHeadingAngleStr.toUInt(nullptr,16));
            qreal outputHeadingAngle = outputHeadingAngleInt32 * 180*qPow(2,-31);
            //QString outputHeadingAngleStrDis = QString("%1").arg(outputHeadingAngle)+"kn";
            QString outputHeadingAngleStrDis = QString::number(outputHeadingAngle,'f',4);
            ui->tableWidget_7->setItem(2,2,new QTableWidgetItem(outputHeadingAngleStrDis));
            ui->tableWidget_7->item(2,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }
    }

    /***********************************************发出查询命令后解析返回的数据,且有12个字节的包**************************************************/
    //初始位置
    else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&& bufferStr.length()==968)
    {
        QString bufferStrTemp = QString(bufferStr);
        bufferStrTemp.remove(0,944);

        /***********************************************发出查询命令后解析返回的初始位置**************************************************/
        if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == '1')
        {

            bufferStrTemp.remove(0,6);
            /***************************************初始纬度***********************************************/
            QString OriLatStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 OriLatInt32 = qint32(OriLatStr.toUInt(nullptr,16));
            qreal OriLat = OriLatInt32 * 90*qPow(2,-31);
            //QString OriLatStrDis = QString("%1").arg(OriLat)+"kn";
            QString OriLatStrDis = QString::number(OriLat,'f',4);
            ui->tableWidget_8->setItem(0,0,new QTableWidgetItem(OriLatStrDis));
            ui->tableWidget_8->item(0,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            /***************************************初始经度***********************************************/
            bufferStrTemp.remove(0,8);
            QString OrilonStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            qint32 OrilonInt32 = qint32(OrilonStr.toUInt(nullptr,16));
            qreal Orilon = OrilonInt32 * 180*qPow(2,-31);
            //QString OrilonStrDis = QString("%1").arg(Orilon)+"kn";
            QString OrilonStrDis = QString::number(Orilon,'f',4);
            ui->tableWidget_8->setItem(0,1,new QTableWidgetItem(OrilonStrDis));
            ui->tableWidget_8->item(0,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
    }

    /***********************************************发出查询命令后解析返回的数据,且有8个字节的包**************************************************/
    //初始航向或者初始速度
    else if(bufferStr[0] == 'e' && bufferStr[1] == 'b'&&bufferStr[2] == '9' && bufferStr[3] == '0'&& bufferStr.length()==960)
    {
        QString bufferStrTemp = QString(bufferStr);
        bufferStrTemp.remove(0,944);

        /***********************************************发出查询命令后解析返回的初始航向**************************************************/
        if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == '2')
        {

            bufferStrTemp.remove(0,6);
            /***************************************初始航向***********************************************/
            QString OriheadingAngleStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            quint32 OriheadingAngleInt32 = quint32(OriheadingAngleStr.toUInt(nullptr,16));
            qreal OriheadingAngle = OriheadingAngleInt32 * 360*qPow(2,-32);
            //QString OriheadingAngleStrDis = QString("%1").arg(OriheadingAngle)+"kn";
            QString OriheadingAngleStrDis = QString::number(OriheadingAngle,'f',4);
            ui->tableWidget_8->setItem(0,2,new QTableWidgetItem(OriheadingAngleStrDis));
            ui->tableWidget_8->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
        else if(bufferStrTemp[4] == '0' && bufferStrTemp[5] == '3')
        {

            bufferStrTemp.remove(0,6);
            /***************************************初始速度***********************************************/
            QString OriSpeedStr = bufferStrTemp.left(8).mid(6,2)+bufferStrTemp.left(8).mid(4,2)+bufferStrTemp.left(8).mid(2,2)+bufferStrTemp.left(8).mid(0,2);
            quint32 OriSpeedInt32 = quint32(OriSpeedStr.toUInt(nullptr,16));
            qreal OriSpeed = OriSpeedInt32 * 1000*qPow(2,-32);
            //QString OriSpeedStrDis = QString("%1").arg(OriSpeed)+"kn";
            QString OriSpeedStrDis = QString::number(OriSpeed,'f',4);
            ui->tableWidget_8->setItem(0,3,new QTableWidgetItem(OriSpeedStrDis));
            ui->tableWidget_8->item(0,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        }

    }


    /******************************************调试信息，打印报文*******************************************/
    if(ui->action->isChecked() == true)
    {
        if(datanum < 10)
        {
            QString displayStr = dateStr+"\n"+QString(result).toUpper()+"\n";

            //从界面中读取以前收到的数据
            QString oldString = ui->browser_dataReceive->toPlainText();
            oldString = oldString + QString(displayStr);
            //清空以前的显示
            ui->browser_dataReceive->clear();
            //重新显示
            ui->browser_dataReceive->append(oldString);
            datanum++;
        }
        else
        {
            ui->browser_dataReceive->clear();
             QString displayStr = dateStr+"\n"+QString(result).toUpper()+"\n";
             ui->browser_dataReceive->append(displayStr);
             datanum = 0;
        }
    }



//    //qDebug() <<  "主线程收到结果数据：" << bufferStr << "线程ID：" << QThread::currentThreadId();
    result.clear();

}

#ifdef QEXTSERIALPORT
//第三方库
void MainWindow::on_btn_openPort_clicked()
{

    if(ui->btn_openPort->text()==QString("打开串口"))
    {


        //设置串口名
        QString portName = (ui->box_portName->currentText()).split(":").at(0);
         serial_1 = new QextSerialPort(portName);
        //qDebug() << portName;
        //serial_1->setPortName(portName);
        if(serial_1->open(QIODevice::ReadWrite))
        {
            if(1)
            {
                fileSaveNum = 1;
                QString fileSaveNumStr = QString::number(fileSaveNum,10);
                QDateTime current_date_time =QDateTime::currentDateTime();
                QString dateStr =current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
                QString C1HisDataName = "./history/nav1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C2HisDataName = "./history/cond1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C3HisDataName = "./history/ref1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
                QString C5HisDataName = "./history/imu1s_"+ dateStr+"_"+fileSaveNumStr+".csv";

                 C1fileSave.setFileName(C1HisDataName);
                if(!C1fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C1文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC1(&C1fileSave);
                QString headStr1 = "时间序号,标识号,系统时间,状态时间,纬度°,经度°,东速kn,北速kn,航向角°,横摇角°,纵摇角°,航向角速度°/s,横摇角速度°/s,纵摇角速度°/s,垂荡m,垂速m/s,横荡m,横速m/s,纵荡m,纵速m/s,时码有效,经纬度有效,东北速有效,航向有效,纵横摇有效,角速度有效,升沉有效,纵横荡有效,导航状态,工作位置,切换模式,时码,参考纬度°,参考经度°,参考组合东速kn,参考组合北速kn,参考阻尼东速kn,参考阻尼北速kn,参考航向°,参考经纬度,参考组合速度,参考阻尼,参考航向";
                dataOutC1<<headStr1.toUtf8();

                C2fileSave.setFileName(C2HisDataName);
                if(!C2fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C2文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC2(&C2fileSave);
                QString headStr2 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到陀螺标定参数,收到加速度计标定参数,收到陀螺零偏温补系数,收到加速度计零位温补系数,收到装订航向,收到等效零偏,收到漂移补偿,收到状态切换命令,收到系统姿态零位,收到惯组和输出姿态零位,收到杆臂,收到显控参考信息,收到1PPS信号,收到录取同步信号,收到主惯导信息,收到系统编号,收到在舰位置,收到IP地址,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GX漂移估计补偿,GY漂移估计补偿,GZ漂移估计补偿,AX零偏估计补偿,AY零偏估计补偿,AZ零偏估计补偿,水平姿态误差估计补偿,航向误差估计补偿,速度误差估计补偿,位置误差估计补偿,直航状态,静止状态,锚泊状态,振动状态,冲击状态,主惯导位置有效,主惯导速度有效,主惯导姿态有效,主惯导角速度有效,陀螺故障,加速度计故障,IF板故障,采集板故障,通信板故障,接口板故障,解算异常故障,备用电源故障,GX陀螺常值漂移°/h,GY陀螺常值漂移°/h,GZ陀螺常值漂移°/h,AX加速度计零偏mg,AY加速度计零偏mg,AZ加速度计零偏mg";
                dataOutC2<<headStr2.toUtf8();

                 C3fileSave.setFileName(C3HisDataName);
                if(!C3fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C3文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC3(&C3fileSave);
                QString headStr3 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到1PPS信号,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GPS纬度°,GPS经度°,GPS合速kn,GPS航向°,GPS东速kn,GPS北速kn,电磁速度kn,多普勒对水横向速度kn,多普勒对水纵向速度kn,多普勒对底横向速度kn,多普勒对底纵向速度kn,时码：日月年,时码：天秒s,插值时间us,GPS卫星数,GPS水平精度因子";
                dataOutC3<<headStr3.toUtf8();

                 C5fileSave.setFileName(C5HisDataName);
                if(!C5fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
                {
                    //无法打开要写入的文件
                    QMessageBox::warning(this, tr("打开写入文件"),
                                         tr("打开要写入的C5文件失败，请检查文件名和是否具有写入权限！"));
                    return;
                }
                QTextStream dataOutC5(&C5fileSave);
                QString headStr5 = "时间序号,标识号,系统时间,X陀螺1s角增量°/h,Y陀螺1s角增量°/h,Z陀螺1s角增量°/h,X加速度计1s速度增量m/s/s,Y加速度计1s速度增量m/s/s,Z加速度计1s速度增量m/s/s,X陀螺1s补偿后角增量°/h,Y陀螺1s补偿后角增量°/h,Z陀螺1s补偿后角增量°/h,X加速度计1s补偿后速度增量m/s/s,Y加速度计1s补偿后速度增量m/s/s,Z加速度计1s补偿后速度增量m/s/s,X陀螺差频p/s,Y陀螺差频p/s,Z陀螺差频p/s,X加速度计差频p/s,Y加速度计差频p/s,Z加速度计差频p/s,X陀螺抖幅p/s,Y陀螺抖幅p/s,Z陀螺抖幅p/s,X陀螺抖频Hz,Y陀螺抖频Hz,Z陀螺抖频Hz,X陀螺温度1°C,X陀螺温度2°C,Y陀螺温度1°C,Y陀螺温度2°C,Z陀螺温度1°C,Z陀螺温度2°C,IF板温度°C,X加速度计温度°C,Y加速度计温度°C,Z加速度计温度°C,采集板温度°C";
                dataOutC5<<headStr5.toUtf8();
            }

            //清空缓冲区
            serial_1->flush();
            //设置波特率
            serial_1->setBaudRate((BaudRateType)ui->box_baudrate->currentText().toInt());

            //设置停止位
            if(ui->box_stopBit->currentText() == "1")
                serial_1->setStopBits(STOP_1);
            else if(ui->box_stopBit->currentText() == "1.5")
                serial_1->setStopBits(STOP_1_5);
            else if(ui->box_stopBit->currentText() == "2")
                serial_1->setStopBits(STOP_2);

            //设置数据位数
            if(ui->box_dataBits->currentText() == "8")
                serial_1->setDataBits(DATA_8);
            else if(ui->box_dataBits->currentText() == "7")
                serial_1->setDataBits(DATA_7);
            else if(ui->box_dataBits->currentText() == "6")
                serial_1->setDataBits(DATA_6);
            else if(ui->box_dataBits->currentText() == "5")
                serial_1->setDataBits(DATA_5);

            //设置奇偶校验
            if(ui->box_parityBit->currentText() == "None")
                serial_1->setParity(PAR_NONE);
            else if(ui->box_parityBit->currentText() == "Even")
                serial_1->setParity(PAR_EVEN);
            else if(ui->box_parityBit->currentText() == "Odd")
                serial_1->setParity(PAR_ODD);

            //设置流控制
            serial_1->setFlowControl(FLOW_OFF);

            //下拉菜单控件失能
            ui->box_portName->setEnabled(false);
            ui->box_baudrate->setEnabled(false);
            ui->box_dataBits->setEnabled(false);
            ui->box_parityBit->setEnabled(false);
            ui->box_stopBit->setEnabled(false);

            ui->btn_openPort->setText(QString("关闭串口"));

            this->setLED1(ui->label_69,2,15);
            serial_1->setTimeout(10);
            qtime->start();
            qGetdataTime->start();
            qDrawTime->start();

        }
        else
        {
            QMessageBox::about(NULL, "提示", "无法打开串口！");
            return;
        }
    }
    else
    {

        //关闭串口
        serial_1->close();
        //InitClear();
        C1fileSave.close();
        C2fileSave.close();
        C3fileSave.close();
        C5fileSave.close();

        this->setLED1(ui->label_69,1,15);
        //下拉菜单控件使能
        ui->box_portName->setEnabled(true);
        ui->box_baudrate->setEnabled(true);
        ui->box_dataBits->setEnabled(true);
        ui->box_parityBit->setEnabled(true);
        ui->box_stopBit->setEnabled(true);
        qGetdataTime->stop();
        qDrawTime->stop();
        //InitClear();

        qtime->stop();
        ui->btn_openPort->setText(QString("打开串口"));
//        delete serial_1;
//        serial_1 = NULL;
        //发送按键失能
        //ui->btn_send->setEnabled(false);
    }
}
#endif

#ifdef SERIALPORT
void MainWindow::on_btn_openPort_clicked()
{
    if(ui->btn_openPort->text()==QString("打开串口"))
        {
        fileSaveNum = 1;
        QString fileSaveNumStr = QString::number(fileSaveNum,10);
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString dateStr =current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
        QString C1HisDataName = "./history/nav1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
        QString C2HisDataName = "./history/cond1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
        QString C3HisDataName = "./history/ref1s_"+ dateStr+"_"+fileSaveNumStr+".csv";
        QString C5HisDataName = "./history/imu1s_"+ dateStr+"_"+fileSaveNumStr+".csv";

         C1fileSave.setFileName(C1HisDataName);
        if(!C1fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的C1文件失败，请检查文件名和是否具有写入权限！"));
            return;
        }
        QTextStream dataOutC1(&C1fileSave);
        QString headStr1 = "时间序号,标识号,系统时间,状态时间,纬度,经度,东速,北速,航向角,横摇角,纵摇角,航向角速度,横摇角速度,纵摇角速度,垂荡,垂速,横荡,横速,纵荡,纵速,时码有效,经纬度有效,东北速有效,航向有效,纵横摇有效,角速度有效,升沉有效,纵横荡有效,导航状态,工作位置,切换模式,时码,参考纬度,参考经度,参考组合东速,参考组合北速,参考阻尼东速,参考阻尼北速,参考航向,参考经纬度,参考组合速度,参考阻尼,参考航向";
        dataOutC1<<headStr1.toUtf8();

        C2fileSave.setFileName(C2HisDataName);
        if(!C2fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的C2文件失败，请检查文件名和是否具有写入权限！"));
            return;
        }
        QTextStream dataOutC2(&C2fileSave);
        QString headStr2 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到陀螺标定参数,收到加速度计标定参数,收到陀螺零偏温补系数,收到加速度计零位温补系数,收到装订航向,收到等效零偏,收到漂移补偿,收到状态切换命令,收到系统姿态零位,收到惯组和输出姿态零位,收到杆臂,收到显控参考信息,收到1PPS信号,收到录取同步信号,收到主惯导信息,收到系统编号,收到在舰位置,收到IP地址,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GX漂移估计补偿,GY漂移估计补偿,GZ漂移估计补偿,AX零偏估计补偿,AY零偏估计补偿,AZ零偏估计补偿,水平姿态误差估计补偿,航向误差估计补偿,速度误差估计补偿,位置误差估计补偿,直航状态,静止状态,锚泊状态,振动状态,冲击状态,主惯导位置有效,主惯导速度有效,主惯导姿态有效,主惯导角速度有效,陀螺故障,加速度计故障,IF板故障,采集板故障,通信板故障,接口板故障,解算异常故障,备用电源故障,GX陀螺常值漂移,GY陀螺常值漂移,GZ陀螺常值漂移,AX加速度计零偏,AY加速度计零偏,AZ加速度计零偏";
        dataOutC2<<headStr2.toUtf8();

         C3fileSave.setFileName(C3HisDataName);
        if(!C3fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的C3文件失败，请检查文件名和是否具有写入权限！"));
            return;
        }
        QTextStream dataOutC3(&C3fileSave);
        QString headStr3 = "时间序号,标识号,系统时间,收到装订位置,收到GPS位置,收到装订速度,收到GPS速度,收到电磁计程仪速度,收到多普勒计程仪速度,收到时码,收到1PPS信号,装订位置有效,GPS位置有效,装订速度有效,GPS速度有效,电磁速度有效,多普勒对水有效,多普勒对底有效,时码有效,GPS纬度,GPS经度,GPS合速,GPS航向,GPS东速,GPS北速,电磁速度,多普勒对水横向速度,多普勒对水纵向速度,多普勒对底横向速度,多普勒对底纵向速度,时码：日月年,时码：天秒,插值时间,GPS卫星数,GPS水平精度因子";
        dataOutC3<<headStr3.toUtf8();

         C5fileSave.setFileName(C5HisDataName);
        if(!C5fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的C5文件失败，请检查文件名和是否具有写入权限！"));
            return;
        }
        QTextStream dataOutC5(&C5fileSave);
        QString headStr5 = "时间序号,标识号,系统时间,X陀螺1s角增量,Y陀螺1s角增量,Z陀螺1s角增量,X加速度计1s速度增量,Y加速度计1s速度增量,Z加速度计1s速度增量,X陀螺1s补偿后角增量,Y陀螺1s补偿后角增量,Z陀螺1s补偿后角增量,X加速度计1s补偿后速度增量,Y加速度计1s补偿后速度增量,Z加速度计1s补偿后速度增量,X陀螺差频,Y陀螺差频,Z陀螺差频,X加速度计差频,Y加速度计差频,Z加速度计差频,X陀螺抖幅,Y陀螺抖幅,Z陀螺抖幅,X陀螺抖频,Y陀螺抖频,Z陀螺抖频,X陀螺温度1,X陀螺温度2,Y陀螺温度1,Y陀螺温度2,Z陀螺温度1,Z陀螺温度2,IF板温度,X加速度计温度,Y加速度计温度,Z加速度计温度,采集板温度";
        dataOutC5<<headStr5.toUtf8();

            //设置串口名
            QString portName = (ui->box_portName->currentText()).split(":").at(0);
            //qDebug() << portName;
            serial_1.setPortName(portName);
            //设置波特率
            serial_1.setBaudRate(ui->box_baudrate->currentText().toInt());
            //设置停止位
            if(ui->box_stopBit->currentText() == "1")
                serial_1.setStopBits(QSerialPort::OneStop);
            else if(ui->box_stopBit->currentText() == "1.5")
                serial_1.setStopBits(QSerialPort::OneAndHalfStop);
            else if(ui->box_stopBit->currentText() == "2")
                serial_1.setStopBits(QSerialPort::TwoStop);
            //设置数据位数
            if(ui->box_dataBits->currentText() == "8")
                serial_1.setDataBits(QSerialPort::Data8);
            else if(ui->box_dataBits->currentText() == "7")
                serial_1.setDataBits(QSerialPort::Data7);
            else if(ui->box_dataBits->currentText() == "6")
                serial_1.setDataBits(QSerialPort::Data6);
            else if(ui->box_dataBits->currentText() == "5")
                serial_1.setDataBits(QSerialPort::Data5);
            //设置奇偶校验
            if(ui->box_parityBit->currentText() == "None")
                serial_1.setParity(QSerialPort::NoParity);
            else if(ui->box_parityBit->currentText() == "Even")
                serial_1.setParity(QSerialPort::EvenParity);
            else if(ui->box_parityBit->currentText() == "Odd")
                serial_1.setParity(QSerialPort::OddParity);
            //设置流控制
            serial_1.setFlowControl(QSerialPort::NoFlowControl);
            //打开串口
            if(!serial_1.open(QIODevice::ReadWrite))
            {
                QMessageBox::about(NULL, "提示", "无法打开串口！");
                return;
            }
            //下拉菜单控件失能
            ui->box_portName->setEnabled(false);
            ui->box_baudrate->setEnabled(false);
            ui->box_dataBits->setEnabled(false);
            ui->box_parityBit->setEnabled(false);
            ui->box_stopBit->setEnabled(false);
            ui->btn_openPort->setText(QString("关闭串口"));

            this->setLED1(ui->label_69,2,15);
            qGetdataTime->start(addDataPeri);
            qDrawTim->start(drawDataPeri);
            //发送按键使能
            //ui->btn_send->setEnabled(true);
        }
        else
        {
            //关闭串口
            serial_1.close();
            C1fileSave.close();
            C2fileSave.close();
            C3fileSave.close();
            C5fileSave.close();
            this->setLED1(ui->label_69,1,15);
            //下拉菜单控件使能
            ui->box_portName->setEnabled(true);
            ui->box_baudrate->setEnabled(true);
            ui->box_dataBits->setEnabled(true);
            ui->box_parityBit->setEnabled(true);
            ui->box_stopBit->setEnabled(true);
            InitClear();
            qGetdataTime->stop();
            qDrawTime->stop();
            qtime->stop();
            ui->btn_openPort->setText(QString("打开串口"));
            //发送按键失能
            //ui->btn_send->setEnabled(false);
        }
}
#endif
/*
 * @breif 串口开始前界面数据清零
 */
void MainWindow::InitClear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_30->clear();
    ui->lineEdit_24->clear();
    ui->lineEdit_25->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_28->clear();
    ui->lineEdit_27->clear();
    ui->lineEdit_29->clear();
    ui->lineEdit_31->clear();
    ui->lineEdit_32->clear();
    ui->lineEdit_33->clear();
    ui->lineEdit_34->clear();
    ui->lineEdit_35->clear();
    ui->lineEdit_36->clear();
    ui->lineEdit_37->clear();
    ui->lineEdit_38->clear();
    ui->lineEdit_39->clear();
    ui->lineEdit_40->clear();
    ui->lineEdit_41->clear();
    ui->lineEdit_42->clear();
    ui->lineEdit_43->clear();
    ui->lineEdit_44->clear();
    ui->lineEdit_49->clear();

    latitude=0;
    headingAngle=0;
    longitude=0;
    rollAngle=0;
    pitchAngle=0;
    northSpeed=0;
    eastSpeed=0;
    headingAngularSpeed=0;
    rollAngleSpeed=0;
    pitchAngleSpeed=0;
    heave=0;
    verticalVelocity=0;
    sway=0;
    transverseVelocity=0;
    surge=0;
    longitudinalVelocity=0;
    C5XGyroAngleIncreaseFloat=0;
    C5YGyroAngleIncreaseFloat=0;
    C5ZGyroAngleIncreaseFloat=0;
    C5XAccelerometerSpeedIncrementFloat=0;
    C5YAccelerometerSpeedIncrementFloat=0;
    C5ZAccelerometerSpeedIncrementFloat=0;
    C5XgyroCompensatedAngleIncrementFloat=0;
    C5YgyroCompensatedAngleIncrementFloat=0;
    C5ZgyroCompensatedAngleIncrementFloat=0;
    C5XAccVelocityIncrementFloat=0;
    C5YAccVelocityIncrementFloat=0;
    C5ZAccVelocityIncrementFloat=0;
    C5XgyroDifFrequency=0;
    C5YgyroDifFrequency=0;
    C5ZgyroDifFrequency=0;
    C5XaccelerometerDifFre=0;
    C5YaccelerometerDifFre=0;
    C5ZaccelerometerDifFre=0;
    C5XgyroTemp1=0;
    C5YgyroTemp1=0;
    C5ZgyroTemp1=0;
    C5XAccelerometerTemperture=0;
    C5YAccelerometerTemperture=0;
    C5ZAccelerometerTemperture=0;
    C5XgyroTemp2=0;
    C5YgyroTemp2=0;
    C5ZgyroTemp2=0;
    C5XgyroAmplitudeJitter=0;
    C5YgyroAmplitudeJitter=0;
    C5ZgyroAmplitudeJitter=0;
    C5XgyroAmpl1itudeFre=0;
    C5YgyroAmpl1itudeFre=0;
    C5ZgyroAmpl1itudeFre=0;
    C3longitude=0;
    C3GPSlatitude=0;
    C3togetherSpeed=0;
    C3headingAngle=0;
    C3combinedEastSpeed=0;
    C3combinedNorthSpeed=0;
    C3waterX=0;
    C3waterY=0;
    C3bottomX=0;
    C3bottomY=0;
    C3electromagnetismSpeed=0;
    C6XGroyFloat=0;
    C6YGroyFloat=0;
    C6ZGroyFloat=0;
    C6XAccelerometerFloat=0;
    C6YAccelerometerFloat=0;
    C6ZAccelerometerFloat=0;
    eastSpeedError=0;
    northSpeedError=0;
    togetherSpeedError=0;
    latitudeError=0;
    longitudeError=0;
    positionError=0;
    QVector<double> a;
    m_xLength = 0;
    //C1Vlongitude_bk.swap(a);
    QVector<double>().swap(C1Vlongitude);
    QVector<double>().swap(C1Vlongitude_bk);

    QVector<double>().swap(curveX);
    QVector<double>().swap(C1Vlatitude);
    QVector<double>().swap(C1Vlatitude_bk);
    QVector<double>().swap(C1VheadingAngle);
    QVector<double>().swap(C1VheadingAngle_bk);
    QVector<double>().swap(C1VrollAngle);
    QVector<double>().swap(C1VrollAngle_bk);
    QVector<double>().swap(C1VpitchAngle);
    QVector<double>().swap(C1VpitchAngle_bk);
    QVector<double>().swap(C1VnorthSpeed);
    QVector<double>().swap(C1VnorthSpeed_bk);

    QVector<double>().swap(C1VeastSpeed);
    QVector<double>().swap(C1VeastSpeed_bk);
    QVector<double>().swap(C1VrollAngleSpeed);
    QVector<double>().swap(C1VrollAngleSpeed_bk);
    QVector<double>().swap(C1VpitchAngleSpeed);
    QVector<double>().swap(C1VpitchAngleSpeed_bk);
    QVector<double>().swap(C1Vheave);
    QVector<double>().swap(C1Vheave_bk);
    QVector<double>().swap(C1VverticalVelocity);
    QVector<double>().swap(C1VverticalVelocity_bk);
    QVector<double>().swap(C1VheadingAngularSpeed);
    QVector<double>().swap(C1VheadingAngularSpeed_bk);

    QVector<double>().swap(C1Vsway);
    QVector<double>().swap(C1Vsway_bk);
    QVector<double>().swap(C1VtransverseVelocity);
    QVector<double>().swap(C1VtransverseVelocity_bk);
    QVector<double>().swap(C1Vsurge);
    QVector<double>().swap(C1Vsurge_bk);
    QVector<double>().swap(C1VlongitudinalVelocity);
    QVector<double>().swap(C1VlongitudinalVelocity_bk);
    QVector<double>().swap(C5VXGyroAngleIncreaseFloat);
    QVector<double>().swap(C5VXGyroAngleIncreaseFloat_bk);
    QVector<double>().swap(C5VYGyroAngleIncreaseFloat);
    QVector<double>().swap(C5VYGyroAngleIncreaseFloat_bk);

    QVector<double>().swap(C5VZGyroAngleIncreaseFloat);
    QVector<double>().swap(C5VZGyroAngleIncreaseFloat_bk);
    QVector<double>().swap(C5VXAccelerometerSpeedIncrementFloat);
    QVector<double>().swap(C5VXAccelerometerSpeedIncrementFloat_bk);
    QVector<double>().swap(C5VYAccelerometerSpeedIncrementFloat);
    QVector<double>().swap(C5VYAccelerometerSpeedIncrementFloat_bk);
    QVector<double>().swap(C5VZAccelerometerSpeedIncrementFloat);
    QVector<double>().swap(C5VZAccelerometerSpeedIncrementFloat_bk);
    QVector<double>().swap(C5VXgyroCompensatedAngleIncrementFloat);
    QVector<double>().swap(C5VXgyroCompensatedAngleIncrementFloat_bk);
    QVector<double>().swap(C5VYgyroCompensatedAngleIncrementFloat);
    QVector<double>().swap(C5VYgyroCompensatedAngleIncrementFloat_bk);
    QVector<double>().swap(C5VZgyroCompensatedAngleIncrementFloat);
    QVector<double>().swap(C5VZgyroCompensatedAngleIncrementFloat_bk);
    QVector<double>().swap(C5VXAccVelocityIncrementFloat);
    QVector<double>().swap(C5VXAccVelocityIncrementFloat_bk);
    QVector<double>().swap(C5VYAccVelocityIncrementFloat);
    QVector<double>().swap(C5VYAccVelocityIncrementFloat_bk);

    QVector<double>().swap(C5VZAccVelocityIncrementFloat);
    QVector<double>().swap(C5VZAccVelocityIncrementFloat_bk);
    QVector<double>().swap(C5VXgyroDifFrequency);
    QVector<double>().swap(C5VXgyroDifFrequency_bk);
    QVector<double>().swap(C5VYgyroDifFrequency);
    QVector<double>().swap(C5VYgyroDifFrequency_bk);
    QVector<double>().swap(C5VZgyroDifFrequency);
    QVector<double>().swap(C5VZgyroDifFrequency_bk);
    QVector<double>().swap(C5VXaccelerometerDifFre);
    QVector<double>().swap(C5VXaccelerometerDifFre_bk);
    QVector<double>().swap(C5VYaccelerometerDifFre);
    QVector<double>().swap(C5VYaccelerometerDifFre_bk);
    QVector<double>().swap(C5VZaccelerometerDifFre);
    QVector<double>().swap(C5VZaccelerometerDifFre_bk);
    QVector<double>().swap(C5VXgyroTemp1);
    QVector<double>().swap(C5VXgyroTemp1_bk);
    QVector<double>().swap(C5VYgyroTemp1);
    QVector<double>().swap(C5VYgyroTemp1_bk);
    QVector<double>().swap(C5VZgyroTemp1);
    QVector<double>().swap(C5VZgyroTemp1_bk);

    QVector<double>().swap(C5VXAccelerometerTemperture);
    QVector<double>().swap(C5VXAccelerometerTemperture_bk);
    QVector<double>().swap(C5VYAccelerometerTemperture);
    QVector<double>().swap(C5VYAccelerometerTemperture_bk);
    QVector<double>().swap(C5VZAccelerometerTemperture);
    QVector<double>().swap(C5VZAccelerometerTemperture_bk);
    QVector<double>().swap(C5VXgyroTemp2);
    QVector<double>().swap(C5VXgyroTemp2_bk);
    QVector<double>().swap(C5VYgyroTemp2);
    QVector<double>().swap(C5VYgyroTemp2_bk);
    QVector<double>().swap(C5VZgyroTemp2);
    QVector<double>().swap(C5VZgyroTemp2_bk);
    QVector<double>().swap(C5VXgyroAmplitudeJitter);
    QVector<double>().swap(C5VXgyroAmplitudeJitter_bk);
    QVector<double>().swap(C5VYgyroAmplitudeJitter);
    QVector<double>().swap(C5VYgyroAmplitudeJitter_bk);

    QVector<double>().swap(C5VZgyroAmplitudeJitter);
    QVector<double>().swap(C5VZgyroAmplitudeJitter_bk);

    QVector<double>().swap(C5VXgyroAmpl1itudeFre);
    QVector<double>().swap(C5VXgyroAmpl1itudeFre_bk);

    QVector<double>().swap(C5VYgyroAmpl1itudeFre);
    QVector<double>().swap(C5VYgyroAmpl1itudeFre_bk);

    QVector<double>().swap(C5VZgyroAmpl1itudeFre);
    QVector<double>().swap(C5VZgyroAmpl1itudeFre_bk);

    QVector<double>().swap(C3Vlongitude);
    QVector<double>().swap(C3Vlongitude_bk);

    QVector<double>().swap(C3VGPSlatitude);
    QVector<double>().swap(C3VGPSlatitude_bk);

    QVector<double>().swap(C3VtogetherSpeed);
    QVector<double>().swap(C3VtogetherSpeed_bk);

    QVector<double>().swap(C3VheadingAngle);
    QVector<double>().swap(C3VheadingAngle_bk);

    QVector<double>().swap(C3VcombinedEastSpeed);
    QVector<double>().swap(C3VcombinedEastSpeed_bk);

    QVector<double>().swap(C3VcombinedNorthSpeed);
    QVector<double>().swap(C3VcombinedNorthSpeed_bk);


    QVector<double>().swap(C3VwaterX);
    QVector<double>().swap(C3VwaterX_bk);
    QVector<double>().swap(C3VwaterY);
    QVector<double>().swap(C3VwaterY_bk);
    QVector<double>().swap(C3VbottomX);
    QVector<double>().swap(C3VbottomX_bk);
    QVector<double>().swap(C3VbottomY);
    QVector<double>().swap(C3VbottomY_bk);
    QVector<double>().swap(C3VelectromagnetismSpeed);
    QVector<double>().swap(C3VelectromagnetismSpeed_bk);

    QVector<double>().swap(C6VC6XGroyFloat);
    QVector<double>().swap(C6VC6XGroyFloat_bk);
    QVector<double>().swap(C6VC6YGroyFloat);
    QVector<double>().swap(C6VC6YGroyFloat_bk);
    QVector<double>().swap(C6VC6ZGroyFloat);
    QVector<double>().swap(C6VC6ZGroyFloat_bk);

    QVector<double>().swap(C6VC6XAccelerometerFloat);
    QVector<double>().swap(C6VC6XAccelerometerFloat_bk);

    QVector<double>().swap(C6VC6YAccelerometerFloat);
    QVector<double>().swap(C6VC6YAccelerometerFloat_bk);

    QVector<double>().swap(C6VC6ZAccelerometerFloat);
    QVector<double>().swap(C6VC6ZAccelerometerFloat_bk);
    QVector<double>().swap(VeastSpeedError);
    QVector<double>().swap(VeastSpeedError_bk);
    QVector<double>().swap(VnorthSpeedError);
    QVector<double>().swap(VnorthSpeedError_bk);

    QVector<double>().swap(VtogetherSpeedError);
    QVector<double>().swap(VtogetherSpeedError_bk);

    QVector<double>().swap(VlatitudeError_bk);
    QVector<double>().swap(VlatitudeError);

    QVector<double>().swap(VlongitudeError_bk);
    QVector<double>().swap(VlongitudeError);

    QVector<double>().swap(VpositionError);
    QVector<double>().swap(VpositionError_bk);



    //ui->tableWidget->clear();

}




//曲线图初始化
void MainWindow::init_darw2()
{
    QCustomPlot* customPlot = ui->customPlot2;
    connect(customPlot,&QCustomPlot::mouseDoubleClick,this,&MainWindow::on_pushButton_15_clicked);

    //四边安上坐标轴
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->setBackground(QColor(220,220,220));
    // 使上下轴、左右轴范围同步
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

//    QLinearGradient axisRectGradient;
//    axisRectGradient.setStart(0, 0);
//    axisRectGradient.setFinalStop(0, 350);
//    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
//    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
//    customPlot->axisRect()->setBackground(axisRectGradient);   // 设置QCPAxisRect背景颜色

    customPlot->xAxis->setBasePen(QPen(Qt::white, 1));  // 轴线的画笔
    customPlot->xAxis->setTickPen(QPen(Qt::white, 1));  // 轴刻度线的画笔
    customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1)); // 轴子刻度线的画笔
    customPlot->xAxis->setTickLabelColor(Qt::black);  // 轴刻度文字颜色
//    customPlot->xAxis->setLabel("标签");  // 只有设置了标签，轴标签的颜色才会显示
//    customPlot->xAxis->setLabelColor(Qt::white);   // 轴标签颜色
    customPlot->xAxis->setTickLengthIn(3);       // 轴线内刻度的长度
    customPlot->xAxis->setTickLengthOut(5);      // 轴线外刻度的长度
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);  // 设置轴线结束时的风格为 实角三角形但内部有凹陷的形状， setLowerEnding设置轴线开始时的风格


    customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));     // 网格线(对应刻度)画笔
    customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine)); // 子网格线(对应子刻度)画笔
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridVisible(true);     // 显示子网格线
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->grid()->setZeroLinePen(QPen(Qt::black));   // 设置刻度为0时的网格线的画笔
    customPlot->yAxis->grid()->setZeroLinePen(QPen(Qt::black));
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    customPlot->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//设置选框的样式：虚线
    customPlot->selectionRect()->setBrush(QBrush(QColor(0,0,100,50)));//设置选框的样式：半透明浅蓝
    customPlot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);


    QCustomPlot* customPlot2 = ui->customPlot3;
    customPlot2->clearGraphs();
    //四边安上坐标轴
    customPlot2->axisRect()->setupFullAxesBox();
    customPlot2->setBackground(QColor(220,220,220));
    // 使上下轴、左右轴范围同步
    //connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    //connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
   // QLinearGradient axisRectGradient;
    //axisRectGradient.setStart(0, 0);
//        axisRectGradient.setFinalStop(0, 350);
//        axisRectGradient.setColorAt(0, QColor(80, 80, 80));
//        axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    //customPlot->axisRect()->setBackground(axisRectGradient);   // 设置QCPAxisRect背景颜色
    customPlot2->xAxis->setBasePen(QPen(Qt::white, 1));  // 轴线的画笔
    customPlot2->xAxis->setTickPen(QPen(Qt::white, 1));  // 轴刻度线的画笔
    customPlot2->xAxis->setSubTickPen(QPen(Qt::white, 1)); // 轴子刻度线的画笔
    customPlot2->xAxis->setTickLabelColor(Qt::black);  // 轴刻度文字颜色
//  customPlot->xAxis->setLabel("标签");  // 只有设置了标签，轴标签的颜色才会显示
//  customPlot->xAxis->setLabelColor(Qt::white);   // 轴标签颜色
    customPlot2->xAxis->setTickLengthIn(3);       // 轴线内刻度的长度
    customPlot2->xAxis->setTickLengthOut(5);      // 轴线外刻度的长度
    customPlot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);  // 设置轴线结束时的风格为 实角三角形但内部有凹陷的形状， setLowerEnding设置轴线开始时的风格
    customPlot2->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));     // 网格线(对应刻度)画笔
    customPlot2->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine)); // 子网格线(对应子刻度)画笔
    customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot2->xAxis->grid()->setSubGridVisible(true);     // 显示子网格线
    customPlot2->yAxis->grid()->setSubGridVisible(true);
    customPlot2->xAxis->grid()->setZeroLinePen(QPen(Qt::black));   // 设置刻度为0时的网格线的画笔
    customPlot2->yAxis->grid()->setZeroLinePen(QPen(Qt::black));
    customPlot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    customPlot2->selectionRect()->setPen(QPen(Qt::black,1,Qt::DashLine));//设置选框的样式：虚线
    customPlot2->selectionRect()->setBrush(QBrush(QColor(0,0,100,50)));//设置选框的样式：半透明浅蓝
    customPlot2->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);

    QFont font;
    font.setPixelSize(14);
    customPlot->xAxis->setTickLabelFont(font);
    customPlot->yAxis->setTickLabelFont(font);

    QFont font2;
    font2.setPixelSize(14);
    customPlot2->xAxis->setTickLabelFont(font2);
    customPlot2->yAxis->setTickLabelFont(font2);

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(index == 1)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(index == 2)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(index == 3)
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if(index == 4)
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(index == 5)
    {
        ui->stackedWidget->setCurrentIndex(11);
    }
    else if(index == 6)
    {
        ui->stackedWidget->setCurrentIndex(12);
    }

    else if(index == 7)
    {
        ui->stackedWidget->setCurrentIndex(13);
    }

    else if(index == 8)
    {
        ui->stackedWidget->setCurrentIndex(14);
    }

    else if(index == 9)
    {
        ui->stackedWidget->setCurrentIndex(15);
    }
    else if(index == 10)
    {
        ui->stackedWidget->setCurrentIndex(16);
    }
    else if(index == 11)
    {
        ui->stackedWidget->setCurrentIndex(17);
    }
    else if(index == 12)
    {
        ui->stackedWidget->setCurrentIndex(20);
    }
    else if(index == 13)
    {
        ui->stackedWidget->setCurrentIndex(21);
    }
    ui->checkBox->setChecked(0);
    ui->checkBox->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_2->setChecked(0);
    ui->checkBox_2->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_3->setChecked(0);
    ui->checkBox_3->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_4->setChecked(0);
    ui->checkBox_4->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_5->setChecked(0);
    ui->checkBox_5->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_6->setChecked(0);
    ui->checkBox_6->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_7->setChecked(0);
    ui->checkBox_7->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_8->setChecked(0);
    ui->checkBox_8->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_9->setChecked(0);
    ui->checkBox_9->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_10->setChecked(0);
    ui->checkBox_10->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_11->setChecked(0);
    ui->checkBox_11->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_12->setChecked(0);
    ui->checkBox_12->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_13->setChecked(0);
    ui->checkBox_13->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_14->setChecked(0);
    ui->checkBox_14->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_15->setChecked(0);
    ui->checkBox_15->setStyleSheet("QCheckBox{color:rgb(255,0,128)}");

    ui->checkBox_16->setChecked(0);
    ui->checkBox_16->setStyleSheet("QCheckBox{color:rgb(147,108,0)}");

    ui->checkBox_17->setChecked(0);
    ui->checkBox_17->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_18->setChecked(0);
    ui->checkBox_18->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_19->setChecked(0);
    ui->checkBox_19->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_20->setChecked(0);
    ui->checkBox_20->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_21->setChecked(0);
    ui->checkBox_21->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_22->setChecked(0);
    ui->checkBox_22->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_23->setChecked(0);
    ui->checkBox_23->setStyleSheet("QCheckBox{color:rgb(255,0,0)}");

    ui->checkBox_24->setChecked(0);
    ui->checkBox_24->setStyleSheet("QCheckBox{color:rgb(128,0,255)}");

    ui->checkBox_25->setChecked(0);
    ui->checkBox_25->setStyleSheet("QCheckBox{color:rgb(0,143,122)}");

    ui->checkBox_26->setChecked(0);
    ui->checkBox_27->setChecked(0);
    ui->checkBox_28->setChecked(0);
    ui->checkBox_29->setChecked(0);
    ui->checkBox_30->setChecked(0);
    ui->checkBox_31->setChecked(0);
    ui->checkBox_32->setChecked(0);
    ui->checkBox_33->setChecked(0);
    ui->checkBox_34->setChecked(0);
    ui->checkBox_35->setChecked(0);
    ui->checkBox_36->setChecked(0);
    ui->checkBox_37->setChecked(0);
    ui->checkBox_40->setChecked(0);
    ui->checkBox_38->setChecked(0);
    ui->checkBox_39->setChecked(0);
    ui->checkBox_42->setChecked(0);
    ui->checkBox_43->setChecked(0);
    ui->checkBox_41->setChecked(0);
    ui->checkBox_45->setChecked(0);
    ui->checkBox_46->setChecked(0);
    ui->checkBox_44->setChecked(0);
    ui->checkBox_48->setChecked(0);
    ui->checkBox_49->setChecked(0);
    ui->checkBox_47->setChecked(0);
    ui->checkBox_50->setChecked(0);
    ui->checkBox_51->setChecked(0);
    ui->checkBox_52->setChecked(0);
    ui->checkBox_53->setChecked(0);
    ui->checkBox_54->setChecked(0);
    ui->checkBox_55->setChecked(0);
    ui->checkBox_56->setChecked(0);
    ui->checkBox_57->setChecked(0);
    ui->checkBox_58->setChecked(0);
    ui->checkBox_59->setChecked(0);
    ui->checkBox_60->setChecked(0);
    ui->checkBox_61->setChecked(0);
    ui->checkBox_62->setChecked(0);
    ui->checkBox_63->setChecked(0);
    ui->checkBox_64->setChecked(0);
    ui->checkBox_65->setChecked(0);
    ui->checkBox_66->setChecked(0);
    ui->checkBox_67->setChecked(0);
    ui->checkBox_68->setChecked(0);
    ui->checkBox_69->setChecked(0);
    ui->checkBox_70->setChecked(0);
    ui->checkBox_71->setChecked(0);
    ui->checkBox_72->setChecked(0);


    ui->checkBox_73->setChecked(0);
    ui->checkBox_74->setChecked(0);
    ui->checkBox_75->setChecked(0);
    ui->checkBox_76->setChecked(0);
    ui->checkBox_77->setChecked(0);
    ui->checkBox_78->setChecked(0);
    ui->checkBox_79->setChecked(0);
    ui->checkBox_80->setChecked(0);
    ui->checkBox_81->setChecked(0);

    C1latitudeCurveRun=0;               //判断C1纬度曲线是否存在
    C1latitudeGraphNum=0;              //纬度在当前画图板中是第几条曲线


    C1headingAngleRun=0;                //判断C1航向曲线是否存在
    C1headingAngleNum=0;              //航向在当前画图板qreal rollAngle中是第几条曲线


    C1longitudeRun=0;                //判断C1经度曲线是否存在
    C1longitudeNum=0;              //经度在当前画图板中是第几条曲线

    C1rollAngleRun=0;                //判断C1横摇角曲线是否存在
    C1rollAngleNum=0;              //横摇角在当前画图板中是第几条曲线


    C1pitchAngleRun=0;                //判断C1纵摇角曲线是否存在
    C1pitchAngleNum=0;              //纵摇角在当前画图板中是第几条曲线


    C1northSpeedRun=0;                //判断C1北速曲线是否存在
    C1northSpeedNum=0;              //北速在当前画图板中是第几条曲线

    C1eastSpeedRun=0;                //判断C1东速曲线是否存在
    C1eastSpeedNum=0;              //东速在当前画图板中是第几条曲线


    C1headingAngularSpeedRun=0;                //判断C1航向角速度曲线是否存在
    C1headingAngularSpeedNum=0;


    C1rollAngleSpeedRun=0;                //判断C1横摇角速度曲线是否存在
    C1rollAngleSpeedNum=0;

    C1pitchAngleSpeedRun=0;                //判断C1纵摇角速度曲线是否存在
    C1pitchAngleSpeedNum=0;


    C1heaveRun=0;                //判断C1垂荡曲线是否存在
    C1heaveNum=0;


    C1verticalVelocityRun=0;                //判断C1垂速曲线是否存在
    C1verticalVelocityNum=0;


    C1swayRun=0;                //判断C1横荡曲线是否存在
    C1swayNum=0;


    C1transverseVelocityRun=0;                //判断C1横速曲线是否存在
    C1transverseVelocityNum=0;


    C1surgeRun=0;                //判断C1纵荡曲线是否存在
    C1surgeNum=0;


    C1longitudinalVelocityRun=0;                //判断C1纵速曲线是否存在
    C1longitudinalVelocityNum=0;


    C5XGyroAngleIncreaseFloatRun=0;                //判断C5X陀螺增量曲线是否存在
    C5XGyroAngleIncreaseFloatNum=0;


    C5YGyroAngleIncreaseFloatRun=0;                //判断C5Y陀螺增量曲线是否存在
    C5YGyroAngleIncreaseFloatNum=0;


    C5ZGyroAngleIncreaseFloatRun=0;                //判断C5Z陀螺增量曲线是否存在
    C5ZGyroAngleIncreaseFloatNum=0;


    C5XAccelerometerSpeedIncrementFloatRun=0;                //判断C5X加表增量曲线是否存在
    C5XAccelerometerSpeedIncrementFloatNum=0;


    C5YAccelerometerSpeedIncrementFloatRun=0;                //判断C5Y加表增量曲线是否存在
    C5YAccelerometerSpeedIncrementFloatNum=0;


    C5ZAccelerometerSpeedIncrementFloatRun=0;                //判断C5Z加表增量曲线是否存在
    C5ZAccelerometerSpeedIncrementFloatNum=0;


    C5XgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的x陀螺1s补偿后角增量曲线是否存在
    C5XgyroCompensatedAngleIncrementFloatNum=0;

    C5YgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的Y陀螺1s补偿后角增量曲线是否存在
    C5YgyroCompensatedAngleIncrementFloatNum=0;


    C5ZgyroCompensatedAngleIncrementFloatRun=0;                //判断C5的Z陀螺1s补偿后角增量曲线是否存在
    C5ZgyroCompensatedAngleIncrementFloatNum=0;


    C5XAccVelocityIncrementFloatRun=0;                //判断C5的x加速度计1s补偿后速度增量曲线是否存在
    C5XAccVelocityIncrementFloatNum=0;


    C5YAccVelocityIncrementFloatRun=0;                //判断C5的Y加速度计1s补偿后速度增量曲线是否存在
    C5YAccVelocityIncrementFloatNum=0;


    C5ZAccVelocityIncrementFloatRun=0;                //判断C5的Z加速度计1s补偿后速度增量曲线是否存在
    C5ZAccVelocityIncrementFloatNum=0;


    C5XgyroDifFrequencyRun=0;                //判断C5的X陀螺差频曲线是否存在
    C5XgyroDifFrequencyNum=0;


    C5YgyroDifFrequencyRun=0;                //判断C5的Y陀螺差频曲线是否存在
    C5YgyroDifFrequencyNum=0;


    C5ZgyroDifFrequencyRun=0;                //判断C5的Z陀螺差频曲线是否存在
    C5ZgyroDifFrequencyNum=0;


    C5XaccelerometerDifFreRun=0;                //判断C5的X加速度计差频曲线是否存在
    C5XaccelerometerDifFreNum=0;


    C5YaccelerometerDifFreRun=0;                //判断C5的Y加速度计差频曲线是否存在
    C5YaccelerometerDifFreNum=0;


    C5ZaccelerometerDifFreRun=0;                //判断C5的Z加速度计差频曲线是否存在
    C5ZaccelerometerDifFreNum=0;


    C5XgyroTemp1Run=0;                //判断C5的X陀螺温度1是否存在
    C5XgyroTemp1Num=0;


    C5YgyroTemp1Run=0;                //判断C5的Y陀螺温度1是否存在
    C5YgyroTemp1Num=0;


    C5ZgyroTemp1Run=0;                //判断C5的Z陀螺温度1曲线是否存在
    C5ZgyroTemp1Num=0;


    C5XAccelerometerTempertureRun=0;                //判断C5的X加速度计温度1是否存在
    C5XAccelerometerTempertureNum=0;


    C5YAccelerometerTempertureRun=0;                //判断C5的Y加速度计温度1是否存在
    C5YAccelerometerTempertureNum=0;


    C5ZAccelerometerTempertureRun=0;                //判断C5的Z加速度计温度1曲线是否存在
    C5ZAccelerometerTempertureNum=0;


    C5XgyroTemp2Run=0;                //判断C5的X陀螺温度2是否存在
    C5XgyroTemp2Num=0;


    C5YgyroTemp2Run=0;                //判断C5的Y陀螺温度2是否存在
    C5YgyroTemp2Num=0;


    C5ZgyroTemp2Run=0;                //判断C5的Z陀螺温度2曲线是否存在
    C5ZgyroTemp2Num=0;


    C5XgyroAmplitudeJitterRun=0;                //判断C5的X陀螺抖幅曲线是否存在
    C5XgyroAmplitudeJitterNum=0;

    C5YgyroAmplitudeJitterRun=0;                //判断C5的Y陀螺抖幅曲线是否存在
    C5YgyroAmplitudeJitterNum=0;


    C5ZgyroAmplitudeJitterRun=0;                //判断C5的Z陀螺抖幅曲线是否存在
    C5ZgyroAmplitudeJitterNum=0;


    C5XgyroAmpl1itudeFreRun=0;                //判断C5的X陀螺抖频曲线是否存在
    C5XgyroAmpl1itudeFreNum=0;


    C5YgyroAmpl1itudeFreRun=0;                //判断C5的Y陀螺抖频曲线是否存在
    C5YgyroAmpl1itudeFreNum=0;


    C5ZgyroAmpl1itudeFreRun=0;                //判断C5的Z陀螺抖频曲线是否存在
    C5ZgyroAmpl1itudeFreNum=0;

    C3longitudeRun=0;                //判断C3的GPS经度曲线是否存在
    C3longitudeNum=0;


    C3GPSlatitudeRun=0;                //判断C3的GPS纬度曲线是否存在
    C3GPSlatitudeNum=0;


    C3togetherSpeedRun=0;                //判断C3的GPS合速曲线是否存在
    C3togetherSpeedNum=0;


    C3headingAngleRun=0;                //判断C3的GPS航向曲线是否存在
    C3headingAngleNum=0;


    C3combinedEastSpeedRun=0;                //判断C3的GPS东速曲线是否存在
    C3combinedEastSpeedNum=0;


    C3combinedNorthSpeedRun=0;                //判断C3的GPS北速曲线是否存在
    C3combinedNorthSpeedNum=0;


    C3waterXRun=0;                //判断C3的G多普勒对水横向速度曲线是否存在
    C3waterXNum=0;


    C3waterYRun=0;                //判断C3的G多普勒对水纵向速度曲线是否存在
    C3waterYNum=0;

    C3bottomXRun=0;                //判断C3的G多普勒对底横向速度曲线是否存在
    C3bottomXNum=0;

    C3bottomYRun=0;                //判断C3的G多普勒对底纵向速度曲线是否存在
    C3bottomYNum=0;

    C3electromagnetismSpeedRun=0;                //判断C3的电磁速度曲线是否存在
    C3electromagnetismSpeedNum=0;


    C6XGroyFloatRun=0;                //判断C6的X陀螺零偏曲线是否存在
    C6XGroyFloatNum=0;


    C6YGroyFloatRun=0;                //判断C6的Y陀螺零偏曲线是否存在
    C6YGroyFloatNum=0;


    C6ZGroyFloatRun=0;                //判断C6的Z陀螺零偏曲线是否存在
    C6ZGroyFloatNum=0;


    C6XAccelerometerFloatRun=0;                //判断C6的X加速度计零偏曲线是否存在
    C6XAccelerometerFloatNum=0;


    C6YAccelerometerFloatRun=0;                //判断C6的Y加速度计零偏曲线是否存在
    C6YAccelerometerFloatNum=0;

    C6ZAccelerometerFloatRun=0;                //判断C6的Z加速度计零偏曲线是否存在
    C6ZAccelerometerFloatNum=0;


    eastSpeedErrorRun=0;                //判断东速误差曲线是否存在
    eastSpeedErrorNum=0;


    northSpeedErrorRun=0;                //判断北速误差曲线是否存在
    northSpeedErrorNum=0;

    togetherSpeedErrorRun=0;                //判断合速速误差曲线是否存在
    togetherSpeedErrorNum=0;

    latitudeErrorRun=0;                //判断纬度误差曲线是否存在
    latitudeErrorNum=0;

    longitudeErrorRun=0;                //判断经度误差曲线是否存在
    longitudeErrorNum=0;


    positionErrorRun=0;                //判断位置误差曲线是否存在
    positionErrorNum=0;


    C6UndampedRollAngleFloatRun=0;                //判断C6无阻尼横摇角曲线是否存在
    C6UndampedRollAngleFloatNum=0;

    C6UndampedPitchAngleFloatRun=0;                //判断C6的无阻尼纵摇角曲线是否存在
    C6UndampedPitchAngleFloatNum=0;

    C6UndampedHeadingAngularFloatRun=0;                //判断C6的无阻尼航向角曲线是否存在
    C6UndampedHeadingAngularFloatNum=0;

    C6UndampedNorthSpeedFloatRun=0;                //判断C6的无阻尼北速是否存在
    C6UndampedNorthSpeedFloatNum=0;

    C6UndampedEastSpeedFloatRun=0;                //判断C6的无阻尼东速曲线是否存在
    C6UndampedEastSpeedFloatNum=0;

    C6VerticalVelocityFloatRun=0;                //判断C6的无阻尼垂速曲线是否存在
    C6VerticalVelocityFloatNum=0;

    C6UndampedLatFloatRun=0;                //判断C6的无阻尼纬度曲线是否存在
    C6UndampedLatFloatNum=0;

    C6UndampedLongFloatRun=0;                //判断C6的无阻尼经度曲线是否存在
    C6UndampedLongFloatNum=0;

    C6UndampedHeightFloatRun=0;                //判断C6的无阻尼高度曲线是否存在
    C6UndampedHeightFloatNum=0;



    ui->customPlot2->clearGraphs();
    ui->customPlot2->replot(QCustomPlot::rpQueuedReplot);

}
//void MainWindow::wheelEvent(QWheelEvent *event)
//{    static int i=0;
//     i++;
//    if (ui->customPlot2->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
//    {
//      qDebug("%d",i);
//     ui->customPlot2->axisRect()->setRangeZoom(ui->customPlot2->xAxis->orientation());
//  // ui->customPlot->axisRect()->setRangeZoomFactor(1.2,1);//x方向为1.2
//    }
//    else if (ui->customPlot2->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
//    {
//       ui->customPlot2->axisRect()->setRangeZoom(ui->customPlot2->yAxis->orientation());
//   // ui->customPlot->axisRect()->setRangeZoomFactor(1.2,1);//x方向为1.2
//    }
//    else
//      ui->customPlot2->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
//}


void MainWindow::on_pushButton_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }

    paraQuery->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }

    bookOriData->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    attitudeData->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    shipLoadData->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    calbratParaData->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    tempCompenCoeffData->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    leverArmData->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }


    if(qGetdataTime->isActive())
        qGetdataTime->stop();
    if(qDrawTime->isActive())
        qDrawTime->stop();
    m_xLength = 0;

    C1Vlatitude_bk += C1Vlatitude;
    C1VheadingAngle_bk += C1VheadingAngle;
    C1Vlongitude_bk += C1Vlongitude;
    C1VrollAngle_bk += C1VrollAngle;
    C1VpitchAngle_bk += C1VpitchAngle;
    C1VnorthSpeed_bk +=C1VnorthSpeed;
    C1VeastSpeed_bk +=C1VeastSpeed;
    C1VheadingAngularSpeed_bk +=C1VheadingAngularSpeed;
    C1VrollAngleSpeed_bk += C1VrollAngleSpeed;
    C1VpitchAngleSpeed_bk += C1VpitchAngleSpeed;
    C1Vheave_bk += C1Vheave;
    C1VverticalVelocity_bk +=C1VverticalVelocity;
    C1Vsway_bk +=C1Vsway;
    C1VtransverseVelocity_bk +=C1VtransverseVelocity;
    C1Vsurge_bk += C1Vsurge;
    C1VlongitudinalVelocity_bk +=C1VlongitudinalVelocity;
    if(0)//不显示增量、补偿增量和差频（原始脉冲曲线）2022-01-20
    {
        C5VXGyroAngleIncreaseFloat_bk+=C5VXGyroAngleIncreaseFloat;
        C5VYGyroAngleIncreaseFloat_bk+=C5VYGyroAngleIncreaseFloat;
        C5VZGyroAngleIncreaseFloat_bk+=C5VZGyroAngleIncreaseFloat;
        C5VXAccelerometerSpeedIncrementFloat_bk +=C5VXAccelerometerSpeedIncrementFloat;
        C5VYAccelerometerSpeedIncrementFloat_bk+=C5VYAccelerometerSpeedIncrementFloat;
        C5VZAccelerometerSpeedIncrementFloat_bk+=C5VZAccelerometerSpeedIncrementFloat;
        C5VXgyroCompensatedAngleIncrementFloat_bk+=C5VXgyroCompensatedAngleIncrementFloat;
        C5VYgyroCompensatedAngleIncrementFloat_bk+=C5VYgyroCompensatedAngleIncrementFloat;
        C5VZgyroCompensatedAngleIncrementFloat_bk+=C5VZgyroCompensatedAngleIncrementFloat;
        C5VXAccVelocityIncrementFloat_bk+=C5VXAccVelocityIncrementFloat;
        C5VYAccVelocityIncrementFloat_bk+=C5VYAccVelocityIncrementFloat;
        C5VZAccVelocityIncrementFloat_bk+=C5VZAccVelocityIncrementFloat;

        C5VXgyroDifFrequency_bk+=C5VXgyroDifFrequency;
        C5VYgyroDifFrequency_bk+=C5VYgyroDifFrequency;
        C5VZgyroDifFrequency_bk+=C5VZgyroDifFrequency;
        C5VXaccelerometerDifFre_bk+=C5VXaccelerometerDifFre;
        C5VYaccelerometerDifFre_bk+=C5VYaccelerometerDifFre;
        C5VZaccelerometerDifFre_bk+=C5VZaccelerometerDifFre;
    }

    C5VXgyroTemp1_bk+=C5VXgyroTemp1;
    C5VYgyroTemp1_bk+=C5VYgyroTemp1;
    C5VZgyroTemp1_bk+=C5VZgyroTemp1;
    C5VXAccelerometerTemperture_bk+=C5VXAccelerometerTemperture;
    C5VYAccelerometerTemperture_bk+=C5VYAccelerometerTemperture;
    C5VZAccelerometerTemperture_bk+=C5VZAccelerometerTemperture;
    C5VXgyroTemp2_bk+=C5VXgyroTemp2;
    C5VYgyroTemp2_bk+=C5VYgyroTemp2;
    C5VZgyroTemp2_bk+=C5VZgyroTemp2;
    C5VXgyroAmplitudeJitter_bk+=C5VXgyroAmplitudeJitter;
    C5VYgyroAmplitudeJitter_bk+=C5VYgyroAmplitudeJitter;
    C5VZgyroAmplitudeJitter_bk+=C5VZgyroAmplitudeJitter;
    C5VXgyroAmpl1itudeFre_bk+=C5VXgyroAmpl1itudeFre;
    C5VYgyroAmpl1itudeFre_bk+=C5VYgyroAmpl1itudeFre;
    C5VZgyroAmpl1itudeFre_bk+=C5VZgyroAmpl1itudeFre;
    C3Vlongitude_bk+=C3Vlongitude;
    C3VGPSlatitude_bk+=C3VGPSlatitude;
    C3VtogetherSpeed_bk+=C3VtogetherSpeed;
    C3VheadingAngle_bk+=C3VheadingAngle;
    C3VcombinedEastSpeed_bk+=C3VcombinedEastSpeed;
    C3VcombinedNorthSpeed_bk+=C3VcombinedNorthSpeed;
    C3VwaterX_bk+=C3VwaterX;
    C3VwaterY_bk+=C3VwaterY;
    C3VbottomX_bk+=C3VbottomX;
    C3VbottomY_bk+=C3VbottomY;
    C3VelectromagnetismSpeed_bk+=C3VelectromagnetismSpeed;

    C6VC6UndampedRollAngleFloat_bk +=C6VC6UndampedRollAngleFloat;
    C6VC6UndampedPitchAngleFloat_bk+=C6VC6UndampedPitchAngleFloat;
    C6VC6UndampedHeadingAngularFloat_bk+=C6VC6UndampedHeadingAngularFloat;
    C6VC6UndampedNorthSpeedFloat_bk+=C6VC6UndampedNorthSpeedFloat;
    C6VC6UndampedEastSpeedFloat_bk+=C6VC6UndampedEastSpeedFloat;
    C6VC6VerticalVelocityFloat_bk+=C6VC6VerticalVelocityFloat;
    C6VC6UndampedLatFloat_bk+=C6VC6UndampedLatFloat;
    C6VC6UndampedLongFloat_bk+=C6VC6UndampedLongFloat;
    C6VC6UndampedHeightFloat_bk+=C6VC6UndampedHeightFloat;

    if(0)//不显示零偏曲线2022-01-20
    {
        C6VC6XGroyFloat_bk+=C6VC6XGroyFloat;
        C6VC6YGroyFloat_bk+=C6VC6YGroyFloat;
        C6VC6ZGroyFloat_bk+=C6VC6ZGroyFloat;
        C6VC6XAccelerometerFloat_bk+=C6VC6XAccelerometerFloat;
        C6VC6YAccelerometerFloat_bk+=C6VC6YAccelerometerFloat;
        C6VC6ZAccelerometerFloat_bk+=C6VC6ZAccelerometerFloat;
    }
    VeastSpeedError_bk+=VeastSpeedError;
    VnorthSpeedError_bk+=VnorthSpeedError;
    VtogetherSpeedError_bk+=VtogetherSpeedError;
    VlatitudeError_bk+=VlatitudeError;
    VlongitudeError_bk+=VlongitudeError;
    VpositionError_bk+=VpositionError;

    C1Vlatitude.clear();
    C1VheadingAngle.clear();
    C1Vlongitude.clear();
    C1VrollAngle.clear();
    C1VpitchAngle.clear();
    C1VnorthSpeed.clear();
    C1VeastSpeed.clear();
    C1VheadingAngularSpeed.clear();
    C1VrollAngleSpeed.clear();
    C1VpitchAngleSpeed.clear();
    C1Vheave.clear();
    C1VverticalVelocity.clear();
    C1Vsway.clear();
    C1VtransverseVelocity.clear();
    C1Vsurge.clear();
    C1VlongitudinalVelocity.clear();
    C5VXGyroAngleIncreaseFloat.clear();
    C5VYGyroAngleIncreaseFloat.clear();
    C5VZGyroAngleIncreaseFloat.clear();
    C5VXAccelerometerSpeedIncrementFloat.clear();
    C5VYAccelerometerSpeedIncrementFloat.clear();
    C5VZAccelerometerSpeedIncrementFloat.clear();
    C5VXgyroCompensatedAngleIncrementFloat.clear();
    C5VYgyroCompensatedAngleIncrementFloat.clear();
    C5VZgyroCompensatedAngleIncrementFloat.clear();
    C5VXAccVelocityIncrementFloat.clear();
    C5VYAccVelocityIncrementFloat.clear();
    C5VZAccVelocityIncrementFloat.clear();
    C5VXgyroDifFrequency.clear();
    C5VYgyroDifFrequency.clear();
    C5VZgyroDifFrequency.clear();
    C5VXaccelerometerDifFre.clear();
    C5VYaccelerometerDifFre.clear();
    C5VZaccelerometerDifFre.clear();
    C5VXgyroTemp1.clear();
    C5VYgyroTemp1.clear();
    C5VZgyroTemp1.clear();
    C5VXAccelerometerTemperture.clear();
    C5VYAccelerometerTemperture.clear();
    C5VZAccelerometerTemperture.clear();
    C5VXgyroTemp2.clear();
    C5VYgyroTemp2.clear();
    C5VZgyroTemp2.clear();
    C5VXgyroAmplitudeJitter.clear();
    C5VYgyroAmplitudeJitter.clear();
    C5VZgyroAmplitudeJitter.clear();
    C5VXgyroAmpl1itudeFre.clear();
    C5VYgyroAmpl1itudeFre.clear();
    C5VZgyroAmpl1itudeFre.clear();
    C3Vlongitude.clear();
    C3VGPSlatitude.clear();
    C3VtogetherSpeed.clear();
    C3VheadingAngle.clear();
    C3VcombinedEastSpeed.clear();
    C3VcombinedNorthSpeed.clear();
    C3VwaterX.clear();
    C3VwaterY.clear();
    C3VbottomX.clear();
    C3VbottomY.clear();
    C3VelectromagnetismSpeed.clear();
    C6VC6XGroyFloat.clear();
    C6VC6YGroyFloat.clear();
    C6VC6ZGroyFloat.clear();
    C6VC6XAccelerometerFloat.clear();
    C6VC6YAccelerometerFloat.clear();
    C6VC6ZAccelerometerFloat.clear();
    VeastSpeedError.clear();
    VnorthSpeedError.clear();
    VtogetherSpeedError.clear();
    VlatitudeError.clear();
    VlongitudeError.clear();
    VpositionError.clear();
    curveX.clear();

    C6VC6UndampedRollAngleFloat.clear();
    C6VC6UndampedPitchAngleFloat.clear();
    C6VC6UndampedHeadingAngularFloat.clear();
    C6VC6UndampedNorthSpeedFloat.clear();
    C6VC6UndampedEastSpeedFloat.clear();
    C6VC6VerticalVelocityFloat.clear();
    C6VC6UndampedLatFloat.clear();
    C6VC6UndampedLongFloat.clear();
    C6VC6UndampedHeightFloat.clear();

    if(!qGetdataTime->isActive())
        qGetdataTime->start(addDataPeri);
    if(!qDrawTime->isActive())
        qDrawTime->start(addDataPeri);
}

void MainWindow::on_pushButton_9_clicked()
{
    qGetdataTime->stop();
    qDrawTime->stop();
    int checkBoxNum = 0;
    if(ui->checkBox->isChecked()) checkBoxNum++;
    if(ui->checkBox_2->isChecked())	checkBoxNum++;
    if(ui->checkBox_3->isChecked())	checkBoxNum++;
    if(ui->checkBox_4->isChecked())	checkBoxNum++;
    if(ui->checkBox_5->isChecked())	checkBoxNum++;
    if(ui->checkBox_6->isChecked())	checkBoxNum++;
    if(ui->checkBox_7->isChecked())	checkBoxNum++;
    if(ui->checkBox_8->isChecked())	checkBoxNum++;
    if(ui->checkBox_9->isChecked())	checkBoxNum++;
    if(ui->checkBox_10->isChecked())	checkBoxNum++;
    if(ui->checkBox_11->isChecked())	checkBoxNum++;
    if(ui->checkBox_12->isChecked())	checkBoxNum++;
    if(ui->checkBox_13->isChecked())	checkBoxNum++;
    if(ui->checkBox_14->isChecked())	checkBoxNum++;
    if(ui->checkBox_15->isChecked())	checkBoxNum++;
    if(ui->checkBox_16->isChecked())	checkBoxNum++;
    if(ui->checkBox_17->isChecked())	checkBoxNum++;
    if(ui->checkBox_18->isChecked())	checkBoxNum++;
    if(ui->checkBox_19->isChecked())	checkBoxNum++;
    if(ui->checkBox_20->isChecked())	checkBoxNum++;
    if(ui->checkBox_21->isChecked())	checkBoxNum++;
    if(ui->checkBox_22->isChecked())	checkBoxNum++;
    if(ui->checkBox_23->isChecked())	checkBoxNum++;
    if(ui->checkBox_24->isChecked())	checkBoxNum++;
    if(ui->checkBox_25->isChecked())	checkBoxNum++;
    if(ui->checkBox_26->isChecked())	checkBoxNum++;
    if(ui->checkBox_27->isChecked())	checkBoxNum++;
    if(ui->checkBox_28->isChecked())	checkBoxNum++;
    if(ui->checkBox_29->isChecked())	checkBoxNum++;
    if(ui->checkBox_30->isChecked())	checkBoxNum++;
    if(ui->checkBox_31->isChecked())	checkBoxNum++;
    if(ui->checkBox_32->isChecked())	checkBoxNum++;
    if(ui->checkBox_33->isChecked())	checkBoxNum++;
    if(ui->checkBox_34->isChecked())	checkBoxNum++;
    if(ui->checkBox_35->isChecked())	checkBoxNum++;
    if(ui->checkBox_36->isChecked())	checkBoxNum++;
    if(ui->checkBox_37->isChecked())	checkBoxNum++;
    if(ui->checkBox_38->isChecked())	checkBoxNum++;
    if(ui->checkBox_39->isChecked())	checkBoxNum++;
    if(ui->checkBox_40->isChecked())	checkBoxNum++;
    if(ui->checkBox_41->isChecked())	checkBoxNum++;
    if(ui->checkBox_42->isChecked())	checkBoxNum++;
    if(ui->checkBox_43->isChecked())	checkBoxNum++;
    if(ui->checkBox_44->isChecked())	checkBoxNum++;
    if(ui->checkBox_45->isChecked())	checkBoxNum++;
    if(ui->checkBox_46->isChecked())	checkBoxNum++;
    if(ui->checkBox_47->isChecked())	checkBoxNum++;
    if(ui->checkBox_48->isChecked())	checkBoxNum++;
    if(ui->checkBox_49->isChecked())	checkBoxNum++;
    if(ui->checkBox_50->isChecked())	checkBoxNum++;
    if(ui->checkBox_51->isChecked())	checkBoxNum++;
    if(ui->checkBox_52->isChecked())	checkBoxNum++;
    if(ui->checkBox_53->isChecked())	checkBoxNum++;
    if(ui->checkBox_54->isChecked())	checkBoxNum++;
    if(ui->checkBox_55->isChecked())	checkBoxNum++;
    if(ui->checkBox_56->isChecked())	checkBoxNum++;
    if(ui->checkBox_57->isChecked())	checkBoxNum++;
    if(ui->checkBox_58->isChecked())	checkBoxNum++;
    if(ui->checkBox_59->isChecked())	checkBoxNum++;
    if(ui->checkBox_60->isChecked())	checkBoxNum++;
    if(ui->checkBox_61->isChecked())	checkBoxNum++;
    if(ui->checkBox_62->isChecked())	checkBoxNum++;
    if(ui->checkBox_63->isChecked())	checkBoxNum++;
    if(ui->checkBox_64->isChecked())	checkBoxNum++;
    if(ui->checkBox_65->isChecked())	checkBoxNum++;
    if(ui->checkBox_66->isChecked())	checkBoxNum++;
    if(ui->checkBox_67->isChecked())	checkBoxNum++;
    if(ui->checkBox_68->isChecked())	checkBoxNum++;
    if(ui->checkBox_69->isChecked())	checkBoxNum++;
    if(ui->checkBox_70->isChecked())	checkBoxNum++;
    if(ui->checkBox_71->isChecked())	checkBoxNum++;
    if(ui->checkBox_72->isChecked())	checkBoxNum++;
    if(ui->checkBox_73->isChecked())	checkBoxNum++;
    if(ui->checkBox_74->isChecked())	checkBoxNum++;
    if(ui->checkBox_75->isChecked())	checkBoxNum++;
    if(ui->checkBox_76->isChecked())	checkBoxNum++;
    if(ui->checkBox_77->isChecked())	checkBoxNum++;
    if(ui->checkBox_78->isChecked())	checkBoxNum++;
    if(ui->checkBox_79->isChecked())	checkBoxNum++;
    if(ui->checkBox_80->isChecked())	checkBoxNum++;
    if(ui->checkBox_81->isChecked())	checkBoxNum++;
    if(checkBoxNum == 0)
    {
        QMessageBox::warning(NULL, "提示", "未勾选曲线！");
        qGetdataTime->start(addDataPeri);
        qDrawTime->start(addDataPeri);
        return;
    }
    QString path = QFileDialog::getSaveFileName(this,"保存曲线","./","*.dat");

    if(path.isEmpty())
    {
        qGetdataTime->start(addDataPeri);
        qDrawTime->start(addDataPeri);
        return;
    }
    QFile fileSave(path);
    if(!fileSave.open( QIODevice::WriteOnly ))
      {
          //无法打开要写入的文件
          QMessageBox::warning(this, tr("打开写入文件"),
                               tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
          qGetdataTime->start(addDataPeri);
          qDrawTime->start(drawDataPeri);
          return;
      }
    QVector<double> C1Vlatitude_save = C1Vlatitude_bk + C1Vlatitude;
    QTextStream dataOut(&fileSave);
    dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
    dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    dataOut<<"<CurveProfile,"<<checkBoxNum<<","<<C1Vlatitude_save.size()*checkBoxNum<<","<<dayStr<<">"<<"\n";   //文件开始格式

    QProgressDialog *progressDialog = new QProgressDialog(this);
    QFont font("ZYSong18030", 12);
    progressDialog->setFont(font);
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setMinimumDuration(5);
    progressDialog->setWindowTitle(tr("Please Wait"));
    progressDialog->setLabelText(tr("Copying..."));
    progressDialog->setCancelButtonText(tr("Cancel"));

    if(1)//保存位置曲线
    {
        int C1VlatitudeNum = 0;
        int C1VlongitudeNum = 0;
        int C6UndampedLatFloatNum = 0;
        int C6UndampedLongFloatNum = 0;
        int C6UndampedHeightFloatNum = 0;

        //保存纬度和经度曲线
        if(ui->checkBox->isChecked() == true)
            C1VlatitudeNum += C1Vlatitude_bk.size() + C1Vlatitude.size();
        if(ui->checkBox_2->isChecked() == true)
            C1VlongitudeNum += C1Vlongitude_bk.size() + C1Vlongitude.size();
        if(ui->checkBox_73->isChecked() == true)
            C6UndampedLatFloatNum += C6VC6UndampedLatFloat_bk.size() + C6VC6UndampedLatFloat.size();
        if(ui->checkBox_74->isChecked() == true)
            C6UndampedLongFloatNum += C6VC6UndampedLongFloat_bk.size() + C6VC6UndampedLongFloat.size();
        if(ui->checkBox_75->isChecked() == true)
            C6UndampedHeightFloatNum += C6VC6UndampedHeightFloat_bk.size() + C6VC6UndampedHeightFloat.size();
        progressDialog->setRange(0, C1VlatitudeNum+C1VlongitudeNum+C6UndampedLatFloatNum+C6UndampedLongFloatNum+C6UndampedHeightFloatNum);
        if(ui->checkBox->isChecked() == true)
        {


            dataOut<<tr("<纬度,")<<C1Vlatitude_save.size()<<">"<<"\n";
            for(int i = 0;i<C1Vlatitude_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1Vlatitude_save[i]<<",";
            }
            dataOut<<tr("\n</纬度>")<<"\n";
        }
        if(ui->checkBox_2->isChecked() == true)
        {
            QVector<double> C1Vlongitude_save = C1Vlongitude_bk + C1Vlongitude;
            dataOut<<tr("<经度,")<<C1Vlongitude_save.size()<<">"<<"\n";
            for(int i = 0;i<C1Vlongitude_save.size();i++)
            {
                progressDialog->setValue(C1VlatitudeNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1Vlongitude_save[i]<<",";
            }
            dataOut<<tr("\n</经度>")<<"\n";
        }
        if(ui->checkBox_73->isChecked() == true)
        {
            QVector<double> C6UndampedLatFloat_save = C6VC6UndampedLatFloat_bk + C6VC6UndampedLatFloat;
            dataOut<<tr("<无阻尼纬度,")<<C6UndampedLatFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedLatFloat_save.size();i++)
            {
                progressDialog->setValue(C1VlatitudeNum+C1VlongitudeNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedLatFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼纬度>")<<"\n";
        }
        if(ui->checkBox_74->isChecked() == true)
        {
            QVector<double> C6UndampedLongFloat_save = C6VC6UndampedLongFloat_bk + C6VC6UndampedLongFloat;
            dataOut<<tr("<无阻尼经度,")<<C6UndampedLongFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedLongFloat_save.size();i++)
            {
                progressDialog->setValue(C1VlatitudeNum+C1VlongitudeNum+C6UndampedLatFloatNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedLongFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼经度>")<<"\n";
        }
        if(ui->checkBox_75->isChecked() == true)
        {
            QVector<double> C6UndampedHeightFloat_save = C6VC6UndampedHeightFloat_bk + C6VC6UndampedHeightFloat;
            dataOut<<tr("<无阻尼高度,")<<C6UndampedHeightFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedHeightFloat_save.size();i++)
            {
                progressDialog->setValue(C1VlatitudeNum+C1VlongitudeNum+C6UndampedLatFloatNum+C6UndampedLongFloatNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedHeightFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼高度>")<<"\n";
        }
    }

    if(1)//保存航姿曲线
    {
        int C1VheadingAngularNum = 0;
        int C1VrollAngleNum = 0;
         int C1VpitchAngleNum = 0;
         int C6UndampedRollAngleFloatNum = 0;
         int C6UndampedPitchAngleFloatNum = 0;
         int C6UndampedHeadingAngularFloatNum = 0;

        if(ui->checkBox_5->isChecked() == true)
            C1VheadingAngularNum += C1VheadingAngle_bk.size() + C1VheadingAngle.size();
        if(ui->checkBox_3->isChecked() == true)
            C1VrollAngleNum += C1VrollAngle_bk.size() + C1VrollAngle.size();
        if(ui->checkBox_4->isChecked() == true)
            C1VpitchAngleNum += C1VpitchAngle_bk.size() + C1VpitchAngle.size();

        if(ui->checkBox_79->isChecked() == true)
            C6UndampedRollAngleFloatNum += C6VC6UndampedRollAngleFloat_bk.size() + C6VC6UndampedRollAngleFloat.size();
        if(ui->checkBox_80->isChecked() == true)
            C6UndampedPitchAngleFloatNum += C6VC6UndampedPitchAngleFloat_bk.size() + C6VC6UndampedPitchAngleFloat.size();
        if(ui->checkBox_81->isChecked() == true)
            C6UndampedHeadingAngularFloatNum += C6VC6UndampedHeadingAngularFloat_bk.size() + C6VC6UndampedHeadingAngularFloat.size();
        progressDialog->setRange(0, C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+C6UndampedRollAngleFloatNum+C6UndampedPitchAngleFloatNum+C6UndampedHeadingAngularFloatNum);
        if(ui->checkBox_5->isChecked() == true)
        {

            QVector<double> C1VheadingAngular_save = C1VheadingAngle_bk + C1VheadingAngle;
            dataOut<<tr("<航向,")<<C1VheadingAngular_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VheadingAngular_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VheadingAngular_save[i]<<",";
            }
            dataOut<<tr("\n</航向>")<<"\n";
        }
        if(ui->checkBox_3->isChecked() == true)
        {
            QVector<double> C1VrollAngle_save = C1VrollAngle_bk + C1VrollAngle;
            dataOut<<tr("<横摇角,")<<C1VrollAngle_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VrollAngle_save.size();i++)
            {
                progressDialog->setValue(C1VheadingAngularNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VrollAngle_save[i]<<",";
            }
            dataOut<<tr("\n</横摇角>")<<"\n";
        }
        if(ui->checkBox_4->isChecked() == true)
        {
            QVector<double> C1VpitchAngle_save = C1VpitchAngle_bk + C1VpitchAngle;
            dataOut<<tr("<纵摇角,")<<C1VpitchAngle_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VpitchAngle_save.size();i++)
            {
                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VpitchAngle_save[i]<<",";
            }
            dataOut<<tr("\n</纵摇角>")<<"\n";
        }

        if(ui->checkBox_79->isChecked() == true)
        {
            QVector<double> C6UndampedRollAngleFloat_save = C6VC6UndampedRollAngleFloat_bk + C6VC6UndampedRollAngleFloat;
            dataOut<<tr("<无阻尼横摇角,")<<C6UndampedRollAngleFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedRollAngleFloat_save.size();i++)
            {
                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedRollAngleFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼横摇角>")<<"\n";
        }
        if(ui->checkBox_80->isChecked() == true)
        {
            QVector<double> C6UndampedPitchAngleFloat_save = C6VC6UndampedPitchAngleFloat_bk + C6VC6UndampedPitchAngleFloat;
            dataOut<<tr("<无阻尼纵摇角,")<<C6UndampedPitchAngleFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedPitchAngleFloat_save.size();i++)
            {
                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+C6UndampedRollAngleFloatNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedPitchAngleFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼纵摇角>")<<"\n";
        }
        if(ui->checkBox_81->isChecked() == true)
        {
            QVector<double> C6UndampedHeadingAngularFloat_save = C6VC6UndampedHeadingAngularFloat_bk + C6VC6UndampedHeadingAngularFloat;
            dataOut<<tr("<无阻尼航向角,")<<C6UndampedHeadingAngularFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedHeadingAngularFloat_save.size();i++)
            {
                progressDialog->setValue(C1VheadingAngularNum+C1VrollAngleNum+C1VpitchAngleNum+C6UndampedRollAngleFloatNum+C6UndampedPitchAngleFloatNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedHeadingAngularFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼航向角>")<<"\n";
        }
    }

    if(1)//保存姿态角速度线
    {
        int C1VheadingAngularSpeedNum = 0;
        int C1VrollAngleSpeedNum = 0;
         int C1VpitchAngleSpeedNum = 0;

        if(ui->checkBox_6->isChecked() == true)
            C1VheadingAngularSpeedNum += C1VheadingAngularSpeed_bk.size() + C1VheadingAngularSpeed.size();
        if(ui->checkBox_7->isChecked() == true)
            C1VrollAngleSpeedNum += C1VrollAngleSpeed_bk.size() + C1VrollAngleSpeed.size();
        if(ui->checkBox_8->isChecked() == true)
            C1VpitchAngleSpeedNum += C1VpitchAngleSpeed_bk.size() + C1VpitchAngleSpeed.size();
        progressDialog->setRange(0, C1VheadingAngularSpeedNum+C1VrollAngleSpeedNum+C1VpitchAngleSpeedNum);
        if(ui->checkBox_6->isChecked() == true)
        {

            QVector<double> C1VheadingAngularSpeed_save = C1VheadingAngularSpeed_bk + C1VheadingAngularSpeed;
            dataOut<<tr("<航向角速度,")<<C1VheadingAngularSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VheadingAngularSpeed_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VheadingAngularSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</航向角速度>")<<"\n";
        }
        if(ui->checkBox_7->isChecked() == true)
        {
            QVector<double> C1VrollAngleSpeed_save = C1VrollAngleSpeed_bk + C1VrollAngleSpeed;
            dataOut<<tr("<横摇角速度,")<<C1VrollAngleSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VrollAngleSpeed_save.size();i++)
            {
                progressDialog->setValue(C1VheadingAngularSpeedNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VrollAngleSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</横摇角速度>")<<"\n";
        }
        if(ui->checkBox_8->isChecked() == true)
        {
            QVector<double> C1VpitchAngleSpeed_save = C1VpitchAngleSpeed_bk + C1VpitchAngleSpeed;
            dataOut<<tr("<纵摇角速度,")<<C1VpitchAngleSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VpitchAngleSpeed_save.size();i++)
            {
                progressDialog->setValue(C1VheadingAngularSpeedNum+C1VpitchAngleSpeedNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri);
                    qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VpitchAngleSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</纵摇角速度>")<<"\n";
        }

    }

    if(1)//保存速度曲线
    {
        int C1VnorthSpeedNum = 0;
        int C1VeastSpeedNum = 0;
        int C6UndampedNorthSpeedFloatNum = 0;
        int C6UndampedEastSpeedFloatNum = 0;
        int C6VerticalVelocityFloatNum = 0;

        if(ui->checkBox_9->isChecked() == true)
            C1VnorthSpeedNum += C1VnorthSpeed_bk.size() + C1VnorthSpeed.size();
        if(ui->checkBox_10->isChecked() == true)
            C1VeastSpeedNum += C1VeastSpeed_bk.size() + C1VeastSpeed.size();
        if(ui->checkBox_76->isChecked() == true)
            C6UndampedNorthSpeedFloatNum += C6VC6UndampedNorthSpeedFloat_bk.size() + C6VC6UndampedNorthSpeedFloat.size();
        if(ui->checkBox_77->isChecked() == true)
            C6UndampedEastSpeedFloatNum += C6VC6UndampedEastSpeedFloat_bk.size() + C6VC6UndampedEastSpeedFloat.size();
        if(ui->checkBox_78->isChecked() == true)
            C6VerticalVelocityFloatNum += C6VC6VerticalVelocityFloat_bk.size() + C6VC6VerticalVelocityFloat.size();
        progressDialog->setRange(0, C1VnorthSpeedNum+C1VeastSpeedNum+C6UndampedNorthSpeedFloatNum+C6UndampedEastSpeedFloatNum+C6VerticalVelocityFloatNum);
        if(ui->checkBox_9->isChecked() == true)
        {

            QVector<double> C1VnorthSpeed_save = C1VnorthSpeed_bk + C1VnorthSpeed;
            dataOut<<tr("<北速,")<<C1VnorthSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VnorthSpeed_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VnorthSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</北速>")<<"\n";
        }
        if(ui->checkBox_10->isChecked() == true)
        {
            QVector<double> C1VeastSpeed_save = C1VeastSpeed_bk + C1VeastSpeed;
            dataOut<<tr("<东速,")<<C1VeastSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C1VeastSpeed_save.size();i++)
            {
                progressDialog->setValue(C1VnorthSpeedNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C1VeastSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</东速>")<<"\n";
        }
        if(ui->checkBox_76->isChecked() == true)
        {
            QVector<double> C6UndampedNorthSpeedFloat_save = C6VC6UndampedNorthSpeedFloat_bk + C6VC6UndampedNorthSpeedFloat;
            dataOut<<tr("<无阻尼北速,")<<C6UndampedNorthSpeedFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedNorthSpeedFloat_save.size();i++)
            {
                progressDialog->setValue(C1VnorthSpeedNum+C1VeastSpeedNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedNorthSpeedFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼北速>")<<"\n";
        }
        if(ui->checkBox_77->isChecked() == true)
        {
            QVector<double> C6UndampedEastSpeedFloat_save = C6VC6UndampedEastSpeedFloat_bk + C6VC6UndampedEastSpeedFloat;
            dataOut<<tr("<无阻尼东速,")<<C6UndampedEastSpeedFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6UndampedEastSpeedFloat_save.size();i++)
            {
                progressDialog->setValue(C1VnorthSpeedNum+C1VeastSpeedNum+C6UndampedNorthSpeedFloatNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6UndampedEastSpeedFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼东速>")<<"\n";
        }
        if(ui->checkBox_78->isChecked() == true)
        {
            QVector<double> C6VerticalVelocityFloat_save = C6VC6VerticalVelocityFloat_bk + C6VC6VerticalVelocityFloat;
            dataOut<<tr("<无阻尼垂速,")<<C6VerticalVelocityFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6VerticalVelocityFloat_save.size();i++)
            {
                progressDialog->setValue(C1VnorthSpeedNum+C1VeastSpeedNum+C6UndampedNorthSpeedFloatNum+C6UndampedEastSpeedFloatNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6VerticalVelocityFloat_save[i]<<",";
            }
            dataOut<<tr("\n</无阻尼垂速>")<<"\n";
        }
    }

    if(0)//不显示增量、补偿增量和差频（原始脉冲）曲线2022-01-20
    {
        if(1)//保存瞬时线运动曲线
        {
            int C1VheaveNum = 0;
            int C1VverticalVelocityNum = 0;
            int C1VswayNum = 0;
            int C1VtransverseVelocityNum = 0;
            int C1VsurgeNum = 0;
            int C1VlongitudinalVelocityNum = 0;
            if(ui->checkBox_12->isChecked() == true)
                C1VheaveNum += C1Vheave_bk.size() + C1Vheave.size();
            if(ui->checkBox_13->isChecked() == true)
                C1VverticalVelocityNum += C1VverticalVelocity_bk.size() + C1VverticalVelocity.size();
            if(ui->checkBox_11->isChecked() == true)
                C1VswayNum += C1Vsway_bk.size() + C1Vsway.size();

            if(ui->checkBox_15->isChecked() == true)
                C1VheaveNum += C1VtransverseVelocity_bk.size() + C1VtransverseVelocity.size();
            if(ui->checkBox_16->isChecked() == true)
                C1VverticalVelocityNum += C1Vsurge_bk.size() + C1Vsurge.size();
            if(ui->checkBox_14->isChecked() == true)
                C1VswayNum += C1VlongitudinalVelocity_bk.size() + C1VlongitudinalVelocity.size();
            progressDialog->setRange(0, C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+C1VtransverseVelocityNum+C1VsurgeNum+C1VlongitudinalVelocityNum);
            if(ui->checkBox_12->isChecked() == true)
            {

                QVector<double> C1Vheave_save = C1Vheave_bk + C1Vheave;
                dataOut<<tr("<垂荡,")<<C1Vheave_save.size()<<">"<<"\n";
                for(int i = 0;i<C1Vheave_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C1Vheave_save[i]<<",";
                }
                dataOut<<tr("\n</垂荡>")<<"\n";
            }
            if(ui->checkBox_13->isChecked() == true)
            {
                QVector<double> C1VverticalVelocity_save = C1VverticalVelocity_bk + C1VverticalVelocity;
                dataOut<<tr("<垂速,")<<C1VverticalVelocity_save.size()<<">"<<"\n";
                for(int i = 0;i<C1VverticalVelocity_save.size();i++)
                {
                    progressDialog->setValue(C1VheaveNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C1VverticalVelocity_save[i]<<",";
                }
                dataOut<<tr("\n</垂速>")<<"\n";
            }
            if(ui->checkBox_11->isChecked() == true)
            {
                QVector<double> C1Vsway_save = C1Vsway_bk + C1Vsway;
                dataOut<<tr("<横荡,")<<C1Vsway_save.size()<<">"<<"\n";
                for(int i = 0;i<C1Vsway_save.size();i++)
                {
                    progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C1Vsway_save[i]<<",";
                }
                dataOut<<tr("\n</横荡>")<<"\n";
            }
            if(ui->checkBox_15->isChecked() == true)
            {
                QVector<double> C1VtransverseVelocity_save = C1VtransverseVelocity_bk + C1VtransverseVelocity;
                dataOut<<tr("<横速,")<<C1VtransverseVelocity_save.size()<<">"<<"\n";
                for(int i = 0;i<C1VtransverseVelocity_save.size();i++)
                {
                    progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C1VtransverseVelocity_save[i]<<",";
                }
                dataOut<<tr("\n</横速>")<<"\n";
            }
            if(ui->checkBox_16->isChecked() == true)
            {
                QVector<double> C1Vsurge_save = C1Vsurge_bk + C1Vsurge;
                dataOut<<tr("<纵荡,")<<C1Vsurge_save.size()<<">"<<"\n";
                for(int i = 0;i<C1Vsurge_save.size();i++)
                {
                    progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+C1VtransverseVelocityNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C1Vsurge_save[i]<<",";
                }
                dataOut<<tr("\n</纵荡>")<<"\n";
            }
            if(ui->checkBox_14->isChecked() == true)
            {
                QVector<double> C1VlongitudinalVelocity_save = C1VlongitudinalVelocity_bk + C1VlongitudinalVelocity;
                dataOut<<tr("<纵速,")<<C1VlongitudinalVelocity_save.size()<<">"<<"\n";
                for(int i = 0;i<C1VlongitudinalVelocity_save.size();i++)
                {
                    progressDialog->setValue(C1VheaveNum+C1VverticalVelocityNum+C1VswayNum+C1VtransverseVelocityNum+C1VsurgeNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C1VlongitudinalVelocity_save[i]<<",";
                }
                dataOut<<tr("\n</纵速>")<<"\n";
            }

        }

        if(1)//保存陀螺增量曲线
        {
            int C5VXGyroAngleIncreaseFloatNum = 0;
            int C5VYGyroAngleIncreaseFloatNum = 0;
            int C5VZGyroAngleIncreaseFloatNum = 0;

            if(ui->checkBox_19->isChecked() == true)
                C5VXGyroAngleIncreaseFloatNum += C5VXGyroAngleIncreaseFloat_bk.size() + C5VXGyroAngleIncreaseFloat.size();
            if(ui->checkBox_18->isChecked() == true)
                C5VYGyroAngleIncreaseFloatNum += C5VYGyroAngleIncreaseFloat_bk.size() + C5VYGyroAngleIncreaseFloat.size();
            if(ui->checkBox_17->isChecked() == true)
                C5VZGyroAngleIncreaseFloatNum += C5VZGyroAngleIncreaseFloat_bk.size() + C5VZGyroAngleIncreaseFloat.size();
            progressDialog->setRange(0, C5VXGyroAngleIncreaseFloatNum+C5VYGyroAngleIncreaseFloatNum+C5VZGyroAngleIncreaseFloatNum);
            if(ui->checkBox_19->isChecked() == true)
            {

                QVector<double> C5VXGyroAngleIncreaseFloat_save = C5VXGyroAngleIncreaseFloat_bk + C5VXGyroAngleIncreaseFloat;
                dataOut<<tr("<X陀螺增量,")<<C5VXGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VXGyroAngleIncreaseFloat_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VXGyroAngleIncreaseFloat_save[i]<<",";
                }
                dataOut<<tr("\n</X陀螺增量>")<<"\n";
            }
            if(ui->checkBox_18->isChecked() == true)
            {
                QVector<double> C5VYGyroAngleIncreaseFloat_save = C5VYGyroAngleIncreaseFloat_bk + C5VYGyroAngleIncreaseFloat;
                dataOut<<tr("<Y陀螺增量,")<<C5VYGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VYGyroAngleIncreaseFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXGyroAngleIncreaseFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VYGyroAngleIncreaseFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Y陀螺增量>")<<"\n";
            }
            if(ui->checkBox_17->isChecked() == true)
            {
                QVector<double> C5VZGyroAngleIncreaseFloat_save = C5VZGyroAngleIncreaseFloat_bk + C5VZGyroAngleIncreaseFloat;
                dataOut<<tr("<Z陀螺增量,")<<C5VZGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VZGyroAngleIncreaseFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXGyroAngleIncreaseFloatNum+C5VYGyroAngleIncreaseFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VZGyroAngleIncreaseFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Z陀螺增量>")<<"\n";
            }

        }

        if(1)//保存加表增量曲线
        {
            int C5VXAccelerometerSpeedIncrementFloatNum = 0;
            int C5VYAccelerometerSpeedIncrementFloatNum = 0;
            int C5VZAccelerometerSpeedIncrementFloatNum = 0;

            if(ui->checkBox_20->isChecked() == true)
                C5VXAccelerometerSpeedIncrementFloatNum += C5VXAccelerometerSpeedIncrementFloat_bk.size() + C5VXAccelerometerSpeedIncrementFloat.size();
            if(ui->checkBox_21->isChecked() == true)
                C5VYAccelerometerSpeedIncrementFloatNum += C5VYAccelerometerSpeedIncrementFloat_bk.size() + C5VYAccelerometerSpeedIncrementFloat.size();
            if(ui->checkBox_22->isChecked() == true)
                C5VZAccelerometerSpeedIncrementFloatNum += C5VZAccelerometerSpeedIncrementFloat_bk.size() + C5VZAccelerometerSpeedIncrementFloat.size();
            progressDialog->setRange(0, C5VXAccelerometerSpeedIncrementFloatNum+C5VYAccelerometerSpeedIncrementFloatNum+C5VZAccelerometerSpeedIncrementFloatNum);
            if(ui->checkBox_20->isChecked() == true)
            {

                QVector<double> C5VXAccelerometerSpeedIncrementFloat_save = C5VXAccelerometerSpeedIncrementFloat_bk + C5VXAccelerometerSpeedIncrementFloat;
                dataOut<<tr("<X加表增量,")<<C5VXAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VXAccelerometerSpeedIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VXAccelerometerSpeedIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</X加表增量>")<<"\n";
            }
            if(ui->checkBox_21->isChecked() == true)
            {
                QVector<double> C5VYAccelerometerSpeedIncrementFloat_save = C5VYAccelerometerSpeedIncrementFloat_bk + C5VYAccelerometerSpeedIncrementFloat;
                dataOut<<tr("<Y加表增量,")<<C5VYAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VYAccelerometerSpeedIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXAccelerometerSpeedIncrementFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VYAccelerometerSpeedIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Y加表增量>")<<"\n";
            }
            if(ui->checkBox_22->isChecked() == true)
            {
                QVector<double> C5VZAccelerometerSpeedIncrementFloat_save = C5VZAccelerometerSpeedIncrementFloat_bk + C5VZAccelerometerSpeedIncrementFloat;
                dataOut<<tr("<Z加表增量,")<<C5VZAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VZAccelerometerSpeedIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXAccelerometerSpeedIncrementFloatNum+C5VZAccelerometerSpeedIncrementFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VZAccelerometerSpeedIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Z加表增量>")<<"\n";
            }

        }

        if(1)//保存陀螺1s补偿后角增量曲线
        {
            int C5VXgyroCompensatedAngleIncrementFloatNum = 0;
            int C5VYgyroCompensatedAngleIncrementFloatNum = 0;
            int C5VZgyroCompensatedAngleIncrementFloatNum = 0;

            if(ui->checkBox_23->isChecked() == true)
                C5VXgyroCompensatedAngleIncrementFloatNum += C5VXgyroCompensatedAngleIncrementFloat_bk.size() + C5VXgyroCompensatedAngleIncrementFloat.size();
            if(ui->checkBox_24->isChecked() == true)
                C5VYgyroCompensatedAngleIncrementFloatNum += C5VYgyroCompensatedAngleIncrementFloat_bk.size() + C5VYgyroCompensatedAngleIncrementFloat.size();
            if(ui->checkBox_25->isChecked() == true)
                C5VZgyroCompensatedAngleIncrementFloatNum += C5VZgyroCompensatedAngleIncrementFloat_bk.size() + C5VZgyroCompensatedAngleIncrementFloat.size();
            progressDialog->setRange(0, C5VXgyroCompensatedAngleIncrementFloatNum+C5VYgyroCompensatedAngleIncrementFloatNum+C5VZgyroCompensatedAngleIncrementFloatNum);
            if(ui->checkBox_23->isChecked() == true)
            {

                QVector<double> C5VXgyroCompensatedAngleIncrementFloat_save = C5VXgyroCompensatedAngleIncrementFloat_bk + C5VXgyroCompensatedAngleIncrementFloat;
                dataOut<<tr("<x陀螺1s补偿后角增量,")<<C5VXgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VXgyroCompensatedAngleIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VXgyroCompensatedAngleIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</x陀螺1s补偿后角增量>")<<"\n";
            }
            if(ui->checkBox_24->isChecked() == true)
            {
                QVector<double> C5VYgyroCompensatedAngleIncrementFloat_save = C5VYgyroCompensatedAngleIncrementFloat_bk + C5VYgyroCompensatedAngleIncrementFloat;
                dataOut<<tr("<Y陀螺1s补偿后角增量,")<<C5VYgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VYgyroCompensatedAngleIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXgyroCompensatedAngleIncrementFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VYgyroCompensatedAngleIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Y陀螺1s补偿后角增量>")<<"\n";
            }
            if(ui->checkBox_25->isChecked() == true)
            {
                QVector<double> C5VZgyroCompensatedAngleIncrementFloat_save = C5VZgyroCompensatedAngleIncrementFloat_bk + C5VZgyroCompensatedAngleIncrementFloat;
                dataOut<<tr("<Z陀螺1s补偿后角增量,")<<C5VZgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VZgyroCompensatedAngleIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXgyroCompensatedAngleIncrementFloatNum+C5VYgyroCompensatedAngleIncrementFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VZgyroCompensatedAngleIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Z陀螺1s补偿后角增量>")<<"\n";
            }

        }

        if(1)//保存加表1s补偿后角增量曲线
        {
            int C5VXAccVelocityIncrementFloatNum = 0;
            int C5VYAccVelocityIncrementFloatNum = 0;
            int C5VZAccVelocityIncrementFloatNum = 0;

            if(ui->checkBox_26->isChecked() == true)
                C5VXAccVelocityIncrementFloatNum += C5VXAccVelocityIncrementFloat_bk.size() + C5VXAccVelocityIncrementFloat.size();
            if(ui->checkBox_27->isChecked() == true)
                C5VYAccVelocityIncrementFloatNum += C5VYAccVelocityIncrementFloat_bk.size() + C5VYAccVelocityIncrementFloat.size();
            if(ui->checkBox_28->isChecked() == true)
                C5VZAccVelocityIncrementFloatNum += C5VZAccVelocityIncrementFloat_bk.size() + C5VZAccVelocityIncrementFloat.size();
            progressDialog->setRange(0, C5VXAccVelocityIncrementFloatNum+C5VYAccVelocityIncrementFloatNum+C5VZAccVelocityIncrementFloatNum);
            if(ui->checkBox_26->isChecked() == true)
            {

                QVector<double> C5VXAccVelocityIncrementFloat_save = C5VXAccVelocityIncrementFloat_bk + C5VXAccVelocityIncrementFloat;
                dataOut<<tr("<x加速度计1s补偿后速度增量,")<<C5VXAccVelocityIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VXAccVelocityIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VXAccVelocityIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</x加速度计1s补偿后速度增量>")<<"\n";
            }
            if(ui->checkBox_27->isChecked() == true)
            {
                QVector<double> C5VYAccVelocityIncrementFloat_save = C5VYAccVelocityIncrementFloat_bk + C5VYAccVelocityIncrementFloat;
                dataOut<<tr("<Y加速度计1s补偿后速度增量,")<<C5VYAccVelocityIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VYAccVelocityIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXAccVelocityIncrementFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VYAccVelocityIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Y加速度计1s补偿后速度增量>")<<"\n";
            }
            if(ui->checkBox_28->isChecked() == true)
            {
                QVector<double> C5VZAccVelocityIncrementFloat_save = C5VZAccVelocityIncrementFloat_bk + C5VZAccVelocityIncrementFloat;
                dataOut<<tr("<Z加速度计1s补偿后速度增量,")<<C5VZAccVelocityIncrementFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VZAccVelocityIncrementFloat_save.size();i++)
                {
                    progressDialog->setValue(C5VXAccVelocityIncrementFloatNum+C5VYAccVelocityIncrementFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VZAccVelocityIncrementFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Z加速度计1s补偿后速度增量>")<<"\n";
            }

        }

        if(1)//保存陀螺差频曲线
        {
            int C5VXgyroDifFrequencyNum = 0;
            int C5VYgyroDifFrequencyNum = 0;
            int C5VZgyroDifFrequencyNum = 0;

            if(ui->checkBox_29->isChecked() == true)
                C5VXgyroDifFrequencyNum += C5VXgyroDifFrequency_bk.size() + C5VXgyroDifFrequency.size();
            if(ui->checkBox_31->isChecked() == true)
                C5VYgyroDifFrequencyNum += C5VYgyroDifFrequency_bk.size() + C5VYgyroDifFrequency.size();
            if(ui->checkBox_30->isChecked() == true)
                C5VZgyroDifFrequencyNum += C5VZgyroDifFrequency_bk.size() + C5VZgyroDifFrequency.size();
            progressDialog->setRange(0, C5VXgyroDifFrequencyNum+C5VYgyroDifFrequencyNum+C5VZgyroDifFrequencyNum);
            if(ui->checkBox_29->isChecked() == true)
            {

                QVector<double> C5VXgyroDifFrequency_save = C5VXgyroDifFrequency_bk + C5VXgyroDifFrequency;
                dataOut<<tr("<X陀螺差频,")<<C5VXgyroDifFrequency_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VXgyroDifFrequency_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VXgyroDifFrequency_save[i]<<",";
                }
                dataOut<<tr("\n</X陀螺差频>")<<"\n";
            }
            if(ui->checkBox_31->isChecked() == true)
            {
                QVector<double> C5VYgyroDifFrequency_save = C5VYgyroDifFrequency_bk + C5VYgyroDifFrequency;
                dataOut<<tr("<Y陀螺差频,")<<C5VYgyroDifFrequency_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VYgyroDifFrequency_save.size();i++)
                {
                    progressDialog->setValue(C5VXgyroDifFrequencyNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VYgyroDifFrequency_save[i]<<",";
                }
                dataOut<<tr("\n</Y陀螺差频>")<<"\n";
            }
            if(ui->checkBox_30->isChecked() == true)
            {
                QVector<double> C5VZgyroDifFrequency_save = C5VZgyroDifFrequency_bk + C5VZgyroDifFrequency;
                dataOut<<tr("<Z陀螺差频,")<<C5VZgyroDifFrequency_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VZgyroDifFrequency_save.size();i++)
                {
                    progressDialog->setValue(C5VXgyroDifFrequencyNum+C5VYgyroDifFrequencyNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VZgyroDifFrequency_save[i]<<",";
                }
                dataOut<<tr("\n</Z陀螺差频>")<<"\n";
            }

        }

        if(1)//保存加速度计差频曲线
        {
            int C5VXaccelerometerDifFreNum = 0;
            int C5VYaccelerometerDifFreNum = 0;
            int C5VZaccelerometerDifFreNum = 0;

            if(ui->checkBox_32->isChecked() == true)
                C5VXaccelerometerDifFreNum += C5VXaccelerometerDifFre_bk.size() + C5VXaccelerometerDifFre.size();
            if(ui->checkBox_33->isChecked() == true)
                C5VYaccelerometerDifFreNum += C5VYaccelerometerDifFre_bk.size() + C5VYaccelerometerDifFre.size();
            if(ui->checkBox_34->isChecked() == true)
                C5VZaccelerometerDifFreNum += C5VZaccelerometerDifFre_bk.size() + C5VZaccelerometerDifFre.size();
            progressDialog->setRange(0, C5VXaccelerometerDifFreNum+C5VYaccelerometerDifFreNum+C5VZaccelerometerDifFreNum);
            if(ui->checkBox_32->isChecked() == true)
            {
                QVector<double> C5VXaccelerometerDifFre_save = C5VXaccelerometerDifFre_bk + C5VXaccelerometerDifFre;
                dataOut<<tr("<X加速度计差频,")<<C5VXaccelerometerDifFre_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VXaccelerometerDifFre_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VXaccelerometerDifFre_save[i]<<",";
                }
                dataOut<<tr("\n</X加速度计差频>")<<"\n";
            }
            if(ui->checkBox_33->isChecked() == true)
            {
                QVector<double> C5VYaccelerometerDifFre_save = C5VYaccelerometerDifFre_bk + C5VYaccelerometerDifFre;
                dataOut<<tr("<Y加速度计差频,")<<C5VYaccelerometerDifFre_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VYaccelerometerDifFre_save.size();i++)
                {
                    progressDialog->setValue(C5VXaccelerometerDifFreNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VYaccelerometerDifFre_save[i]<<",";
                }
                dataOut<<tr("\n</Y加速度计差频>")<<"\n";
            }
            if(ui->checkBox_34->isChecked() == true)
            {
                QVector<double> C5VZaccelerometerDifFre_save = C5VZaccelerometerDifFre_bk + C5VZaccelerometerDifFre;
                dataOut<<tr("<Z加速度计差频,")<<C5VZaccelerometerDifFre_save.size()<<">"<<"\n";
                for(int i = 0;i<C5VZaccelerometerDifFre_save.size();i++)
                {
                    progressDialog->setValue(C5VXaccelerometerDifFreNum+C5VYaccelerometerDifFreNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C5VZaccelerometerDifFre_save[i]<<",";
                }
                dataOut<<tr("\n</Z加速度计差频>")<<"\n";
            }

        }
    }
    if(1)//保存陀螺温度1曲线
    {
        int C5VXgyroTemp1Num = 0;
        int C5VYgyroTemp1Num = 0;
         int C5VZgyroTemp1Num = 0;

        if(ui->checkBox_37->isChecked() == true)
            C5VXgyroTemp1Num += C5VXgyroTemp1_bk.size() + C5VXgyroTemp1.size();
        if(ui->checkBox_35->isChecked() == true)
            C5VYgyroTemp1Num += C5VYgyroTemp1_bk.size() + C5VYgyroTemp1.size();
        if(ui->checkBox_36->isChecked() == true)
            C5VZgyroTemp1Num += C5VZgyroTemp1_bk.size() + C5VZgyroTemp1.size();
        progressDialog->setRange(0, C5VXgyroTemp1Num+C5VYgyroTemp1Num+C5VZgyroTemp1Num);
        if(ui->checkBox_37->isChecked() == true)
        {
            QVector<double> C5VXgyroTemp1_save = C5VXgyroTemp1_bk + C5VXgyroTemp1;
            dataOut<<tr("<X陀螺温度1,")<<C5VXgyroTemp1_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXgyroTemp1_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXgyroTemp1_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺温度1>")<<"\n";
        }
        if(ui->checkBox_35->isChecked() == true)
        {
            QVector<double> C5VYgyroTemp1_save = C5VYgyroTemp1_bk + C5VYgyroTemp1;
            dataOut<<tr("<Y陀螺温度1,")<<C5VYgyroTemp1_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYgyroTemp1_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroTemp1Num+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYgyroTemp1_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺温度1>")<<"\n";
        }
        if(ui->checkBox_36->isChecked() == true)
        {
            QVector<double> C5VZgyroTemp1_save = C5VZgyroTemp1_bk + C5VZgyroTemp1;
            dataOut<<tr("<Z陀螺温度1,")<<C5VZgyroTemp1_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZgyroTemp1_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroTemp1Num+C5VYgyroTemp1Num+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZgyroTemp1_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺温度1>")<<"\n";
        }

    }

    if(1)//保存加速度计温度1曲线
    {
        int C5VXAccelerometerTempertureNum = 0;
        int C5VYAccelerometerTempertureNum = 0;
         int C5VZAccelerometerTempertureNum = 0;

        if(ui->checkBox_40->isChecked() == true)
            C5VXAccelerometerTempertureNum += C5VXAccelerometerTemperture_bk.size() + C5VXAccelerometerTemperture.size();
        if(ui->checkBox_38->isChecked() == true)
            C5VYAccelerometerTempertureNum += C5VYAccelerometerTemperture_bk.size() + C5VYAccelerometerTemperture.size();
        if(ui->checkBox_39->isChecked() == true)
            C5VZAccelerometerTempertureNum += C5VZAccelerometerTemperture_bk.size() + C5VZAccelerometerTemperture.size();
        progressDialog->setRange(0, C5VXAccelerometerTempertureNum+C5VYAccelerometerTempertureNum+C5VZAccelerometerTempertureNum);
        if(ui->checkBox_40->isChecked() == true)
        {
            QVector<double> C5VXAccelerometerTemperture_save = C5VXAccelerometerTemperture_bk + C5VXAccelerometerTemperture;
            dataOut<<tr("<X加速度计温度1,")<<C5VXAccelerometerTemperture_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXAccelerometerTemperture_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXAccelerometerTemperture_save[i]<<",";
            }
            dataOut<<tr("\n</X加速度计温度1>")<<"\n";
        }
        if(ui->checkBox_38->isChecked() == true)
        {
            QVector<double> C5VYAccelerometerTemperture_save = C5VYAccelerometerTemperture_bk + C5VYAccelerometerTemperture;
            dataOut<<tr("<Y加速度计温度1,")<<C5VYAccelerometerTemperture_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYAccelerometerTemperture_save.size();i++)
            {
                progressDialog->setValue(C5VXAccelerometerTempertureNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYAccelerometerTemperture_save[i]<<",";
            }
            dataOut<<tr("\n</Y加速度计温度1>")<<"\n";
        }
        if(ui->checkBox_39->isChecked() == true)
        {
            QVector<double> C5VZAccelerometerTemperture_save = C5VZAccelerometerTemperture_bk + C5VZAccelerometerTemperture;
            dataOut<<tr("<Z陀螺温度1,")<<C5VZAccelerometerTemperture_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZAccelerometerTemperture_save.size();i++)
            {
                progressDialog->setValue(C5VXAccelerometerTempertureNum+C5VYAccelerometerTempertureNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZAccelerometerTemperture_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺温度1>")<<"\n";
        }

    }
    if(1)//保存陀螺温度2曲线
    {
        int C5VXgyroTemp2Num = 0;
        int C5VYgyroTemp2Num = 0;
         int C5VZgyroTemp2Num = 0;

        if(ui->checkBox_42->isChecked() == true)
            C5VXgyroTemp2Num += C5VXgyroTemp2_bk.size() + C5VXgyroTemp2.size();
        if(ui->checkBox_43->isChecked() == true)
            C5VYgyroTemp2Num += C5VYgyroTemp2_bk.size() + C5VYgyroTemp2.size();
        if(ui->checkBox_41->isChecked() == true)
            C5VZgyroTemp2Num += C5VZgyroTemp2_bk.size() + C5VZgyroTemp2.size();
        progressDialog->setRange(0, C5VXgyroTemp2Num+C5VYgyroTemp2Num+C5VZgyroTemp2Num);
        if(ui->checkBox_42->isChecked() == true)
        {
            QVector<double> C5VXgyroTemp2_save = C5VXgyroTemp2_bk + C5VXgyroTemp2;
            dataOut<<tr("<X陀螺温度2,")<<C5VXgyroTemp2_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXgyroTemp2_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXgyroTemp2_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺温度2>")<<"\n";
        }
        if(ui->checkBox_43->isChecked() == true)
        {
            QVector<double> C5VYgyroTemp2_save = C5VYgyroTemp2_bk + C5VYgyroTemp2;
            dataOut<<tr("<Y陀螺温度2,")<<C5VYgyroTemp2_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYgyroTemp2_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroTemp2Num+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYgyroTemp2_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺温度2>")<<"\n";
        }
        if(ui->checkBox_41->isChecked() == true)
        {
            QVector<double> C5VZgyroTemp2_save = C5VZgyroTemp2_bk + C5VZgyroTemp2;
            dataOut<<tr("<Z陀螺温度2,")<<C5VZgyroTemp2_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZgyroTemp2_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroTemp2Num+C5VYgyroTemp2Num+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZgyroTemp2_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺温度2>")<<"\n";
        }

    }
    if(1)//保存陀螺抖幅曲线
    {
        int C5VXgyroAmplitudeJitterNum = 0;
        int C5VYgyroAmplitudeJitterNum = 0;
         int C5VZgyroAmplitudeJitterNum = 0;

        if(ui->checkBox_45->isChecked() == true)
            C5VXgyroAmplitudeJitterNum += C5VXgyroAmplitudeJitter_bk.size() + C5VXgyroAmplitudeJitter.size();
        if(ui->checkBox_46->isChecked() == true)
            C5VYgyroAmplitudeJitterNum += C5VYgyroAmplitudeJitter_bk.size() + C5VYgyroAmplitudeJitter.size();
        if(ui->checkBox_44->isChecked() == true)
            C5VZgyroAmplitudeJitterNum += C5VZgyroAmplitudeJitter_bk.size() + C5VZgyroAmplitudeJitter.size();
        progressDialog->setRange(0, C5VXgyroAmplitudeJitterNum+C5VYgyroAmplitudeJitterNum+C5VZgyroAmplitudeJitterNum);
        if(ui->checkBox_45->isChecked() == true)
        {
            QVector<double> C5VXgyroAmplitudeJitter_save = C5VXgyroAmplitudeJitter_bk + C5VXgyroAmplitudeJitter;
            dataOut<<tr("<X陀螺抖幅,")<<C5VXgyroAmplitudeJitter_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXgyroAmplitudeJitter_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXgyroAmplitudeJitter_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺抖幅>")<<"\n";
        }
        if(ui->checkBox_46->isChecked() == true)
        {
            QVector<double> C5VYgyroAmplitudeJitter_save = C5VYgyroAmplitudeJitter_bk + C5VYgyroAmplitudeJitter;
            dataOut<<tr("<陀螺抖幅,")<<C5VYgyroAmplitudeJitter_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYgyroAmplitudeJitter_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroAmplitudeJitterNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYgyroAmplitudeJitter_save[i]<<",";
            }
            dataOut<<tr("\n</陀螺抖幅>")<<"\n";
        }
        if(ui->checkBox_44->isChecked() == true)
        {
            QVector<double> C5VZgyroAmplitudeJitter_save = C5VZgyroAmplitudeJitter_bk + C5VZgyroAmplitudeJitter;
            dataOut<<tr("<Z陀螺抖幅,")<<C5VZgyroAmplitudeJitter_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZgyroAmplitudeJitter_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroAmplitudeJitterNum+C5VYgyroAmplitudeJitterNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZgyroAmplitudeJitter_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺抖幅>")<<"\n";
        }

    }

    if(1)//保存陀螺抖频曲线
    {
        int C5VXgyroAmpl1itudeFreNum = 0;
        int C5VYgyroAmpl1itudeFreNum = 0;
         int C5VZgyroAmpl1itudeFreNum = 0;

        if(ui->checkBox_48->isChecked() == true)
            C5VXgyroAmpl1itudeFreNum += C5VXgyroAmpl1itudeFre_bk.size() + C5VXgyroAmpl1itudeFre.size();
        if(ui->checkBox_49->isChecked() == true)
            C5VYgyroAmpl1itudeFreNum += C5VYgyroAmpl1itudeFre_bk.size() + C5VYgyroAmpl1itudeFre.size();
        if(ui->checkBox_47->isChecked() == true)
            C5VZgyroAmpl1itudeFreNum += C5VZgyroAmpl1itudeFre_bk.size() + C5VZgyroAmpl1itudeFre.size();
        progressDialog->setRange(0, C5VXgyroAmpl1itudeFreNum+C5VYgyroAmpl1itudeFreNum+C5VZgyroAmpl1itudeFreNum);
        if(ui->checkBox_48->isChecked() == true)
        {
            QVector<double> C5VXgyroAmpl1itudeFre_save = C5VXgyroAmpl1itudeFre_bk + C5VXgyroAmpl1itudeFre;
            dataOut<<tr("<X陀螺抖频,")<<C5VXgyroAmpl1itudeFre_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXgyroAmpl1itudeFre_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXgyroAmpl1itudeFre_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺抖频>")<<"\n";
        }
        if(ui->checkBox_49->isChecked() == true)
        {
            QVector<double> C5VYgyroAmpl1itudeFre_save = C5VYgyroAmpl1itudeFre_bk + C5VYgyroAmpl1itudeFre;
            dataOut<<tr("<Y陀螺抖频,")<<C5VYgyroAmpl1itudeFre_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYgyroAmpl1itudeFre_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroAmpl1itudeFreNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYgyroAmpl1itudeFre_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺抖频>")<<"\n";
        }
        if(ui->checkBox_47->isChecked() == true)
        {
            QVector<double> C5VZgyroAmpl1itudeFre_save = C5VZgyroAmpl1itudeFre_bk + C5VZgyroAmpl1itudeFre;
            dataOut<<tr("<Z陀螺抖频,")<<C5VZgyroAmpl1itudeFre_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZgyroAmpl1itudeFre_save.size();i++)
            {
                progressDialog->setValue(C5VXgyroAmpl1itudeFreNum+C5VYgyroAmpl1itudeFreNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZgyroAmpl1itudeFre_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺抖频>")<<"\n";
        }

    }

    if(1)//保存卫导曲线
    {
        int C3VlongitudeNum = 0;
        int C3VGPSlatitudeNum = 0;
         int C3VtogetherSpeedNum = 0;
         int C3VheadingAngleNum = 0;
         int C3VcombinedEastSpeedNum = 0;
          int C3VcombinedNorthSpeedNum = 0;
        if(ui->checkBox_54->isChecked() == true)
            C3VlongitudeNum += C3Vlongitude_bk.size() + C3Vlongitude.size();
        if(ui->checkBox_51->isChecked() == true)
            C3VGPSlatitudeNum += C3VGPSlatitude_bk.size() + C3VGPSlatitude.size();
        if(ui->checkBox_50->isChecked() == true)
            C3VtogetherSpeedNum += C3VtogetherSpeed_bk.size() + C3VtogetherSpeed.size();

        if(ui->checkBox_52->isChecked() == true)
            C3VheadingAngleNum += C3VheadingAngle_bk.size() + C3VheadingAngle.size();
        if(ui->checkBox_53->isChecked() == true)
            C3VcombinedEastSpeedNum += C3VcombinedEastSpeed_bk.size() + C3VcombinedEastSpeed.size();
        if(ui->checkBox_60->isChecked() == true)
            C3VcombinedNorthSpeedNum += C3VcombinedNorthSpeed_bk.size() + C3VcombinedNorthSpeed.size();
        progressDialog->setRange(0, C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+C3VheadingAngleNum+C3VcombinedEastSpeedNum+C3VcombinedNorthSpeedNum);
        if(ui->checkBox_54->isChecked() == true)
        {

            QVector<double> C3Vlongitude_save = C3Vlongitude_bk + C3Vlongitude;
            dataOut<<tr("<GPS经度,")<<C3Vlongitude_save.size()<<">"<<"\n";
            for(int i = 0;i<C3Vlongitude_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3Vlongitude_save[i]<<",";
            }
            dataOut<<tr("\n</GPS经度>")<<"\n";
        }
        if(ui->checkBox_51->isChecked() == true)
        {
            QVector<double> C3VGPSlatitude_save = C3VGPSlatitude_bk + C3VGPSlatitude;
            dataOut<<tr("<GPS纬度,")<<C3VGPSlatitude_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VGPSlatitude_save.size();i++)
            {
                progressDialog->setValue(C3VlongitudeNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VGPSlatitude_save[i]<<",";
            }
            dataOut<<tr("\n</GPS纬度>")<<"\n";
        }
        if(ui->checkBox_50->isChecked() == true)
        {
            QVector<double> C3VtogetherSpeed_save = C3VtogetherSpeed_bk + C3VtogetherSpeed;
            dataOut<<tr("<GPS合速,")<<C3VtogetherSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VtogetherSpeed_save.size();i++)
            {
                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VtogetherSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</GPS合速>")<<"\n";
        }
        if(ui->checkBox_52->isChecked() == true)
        {
            QVector<double> C3VheadingAngle_save = C3VheadingAngle_bk + C3VheadingAngle;
            dataOut<<tr("<GPS航向,")<<C3VheadingAngle_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VheadingAngle_save.size();i++)
            {
                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VheadingAngle_save[i]<<",";
            }
            dataOut<<tr("\n</GPS航向>")<<"\n";
        }
        if(ui->checkBox_53->isChecked() == true)
        {
            QVector<double> C3VcombinedEastSpeed_save = C3VcombinedEastSpeed_bk + C3VcombinedEastSpeed;
            dataOut<<tr("<GPS东速,")<<C3VcombinedEastSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VcombinedEastSpeed_save.size();i++)
            {
                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+C3VheadingAngleNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VcombinedEastSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</GPS东速>")<<"\n";
        }
        if(ui->checkBox_60->isChecked() == true)
        {
            QVector<double> C3VcombinedNorthSpeed_save = C3VcombinedNorthSpeed_bk + C3VcombinedNorthSpeed;
            dataOut<<tr("<纵速,")<<C3VcombinedNorthSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VcombinedNorthSpeed_save.size();i++)
            {
                progressDialog->setValue(C3VlongitudeNum+C3VGPSlatitudeNum+C3VtogetherSpeedNum+C3VheadingAngleNum+C3VcombinedEastSpeedNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VcombinedNorthSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</纵速>")<<"\n";
        }

    }

    if(1)//保存计程仪曲线
    {
        int C3VwaterXNum = 0;
        int C3VwaterYNum = 0;
        int C3VbottomXNum = 0;
        int C3VbottomYNum = 0;
        int C3VelectromagnetismSpeedNum = 0;

        if(ui->checkBox_59->isChecked() == true)
            C3VwaterXNum += C3VwaterX_bk.size() + C3VwaterX.size();
        if(ui->checkBox_56->isChecked() == true)
            C3VwaterYNum += C3VwaterY_bk.size() + C3VwaterY.size();
        if(ui->checkBox_57->isChecked() == true)
            C3VbottomXNum += C3VbottomX_bk.size() + C3VbottomX.size();

        if(ui->checkBox_55->isChecked() == true)
            C3VbottomYNum += C3VbottomY_bk.size() + C3VbottomY.size();
        if(ui->checkBox_58->isChecked() == true)
            C3VelectromagnetismSpeedNum += C3VelectromagnetismSpeed_bk.size() + C3VelectromagnetismSpeed.size();
        progressDialog->setRange(0, C3VwaterXNum+C3VwaterYNum+C3VbottomXNum+C3VbottomYNum+C3VelectromagnetismSpeedNum);
        if(ui->checkBox_59->isChecked() == true)
        {

            QVector<double> C3VwaterX_save = C3VwaterX_bk + C3VwaterX;
            dataOut<<tr("<多普勒对水横向速度,")<<C3VwaterX_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VwaterX_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VwaterX_save[i]<<",";
            }
            dataOut<<tr("\n</多普勒对水横向速度>")<<"\n";
        }
        if(ui->checkBox_56->isChecked() == true)
        {
            QVector<double> C3VwaterY_save = C3VwaterY_bk + C3VwaterY;
            dataOut<<tr("<多普勒对水纵向速度,")<<C3VwaterY_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VwaterY_save.size();i++)
            {
                progressDialog->setValue(C3VwaterXNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VwaterY_save[i]<<",";
            }
            dataOut<<tr("\n</多普勒对水纵向速度>")<<"\n";
        }
        if(ui->checkBox_57->isChecked() == true)
        {
            QVector<double> C3VbottomX_save = C3VbottomX_bk + C3VbottomX;
            dataOut<<tr("<多普勒对底横向速度,")<<C3VbottomX_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VbottomX_save.size();i++)
            {
                progressDialog->setValue(C3VwaterXNum+C3VwaterYNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VbottomX_save[i]<<",";
            }
            dataOut<<tr("\n</多普勒对底横向速度>")<<"\n";
        }
        if(ui->checkBox_55->isChecked() == true)
        {
            QVector<double> C3VbottomY_save = C3VbottomY_bk + C3VbottomY;
            dataOut<<tr("<多普勒对底纵向速度,")<<C3VbottomY_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VbottomY_save.size();i++)
            {
                progressDialog->setValue(C3VwaterXNum+C3VwaterYNum+C3VbottomXNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VbottomY_save[i]<<",";
            }
            dataOut<<tr("\n</多普勒对底纵向速度>")<<"\n";
        }
        if(ui->checkBox_58->isChecked() == true)
        {
            QVector<double> C3VelectromagnetismSpeed_save = C3VelectromagnetismSpeed_bk + C3VelectromagnetismSpeed;
            dataOut<<tr("<电磁速度,")<<C3VelectromagnetismSpeed_save.size()<<">"<<"\n";
            for(int i = 0;i<C3VelectromagnetismSpeed_save.size();i++)
            {
                progressDialog->setValue(C3VwaterXNum+C3VwaterYNum+C3VbottomXNum+C3VbottomYNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C3VelectromagnetismSpeed_save[i]<<",";
            }
            dataOut<<tr("\n</电磁速度>")<<"\n";
        }
    }
    if(0)//不显示零偏曲线2022-01-20
    {
        if(1)//保存陀螺零偏曲线
        {
            int C6VC6XGroyFloatNum = 0;
            int C6VC6YGroyFloatNum = 0;
            int C6VC6ZGroyFloatNum = 0;

            if(ui->checkBox_61->isChecked() == true)
                C6VC6XGroyFloatNum += C6VC6XGroyFloat_bk.size() + C6VC6XGroyFloat.size();
            if(ui->checkBox_63->isChecked() == true)
                C6VC6YGroyFloatNum += C6VC6YGroyFloat_bk.size() + C6VC6YGroyFloat.size();
            if(ui->checkBox_62->isChecked() == true)
                C6VC6ZGroyFloatNum += C6VC6ZGroyFloat_bk.size() + C6VC6ZGroyFloat.size();
            progressDialog->setRange(0, C6VC6XGroyFloatNum+C6VC6YGroyFloatNum+C6VC6ZGroyFloatNum);
            if(ui->checkBox_61->isChecked() == true)
            {
                QVector<double> C6VC6XGroyFloat_save = C6VC6XGroyFloat_bk + C6VC6XGroyFloat;
                dataOut<<tr("<X陀螺零偏,")<<C6VC6XGroyFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C6VC6XGroyFloat_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
                        return;
                    }
                    dataOut<<C6VC6XGroyFloat_save[i]<<",";
                }
                dataOut<<tr("\n</X陀螺零偏>")<<"\n";
            }
            if(ui->checkBox_63->isChecked() == true)
            {
                QVector<double> C6VC6YGroyFloat_save = C6VC6YGroyFloat_bk + C6VC6YGroyFloat;
                dataOut<<tr("<Y陀螺零偏,")<<C6VC6YGroyFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C6VC6YGroyFloat_save.size();i++)
                {
                    progressDialog->setValue(C6VC6XGroyFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
                        return;
                    }
                    dataOut<<C6VC6YGroyFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Y陀螺零偏>")<<"\n";
            }
            if(ui->checkBox_62->isChecked() == true)
            {
                QVector<double> C6VC6ZGroyFloat_save = C6VC6ZGroyFloat_bk + C6VC6ZGroyFloat;
                dataOut<<tr("<Z陀螺零偏,")<<C6VC6ZGroyFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C6VC6ZGroyFloat_save.size();i++)
                {
                    progressDialog->setValue(C6VC6XGroyFloatNum+C6VC6YGroyFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
                        return;
                    }
                    dataOut<<C6VC6ZGroyFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Z陀螺零偏>")<<"\n";
            }
        }
        if(1)//保存加速度计零偏曲线
        {
            int C6VC6XAccelerometerFloatNum = 0;
            int C6VC6YAccelerometerFloatNum = 0;
            int C6VC6ZAccelerometerFloatNum = 0;

            if(ui->checkBox_65->isChecked() == true)
                C6VC6XAccelerometerFloatNum += C6VC6XAccelerometerFloat_bk.size() + C6VC6XAccelerometerFloat.size();
            if(ui->checkBox_64->isChecked() == true)
                C6VC6YAccelerometerFloatNum += C6VC6YAccelerometerFloat_bk.size() + C6VC6YAccelerometerFloat.size();
            if(ui->checkBox_66->isChecked() == true)
                C6VC6ZAccelerometerFloatNum += C6VC6ZAccelerometerFloat_bk.size() + C6VC6ZAccelerometerFloat.size();
            progressDialog->setRange(0, C6VC6XAccelerometerFloatNum+C6VC6YAccelerometerFloatNum+C6VC6ZAccelerometerFloatNum);
            if(ui->checkBox_65->isChecked() == true)
            {
                QVector<double> C6VC6XAccelerometerFloat_save = C6VC6XAccelerometerFloat_bk + C6VC6XAccelerometerFloat;
                dataOut<<tr("<X加速度计零偏,")<<C6VC6XAccelerometerFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C6VC6XAccelerometerFloat_save.size();i++)
                {
                    progressDialog->setValue(i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C6VC6XAccelerometerFloat_save[i]<<",";
                }
                dataOut<<tr("\n</X加速度计零偏>")<<"\n";
            }
            if(ui->checkBox_64->isChecked() == true)
            {
                QVector<double> C6VC6YAccelerometerFloat_save = C6VC6YAccelerometerFloat_bk + C6VC6YAccelerometerFloat;
                dataOut<<tr("<Y加速度计零偏,")<<C6VC6YAccelerometerFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C6VC6YAccelerometerFloat_save.size();i++)
                {
                    progressDialog->setValue(C6VC6XAccelerometerFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C6VC6YAccelerometerFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Y加速度计零偏>")<<"\n";
            }
            if(ui->checkBox_66->isChecked() == true)
            {
                QVector<double> C6VC6ZAccelerometerFloat_save = C6VC6ZAccelerometerFloat_bk + C6VC6ZAccelerometerFloat;
                dataOut<<tr("<Z加速度计零偏,")<<C6VC6ZAccelerometerFloat_save.size()<<">"<<"\n";
                for(int i = 0;i<C6VC6ZAccelerometerFloat_save.size();i++)
                {
                    progressDialog->setValue(C6VC6XAccelerometerFloatNum+C6VC6YAccelerometerFloatNum+i);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        fileSave.close();
                        fileSave.remove();
                        qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                        return;
                    }
                    dataOut<<C6VC6ZAccelerometerFloat_save[i]<<",";
                }
                dataOut<<tr("\n</Z加速度计零偏>")<<"\n";
            }
        }
    }
    if(1)//保存速度误差曲线
    {
        int VeastSpeedErrorNum = 0;
        int VnorthSpeedErrorNum = 0;
         int VtogetherSpeedErrorNum = 0;

        if(ui->checkBox_67->isChecked() == true)
            VeastSpeedErrorNum += VeastSpeedError_bk.size() + VeastSpeedError.size();
        if(ui->checkBox_69->isChecked() == true)
            VnorthSpeedErrorNum += VnorthSpeedError_bk.size() + VnorthSpeedError.size();
        if(ui->checkBox_68->isChecked() == true)
            VtogetherSpeedErrorNum += VtogetherSpeedError_bk.size() + VtogetherSpeedError.size();
        progressDialog->setRange(0, VeastSpeedErrorNum+VnorthSpeedErrorNum+VtogetherSpeedErrorNum);
        if(ui->checkBox_67->isChecked() == true)
        {
            QVector<double> VeastSpeedError_save = VeastSpeedError_bk + VeastSpeedError;
            dataOut<<tr("<东速误差,")<<VeastSpeedError_save.size()<<">"<<"\n";
            for(int i = 0;i<VeastSpeedError_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<VeastSpeedError_save[i]<<",";
            }
            dataOut<<tr("\n</东速误差>")<<"\n";
        }
        if(ui->checkBox_68->isChecked() == true)
        {
            QVector<double> VnorthSpeedError_save = VnorthSpeedError_bk + VnorthSpeedError;
            dataOut<<tr("<北速误差,")<<VnorthSpeedError_save.size()<<">"<<"\n";
            for(int i = 0;i<VnorthSpeedError_save.size();i++)
            {
                progressDialog->setValue(VeastSpeedErrorNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<VnorthSpeedError_save[i]<<",";
            }
            dataOut<<tr("\n</北速误差>")<<"\n";
        }
        if(ui->checkBox_68->isChecked() == true)
        {
            QVector<double> VtogetherSpeedError_save = VtogetherSpeedError_bk + VtogetherSpeedError;
            dataOut<<tr("<合速误差,")<<VtogetherSpeedError_save.size()<<">"<<"\n";
            for(int i = 0;i<VtogetherSpeedError_save.size();i++)
            {
                progressDialog->setValue(VeastSpeedErrorNum+VnorthSpeedErrorNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<VtogetherSpeedError_save[i]<<",";
            }
            dataOut<<tr("\n</合速误差>")<<"\n";
        }
    }

    if(1)//保存位置误差曲线
    {
        int VlatitudeErrorNum = 0;
        int VlongitudeErrorNum = 0;
         int VpositionErrorNum = 0;

        if(ui->checkBox_70->isChecked() == true)
            VlatitudeErrorNum += VlatitudeError_bk.size() + VlatitudeError.size();
        if(ui->checkBox_72->isChecked() == true)
            VlongitudeErrorNum += VlongitudeError_bk.size() + VlongitudeError.size();
        if(ui->checkBox_71->isChecked() == true)
            VpositionErrorNum += VpositionError_bk.size() + VpositionError.size();
        progressDialog->setRange(0, VlatitudeErrorNum+VlongitudeErrorNum+VpositionErrorNum);
        if(ui->checkBox_70->isChecked() == true)
        {
            QVector<double> VlatitudeError_save = VlatitudeError_bk + VlatitudeError;
            dataOut<<tr("<纬度误差,")<<VlatitudeError_save.size()<<">"<<"\n";
            for(int i = 0;i<VlatitudeError_save.size();i++)
            {
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<VlatitudeError_save[i]<<",";
            }
            dataOut<<tr("\n</纬度误差>")<<"\n";
        }
        if(ui->checkBox_72->isChecked() == true)
        {
            QVector<double> VlongitudeError_save = VlongitudeError_bk + VlongitudeError;
            dataOut<<tr("<经度误差,")<<VlongitudeError_save.size()<<">"<<"\n";
            for(int i = 0;i<VlongitudeError_save.size();i++)
            {
                progressDialog->setValue(VlatitudeErrorNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<VlongitudeError_save[i]<<",";
            }
            dataOut<<tr("\n</经度误差>")<<"\n";
        }
        if(ui->checkBox_71->isChecked() == true)
        {
            QVector<double> VpositionError_save = VpositionError_bk + VpositionError;
            dataOut<<tr("<位置误差,")<<VpositionError_save.size()<<">"<<"\n";
            for(int i = 0;i<VpositionError_save.size();i++)
            {
                progressDialog->setValue(VlatitudeErrorNum+VlongitudeErrorNum+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<VpositionError_save[i]<<",";
            }
            dataOut<<tr("\n</位置误差>")<<"\n";
        }
    }

    dataOut<<"</CurveProfile>";
    fileSave.close();
    delete progressDialog;
    progressDialog = NULL;
    QMessageBox::information(NULL, "提示", "保存成功！");
    qGetdataTime->start();
    qDrawTime->start();

}
void MainWindow::bookLog(QString bookStr)
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dayStr = current_date_time.toString("yyyy-MM-dd");
    //从界面中读取以前收到的数据
    QString oldString = ui->textBrowser->toPlainText();
    oldString = oldString + bookStr;
    //清空以前的显示
    ui->textBrowser->clear();
    //重新显示
    ui->textBrowser->append(oldString);
    QString fileName = tr("装订日志_")+dayStr;
    QFile fileSave(fileName);
   if(!fileSave.open( QIODevice::ReadWrite | QIODevice::Append ))
    {
        //无法打开要写入的文件
        QMessageBox::warning(this, tr("打开写入文件"),
                             tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
        return;
    }

    QTextStream dataOut(&fileSave);
    dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
    dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
    dataOut << oldString;
    fileSave.close();

}



void MainWindow::on_pushButton_10_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("打开曲线"),"./","*.dat");
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开曲线文件"),
                                 tr("打开曲线文件失败，请检查文件名和是否具有读取权限！"));
            return;
        }

        QTextStream stream(&file);
        stream.setCodec("utf-8");  // 要读的文件是utf-8编码
        stream.setGenerateByteOrderMark(true);  // 带bom的utf8
        QString start = stream.readLine();
        QStringList startList = start.split(",");
        if(startList[0] != "<CurveProfile")
        {
            //曲线格式错误
            QMessageBox::warning(this, tr("打开曲线文件"),
                                 tr("文件格式错误！"));
            return;
        }
        int graphPointNum = startList[2].toUInt();

        QProgressDialog *progressDialog = new QProgressDialog(this);
        QFont font("ZYSong18030", 12);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle(tr("打开曲线"));
        progressDialog->setLabelText(tr("打开中..."));
        progressDialog->setCancelButtonText(tr("取消"));
        progressDialog->setRange(0, graphPointNum);
        long  currentPoint = 0;



        QCustomPlot* customPlot = ui->customPlot3;
        customPlot->clearGraphs();

        QStringList curveNameList;
        QString pointNumStr;
        int graphNum = 0;

//        if(lineList[0][0] == '<' && lineList[0][1] != "/")
//        if(line[0] == '<' && line[1] == 'C')
//        {
//            QStringList lineList = line.split(",");
//            QStringList curveStartList = lineList[0].split("<");
//            graphPointNum = curveStartList[2].toUInt();

//        }
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            QStringList lineList = line.split(",");
            //if(lineList[0][0] == '<' && lineList[0][1] != "/")
            if(line[0] == '<' && line[1] != '/')
            {
                QStringList curveStartList = lineList[0].split("<");
                curveNameList.append(curveStartList[1]);
                curveStartList = lineList[1].split(">");
                pointNumStr = curveStartList[0];
            }
            else if(line[0] == '<' && line[1] == "/" && line !="</CurveProfile>")
            {
                continue;
            }
            else if(line == "</CurveProfile>")
            {
                break;
            }
            else
            {
                QVector<double> valueVector;
                QVector<double> X;

                QStringList valueList = line.split(",");
                //for(QStringList::iterator it =valueList.begin();it!=valueList.end();++it)
                for(int i = 0;i<pointNumStr.toInt();i++)
                {
                    valueVector.append( valueList[i].toFloat());
                    X.append(i);

                    progressDialog->setValue(currentPoint);
                    if(progressDialog->wasCanceled())
                    {
                        delete progressDialog;
                        file.close();
                        progressDialog =NULL;
                        return;
                    }
                    currentPoint ++;

                }
                QPen pen;
                customPlot->addGraph();
                if(graphNum == 0)
                {
                    pen.setColor(QColor(255,0,0));
                }
                else if(graphNum == 1)
                {
                    pen.setColor(QColor(128,0,255));
                }
                else if(graphNum == 2)
                {
                    pen.setColor(QColor(0,143,122));
                }
                else if(graphNum == 3)
                {
                    pen.setColor(QColor(255,0,128));
                }
                else if(graphNum == 4)
                {
                    pen.setColor(QColor(147,108,0));
                }
                else if(graphNum == 5)
                {
                    pen.setColor(QColor(0,0,255));
                }

                customPlot->legend->setVisible(true);
                customPlot->graph(graphNum)->setPen(pen);
                customPlot->graph(graphNum)->setName(curveNameList[graphNum]);
                customPlot->yAxis->setNumberPrecision(7);
                customPlot->graph(graphNum)->setData(X,valueVector);
                customPlot->graph(graphNum)->rescaleAxes();                   //使曲线平铺整个画面
                //customPlot->xAxis->setRange(0, 500, Qt::AlignRight);
               customPlot->graph(graphNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
               graphNum++;
            }
        }
        //绘图
        customPlot->replot(QCustomPlot::rpQueuedReplot);

        delete progressDialog;
        file.close();
        progressDialog = NULL;
        QMessageBox::information(NULL, "提示", "打开成功！");
    }
}
//void MainWindow::doDataReciveWork()
//{

//    if(serial_1 !=NULL)
//    {
//        if(serial_1->bytesAvailable()>0)
//        {
//            QByteArray buffertemp = serial->readAll();
//            buffertemp = buffertemp.toHex();
//            emit sendResultToGui(buffertemp);
//        }
//        else if(serial_1->bytesAvailable()==0)
//        {
//            qDebug()<<"Serial port do not open";
//        }
//        else if(serial_1->bytesAvailable()<0)
//        {
//            qDebug()<<"Serial port error";
//        }
//    }
//}
#ifdef QEXTSERIALPORT
void MainWindow::doDataSendWork(const QByteArray data)
{
        // 发送数据

    serial_1->write(data);
}
#endif




void MainWindow::on_pushButton_11_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    sysHeightData->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    //判断打开串口是否打开
    if(ui->btn_openPort->text()=="打开串口")
    {
        QMessageBox::information(NULL, "提示", "串口未打开！");
        return;
    }
    sysBaseGData->show();
}

void MainWindow::on_pushButton_13_clicked()
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dayStr = current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
    long totalPoint = 72*(C1Vlatitude_bk.size() + C1Vlatitude.size());
    QProgressDialog *progressDialog = new QProgressDialog(this);
    QFont font("ZYSong18030", 12);
    progressDialog->setFont(font);
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setMinimumDuration(5);
    progressDialog->setWindowTitle(tr("保存曲线"));
    progressDialog->setLabelText(tr("复制中..."));
    progressDialog->setCancelButtonText(tr("取消"));
    progressDialog->setRange(0, totalPoint);
    long  currentPoint = 0;
    qGetdataTime->stop();

    QDir dir;
    QString currentPath = "./curve/" + dayStr;
    bool res = dir.mkpath(currentPath);
    if(!res)
    {
        QMessageBox::warning(NULL, "提示", "创建曲线文件夹失败！");
    }
    QVector<double> C1Vlongitude_save = C1Vlongitude_bk + C1Vlongitude;
    if(1)//保存位置曲线
    {

        //保存纬度和经度曲线
        QString path = currentPath + "/位置曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"2"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"2"<<","<<C1Vlongitude_save.size()*2<<","<<dayStr<<">"<<"\n";   //文件开始格式
        QVector<double> C1Vlatitude_save = C1Vlatitude_bk + C1Vlatitude;
        dataOut<<tr("<纬度,")<<C1Vlatitude_save.size()<<">"<<"\n";
        for(int i = 0;i<C1Vlatitude_save.size();i++)
        {
            progressDialog->setValue(i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1Vlatitude_save[i]<<",";
        }
        dataOut<<tr("\n</纬度>")<<"\n";
        currentPoint += C1Vlatitude_save.size();

        dataOut<<tr("<经度,")<<C1Vlongitude_save.size()<<">"<<"\n";
        for(int i = 0;i<C1Vlongitude_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1Vlongitude_save[i]<<",";
        }
        dataOut<<tr("\n</经度>")<<"\n";
        currentPoint += C1Vlongitude_save.size();

         QVector<double> C6UndampedLatFloat_save = C6VC6UndampedLatFloat_bk + C6VC6UndampedLatFloat;
        dataOut<<tr("<无阻尼纬度,")<<C6UndampedLatFloat_save.size()<<">"<<"\n";
        for(int i = 0;i<C6UndampedLatFloat_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C6UndampedLatFloat_save[i]<<",";
        }
        dataOut<<tr("\n</无阻尼纬度>")<<"\n";
        currentPoint += C6UndampedLatFloat_save.size();

        QVector<double> C6UndampedLongFloat_save = C6VC6UndampedLongFloat_bk + C6VC6UndampedLongFloat;
       dataOut<<tr("<无阻尼经度,")<<C6UndampedLongFloat_save.size()<<">"<<"\n";
       for(int i = 0;i<C6UndampedLongFloat_save.size();i++)
       {
           progressDialog->setValue(currentPoint+i);
           if(progressDialog->wasCanceled())
           {
               delete progressDialog;
               fileSave.close();
               fileSave.remove();
               qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
               return;
           }
           dataOut<<C6UndampedLongFloat_save[i]<<",";
       }
       dataOut<<tr("\n</无阻尼经度>")<<"\n";
       currentPoint += C6UndampedLongFloat_save.size();

       QVector<double> C6UndampedHeightFloat_save = C6VC6UndampedHeightFloat_bk + C6VC6UndampedHeightFloat;
      dataOut<<tr("<无阻尼高度,")<<C6UndampedHeightFloat_save.size()<<">"<<"\n";
      for(int i = 0;i<C6UndampedHeightFloat_save.size();i++)
      {
          progressDialog->setValue(currentPoint+i);
          if(progressDialog->wasCanceled())
          {
              delete progressDialog;
              fileSave.close();
              fileSave.remove();
              qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
              return;
          }
          dataOut<<C6UndampedHeightFloat_save[i]<<",";
      }
      dataOut<<tr("\n</无阻尼高度>")<<"\n";
      currentPoint += C6UndampedHeightFloat_save.size();

        dataOut<<"</CurveProfile>";
        fileSave.close();

    }

    if(1)//保存航姿曲线
    {

        QString path = currentPath + "/航姿曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式

        QVector<double> C1VheadingAngular_save = C1VheadingAngle + C1VheadingAngle_bk;
        dataOut<<tr("<航向,")<<C1VheadingAngular_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VheadingAngular_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VheadingAngular_save[i]<<",";
        }
        dataOut<<tr("\n</航向>")<<"\n";
        currentPoint += C1VheadingAngular_save.size();

        QVector<double> C1VrollAngle_save = C1VrollAngle_bk + C1VrollAngle;
        dataOut<<tr("<横摇角,")<<C1VrollAngle_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VrollAngle_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VrollAngle_save[i]<<",";
        }
        dataOut<<tr("\n</横摇角>")<<"\n";
        currentPoint += C1VrollAngle_save.size();

        QVector<double> C1VpitchAngle_save = C1VpitchAngle_bk + C1VpitchAngle;
        dataOut<<tr("<纵摇角,")<<C1VpitchAngle_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VpitchAngle_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VpitchAngle_save[i]<<",";
        }
        dataOut<<tr("\n</纵摇角>")<<"\n";
        currentPoint +=C1VpitchAngle_save.size();

        QVector<double> C6UndampedRollAngleFloat_save = C6VC6UndampedRollAngleFloat_bk + C6VC6UndampedRollAngleFloat;
        dataOut<<tr("<无阻尼横摇角,")<<C6UndampedRollAngleFloat_save.size()<<">"<<"\n";
        for(int i = 0;i<C6UndampedRollAngleFloat_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C6UndampedRollAngleFloat_save[i]<<",";
        }
        dataOut<<tr("\n</无阻尼横摇角>")<<"\n";
        currentPoint +=C6UndampedRollAngleFloat_save.size();

        QVector<double> C6UndampedPitchAngleFloat_save = C6VC6UndampedPitchAngleFloat_bk + C6VC6UndampedPitchAngleFloat;
        dataOut<<tr("<无阻尼纵摇角,")<<C6UndampedPitchAngleFloat_save.size()<<">"<<"\n";
        for(int i = 0;i<C6UndampedPitchAngleFloat_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C6UndampedPitchAngleFloat_save[i]<<",";
        }
        dataOut<<tr("\n</无阻尼纵摇角>")<<"\n";
        currentPoint +=C6UndampedPitchAngleFloat_save.size();

        QVector<double> C6UndampedHeadingAngularFloat_save = C6VC6UndampedHeadingAngularFloat_bk + C6VC6UndampedHeadingAngularFloat;
        dataOut<<tr("<无阻尼航向角,")<<C6UndampedHeadingAngularFloat_save.size()<<">"<<"\n";
        for(int i = 0;i<C6UndampedHeadingAngularFloat_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C6UndampedHeadingAngularFloat_save[i]<<",";
        }
        dataOut<<tr("\n</无阻尼航向角>")<<"\n";
        currentPoint +=C6UndampedHeadingAngularFloat_save.size();

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存姿态角速度曲线
    {

        QString path = currentPath + "/姿态角速度曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        QVector<double> C1VheadingAngularSpeed_save = C1VheadingAngularSpeed_bk + C1VheadingAngularSpeed;
        dataOut<<tr("<航向角速度,")<<C1VheadingAngularSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VheadingAngularSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VheadingAngularSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</航向角速度>")<<"\n";
        currentPoint += C1VheadingAngularSpeed_save.size();

        QVector<double> C1VrollAngleSpeed_save = C1VrollAngleSpeed_bk + C1VrollAngleSpeed;
        dataOut<<tr("<横摇角速度,")<<C1VrollAngleSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VrollAngleSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VrollAngleSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</横摇角速度>")<<"\n";
        currentPoint += C1VrollAngleSpeed_save.size();

        QVector<double> C1VpitchAngleSpeed_save = C1VpitchAngleSpeed_bk + C1VpitchAngleSpeed;
        dataOut<<tr("<纵摇角速度,")<<C1VpitchAngleSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VpitchAngleSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VpitchAngleSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</纵摇角速度>")<<"\n";
        currentPoint +=C1VpitchAngleSpeed_save.size();


        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存速度曲线
    {
        //保存北速和东速曲线
        QString path = currentPath + "/速度曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"2"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"2"<<","<<C1Vlongitude_save.size()*2<<","<<dayStr<<">"<<"\n";   //文件开始格式
        QVector<double> C1VnorthSpeed_save = C1VnorthSpeed_bk + C1VnorthSpeed;
        dataOut<<tr("<北速,")<<C1VnorthSpeed_save.size()<<">"<<"\n";

        for(int i = 0;i<C1VnorthSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VnorthSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</北速>")<<"\n";
        currentPoint += C1VnorthSpeed_save.size();

        /**********************************************************************************/

        QVector<double> C1VeastSpeed_save = C1VeastSpeed_bk + C1VeastSpeed;
        dataOut<<tr("<东速,")<<C1VeastSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VeastSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VeastSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</东速>")<<"\n";
        currentPoint += C1VeastSpeed_save.size();


        QVector<double> C6UndampedNorthSpeedFloat_save = C6VC6UndampedNorthSpeedFloat_bk + C6VC6UndampedNorthSpeedFloat;
        dataOut<<tr("<无阻尼北速,")<<C6UndampedNorthSpeedFloat_save.size()<<">"<<"\n";
        for(int i = 0;i<C6UndampedNorthSpeedFloat_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C6UndampedNorthSpeedFloat_save[i]<<",";
        }
        dataOut<<tr("\n</无阻尼北速>")<<"\n";
        currentPoint += C6UndampedNorthSpeedFloat_save.size();

        QVector<double> C6UndampedEastSpeedFloat_save = C6VC6UndampedEastSpeedFloat_bk + C6VC6UndampedEastSpeedFloat;
        dataOut<<tr("<无阻尼东速,")<<C6UndampedEastSpeedFloat_save.size()<<">"<<"\n";
        for(int i = 0;i<C6UndampedEastSpeedFloat_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C6UndampedEastSpeedFloat_save[i]<<",";
        }
        dataOut<<tr("\n</无阻尼东速>")<<"\n";
        currentPoint += C6UndampedEastSpeedFloat_save.size();

        QVector<double> C6VerticalVelocityFloat_save = C6VC6VerticalVelocityFloat_bk + C6VC6VerticalVelocityFloat;
        dataOut<<tr("<无阻尼垂速,")<<C6VerticalVelocityFloat_save.size()<<">"<<"\n";
        for(int i = 0;i<C6VerticalVelocityFloat_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C6VerticalVelocityFloat_save[i]<<",";
        }
        dataOut<<tr("\n</无阻尼垂速>")<<"\n";
        currentPoint += C6VerticalVelocityFloat_save.size();

        dataOut<<"</CurveProfile>";
        fileSave.close();

    }

    if(1)//保存瞬时线运动曲线
    {

        QString path = currentPath + "/瞬时线运动曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"6"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"6"<<","<<C1Vlongitude_save.size()*6<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /**********************************************************************************/

        QVector<double> C1Vheave_save = C1Vheave_bk + C1Vheave;
        dataOut<<tr("<垂荡,")<<C1Vheave_save.size()<<">"<<"\n";
        for(int i = 0;i<C1Vheave_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1Vheave_save[i]<<",";
        }
        dataOut<<tr("\n</垂荡>")<<"\n";
        currentPoint += C1Vheave_save.size();

        /**********************************************************************************/

        QVector<double> C1VheaveC1VverticalVelocity_save = C1VverticalVelocity + C1VverticalVelocity_bk;
        dataOut<<tr("<垂速,")<<C1VheaveC1VverticalVelocity_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VheaveC1VverticalVelocity_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VheaveC1VverticalVelocity_save[i]<<",";
        }
        dataOut<<tr("\n</垂速>")<<"\n";
        currentPoint += C1VheaveC1VverticalVelocity_save.size();

        /**********************************************************************************/
        QVector<double> C1Vsway_save = C1Vsway_bk + C1Vsway;
        dataOut<<tr("<横荡,")<<C1Vsway_save.size()<<">"<<"\n";
        for(int i = 0;i<C1Vsway_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1Vsway_save[i]<<",";
        }
        dataOut<<tr("\n</横荡>")<<"\n";
        currentPoint += C1Vsway_save.size();

        /**********************************************************************************/
        QVector<double> C1VtransverseVelocity_save = C1VtransverseVelocity_bk + C1VtransverseVelocity;
        dataOut<<tr("<横速,")<<C1VtransverseVelocity_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VtransverseVelocity_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VtransverseVelocity_save[i]<<",";
        }
        dataOut<<tr("\n</横速>")<<"\n";
        currentPoint += C1VtransverseVelocity_save.size();

        /**********************************************************************************/
        QVector<double> C1Vsurge_save = C1Vsurge_bk + C1Vsurge;
        dataOut<<tr("<纵荡,")<<C1Vsurge_save.size()<<">"<<"\n";
        for(int i = 0;i<C1Vsurge_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1Vsurge_save[i]<<",";
        }
        dataOut<<tr("\n</纵荡>")<<"\n";
        currentPoint += C1Vsurge_save.size();
        /**********************************************************************************/
        QVector<double> C1VlongitudinalVelocity_save = C1VlongitudinalVelocity_bk + C1VlongitudinalVelocity;
        dataOut<<tr("<纵速,")<<C1VlongitudinalVelocity_save.size()<<">"<<"\n";
        for(int i = 0;i<C1VlongitudinalVelocity_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C1VlongitudinalVelocity_save[i]<<",";
        }
        dataOut<<tr("\n</纵速>")<<"\n";
        currentPoint += C1VlongitudinalVelocity_save.size();
        /**********************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();

    }
    if(0)//不显示增量、补偿增量和差频（原始脉冲）曲线2022-01-20
    {
        if(1)//保存陀螺增量曲线
        {

            QString path = currentPath + "/陀螺增量曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C5VXGyroAngleIncreaseFloat_save = C5VXGyroAngleIncreaseFloat_bk + C5VXGyroAngleIncreaseFloat;
            dataOut<<tr("<X陀螺增量,")<<C5VXGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXGyroAngleIncreaseFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXGyroAngleIncreaseFloat_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺增量>")<<"\n";
            currentPoint += C5VXGyroAngleIncreaseFloat_save.size();

            /********************************************************************************************/

            QVector<double> C5VYGyroAngleIncreaseFloat_save = C5VYGyroAngleIncreaseFloat_bk + C5VYGyroAngleIncreaseFloat;
            dataOut<<tr("<Y陀螺增量,")<<C5VYGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYGyroAngleIncreaseFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYGyroAngleIncreaseFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺增量>")<<"\n";
            currentPoint += C5VYGyroAngleIncreaseFloat_save.size();
            /********************************************************************************************/

            QVector<double> C5VZGyroAngleIncreaseFloat_save = C5VZGyroAngleIncreaseFloat_bk + C5VZGyroAngleIncreaseFloat;
            dataOut<<tr("<Z陀螺增量,")<<C5VZGyroAngleIncreaseFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZGyroAngleIncreaseFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZGyroAngleIncreaseFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺增量>")<<"\n";
            currentPoint +=C5VZGyroAngleIncreaseFloat_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }

        if(1)//保存加表增量曲线
        {

            QString path = currentPath + "/加表增量曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C5VXAccelerometerSpeedIncrementFloat_save = C5VXAccelerometerSpeedIncrementFloat_bk + C5VXAccelerometerSpeedIncrementFloat;
            dataOut<<tr("<X加表增量,")<<C5VXAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXAccelerometerSpeedIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXAccelerometerSpeedIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</X加表增量>")<<"\n";
            currentPoint += C5VXAccelerometerSpeedIncrementFloat_save.size();

            /********************************************************************************************/

            QVector<double> C5VYAccelerometerSpeedIncrementFloat_save = C5VYAccelerometerSpeedIncrementFloat_bk + C5VYAccelerometerSpeedIncrementFloat;
            dataOut<<tr("<Y加表增量,")<<C5VYAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYAccelerometerSpeedIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYAccelerometerSpeedIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Y加表增量>")<<"\n";
            currentPoint += C5VYAccelerometerSpeedIncrementFloat_save.size();
            /********************************************************************************************/

            QVector<double> C5VZAccelerometerSpeedIncrementFloat_save = C5VZAccelerometerSpeedIncrementFloat_bk + C5VZAccelerometerSpeedIncrementFloat;
            dataOut<<tr("<Z加表增量,")<<C5VZAccelerometerSpeedIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZAccelerometerSpeedIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZAccelerometerSpeedIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Z加表增量>")<<"\n";
            currentPoint +=C5VZAccelerometerSpeedIncrementFloat_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }

        if(1)//保存陀螺1s补偿后角增量曲线
        {

            QString path = currentPath + "/陀螺1s补偿后角增量曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C5VXgyroCompensatedAngleIncrementFloat_save = C5VXgyroCompensatedAngleIncrementFloat_bk + C5VXgyroCompensatedAngleIncrementFloat;
            dataOut<<tr("<X陀螺1s补偿后角增量,")<<C5VXgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXgyroCompensatedAngleIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXgyroCompensatedAngleIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺1s补偿后角增量>")<<"\n";
            currentPoint += C5VXgyroCompensatedAngleIncrementFloat_save.size();

            /********************************************************************************************/

            QVector<double> C5VYgyroCompensatedAngleIncrementFloat_save = C5VYgyroCompensatedAngleIncrementFloat_bk + C5VYgyroCompensatedAngleIncrementFloat;
            dataOut<<tr("<Y陀螺1s补偿后角增量,")<<C5VYgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYgyroCompensatedAngleIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYgyroCompensatedAngleIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺1s补偿后角增量>")<<"\n";
            currentPoint += C5VYgyroCompensatedAngleIncrementFloat_save.size();
            /********************************************************************************************/

            QVector<double> C5VZgyroCompensatedAngleIncrementFloat_save = C5VZgyroCompensatedAngleIncrementFloat_bk + C5VZgyroCompensatedAngleIncrementFloat;
            dataOut<<tr("<Z陀螺1s补偿后角增量,")<<C5VZgyroCompensatedAngleIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZgyroCompensatedAngleIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZgyroCompensatedAngleIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺1s补偿后角增量>")<<"\n";
            currentPoint +=C5VZgyroCompensatedAngleIncrementFloat_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }

        if(1)//保存加速度计1s补偿后速度增量曲线
        {

            QString path = currentPath + "/加速度计1s补偿后速度增量曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C5VXAccVelocityIncrementFloat_save = C5VXAccVelocityIncrementFloat_bk + C5VXAccVelocityIncrementFloat;
            dataOut<<tr("<X加速度计1s补偿后速度增量,")<<C5VXAccVelocityIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXAccVelocityIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXAccVelocityIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</X加速度计1s补偿后速度增量>")<<"\n";
            currentPoint += C5VXAccVelocityIncrementFloat_save.size();

            /********************************************************************************************/

            QVector<double> C5VYAccVelocityIncrementFloat_save = C5VYAccVelocityIncrementFloat_bk + C5VYAccVelocityIncrementFloat;
            dataOut<<tr("<Y加速度计1s补偿后速度增量,")<<C5VYAccVelocityIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYAccVelocityIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYAccVelocityIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Y加速度计1s补偿后速度增量>")<<"\n";
            currentPoint += C5VYAccVelocityIncrementFloat_save.size();
            /********************************************************************************************/

            QVector<double> C5VZAccVelocityIncrementFloat_save = C5VZAccVelocityIncrementFloat_bk + C5VZAccVelocityIncrementFloat;
            dataOut<<tr("<Z加速度计1s补偿后速度增量,")<<C5VZAccVelocityIncrementFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZAccVelocityIncrementFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                }
                dataOut<<C5VZAccVelocityIncrementFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Z加速度计1s补偿后速度增量>")<<"\n";
            currentPoint +=C5VZAccVelocityIncrementFloat_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }

        if(1)//保存陀螺差频曲线
        {

            QString path = currentPath + "/陀螺差频曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C5VXgyroDifFrequencyt_save = C5VXgyroDifFrequency_bk  + C5VXgyroDifFrequency;
            dataOut<<tr("<X陀螺差频,")<<C5VXgyroDifFrequencyt_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXgyroDifFrequencyt_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXgyroDifFrequencyt_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺差频>")<<"\n";
            currentPoint += C5VXgyroDifFrequencyt_save.size();

            /********************************************************************************************/

            QVector<double> C5VYgyroDifFrequency_save = C5VYgyroDifFrequency_bk + C5VYgyroDifFrequency;
            dataOut<<tr("<Y陀螺差频,")<<C5VYgyroDifFrequency_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYgyroDifFrequency_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYgyroDifFrequency_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺差频>")<<"\n";
            currentPoint += C5VYgyroDifFrequency_save.size();
            /********************************************************************************************/

            QVector<double> C5VZgyroDifFrequency_save = C5VZgyroDifFrequency_bk + C5VZgyroDifFrequency;
            dataOut<<tr("<Y陀螺差频,")<<C5VZgyroDifFrequency_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZgyroDifFrequency_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZgyroDifFrequency_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺差频>")<<"\n";
            currentPoint +=C5VZgyroDifFrequency_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }

        if(1)//保存加速度计差频曲线
        {

            QString path = currentPath + "/加速度计差频曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C5VXaccelerometerDifFre_save = C5VXaccelerometerDifFre_bk + C5VXaccelerometerDifFre;
            dataOut<<tr("<X加速度计差频,")<<C5VXaccelerometerDifFre_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VXaccelerometerDifFre_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VXaccelerometerDifFre_save[i]<<",";
            }
            dataOut<<tr("\n</X加速度计差频>")<<"\n";
            currentPoint += C5VXaccelerometerDifFre_save.size();

            /********************************************************************************************/

            QVector<double> C5VYaccelerometerDifFre_save = C5VYaccelerometerDifFre_bk + C5VYaccelerometerDifFre;
            dataOut<<tr("<Y加速度计差频,")<<C5VYaccelerometerDifFre_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VYaccelerometerDifFre_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VYaccelerometerDifFre_save[i]<<",";
            }
            dataOut<<tr("\n</Y加速度计差频>")<<"\n";
            currentPoint += C5VYaccelerometerDifFre_save.size();
            /********************************************************************************************/

            QVector<double> C5VZaccelerometerDifFre_save = C5VZaccelerometerDifFre_bk + C5VZaccelerometerDifFre;
            dataOut<<tr("<Z加速度计差频,")<<C5VZaccelerometerDifFre_save.size()<<">"<<"\n";
            for(int i = 0;i<C5VZaccelerometerDifFre_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C5VZaccelerometerDifFre_save[i]<<",";
            }
            dataOut<<tr("\n</Z加速度计差频>")<<"\n";
            currentPoint +=C5VZaccelerometerDifFre_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }
    }
    if(1)//保存陀螺温度1曲线
    {

        QString path = currentPath + "/陀螺温度1曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> C5VXgyroTemp1_save = C5VXgyroTemp1_bk + C5VXgyroTemp1;
        dataOut<<tr("<X陀螺温度1,")<<C5VXgyroTemp1_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VXgyroTemp1_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VXgyroTemp1_save[i]<<",";
        }
        dataOut<<tr("\n</X陀螺温度1>")<<"\n";
        currentPoint += C5VXgyroTemp1_save.size();

        /********************************************************************************************/

        QVector<double> C5VYgyroTemp1_save = C5VYgyroTemp1_bk + C5VYgyroTemp1;
        dataOut<<tr("<Y陀螺温度1,")<<C5VYgyroTemp1_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VYgyroTemp1_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VYgyroTemp1_save[i]<<",";
        }
        dataOut<<tr("\n</Y陀螺温度1>")<<"\n";
        currentPoint += C5VYgyroTemp1_save.size();
        /********************************************************************************************/

        QVector<double> C5VZgyroTemp1_save = C5VZgyroTemp1_bk + C5VZgyroTemp1;
        dataOut<<tr("<Z陀螺温度1,")<<C5VZgyroTemp1_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VZgyroTemp1_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VZgyroTemp1_save[i]<<",";
        }
        dataOut<<tr("\n</Z陀螺温度1>")<<"\n";
        currentPoint +=C5VZgyroTemp1_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存加速度计温度1曲线
    {

        QString path = currentPath + "/加速度计温度1曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> C5VXAccelerometerTemperture_save = C5VXAccelerometerTemperture_bk + C5VXAccelerometerTemperture;
        dataOut<<tr("<X加速度计温度1,")<<C5VXAccelerometerTemperture_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VXAccelerometerTemperture_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VXAccelerometerTemperture_save[i]<<",";
        }
        dataOut<<tr("\n</X加速度计温度1>")<<"\n";
        currentPoint += C5VXAccelerometerTemperture_save.size();

        /********************************************************************************************/

        QVector<double> C5VYAccelerometerTemperture_save = C5VYAccelerometerTemperture_bk + C5VYAccelerometerTemperture;
        dataOut<<tr("<Y加速度计温度1,")<<C5VYAccelerometerTemperture_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VYAccelerometerTemperture_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VYAccelerometerTemperture_save[i]<<",";
        }
        dataOut<<tr("\n</Y加速度计温度1>")<<"\n";
        currentPoint += C5VYAccelerometerTemperture_save.size();
        /********************************************************************************************/

        QVector<double> C5VZAccelerometerTemperture_save = C5VZAccelerometerTemperture_bk + C5VZAccelerometerTemperture;
        dataOut<<tr("<Z加速度计温度1,")<<C5VZAccelerometerTemperture_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VZAccelerometerTemperture_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VZAccelerometerTemperture_save[i]<<",";
        }
        dataOut<<tr("\n</Z加速度计温度1>")<<"\n";
        currentPoint +=C5VZAccelerometerTemperture_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存陀螺温度2曲线
    {

        QString path = currentPath + "/陀螺温度2曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> C5VXgyroTemp2_save = C5VXgyroTemp2_bk + C5VXgyroTemp2;
        dataOut<<tr("<X陀螺温度2,")<<C5VXgyroTemp2_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VXgyroTemp2_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VXgyroTemp2_save[i]<<",";
        }
        dataOut<<tr("\n</X陀螺温度2>")<<"\n";
        currentPoint += C5VXgyroTemp2_save.size();

        /********************************************************************************************/

        QVector<double> C5VYgyroTemp2_save = C5VYgyroTemp2_bk + C5VYgyroTemp2;
        dataOut<<tr("<Y陀螺温度2,")<<C5VYgyroTemp2_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VYgyroTemp2_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VYgyroTemp2_save[i]<<",";
        }
        dataOut<<tr("\n</Y陀螺温度2>")<<"\n";
        currentPoint += C5VYgyroTemp2_save.size();
        /********************************************************************************************/

        QVector<double> C5VZgyroTemp2_save = C5VZgyroTemp2_bk + C5VZgyroTemp2;
        dataOut<<tr("<Z陀螺温度2,")<<C5VZgyroTemp2_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VZgyroTemp2_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VZgyroTemp2_save[i]<<",";
        }
        dataOut<<tr("\n</Z陀螺温度2>")<<"\n";
        currentPoint +=C5VZgyroTemp2_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存陀螺抖幅曲线
    {

        QString path = currentPath + "/陀螺抖幅曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> C5VXgyroAmplitudeJitter_save = C5VXgyroAmplitudeJitter_bk + C5VXgyroAmplitudeJitter;
        dataOut<<tr("<X陀螺抖幅,")<<C5VXgyroAmplitudeJitter_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VXgyroAmplitudeJitter_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VXgyroAmplitudeJitter_save[i]<<",";
        }
        dataOut<<tr("\n</X陀螺抖幅>")<<"\n";
        currentPoint += C5VXgyroAmplitudeJitter_save.size();

        /********************************************************************************************/

        QVector<double> C5VYgyroAmplitudeJitter_save = C5VYgyroAmplitudeJitter_bk + C5VYgyroAmplitudeJitter;
        dataOut<<tr("<Y陀螺抖,")<<C5VYgyroAmplitudeJitter_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VYgyroAmplitudeJitter_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VYgyroAmplitudeJitter_save[i]<<",";
        }
        dataOut<<tr("\n</Y陀螺抖>")<<"\n";
        currentPoint += C5VYgyroAmplitudeJitter_save.size();
        /********************************************************************************************/

        QVector<double> C5VZgyroAmplitudeJitter_save = C5VZgyroAmplitudeJitter_bk + C5VZgyroAmplitudeJitter;
        dataOut<<tr("<Z陀螺抖幅,")<<C5VZgyroAmplitudeJitter_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VZgyroAmplitudeJitter_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VZgyroAmplitudeJitter_save[i]<<",";
        }
        dataOut<<tr("\n</Z陀螺抖幅>")<<"\n";
        currentPoint +=C5VZgyroAmplitudeJitter_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存陀螺抖频曲线
    {

        QString path = currentPath + "/陀螺抖频曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> C5VXgyroAmpl1itudeFrer_save = C5VXgyroAmpl1itudeFre_bk + C5VXgyroAmpl1itudeFre;
        dataOut<<tr("<X陀螺抖频,")<<C5VXgyroAmpl1itudeFrer_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VXgyroAmpl1itudeFrer_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VXgyroAmpl1itudeFrer_save[i]<<",";
        }
        dataOut<<tr("\n</X陀螺抖频>")<<"\n";
        currentPoint += C5VXgyroAmpl1itudeFrer_save.size();

        /********************************************************************************************/

        QVector<double> C5VYgyroAmpl1itudeFre_save = C5VYgyroAmpl1itudeFre_bk + C5VYgyroAmpl1itudeFre;
        dataOut<<tr("<Y陀螺抖频,")<<C5VYgyroAmpl1itudeFre_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VYgyroAmpl1itudeFre_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VYgyroAmpl1itudeFre_save[i]<<",";
        }
        dataOut<<tr("\n</Y陀螺抖频>")<<"\n";
        currentPoint += C5VYgyroAmpl1itudeFre_save.size();
        /********************************************************************************************/

        QVector<double> C5VZgyroAmpl1itudeFre_save = C5VZgyroAmpl1itudeFre_bk + C5VZgyroAmpl1itudeFre;
        dataOut<<tr("<Z陀螺抖频,")<<C5VZgyroAmpl1itudeFre_save.size()<<">"<<"\n";
        for(int i = 0;i<C5VZgyroAmpl1itudeFre_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C5VZgyroAmpl1itudeFre_save[i]<<",";
        }
        dataOut<<tr("\n</Z陀螺抖频>")<<"\n";
        currentPoint +=C5VZgyroAmpl1itudeFre_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存卫导曲线
    {

        QString path = currentPath + "/卫导曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> C3Vlongitude_save = C3Vlongitude_bk + C3Vlongitude;
        dataOut<<tr("<GPS经度,")<<C3Vlongitude_save.size()<<">"<<"\n";
        for(int i = 0;i<C3Vlongitude_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3Vlongitude_save[i]<<",";
        }
        dataOut<<tr("\n</GPS经度>")<<"\n";
        currentPoint += C3Vlongitude_save.size();

        /********************************************************************************************/

        QVector<double> C3VGPSlatitude_save = C3VGPSlatitude_bk + C3VGPSlatitude;
        dataOut<<tr("<GPS纬度,")<<C3VGPSlatitude_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VGPSlatitude_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VGPSlatitude_save[i]<<",";
        }
        dataOut<<tr("\n</GPS纬度>")<<"\n";
        currentPoint += C3VGPSlatitude_save.size();
        /********************************************************************************************/

        QVector<double> C3VtogetherSpeed_save = C3VtogetherSpeed_bk + C3VtogetherSpeed;
        dataOut<<tr("<GPS合速,")<<C3VtogetherSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VtogetherSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VtogetherSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</GPS合速>")<<"\n";
        currentPoint +=C3VtogetherSpeed_save.size();
        /********************************************************************************************/

        /********************************************************************************************/
        QVector<double> C3VheadingAngle_save = C3VheadingAngle_bk + C3VheadingAngle;
        dataOut<<tr("<GPS航向,")<<C3VheadingAngle_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VheadingAngle_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VheadingAngle_save[i]<<",";
        }
        dataOut<<tr("\n</GPS航向>")<<"\n";
        currentPoint += C3VheadingAngle_save.size();

        /********************************************************************************************/

        QVector<double> C3VcombinedEastSpeed_save = C3VcombinedEastSpeed_bk + C3VcombinedEastSpeed;
        dataOut<<tr("<GPS东速,")<<C3VcombinedEastSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VcombinedEastSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VcombinedEastSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</GPS东速>")<<"\n";
        currentPoint += C3VcombinedEastSpeed_save.size();
        /********************************************************************************************/

        QVector<double> C3VcombinedNorthSpeed_save = C3VcombinedNorthSpeed_bk + C3VcombinedNorthSpeed;
        dataOut<<tr("<GPS北速,")<<C3VcombinedNorthSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VcombinedNorthSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VcombinedNorthSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</GPS北速>")<<"\n";
        currentPoint +=C3VcombinedNorthSpeed_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存计程仪曲线
    {

        QString path = currentPath + "/计程仪曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> C3VwaterX_save = C3VwaterX_bk + C3VwaterX;
        dataOut<<tr("<多普勒对水横向速度,")<<C3VwaterX_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VwaterX_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VwaterX_save[i]<<",";
        }
        dataOut<<tr("\n</多普勒对水横向速度>")<<"\n";
        currentPoint += C3VwaterX_save.size();

        /********************************************************************************************/

        QVector<double> C3VwaterY_save = C3VwaterY_bk + C3VwaterY;
        dataOut<<tr("<多普勒对水纵向速度,")<<C3VwaterY_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VwaterY_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VwaterY_save[i]<<",";
        }
        dataOut<<tr("\n</多普勒对水纵向速度>")<<"\n";
        currentPoint += C3VwaterY_save.size();
        /********************************************************************************************/

        QVector<double> C3VbottomX_save = C3VbottomX_bk + C3VbottomX;
        dataOut<<tr("<多普勒对底横向速度,")<<C3VbottomX_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VbottomX_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VbottomX_save[i]<<",";
        }
        dataOut<<tr("\n</多普勒对底横向速度>")<<"\n";
        currentPoint +=C3VbottomX_save.size();
        /********************************************************************************************/

        /********************************************************************************************/
        QVector<double> C3VbottomY_save = C3VbottomY_bk + C3VbottomY;
        dataOut<<tr("<多普勒对底纵向速度,")<<C3VbottomY_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VbottomY_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VbottomY_save[i]<<",";
        }
        dataOut<<tr("\n</多普勒对底纵向速度>")<<"\n";
        currentPoint += C3VbottomY_save.size();

        /********************************************************************************************/

        QVector<double> C3VelectromagnetismSpeed_save = C3VelectromagnetismSpeed_bk + C3VelectromagnetismSpeed;
        dataOut<<tr("<电磁速度,")<<C3VelectromagnetismSpeed_save.size()<<">"<<"\n";
        for(int i = 0;i<C3VelectromagnetismSpeed_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<C3VelectromagnetismSpeed_save[i]<<",";
        }
        dataOut<<tr("\n</电磁速度>")<<"\n";
        currentPoint += C3VelectromagnetismSpeed_save.size();
        /********************************************************************************************/


        dataOut<<"</CurveProfile>";
        fileSave.close();
    }
    if(0)//不显示零偏曲线2022-01-20
    {
        if(1)//保存陀螺零偏估计曲线
        {

            QString path = currentPath + "/陀螺零偏估计曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qGetdataTime->start(addDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C6VC6XGroyFloat_save = C6VC6XGroyFloat_bk + C6VC6XGroyFloat;
            dataOut<<tr("<X陀螺零偏,")<<C6VC6XGroyFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6VC6XGroyFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6VC6XGroyFloat_save[i]<<",";
            }
            dataOut<<tr("\n</X陀螺零偏>")<<"\n";
            currentPoint += C6VC6XGroyFloat_save.size();

            /********************************************************************************************/

            QVector<double> C6VC6YGroyFloat_save = C6VC6YGroyFloat_bk + C6VC6YGroyFloat;
            dataOut<<tr("<Y陀螺零偏,")<<C6VC6YGroyFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6VC6YGroyFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6VC6YGroyFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Y陀螺零偏>")<<"\n";
            currentPoint += C6VC6YGroyFloat_save.size();
            /********************************************************************************************/

            QVector<double> C6VC6ZGroyFloat_save = C6VC6ZGroyFloat_bk + C6VC6ZGroyFloat;
            dataOut<<tr("<Z陀螺零偏,")<<C6VC6ZGroyFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6VC6ZGroyFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6VC6ZGroyFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Z陀螺零偏>")<<"\n";
            currentPoint +=C6VC6ZGroyFloat_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }

        if(1)//保存加速度计偏估计曲线
        {

            QString path = currentPath + "/加速度计偏估计曲线.dat";
            if(path.isEmpty())
            {
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QFile fileSave(path);
            if(!fileSave.open( QIODevice::WriteOnly ))
            {
                //无法打开要写入的文件
                QMessageBox::warning(this, tr("打开写入文件"),
                                     tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            QTextStream dataOut(&fileSave);
            dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
            dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
            current_date_time =QDateTime::currentDateTime();
            dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
            //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
            dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
            /********************************************************************************************/
            QVector<double> C6VC6XAccelerometerFloat_save = C6VC6XAccelerometerFloat_bk + C6VC6XAccelerometerFloat;
            dataOut<<tr("<X加速度计零偏,")<<C6VC6XAccelerometerFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6VC6XAccelerometerFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6VC6XAccelerometerFloat_save[i]<<",";
            }
            dataOut<<tr("\n</X加速度计零偏>")<<"\n";
            currentPoint += C6VC6XAccelerometerFloat_save.size();

            /********************************************************************************************/

            QVector<double> C6VC6YAccelerometerFloat_save = C6VC6YAccelerometerFloat_bk + C6VC6YAccelerometerFloat;
            dataOut<<tr("<Y加速度计零偏,")<<C6VC6YAccelerometerFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6VC6YAccelerometerFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6VC6YAccelerometerFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Y加速度计零偏>")<<"\n";
            currentPoint += C6VC6YAccelerometerFloat_save.size();
            /********************************************************************************************/

            QVector<double> C6VC6ZAccelerometerFloat_save = C6VC6ZAccelerometerFloat_bk + C6VC6ZAccelerometerFloat;
            dataOut<<tr("<Z加速度计零偏,")<<C6VC6ZAccelerometerFloat_save.size()<<">"<<"\n";
            for(int i = 0;i<C6VC6ZAccelerometerFloat_save.size();i++)
            {
                progressDialog->setValue(currentPoint+i);
                if(progressDialog->wasCanceled())
                {
                    delete progressDialog;
                    fileSave.close();
                    fileSave.remove();
                    qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                    return;
                }
                dataOut<<C6VC6ZAccelerometerFloat_save[i]<<",";
            }
            dataOut<<tr("\n</Z加速度计零偏>")<<"\n";
            currentPoint +=C6VC6ZAccelerometerFloat_save.size();
            /********************************************************************************************/

            dataOut<<"</CurveProfile>";
            fileSave.close();
        }
    }
    if(1)//保存速度误差曲线
    {

        QString path = currentPath + "/速度误差曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> VeastSpeedError_save = VeastSpeedError_bk + VeastSpeedError;
        dataOut<<tr("<东速误差,")<<VeastSpeedError_save.size()<<">"<<"\n";
        for(int i = 0;i<VeastSpeedError_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<VeastSpeedError_save[i]<<",";
        }
        dataOut<<tr("\n</东速误差>")<<"\n";
        currentPoint += VeastSpeedError_save.size();

        /********************************************************************************************/

        QVector<double> VnorthSpeedError_save = VnorthSpeedError_bk + VnorthSpeedError;
        dataOut<<tr("<北速误差,")<<VnorthSpeedError_save.size()<<">"<<"\n";
        for(int i = 0;i<VnorthSpeedError_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<VnorthSpeedError_save[i]<<",";
        }
        dataOut<<tr("\n</北速误差>")<<"\n";
        currentPoint += VnorthSpeedError_save.size();
        /********************************************************************************************/

        QVector<double> VtogetherSpeedError_save = VtogetherSpeedError_bk + VtogetherSpeedError;
        dataOut<<tr("<合速误差,")<<VtogetherSpeedError_save.size()<<">"<<"\n";
        for(int i = 0;i<VtogetherSpeedError_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<VtogetherSpeedError_save[i]<<",";
        }
        dataOut<<tr("\n</合速误差>")<<"\n";
        currentPoint +=VtogetherSpeedError_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    if(1)//保存位置误差曲线
    {

        QString path = currentPath + "/位置误差曲线.dat";
        if(path.isEmpty())
        {
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QFile fileSave(path);
        if(!fileSave.open( QIODevice::WriteOnly ))
        {
            //无法打开要写入的文件
            QMessageBox::warning(this, tr("打开写入文件"),
                                 tr("打开要写入的文件失败，请检查文件名和是否具有写入权限！"));
            qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
            return;
        }
        QTextStream dataOut(&fileSave);
        dataOut.setCodec("utf-8");  // 要读的文件是utf-8编码
        dataOut.setGenerateByteOrderMark(true);  // 带bom的utf8
        current_date_time =QDateTime::currentDateTime();
        dayStr = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        //dataOut<<"<CurveProfile,"<<"3"<<","<<dayStr<<">"<<"\n";   //文件开始格式
        dataOut<<"<CurveProfile,"<<"3"<<","<<C1Vlongitude_save.size()*3<<","<<dayStr<<">"<<"\n";   //文件开始格式
        /********************************************************************************************/
        QVector<double> VlatitudeError_save = VlatitudeError_bk + VlatitudeError;
        dataOut<<tr("<纬度误差,")<<VlatitudeError_save.size()<<">"<<"\n";
        for(int i = 0;i<VlatitudeError_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<VlatitudeError_save[i]<<",";
        }
        dataOut<<tr("\n</纬度误差>")<<"\n";
        currentPoint += VlatitudeError_save.size();

        /********************************************************************************************/

        QVector<double> VlongitudeError_save = VlongitudeError_bk + VlongitudeError;
        dataOut<<tr("<经度误差,")<<VlongitudeError_save.size()<<">"<<"\n";
        for(int i = 0;i<VlongitudeError_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<VlongitudeError_save[i]<<",";
        }
        dataOut<<tr("\n</经度误差>")<<"\n";
        currentPoint += VlongitudeError_save.size();
        /********************************************************************************************/

        QVector<double> VpositionError_save = VpositionError_bk + VpositionError;
        dataOut<<tr("<位置误差,")<<VpositionError_save.size()<<">"<<"\n";
        for(int i = 0;i<VpositionError_save.size();i++)
        {
            progressDialog->setValue(currentPoint+i);
            if(progressDialog->wasCanceled())
            {
                delete progressDialog;
                fileSave.close();
                fileSave.remove();
                qGetdataTime->start(addDataPeri); qDrawTime->start(drawDataPeri);
                return;
            }
            dataOut<<VpositionError_save[i]<<",";
        }
        dataOut<<tr("\n</位置误差>")<<"\n";
        currentPoint +=VpositionError_save.size();
        /********************************************************************************************/

        dataOut<<"</CurveProfile>";
        fileSave.close();
    }

    delete progressDialog;
    progressDialog = NULL;
    QMessageBox::information(NULL, "提示", "保存成功！");
    qGetdataTime->start();
    qDrawTime->start();
}
void MainWindow::on_action_3_triggered()
{
    isDegree = 1;
    ui->action_3->setChecked(true);
    ui->action_4->setChecked(false);

}

void MainWindow::on_action_4_triggered()
{
    isDegree = 0;
    ui->action_4->setChecked(true);
    ui->action_3->setChecked(false);

}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if(ui->btn_openPort->text() !=QString("打开串口"))
    {
        QMessageBox::warning(this,"关闭程序","请关闭串口后再退出！");
        e->ignore();

    }
}

void MainWindow::on_action_triggered()
{
    if(ui->action->isChecked() == false)
        ui->action->setChecked(false);
    else
        ui->action->setChecked(true);
}

void MainWindow::on_pushButton_15_clicked()
{

    //ui->customPlot2->graph(C1latitudeGraphNum)->rescaleValueAxis(false, true);  //调整Y轴为最大
    double biggest = -999999999;
    double smallest = 999999999;
    //经度、纬度
    if(ui->checkBox->isChecked())
    {
        auto C1Vlatitude_max = std::max_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));
        auto C1Vlatitude_min = std::min_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));

        if(*C1Vlatitude_max >= biggest)
            biggest = *C1Vlatitude_max;
        if(*C1Vlatitude_min <= smallest)
            smallest = *C1Vlatitude_min;
    }
    if(ui->checkBox_2->isChecked())
    {
        auto C1Vlongitude_max = std::max_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));
        auto C1Vlongitude_min = std::min_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));

        if(*C1Vlongitude_max >= biggest)
            biggest = *C1Vlongitude_max;
        if(*C1Vlongitude_min <= smallest)
            smallest = *C1Vlongitude_min;
    }
    if(ui->checkBox_73->isChecked())
    {
        auto C6VC6UndampedLatFloat_max = std::max_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));
        auto C6VC6UndampedLatFloat_min = std::min_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));

        if(*C6VC6UndampedLatFloat_max >= biggest)
            biggest = *C6VC6UndampedLatFloat_max;
        if(*C6VC6UndampedLatFloat_min <= smallest)
            smallest = *C6VC6UndampedLatFloat_min;
    }
    if(ui->checkBox_74->isChecked())
    {
        auto C6VC6UndampedLongFloat_max = std::max_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));
        auto C6VC6UndampedLongFloat_min = std::min_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));

        if(*C6VC6UndampedLongFloat_max >= biggest)
            biggest = *C6VC6UndampedLongFloat_max;
        if(*C6VC6UndampedLongFloat_min <= smallest)
            smallest = *C6VC6UndampedLongFloat_min;
    }
    if(ui->checkBox_75->isChecked())
    {
        auto C6VC6UndampedHeightFloat_max = std::max_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));
        auto C6VC6UndampedHeightFloat_min = std::min_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));

        if(*C6VC6UndampedHeightFloat_max >= biggest)
            biggest = *C6VC6UndampedHeightFloat_max;
        if(*C6VC6UndampedHeightFloat_min <= smallest)
            smallest = *C6VC6UndampedHeightFloat_min;
    }

     ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);

     ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

       //航向、横摇、纵摇
     if(ui->checkBox_5->isChecked())
     {
         auto C1VheadingAngle_max = std::max_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));
         auto C1VheadingAngle_min = std::min_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));

         if(*C1VheadingAngle_max >= biggest)
             biggest = *C1VheadingAngle_max;
         if(*C1VheadingAngle_min <= smallest)
             smallest = *C1VheadingAngle_min;
     }
     if(ui->checkBox_3->isChecked())
     {
         auto C1VrollAngle_max = std::max_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));
         auto C1VrollAngle_min = std::min_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));

         if(*C1VrollAngle_max >= biggest)
             biggest = *C1VrollAngle_max;
         if(*C1VrollAngle_min <= smallest)
             smallest = *C1VrollAngle_min;
     }
     if(ui->checkBox_4->isChecked())
     {
         auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));
         auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));

         if(*C1VpitchAngle_max >= biggest)
             biggest = *C1VpitchAngle_max;
         if(*C1VpitchAngle_min <= smallest)
             smallest = *C1VpitchAngle_min;
     }
     if(ui->checkBox_79->isChecked())
     {
         auto C6VC6UndampedRollAngleFloat_max = std::max_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));
         auto C6VC6UndampedRollAngleFloat_min = std::min_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));

         if(*C6VC6UndampedRollAngleFloat_max >= biggest)
             biggest = *C6VC6UndampedRollAngleFloat_max;
         if(*C6VC6UndampedRollAngleFloat_min <= smallest)
             smallest = *C6VC6UndampedRollAngleFloat_min;
     }
     if(ui->checkBox_80->isChecked())
     {
         auto C6VC6UndampedPitchAngleFloat_max = std::max_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));
         auto C6VC6UndampedPitchAngleFloat_min = std::min_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));

         if(*C6VC6UndampedPitchAngleFloat_max >= biggest)
             biggest = *C6VC6UndampedPitchAngleFloat_max;
         if(*C6VC6UndampedPitchAngleFloat_min <= smallest)
             smallest = *C6VC6UndampedPitchAngleFloat_min;
     }
     if(ui->checkBox_81->isChecked())
     {
         auto C6VC6UndampedHeadingAngularFloat_max = std::max_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));
         auto C6VC6UndampedHeadingAngularFloat_min = std::min_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));

         if(*C6VC6UndampedHeadingAngularFloat_max >= biggest)
             biggest = *C6VC6UndampedHeadingAngularFloat_max;
         if(*C6VC6UndampedHeadingAngularFloat_min <= smallest)
             smallest = *C6VC6UndampedHeadingAngularFloat_min;
     }

      ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
      ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

      //东速、北速
      if(ui->checkBox_9->isChecked())
      {
          auto C1VnorthSpeed_max = std::max_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));
          auto C1VnorthSpeed_min = std::min_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));

          if(*C1VnorthSpeed_max >= biggest)
              biggest = *C1VnorthSpeed_max;
          if(*C1VnorthSpeed_min <= smallest)
              smallest = *C1VnorthSpeed_min;
      }
      if(ui->checkBox_10->isChecked())
      {
          auto C1VeastSpeed_max = std::max_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));
          auto C1VeastSpeed_min = std::min_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));

          if(*C1VeastSpeed_max >= biggest)
              biggest = *C1VeastSpeed_max;
          if(*C1VeastSpeed_min <= smallest)
              smallest = *C1VeastSpeed_min;
      }
      if(ui->checkBox_76->isChecked())
      {
          auto C6VC6UndampedNorthSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));
          auto C6VC6UndampedNorthSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));

          if(*C6VC6UndampedNorthSpeedFloat_max >= biggest)
              biggest = *C6VC6UndampedNorthSpeedFloat_max;
          if(*C6VC6UndampedNorthSpeedFloat_min <= smallest)
              smallest = *C6VC6UndampedNorthSpeedFloat_min;
      }
      if(ui->checkBox_77->isChecked())
      {
          auto C6VC6UndampedEastSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));
          auto C6VC6UndampedEastSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));

          if(*C6VC6UndampedEastSpeedFloat_max >= biggest)
              biggest = *C6VC6UndampedEastSpeedFloat_max;
          if(*C6VC6UndampedEastSpeedFloat_min <= smallest)
              smallest = *C6VC6UndampedEastSpeedFloat_min;
      }
      if(ui->checkBox_78->isChecked())
      {
          auto C6VC6VerticalVelocityFloat_max = std::max_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));
          auto C6VC6VerticalVelocityFloat_min = std::min_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));

          if(*C6VC6VerticalVelocityFloat_max >= biggest)
              biggest = *C6VC6VerticalVelocityFloat_max;
          if(*C6VC6VerticalVelocityFloat_min <= smallest)
              smallest = *C6VC6VerticalVelocityFloat_min;
      }
       ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
       ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

        //航向角速度、横摇角速度、纵摇角速度
       if(ui->checkBox_6->isChecked())
       {
           auto C1VheadingAngularSpeed_max = std::max_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));
           auto C1VheadingAngularSpeed_min = std::min_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));

           if(*C1VheadingAngularSpeed_max >= biggest)
               biggest = *C1VheadingAngularSpeed_max;
           if(*C1VheadingAngularSpeed_min <= smallest)
               smallest = *C1VheadingAngularSpeed_min;
       }
       if(ui->checkBox_7->isChecked())
       {
           auto C1VrollAngleSpeed_max = std::max_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));
           auto C1VrollAngleSpeed_min = std::min_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));

           if(*C1VrollAngleSpeed_max >= biggest)
               biggest = *C1VrollAngleSpeed_max;
           if(*C1VrollAngleSpeed_min <= smallest)
               smallest = *C1VrollAngleSpeed_min;
       }
       if(ui->checkBox_8->isChecked())
       {
           auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));
           auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));

           if(*C1VpitchAngle_max >= biggest)
               biggest = *C1VpitchAngle_max;
           if(*C1VpitchAngle_min <= smallest)
               smallest = *C1VpitchAngle_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


        //垂荡、垂速、横荡、横速、纵荡、纵速
       if(ui->checkBox_12->isChecked())
       {
           auto C1Vheave_max = std::max_element(std::begin(C1Vheave), std::end(C1Vheave));
           auto C1Vheave_min = std::min_element(std::begin(C1Vheave), std::end(C1Vheave));

           if(*C1Vheave_max >= biggest)
               biggest = *C1Vheave_max;
           if(*C1Vheave_min <= smallest)
               smallest = *C1Vheave_min;
       }
       if(ui->checkBox_13->isChecked())
       {
           auto C1VverticalVelocity_max = std::max_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));
           auto C1VverticalVelocity_min = std::min_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));

           if(*C1VverticalVelocity_max >= biggest)
               biggest = *C1VverticalVelocity_max;
           if(*C1VverticalVelocity_min <= smallest)
               smallest = *C1VverticalVelocity_min;
       }
       if(ui->checkBox_11->isChecked())
       {
           auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
           auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

           if(*C1Vsway_max >= biggest)
               biggest = *C1Vsway_max;
           if(*C1Vsway_min <= smallest)
               smallest = *C1Vsway_min;
       }

       if(ui->checkBox_15->isChecked())
       {
           auto C1VtransverseVelocity_max = std::max_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));
           auto C1VtransverseVelocity_min = std::min_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));

           if(*C1VtransverseVelocity_max >= biggest)
               biggest = *C1VtransverseVelocity_max;
           if(*C1VtransverseVelocity_min <= smallest)
               smallest = *C1VtransverseVelocity_min;
       }
       if(ui->checkBox_16->isChecked())
       {
           auto C1Vsurge_max = std::max_element(std::begin(C1Vsurge), std::end(C1Vsurge));
           auto C1Vsurge_min = std::min_element(std::begin(C1Vsurge), std::end(C1Vsurge));

           if(*C1Vsurge_max >= biggest)
               biggest = *C1Vsurge_max;
           if(*C1Vsurge_min <= smallest)
               smallest = *C1Vsurge_min;
       }
       if(ui->checkBox_14->isChecked())
       {
           auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
           auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

           if(*C1Vsway_max >= biggest)
               biggest = *C1Vsway_max;
           if(*C1Vsway_min <= smallest)
               smallest = *C1Vsway_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

        if(0)//不显示增量和补偿增量2022-01-20
        {
            //X Y Z陀螺增量
            if(ui->checkBox_19->isChecked())
            {
                auto C5VXGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));
                auto C5VXGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));

                if(*C5VXGyroAngleIncreaseFloat_max >= biggest)
                    biggest = *C5VXGyroAngleIncreaseFloat_max;
                if(*C5VXGyroAngleIncreaseFloat_min <= smallest)
                    smallest = *C5VXGyroAngleIncreaseFloat_min;
            }
            if(ui->checkBox_18->isChecked())
            {
                auto C5VYGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));
                auto C5VYGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));

                if(*C5VYGyroAngleIncreaseFloat_max >= biggest)
                    biggest = *C5VYGyroAngleIncreaseFloat_max;
                if(*C5VYGyroAngleIncreaseFloat_min <= smallest)
                    smallest = *C5VYGyroAngleIncreaseFloat_min;
            }
            if(ui->checkBox_17->isChecked())
            {
                auto C5VZGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));
                auto C5VZGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));

                if(*C5VZGyroAngleIncreaseFloat_max >= biggest)
                    biggest = *C5VZGyroAngleIncreaseFloat_max;
                if(*C5VZGyroAngleIncreaseFloat_min <= smallest)
                    smallest = *C5VZGyroAngleIncreaseFloat_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


            //X Y Z加表增量
            if(ui->checkBox_20->isChecked())
            {
                auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));
                auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));

                if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
                    biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
                if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
                    smallest = *C5VXAccelerometerSpeedIncrementFloat_min;
            }
            if(ui->checkBox_21->isChecked())
            {
                auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));
                auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));

                if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
                    biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
                if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
                    smallest = *C5VYAccelerometerSpeedIncrementFloat_min;
            }
            if(ui->checkBox_22->isChecked())
            {
                auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));
                auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));

                if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
                    biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
                if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
                    smallest = *C5VZAccelerometerSpeedIncrementFloat_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


            //X Y Z陀螺1s补偿后角增量
            if(ui->checkBox_23->isChecked())
            {
                auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));
                auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));

                if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
                    biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
                if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
                    smallest = *C5VXAccelerometerSpeedIncrementFloat_min;
            }
            if(ui->checkBox_24->isChecked())
            {
                auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));
                auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));

                if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
                    biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
                if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
                    smallest = *C5VYAccelerometerSpeedIncrementFloat_min;
            }
            if(ui->checkBox_25->isChecked())
            {
                auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));
                auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));

                if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
                    biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
                if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
                    smallest = *C5VZAccelerometerSpeedIncrementFloat_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


            //X Y Z加速度计1s补偿后速度增量
            if(ui->checkBox_26->isChecked())
            {
                auto C5VXAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));
                auto C5VXAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));

                if(*C5VXAccVelocityIncrementFloat_max >= biggest)
                    biggest = *C5VXAccVelocityIncrementFloat_max;
                if(*C5VXAccVelocityIncrementFloat_min <= smallest)
                    smallest = *C5VXAccVelocityIncrementFloat_min;
            }
            if(ui->checkBox_27->isChecked())
            {
                auto C5VYAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));
                auto C5VYAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));

                if(*C5VYAccVelocityIncrementFloat_max >= biggest)
                    biggest = *C5VYAccVelocityIncrementFloat_max;
                if(*C5VYAccVelocityIncrementFloat_min <= smallest)
                    smallest = *C5VYAccVelocityIncrementFloat_min;
            }
            if(ui->checkBox_28->isChecked())
            {
                auto C5VZAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));
                auto C5VZAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));

                if(*C5VZAccVelocityIncrementFloat_max >= biggest)
                    biggest = *C5VZAccVelocityIncrementFloat_max;
                if(*C5VZAccVelocityIncrementFloat_min <= smallest)
                    smallest = *C5VZAccVelocityIncrementFloat_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);
        }
        if(0)//不显示差频（原始脉冲）2022-01-20
        {
            //X Y Z陀螺差频
            if(ui->checkBox_29->isChecked())
            {
                auto C5VXgyroDifFrequency_max = std::max_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));
                auto C5VXgyroDifFrequency_min = std::min_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));

                if(*C5VXgyroDifFrequency_max >= biggest)
                    biggest = *C5VXgyroDifFrequency_max;
                if(*C5VXgyroDifFrequency_min <= smallest)
                    smallest = *C5VXgyroDifFrequency_min;
            }
            if(ui->checkBox_31->isChecked())
            {
                auto C5VYgyroDifFrequency_max = std::max_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));
                auto C5VYgyroDifFrequency_min = std::min_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));

                if(*C5VYgyroDifFrequency_max >= biggest)
                    biggest = *C5VYgyroDifFrequency_max;
                if(*C5VYgyroDifFrequency_min <= smallest)
                    smallest = *C5VYgyroDifFrequency_min;
            }
            if(ui->checkBox_30->isChecked())
            {
                auto C5VZgyroDifFrequency_max = std::max_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));
                auto C5VZgyroDifFrequency_min = std::min_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));

                if(*C5VZgyroDifFrequency_max >= biggest)
                    biggest = *C5VZgyroDifFrequency_max;
                if(*C5VZgyroDifFrequency_min <= smallest)
                    smallest = *C5VZgyroDifFrequency_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


            //X Y Z加速度计差频
            if(ui->checkBox_32->isChecked())
            {
                auto C5VXaccelerometerDifFre_max = std::max_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));
                auto C5VXaccelerometerDifFre_min = std::min_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));

                if(*C5VXaccelerometerDifFre_max >= biggest)
                    biggest = *C5VXaccelerometerDifFre_max;
                if(*C5VXaccelerometerDifFre_min <= smallest)
                    smallest = *C5VXaccelerometerDifFre_min;
            }
            if(ui->checkBox_33->isChecked())
            {
                auto C5VYaccelerometerDifFre_max = std::max_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));
                auto C5VYaccelerometerDifFre_min = std::min_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));

                if(*C5VYaccelerometerDifFre_max >= biggest)
                    biggest = *C5VYaccelerometerDifFre_max;
                if(*C5VYaccelerometerDifFre_min <= smallest)
                    smallest = *C5VYaccelerometerDifFre_min;
            }
            if(ui->checkBox_34->isChecked())
            {
                auto C5VZaccelerometerDifFre_max = std::max_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));
                auto C5VZaccelerometerDifFre_min = std::min_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));

                if(*C5VZaccelerometerDifFre_max >= biggest)
                    biggest = *C5VZaccelerometerDifFre_max;
                if(*C5VZaccelerometerDifFre_min <= smallest)
                    smallest = *C5VZaccelerometerDifFre_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);
        }
        //X Y Z陀螺温度1数据
       if(ui->checkBox_37->isChecked())
       {
           auto C5VXgyroTemp1_max = std::max_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));
           auto C5VXgyroTemp1_min = std::min_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));

           if(*C5VXgyroTemp1_max >= biggest)
               biggest = *C5VXgyroTemp1_max;
           if(*C5VXgyroTemp1_min <= smallest)
               smallest = *C5VXgyroTemp1_min;
       }
       if(ui->checkBox_35->isChecked())
       {
           auto C5VYgyroTemp1_max = std::max_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));
           auto C5VYgyroTemp1_min = std::min_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));

           if(*C5VYgyroTemp1_max >= biggest)
               biggest = *C5VYgyroTemp1_max;
           if(*C5VYgyroTemp1_min <= smallest)
               smallest = *C5VYgyroTemp1_min;
       }
       if(ui->checkBox_36->isChecked())
       {
           auto C5VZgyroTemp1_max = std::max_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));
           auto C5VZgyroTemp1_min = std::min_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));

           if(*C5VZgyroTemp1_max >= biggest)
               biggest = *C5VZgyroTemp1_max;
           if(*C5VZgyroTemp1_min <= smallest)
               smallest = *C5VZgyroTemp1_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

        //X Y Z加速度计温度1数据
       if(ui->checkBox_40->isChecked())
       {
           auto C5VXAccelerometerTemperture_max = std::max_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));
           auto C5VXAccelerometerTemperture_min = std::min_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));

           if(*C5VXAccelerometerTemperture_max >= biggest)
               biggest = *C5VXAccelerometerTemperture_max;
           if(*C5VXAccelerometerTemperture_min <= smallest)
               smallest = *C5VXAccelerometerTemperture_min;
       }
       if(ui->checkBox_38->isChecked())
       {
           auto C5VYAccelerometerTemperture_max = std::max_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));
           auto C5VYAccelerometerTemperture_min = std::min_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));

           if(*C5VYAccelerometerTemperture_max >= biggest)
               biggest = *C5VYAccelerometerTemperture_max;
           if(*C5VYAccelerometerTemperture_min <= smallest)
               smallest = *C5VYAccelerometerTemperture_min;
       }
       if(ui->checkBox_39->isChecked())
       {
           auto C5VZAccelerometerTemperture_max = std::max_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));
           auto C5VZAccelerometerTemperture_min = std::min_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));

           if(*C5VZAccelerometerTemperture_max >= biggest)
               biggest = *C5VZAccelerometerTemperture_max;
           if(*C5VZAccelerometerTemperture_min <= smallest)
               smallest = *C5VZAccelerometerTemperture_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

        //X Y Z陀螺温度2数据
       if(ui->checkBox_42->isChecked())
       {
           auto C5VXgyroTemp2_max = std::max_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));
           auto C5VXgyroTemp2_min = std::min_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));

           if(*C5VXgyroTemp2_max >= biggest)
               biggest = *C5VXgyroTemp2_max;
           if(*C5VXgyroTemp2_min <= smallest)
               smallest = *C5VXgyroTemp2_min;
       }
       if(ui->checkBox_43->isChecked())
       {
           auto C5VYgyroTemp2_max = std::max_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));
           auto C5VYgyroTemp2_min = std::min_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));

           if(*C5VYgyroTemp2_max >= biggest)
               biggest = *C5VYgyroTemp2_max;
           if(*C5VYgyroTemp2_min <= smallest)
               smallest = *C5VYgyroTemp2_min;
       }
       if(ui->checkBox_41->isChecked())
       {
           auto C5VZgyroTemp2_max = std::max_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));
           auto C5VZgyroTemp2_min = std::min_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));

           if(*C5VZgyroTemp2_max >= biggest)
               biggest = *C5VZgyroTemp2_max;
           if(*C5VZgyroTemp2_min <= smallest)
               smallest = *C5VZgyroTemp2_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


        //X Y Z陀螺抖幅数据
       if(ui->checkBox_45->isChecked())
       {
           auto C5VXgyroAmplitudeJitter_max = std::max_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));
           auto C5VXgyroAmplitudeJitter_min = std::min_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));

           if(*C5VXgyroAmplitudeJitter_max >= biggest)
               biggest = *C5VXgyroAmplitudeJitter_max;
           if(*C5VXgyroAmplitudeJitter_min <= smallest)
               smallest = *C5VXgyroAmplitudeJitter_min;
       }
       if(ui->checkBox_46->isChecked())
       {
           auto C5VYgyroAmplitudeJitter_max = std::max_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));
           auto C5VYgyroAmplitudeJitter_min = std::min_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));

           if(*C5VYgyroAmplitudeJitter_max >= biggest)
               biggest = *C5VYgyroAmplitudeJitter_max;
           if(*C5VYgyroAmplitudeJitter_min <= smallest)
               smallest = *C5VYgyroAmplitudeJitter_min;
       }
       if(ui->checkBox_44->isChecked())
       {
           auto C5VZgyroAmplitudeJitter_max = std::max_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));
           auto C5VZgyroAmplitudeJitter_min = std::min_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));

           if(*C5VZgyroAmplitudeJitter_max >= biggest)
               biggest = *C5VZgyroAmplitudeJitter_max;
           if(*C5VZgyroAmplitudeJitter_min <= smallest)
               smallest = *C5VZgyroAmplitudeJitter_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


        //X Y Z陀螺抖频数据
       if(ui->checkBox_48->isChecked())
       {
           auto C5VXgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));
           auto C5VXgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));

           if(*C5VXgyroAmpl1itudeFre_max >= biggest)
               biggest = *C5VXgyroAmpl1itudeFre_max;
           if(*C5VXgyroAmpl1itudeFre_min <= smallest)
               smallest = *C5VXgyroAmpl1itudeFre_min;
       }
       if(ui->checkBox_49->isChecked())
       {
           auto C5VYgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));
           auto C5VYgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));

           if(*C5VYgyroAmpl1itudeFre_max >= biggest)
               biggest = *C5VYgyroAmpl1itudeFre_max;
           if(*C5VYgyroAmpl1itudeFre_min <= smallest)
               smallest = *C5VYgyroAmpl1itudeFre_min;
       }
       if(ui->checkBox_47->isChecked())
       {
           auto C5VZgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));
           auto C5VZgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));

           if(*C5VZgyroAmpl1itudeFre_max >= biggest)
               biggest = *C5VZgyroAmpl1itudeFre_max;
           if(*C5VZgyroAmpl1itudeFre_min <= smallest)
               smallest = *C5VZgyroAmpl1itudeFre_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


        //GPS纬度
       if(ui->checkBox_51->isChecked())
       {
           auto C3VGPSlatitude_max = std::max_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));
           auto C3VGPSlatitude_min = std::min_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));

           if(*C3VGPSlatitude_max >= biggest)
               biggest = *C3VGPSlatitude_max;
           if(*C3VGPSlatitude_min <= smallest)
               smallest = *C3VGPSlatitude_min;
       }
       if(ui->checkBox_54->isChecked())
       {
           auto C3Vlongitude_max = std::max_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));
           auto C3Vlongitude_min = std::min_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));

           if(*C3Vlongitude_max >= biggest)
               biggest = *C3Vlongitude_max;
           if(*C3Vlongitude_min <= smallest)
               smallest = *C3Vlongitude_min;
       }
       if(ui->checkBox_50->isChecked())
       {
           auto C3VtogetherSpeed_max = std::max_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));
           auto C3VtogetherSpeed_min = std::min_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));

           if(*C3VtogetherSpeed_max >= biggest)
               biggest = *C3VtogetherSpeed_max;
           if(*C3VtogetherSpeed_min <= smallest)
               smallest = *C3VtogetherSpeed_min;
       }

       if(ui->checkBox_52->isChecked())
       {
           auto C3VheadingAngle_max = std::max_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));
           auto C3VheadingAngle_min = std::min_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));

           if(*C3VheadingAngle_max >= biggest)
               biggest = *C3VheadingAngle_max;
           if(*C3VheadingAngle_min <= smallest)
               smallest = *C3VheadingAngle_min;
       }
       if(ui->checkBox_53->isChecked())
       {
           auto C3VcombinedEastSpeed_max = std::max_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));
           auto C3VcombinedEastSpeed_min = std::min_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));

           if(*C3VcombinedEastSpeed_max >= biggest)
               biggest = *C3VcombinedEastSpeed_max;
           if(*C3VcombinedEastSpeed_min <= smallest)
               smallest = *C3VcombinedEastSpeed_min;
       }
       if(ui->checkBox_60->isChecked())
       {
           auto C3VcombinedNorthSpeed_max = std::max_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));
           auto C3VcombinedNorthSpeed_min = std::min_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));

           if(*C3VcombinedNorthSpeed_max >= biggest)
               biggest = *C3VcombinedNorthSpeed_max;
           if(*C3VcombinedNorthSpeed_min <= smallest)
               smallest = *C3VcombinedNorthSpeed_min;
       }
        ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
        ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

        //多普勒,电磁
        if(ui->checkBox_59->isChecked())
        {
            auto C3VwaterX_max = std::max_element(std::begin(C3VwaterX), std::end(C3VwaterX));
            auto C3VwaterX_min = std::min_element(std::begin(C3VwaterX), std::end(C3VwaterX));

            if(*C3VwaterX_max >= biggest)
                biggest = *C3VwaterX_max;
            if(*C3VwaterX_min <= smallest)
                smallest = *C3VwaterX_min;
        }
        if(ui->checkBox_56->isChecked())
        {
            auto C3VwaterY_max = std::max_element(std::begin(C3VwaterY), std::end(C3VwaterY));
            auto C3VwaterY_min = std::min_element(std::begin(C3VwaterY), std::end(C3VwaterY));

            if(*C3VwaterY_max >= biggest)
                biggest = *C3VwaterY_max;
            if(*C3VwaterY_min <= smallest)
                smallest = *C3VwaterY_min;
        }

        if(ui->checkBox_57->isChecked())
        {
            auto C3VbottomX_max = std::max_element(std::begin(C3VbottomX), std::end(C3VbottomX));
            auto C3VbottomX_min = std::min_element(std::begin(C3VbottomX), std::end(C3VbottomX));

            if(*C3VbottomX_max >= biggest)
                biggest = *C3VbottomX_max;
            if(*C3VbottomX_min <= smallest)
                smallest = *C3VbottomX_min;
        }
        if(ui->checkBox_55->isChecked())
        {
            auto C3VbottomY_max = std::max_element(std::begin(C3VbottomY), std::end(C3VbottomY));
            auto C3VbottomY_min = std::min_element(std::begin(C3VbottomY), std::end(C3VbottomY));

            if(*C3VbottomY_max >= biggest)
                biggest = *C3VbottomY_max;
            if(*C3VbottomY_min <= smallest)
                smallest = *C3VbottomY_min;
        }
        if(ui->checkBox_58->isChecked())
        {
            auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));
            auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));

            if(*C3VelectromagnetismSpeed_max >= biggest)
                biggest = *C3VelectromagnetismSpeed_max;
            if(*C3VelectromagnetismSpeed_min <= smallest)
                smallest = *C3VelectromagnetismSpeed_min;
        }
         ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
         ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

         if(0)
         {
             //X Y Z陀螺零偏
             if(ui->checkBox_61->isChecked())
             {
                 auto C6VC6XGroyFloat_max = std::max_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));
                 auto C6VC6XGroyFloat_min = std::min_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));

                 if(*C6VC6XGroyFloat_max >= biggest)
                     biggest = *C6VC6XGroyFloat_max;
                 if(*C6VC6XGroyFloat_min <= smallest)
                     smallest = *C6VC6XGroyFloat_min;
             }
             if(ui->checkBox_63->isChecked())
             {
                 auto C6VC6YGroyFloat_max = std::max_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));
                 auto C6VC6YGroyFloat_min = std::min_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));

                 if(*C6VC6YGroyFloat_max >= biggest)
                     biggest = *C6VC6YGroyFloat_max;
                 if(*C6VC6YGroyFloat_min <= smallest)
                     smallest = *C6VC6YGroyFloat_min;
             }
             if(ui->checkBox_62->isChecked())
             {
                 auto C6VC6ZGroyFloat_max = std::max_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));
                 auto C6VC6ZGroyFloat_min = std::min_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));

                 if(*C6VC6ZGroyFloat_max >= biggest)
                     biggest = *C6VC6ZGroyFloat_max;
                 if(*C6VC6ZGroyFloat_min <= smallest)
                     smallest = *C6VC6ZGroyFloat_min;
             }
             ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
             ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


             //X Y Z加速度计零偏
             if(ui->checkBox_65->isChecked())
             {
                 auto C6VC6XAccelerometerFloat_max = std::max_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));
                 auto C6VC6XAccelerometerFloat_min = std::min_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));

                 if(*C6VC6XAccelerometerFloat_max >= biggest)
                     biggest = *C6VC6XAccelerometerFloat_max;
                 if(*C6VC6XAccelerometerFloat_min <= smallest)
                     smallest = *C6VC6XAccelerometerFloat_min;
             }
             if(ui->checkBox_64->isChecked())
             {
                 auto C6VC6YAccelerometerFloat_max = std::max_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));
                 auto C6VC6YAccelerometerFloat_min = std::min_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));

                 if(*C6VC6YAccelerometerFloat_max >= biggest)
                     biggest = *C6VC6YAccelerometerFloat_max;
                 if(*C6VC6YAccelerometerFloat_min <= smallest)
                     smallest = *C6VC6YAccelerometerFloat_min;
             }
             if(ui->checkBox_66->isChecked())
             {
                 auto C6VC6ZAccelerometerFloat_max = std::max_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));
                 auto C6VC6ZAccelerometerFloat_min = std::min_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));

                 if(*C6VC6ZAccelerometerFloat_max >= biggest)
                     biggest = *C6VC6ZAccelerometerFloat_max;
                 if(*C6VC6ZAccelerometerFloat_min <= smallest)
                     smallest = *C6VC6ZAccelerometerFloat_min;
             }
             ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
             ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);
         }
            //速度误差
            if(ui->checkBox_67->isChecked())
            {
                auto VeastSpeedError_max = std::max_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));
                auto VeastSpeedError_min = std::min_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));

                if(*VeastSpeedError_max >= biggest)
                    biggest = *VeastSpeedError_max;
                if(*VeastSpeedError_min <= smallest)
                    smallest = *VeastSpeedError_min;
            }
            if(ui->checkBox_69->isChecked())
            {
                auto VnorthSpeedError_max = std::max_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));
                auto VnorthSpeedError_min = std::min_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));

                if(*VnorthSpeedError_max >= biggest)
                    biggest = *VnorthSpeedError_max;
                if(*VnorthSpeedError_min <= smallest)
                    smallest = *VnorthSpeedError_min;
            }
            if(ui->checkBox_68->isChecked())
            {
                auto VtogetherSpeedError_max = std::max_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));
                auto VtogetherSpeedError_min = std::min_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));

                if(*VtogetherSpeedError_max >= biggest)
                    biggest = *VtogetherSpeedError_max;
                if(*VtogetherSpeedError_min <= smallest)
                    smallest = *VtogetherSpeedError_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

            //位置误差
            if(ui->checkBox_70->isChecked())
            {
                auto VlatitudeError_max = std::max_element(std::begin(VlatitudeError), std::end(VlatitudeError));
                auto VlatitudeError_min = std::min_element(std::begin(VlatitudeError), std::end(VlatitudeError));

                if(*VlatitudeError_max >= biggest)
                    biggest = *VlatitudeError_max;
                if(*VlatitudeError_min <= smallest)
                    smallest = *VlatitudeError_min;
            }
            if(ui->checkBox_72->isChecked())
            {
                auto VlongitudeError_max = std::max_element(std::begin(VlongitudeError), std::end(VlongitudeError));
                auto VlongitudeError_min = std::min_element(std::begin(VlongitudeError), std::end(VlongitudeError));

                if(*VlongitudeError_max >= biggest)
                    biggest = *VlongitudeError_max;
                if(*VlongitudeError_min <= smallest)
                    smallest = *VlongitudeError_min;
            }
            if(ui->checkBox_71->isChecked())
            {
                auto VpositionError_max = std::max_element(std::begin(VpositionError), std::end(VpositionError));
                auto VpositionError_min = std::min_element(std::begin(VpositionError), std::end(VpositionError));

                if(*VpositionError_max >= biggest)
                    biggest = *VpositionError_max;
                if(*VpositionError_min <= smallest)
                    smallest = *VpositionError_min;
            }
            ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
            ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

//    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
//    ui->customPlot2->yAxis->setRange(ui->customPlot2->yAxis->range().lower, ui->customPlot2->yAxis->range().upper, Qt::AlignLeft);

//    if(ui->checkBox->isChecked())
//    {
//        ui->customPlot2->yAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
//        ui->customPlot2->yAxis->setRange(0, ui->customPlot2->yAxis->range().upper*1.5, Qt::AlignBottom);
//       //
//    }

//    if(ui->checkBox_2->isChecked())
//    {
//        ui->customPlot2->yAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
//        ui->customPlot2->yAxis->setRange(0, ui->customPlot2->yAxis->range().upper*1.5, Qt::AlignTop);

//    }
}
void MainWindow::set_checkBox_1_2_73_74_75()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox->isChecked())
    {
        auto C1Vlatitude_max = std::max_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));
        auto C1Vlatitude_min = std::min_element(std::begin(C1Vlatitude), std::end(C1Vlatitude));

        if(*C1Vlatitude_max >= biggest)
            biggest = *C1Vlatitude_max;
        if(*C1Vlatitude_min <= smallest)
            smallest = *C1Vlatitude_min;
    }
    if(ui->checkBox_2->isChecked())
    {
        auto C1Vlongitude_max = std::max_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));
        auto C1Vlongitude_min = std::min_element(std::begin(C1Vlongitude), std::end(C1Vlongitude));

        if(*C1Vlongitude_max >= biggest)
            biggest = *C1Vlongitude_max;
        if(*C1Vlongitude_min <= smallest)
            smallest = *C1Vlongitude_min;
    }

    if(ui->checkBox_73->isChecked())
    {
        auto C6UndampedLatFloat_max = std::max_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));
        auto C6UndampedLatFloat_min = std::min_element(std::begin(C6VC6UndampedLatFloat), std::end(C6VC6UndampedLatFloat));

        if(*C6UndampedLatFloat_max >= biggest)
            biggest = *C6UndampedLatFloat_max;
        if(*C6UndampedLatFloat_min <= smallest)
            smallest = *C6UndampedLatFloat_min;
    }
    if(ui->checkBox_74->isChecked())
    {
        auto C6UndampedLongFloat_max = std::max_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));
        auto C6UndampedLongFloat_min = std::min_element(std::begin(C6VC6UndampedLongFloat), std::end(C6VC6UndampedLongFloat));

        if(*C6UndampedLongFloat_max >= biggest)
            biggest = *C6UndampedLongFloat_max;
        if(*C6UndampedLongFloat_min <= smallest)
            smallest = *C6UndampedLongFloat_min;
    }
    if(ui->checkBox_75->isChecked())
    {
        auto C6UndampedHeightFloat_max = std::max_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));
        auto C6UndampedHeightFloat_min = std::min_element(std::begin(C6VC6UndampedHeightFloat), std::end(C6VC6UndampedHeightFloat));

        if(*C6UndampedHeightFloat_max >= biggest)
            biggest = *C6UndampedHeightFloat_max;
        if(*C6UndampedHeightFloat_min <= smallest)
            smallest = *C6UndampedHeightFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


}
void MainWindow::set_checkBox_5_3_4_79_80_81()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_5->isChecked())
    {
        auto C1VheadingAngle_max = std::max_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));
        auto C1VheadingAngle_min = std::min_element(std::begin(C1VheadingAngle), std::end(C1VheadingAngle));

        if(*C1VheadingAngle_max >= biggest)
            biggest = *C1VheadingAngle_max;
        if(*C1VheadingAngle_min <= smallest)
            smallest = *C1VheadingAngle_min;
    }
    if(ui->checkBox_3->isChecked())
    {
        auto C1VrollAngle_max = std::max_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));
        auto C1VrollAngle_min = std::min_element(std::begin(C1VrollAngle), std::end(C1VrollAngle));

        if(*C1VrollAngle_max >= biggest)
            biggest = *C1VrollAngle_max;
        if(*C1VrollAngle_min <= smallest)
            smallest = *C1VrollAngle_min;
    }
    if(ui->checkBox_4->isChecked())
    {
        auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));
        auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngle), std::end(C1VpitchAngle));

        if(*C1VpitchAngle_max >= biggest)
            biggest = *C1VpitchAngle_max;
        if(*C1VpitchAngle_min <= smallest)
            smallest = *C1VpitchAngle_min;
    }
    if(ui->checkBox_79->isChecked())
    {
        auto C6UndampedRollAngleFloat_max = std::max_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));
        auto C6UndampedRollAngleFloat_min = std::min_element(std::begin(C6VC6UndampedRollAngleFloat), std::end(C6VC6UndampedRollAngleFloat));

        if(*C6UndampedRollAngleFloat_max >= biggest)
            biggest = *C6UndampedRollAngleFloat_max;
        if(*C6UndampedRollAngleFloat_min <= smallest)
            smallest = *C6UndampedRollAngleFloat_min;
    }
    if(ui->checkBox_80->isChecked())
    {
        auto C6UndampedPitchAngleFloat_max = std::max_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));
        auto C6UndampedPitchAngleFloat_min = std::min_element(std::begin(C6VC6UndampedPitchAngleFloat), std::end(C6VC6UndampedPitchAngleFloat));

        if(*C6UndampedPitchAngleFloat_max >= biggest)
            biggest = *C6UndampedPitchAngleFloat_max;
        if(*C6UndampedPitchAngleFloat_min <= smallest)
            smallest = *C6UndampedPitchAngleFloat_min;
    }
    if(ui->checkBox_81->isChecked())
    {
        auto C6UndampedHeadingAngularFloat_max = std::max_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));
        auto C6UndampedHeadingAngularFloat_min = std::min_element(std::begin(C6VC6UndampedHeadingAngularFloat), std::end(C6VC6UndampedHeadingAngularFloat));

        if(*C6UndampedHeadingAngularFloat_max >= biggest)
            biggest = *C6UndampedHeadingAngularFloat_max;
        if(*C6UndampedHeadingAngularFloat_min <= smallest)
            smallest = *C6UndampedHeadingAngularFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


}
void MainWindow::set_checkBox_9_10_76_77_78()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_9->isChecked())
    {
        auto C1VnorthSpeed_max = std::max_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));
        auto C1VnorthSpeed_min = std::min_element(std::begin(C1VnorthSpeed), std::end(C1VnorthSpeed));

        if(*C1VnorthSpeed_max >= biggest)
            biggest = *C1VnorthSpeed_max;
        if(*C1VnorthSpeed_min <= smallest)
            smallest = *C1VnorthSpeed_min;
    }
    if(ui->checkBox_10->isChecked())
    {
        auto C1VeastSpeed_max = std::max_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));
        auto C1VeastSpeed_min = std::min_element(std::begin(C1VeastSpeed), std::end(C1VeastSpeed));

        if(*C1VeastSpeed_max >= biggest)
            biggest = *C1VeastSpeed_max;
        if(*C1VeastSpeed_min <= smallest)
            smallest = *C1VeastSpeed_min;
    }
    if(ui->checkBox_76->isChecked())
    {
        auto C6UndampedNorthSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));
        auto C6UndampedNorthSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedNorthSpeedFloat), std::end(C6VC6UndampedNorthSpeedFloat));

        if(*C6UndampedNorthSpeedFloat_max >= biggest)
            biggest = *C6UndampedNorthSpeedFloat_max;
        if(*C6UndampedNorthSpeedFloat_min <= smallest)
            smallest = *C6UndampedNorthSpeedFloat_min;
    }
    if(ui->checkBox_77->isChecked())
    {
        auto C6UndampedEastSpeedFloat_max = std::max_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));
        auto C6UndampedEastSpeedFloat_min = std::min_element(std::begin(C6VC6UndampedEastSpeedFloat), std::end(C6VC6UndampedEastSpeedFloat));

        if(*C6UndampedEastSpeedFloat_max >= biggest)
            biggest = *C6UndampedEastSpeedFloat_max;
        if(*C6UndampedEastSpeedFloat_min <= smallest)
            smallest = *C6UndampedEastSpeedFloat_min;
    }
    if(ui->checkBox_78->isChecked())
    {
        auto C6VerticalVelocityFloat_max = std::max_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));
        auto C6VerticalVelocityFloat_min = std::min_element(std::begin(C6VC6VerticalVelocityFloat), std::end(C6VC6VerticalVelocityFloat));

        if(*C6VerticalVelocityFloat_max >= biggest)
            biggest = *C6VerticalVelocityFloat_max;
        if(*C6VerticalVelocityFloat_min <= smallest)
            smallest = *C6VerticalVelocityFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


}
void MainWindow::set_checkBox_6_7_8()
{
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_6->isChecked())
    {
        auto C1VheadingAngle_max = std::max_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));
        auto C1VheadingAngle_min = std::min_element(std::begin(C1VheadingAngularSpeed), std::end(C1VheadingAngularSpeed));

        if(*C1VheadingAngle_max >= biggest)
            biggest = *C1VheadingAngle_max;
        if(*C1VheadingAngle_min <= smallest)
            smallest = *C1VheadingAngle_min;
    }
    if(ui->checkBox_7->isChecked())
    {
        auto C1VrollAngle_max = std::max_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));
        auto C1VrollAngle_min = std::min_element(std::begin(C1VrollAngleSpeed), std::end(C1VrollAngleSpeed));

        if(*C1VrollAngle_max >= biggest)
            biggest = *C1VrollAngle_max;
        if(*C1VrollAngle_min <= smallest)
            smallest = *C1VrollAngle_min;
    }
    if(ui->checkBox_8->isChecked())
    {
        auto C1VpitchAngle_max = std::max_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));
        auto C1VpitchAngle_min = std::min_element(std::begin(C1VpitchAngleSpeed), std::end(C1VpitchAngleSpeed));

        if(*C1VpitchAngle_max >= biggest)
            biggest = *C1VpitchAngle_max;
        if(*C1VpitchAngle_min <= smallest)
            smallest = *C1VpitchAngle_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


}

void MainWindow::set_checkBox_12_13_11_15_16_14()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_12->isChecked())
    {
        auto C1Vheave_max = std::max_element(std::begin(C1Vheave), std::end(C1Vheave));
        auto C1Vheave_min = std::min_element(std::begin(C1Vheave), std::end(C1Vheave));

        if(*C1Vheave_max >= biggest)
            biggest = *C1Vheave_max;
        if(*C1Vheave_min <= smallest)
            smallest = *C1Vheave_min;
    }
    if(ui->checkBox_13->isChecked())
    {
        auto C1VverticalVelocity_max = std::max_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));
        auto C1VverticalVelocity_min = std::min_element(std::begin(C1VverticalVelocity), std::end(C1VverticalVelocity));

        if(*C1VverticalVelocity_max >= biggest)
            biggest = *C1VverticalVelocity_max;
        if(*C1VverticalVelocity_min <= smallest)
            smallest = *C1VverticalVelocity_min;
    }
    if(ui->checkBox_11->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
        auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }

    if(ui->checkBox_15->isChecked())
    {
        auto C1VtransverseVelocity_max = std::max_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));
        auto C1VtransverseVelocity_min = std::min_element(std::begin(C1VtransverseVelocity), std::end(C1VtransverseVelocity));

        if(*C1VtransverseVelocity_max >= biggest)
            biggest = *C1VtransverseVelocity_max;
        if(*C1VtransverseVelocity_min <= smallest)
            smallest = *C1VtransverseVelocity_min;
    }
    if(ui->checkBox_16->isChecked())
    {
        auto C1Vsurge_max = std::max_element(std::begin(C1Vsurge), std::end(C1Vsurge));
        auto C1Vsurge_min = std::min_element(std::begin(C1Vsurge), std::end(C1Vsurge));

        if(*C1Vsurge_max >= biggest)
            biggest = *C1Vsurge_max;
        if(*C1Vsurge_min <= smallest)
            smallest = *C1Vsurge_min;
    }
    if(ui->checkBox_14->isChecked())
    {
        auto C1Vsway_max = std::max_element(std::begin(C1Vsway), std::end(C1Vsway));
        auto C1Vsway_min = std::min_element(std::begin(C1Vsway), std::end(C1Vsway));

        if(*C1Vsway_max >= biggest)
            biggest = *C1Vsway_max;
        if(*C1Vsway_min <= smallest)
            smallest = *C1Vsway_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


}
void MainWindow::set_checkBox_19_18_17()
{
    double biggest = -999999999;
    double smallest = 999999999;

    if(ui->checkBox_19->isChecked())
    {
        auto C5VXGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));
        auto C5VXGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VXGyroAngleIncreaseFloat), std::end(C5VXGyroAngleIncreaseFloat));

        if(*C5VXGyroAngleIncreaseFloat_max >= biggest)
            biggest = *C5VXGyroAngleIncreaseFloat_max;
        if(*C5VXGyroAngleIncreaseFloat_min <= smallest)
            smallest = *C5VXGyroAngleIncreaseFloat_min;
    }
    if(ui->checkBox_18->isChecked())
    {
        auto C5VYGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));
        auto C5VYGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VYGyroAngleIncreaseFloat), std::end(C5VYGyroAngleIncreaseFloat));

        if(*C5VYGyroAngleIncreaseFloat_max >= biggest)
            biggest = *C5VYGyroAngleIncreaseFloat_max;
        if(*C5VYGyroAngleIncreaseFloat_min <= smallest)
            smallest = *C5VYGyroAngleIncreaseFloat_min;
    }
    if(ui->checkBox_17->isChecked())
    {
        auto C5VZGyroAngleIncreaseFloat_max = std::max_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));
        auto C5VZGyroAngleIncreaseFloat_min = std::min_element(std::begin(C5VZGyroAngleIncreaseFloat), std::end(C5VZGyroAngleIncreaseFloat));

        if(*C5VZGyroAngleIncreaseFloat_max >= biggest)
            biggest = *C5VZGyroAngleIncreaseFloat_max;
        if(*C5VZGyroAngleIncreaseFloat_min <= smallest)
            smallest = *C5VZGyroAngleIncreaseFloat_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


}
void MainWindow::set_checkBox_20_21_22()
{
    //X Y Z加表增量
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_20->isChecked())
   {
       auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));
       auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXAccelerometerSpeedIncrementFloat), std::end(C5VXAccelerometerSpeedIncrementFloat));

       if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
       if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VXAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_21->isChecked())
   {
       auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));
       auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYAccelerometerSpeedIncrementFloat), std::end(C5VYAccelerometerSpeedIncrementFloat));

       if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
       if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VYAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_22->isChecked())
   {
       auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));
       auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZAccelerometerSpeedIncrementFloat), std::end(C5VZAccelerometerSpeedIncrementFloat));

       if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
       if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VZAccelerometerSpeedIncrementFloat_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_23_24_25()
{
    //X Y Z陀螺1s补偿后角增量
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_23->isChecked())
   {
       auto C5VXAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));
       auto C5VXAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VXgyroCompensatedAngleIncrementFloat), std::end(C5VXgyroCompensatedAngleIncrementFloat));

       if(*C5VXAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VXAccelerometerSpeedIncrementFloat_max;
       if(*C5VXAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VXAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_24->isChecked())
   {
       auto C5VYAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));
       auto C5VYAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VYgyroCompensatedAngleIncrementFloat), std::end(C5VYgyroCompensatedAngleIncrementFloat));

       if(*C5VYAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VYAccelerometerSpeedIncrementFloat_max;
       if(*C5VYAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VYAccelerometerSpeedIncrementFloat_min;
   }
   if(ui->checkBox_25->isChecked())
   {
       auto C5VZAccelerometerSpeedIncrementFloat_max = std::max_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));
       auto C5VZAccelerometerSpeedIncrementFloat_min = std::min_element(std::begin(C5VZgyroCompensatedAngleIncrementFloat), std::end(C5VZgyroCompensatedAngleIncrementFloat));

       if(*C5VZAccelerometerSpeedIncrementFloat_max >= biggest)
           biggest = *C5VZAccelerometerSpeedIncrementFloat_max;
       if(*C5VZAccelerometerSpeedIncrementFloat_min <= smallest)
           smallest = *C5VZAccelerometerSpeedIncrementFloat_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}

void MainWindow::set_checkBox_26_27_28()
{
    //X Y Z加速度计1s补偿后速度增量
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_26->isChecked())
   {
       auto C5VXAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));
       auto C5VXAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VXAccVelocityIncrementFloat), std::end(C5VXAccVelocityIncrementFloat));

       if(*C5VXAccVelocityIncrementFloat_max >= biggest)
           biggest = *C5VXAccVelocityIncrementFloat_max;
       if(*C5VXAccVelocityIncrementFloat_min <= smallest)
           smallest = *C5VXAccVelocityIncrementFloat_min;
   }
   if(ui->checkBox_27->isChecked())
   {
       auto C5VYAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));
       auto C5VYAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VYAccVelocityIncrementFloat), std::end(C5VYAccVelocityIncrementFloat));

       if(*C5VYAccVelocityIncrementFloat_max >= biggest)
           biggest = *C5VYAccVelocityIncrementFloat_max;
       if(*C5VYAccVelocityIncrementFloat_min <= smallest)
           smallest = *C5VYAccVelocityIncrementFloat_min;
   }
   if(ui->checkBox_28->isChecked())
   {
       auto C5VZAccVelocityIncrementFloat_max = std::max_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));
       auto C5VZAccVelocityIncrementFloat_min = std::min_element(std::begin(C5VZAccVelocityIncrementFloat), std::end(C5VZAccVelocityIncrementFloat));

       if(*C5VZAccVelocityIncrementFloat_max >= biggest)
           biggest = *C5VZAccVelocityIncrementFloat_max;
       if(*C5VZAccVelocityIncrementFloat_min <= smallest)
           smallest = *C5VZAccVelocityIncrementFloat_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}

void MainWindow::set_checkBox_29_30_31()
{
    //X Y Z陀螺差频
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_29->isChecked())
   {
       auto C5VXgyroDifFrequency_max = std::max_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));
       auto C5VXgyroDifFrequency_min = std::min_element(std::begin(C5VXgyroDifFrequency), std::end(C5VXgyroDifFrequency));

       if(*C5VXgyroDifFrequency_max >= biggest)
           biggest = *C5VXgyroDifFrequency_max;
       if(*C5VXgyroDifFrequency_min <= smallest)
           smallest = *C5VXgyroDifFrequency_min;
   }
   if(ui->checkBox_31->isChecked())
   {
       auto C5VYgyroDifFrequency_max = std::max_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));
       auto C5VYgyroDifFrequency_min = std::min_element(std::begin(C5VYgyroDifFrequency), std::end(C5VYgyroDifFrequency));

       if(*C5VYgyroDifFrequency_max >= biggest)
           biggest = *C5VYgyroDifFrequency_max;
       if(*C5VYgyroDifFrequency_min <= smallest)
           smallest = *C5VYgyroDifFrequency_min;
   }
   if(ui->checkBox_30->isChecked())
   {
       auto C5VZgyroDifFrequency_max = std::max_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));
       auto C5VZgyroDifFrequency_min = std::min_element(std::begin(C5VZgyroDifFrequency), std::end(C5VZgyroDifFrequency));

       if(*C5VZgyroDifFrequency_max >= biggest)
           biggest = *C5VZgyroDifFrequency_max;
       if(*C5VZgyroDifFrequency_min <= smallest)
           smallest = *C5VZgyroDifFrequency_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}

void MainWindow::set_checkBox_32_33_34()
{
    //X Y Z加速度计差频
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_32->isChecked())
   {
       auto C5VXaccelerometerDifFre_max = std::max_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));
       auto C5VXaccelerometerDifFre_min = std::min_element(std::begin(C5VXaccelerometerDifFre), std::end(C5VXaccelerometerDifFre));

       if(*C5VXaccelerometerDifFre_max >= biggest)
           biggest = *C5VXaccelerometerDifFre_max;
       if(*C5VXaccelerometerDifFre_min <= smallest)
           smallest = *C5VXaccelerometerDifFre_min;
   }
   if(ui->checkBox_33->isChecked())
   {
       auto C5VYaccelerometerDifFre_max = std::max_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));
       auto C5VYaccelerometerDifFre_min = std::min_element(std::begin(C5VYaccelerometerDifFre), std::end(C5VYaccelerometerDifFre));

       if(*C5VYaccelerometerDifFre_max >= biggest)
           biggest = *C5VYaccelerometerDifFre_max;
       if(*C5VYaccelerometerDifFre_min <= smallest)
           smallest = *C5VYaccelerometerDifFre_min;
   }
   if(ui->checkBox_34->isChecked())
   {
       auto C5VZaccelerometerDifFre_max = std::max_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));
       auto C5VZaccelerometerDifFre_min = std::min_element(std::begin(C5VZaccelerometerDifFre), std::end(C5VZaccelerometerDifFre));

       if(*C5VZaccelerometerDifFre_max >= biggest)
           biggest = *C5VZaccelerometerDifFre_max;
       if(*C5VZaccelerometerDifFre_min <= smallest)
           smallest = *C5VZaccelerometerDifFre_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_37_35_36()
{
    //X Y Z陀螺温度1数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_37->isChecked())
   {
       auto C5VXgyroTemp1_max = std::max_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));
       auto C5VXgyroTemp1_min = std::min_element(std::begin(C5VXgyroTemp1), std::end(C5VXgyroTemp1));

       if(*C5VXgyroTemp1_max >= biggest)
           biggest = *C5VXgyroTemp1_max;
       if(*C5VXgyroTemp1_min <= smallest)
           smallest = *C5VXgyroTemp1_min;
   }
   if(ui->checkBox_35->isChecked())
   {
       auto C5VYgyroTemp1_max = std::max_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));
       auto C5VYgyroTemp1_min = std::min_element(std::begin(C5VYgyroTemp1), std::end(C5VYgyroTemp1));

       if(*C5VYgyroTemp1_max >= biggest)
           biggest = *C5VYgyroTemp1_max;
       if(*C5VYgyroTemp1_min <= smallest)
           smallest = *C5VYgyroTemp1_min;
   }
   if(ui->checkBox_36->isChecked())
   {
       auto C5VZgyroTemp1_max = std::max_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));
       auto C5VZgyroTemp1_min = std::min_element(std::begin(C5VZgyroTemp1), std::end(C5VZgyroTemp1));

       if(*C5VZgyroTemp1_max >= biggest)
           biggest = *C5VZgyroTemp1_max;
       if(*C5VZgyroTemp1_min <= smallest)
           smallest = *C5VZgyroTemp1_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_40_38_39()
{
    //X Y Z加速度计温度1数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_40->isChecked())
   {
       auto C5VXAccelerometerTemperture_max = std::max_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));
       auto C5VXAccelerometerTemperture_min = std::min_element(std::begin(C5VXAccelerometerTemperture), std::end(C5VXAccelerometerTemperture));

       if(*C5VXAccelerometerTemperture_max >= biggest)
           biggest = *C5VXAccelerometerTemperture_max;
       if(*C5VXAccelerometerTemperture_min <= smallest)
           smallest = *C5VXAccelerometerTemperture_min;
   }
   if(ui->checkBox_38->isChecked())
   {
       auto C5VYAccelerometerTemperture_max = std::max_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));
       auto C5VYAccelerometerTemperture_min = std::min_element(std::begin(C5VYAccelerometerTemperture), std::end(C5VYAccelerometerTemperture));

       if(*C5VYAccelerometerTemperture_max >= biggest)
           biggest = *C5VYAccelerometerTemperture_max;
       if(*C5VYAccelerometerTemperture_min <= smallest)
           smallest = *C5VYAccelerometerTemperture_min;
   }
   if(ui->checkBox_39->isChecked())
   {
       auto C5VZAccelerometerTemperture_max = std::max_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));
       auto C5VZAccelerometerTemperture_min = std::min_element(std::begin(C5VZAccelerometerTemperture), std::end(C5VZAccelerometerTemperture));

       if(*C5VZAccelerometerTemperture_max >= biggest)
           biggest = *C5VZAccelerometerTemperture_max;
       if(*C5VZAccelerometerTemperture_min <= smallest)
           smallest = *C5VZAccelerometerTemperture_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_42_43_41()
{
    //X Y Z陀螺温度2数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_42->isChecked())
   {
       auto C5VXgyroTemp2_max = std::max_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));
       auto C5VXgyroTemp2_min = std::min_element(std::begin(C5VXgyroTemp2), std::end(C5VXgyroTemp2));

       if(*C5VXgyroTemp2_max >= biggest)
           biggest = *C5VXgyroTemp2_max;
       if(*C5VXgyroTemp2_min <= smallest)
           smallest = *C5VXgyroTemp2_min;
   }
   if(ui->checkBox_43->isChecked())
   {
       auto C5VYgyroTemp2_max = std::max_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));
       auto C5VYgyroTemp2_min = std::min_element(std::begin(C5VYgyroTemp2), std::end(C5VYgyroTemp2));

       if(*C5VYgyroTemp2_max >= biggest)
           biggest = *C5VYgyroTemp2_max;
       if(*C5VYgyroTemp2_min <= smallest)
           smallest = *C5VYgyroTemp2_min;
   }
   if(ui->checkBox_41->isChecked())
   {
       auto C5VZgyroTemp2_max = std::max_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));
       auto C5VZgyroTemp2_min = std::min_element(std::begin(C5VZgyroTemp2), std::end(C5VZgyroTemp2));

       if(*C5VZgyroTemp2_max >= biggest)
           biggest = *C5VZgyroTemp2_max;
       if(*C5VZgyroTemp2_min <= smallest)
           smallest = *C5VZgyroTemp2_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_45_46_44()
{
    //X Y Z陀螺抖幅数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_45->isChecked())
   {
       auto C5VXgyroAmplitudeJitter_max = std::max_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));
       auto C5VXgyroAmplitudeJitter_min = std::min_element(std::begin(C5VXgyroAmplitudeJitter), std::end(C5VXgyroAmplitudeJitter));

       if(*C5VXgyroAmplitudeJitter_max >= biggest)
           biggest = *C5VXgyroAmplitudeJitter_max;
       if(*C5VXgyroAmplitudeJitter_min <= smallest)
           smallest = *C5VXgyroAmplitudeJitter_min;
   }
   if(ui->checkBox_46->isChecked())
   {
       auto C5VYgyroAmplitudeJitter_max = std::max_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));
       auto C5VYgyroAmplitudeJitter_min = std::min_element(std::begin(C5VYgyroAmplitudeJitter), std::end(C5VYgyroAmplitudeJitter));

       if(*C5VYgyroAmplitudeJitter_max >= biggest)
           biggest = *C5VYgyroAmplitudeJitter_max;
       if(*C5VYgyroAmplitudeJitter_min <= smallest)
           smallest = *C5VYgyroAmplitudeJitter_min;
   }
   if(ui->checkBox_44->isChecked())
   {
       auto C5VZgyroAmplitudeJitter_max = std::max_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));
       auto C5VZgyroAmplitudeJitter_min = std::min_element(std::begin(C5VZgyroAmplitudeJitter), std::end(C5VZgyroAmplitudeJitter));

       if(*C5VZgyroAmplitudeJitter_max >= biggest)
           biggest = *C5VZgyroAmplitudeJitter_max;
       if(*C5VZgyroAmplitudeJitter_min <= smallest)
           smallest = *C5VZgyroAmplitudeJitter_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_48_49_47()
{
    //X Y Z陀螺抖频数据
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_48->isChecked())
   {
       auto C5VXgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));
       auto C5VXgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VXgyroAmpl1itudeFre), std::end(C5VXgyroAmpl1itudeFre));

       if(*C5VXgyroAmpl1itudeFre_max >= biggest)
           biggest = *C5VXgyroAmpl1itudeFre_max;
       if(*C5VXgyroAmpl1itudeFre_min <= smallest)
           smallest = *C5VXgyroAmpl1itudeFre_min;
   }
   if(ui->checkBox_49->isChecked())
   {
       auto C5VYgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));
       auto C5VYgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VYgyroAmpl1itudeFre), std::end(C5VYgyroAmpl1itudeFre));

       if(*C5VYgyroAmpl1itudeFre_max >= biggest)
           biggest = *C5VYgyroAmpl1itudeFre_max;
       if(*C5VYgyroAmpl1itudeFre_min <= smallest)
           smallest = *C5VYgyroAmpl1itudeFre_min;
   }
   if(ui->checkBox_47->isChecked())
   {
       auto C5VZgyroAmpl1itudeFre_max = std::max_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));
       auto C5VZgyroAmpl1itudeFre_min = std::min_element(std::begin(C5VZgyroAmpl1itudeFre), std::end(C5VZgyroAmpl1itudeFre));

       if(*C5VZgyroAmpl1itudeFre_max >= biggest)
           biggest = *C5VZgyroAmpl1itudeFre_max;
       if(*C5VZgyroAmpl1itudeFre_min <= smallest)
           smallest = *C5VZgyroAmpl1itudeFre_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_51_54_50_52_53_60()
{
    //GPS纬度
    double biggest = -999999999;
    double smallest = 999999999;
   if(ui->checkBox_51->isChecked())
   {
       auto C3VGPSlatitude_max = std::max_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));
       auto C3VGPSlatitude_min = std::min_element(std::begin(C3VGPSlatitude), std::end(C3VGPSlatitude));

       if(*C3VGPSlatitude_max >= biggest)
           biggest = *C3VGPSlatitude_max;
       if(*C3VGPSlatitude_min <= smallest)
           smallest = *C3VGPSlatitude_min;
   }
   if(ui->checkBox_54->isChecked())
   {
       auto C3Vlongitude_max = std::max_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));
       auto C3Vlongitude_min = std::min_element(std::begin(C3Vlongitude), std::end(C3Vlongitude));

       if(*C3Vlongitude_max >= biggest)
           biggest = *C3Vlongitude_max;
       if(*C3Vlongitude_min <= smallest)
           smallest = *C3Vlongitude_min;
   }
   if(ui->checkBox_50->isChecked())
   {
       auto C3VtogetherSpeed_max = std::max_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));
       auto C3VtogetherSpeed_min = std::min_element(std::begin(C3VtogetherSpeed), std::end(C3VtogetherSpeed));

       if(*C3VtogetherSpeed_max >= biggest)
           biggest = *C3VtogetherSpeed_max;
       if(*C3VtogetherSpeed_min <= smallest)
           smallest = *C3VtogetherSpeed_min;
   }

   if(ui->checkBox_52->isChecked())
   {
       auto C3VheadingAngle_max = std::max_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));
       auto C3VheadingAngle_min = std::min_element(std::begin(C3VheadingAngle), std::end(C3VheadingAngle));

       if(*C3VheadingAngle_max >= biggest)
           biggest = *C3VheadingAngle_max;
       if(*C3VheadingAngle_min <= smallest)
           smallest = *C3VheadingAngle_min;
   }
   if(ui->checkBox_53->isChecked())
   {
       auto C3VcombinedEastSpeed_max = std::max_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));
       auto C3VcombinedEastSpeed_min = std::min_element(std::begin(C3VcombinedEastSpeed), std::end(C3VcombinedEastSpeed));

       if(*C3VcombinedEastSpeed_max >= biggest)
           biggest = *C3VcombinedEastSpeed_max;
       if(*C3VcombinedEastSpeed_min <= smallest)
           smallest = *C3VcombinedEastSpeed_min;
   }
   if(ui->checkBox_60->isChecked())
   {
       auto C3VcombinedNorthSpeed_max = std::max_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));
       auto C3VcombinedNorthSpeed_min = std::min_element(std::begin(C3VcombinedNorthSpeed), std::end(C3VcombinedNorthSpeed));

       if(*C3VcombinedNorthSpeed_max >= biggest)
           biggest = *C3VcombinedNorthSpeed_max;
       if(*C3VcombinedNorthSpeed_min <= smallest)
           smallest = *C3VcombinedNorthSpeed_min;
   }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_59_56_57_55_58()
{
    //多普勒,电磁
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_59->isChecked())
    {
        auto C3VwaterX_max = std::max_element(std::begin(C3VwaterX), std::end(C3VwaterX));
        auto C3VwaterX_min = std::min_element(std::begin(C3VwaterX), std::end(C3VwaterX));

        if(*C3VwaterX_max >= biggest)
            biggest = *C3VwaterX_max;
        if(*C3VwaterX_min <= smallest)
            smallest = *C3VwaterX_min;
    }
    if(ui->checkBox_56->isChecked())
    {
        auto C3VwaterY_max = std::max_element(std::begin(C3VwaterY), std::end(C3VwaterY));
        auto C3VwaterY_min = std::min_element(std::begin(C3VwaterY), std::end(C3VwaterY));

        if(*C3VwaterY_max >= biggest)
            biggest = *C3VwaterY_max;
        if(*C3VwaterY_min <= smallest)
            smallest = *C3VwaterY_min;
    }

    if(ui->checkBox_57->isChecked())
    {
        auto C3VbottomX_max = std::max_element(std::begin(C3VbottomX), std::end(C3VbottomX));
        auto C3VbottomX_min = std::min_element(std::begin(C3VbottomX), std::end(C3VbottomX));

        if(*C3VbottomX_max >= biggest)
            biggest = *C3VbottomX_max;
        if(*C3VbottomX_min <= smallest)
            smallest = *C3VbottomX_min;
    }
    if(ui->checkBox_55->isChecked())
    {
        auto C3VbottomY_max = std::max_element(std::begin(C3VbottomY), std::end(C3VbottomY));
        auto C3VbottomY_min = std::min_element(std::begin(C3VbottomY), std::end(C3VbottomY));

        if(*C3VbottomY_max >= biggest)
            biggest = *C3VbottomY_max;
        if(*C3VbottomY_min <= smallest)
            smallest = *C3VbottomY_min;
    }
    if(ui->checkBox_58->isChecked())
    {
        auto C3VelectromagnetismSpeed_max = std::max_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));
        auto C3VelectromagnetismSpeed_min = std::min_element(std::begin(C3VelectromagnetismSpeed), std::end(C3VelectromagnetismSpeed));

        if(*C3VelectromagnetismSpeed_max >= biggest)
            biggest = *C3VelectromagnetismSpeed_max;
        if(*C3VelectromagnetismSpeed_min <= smallest)
            smallest = *C3VelectromagnetismSpeed_min;
    }
     ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
     ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_61_63_62()
{
    //X Y Z陀螺零偏
    double biggest = -999999999;
    double smallest = 999999999;
     if(ui->checkBox_61->isChecked())
     {
         auto C6VC6XGroyFloat_max = std::max_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));
         auto C6VC6XGroyFloat_min = std::min_element(std::begin(C6VC6XGroyFloat), std::end(C6VC6XGroyFloat));

         if(*C6VC6XGroyFloat_max >= biggest)
             biggest = *C6VC6XGroyFloat_max;
         if(*C6VC6XGroyFloat_min <= smallest)
             smallest = *C6VC6XGroyFloat_min;
     }
     if(ui->checkBox_63->isChecked())
     {
         auto C6VC6YGroyFloat_max = std::max_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));
         auto C6VC6YGroyFloat_min = std::min_element(std::begin(C6VC6YGroyFloat), std::end(C6VC6YGroyFloat));

         if(*C6VC6YGroyFloat_max >= biggest)
             biggest = *C6VC6YGroyFloat_max;
         if(*C6VC6YGroyFloat_min <= smallest)
             smallest = *C6VC6YGroyFloat_min;
     }
     if(ui->checkBox_62->isChecked())
     {
         auto C6VC6ZGroyFloat_max = std::max_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));
         auto C6VC6ZGroyFloat_min = std::min_element(std::begin(C6VC6ZGroyFloat), std::end(C6VC6ZGroyFloat));

         if(*C6VC6ZGroyFloat_max >= biggest)
             biggest = *C6VC6ZGroyFloat_max;
         if(*C6VC6ZGroyFloat_min <= smallest)
             smallest = *C6VC6ZGroyFloat_min;
     }
      ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
      ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);


}
void MainWindow::set_checkBox_65_64_66()
{
    //X Y Z加速度计零偏
    double biggest = -999999999;
    double smallest = 999999999;
     if(ui->checkBox_65->isChecked())
     {
         auto C6VC6XAccelerometerFloat_max = std::max_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));
         auto C6VC6XAccelerometerFloat_min = std::min_element(std::begin(C6VC6XAccelerometerFloat), std::end(C6VC6XAccelerometerFloat));

         if(*C6VC6XAccelerometerFloat_max >= biggest)
             biggest = *C6VC6XAccelerometerFloat_max;
         if(*C6VC6XAccelerometerFloat_min <= smallest)
             smallest = *C6VC6XAccelerometerFloat_min;
     }
     if(ui->checkBox_64->isChecked())
     {
         auto C6VC6YAccelerometerFloat_max = std::max_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));
         auto C6VC6YAccelerometerFloat_min = std::min_element(std::begin(C6VC6YAccelerometerFloat), std::end(C6VC6YAccelerometerFloat));

         if(*C6VC6YAccelerometerFloat_max >= biggest)
             biggest = *C6VC6YAccelerometerFloat_max;
         if(*C6VC6YAccelerometerFloat_min <= smallest)
             smallest = *C6VC6YAccelerometerFloat_min;
     }
     if(ui->checkBox_66->isChecked())
     {
         auto C6VC6ZAccelerometerFloat_max = std::max_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));
         auto C6VC6ZAccelerometerFloat_min = std::min_element(std::begin(C6VC6ZAccelerometerFloat), std::end(C6VC6ZAccelerometerFloat));

         if(*C6VC6ZAccelerometerFloat_max >= biggest)
             biggest = *C6VC6ZAccelerometerFloat_max;
         if(*C6VC6ZAccelerometerFloat_min <= smallest)
             smallest = *C6VC6ZAccelerometerFloat_min;
     }
      ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
      ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_67_69_68()
{
    //速度误差
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_67->isChecked())
    {
        auto VeastSpeedError_max = std::max_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));
        auto VeastSpeedError_min = std::min_element(std::begin(VeastSpeedError), std::end(VeastSpeedError));

        if(*VeastSpeedError_max >= biggest)
            biggest = *VeastSpeedError_max;
        if(*VeastSpeedError_min <= smallest)
            smallest = *VeastSpeedError_min;
    }
    if(ui->checkBox_69->isChecked())
    {
        auto VnorthSpeedError_max = std::max_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));
        auto VnorthSpeedError_min = std::min_element(std::begin(VnorthSpeedError), std::end(VnorthSpeedError));

        if(*VnorthSpeedError_max >= biggest)
            biggest = *VnorthSpeedError_max;
        if(*VnorthSpeedError_min <= smallest)
            smallest = *VnorthSpeedError_min;
    }
    if(ui->checkBox_68->isChecked())
    {
        auto VtogetherSpeedError_max = std::max_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));
        auto VtogetherSpeedError_min = std::min_element(std::begin(VtogetherSpeedError), std::end(VtogetherSpeedError));

        if(*VtogetherSpeedError_max >= biggest)
            biggest = *VtogetherSpeedError_max;
        if(*VtogetherSpeedError_min <= smallest)
            smallest = *VtogetherSpeedError_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}
void MainWindow::set_checkBox_70_72_71()
{
    //位置误差
    double biggest = -999999999;
    double smallest = 999999999;
    if(ui->checkBox_70->isChecked())
    {
        auto VlatitudeError_max = std::max_element(std::begin(VlatitudeError), std::end(VlatitudeError));
        auto VlatitudeError_min = std::min_element(std::begin(VlatitudeError), std::end(VlatitudeError));

        if(*VlatitudeError_max >= biggest)
            biggest = *VlatitudeError_max;
        if(*VlatitudeError_min <= smallest)
            smallest = *VlatitudeError_min;
    }
    if(ui->checkBox_72->isChecked())
    {
        auto VlongitudeError_max = std::max_element(std::begin(VlongitudeError), std::end(VlongitudeError));
        auto VlongitudeError_min = std::min_element(std::begin(VlongitudeError), std::end(VlongitudeError));

        if(*VlongitudeError_max >= biggest)
            biggest = *VlongitudeError_max;
        if(*VlongitudeError_min <= smallest)
            smallest = *VlongitudeError_min;
    }
    if(ui->checkBox_71->isChecked())
    {
        auto VpositionError_max = std::max_element(std::begin(VpositionError), std::end(VpositionError));
        auto VpositionError_min = std::min_element(std::begin(VpositionError), std::end(VpositionError));

        if(*VpositionError_max >= biggest)
            biggest = *VpositionError_max;
        if(*VpositionError_min <= smallest)
            smallest = *VpositionError_min;
    }
    ui->customPlot2->xAxis->setRange(0, curveX.size()*1.5, Qt::AlignLeft);
    ui->customPlot2->yAxis->setRange(smallest, (biggest-smallest), Qt::AlignLeft);

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
        on_pushButton_15_clicked();

}
