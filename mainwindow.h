#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelessmainwindow.h"
#include <QColor>
#include <QRgb>
#include <QLabel>
#include <QPainter>
#include <QEvent>
#include <initializer_list>
#include <QList>
#include <QLabel>
#include <QToolTip>
#include "mcommon.h"
#include "menuadddialog.h"
namespace Ui {
class MainWindow;
}

using namespace Common;
class MainWindow : public FramelessMainWindow
{
    Q_OBJECT

public:

    friend class Common::MQObject;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
      bool eventFilter(QObject*,QEvent*);
protected:
       void showEvent(QShowEvent *event);
private:

    inline  void labelMin_Clicked();
    inline  void labelMax_Clicked();
    inline  void labelClose_Clicked();
      void labelMenuAdd_Clicked();
      void labelAccountPicture_unClicked();
      void menuLeftMessage_Clicked();
      void menuLeftContact_Clicked();
      void menuLeftDocument_Clicked();
      void menuLeftMeet_clicked();
      void menuLeftCloud_clicked();
      void menuleftCalendar_clicked();
      void menuLeftSchedule_clicked();
      void menuLeftSetting_clicked();

      void menuLeftCalendar_unClicked();
      void menuLeftMessage_unClicked();
      void menuLeftContact_unClicked();
      void menuLeftDocument_unClicked();
      void menuLeftMeet_unClicked();
      void menuLeftCloud_unClicked();
      void menuLeftSchedule_unClicked();
      void menuLeftSetting_unClicked();

      void initFilter();
      void init();
      void initLabelPixmap();
private slots:
    void initForm();
    void titleDblClick();
private:
    MenuAddDialog*menuAddDialog;
    MQObjects menuLeftobjects;
    MQToolTips toolTips;
};

#endif // MAINWINDOW_H
