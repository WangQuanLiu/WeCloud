QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QVerificationCode.cpp \
    main.cpp \
    mainwindow.cpp \
    network.cpp \
    object.cpp \
    qdlglogin.cpp

HEADERS += \
    QVerificationCode.h \
    mainwindow.h \
    network.h \
    object.h \
    qdlglogin.h

FORMS += \
    mainwindow.ui \
    qdlglogin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
