#include "datacollectorfactory.h"
#include "widgetshowtype.h"

DataCollectorFactory::DataCollectorFactory()
{

}

DataCollectorFactory::~DataCollectorFactory()
{
    if(dataCollector != NULL)
    {
        delete dataCollector;
        dataCollector = NULL;
    }

    if (cachedatasaver != NULL)
    {
        delete cachedatasaver;
        cachedatasaver = NULL;
    }
}

void DataCollectorFactory::createDataCollector(int type)
{
 //   m_dataCollector = NULL;
    switch(type)
    {
    case dstComm:
        {
            dataCollector = new CommDataCollector();
            QObject::connect(dataCollector, SIGNAL(dataCollected(QByteArray,qint16)),
                                &DataAnalyser::instance(), SLOT(AnalyseData2(QByteArray,qint16)));

            cachedatasaver = new CacheDataSaver();
            cachedatasaver->start();
            QObject::connect(dataCollector,SIGNAL(cacheData(QByteArray,qint16)),
                                cachedatasaver,SLOT(onDataCollected(QByteArray)));
        }
        break;
   case dstFile:
        {
            dataCollector = new FileDataCollector;
            QObject::connect(dataCollector, SIGNAL(dataCollected(QByteArray,qint16)),
                                &DataAnalyser::instance(), SLOT(AnalyseData4(QByteArray)));
        }
        break;
    default:
        break;
    }

   // return m_dataCollector;
}

AbstractDataCollector *DataCollectorFactory::getDataCollector()
{
    return dataCollector;
}

CacheDataSaver *DataCollectorFactory::getCacheDataSaver()
{
    return cachedatasaver;
}
