#ifndef FILEDATACOLLECTOR_H
#define FILEDATACOLLECTOR_H

#include "abstractdatacollector.h"
#include <QTimer>
#include <QFile>
#include <QDataStream>
#include "dataanalyser.h"
#include <QObject>

class FileDataCollector : public AbstractDataCollector
{
    Q_OBJECT

public:
    explicit FileDataCollector(QObject* parent = 0);
    virtual ~FileDataCollector();

    virtual void start() override;//override 覆盖    重写基类的start函数并覆盖
    virtual void startCollect();
    virtual void stopCollect();
    virtual void timerStop();

    char buf[650];
    QByteArray  m_dataCache;
    QByteArray temp;

private slots:
    void readDataFile();

private:
    QTimer *m_timer;
    QFile *m_dataFile;
    QDataStream *m_dataStream;
};

#endif // FILEDATACOLLECTOR_H
