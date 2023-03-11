#include "filedatacache.h"
#include <cstdio>
#include <QDebug>
#include <cstring>
#include <QApplication>

FileDataCache::FileDataCache()
{
    /*
    count = -1;

    data = new QMap<int,QVector<QString>*>;
    connect(this,SIGNAL(saveSignal(QString)),
            this,SLOT(dataSave(QString)));
            */
    filecache = new QVector<QString>;

    markCount = 0;
    lineCount = 0;
    pointCount = 0;
    //markPosition = new int[200];
    //linePosition = new int[100];
    //lineStartMark = new int[100];
    //lineEndMark = new int[100];
    markReset();
}

FileDataCache::~FileDataCache()
{
    /*if (data != NULL)
    {
        delete data;
        data = NULL;
    }*/
    /*if (cache != NULL)
    {
        delete cache;
        cache = NULL;
    }*/
    if (filecache != NULL)
    {
        delete filecache;
        filecache = NULL;
    }
 /*   if (markPosition != NULL)
    {
        delete[] markPosition;
        markPosition = NULL;
    }
    if (linePosition != NULL)
    {
        delete[] linePosition;
        linePosition = NULL;
    }
    if (lineStartMark != NULL)
    {
        delete[] lineStartMark;
        lineStartMark = NULL;
    }
    if (lineEndMark != NULL)
    {
        delete[] lineEndMark;
        lineEndMark = NULL;
    }*/
}

void FileDataCache::setDataSaver(DataSaver *datasaver)
{
    this->datasaver = datasaver;
}

void FileDataCache::removeDataSaver()
{
    this->datasaver = NULL;
}

void FileDataCache::checkLastLine(int type)
{
    if (filecache->size() > 0)
    {
        //makeSimpleGrid();
        fileDataSave(type);
        markReset();
    }

}

void FileDataCache::deleteLine()
{
    //qDebug() << "DELETELINE";

    if (linePosition[lineCount] != -1)
    {
        filecache->remove(linePosition[lineCount],pointCount - linePosition[lineCount]);
        pointCount = linePosition[lineCount];

        for (int i = lineStartMark[lineCount]; i <= markCount; i++)
        {
            markPosition[i] = -1;
        }
        markCount = lineStartMark[lineCount];
        linePosition[lineCount] = -1;
        //markPosition[markCount] = -1;
        lineStartMark[lineCount] = -1;
    }
    else
    {
        if (lineCount == 0)
        {
            return;
        }
        filecache->remove(linePosition[lineCount-1],pointCount - linePosition[lineCount-1]);
        pointCount = linePosition[lineCount-1];

        linePosition[lineCount-1] = -1;
        for (int i = lineStartMark[lineCount-1]; i <= markCount; i++)
        {
            markPosition[i] = -1;
        }
        markCount = lineStartMark[lineCount-1];
        lineCount--;
    }
    /*qDebug() << "pointCount = " << pointCount;
    qDebug() << "markCount = " << markCount;
    qDebug() << "markPosition[" << markCount << "] = " << markPosition[markCount];
    qDebug() << "lineCount = " << lineCount;
    qDebug() << "linePosition[" << lineCount << "] = " << linePosition[lineCount];*/

}

void FileDataCache::goBackToLastPosition()
{
    if (markCount > 0)
    {
        filecache->remove(markPosition[markCount-1],pointCount - markPosition[markCount-1]);
        pointCount = markPosition[markCount-1];
        markPosition[markCount-1] = -1;
        markCount--;
        if (lineStartMark[lineCount] == markCount)
        {
            lineStartMark[lineCount] = -1;
            linePosition[lineCount] = -1;
            return;
        }
        if (lineEndMark[lineCount-1] == markCount)
        {
            lineEndMark[lineCount-1] = -1;
            lineCount--;
            return;
        }
    }
    /*qDebug() << "pointCount = " << pointCount;
    qDebug() << "markCount = " << markCount;
    qDebug() << "markPosition[" << markCount << "] = " << markPosition[markCount];
    qDebug() << "lineCount = " << lineCount;
    qDebug() << "linePosition[" << lineCount << "] = " << linePosition[lineCount];*/
}

