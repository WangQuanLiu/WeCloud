#include "menuadddialog.h"
#include "ui_menuadddialog.h"

bool MenuAddDialog::eventFilter(QObject *watched, QEvent *event)
{

    if(event->type()==QEvent::HoverEnter){
        if(watched==ui->labelMessage){
            message_hover();
        }else if(watched==ui->labelContact){
            contact_hover();
        }else if(watched==ui->labelMeet){
            meet_hover();
        }else if(watched==ui->labelSchedule){
            schedule_hover();
        }else if(watched==ui->labelCalendar){
            calendar_hover();
        }else if(watched==ui->labelTeam){
            team_hover();
        }
    }else if(event->type()==QEvent::HoverLeave){
        if(watched==ui->labelMessage){
            message_unClick();
        }else if(watched==ui->labelContact){
            contact_unClick();
        }else if(watched==ui->labelMeet){
            meet_unClick();
        }else if(watched==ui->labelSchedule){
            schedule_unClick();
        }else if(watched==ui->labelCalendar){
            calendar_unClcik();
        }else if(watched==ui->labelTeam){
            team_unClick();
        }
    }
   else if(event->type()==QEvent::ActivationChange){

            if(QApplication::activeWindow()!=this){

                this->hide();
            }
    }

     return QDialog::eventFilter(watched,event);//½»¸øÉÏ²ã
}

MenuAddDialog::MenuAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuAddDialog)
{
    ui->setupUi(this);
    isShow=false;
  //  ui->widget->setStyleSheet("#widget,#MenuAddDialog{border:2px solid #EAEAEA;background:#EAEAEA;border-radius: 8px;}QLabel{color:#777777;}");
    init();

}

MenuAddDialog::~MenuAddDialog()
{
    delete ui;
}

void MenuAddDialog::contact_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/contact.png",ui->labelContact,10);
}

void MenuAddDialog::meet_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/meet.png",ui->labelMeet,10);
}

void MenuAddDialog::calendar_unClcik()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/calendar.png",ui->labelCalendar,10);
}

void MenuAddDialog::schedule_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/schedule.png",ui->labelSchedule,10);
}

void MenuAddDialog::team_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/team.png",ui->labelTeam,10);
}

void MenuAddDialog::message_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/message_hover.png",ui->labelMessage,10);
}

void MenuAddDialog::contact_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/contact_hover.png",ui->labelContact,10);
}

void MenuAddDialog::meet_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/meet_hover.png",ui->labelMeet,10);
}

void MenuAddDialog::calendar_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/calendar_hover.png",ui->labelCalendar,10);
}

void MenuAddDialog::schedule_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/schedule_hover.png",ui->labelSchedule,10);
}

void MenuAddDialog::team_hover()
{
      setLabelRoundRectPixmap(":images/mainWindow/menuAdd/team_hover.png",ui->labelTeam,10);
}

void MenuAddDialog::init()
{
    readQss("menuAdd.qss",this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    message_unClick();
    contact_unClick();
    meet_unClick();
    calendar_unClcik();
    schedule_unClick();
    team_unClick();
    this->setAttribute(Qt::WA_Hover,true);
  //   this->setWindowFlags(Qt::Window);
    ui->labelMessage->installEventFilter(this);
    ui->labelContact->installEventFilter(this);
    ui->labelMeet->installEventFilter(this);
    ui->labelCalendar->installEventFilter(this);
    ui->labelSchedule->installEventFilter(this);
    ui->labelTeam->installEventFilter(this);
    this->installEventFilter(this);
}

bool MenuAddDialog::getIsShow()
{
    return this->isShow;
}

void MenuAddDialog::showed()
{
    this->show();
    this->isShow=true;
}

void MenuAddDialog::hiddened()
{
    this->hide();
    this->isShow=false;
}


void MenuAddDialog::message_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/message.png",ui->labelMessage,10);
}


