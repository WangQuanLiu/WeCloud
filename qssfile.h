#ifndef QSSFILE_H
#define QSSFILE_H

#include <QObject>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QDialog>
#define ReadQssFile(FilePath,Filename) FilePath+=FileName;




class QssFile : public QObject
{
    Q_OBJECT
public:
    explicit QssFile(QObject *parent = nullptr);
static bool readQss(const QString&QssFilename,QDialog*ptr);
signals:

};

#endif // QSSFILE_H
