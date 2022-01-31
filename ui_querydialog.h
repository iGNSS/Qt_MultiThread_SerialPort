/********************************************************************************
** Form generated from reading UI file 'querydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYDIALOG_H
#define UI_QUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QueryDialog
{
public:
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QComboBox *comboBox_3;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_4;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QComboBox *comboBox_5;
    QPushButton *pushButton_5;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QDialog *QueryDialog)
    {
        if (QueryDialog->objectName().isEmpty())
            QueryDialog->setObjectName(QStringLiteral("QueryDialog"));
        QueryDialog->resize(342, 416);
        QueryDialog->setModal(true);
        gridLayout_12 = new QGridLayout(QueryDialog);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        groupBox = new QGroupBox(QueryDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(25, 0));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(QueryDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_3->addWidget(comboBox_2, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(100, 25));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(QueryDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout_5->addWidget(comboBox_3, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(100, 25));

        gridLayout_5->addWidget(pushButton_3, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(QueryDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        comboBox_4 = new QComboBox(groupBox_4);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout_7->addWidget(comboBox_4, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(100, 25));

        gridLayout_7->addWidget(pushButton_4, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_4, 3, 0, 1, 1);

        groupBox_5 = new QGroupBox(QueryDialog);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_10 = new QGridLayout(groupBox_5);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        comboBox_5 = new QComboBox(groupBox_5);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        gridLayout_9->addWidget(comboBox_5, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(100, 25));

        gridLayout_9->addWidget(pushButton_5, 0, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_5, 4, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        pushButton_6 = new QPushButton(QueryDialog);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_11->addWidget(pushButton_6, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(QueryDialog);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_11->addWidget(pushButton_7, 0, 1, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 5, 0, 1, 1);


        retranslateUi(QueryDialog);

        QMetaObject::connectSlotsByName(QueryDialog);
    } // setupUi

    void retranslateUi(QDialog *QueryDialog)
    {
        QueryDialog->setWindowTitle(QApplication::translate("QueryDialog", "\347\212\266\346\200\201\345\210\207\346\215\242", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QueryDialog", "\345\257\274\350\210\252\347\212\266\346\200\201", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("QueryDialog", "\345\207\206\345\244\207", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\350\207\252\345\257\271\345\207\206", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\344\274\240\351\200\222\345\257\271\345\207\206", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\347\275\227\347\273\217\345\257\271\345\207\206", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\350\207\252\344\270\273\345\257\274\350\210\252/\346\227\240\351\230\273\345\260\274", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\350\207\252\344\270\273\345\257\274\350\210\252/\346\260\264\345\271\263\351\230\273\345\260\274", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\350\207\252\344\270\273\345\257\274\350\210\252/\345\205\250\351\230\273\345\260\274", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\347\275\227\347\273\217\345\257\274\350\210\252", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\347\273\204\345\220\210\345\257\274\350\210\252", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\345\234\250\350\210\260\346\240\207\345\256\232", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\347\273\204\345\220\210\346\240\241\345\207\206", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("QueryDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QueryDialog", "\345\267\245\344\275\234\345\234\260\347\202\271", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("QueryDialog", "\347\240\201\345\244\264", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\346\265\267\344\270\212", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("QueryDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("QueryDialog", "\346\223\215\344\275\234\346\226\271\345\274\217", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("QueryDialog", "\350\207\252\345\212\250", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\346\211\213\345\212\250", Q_NULLPTR)
        );
        pushButton_3->setText(QApplication::translate("QueryDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("QueryDialog", "\345\235\220\346\240\207\347\263\273\345\210\207\346\215\242", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("QueryDialog", "XYZ", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "Y-XZ", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-X-YZ", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-YXZ", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-XY-Z", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-Y-X-Z", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "X-Y-Z", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "YX-Z", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "XZ-Y", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "YZX", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-XZY", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-YZ-X", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "X-ZY", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "Y-Z-X", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-X-Z-Y", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-Y-ZX", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "ZY-X", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "Z-X-Y", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "Z-YX", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "ZXY", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-ZYX", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-Z-XY", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-Z-Y-X", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "-ZX-Y", Q_NULLPTR)
        );
        pushButton_4->setText(QApplication::translate("QueryDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("QueryDialog", "\345\217\202\346\225\260\346\237\245\350\257\242", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("QueryDialog", "\347\273\217\347\272\254\345\272\246", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\350\210\252\345\220\221", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\351\200\237\345\272\246", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\347\263\273\347\273\237\347\274\226\345\217\267", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\345\234\250\350\210\260\344\275\215\347\275\256", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "IP\345\234\260\345\235\200", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\351\231\200\350\236\272\346\240\207\345\256\232\345\217\202\346\225\260", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\345\212\240\351\200\237\345\272\246\350\256\241\346\240\207\345\256\232\345\217\202\346\225\260", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\347\255\211\346\225\210\351\233\266\345\201\217", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\347\263\273\347\273\237\345\247\277\346\200\201\351\233\266\344\275\215", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\346\203\257\347\273\204\345\222\214\350\276\223\345\207\272\351\233\266\344\275\215", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\346\235\206\350\207\202", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\351\231\200\350\236\272\351\233\266\345\201\217\346\270\251\350\241\245\347\263\273\346\225\260", Q_NULLPTR)
         << QApplication::translate("QueryDialog", "\345\212\240\350\241\250\351\233\266\344\275\215\346\270\251\350\241\245\347\263\273\346\225\260", Q_NULLPTR)
        );
        pushButton_5->setText(QApplication::translate("QueryDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("QueryDialog", "\347\250\213\345\272\217\347\203\247\345\206\231", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("QueryDialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QueryDialog: public Ui_QueryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYDIALOG_H
