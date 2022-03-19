#ifndef QVERIFICATIONCODE_H
#define QVERIFICATIONCODE_H
#include<qlabel.h>
#include<QPainter>
#include<qrandom.h>
#include<qtguiglobal.h>
const int codeNumber = 4;
const int pointNumber = 80;
const int lineNumber = 10;
class QVerificationCode :
    public QLabel
{
    Q_OBJECT
public:
    QVerificationCode(QWidget* parent = 0);
    ~QVerificationCode();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);//Êó±ê°´ÏÂ
private:
    QString code;
};
#endif // QVERIFICATIONCODE_H



