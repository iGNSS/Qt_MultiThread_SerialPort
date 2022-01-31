#ifndef SERIALINTERFACEDIALOG_H
#define SERIALINTERFACEDIALOG_H

#include <QDialog>

namespace Ui {
class SerialInterfaceDialog;
}

class SerialInterfaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SerialInterfaceDialog(QWidget *parent = nullptr);
    ~SerialInterfaceDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
signals:
    void serialInterCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
private:
    Ui::SerialInterfaceDialog *ui;
};

#endif // SERIALINTERFACEDIALOG_H
