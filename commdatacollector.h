#ifndef COMMDATACOLLECTOR_H
#define COMMDATACOLLECTOR_H
#include <QTimer>
#include <QtSerialPort/qserialport.h>
#include "abstractdatacollector.h"

class CommDataCollector : public AbstractDataCollector
{
    Q_OBJECT
public:
    explicit CommDataCollector(short type = 0, QObject *parent = 0);
    virtual ~CommDataCollector();

    virtual void start();
    virtual void startCollect();
    virtual void stopCollect();
    virtual void timerStop();

    QByteArray temp ;


signals:

public slots:
    void retakeOpenPort();

    virtual void sendCommand(QString cmd);

private slots:
    void readDataFile();

private:
    QSerialPort m_port;			// 串口
    QByteArray  m_dataCache;
    QTimer *m_timer;

    QByteArray gpsHead;
    short gpsDataLen;
    short type;
    short resetCount;
    short mCount;
    short hzCount;
};

#endif // COMMDATACOLLECTOR_H
