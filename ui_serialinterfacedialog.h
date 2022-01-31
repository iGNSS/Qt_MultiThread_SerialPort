/********************************************************************************
** Form generated from reading UI file 'serialinterfacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALINTERFACEDIALOG_H
#define UI_SERIALINTERFACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialInterfaceDialog
{
public:
    QGridLayout *gridLayout_10;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *comboBox_6;
    QWidget *widget_4;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QComboBox *comboBox_7;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QComboBox *comboBox_8;
    QWidget *widget_7;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QWidget *widget_8;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SerialInterfaceDialog)
    {
        if (SerialInterfaceDialog->objectName().isEmpty())
            SerialInterfaceDialog->setObjectName(QStringLiteral("SerialInterfaceDialog"));
        SerialInterfaceDialog->resize(436, 244);
        SerialInterfaceDialog->setModal(true);
        gridLayout_10 = new QGridLayout(SerialInterfaceDialog);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        widget = new QWidget(SerialInterfaceDialog);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(comboBox);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(SerialInterfaceDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        comboBox_2 = new QComboBox(widget_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(120, 0));

        horizontalLayout_3->addWidget(comboBox_2);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(SerialInterfaceDialog);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        comboBox_6 = new QComboBox(widget_3);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        comboBox_6->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(comboBox_6);


        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_3, 1, 0, 1, 1);

        widget_4 = new QWidget(SerialInterfaceDialog);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_9 = new QGridLayout(widget_4);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        comboBox_7 = new QComboBox(widget_4);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));
        comboBox_7->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(comboBox_7, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_4, 1, 1, 1, 1);

        widget_5 = new QWidget(SerialInterfaceDialog);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        comboBox_3 = new QComboBox(widget_5);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(120, 0));

        horizontalLayout_5->addWidget(comboBox_3);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_5, 2, 0, 1, 1);

        widget_6 = new QWidget(SerialInterfaceDialog);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        comboBox_8 = new QComboBox(widget_6);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));
        comboBox_8->setMinimumSize(QSize(120, 0));

        horizontalLayout_6->addWidget(comboBox_8);


        gridLayout_6->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_6, 2, 1, 1, 1);

        widget_7 = new QWidget(SerialInterfaceDialog);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        gridLayout_7 = new QGridLayout(widget_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        comboBox_4 = new QComboBox(widget_7);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setMinimumSize(QSize(120, 0));

        horizontalLayout_7->addWidget(comboBox_4);


        gridLayout_7->addLayout(horizontalLayout_7, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_7, 3, 0, 1, 1);

        widget_8 = new QWidget(SerialInterfaceDialog);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        gridLayout_8 = new QGridLayout(widget_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        comboBox_5 = new QComboBox(widget_8);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setMinimumSize(QSize(120, 0));

        horizontalLayout_8->addWidget(comboBox_5);


        gridLayout_8->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget_8, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(SerialInterfaceDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(SerialInterfaceDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_10->addLayout(horizontalLayout, 4, 0, 1, 2);


        retranslateUi(SerialInterfaceDialog);

        QMetaObject::connectSlotsByName(SerialInterfaceDialog);
    } // setupUi

    void retranslateUi(QDialog *SerialInterfaceDialog)
    {
        SerialInterfaceDialog->setWindowTitle(QApplication::translate("SerialInterfaceDialog", "\350\256\276\345\244\207\346\216\245\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("SerialInterfaceDialog", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "COMA", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "COMB", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "COMC", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "COMD", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "COME", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "COMF", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "COMG", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("SerialInterfaceDialog", "\346\263\242\347\211\271\347\216\207 ", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "2400", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "4800", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "9600", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "19200", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "38400", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "57600", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "115200", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "230400", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "384000", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "460800", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("SerialInterfaceDialog", "\344\275\277\350\203\275\345\217\221\351\200\201", Q_NULLPTR));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "\347\246\201\346\255\242\345\217\221\351\200\201", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "\344\275\277\350\203\275\345\217\221\351\200\201", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("SerialInterfaceDialog", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "1\344\275\215\345\201\234\346\255\242\344\275\215", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "2\344\275\215\345\201\234\346\255\242\344\275\215", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("SerialInterfaceDialog", "\345\245\207\345\201\266\346\240\241\351\252\214", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "\345\201\266\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "\345\245\207\346\240\241\351\252\214", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("SerialInterfaceDialog", "\344\275\277\350\203\275\346\240\241\351\252\214", Q_NULLPTR));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "\347\246\201\346\255\242", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "\344\275\277\350\203\275\345\245\207\345\201\266\346\240\241\351\252\214", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("SerialInterfaceDialog", "\346\224\266\345\217\221", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "\345\217\221\351\200\201", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "\346\216\245\346\224\266", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("SerialInterfaceDialog", "\345\215\217\350\256\256", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("SerialInterfaceDialog", "\345\217\221\351\200\201\350\204\211\345\206\262\346\225\260", Q_NULLPTR)
         << QApplication::translate("SerialInterfaceDialog", "\345\217\221\351\200\201\345\257\274\350\210\252\346\225\260\346\215\256", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("SerialInterfaceDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SerialInterfaceDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialInterfaceDialog: public Ui_SerialInterfaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALINTERFACEDIALOG_H
