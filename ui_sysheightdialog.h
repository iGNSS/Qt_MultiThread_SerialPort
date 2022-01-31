/********************************************************************************
** Form generated from reading UI file 'sysheightdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSHEIGHTDIALOG_H
#define UI_SYSHEIGHTDIALOG_H

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

class Ui_sysHeightDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *sysHeightDialog)
    {
        if (sysHeightDialog->objectName().isEmpty())
            sysHeightDialog->setObjectName(QStringLiteral("sysHeightDialog"));
        sysHeightDialog->resize(218, 138);
        gridLayout = new QGridLayout(sysHeightDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(sysHeightDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        pushButton = new QPushButton(sysHeightDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(sysHeightDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);


        retranslateUi(sysHeightDialog);

        QMetaObject::connectSlotsByName(sysHeightDialog);
    } // setupUi

    void retranslateUi(QDialog *sysHeightDialog)
    {
        sysHeightDialog->setWindowTitle(QApplication::translate("sysHeightDialog", "\350\243\205\350\256\242\347\263\273\347\273\237\351\253\230\345\272\246", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("sysHeightDialog", "\347\263\273\347\273\237\351\253\230\345\272\246", Q_NULLPTR));
        label->setText(QApplication::translate("sysHeightDialog", "\351\253\230\345\272\246\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("sysHeightDialog", "\350\243\205\350\256\242\347\263\273\347\273\237\351\253\230\345\272\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("sysHeightDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sysHeightDialog: public Ui_sysHeightDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSHEIGHTDIALOG_H
