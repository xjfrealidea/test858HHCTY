#include "dataanalyser.h"
#include <QTime>
#include <QDebug>
#include "settings.h"
#include <math.h>
DataAnalyser::DataAnalyser()
{
    //绘图数据
    mGBData1   = new DataCache(NULL, DATACACHE_LEN);//mag1
    mGBData2   = new DataCache(NULL, DATACACHE_LEN);//mag2
    mGBData3   = new DataCache(NULL, DATACACHE_LEN);//mag1-mag2
    mGBData1_BC   = new DataCache(NULL, DATACACHE_LEN);//mag1 after BC
    mGBData2_BC   = new DataCache(NULL, DATACACHE_LEN);//mag2 after BC
    mGBData3_BC   = new DataCache(NULL, DATACACHE_LEN);//mag1-mag2 after BC

    mCount   = 0;
    hzCount  = 1;
    mag_data1 = 0.0;
    mag_data2 = 0.0;
    mag_delta = 0.0;

    gps_lon = 361.0;
    gps_lat = 361.0;
    last_lon = 361.0;
    last_lat = 361.0;

    gps_delta = Settings::instance()["GPS/DELTA"].toDouble();

    last_mag1 = -1.0;
    last_mag2 = -1.0;
    start_mag = true;
}

DataAnalyser::~DataAnalyser()
{
    if(mGBData1 != NULL)
    {
        delete mGBData1;
        mGBData1 = NULL;
    }
    if(mGBData2 != NULL)
    {
        delete mGBData2;
        mGBData2 = NULL;
    }
    if(mGBData3 != NULL)
    {
        delete mGBData3;
        mGBData3 = NULL;
    }

}
//串口
void DataAnalyser::changeSpeed(int hz)
{
    hzCount = round(100.0 / hz);
    if (hzCount < 1)
    {
        hzCount = 1;
    }
//    qDebug() << "hzCount change " << hzCount;
}

