#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString StrPath = QApplication::applicationDirPath();
    StrPath = "./INS.ico";
    a.setWindowIcon(QIcon(StrPath));
    w.show();
    return a.exec();
}