void FileDataCache::fileDataSave(int type)
{
    int num = filecache->size();
    int count = markCount-1;
    //int readingcount = 0;
 /*   for (int i = 0;i <= count;i++)
    {
        qDebug() << "markPosition["<<i<<"]=" << markPosition[i];
    }*/
    int i = 0;
    for (i = 0;i < num;i++)
    {
        //QString dataStr = filecache->takeLast();
        QString dataStr = filecache->value(num-i-1);
        /*
        if (dataStr[0] == '3' && dataStr[1] == ' ')
        {
            char *str;
            QByteArray ba = dataStr.toLatin1();
            str = ba.data();
            sprintf(str+50,"%10ld%s",(long)readingcount,str+60);
            datasaver->onDataCollected(QString::fromLocal8Bit(str));
            readingcount = 0;
        }
        else
        {
            datasaver->onDataCollected(dataStr);
            readingcount++;
        }
        */

        if (num-i-1 == markPosition[count])//MARK ENDLINE点
        {
            char *str;
            QByteArray ba = dataStr.toLatin1();
            str = ba.data();

            if (type == 2)//离散
            {
                int j = 0;
                double reading1_sum = 0.0;
                double reading2_sum = 0.0;
                int num_count = 0;
                for (j = num-i-1-5;j < num-i-1+5;j++)
                {
                    if ((markPosition[count+1] == -1 || j < markPosition[count+1])
                            && (count == 0 || j > markPosition[count-1]))
                    {
                        if (j < num && j > 0)
                        {
                            if (j != num-i-1)
                            {
                                num_count++;
                                QString readingStr = filecache->value(j);
                                char *reading_str;
                                QByteArray ba = readingStr.toLatin1();
                                reading_str = ba.data();
                                int a;
                                double b,c;
                                sscanf(reading_str,"%d %lf %lf",&a,&b,&c);
                                reading1_sum += b;
                                reading2_sum += c;
                            }
                        }
                    }
                }
                if (num_count > 0)
                {
                    reading1_sum /= num_count;
                    reading2_sum /= num_count;
                }
                QString timeStr = dataStr.mid(29,20);
                char *timestr;
                QByteArray timeba = timeStr.toLatin1();
                timestr = timeba.data();
                char x_str[100];
                sprintf(x_str,"%-2u %10.3lf %10.3lf %s %3u",(unsigned)0,reading1_sum,reading2_sum,timestr,0);
                datasaver->onDataCollected(QString::fromLocal8Bit(x_str));
            }

            long reading_count = 0;
            if (type == 2)
            {
                reading_count = 1;
            }
            else
            {
                reading_count = (long)(markPosition[count+1]-markPosition[count]-1);
            }
            if (count != markCount-1)
            {
                sprintf(str+50,"%10ld%s",reading_count,str+60);
                //qDebug() << "markPosition[" << count+1<<"]-markPosition["<<count<<"]-1="<<(markPosition[count+1]-markPosition[count]-1);
            }
            datasaver->onDataCollected(QString::fromLocal8Bit(str));
            count--;
        }
        else
        {
            if (type != 2)
            {
                datasaver->onDataCollected(dataStr);
            }
        }

    }
    datasaver->stop();
    filecache->clear();
}

void FileDataCache::markReset()
{
    markCount = 0;
    lineCount = 0;
    pointCount = 0;
    memset(markPosition,-1,sizeof(int)*200);
    memset(linePosition,-1,sizeof(int)*100);
    memset(lineStartMark,-1,sizeof(int)*100);
    memset(lineEndMark,-1,sizeof(int)*100);
}

void FileDataCache::getData(int type, QString dataStr)
{
#if 1
    if (type == MARK)
    {
        //qDebug() << "MARK";
        if (linePosition[lineCount] == -1)
        {
            linePosition[lineCount] = pointCount;
            lineStartMark[lineCount] = markCount;
        }
        markPosition[markCount] = pointCount;
        markCount++;
    }
    /*else if (type == READINGS)
    {

    }*/
    else if (type == ENDLINE)
    {
        //qDebug() << "ENDLINE";
        markPosition[markCount] = pointCount;
        lineEndMark[lineCount] = markCount;
        markCount++;
        lineCount++;
    }
    filecache->push_back(dataStr);
    //datasaver->cacheDataSave(dataStr);
    pointCount++;

#endif
}

