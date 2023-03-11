
//PlotSeriesData::PlotSeriesData(size_t numPoints)
//{
//   data = new DataCache(NULL,numPoints);
//}
//size_t PlotSeriesData::size() const
//{
//    return data->GetCount();
//}

//QPointF PlotSeriesData::sample( size_t i ) const
//{
//    if(data->GetCount()>0)
//    {
//        DataCache::iterator iter = data->first();
//        Data mdata = *(iter+i);
//        const double x = i;
//        const double y = mdata.value;

//        return QPointF( x, y );
//    }
//    else
//        return QPointF( 0, 0 );
//}

//QRectF PlotSeriesData::boundingRect() const
//{
//    return QRectF( 43000.0, 0, 44000.0, 10000 );
//}
//void PlotSeriesData::AddData(double key, double value, short flag ) // 添加数据
//{
//   data->AddData(key,value,flag);
//}


#include "plotseriesdata.h"
#include "signaldata.h"
PlotSeriesData::PlotSeriesData()
{

}

const SignalData &PlotSeriesData::values() const
{
    return d_data;
}

SignalData &PlotSeriesData::values()
{
    return d_data;
}

QPointF PlotSeriesData::sample( size_t i ) const
{
    return d_data.value( i );
}

size_t PlotSeriesData::size() const
{
    return d_data.size();
}

QRectF PlotSeriesData::boundingRect() const
{
    return d_data.boundingRect();
}
