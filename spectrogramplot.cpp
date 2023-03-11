//#include <qprinter.h>
//#include <qprintdialog.h>
#include <qnumeric.h>

#include "spectrogramplot.h"
#include <QFile>
#include <QApplication>
#include <QDataStream>
#include <macro.h>

class GScaleDraw: public QwtScaleDraw
{
public:
    GScaleDraw()
    {
        setTickLength( QwtScaleDiv::MinorTick, 0 );
        setTickLength( QwtScaleDiv::MediumTick, 0 );
        setTickLength( QwtScaleDiv::MajorTick, 2 );

        enableComponent( QwtScaleDraw::Backbone, false );
    }
    virtual QwtText label(double value) const
    {
        QString s;
        s = QString::asprintf("%.7f",value);
        QwtText text( s );
        return text;
    }
};
class MyZoomer: public QwtPlotZoomer
{
public:
    MyZoomer( QWidget *canvas ):
        QwtPlotZoomer( canvas )
    {
        setTrackerMode( AlwaysOn );
    }

    virtual QwtText trackerTextF( const QPointF &pos ) const
    {
       //const QDateTime dt = QwtDate::toDateTime( pos.x() );
        double x,y;
        x = pos.x();
        y = pos.y();

        QString s;
       // s += QwtDate::toString( QwtDate::toDateTime( pos.x() ),
       //     "MMM dd hh:mm ", QwtDate::FirstThursday );

        s = QString::asprintf("x:%.7f,y:%.7f",x,y);
        QwtText text( s );
        text.setColor( Qt::white );

        QColor c = rubberBandPen().color();
        text.setBorderPen( QPen( c ) );
        text.setBorderRadius( 6 );
        c.setAlpha( 170 );
        text.setBackgroundBrush( c );

        return text;
    }
};

SpectrogramPlot::SpectrogramPlot(QString gridFilePath, short type, double LLx, double LLy, double URx, double URy, QWidget *parent ):
    QwtPlot( parent ),
    d_alpha(255)
{
    d_spectrogram = new QwtPlotSpectrogram();
    d_spectrogram->setRenderThreadCount( 0 ); // use system specific thread count
    d_spectrogram->setCachePolicy( QwtPlotRasterItem::PaintCache );

    if (gridFilePath.isEmpty())
    {
        return;
    }
    data = new RasterData();
    //QString filePath = QApplication::applicationDirPath() + "/grid.txt";

    if (type == 0)
    {
        setflag = data->setGridData(gridFilePath);
    }
    else if (type == 1)
    {
        setflag = data->setGpsData(gridFilePath);
    }
    else if (type == 2)
    {
        setflag = data->setDrawData(gridFilePath, LLx,LLy,URx,URy);
    }
    if (setflag == false)
    {
        return;
    }

    format(type, data);
}

void SpectrogramPlot::format(short type, RasterData *mapData)
{
    data = mapData;
    //QString filePath = QApplication::applicationDirPath() + "/grid.txt";

    QList<double> contourLevels;
    for ( double level = data->min_value; level <= data->max_value; level += ((data->max_value-data->min_value)/20) )
        contourLevels += level;
    d_spectrogram->setDefaultContourPen(QPen( Qt::white, 0 ));
    d_spectrogram->setContourLevels( contourLevels );
    d_spectrogram->setConrecFlag( QwtRasterData::IgnoreOutOfRange,true);
    d_spectrogram->setData( data );

    d_spectrogram->attach( this );

    const QwtInterval zInterval = d_spectrogram->data()->interval( Qt::ZAxis );

    // A color bar on the right axis
    QwtScaleWidget *rightAxis = axisWidget( QwtPlot::yRight );
    rightAxis->setColorBarEnabled( true );

    setAxisScale( QwtPlot::yRight, zInterval.minValue(), zInterval.maxValue() );
    enableAxis( QwtPlot::yRight );
    if (type == 1)   //GPS
    {
        GScaleDraw *yscaleDraw = new GScaleDraw();
        GScaleDraw *xscaleDraw = new GScaleDraw();

        setAxisScaleDraw(QwtPlot::yLeft,yscaleDraw);
        setAxisScaleDraw(QwtPlot::xBottom,xscaleDraw);
   //调整经纬度的刻度一致
        double tmplon = data->max_gps_lon-data->min_gps_lon;
        double tmplat = data->max_gps_lat-data->min_gps_lat;
        double tmpsetp;
        if(tmplat > tmplon)
        {
            tmpsetp = tmplat/10;
            setAxisScale( QwtPlot::yLeft, data->min_gps_lat, data->max_gps_lat,tmpsetp);
            tmpsetp = tmplat/5;
            setAxisScale( QwtPlot::xBottom, data->min_gps_lon -(tmplat-tmplon)/2, data->max_gps_lon+(tmplat-tmplon)/2,tmpsetp);
        }
        else
        {
            tmpsetp = tmplon/10;
            setAxisScale( QwtPlot::yLeft, data->min_gps_lat-(tmplon-tmplat)/2, data->max_gps_lat+(tmplon-tmplat)/2,tmpsetp);
            tmpsetp = tmplon/5;
            setAxisScale( QwtPlot::xBottom, data->min_gps_lon, data->max_gps_lon,tmpsetp);
        }

    }

    d_spectrogram->setDisplayMode(QwtPlotSpectrogram::ContourMode);
    plotLayout()->setAlignCanvasToScales( true );

    setColorMap( SpectrogramPlot::RGBMap );

    // LeftButton for the zooming
    // MidButton for the panning
    // RightButton: zoom out by 1
    // Ctrl+RighButton: zoom out to full size

    zoomer = new MyZoomer( canvas() );
    zoomer->setMousePattern( QwtEventPattern::MouseSelect2,
        Qt::RightButton, Qt::ControlModifier );
    zoomer->setMousePattern( QwtEventPattern::MouseSelect3,
        Qt::RightButton );

    QwtPlotPanner *panner = new QwtPlotPanner( canvas() );
    panner->setAxisEnabled( QwtPlot::yRight, false );
    panner->setMouseButton( Qt::MidButton );

    // Avoid jumping when labels with more/less digits
    // appear/disappear when scrolling vertically

   // const QFontMetrics fm( axisWidget( QwtPlot::yLeft )->font() );
   // QwtScaleDraw *sd = axisScaleDraw( QwtPlot::yLeft );
   // sd->setMinimumExtent( fm.width( "10.00000" ) );

//    const QColor c( Qt::darkBlue );
//    zoomer->setRubberBandPen( c );
//    zoomer->setTrackerPen( c );

}