void FileDataCache::makeSimpleGrid()
{
    datasaver->gridStop();
    datasaver->gridStart();
#if 1
    double max_mark = 0.0;
    double min_mark = 99.0;
    for (int i = 0;i < markCount;i++)
    {
        int position = markPosition[i];
        QString dataStr = filecache->value(position,QString::fromLocal8Bit("-1"));
        QString midStr = dataStr.mid(3,25);
        double x,y;
        sscanf((midStr.toLatin1()).data(),"%lf %lf",&x,&y);
        if (y > max_mark)
        {
            max_mark = y;
        }
        if (y < min_mark)
        {
            min_mark = y;
        }
    }

    int direction = -1;
    for (int i = 0;i < markCount;i++)
    {
        int position = markPosition[i];
        QString dataStr = filecache->value(position,QString::fromLocal8Bit("-1"));
        QString midStr = dataStr.mid(3,25);
        double x,y;
        sscanf((midStr.toLatin1()).data(),"%lf %lf",&x,&y);

        double mag = 0;
        char buff[100] = "";
        if (i == 0 || (markPosition[i]-markPosition[i-1] == 1))// markstart
        {
            direction *= -1;
            dataStr = filecache->value(position+1,QString::fromLocal8Bit("-1"));
            midStr = dataStr.mid(3,10);
            sscanf((midStr.toLatin1()).data(),"%lf",&mag);
            sprintf(buff,"%lf %lf %lf",x,y,mag);
            if (direction == 1)
            {
                if (y > min_mark)
                {
                    for (int j = (int)min_mark;j < (int)y;j++)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }
            }
            else
            {
                if (y < max_mark)
                {
                    for (int j = (int)max_mark;j > (int)y;j--)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }

            }
            datasaver->gridDataSave(QString::fromLocal8Bit(buff));
        }
        else if (i == (markCount-1) || (markPosition[i+1]-markPosition[i] == 1))// endline
        {
            dataStr = filecache->value(position-1,QString::fromLocal8Bit("-1"));
            midStr = dataStr.mid(3,10);
            sscanf((midStr.toLatin1()).data(),"%lf",&mag);
            sprintf(buff,"%lf %lf %lf",x,y,mag);
            datasaver->gridDataSave(QString::fromLocal8Bit(buff));

            if (direction == 1)
            {
                if (y < max_mark)
                {
                    for (int j = (int)y+1;j < (int)max_mark+1;j++)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }
            }
            else
            {
                if (y > min_mark)
                {
                    for (int j = (int)y-1;j > (int)min_mark-1;j--)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }
            }
        }
        else
        {
            dataStr = filecache->value(position+1,QString::fromLocal8Bit("-1"));
            midStr = dataStr.mid(3);
            double src_mag[3] = {};
            int plotIndex = 0;
            sscanf((midStr.toLatin1()).data(),"%lf %lf %d",&(src_mag[0]),&(src_mag[1]),&plotIndex);
            src_mag[2] = src_mag[0] - src_mag[1];
            sprintf(buff,"%lf %lf %lf",x,y,src_mag[plotIndex]);
            datasaver->gridDataSave(QString::fromLocal8Bit(buff));
        }
    }
#endif

#if 0
    QString path = QApplication::applicationDirPath() + "/data/simple_test2.txt";
    QFile *m_dataFile = new QFile(path);

    bool ret = m_dataFile->open(QIODevice::ReadOnly);

    double mag1 = 0.0;
    double mag2 = 0.0;
    int line = 0;
    int mark = 0;
    int max_mark = 0;
    int min_mark = 99;

    QVector<double> mag1_cache;
    QVector<double> mag2_cache;
    QVector<int> line_cache;
    QVector<int> mark_cache;
    mag1_cache.clear();
    mag2_cache.clear();
    line_cache.clear();
    mark_cache.clear();

    char buff[100] = "";
    while (m_dataFile->readLine(buff,100) != -1)
    {
        sscanf(buff,"*dat,0,%lf,%lf,%d,%d,#",&mag1,&mag2,&line,&mark);
        mag1_cache.push_back(mag1);
        mag2_cache.push_back(mag2);
        line_cache.push_back(line);
        mark_cache.push_back(mark);
    }
//    line = 0;
    mark = 0;
//    int lastmark = 99;
    int dir = 1;
    int len = strlen(buff);
    memset(buff,0,100 * sizeof(char));
    for (int i = 1;i < mag1_cache.size(); i++)
    {
        if (mark_cache.at(i) != mark_cache.at(i-1))//mark变化
        {
            if (mark_cache.at(i-1) == 99)//一列开始
            {
                sprintf(buff,"%lf %lf %lf",(double)line_cache.at(i),(double)mark,mag2_cache.at(i));
                datasaver->gridDataSave(QString::fromLocal8Bit(buff));
                memset(buff,0,100 * sizeof(char));
            }
            else if (mark_cache.at(i) != 99)//中间点
            {
                mark += dir;
                sprintf(buff,"%lf %lf %lf",(double)line_cache.at(i),(double)mark,mag2_cache.at(i));
                datasaver->gridDataSave(QString::fromLocal8Bit(buff));
                memset(buff,0,100 * sizeof(char));
            }
            else//一列结束
            {
                mark += dir;
                sprintf(buff,"%lf %lf %lf",(double)line_cache.at(i-1),(double)mark,mag2_cache.at(i));
                datasaver->gridDataSave(QString::fromLocal8Bit(buff));
                memset(buff,0,100 * sizeof(char));
                dir *= -1;
            }
        }
    }



#endif
    datasaver->gridStop();


}

