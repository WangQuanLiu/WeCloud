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

QPixmap pixmapScale(const QPixmap &image, const int &width,const int &heignt)
{

    QPixmap temp_image;
    temp_image=image.scaled(width,heignt,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    return temp_image;
}

QPixmap getRoundRectPixmap(QPixmap srcPixmap, int radius)
{
    if(srcPixmap.isNull())return srcPixmap;
    //获取图片尺寸
    int imageWidth=srcPixmap.width();
    int imageHeight=srcPixmap.height();

    //处理大尺寸的图片，保证图片显示区域完整
    QPixmap newPixmap=srcPixmap.scaled(imageWidth,imageHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QPixmap destImage(imageWidth,imageHeight);
    destImage.fill(Qt::transparent);
    QPainter painter(&destImage);
    //抗锯齿
    painter.setRenderHints(QPainter::Antialiasing,true);
    //图片平滑处理
    painter.setRenderHints(QPainter::SmoothPixmapTransform,true);
    //将图片裁剪成圆角
    QPainterPath path;
    QRect rect(0,0,imageWidth,imageHeight);
    path.addRoundedRect(rect,radius,radius);
    painter.setClipPath(path);
    painter.drawPixmap(0,0,imageWidth,imageHeight,newPixmap);
    return destImage;
}

void initTooltip()
{
    QPalette palette=QToolTip::palette();
    palette.setColor(QPalette::Inactive,QPalette::ToolTipBase,Qt::black);//设置背景色
    palette.setColor(QPalette::Inactive,QPalette::Text,Qt::white);//字体颜色
    QToolTip::setPalette(palette);
}
void Common::setLabelPixmap(const QString &imagePath, QLabel *label)
{
    QPixmap pixmap;
    if(!pixmap.load(imagePath))return ;
    QPixmap newPixmap=pixmapScale(pixmap, label->width(),label->height());
    label->setPixmap(newPixmap);
}

void Common::setLabelRoundRectPixmap(const QString &imagePath, QLabel *label,int radius)
{
    QPixmap pixmap;
    if(!pixmap.load(imagePath))return ;
    QPixmap newPixmap=pixmapScale(pixmap, label->width(),label->height());
    newPixmap=getRoundRectPixmap(newPixmap,radius);
    label->setPixmap(newPixmap);
}
