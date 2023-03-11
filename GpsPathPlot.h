#ifndef GPSPATHPLOT_H
#define GPSPATHPLOT_H

#include <QObject>
#include <QWidget>
#include <qwt_plot.h>
#include <qwt_plot.h>
#include <qwt_system_clock.h>
#include "common.h"
#include "plotseriesdata.h"
#include <qwt_plot_curve.h>

class QwtPlotGrid;
class QwtPlotCurve;
class QwtPlotMarker;
class QwtPlotDirectPainter;
class GpsPathPlot : public QwtPlot
{
    Q_OBJECT
public:
    GpsPathPlot ( QWidget* = NULL );
    virtual void replot();
    virtual bool eventFilter(QObject *object, QEvent * event);

    PlotSeriesData *getSeriesData() {return seriesData;}
    PlotSeriesData *getSeriesData1() {return seriesData1;}

    QwtPlotCurve *d_curve;      //曲线

public Q_SLOTS:
    void setIntervalRange(double minLon, double maxLon, double minLat, double maxLat);
    void SetTimeScaleEngine();
protected:
    virtual void timerEvent(QTimerEvent *event );
    virtual void showEvent( QShowEvent * );
    virtual void resizeEvent(QResizeEvent * event);
private:

    void alignScales();
    int d_paintedPoints;

    QwtInterval d_interval_lon; //经度范围
    QwtInterval d_interval_lat; //纬度范围
    QwtPlotGrid *d_grid;        //网格
    QwtPlotMarker *d_origin;
    QwtSystemClock d_clock;     //高精度定时器时钟

    int d_timerId;              //定时器ID标识符

    PlotSeriesData *seriesData;

    QwtPlotCurve *d_curve1;      //曲线
    PlotSeriesData *seriesData1;
};

#endif // GPSPATHPLOT_H