void FileDataCache::makeGpsGrid()
{
    datasaver->gridStop();
    datasaver->gridStart();

    for (int i = 0;i < pointCount;i++)
    {

        QString dataStr = filecache->value(i,QString::fromLocal8Bit("-1"));
        if (dataStr.left(1) != QString("0"))
        {
            continue;
        }
        QString midStr = dataStr.mid(3);
        double gps_lon,gps_lat;
      //  char timestr[50] = "";
        double src_mag[3] = {};
        int plotIndex = 0;
        sscanf((midStr.toLatin1()).data(),"%lf %lf %lf %lf %d",&(src_mag[0]),&(src_mag[1]),&gps_lon,&gps_lat,&plotIndex);

        src_mag[2] = src_mag[0] - src_mag[1];

        char buff[100] = "";

        sprintf(buff,"%15.11lf %15.11lf %lf",gps_lon,gps_lat,src_mag[plotIndex]);
        datasaver->gridDataSave(QString::fromLocal8Bit(buff));
    }

    datasaver->gridStop();
}

void FileDataCache::makeDrawGrid(double spaceX, double spaceY)
{
    datasaver->gridStop();
    datasaver->gridStart();
#if 1
    double max_mark = 0.0;
    double min_mark = 99.0;
    for (int i = 0;i < markCount;i++)
    {
        int position = markPosition[i];
        QString dataStr = filecache->value(position,QString::fromLocal8Bit("-1"));
        QString midStr = dataStr.mid(3,25);
        double x,y;
        sscanf((midStr.toLatin1()).data(),"%lf %lf",&x,&y);
        y = y / spaceY;
        if (y > max_mark)
        {
            max_mark = y;
        }
        if (y < min_mark)
        {
            min_mark = y;
        }
    }

    int direction = -1;
    for (int i = 0;i < markCount;i++)
    {
        int position = markPosition[i];
        QString dataStr = filecache->value(position,QString::fromLocal8Bit("-1"));
        QString midStr = dataStr.mid(3,25);
        double x,y;
        sscanf((midStr.toLatin1()).data(),"%lf %lf",&x,&y);
        y = y / spaceY;
        x = x / spaceX;
        double mag = 0;
        char buff[100] = "";
        if (i == 0 || (markPosition[i]-markPosition[i-1] == 1))// markstart
        {
            direction *= -1;
            dataStr = filecache->value(position+1,QString::fromLocal8Bit("-1"));
            midStr = dataStr.mid(3,10);
            sscanf((midStr.toLatin1()).data(),"%lf",&mag);
            sprintf(buff,"%lf %lf %lf",x,y,mag);
            if (direction == 1)
            {
                if (y > min_mark)
                {
                    for (int j = (int)min_mark;j < (int)y;j++)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }
            }
            else
            {
                if (y < max_mark)
                {
                    for (int j = (int)max_mark;j > (int)y;j--)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }

            }
            datasaver->gridDataSave(QString::fromLocal8Bit(buff));
        }
        else if (i == (markCount-1) || (markPosition[i+1]-markPosition[i] == 1))// endline
        {
            dataStr = filecache->value(position-1,QString::fromLocal8Bit("-1"));
            midStr = dataStr.mid(3,10);
            sscanf((midStr.toLatin1()).data(),"%lf",&mag);
            sprintf(buff,"%lf %lf %lf",x,y,mag);
            datasaver->gridDataSave(QString::fromLocal8Bit(buff));

            if (direction == 1)
            {
                if (y < max_mark)
                {
                    for (int j = (int)y+1;j < (int)max_mark+1;j++)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }
            }
            else
            {
                if (y > min_mark)
                {
                    for (int j = (int)y-1;j > (int)min_mark-1;j--)
                    {
                        char x_buff[100] = "";
                        sprintf(x_buff,"%lf %lf %lf",x,(double)j,mag);
                        datasaver->gridDataSave(QString::fromLocal8Bit(x_buff));
                    }
                }
            }
        }
        else
        {
            dataStr = filecache->value(position+1,QString::fromLocal8Bit("-1"));
            midStr = dataStr.mid(3);
            double src_mag[3] = {};
            int plotIndex = 0;
            sscanf((midStr.toLatin1()).data(),"%lf %lf %d",&(src_mag[0]),&(src_mag[1]),&plotIndex);
            src_mag[2] = src_mag[0] - src_mag[1];
            sprintf(buff,"%lf %lf %lf",x,y,src_mag[plotIndex]);
            datasaver->gridDataSave(QString::fromLocal8Bit(buff));
        }
    }
#endif

    datasaver->gridStop();
}

QString FileDataCache::getGridTextPath()
{
    if (datasaver != NULL)
    {
          return datasaver->getGridTextPath();
         // QString path = QApplication::applicationDirPath() + "/data/grid_test.txt";
          //return path;
    }
    return QString::fromLocal8Bit("\0");
}
