#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QDialog>
class Object
{
public:
    Object();
};
bool readQss(const QString&QssFilename,QDialog*ptr);
#endif // OBJECT_H
