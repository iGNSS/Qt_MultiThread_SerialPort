#ifndef TEMPCOMPENCOEFFDIALOG_H
#define TEMPCOMPENCOEFFDIALOG_H

#include <QDialog>

namespace Ui {
class TempCompenCoeffDialog;
}

class TempCompenCoeffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TempCompenCoeffDialog(QWidget *parent = nullptr);
    ~TempCompenCoeffDialog();

private:
    Ui::TempCompenCoeffDialog *ui;

signals:
    void GyroTempComCoeffCMD(const QByteArray result);
    void AccelerometerComCoeffCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // TEMPCOMPENCOEFFDIALOG_H
