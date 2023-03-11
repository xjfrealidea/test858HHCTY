#ifndef DATACOLLECTORFACTORY_H
#define DATACOLLECTORFACTORY_H

#include "abstractdatacollector.h"
#include "filedatacollector.h"
#include "commdatacollector.h"
#include "common.h"
#include "cachedatasaver.h"

enum DataSourceType
{
    dstComm = 0,
    dstFile
};

class DataCollectorFactory
{
    SINGLETON(DataCollectorFactory)
public:
    AbstractDataCollector *getDataCollector();
    void createDataCollector(int type);
    CacheDataSaver *getCacheDataSaver();

private:
    AbstractDataCollector *dataCollector;

    CacheDataSaver *cachedatasaver;
};

#endif // DATACOLLECTORFACTORY_H
