#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H

#include <QObject>
#include <QTimer>
#include <QFile>
#include <QDataStream>
#include "dataanalyser.h"
#include <stdio.h>
//#include <wchar.h>
#include "common.h"

class DataCollector : public QObject
{
    Q_OBJECT

    SINGLETON(DataCollector)
public:
    void start();
    void stopCollect();

signals:
    void dataCollected(SAVE_DATA *savedata);//将读到的数据文件名字发送出去

private slots:
    void readDataFile();//给自己发的一个信号对应的槽函数

private:
    QTimer *m_timer;
    QFile *m_dataFile;
    QDataStream *m_dataStream;
};

#endif // DATACOLLECTOR_H
