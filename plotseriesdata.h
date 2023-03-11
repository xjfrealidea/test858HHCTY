#ifndef PLOTSERIESDATA_H
#define PLOTSERIESDATA_H
#include <qwt_series_data.h>
#include <qpointer.h>
#include <signaldata.h>

class SignalData;

class PlotSeriesData: public QwtSeriesData<QPointF>
{
public:
    PlotSeriesData();
    const SignalData &values() const;
    SignalData &values();

    virtual QPointF sample( size_t i ) const;
    virtual size_t size() const;

    virtual QRectF boundingRect() const;
    SignalData d_data;
};
#endif // PLOTSERIESDATA_H
