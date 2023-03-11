#include "commdatacollector.h"
#include "settings.h"
#include "systemdetail.h"
#include <QDialog>
//#include <unistd.h>
#include <QThread>
#include <QDebug>


CommDataCollector::CommDataCollector(short type, QObject *parent) :
    AbstractDataCollector(parent),type(type)
{
    m_timer = NULL;
    pauseFlag = true;
    //connect(this,SIGNAL(portOpenFailed(int)),
      //      this,SLOT(retakeOpenPort()));


    gpsDataLen = 104;
    resetCount = 0;
    mCount = 0;
    hzCount = 1;
}

CommDataCollector::~CommDataCollector()
{
    if (m_port.isOpen())
    {
        m_port.close();
    }
}

void CommDataCollector::start()
{
    if (m_timer == NULL)
    {
        // 设置串口号和波特率：
        QString portName;
        int no;
        if (type == 0)
        {
            portName = Settings::instance()["COM/No"].toString();
            no = Settings::instance()["COM/Baud"].toInt();
        }

        m_port.setPortName(portName);
        m_port.setBaudRate(no);
        m_port.setDataBits(QSerialPort::Data8);
        m_port.setParity(QSerialPort::NoParity);
        m_port.setStopBits(QSerialPort::OneStop);
        m_port.setFlowControl(QSerialPort::NoFlowControl);

        // 打开串口
        if(m_port.open(QIODevice::ReadWrite))	// 串口打开成功
        {

            m_port.clear();	// 清空串口内部缓冲区

            m_timer = new QTimer(this);
            m_timer->setTimerType(Qt::PreciseTimer);

            connect(m_timer, SIGNAL(timeout()), this, SLOT(readDataFile()));

            QThread::sleep(1);
            m_timer->start(20);

            emit portOpenSuccessed();
        }
        else
        {
            m_port.close();

            emit portOpenFailed(1);
        }

    }

}

void CommDataCollector::startCollect()
{
    pauseFlag = false;
}

void CommDataCollector::stopCollect()
{
    pauseFlag = true;
}

void CommDataCollector::retakeOpenPort()
{
    start();
}

void CommDataCollector::timerStop()
{
    /*if(m_timer && m_timer->isActive())
    {
        m_timer->stop();
    }*/
}

void CommDataCollector::sendCommand(QString cmd)
{
    QByteArray ba;
    ba.append(cmd);

    int ret = m_port.write(ba);
    qDebug() << ret;
}

void CommDataCollector::readDataFile()
{
    int inx;
    QByteArray tmp = m_port.readAll();

    if (tmp.isEmpty())
    {
        resetCount++;
        if (resetCount > 100)
        {
            m_port.reset();
            resetCount = 0;
        }
        emit portOpenFailed(2);
        return;
    }
    else
    {
        resetCount = 0;
        m_dataCache.append(tmp);
    }
    do
    {
        inx = m_dataCache.indexOf("<");
        if(inx > 0)
        {
            m_dataCache.remove(0,inx);
        }
        if(inx >= 0)
        {
            inx = m_dataCache.indexOf("dat");
            if(inx>=0)
            {
                inx = m_dataCache.indexOf(">");
                if(inx>=0)
                {
                    temp = m_dataCache.left(inx+1);
//                    temp.append(",>");
                    m_dataCache.remove(0,inx+1);

                    if (!pauseFlag)
                    {
    //                    if (mCount % hzCount == 0)
    //                    {
                            emit dataCollected(temp,12);
    //                        mCount = 0;
    //                    }
    //                    mCount++;
                    }

    //                emit cacheData(temp,12);
                }
            }
            else
            {
                inx = m_dataCache.indexOf("sta");
                if(inx>=0)
                {
                    inx = m_dataCache.indexOf(">");
                    if(inx>=0)
                    {
                        temp = m_dataCache.left(inx+1);
//                        temp.append(",>");
                        m_dataCache.remove(0,inx+1);

                        emit statusData(temp,12);
     //                emit cacheData(temp,12);
                    }
                }
            }
        }
    }while(inx>=0);


}



