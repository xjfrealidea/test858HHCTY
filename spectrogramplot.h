#ifndef SPECTROGRAMPLOT_H
#define SPECTROGRAMPLOT_H
#include <qwt_plot.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_matrix_raster_data.h>
#include <QVector>
#include "rasterdata.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <qwt_color_map.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_renderer.h>

class SpectrogramPlot: public QwtPlot
{
    Q_OBJECT

public:
    enum ColorMap
    {
        HueMap,
        IndexMap,
        RGBMap,
        AlphaMap,
        BlockRGB
    };

    SpectrogramPlot(QString gridFilePath = "", short type = 0, double LLx=0.0, double LLy=0.0, double URx=0.0, double URy=0.0, QWidget *parent = NULL );

    QwtPlotSpectrogram *get_d_spectrogram() {return d_spectrogram;}
    void setRasterData();

    void format(short type, RasterData* mapData);
    void mapReplot();
    bool setflag;

    const QwtPlotZoomer* getPlotZoomer() {return zoomer;}
    void setZoom(int type) {zoomer->zoom(type);}

    RasterData* getRasterData() {return data;}

    void setCursorTxt(double x, double y);


    void exportGrid();


public Q_SLOTS:
    void showContour( bool on );
    void showSpectrogram( bool on );
    void setColorMap(int type, const QwtInterval *interval = NULL);
    void setAlpha( int alpha);

protected:

    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

private:
    QwtPlotSpectrogram *d_spectrogram;
    RasterData* data;
    QwtPlotZoomer* zoomer;

    int d_mapType;
    int d_alpha;

    double max_level;
    double min_level;

    QVector<double> v_cache;
};

class LinearColorMapRGB: public QwtLinearColorMap
{
public:
    LinearColorMapRGB():
        QwtLinearColorMap( Qt::blue, Qt::red, QwtColorMap::RGB )
    {
        addColorStop( 0.25, Qt::cyan );
        addColorStop( 0.5, Qt::green );
        addColorStop( 0.75, Qt::yellow );
    }
};

class LinearColorMapIndexed: public QwtLinearColorMap
{
public:
    LinearColorMapIndexed():
        QwtLinearColorMap( Qt::darkCyan, Qt::red, QwtColorMap::Indexed )
    {
        addColorStop( 0.1, Qt::cyan );
        addColorStop( 0.6, Qt::green );
        addColorStop( 0.95, Qt::yellow );
    }
};

class HueColorMap: public QwtColorMap
{
public:
    // class backported from Qwt 6.2

    HueColorMap():
        d_hue1(0),
        d_hue2(359),
        d_saturation(150),
        d_value(200)
    {
        updateTable();

    }

    virtual QRgb rgb( const QwtInterval &interval, double value ) const
    {
        if ( qIsNaN(value) )
            return 0u;

        const double width = interval.width();
        if ( width <= 0 )
            return 0u;

        if ( value <= interval.minValue() )
            return d_rgbMin;

        if ( value >= interval.maxValue() )
            return d_rgbMax;

        const double ratio = ( value - interval.minValue() ) / width;
        int hue = d_hue1 + qRound( ratio * ( d_hue2 - d_hue1 ) );

        if ( hue >= 360 )
        {
            hue -= 360;

            if ( hue >= 360 )
                hue = hue % 360;
        }

        return d_rgbTable[hue];
    }

    virtual unsigned char colorIndex( const QwtInterval &, double ) const
    {
        // we don't support indexed colors
        return 0;
    }


private:
    void updateTable()
    {
        for ( int i = 0; i < 360; i++ )
            d_rgbTable[i] = QColor::fromHsv( i, d_saturation, d_value ).rgb();

        d_rgbMin = d_rgbTable[ d_hue1 % 360 ];
        d_rgbMax = d_rgbTable[ d_hue2 % 360 ];
    }

    int d_hue1, d_hue2, d_saturation, d_value;
    QRgb d_rgbMin, d_rgbMax, d_rgbTable[360];
};
class BlockColorMap: public QwtColorMap
{
public:
    BlockColorMap()
    {
        updateTable();

    }

    virtual QRgb rgb( const QwtInterval &interval, double value ) const
    {
        if ( qIsNaN(value) )
            return 0u;

        const double width = interval.width();
        if ( width <= 0 )
            return 0u;

        if ( value <= interval.minValue() )
            return d_rgbMin;

        if ( value >= interval.maxValue() )
            return d_rgbMax;

        const double ratio = ( value - interval.minValue() ) / width;
        int hue = qRound( ratio *15);


        return d_rgbTable[hue];
    }

    virtual unsigned char colorIndex( const QwtInterval &, double ) const
    {
        // we don't support indexed colors
        return 0;
    }


private:
    void updateTable()
    {
        d_rgbTable[0] =qRgb(153,102,255);
        d_rgbTable[1] =qRgb(102,68,255);
        d_rgbTable[2] =qRgb(51,34,255);
        d_rgbTable[3] =qRgb(0,0,255);
        d_rgbTable[4] =qRgb(0,85,170);
        d_rgbTable[5] =qRgb(0,170,85);
        d_rgbTable[6] =qRgb(0,255,0);
        d_rgbTable[7] =qRgb(85,255,0);
        d_rgbTable[8] =qRgb(170,255,0);
        d_rgbTable[9] =qRgb(255,255,0);
        d_rgbTable[10] =qRgb(255,204,0);
        d_rgbTable[11] =qRgb(255,153,0);
        d_rgbTable[12] =qRgb(255,102,0);
        d_rgbTable[13] =qRgb(255,68,0);
        d_rgbTable[14] =qRgb(255,34,0);
        d_rgbTable[15] =qRgb(255,0,0);


        d_rgbMin = d_rgbTable[ 15];
        d_rgbMax = d_rgbTable[ 0 ];
    }
    QRgb d_rgbMin, d_rgbMax, d_rgbTable[16];
};
class AlphaColorMap: public QwtAlphaColorMap
{
public:
    AlphaColorMap()
    {
        //setColor( QColor("DarkSalmon") );
        setColor( QColor("SteelBlue") );
    }
};

#endif
