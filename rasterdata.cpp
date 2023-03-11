#include "rasterdata.h"
#include <QFile>
#include <QtNumeric>
#include <QApplication>
#include "settings.h"

RasterData::RasterData()
{
    setResampleMode(QwtMatrixRasterData::BilinearInterpolation);
    gps_flag = false;
    max_gps_lon = 0;
    min_gps_lon = 999;
    max_gps_lat = 0;
    min_gps_lat = 999;
    max_value = 0;
    min_value = 9999999999;

    offset = Settings::instance()["GPS/OFFSET"].toInt();
}

void RasterData::addData(double x,double y,double data)
{
    GPSDATA gpsdata;
    gpsdata.gps_lon = x;
    gpsdata.gps_lat = y;
    gpsdata.mag_data = data;
    if(max_gps_lon < gpsdata.gps_lon)
        max_gps_lon = gpsdata.gps_lon;
    if(min_gps_lon > gpsdata.gps_lon)
        min_gps_lon = gpsdata.gps_lon;

    if(max_gps_lat < gpsdata.gps_lat)
        max_gps_lat = gpsdata.gps_lat;
    if(min_gps_lat > gpsdata.gps_lat)
        min_gps_lat = gpsdata.gps_lat;

    if(max_value < gpsdata.mag_data)
        max_value = gpsdata.mag_data;
    if(min_value > gpsdata.mag_data)
        min_value = gpsdata.mag_data;
    d_data.append(gpsdata);
}
void RasterData::differenceValue()
{
    GPSDATA *data;
    double firstLon,firstLat,endLon,endLat;
    double dx_lon,dy_lat; //��ֵ�ݶ�;
    int firstIndex,endIndex;
    int count;
    data = d_data.data();
    firstLon = data[0].gps_lon;
    firstLat = data[0].gps_lat;
    endLon = data[0].gps_lon;
    endLat = data[0].gps_lat;
    firstIndex = 0;
    endIndex = 0;
    for(int i=1; i< d_data.size();i++)
    {
        endLon = data[i].gps_lon;
        endLat = data[i].gps_lat;

        if((firstLon == endLon)
           &&(firstLat == endLat))
        {
            endIndex = i;
        }
        else
        {
            count = endIndex - firstIndex; // ��ͬ��γ��ֵ�ĸ�����
            if(count > 0) //����1����ֵͬ,���ֵ;
            {
                dx_lon = (endLon - firstLon )/(count+1);
                dy_lat = (endLat - firstLat)/(count+1);
                for(int i=0; i<count; i++)
                {
                    data[firstIndex+1+i].gps_lon = data[firstIndex].gps_lon + (1+i)*dx_lon;
                    data[firstIndex+1+i].gps_lat = data[firstIndex].gps_lat + (1+i)*dy_lat;
                }
            }
            firstLon = data[i].gps_lon;
            firstLat = data[i].gps_lat;
            firstIndex = i;
            endIndex = i;
        }
    }
}
GPSDATA RasterData::selectNearData(GPSDATA data1, GPSDATA data2, double x, double y)
{
    double x1 = ((data1.gps_lon - min_gps_lon)/gridDis_x)*falgToGrid;
    double y1 = ((data1.gps_lat - min_gps_lat)/gridDis_y)*falgToGrid;

    double x2 = ((data2.gps_lon - min_gps_lon)/gridDis_x)*falgToGrid;
    double y2 = ((data2.gps_lat - min_gps_lat)/gridDis_y)*falgToGrid;

    double d1 = (x1-x)*(x1-x)+(y1-y)*(y1-y);
    double d2 = (x2-x)*(x2-x)+(y2-y)*(y2-y);

    return (d1<d2)?(data1):(data2);
}

void RasterData::recheckMaxMinValue(double right, double left, double top, double bottom, int type)
{
//    for (int i = 0;i < 21; i++)
//    {
//        for (int j = 0;j < 21; j++)
//        {
//            qDebug() << i << " " << j << " " << QString::number(this->value(i/4,j/4));
//        }
//    }

    if (0 == type)
    {
        checkGridMaxMinValue(right, left, top, bottom);
    }
    else if (1 == type)
    {
        checkGpsMaxMinValue(right, left, top, bottom);
    }
    return;
}

