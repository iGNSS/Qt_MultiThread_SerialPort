#ifndef SYSHEIGHTDIALOG_H
#define SYSHEIGHTDIALOG_H

#include <QDialog>

namespace Ui {
class sysHeightDialog;
}

class sysHeightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sysHeightDialog(QWidget *parent = nullptr);
    ~sysHeightDialog();
signals:
    void sysHeightDataCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sysHeightDialog *ui;
};

#endif // SYSHEIGHTDIALOG_H
