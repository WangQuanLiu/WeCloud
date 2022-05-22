#include"mmainwindow.h"
#include <QApplication>
#include"qdlglogin.h"
#include"mcommon.h"
#include"mframelesswidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDlgLogin*dlgLogin=new QDlgLogin();
   if(! readQss("LoginQss.qss",dlgLogin))
       return 0;
   // if(dlgLogin->exec()==QDialog::Accepted){
  //  MMainWindow w;
   // w.show();
    //return a.exec();
   MFrameLessWidget f;
   f.show();
   return a.exec();
   // }
   // else
    return 0;
}
