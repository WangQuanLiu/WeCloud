#include "object.h"

Object::Object()
{

}
bool readQss(const QString &QssFilename,QDialog*ptr)
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