void RasterData::checkGridMaxMinValue(double max_x, double min_x, double min_y, double max_y)
{
    max_value_changed = -99999;
    min_value_changed = 99999;

    double maxy = 0;
    double maxx = 0;
    double miny = 0;
    double minx = 0;

    for (double i = min_x; i < max_x; i+=0.1)
    {
        for (double j = min_y; j < max_y; j+=0.1)
        {
            double mag = this->value(i,j);
//            qDebug() << i << " " << j << " " << QString::number(mag,'g',10);
            if (mag > max_value_changed)
            {
                max_value_changed = mag;
                maxx = i;
                maxy = j;
            }
            if (mag < min_value_changed)
            {
                min_value_changed = mag;
                minx = i;
                miny = j;
            }
        }
    }

    max_value = max_value_changed;
    min_value = min_value_changed;

    posx = (maxx+minx)/2;
    posy = (maxy+miny)/2;
}

void RasterData::checkGpsMaxMinValue(double max_lon, double min_lon, double min_lat, double max_lat)
{
    max_value_changed = -99999;
    min_value_changed = 99999;

    double maxy = 0;
    double maxx = 0;
    double miny = 0;
    double minx = 0;
    /*
    x_max = gpsValueToInt((max_x - min_gps_lon)/gridDis_x);
    y_min = gpsValueToInt((min_y - min_gps_lat)/gridDis_y);
    x_min = gpsValueToInt((min_x - min_gps_lon)/gridDis_x);
    y_max = gpsValueToInt((max_y - min_gps_lat)/gridDis_y);
*/

    for (double i = min_lon; i < max_lon; i+=(max_lon-min_lon)/200)
    {
        for (double j = min_lat; j < max_lat; j+=(max_lat-min_lat)/200)
        {
            double mag = this->value(i,j);
//            qDebug() << i << " " << j << " " << QString::number(mag,'g',10);
            if (mag > max_value_changed)
            {
                max_value_changed = mag;
                maxx = i;
                maxy = j;
            }
            if (mag < min_value_changed)
            {
                min_value_changed = mag;
                minx = i;
                miny = j;
            }
        }
    }
    qDebug() << "max x " << maxx << " max y " << maxy << " mag " << QString::number(max_value_changed,'g',10);
    qDebug() << "min x " << minx << " min y " << miny << " mag " << QString::number(min_value_changed,'g',10);
    qDebug() << "x " << (maxx+minx)/2;
    qDebug() << "y " << (maxy+miny)/2;


    max_value = max_value_changed;
    min_value = min_value_changed;

    posx = (maxx+minx)/2;
    posy = (maxy+miny)/2;

}

void RasterData::exportGrid()
{

}

int RasterData::gpsValueToInt(double value)
{
    return qRound(value*falgToGrid);
}

