#ifndef RASTERDATA_H
#define RASTERDATA_H
#include <qwt_matrix_raster_data.h>
#include <QString>
#include <QVector>

#define MAX_MATRIX 40
#define ZERONUM 1000000
#define MIN_SCALE 0.000001
typedef struct gps_data
{
    double gps_lon;
    double gps_lat;
    double mag_data;
}GPSDATA;

class RasterData : public QwtMatrixRasterData
{
public:
    RasterData();

    bool setGridData(QString filename);
    bool intGridData();
    bool setGpsData(QString filename);
    bool setDrawData(QString filename, double LLx, double LLy, double URx, double URy);
    void setFileCache();
    int gpsValueToInt(double value);
    void addData(double x,double y,double data);
    void differenceValue();
    void printGridData(QString filename);
 //   virtual QRectF pixelHint(const QRectF & area) const;
//    virtual double value( double x, double y ) const;

    GPSDATA selectNearData(GPSDATA data1, GPSDATA data2, double x, double y);

    void recheckMaxMinValue(double right, double left, double top, double bottom,int type);

    void checkGridMaxMinValue(double max_x, double min_x, double min_y, double max_y);
    void checkGpsMaxMinValue(double max_lon, double min_lon, double min_lat, double max_lat);

    void exportGrid();

    double max_value;
    double min_value;
    double max_gps_lon;
    double min_gps_lon;
    double max_gps_lat;
    double min_gps_lat;
    double dx;
    double dy;
    double gridDis_x;
    double gridDis_y;

    double max_value_changed;
    double min_value_changed;

    double posx;
    double posy;
    double max_value_lon;
    double min_value_lon;
    double max_value_lat;
    double min_value_lat;

private:
    QVector<double> v_cache;

    QVector<GPSDATA> d_data;
  //  QVector<GPSDATA> d_datacache;
    bool gps_flag;
    double falgToGrid;  //数据转换因子；
    GPSDATA gridcache[MAX_MATRIX][MAX_MATRIX];
    GPSDATA gridcacheP[MAX_MATRIX][MAX_MATRIX];

    int offset;
    int data_row;
    int data_column;
};

#endif // RASTERDATA_H