void DataAnalyser::AnalyseData2(QByteArray data,qint16 len)
{
    Q_UNUSED(len);

    char *dataBuf = (char*)data.data();

//    char type[10];
//    GetValue(dataBuf,1,type);
//    if (strcmp(type,"dat"))
//    {

//    }

    char values[600];
    char time [20];

    //读取
    //time
    GetValue(dataBuf,2,time);
    for(int i=0;i<14;i++)
    {
        if(time[i] == ' ')
            time[i] = 0x30;//空置为0
        mBCData.time[i] = time[i];
    }
    QTime qtime = QTime::fromString(time, "hh:mm:ss:zzz");
    int msecs = QTime(0,0).msecsTo(qtime);

    //mag1绘图
    GetValue(dataBuf,3,values);
    mBCData.magafter =  atof(values);
    mGBData1->AddData(msecs, mBCData.magafter);
    mag_data1 = mBCData.magafter;

    //mag2绘图
    GetValue(dataBuf,4,values);
    mBCData.magafter =  atof(values);
    mGBData2->AddData(msecs, mBCData.magafter);
    mag_data2 = mBCData.magafter;

    //mag1-mag2绘图
    mag_delta = mag_data1 - mag_data2;
    mGBData3->AddData(msecs, mag_delta );

    //GPS lon lat绘图
    GetValue(dataBuf,5,values);
    gps_lon =  atof(values);
    GetValue(dataBuf,6,values);
    gps_lat =  atof(values);
    GetValue(dataBuf,7,values);
    gps_postype =  atoi(values);

    if (gps_postype != 0)
    {
        if ( (last_lon > 360 && last_lat > 360)
            || (fabs(last_lon - gps_lon) < gps_delta && fabs(last_lat - gps_lat) < gps_delta) )
        {
            last_lon = gps_lon;
            last_lat = gps_lat;
        }
    }

    last_mag1 = mag_data1;
    last_mag2 = mag_data2;

    //记录数据
    if (start_mag == true)
    {
        emit dataCollected(gps_postype,mag_data1,mag_data2,last_lon,last_lat);

        mCount++;
        start_mag = false;
        return;
    }

//// 100hz 1; 50hz 2;20hz 5;10hz 10;5hz 20;1hz 100
    if (mCount % hzCount == 0)//插值
    {
        emit dataCollected(gps_postype,(mag_data1+last_mag1)/2,(mag_data2+last_mag2)/2,last_lon,last_lat);
//        mCount = 0;
    }
    mCount++;

    if (mCount % hzCount == 0)//原始数据
    {
        emit dataCollected(gps_postype,mag_data1,mag_data2,last_lon,last_lat);
//        mCount = 0;
    }
    mCount++;

    if (mCount % 5 == 0)//信息窗显示数据
    {
        emit fieldData(gps_postype,mag_data1,mag_data2,last_lon,last_lat);
    }

    /////
    if (mCount > 100)
    {
        mCount -= 100;
    }

    last_mag1 = mag_data1;
    last_mag2 = mag_data2;
}
//文件
void DataAnalyser::AnalyseData4(QByteArray data)
{
    char values[600];
    char *dataBuf = (char*)data.data();

    char time [20];
    GetValue(dataBuf,1,time);
    for(int i=0;i<14;i++)
    {
        if(time[i] == ' ')
            time[i] = 0x30;//空置为0
        mBCData.time[i] = time[i];
    }

    QTime qtime = QTime::fromString(time, "hh:mm:ss:zzz");
    int msecs = QTime(0,0).msecsTo(qtime);

    GetValue(dataBuf,2,values);
    mBCData.magafter = atof(values);
    mGBData1->AddData(msecs, mBCData.magafter);
    mag_data1 = mBCData.magafter;

    mGBData2->AddData(msecs, 1.0*mCount);
    mGBData3->AddData(msecs, -1.0*mCount);

    GetValue(dataBuf,3,values);
    gps_lon =  atof(values);

    GetValue(dataBuf,4,values);
    gps_lat =  atof(values);

    GetValue(dataBuf,5,values);
    gps_postype =  atoi(values);

    if (gps_postype != 0)
    {
        if ( (last_lon > 360 && last_lat > 360)
            || (fabs(last_lon - gps_lon) < gps_delta && fabs(last_lat - gps_lat) < gps_delta) )
        {
            last_lon = gps_lon;
            last_lat = gps_lat;
        }
    }

//    if (mCount % 10 == 0)
    {
        emit dataCollected(gps_postype,mag_data1,0.0,last_lon,last_lat);
    }

    if (mCount % 2 == 0)
    {
        emit fieldData(gps_postype,mag_data1,0.0,last_lon,last_lat);
        mCount = 0;
    }

    mCount++;
}

void DataAnalyser::dataReset()
{
    mGBData1->dataReset(DATACACHE_LEN);
    mGBData2->dataReset(DATACACHE_LEN);
    mGBData3->dataReset(DATACACHE_LEN);
}

void DataAnalyser::setHzCount(int hz)
{

}
//////////////////////////////////////////////////////////////////////
char* DataAnalyser::GetValue(const char *dataBuf,int num,char* values)
{
    try
    {
        int tag=0;
        int valuestag=0;
        int length=(int)strlen(dataBuf);
        //qDebug()<<length<<__LINE__<<__FILE__;
        if(num<1)
        {
            values[0]='\0';
            return values;
        }
        for(int i=0;i<length;i++)
        {
            if((dataBuf[i]==',') || (dataBuf[i]=='<') || (dataBuf[i]=='>'))
            {
                if ((i < length-1)
                        && ((dataBuf[i+1]!=',') && (dataBuf[i+1]!='<') && (dataBuf[i+1]!='>')))
                {
                    tag += 1;
                }
            }
            else
            {
                if(tag==num)
                {
                    values[valuestag++]=dataBuf[i];
                }
                else if ((tag - num) == 1)
                {
                    break;
                }
            }
        }
        if(tag <= num)
        {
            valuestag = 0;
        }
        values[valuestag]='\0';
        //qDebug()<<tag<<__LINE__<<__FILE__;
    }
    catch (...)
    {
    }
    return values;
}
