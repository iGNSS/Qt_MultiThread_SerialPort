QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11
RC_FILE = res.rc
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
TARGET = InsDisCtr
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attitudedialog.cpp \
    bookoridatadialog.cpp \
    calibratparadialog.cpp \
    common.cpp \
    leverarmdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    qextserialport.cpp \
    qextserialport_win.cpp \
    querydialog.cpp \
    serialinterfacedialog.cpp \
    serialworker.cpp \
    shoploaddialog.cpp \
    sysbasegdialog.cpp \
    sysheightdialog.cpp \
    tempcompencoeffdialog.cpp \
    xxwcustomplot.cpp \
    xxwtracer.cpp

HEADERS += \
    attitudedialog.h \
    bookoridatadialog.h \
    calibratparadialog.h \
    common.h \
    leverarmdialog.h \
    mainwindow.h \
    qcustomplot.h \
    qextserialport.h \
    qextserialport_global.h \
    qextserialport_p.h \
    querydialog.h \
    serialinterfacedialog.h \
    serialworker.h \
    shoploaddialog.h \
    sysbasegdialog.h \
    sysheightdialog.h \
    tempcompencoeffdialog.h \
    xxwcustomplot.h \
    xxwtracer.h

FORMS += \
    attitudedialog.ui \
    bookoridatadialog.ui \
    calibratparadialog.ui \
    leverarmdialog.ui \
    mainwindow.ui \
    querydialog.ui \
    serialinterfacedialog.ui \
    shoploaddialog.ui \
    sysbasegdialog.ui \
    sysheightdialog.ui \
    tempcompencoeffdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    scale.qrc
