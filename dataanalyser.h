#ifndef DATAANALYSER_H
#define DATAANALYSER_H

#include "datacache.h"
#include <QObject>
#include "common.h"
#include "gdecode.h"
#include "Filter.h"
#include <QReadWriteLock>

#define DATACACHE_LEN  576000  // 8小时
//#define DATACACHE_LEN  5000  // 8小时

typedef struct   // 实时磁补偿程序输入和输出的数据结构
{
    double magbefore1; // 补偿前的光泵数据
    double magbefore2; // 补偿前的光泵数据
    double magbefore3; // 补偿前的光泵数据
    double magbefore4; // 补偿前的光泵数据
    double magbefore5; // 补偿前的光泵数据
    double magbefore6; // 补偿前的光泵数据
    double magbefore7; // 补偿前的光泵数据

    double ad1; // 横滚角
    double ad2; // 俯仰角
    double gps_velocity; // GPS地速
    double gps_direction; // GPS航向
    double gps_long; // GPS经度
    double gps_lat;  // GPS纬度
    double high;     // 高度
    double magafter; // 补偿后的光泵数据
    double magmid;
    char time[14];//时间
    char flag[4];
    unsigned char state;    //目标状态
}COMPENSATE_DATA;

typedef struct   // 实时磁补偿程序输入和输出的数据结构
{
    double magbefore; // 补偿前的光泵数据

    int aix1_bc; // 磁补偿探头1X分量 补偿后
    int aix2_bc; // 磁补偿探头1Y分量 补偿后
    int aix3_bc; // 磁补偿探头1Z分量 补偿后

    float ad1; // 横滚角
    float ad2; // 俯仰角
    float gps_velocity; // GPS地速
    float gps_direction; // GPS航向
    float gps_long; // GPS经度
    float gps_lat;  // GPS纬度
    float high;     // 高度
    float magafter; // 磁补偿再经滤波后剩余信号
    float magmid;   // 经滤波后剩余信号(未补偿)
    float magSP;    // 时频图数据
    char time[14];  // 时间
    unsigned char state;    //目标状态
}SAVE_DATA;

typedef struct
{
    unsigned int solstat;       //4
    unsigned int postype;       //4
    double lat;                 //8 纬度
    double lon;                 //8 经度
    double hgt;                 //8
    float undulation;           //4
    unsigned int datumid;       //4
    float latq;                 //4
    float lonq;                 //4
    float hgtq;                 //4
    unsigned int stnid;         //4
    float diffage;              //4
    float solage;               //4
    unsigned char svs;              //1
    unsigned char solnsvs;          //1
    unsigned char solnl1svs;        //1
    unsigned char solnmultisvs;     //1
    unsigned char reserved;         //1
    unsigned char extsolstat;       //1
    unsigned char galileoand;       //1
    unsigned char gps_glonass_sigImask;     //1
    unsigned int crc;                       //4
}GPS_DATA;
class DataAnalyser : public QObject
{
    Q_OBJECT

    SINGLETON(DataAnalyser)
signals:
    void dataCollected(int,double,double,double,double);
    void fieldData(int,double,double,double,double);
    void gpsStatus(int, int);

public slots:
    void changeSpeed(int hz);
//串口
    void AnalyseData2(QByteArray data,qint16 len);
//文件
    void AnalyseData4(QByteArray data);
//GPS
//    void AnalyseData6(QByteArray data,qint16 len);

    void dataReset();
    void setHzCount(int hz);

public:

    char* GetValue(const char *dataBuf,int num,char* values);
    COMPENSATE_DATA mBCData;
    DataCache      *mGBData1;      // mag1 origin
    DataCache      *mGBData2;      // mag2 origin
    DataCache      *mGBData3;      // mag1-mag2
    DataCache      *mGBData1_BC;      // mag1 after BC
    DataCache      *mGBData2_BC;      // mag2 after BC
    DataCache      *mGBData3_BC;      // mag1-mag2 after BC

    int  mCount;
    int  hzCount;
    double mag_data1;
    double mag_data2;
    double mag_delta;
    double gps_lon;                //经度
    double gps_lat;                //纬度
    double last_lon;
    double last_lat;
    double gps_delta;

    int gps_postype;            //

    int last_msecs;
    double last_mag1;
    double last_mag2;

    bool start_mag;
};


#endif // DATAANALYSER_H