bool RasterData::intGridData()
{

    int x = 0;
    int y = 0;
    int count;
    int flag = 0;  //flag == 0 Ϊ����������ݵĲ��䣻
    int  row = 0;  //��Ч����
    int  column = 0; //��Ч����

    //gridcache

    //��γ�Ȳ�ֵ;
    differenceValue();
    //��������ת������  ��XY�ı仯��Χ������1~100��
    double xdis,ydis;
    xdis = max_gps_lon - min_gps_lon;
    ydis = max_gps_lat - min_gps_lat;
    if(xdis > ydis)
    {
        falgToGrid = 1/ydis*100;
    }
    else
    {
        falgToGrid = 1/xdis*100;
    }

    column = MAX_MATRIX;
    row = MAX_MATRIX;
/////////�������////////////////////////////////
    gridDis_x = (max_gps_lon - min_gps_lon)*falgToGrid/column;//����ľ��룻
    gridDis_y = (max_gps_lat - min_gps_lat)*falgToGrid/row;
    //��ʼ����������Ϊ0
    for(int i=0; i < MAX_MATRIX; i++)
    {
        for(int j=0; j < MAX_MATRIX; j++)
        {
            gridcache[i][j].mag_data = 0;
        }
    }
    //����������ݣ�
//    int sumdata2 = 0;
    GPSDATA tmp;

    for(int i=offset; i< d_data.size();i++)
    {
        tmp.gps_lon = d_data.at(i-offset).gps_lon;
        tmp.gps_lat = d_data.at(i-offset).gps_lat;
        tmp.mag_data = d_data.at(i).mag_data;
        x = gpsValueToInt((tmp.gps_lon - min_gps_lon)/gridDis_x);
        y = gpsValueToInt((tmp.gps_lat - min_gps_lat)/gridDis_y);
        if(x>(column-1) || y>(row-1))
               continue;
        if(gridcache[y][x].mag_data != 0)
        {
            //gridcache[y][x] = (gridcache[y][x] +d_data.at(i).mag_data)/2; //ȡ��ֵ
            //sumdata2 = gridcache[y][x].mag_data;

             gridcache[y][x] = selectNearData(gridcache[y][x], tmp, x, y);
            // gridcache[y][x].mag_data = (sumdata2 + gridcache[y][x].mag_data)/2;
        }
        else
        {
             gridcache[y][x] = tmp;
        }

    }

    //printGridData("E:/123pre.txt");
    //������������,����ı����ݲ�����
    double sumData = 0.0;
    do
    {
        flag = 0;
        for(int i=1; i < column-1; i++)
        {
            for(int j=1; j < row-1; j++)
            {
                if(gridcache[i][j].mag_data == 0)
                {
                    sumData = 0.0;
                    count   = 0;
                    //�ܱ�4�����ٶ���1��ֵ�����ֻ��һ��ֵ��Ч������
                    if(gridcache[i-1][j].mag_data != 0) //�ϱ�
                    {
                        sumData += gridcache[i-1][j].mag_data;
                        count++;
                    }
                    if(gridcache[i+1][j].mag_data != 0)  //�±�
                    {
                        sumData += gridcache[i+1][j].mag_data;
                        count++;
                    }
                    if(gridcache[i][j-1].mag_data != 0)  //���
                    {
                        sumData += gridcache[i][j-1].mag_data ;
                        count++;
                    }
                    if(gridcache[i][j+1].mag_data != 0)  //�ұ�
                    {
                        sumData += gridcache[i][j+1].mag_data;
                        count++;
                    }
                    if(count > 0)
                    {
                        gridcache[i][j].mag_data = sumData/count;  //ȡ��Ȩƽ����
                    }
                    flag = 1;
                }
            }
        }
    }while(flag == 1);

    //��������������ݣ�
    for(int i=0; i < row; i++)
    {
        //���������
        if(gridcache[i][0].mag_data == 0)
        {
            gridcache[i][0].mag_data = gridcache[i][1].mag_data;
        }
        //�ұ�������
        if(gridcache[i][row-1].mag_data == 0)
        {
            gridcache[i][row-1].mag_data = gridcache[i][row-2].mag_data;
        }
    }
    for(int i=0; i < column; i++)
    {
        //�ϱ�������
        if(gridcache[0][i].mag_data == 0)
        {
            gridcache[0][i].mag_data = gridcache[1][i].mag_data;
        }
        //�±�������
        if(gridcache[column-1][i].mag_data == 0)
        {
            gridcache[column-1][i].mag_data = gridcache[column-2][i].mag_data;
        }
    }
#if 1
    //ƽ����������
    max_value = LONG_LONG_MIN;
    min_value = LONG_LONG_MAX;
    for(int i=1; i < column-1; i++)
    {
        for(int j=1; j < row-1; j++)
        {
            sumData = 0;
            sumData += gridcache[i-1][j].mag_data *0.3;
            sumData += gridcache[i-1][j-1].mag_data*0.2;
            sumData += gridcache[i-1][j+1].mag_data*0.2;
            sumData += gridcache[i+1][j].mag_data *0.3;
            sumData += gridcache[i+1][j-1].mag_data*0.2;
            sumData += gridcache[i+1][j+1].mag_data*0.2;

            sumData += gridcache[i][j-1].mag_data *0.3;
            sumData += gridcache[i][j+1].mag_data*0.3;
            sumData += gridcache[i][j].mag_data;
            gridcacheP[i][j].mag_data = sumData/3;

            max_value = qMax(max_value,gridcacheP[i][j].mag_data);//��ȡ���ݵ����/��Сֵ
            min_value = qMin(min_value,gridcacheP[i][j].mag_data);
        }
    }
    //��������������ݣ�
    for(int i=0; i < row; i++)
    {
        //���������

        gridcacheP[i][0].mag_data = gridcacheP[i][1].mag_data;
        //�ұ�������
        gridcacheP[i][row-1].mag_data = gridcacheP[i][row-2].mag_data;
    }
    for(int i=0; i < column; i++)
    {
        //�ϱ�������
        gridcacheP[0][i].mag_data = gridcacheP[1][i].mag_data;
        //�±�������
        gridcacheP[column-1][i].mag_data = gridcacheP[column-2][i].mag_data;
    }
#endif
//printGridData("E:/123pre2.txt");
    for (int i = 0;i < column;i++)
    {
        for (int j = 0;j < row;j++)
        {
            v_cache.push_back(gridcacheP[i][j].mag_data);
        }
    }
    setValueMatrix(v_cache,column);
    this->max_value = max_value;
    this->min_value = min_value;
    this->data_row = row;
    this->data_column = column;

    setInterval( Qt::XAxis, QwtInterval( min_gps_lon, max_gps_lon) );
    setInterval( Qt::YAxis, QwtInterval(  min_gps_lat, max_gps_lat ) );
    setInterval( Qt::ZAxis, QwtInterval( (int)min_value-1, (int)max_value+1 ) );

    return true;
}

