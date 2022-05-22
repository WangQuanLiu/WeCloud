#ifndef QVERIFICATIONCODE_H
#define QVERIFICATIONCODE_H
#include<qlabel.h>
#include<QPainter>
#include<qrandom.h>
#include<qtguiglobal.h>
#include<cstdlib>
#include<ctime>
const int codeNumber = 4;
const int pointNumber = 80;
const int lineNumber = 10;
class QVerificationCode :
    public QLabel
{
    Q_OBJECT
public:
    explicit   QVerificationCode(QWidget* parent = nullptr) :QLabel(parent) {
        srand((unsigned)time(NULL));
    }
    ~QVerificationCode();
    QString getCode();
protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);//鼠标按下
private:
    QString code;
};
#endif // QVERIFICATIONCODE_H



