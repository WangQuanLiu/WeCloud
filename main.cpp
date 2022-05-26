#include <QApplication>
#include"qdlglogin.h"
#include "mainwindow.h""
#include "mcommon.h"
void init();
int main(int argc, char *argv[])
{
    //init();
    QApplication a(argc, argv);
    QDlgLogin*dlgLogin=new QDlgLogin();
   if(! readQss("LoginQss.qss",dlgLogin))
       return 0;

  // MainWindow m;
  // m.show();
    if(dlgLogin->exec()==QDialog::Accepted){
        QDlgLogin login;
        login.show();

 //   MainWindow m;
  //  m.show();
   // MMainWindow w;
  //  w.show();


   return a.exec();
  }
   // else
    return 0;
}
void init(){
    setNormalShowScale();

}