void RasterData::printGridData(QString filename)
{
    QFile *m_dataFile = new QFile(filename);
    m_dataFile->open(QIODevice::WriteOnly);
    QString aaa;
    char buf[100];

    for(int i=0; i < MAX_MATRIX; i++)
    {
        for(int j=0; j < MAX_MATRIX; j++)
        {
            sprintf(buf,"%0.3f,",gridcache[i][j].mag_data);
            m_dataFile->write(buf);
        }
        m_dataFile->write("\r\n");
    }
    m_dataFile->close();
    delete m_dataFile;
}
bool RasterData::setGridData(QString filename)
{
    gps_flag = false;
//    QString path = "E:/858/grid2.txt";
//    QFile *m_dataFile = new QFile(path);
    QFile *m_dataFile = new QFile(filename);
    m_dataFile->open(QIODevice::ReadOnly);

    double cache[50][50];

    char buffer[100];
    double line,mark,value;
    int max_line = -1;
    int max_mark = -1;
    int min_mark = 99999;
    double max_value = -999999;
    double min_value = 999999;

    int last_line = -1;
    int count = 0;
    int max_count = -1;
    int direction = -1;
    while (1)
    {
        if (m_dataFile->readLine(buffer,100) == -1)
        {
            //qDebug() << "cannotread";
            break;
        }

        sscanf(buffer,"%lf %lf %lf",&line,&mark,&value);
        //qDebug() << buffer;

        if (value > max_value)
        {
            max_value = value;
        }
        if (value < min_value)
        {
            min_value = value;
        }
        if ((int)line > max_line)
        {
            max_line = (int)line;
        }
        if ((int)mark > max_mark)
        {
            max_mark = (int)mark;
        }
        if ((int)mark < min_mark)
        {
            min_mark = (int)mark;
        }
        //cache[(int)line][(int)mark] = value;

        if (last_line != line)
        {
            direction *= -1;
            last_line = line;
        }
        else
        {
            count += direction;
        }
        cache[(int)line][count] = value;
        //qDebug() << "count =" << count;
        if (count > max_count)
        {
            max_count = count;
        }
    }
    //qDebug() << "max_count =" << max_count;
    if (max_line == 0)
    {
        return false;
    }
    if (max_value == min_value )
    {
        return false;
    }

    this->max_value = max_value;
    this->min_value = min_value;

    for (int i = 0;i < max_count+1;i++)
    {
        for (int j = 0;j < max_line+1;j++)
        {
            v_cache.push_back(cache[j][i]);
        }
    }
    setValueMatrix(v_cache,max_line+1);
    this->max_value = max_value;
    this->min_value = min_value;

    setInterval( Qt::XAxis, QwtInterval( 0, max_line) );
    setInterval( Qt::YAxis, QwtInterval( min_mark, max_mark ) );
    setInterval( Qt::ZAxis, QwtInterval( (int)min_value-1, (int)max_value+1 ) );

    m_dataFile->close();
    delete m_dataFile;

    return true;
}

