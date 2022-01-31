/********************************************************************************
** Form generated from reading UI file 'bookoridatadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKORIDATADIALOG_H
#define UI_BOOKORIDATADIALOG_H

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
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BookOriDataDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QDialog *BookOriDataDialog)
    {
        if (BookOriDataDialog->objectName().isEmpty())
            BookOriDataDialog->setObjectName(QStringLiteral("BookOriDataDialog"));
        BookOriDataDialog->resize(346, 371);
        BookOriDataDialog->setModal(true);
        gridLayout_3 = new QGridLayout(BookOriDataDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(BookOriDataDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 2, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BookOriDataDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(BookOriDataDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_4->addWidget(lineEdit_4, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_4->addWidget(pushButton_3, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, 11, -1);
        horizontalSpacer = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(BookOriDataDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);


        gridLayout_3->addLayout(horizontalLayout_4, 3, 0, 1, 1);


        retranslateUi(BookOriDataDialog);

        QMetaObject::connectSlotsByName(BookOriDataDialog);
    } // setupUi

    void retranslateUi(QDialog *BookOriDataDialog)
    {
        BookOriDataDialog->setWindowTitle(QApplication::translate("BookOriDataDialog", "\350\243\205\350\256\242\345\210\235\345\247\213\344\275\215\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BookOriDataDialog", "\345\210\235\345\247\213\344\275\215\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("BookOriDataDialog", "\347\272\254\345\272\246", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BookOriDataDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("BookOriDataDialog", "\347\272\254\345\272\246", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BookOriDataDialog", "\345\210\235\345\247\213\351\200\237\345\272\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("BookOriDataDialog", "\351\200\237\345\272\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BookOriDataDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("BookOriDataDialog", "\345\210\235\345\247\213\350\210\252\345\220\221", Q_NULLPTR));
        label_4->setText(QApplication::translate("BookOriDataDialog", "\350\210\252\345\220\221", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("BookOriDataDialog", "\350\243\205\350\256\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("BookOriDataDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BookOriDataDialog: public Ui_BookOriDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKORIDATADIALOG_H
