/********************************************************************************
** Form generated from reading UI file 'sysbasegdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSBASEGDIALOG_H
#define UI_SYSBASEGDIALOG_H

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

class Ui_sysBaseGDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *sysBaseGDialog)
    {
        if (sysBaseGDialog->objectName().isEmpty())
            sysBaseGDialog->setObjectName(QStringLiteral("sysBaseGDialog"));
        sysBaseGDialog->resize(268, 121);
        gridLayout_2 = new QGridLayout(sysBaseGDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(sysBaseGDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);

        pushButton = new QPushButton(sysBaseGDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(sysBaseGDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);


        retranslateUi(sysBaseGDialog);

        QMetaObject::connectSlotsByName(sysBaseGDialog);
    } // setupUi

    void retranslateUi(QDialog *sysBaseGDialog)
    {
        sysBaseGDialog->setWindowTitle(QApplication::translate("sysBaseGDialog", "\350\243\205\350\256\242\347\263\273\347\273\237\345\237\272\345\207\206\351\207\215\345\212\233\345\200\274", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("sysBaseGDialog", "\347\263\273\347\273\237\345\237\272\345\207\206\351\207\215\345\212\233\345\200\274", Q_NULLPTR));
        label->setText(QApplication::translate("sysBaseGDialog", "\347\263\273\347\273\237\345\237\272\345\207\206\351\207\215\345\212\233\345\200\274\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("sysBaseGDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("sysBaseGDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sysBaseGDialog: public Ui_sysBaseGDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSBASEGDIALOG_H
