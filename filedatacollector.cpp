#include "filedatacollector.h"
#include "settings.h"
#include "systemdetail.h"
#include <QDebug>

FileDataCollector::FileDataCollector(QObject* parent) :
    AbstractDataCollector(parent)
{
    m_timer = NULL;
    pauseFlag = true;
}

FileDataCollector::~FileDataCollector()
{

}

void FileDataCollector::start()
{
    if(m_timer == NULL)
    {
        m_dataFile = new QFile(Settings::instance()["File/Name"].toString(), this);
        if(m_dataFile->open(QIODevice::ReadOnly))
        {
            m_dataStream = new QDataStream(m_dataFile);
        // m_dataStream->skipRawData(1);
            m_timer = new QTimer(this);
            m_timer->setTimerType(Qt::PreciseTimer);
            connect(m_timer, SIGNAL(timeout()), this, SLOT(readDataFile()));
            //m_timer->start(SystemDetail::instance().getDetail().cycleTime * 1000);
            m_timer->start(20);
        }
    }
    /*else
    {
        m_timer->start(SystemDetail::instance().getDetail().cycleTime * 1000);
    }*/
    //pauseFlag = true;
}

void FileDataCollector::startCollect()
{
    pauseFlag = false;
}

void FileDataCollector::stopCollect()
{
    pauseFlag = true;
}

void FileDataCollector::timerStop()
{
    /*if(m_timer && m_timer->isActive())
    {
        m_timer->stop();
    }*/
}

void FileDataCollector::readDataFile()
{
    int inx;
    int l = m_dataStream->readRawData(buf, 270);//每次读取270个字节长度的数据存进buf里面
    if(l>0)
        m_dataCache.append(buf,l);  //再把buf追加到数据存储器里面
    do
    {
        inx = m_dataCache.indexOf("<");
        if(inx > 0)
        {
            m_dataCache.remove(0,inx);
        }
        if(inx >= 0)
        {
            inx = m_dataCache.indexOf(">");
            if(inx>=0)
            {
                temp = m_dataCache.left(inx);
                temp.append(",>");
                m_dataCache.remove(0,inx+1);
                if (!pauseFlag)
                {
                    emit dataCollected(temp,12);
                }
            }
        }
    }while(inx>=0);
}
