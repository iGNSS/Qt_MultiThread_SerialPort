#ifndef SYSBASEGDIALOG_H
#define SYSBASEGDIALOG_H

#include <QDialog>

namespace Ui {
class sysBaseGDialog;
}

class sysBaseGDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sysBaseGDialog(QWidget *parent = nullptr);
    ~sysBaseGDialog();
signals:
    void sysBaseGDataCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sysBaseGDialog *ui;
};

#endif // SYSBASEGDIALOG_H
