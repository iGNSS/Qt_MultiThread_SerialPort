#ifndef CALIBRATPARADIALOG_H
#define CALIBRATPARADIALOG_H

#include <QDialog>

namespace Ui {
class CalibratParaDialog;
}

class CalibratParaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalibratParaDialog(QWidget *parent = nullptr);
    ~CalibratParaDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

signals:
    void GyroParaCMD(const QByteArray result);
    void AccelerometerParaCMD(const QByteArray result);
    void GyroEqZeroBiasCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
private:
    Ui::CalibratParaDialog *ui;
};

#endif // CALIBRATPARADIALOG_H
