QT       += core gui
QT       += network
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QVerificationCode.cpp \
    accountpicturedialog.cpp \
    framelessdialog.cpp \
    framelessmainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mcommon.cpp \
    mdialogmessage.cpp \
    menuadddialog.cpp \
    message.cpp \
    mqscrollarea.cpp \
    network.cpp \
    qdlglogin.cpp

HEADERS += \
    QVerificationCode.h \
    accountpicturedialog.h \
    framelessdialog.h \
    framelessmainwindow.h \
    mainwindow.h \
    mcommon.h \
    mdialogmessage.h \
    menuadddialog.h \
    message.h \
    mqscrollarea.h \
    network.h \
    qdlglogin.h

FORMS += \
    accountpicturedialog.ui \
    mainwindow.ui \
    mdialogmessage.ui \
    menuadddialog.ui \
    qdlglogin.ui


RESOURCES += \
    source.qrc

LIBS += User32.Lib
LIBS += gdi32.lib

RC_ICONS = logo.ico
RC_FILE = logo.rc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/ -lcommonLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lcommonLibd

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/include/libcommonLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/include/libcommonLibd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/include/commonLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/include/commonLibd.lib


