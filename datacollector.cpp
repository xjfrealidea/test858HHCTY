#include "datacollector.h"
#include "settings.h"

DataCollector::DataCollector()
{
}

DataCollector::~DataCollector()
{
}

void DataCollector::start()
{
    if (!m_timer)
    {
        m_dataFile = new QFile(Settings::instance()["DataCollect/FileName"].toString(), this);//数据文件名字
        m_dataFile->open(QIODevice::ReadOnly);
        m_dataStream = new QDataStream(m_dataFile);
        m_dataStream->skipRawData(1);   //一个字节一个字节读取
        m_timer = new QTimer(this);
        //设置时间精确到毫秒
        m_timer->setTimerType(Qt::PreciseTimer);//QT::PreciseTimer 值为0  精确到毫秒
        connect(m_timer, SIGNAL(timeout()), this, SLOT(readDataFile()));
    }
    m_timer->start(20);
}

void DataCollector::stopCollect()
{
    m_timer->stop();
}

void DataCollector::readDataFile()
{
    SAVE_DATA savedata;
    m_dataStream->readRawData((char*)&savedata, sizeof(SAVE_DATA));
    emit dataCollected(&savedata);
}
