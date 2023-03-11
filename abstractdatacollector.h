#ifndef ABSTRACTDATACOLLECTOR_H
#define ABSTRACTDATACOLLECTOR_H

#include <QObject>
#include "dataanalyser.h"

class AbstractDataCollector : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDataCollector(QObject *parent = 0);

    virtual void start() = 0;
    virtual void startCollect() = 0;
    virtual void stopCollect() = 0;
    virtual void timerStop() = 0;

    bool pauseFlag;

public slots:
    virtual void sendCommand(QString cmd) {}

signals:
    void dataCollected(QByteArray data, qint16 aa);
    void cacheData(QByteArray,qint16);
    void statusData(QByteArray data, qint16 aa);

    void portOpenFailed(int);
    void portOpenSuccessed();
};

#endif // ABSTRACTDATACOLLECTOR_H
