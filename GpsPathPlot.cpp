#include "GpsPathPlot.h"
#include "qwt_plot_canvas.h"
#include "qwt_plot_marker.h"
#include "qwt_plot_curve.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_zoomer.h"
#include "qwt_plot_magnifier.h"
#include "qwt_scale_widget.h"
#include "qwt_plot_layout.h"
#include <QTimerEvent>
#include "qwt_date_scale_draw.h"
#include "qwt_date_scale_engine.h"

class DateScaleDraw: public QwtDateScaleDraw
{
public:
    DateScaleDraw( Qt::TimeSpec timeSpec ):
        QwtDateScaleDraw( timeSpec )
    {
        // as we have dates from 2010 only we use
        // format strings without the year

        setDateFormat( QwtDate::Millisecond, "hh:mm:ss:zzz" );
        setDateFormat( QwtDate::Second, "hh:mm:ss" );
        setDateFormat( QwtDate::Minute, "hh:mm" );
        setDateFormat( QwtDate::Hour, "hh:mm" );
    }
};
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
GpsPathPlot::GpsPathPlot( QWidget *parent ):
    QwtPlot( parent ),
    d_paintedPoints( 0 ),
  //  d_interval(  0.0, 10000.0 ), // seconds
    d_timerId( -1 )
{
    // Assign a title
//    setTitle( "Testing Refresh Rates" );
//    d_directPainter = new QwtPlotDirectPainter();
    QwtPlotCanvas *canvas = new QwtPlotCanvas();
    canvas->setFrameStyle( QFrame::Box | QFrame::Sunken );
    canvas->setLineWidth( 1 );
//    canvas->setPalette( Qt::blue );

    setCanvas( canvas );

    alignScales();
    GScaleDraw *yscaleDraw = new GScaleDraw();
    GScaleDraw *xscaleDraw = new GScaleDraw();

    setAxisScaleDraw(QwtPlot::yLeft,yscaleDraw);
    setAxisScaleDraw(QwtPlot::xBottom,xscaleDraw);
//    setAxisTitle( QwtPlot::xBottom, "tick" );
//    setAxisAutoScale(QwtPlot::xBottom);
//    setAxisScale( QwtPlot::xBottom, -0, 1000 );


//    setAxisTitle( QwtPlot::yLeft, "Values" );
//    setAxisAutoScale(QwtPlot::yLeft);
//    setAxisScale( QwtPlot::yLeft, 43000, 44000 );

    d_origin = new QwtPlotMarker();
    d_origin->setLineStyle( QwtPlotMarker::HLine );
    d_origin->setValue(0.5,0.5);
    //d_origin->setValue( d_interval.minValue() + d_interval.width() / 2.0, 0.0 );
    d_origin->setLinePen( Qt::red, 0.0, Qt::DashLine );
    d_origin->attach( this );

    // Insert curve
    d_curve = new QwtPlotCurve( "Data Moving Right" );

    seriesData = new PlotSeriesData();
    d_curve->setData(seriesData);
    d_curve->attach(this);

    //////
    d_curve1 = new QwtPlotCurve( "Data Moving Right" );

    seriesData1 = new PlotSeriesData();
    d_curve1->setData(seriesData1);
    d_curve1->attach(this);

    // Insert grid
    d_grid = new QwtPlotGrid();
    d_grid->setPen( Qt::red, 0.0, Qt::DotLine );

//    d_grid->enableX( true );
//    d_grid->enableXMin( true );
//    d_grid->enableY( true );
//    d_grid->enableYMin( false );
    d_grid->setZ(0);
    d_grid->attach( this );

#if 0
    QwtPlotZoomer* zoomer = new QwtPlotZoomer( canvas );
    zoomer->setRubberBandPen( QColor( Qt::black ) );
    zoomer->setTrackerPen( QColor( Qt::black ) );
    zoomer->setMousePattern( QwtEventPattern::MouseSelect2,
        Qt::RightButton, Qt::ControlModifier );
    zoomer->setMousePattern( QwtEventPattern::MouseSelect3,
        Qt::RightButton );
#endif
    // Axis
    // panning with the left mouse button
    //( void ) new QwtPlotPanner( canvas );

    // zoom in/out with the wheel
    ( void ) new QwtPlotMagnifier( canvas );


    d_clock.start();
    d_timerId = startTimer( 1000 );
    //setSettings( d_settings );
}

void GpsPathPlot::replot()
{
    QwtPlot::replot();
}

bool GpsPathPlot::eventFilter(QObject *object, QEvent *event)
{
    if ( object == canvas() &&
        event->type() == QEvent::PaletteChange )
    {
       //d_curve->setPen( canvas()->palette().color( QPalette::WindowText ) );
    }

    return QwtPlot::eventFilter( object, event );
}

void GpsPathPlot::setIntervalRange(double minLon, double maxLon, double minLat, double maxLat)
{
    d_interval_lon.setMinValue(minLon);
    d_interval_lon.setMaxValue(maxLon);
    d_interval_lat.setMinValue(minLat);
    d_interval_lat.setMaxValue(maxLat);

    setAxisScale( QwtPlot::xBottom, d_interval_lon.minValue(), d_interval_lon.maxValue() );
    setAxisScale( QwtPlot::yLeft, d_interval_lat.minValue(), d_interval_lat.maxValue() );

    replot();
}

void GpsPathPlot::SetTimeScaleEngine()
{
    QwtDateScaleDraw *scaleDraw = new DateScaleDraw( Qt::UTC );
    QwtDateScaleEngine *scaleEngine = new QwtDateScaleEngine( Qt::UTC );
    setAxisScaleDraw( QwtPlot::xBottom, scaleDraw );
    setAxisScaleEngine( QwtPlot::xBottom, scaleEngine );
}

void GpsPathPlot::timerEvent(QTimerEvent *event)
{
    if ( event->timerId() == d_timerId )
    {
        //updateCurve();

//        const double elapsed = d_clock.elapsed() / 1000.0;
//        if ( elapsed > d_interval.maxValue() )
          //  incrementInterval();
//replot();
        return;
    }

    QwtPlot::timerEvent( event );
}

void GpsPathPlot::showEvent(QShowEvent *)
{
    replot();
}

void GpsPathPlot::resizeEvent(QResizeEvent *event)
{
    QwtPlot::resizeEvent( event );
}

void GpsPathPlot::alignScales()
{
    // The code below shows how to align the scales to
    // the canvas frame, but is also a good example demonstrating
    // why the spreaded API needs polishing.

    for ( int i = 0; i < QwtPlot::axisCnt; i++ )
    {
        QwtScaleWidget *scaleWidget = axisWidget( i );
        if ( scaleWidget )
            scaleWidget->setMargin( 0 );

        QwtScaleDraw *scaleDraw = axisScaleDraw( i );
        if ( scaleDraw )
            scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, false );
    }

    plotLayout()->setAlignCanvasToScales( true );
}