void SpectrogramPlot::mapReplot()
{
    replot();
}

void SpectrogramPlot::setCursorTxt(double x, double y)
{

}

void SpectrogramPlot::exportGrid()
{
    data->exportGrid();
}

void SpectrogramPlot::showContour( bool on )
{
    d_spectrogram->setDisplayMode( QwtPlotSpectrogram::ContourMode, on );
    replot();
}

void SpectrogramPlot::showSpectrogram( bool on )
{
    d_spectrogram->setDisplayMode( QwtPlotSpectrogram::ImageMode, on );
    d_spectrogram->setDefaultContourPen(
        on ? QPen( Qt::black, 0 ) : QPen( Qt::NoPen ) );

    replot();
}

void SpectrogramPlot::setColorMap(int type , const QwtInterval *interval)
{
    QwtScaleWidget *axis = axisWidget( QwtPlot::yRight );
    const QwtInterval *zInterval = NULL;
    if (interval == NULL)
    {
        zInterval = &(d_spectrogram->data()->interval( Qt::ZAxis ));
    }
    else
    {
        zInterval = interval;
        d_spectrogram->data()->setInterval(Qt::ZAxis,*zInterval);
    }

    d_mapType = type;

    int alpha = d_alpha;
    switch( type )
    {
        case SpectrogramPlot::HueMap:
        {
            d_spectrogram->setColorMap( new HueColorMap() );
            axis->setColorMap( *zInterval, new HueColorMap() );
            break;
        }
        case SpectrogramPlot::AlphaMap:
        {
            alpha = 255;
            d_spectrogram->setColorMap( new AlphaColorMap() );
            axis->setColorMap( *zInterval, new AlphaColorMap() );
            break;
        }
        case SpectrogramPlot::IndexMap:
        {
            d_spectrogram->setColorMap( new LinearColorMapIndexed() );
            axis->setColorMap( *zInterval, new LinearColorMapIndexed() );
            break;
        }
        case SpectrogramPlot::BlockRGB:
        {
            d_spectrogram->setColorMap( new BlockColorMap() );
            axis->setColorMap( *zInterval, new BlockColorMap() );
            break;
        }
        case SpectrogramPlot::RGBMap:
        default:
        {
            d_spectrogram->setColorMap( new LinearColorMapRGB() );
            axis->setColorMap( *zInterval, new LinearColorMapRGB() );
        }
    }
    d_spectrogram->setAlpha( alpha );

    replot();
}

void SpectrogramPlot::setAlpha( int alpha )
{
    // setting an alpha value doesn't make sense in combination
    // with a color map interpolating the alpha value

    d_alpha = alpha;
    if ( d_mapType != SpectrogramPlot::AlphaMap )
    {
        d_spectrogram->setAlpha( alpha );
        replot();
    }
}

void SpectrogramPlot::mousePressEvent(QMouseEvent *e)
{
    if (e->KeyPress == Qt::RightButton)
    {
        qDebug() << "mouse right press";
    }
    QwtPlot::mousePressEvent(e);
}

void SpectrogramPlot::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->KeyPress == Qt::RightButton)
    {
        qDebug() << "mouse right release";
    }
    QwtPlot::mouseReleaseEvent(e);
}
