#ifndef FILEDATAINFO_H
#define FILEDATAINFO_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "filedatawidget.h"
#include "common.h"

#define SIMPLE 0
#define MAPPED 1
#define DRAW 2
#define BASE 3

#define MAXNUM 50

struct FileData
{
    QString startTime;
    QString endTime;
    QString startDate;
    QString endDate;
    QString startX;//LINE
    QString endX;//LINE
    QString startY;//MARK
    QString endY;//MAEK

    int fileType;
    int readingsNum;
    long filesize;
    int surveyMode;
    int direction;
    long markPosition;
};


class FileDataInfo : public QObject
{
    Q_OBJECT

    SINGLETON(FileDataInfo)
public:
    void memorySizeCheck();
    void fileDataCheck();
    void fileDataCheck(int index);

    void continuousDataCheck(QFile *file,FileData *filedata,char* lastbuf);
    void gpsDataCheck(QFile *file,FileData *filedata,char* lastbuf);
    void discreteDataCheck(QFile *file,FileData *filedata,char* lastbuf);

    int setFileDataWidget(int index,FileDataWidget *w);

    void setTransferStatus(int index, bool flag);
    bool getTransferStatus(int index);

    double getMemoryUsed() { return memoryUsed; }

signals:

public slots:

private:
    double memoryUsed;
    QMap<int,FileData*> *data;

    QMap<int,bool> *transferStatus;

};

#endif // FILEDATAINFO_H
