/********************************************************************************
** Form generated from reading UI file 'attitudedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTITUDEDIALOG_H
#define UI_ATTITUDEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AttitudeDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *AttitudeDialog)
    {
        if (AttitudeDialog->objectName().isEmpty())
            AttitudeDialog->setObjectName(QStringLiteral("AttitudeDialog"));
        AttitudeDialog->resize(509, 187);
        AttitudeDialog->setModal(true);
        gridLayout_3 = new QGridLayout(AttitudeDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(AttitudeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(AttitudeDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_5->addWidget(lineEdit_4);

        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout_5->addWidget(lineEdit_7);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_6->addWidget(lineEdit_5);

        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_6->addWidget(lineEdit_8);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);

        lineEdit_9 = new QLineEdit(groupBox_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        horizontalLayout_7->addWidget(lineEdit_9);


        gridLayout->addLayout(horizontalLayout_7, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(AttitudeDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(AttitudeDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(AttitudeDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 2);


        retranslateUi(AttitudeDialog);

        QMetaObject::connectSlotsByName(AttitudeDialog);
    } // setupUi

    void retranslateUi(QDialog *AttitudeDialog)
    {
        AttitudeDialog->setWindowTitle(QApplication::translate("AttitudeDialog", "\345\247\277\346\200\201\351\233\266\344\275\215", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AttitudeDialog", "\347\263\273\347\273\237\345\247\277\346\200\201\351\233\266\344\275\215", Q_NULLPTR));
        label->setText(QApplication::translate("AttitudeDialog", "\346\250\252\346\221\207", Q_NULLPTR));
        label_2->setText(QApplication::translate("AttitudeDialog", "\347\272\265\346\221\207", Q_NULLPTR));
        label_3->setText(QApplication::translate("AttitudeDialog", "\350\210\252\345\220\221", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("AttitudeDialog", "\346\203\257\347\273\204\345\247\277\346\200\201\351\233\266\344\275\215\345\222\214\350\276\223\345\207\272\345\247\277\346\200\201\351\233\266\344\275\215", Q_NULLPTR));
        label_6->setText(QApplication::translate("AttitudeDialog", "\346\250\252\346\221\207", Q_NULLPTR));
        label_5->setText(QApplication::translate("AttitudeDialog", "\347\272\265\346\221\207", Q_NULLPTR));
        label_4->setText(QApplication::translate("AttitudeDialog", "\350\210\252\345\220\221", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AttitudeDialog", "\350\243\205\350\256\242\347\263\273\347\273\237\351\233\266\344\275\215", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AttitudeDialog", "\350\243\205\350\256\242\346\203\257\347\273\204\345\222\214\350\276\223\345\207\272\351\233\266\344\275\215", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("AttitudeDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AttitudeDialog: public Ui_AttitudeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTITUDEDIALOG_H
