/********************************************************************************
** Form generated from reading UI file 'oridatabook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORIDATABOOK_H
#define UI_ORIDATABOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_oriDataBook
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QTextEdit *textEdit_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QTextEdit *textEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *oriDataBook)
    {
        if (oriDataBook->objectName().isEmpty())
            oriDataBook->setObjectName(QStringLiteral("oriDataBook"));
        oriDataBook->resize(379, 362);
        gridLayout = new QGridLayout(oriDataBook);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(oriDataBook);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 51, 16));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(70, 20, 141, 31));
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(70, 60, 141, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 51, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 40, 93, 28));

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(oriDataBook);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 40, 51, 16));
        textEdit_3 = new QTextEdit(groupBox_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(70, 30, 141, 31));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 32, 93, 28));

        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(oriDataBook);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 51, 16));
        textEdit_4 = new QTextEdit(groupBox_3);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(70, 30, 141, 31));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 32, 93, 28));

        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(oriDataBook);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);


        retranslateUi(oriDataBook);

        QMetaObject::connectSlotsByName(oriDataBook);
    } // setupUi

    void retranslateUi(QDialog *oriDataBook)
    {
        oriDataBook->setWindowTitle(QApplication::translate("oriDataBook", "\350\243\205\350\256\242\345\210\235\345\247\213\345\200\274", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("oriDataBook", "\345\210\235\345\247\213\344\275\215\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("oriDataBook", "\347\272\254\345\272\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("oriDataBook", "\347\273\217\345\272\246", Q_NULLPTR));
        pushButton->setText(QApplication::translate("oriDataBook", "\350\243\205\350\256\242", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("oriDataBook", "\345\210\235\345\247\213\344\275\215\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("oriDataBook", "\347\272\254\345\272\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("oriDataBook", "\350\243\205\350\256\242", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("oriDataBook", "\345\210\235\345\247\213\344\275\215\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("oriDataBook", "\347\272\254\345\272\246", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("oriDataBook", "\350\243\205\350\256\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("oriDataBook", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class oriDataBook: public Ui_oriDataBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORIDATABOOK_H
