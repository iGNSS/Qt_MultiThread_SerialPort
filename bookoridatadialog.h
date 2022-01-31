#ifndef BOOKORIDATADIALOG_H
#define BOOKORIDATADIALOG_H

#include <QDialog>
#include "common.h"
namespace Ui {
class BookOriDataDialog;
}

class BookOriDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookOriDataDialog(QWidget *parent = nullptr);
    ~BookOriDataDialog();
    //QByteArray HexStringToByteArray(QString HexString);

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void OriDataCMD(const QByteArray result);
    void bookLogCMD(QString oldString);



private:
    Ui::BookOriDataDialog *ui;
};

#endif // BOOKORIDATADIALOG_H
