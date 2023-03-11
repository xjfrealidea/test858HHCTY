#include "RealTimeMapView.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QApplication>

RealTimeMapView::RealTimeMapView(QObject *parent) :
    QObject(parent)
{
    data = NULL;
}

RealTimeMapView::~RealTimeMapView()
{

}

void RealTimeMapView::distCompare(MAGDATA new_data)
{
    cache_mutex.lock();

    mag_cache->push_back(new_data);
    /*
    if (mag_cache->size() > 300)
    {
        mag_cache->pop_front();

    }
*/
    cache_mutex.unlock();
    return;
}

bool RealTimeMapView::drawMap()
{
    cache_mutex.lock();
    QString path = QApplication::applicationDirPath() + "/data/";
    QDir().mkpath(path);

    QString fileName = "grid_0.txt";
    QString filePathName = path + fileName;
    QFile *gridFile = new QFile(filePathName);
    gridFile->open(QIODevice::WriteOnly);
    QTextStream *grid_Saver = new QTextStream(gridFile);

    for (int i = 0 ; i < mag_cache->size(); i++)
    {
        char buff[100] = "";

        sprintf(buff,"%15.11lf %15.11lf %lf %lf %lf",
                mag_cache->at(i).gps_lon, mag_cache->at(i).gps_lat,
                mag_cache->at(i).mag_data1, mag_cache->at(i).mag_data2,
                mag_cache->at(i).mag_data1 - mag_cache->at(i).mag_data2);

        *grid_Saver<<buff<<'\r'<<'\n';
        (*gridFile).flush();

    }

    if(gridFile != NULL)
    {
        gridFile->close();
        delete gridFile;
        gridFile = NULL;
        delete grid_Saver;
        grid_Saver = NULL;
    }
    cache_mutex.unlock();

    if (data != NULL)
    {
        delete data;
        data = NULL;
    }
    data = new RasterData();
    bool ret = data->setGpsData(filePathName);
    if (ret == true)
    {
        emit mapData(data);
    }
    return ret;
}

void RealTimeMapView::format()
{
    mag_cache = new QVector<MAGDATA>;
    mag_cache->clear();

    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),
            this,SLOT(onTimeOut()));

    //spectrogramplot = NULL;
    //lastplot = NULL;

    max_lon = -361.0;
    min_lon = 361.0;
    max_lat = -361.0;
    min_lat = 361.0;

  //  mainLayout = new QHBoxLayout(&mainWidget);
}

void RealTimeMapView::addData(int type, double mag1, double mag2, double lon, double lat)
{
    if (type == 0)
    {
        return;
    }
    MAGDATA new_data;
    new_data.gps_lat = lat;
    new_data.gps_lon = lon;
    new_data.mag_data1 = mag1;
    new_data.mag_data2 = mag2;

    if (lon > max_lon)
    {
        max_lon = lon;
    }
    else if (lon < min_lon)
    {
        min_lon = lon;
    }
    if (lat > max_lat)
    {
        max_lat = lat;
    }
    else if (lat < min_lat)
    {
        min_lat = lat;
    }

    distCompare(new_data);
    if (mag_cache->size() > 300)
    {
        if ( (max_lon - min_lon > 0.00002)
            && (max_lat - min_lat > 0.00002))
        {
            ////绘图
            bool ret = drawMap();
            ///
            if (true == ret)
            {
                mag_cache->remove(0,mag_cache->size() - 100);
            }
        }
        mag_cache->remove(0,mag_cache->size() - 150);

        max_lon = -361.0;
        min_lon = 361.0;
        max_lat = -361.0;
        min_lat = 361.0;

        for (int i = 0; i < mag_cache->size(); i++)
        {
            if (mag_cache->at(i).gps_lon > max_lon)
            {
                max_lon = mag_cache->at(i).gps_lon;
            }
            else if (mag_cache->at(i).gps_lon < min_lon)
            {
                min_lon = mag_cache->at(i).gps_lon;
            }
            if (mag_cache->at(i).gps_lat > max_lat)
            {
                max_lat = mag_cache->at(i).gps_lat;
            }
            else if (mag_cache->at(i).gps_lat < min_lat)
            {
                min_lat = mag_cache->at(i).gps_lat;
            }
        }
    }
}

void RealTimeMapView::onTimeOut()
{
    cache_mutex.tryLock();



    cache_mutex.unlock();
}

void RealTimeMapView::timerStart(int msec)
{
    m_timer->start(msec);
}

void RealTimeMapView::timerStop()
{
    m_timer->stop();
}
