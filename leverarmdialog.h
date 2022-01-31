#ifndef LEVERARMDIALOG_H
#define LEVERARMDIALOG_H

#include <QDialog>

namespace Ui {
class LeverArmDialog;
}

class LeverArmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LeverArmDialog(QWidget *parent = nullptr);
    ~LeverArmDialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void leverArmDataCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
private:
    Ui::LeverArmDialog *ui;
};

#endif // LEVERARMDIALOG_H
