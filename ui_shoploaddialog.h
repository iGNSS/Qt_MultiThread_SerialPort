/********************************************************************************
** Form generated from reading UI file 'shoploaddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPLOADDIALOG_H
#define UI_SHOPLOADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ShopLoadDialog
{
public:
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QDialog *ShopLoadDialog)
    {
        if (ShopLoadDialog->objectName().isEmpty())
            ShopLoadDialog->setObjectName(QStringLiteral("ShopLoadDialog"));
        ShopLoadDialog->resize(350, 302);
        ShopLoadDialog->setModal(true);
        gridLayout_7 = new QGridLayout(ShopLoadDialog);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(ShopLoadDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        pushButton = new QPushButton(ShopLoadDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 0, 1, 2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_2 = new QGroupBox(ShopLoadDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(ShopLoadDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_5->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 1, 0, 1, 2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_3 = new QGroupBox(ShopLoadDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_3->addWidget(lineEdit_3, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_3, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(ShopLoadDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_6->addWidget(pushButton_3, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(ShopLoadDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_7->addWidget(pushButton_4, 3, 1, 1, 1);


        retranslateUi(ShopLoadDialog);

        QMetaObject::connectSlotsByName(ShopLoadDialog);
    } // setupUi

    void retranslateUi(QDialog *ShopLoadDialog)
    {
        ShopLoadDialog->setWindowTitle(QApplication::translate("ShopLoadDialog", "\350\243\205\350\211\207\345\217\202\346\225\260", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ShopLoadDialog", "\347\263\273\347\273\237\347\274\226\345\217\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ShopLoadDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ShopLoadDialog", "\350\210\260\344\275\215", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ShopLoadDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ShopLoadDialog", "IP\345\234\260\345\235\200", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ShopLoadDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ShopLoadDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShopLoadDialog: public Ui_ShopLoadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPLOADDIALOG_H