bool RasterData::setGpsData(QString filename)
{
//    QString path = "E:/858/8582020-5-4-lingang/grid_42.txt";
//    QFile *m_dataFile = new QFile(path);
    QFile *m_dataFile = new QFile(filename);

    m_dataFile->open(QIODevice::ReadOnly);

    char buffer[100];
    double x,y,value;

    while (m_dataFile->readLine(buffer,100) != -1)
    {
        sscanf(buffer,"%lf %lf %lf",&x,&y,&value);
        addData(x,y,value);
    }

    bool ret = intGridData();

    m_dataFile->close();
    delete m_dataFile;

    dx = interval( Qt::XAxis ).width() / 75;
    dy = interval( Qt::YAxis ).width() / 75;

    return ret;
}

bool RasterData::setDrawData(QString filename, double LLx, double LLy, double URx, double URy)
{
    gps_flag = false;
    QFile *m_dataFile = new QFile(filename);
    m_dataFile->open(QIODevice::ReadOnly);

    double cache[50][50];

    char buffer[100];
    double line,mark,value;
    int max_line = -1;
    int max_mark = -1;
    int min_mark = 99999;
    double max_value = -999999;
    double min_value = 999999;

    int last_line = -1;
    int count = 0;
    int max_count = -1;
    int direction = -1;
    while (1)
    {
        if (m_dataFile->readLine(buffer,100) == -1)
        {
            //qDebug() << "cannotread";
            break;
        }

        sscanf(buffer,"%lf %lf %lf",&line,&mark,&value);
        //qDebug() << buffer;

        if (value > max_value)
        {
            max_value = value;
        }
        if (value < min_value)
        {
            min_value = value;
        }
        if ((int)line > max_line)
        {
            max_line = (int)line;
        }
        if ((int)mark > max_mark)
        {
            max_mark = (int)mark;
        }
        if ((int)mark < min_mark)
        {
            min_mark = (int)mark;
        }
        //cache[(int)line][(int)mark] = value;

        if (last_line != line)
        {
            direction *= -1;
            last_line = line;
        }
        else
        {
            count += direction;
        }
        cache[(int)line][count] = value;
        //qDebug() << "count =" << count;
        if (count > max_count)
        {
            max_count = count;
        }
    }
    //qDebug() << "max_count =" << max_count;
    if (max_line == 0)
    {
        return false;
    }
    if (max_value == min_value )
    {
        return false;
    }

    this->max_value = max_value;
    this->min_value = min_value;

    for (int i = 0;i < max_count+1;i++)
    {
        for (int j = 0;j < max_line+1;j++)
        {
            v_cache.push_back(cache[j][i]);
        }
    }
    setValueMatrix(v_cache,max_line+1);
    this->max_value = max_value;
    this->min_value = min_value;

    setInterval( Qt::XAxis, QwtInterval( LLx, URx) );
    setInterval( Qt::YAxis, QwtInterval( LLy, URy ) );
    setInterval( Qt::ZAxis, QwtInterval( (int)min_value-1, (int)max_value+1 ) );

    m_dataFile->close();
    delete m_dataFile;

    return true;
}

void RasterData::setFileCache()
{

}

