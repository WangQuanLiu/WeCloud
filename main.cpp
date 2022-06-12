#include <QApplication>
#include"qdlglogin.h"
#include "mainwindow.h"
#include "mcommon.h"
#include "menuadddialog.h"
#include "accountpicturedialog.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



    MainWindow m;
    m.show();

    return a.exec();
}

