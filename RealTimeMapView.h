#ifndef REALTIMEMAPVIEW_H
#define REALTIMEMAPVIEW_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QString>
#include <QMutex>
#include <QTimer>
#include "spectrogramplot.h"
#include <QWidget>
#include <QHBoxLayout>

typedef struct mag_data
{
    double gps_lon;
    double gps_lat;
    double mag_data1;
    double mag_data2;
}MAGDATA;

class RealTimeMapView : public QObject
{
    Q_OBJECT

public:
    explicit RealTimeMapView(QObject *parent = 0);
    ~RealTimeMapView();

    void distCompare(MAGDATA new_data);

    bool drawMap();

 //   QWidget mainWidget;

Q_SIGNALS:
    void newMap(QWidget *w);
    void mapData(RasterData *data);

public slots:
    void format();
    void addData(int type, double mag1, double mag2, double lon, double lat);
    void onTimeOut();
    void timerStart(int msec = 5000);
    void timerStop();

private:
    QMutex cache_mutex;

    QTimer *m_timer;
    QVector<MAGDATA> *mag_cache;

    RasterData *data;

  //  QHBoxLayout *mainLayout;
  //  SpectrogramPlot *spectrogramplot;
  //  SpectrogramPlot *lastplot;

    double max_lon;
    double min_lon;
    double max_lat;
    double min_lat;
};

#endif // REALTIMEMAPVIEW_H
