#ifndef ATTITUDEDIALOG_H
#define ATTITUDEDIALOG_H

#include <QDialog>

namespace Ui {
class AttitudeDialog;
}

class AttitudeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AttitudeDialog(QWidget *parent = nullptr);
    ~AttitudeDialog();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void attitudeDataCMD(const QByteArray result);
    void outputDataCMD(const QByteArray result);
    void bookLogCMD(QString oldString);

private:
    Ui::AttitudeDialog *ui;
};

#endif // ATTITUDEDIALOG_H
