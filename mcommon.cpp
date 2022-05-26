#include "mcommon.h"

MCommon::MCommon()
{
}
bool readQss(const QString &QssFilename,QWidget*ptr)
{
    QString QssFilePath=":/qss/"+QssFilename;
    QFile file=(QssFilePath);
    if(!file.exists())//文件不存在
        return false;
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return false;
    QTextStream stream(&file);
    ptr->setStyleSheet(stream.readAll());
    file.close();
    return true;
}
/*
 *
 * 功能：使得窗口可以自适应分辩率
 */
void setNormalShowScale()
{
    double dScaleFactor = 1.0;
       //应用开启DPI感知
       SetProcessDPIAware();
       //计算当前屏幕的DPI
       HDC desktopDc = GetDC(NULL);
       float horizontal_dpi = GetDeviceCaps(desktopDc, LOGPIXELSX);
       float vrtical_dpi = GetDeviceCaps(desktopDc, LOGPIXELSY);
       int hv_dpi = (horizontal_dpi+vrtical_dpi)/2;
       //计算DPI的缩放系数设置全局的QT缩放系数
       dScaleFactor = static_cast<double>(hv_dpi)/96.0;
       qputenv("QT_SCALE_FACTOR", QString::number(dScaleFactor).toUtf8());
}

void setLabelFontSize(QLabel *lineEdit,unsigned fontSize)
{
    if(lineEdit==nullptr)return;
    QFont font;
    font.setPointSize(fontSize);
    lineEdit->setFont(font);
}
