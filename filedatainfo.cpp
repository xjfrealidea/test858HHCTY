#include "filedatainfo.h"
#include <cstring>
#include <QStringList>
#include <QFileInfo>
#include <QFileInfoList>

#define PARM_SIZE_CAL (1.0*1024*1024*25000)
FileDataInfo::FileDataInfo()
{
    data = new QMap<int,FileData*>;
    transferStatus = new QMap<int,bool>;

    memoryUsed = 0.0;
}

FileDataInfo::~FileDataInfo()
{
    if (data != NULL)
    {
        delete data;
        data = NULL;
    }
    if (transferStatus != NULL)
    {
        delete transferStatus;
        transferStatus = NULL;
    }
}


void FileDataInfo::memorySizeCheck()
{
    QString path = QApplication::applicationDirPath() + "/data/";
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.stn" << "*.txt";
    QFileInfoList infoList = dir.entryInfoList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);

    qint64 fileTotalSize = 0;
    for (int i = 0; i < infoList.size(); i++)
    {
        fileTotalSize += infoList.at(i).size();
    }
    memoryUsed = fileTotalSize / PARM_SIZE_CAL;
    if (1 < memoryUsed)
    {
        memoryUsed = 0.99999;
    }
}

void FileDataInfo::fileDataCheck()
{
    int index = 1;
    for (;index <= MAXNUM; index++)
    {
        fileDataCheck(index);
        transferStatus->insert(index,false);
    }
}

void FileDataInfo::fileDataCheck(int index)
{
    QString path = QApplication::applicationDirPath() + "/data/";
    QDir().mkpath(path);
    QString fileName = "FILE_" + QString::number(index) + ".stn";
    QString filePathName = path + fileName;

    QFile *m_File;
    m_File = new QFile(filePathName);
    if (!m_File->exists())
    {
        if (data->find(index) != data->end())
        {
            delete data->take(index);
        }
        return;
    }
    //qDebug() << "filename =" << fileName;
    FileData *filedata = new FileData;
    filedata->filesize = m_File->size();
    filedata->surveyMode = 0;
    m_File->open(QIODevice::ReadOnly);
    char buf[1024];
    m_File->readLine(buf, sizeof(buf));
    int a,b,c;
    int ret = sscanf(buf,"%d%d%d",&a,&b,&c);
    if (3 != ret)
    {
        m_File->close();
        delete m_File;
        m_File = NULL;
        QFile::remove(filePathName);
        return;
    }
    filedata->fileType = b;
    if (b != BASE)//SIMPLE MAPPED
    {
        m_File->readLine(buf, sizeof(buf));
        sscanf(buf,"%d",&a);
        if (a == 3)//SIMPLE(CONTINUOUS) MAPPED
        {
            filedata->surveyMode = 1;
            if (filedata->fileType == SIMPLE)//SIMPLE(CONTINUOUS)
            {
                continuousDataCheck(m_File,filedata,buf);
            }
            else if (filedata->fileType == MAPPED)//MAPPED
            {
                gpsDataCheck(m_File,filedata,buf);
            }
        }
        else //SIMPLE(DISCRETE)
        {
            filedata->surveyMode = 2;
            discreteDataCheck(m_File,filedata,buf);
        }
    }
    else //BASE
    {

    }
    if (data->find(index) != data->end())
    {
        delete data->take(index);
    }
    data->insert(index,filedata);

    m_File->close();
    delete m_File;
    m_File = NULL;
}

void FileDataInfo::continuousDataCheck(QFile *file, FileData *filedata, char *lastbuf)
{
    filedata->surveyMode = 1;//CONTINUOUS
//    if (filedata->fileType == SIMPLE)
//    {
        //3+13+13+12+9+11,
        long x,y;
        sscanf(lastbuf+61,"%ld %ld",&x,&y);
        filedata->endX = QString::number(x);
        filedata->endY = QString::number(y);
        //qDebug() << "endLine = " << filedata->endX;
        //qDebug() << "endMark = " << filedata->endY;
//    }
//    else if (filedata->fileType == MAPPED)
//    {
//        double x,y;
//        sscanf(lastbuf+3,"%lf %lf",&x,&y);
//        filedata->endX = QString("%1").arg(x,0,'f',2);
//        filedata->endY = QString("%1").arg(y,0,'f',2);
//        //qDebug() << "endX = " << filedata->endX;
//        //qDebug() << "endY = " << filedata->endY;
//    }
    QString tmp = (QString::fromLocal8Bit(lastbuf)).mid(29);
    filedata->endTime = tmp.left(8);
    filedata->endDate = tmp.mid(12,8);
    //qDebug() << "endTime = " << filedata->endTime;
    //qDebug() << "endDate = " << filedata->endDate;

    char buf[1024];
    char x_buf[1024];
    filedata->readingsNum = 0;
    int direction = 1;
    int position = 0;
    while (1)
    {
        int ret = file->readLine(buf, sizeof(buf));
        if (ret == -1)
        {
            break;
        }
        /*if (!file->canReadLine())
        {
            break;
        }
        memset(buf,0,1024);
        file->readLine(buf, sizeof(buf));*/
        //qDebug() << "strlen ="<<strlen(buf);
        int type = 0;
        sscanf(buf,"%d",&type);
        int point = 0;
        sscanf(buf+85,"%d",&point);
        if (type == 0)
        {
            filedata->readingsNum++;
        }
        else if (point == 1 || point == 5 || point == 7)
        {
            direction *= -1;
        }
        else
        {
            position += direction;
        }
        memcpy(x_buf,buf,1024);
        memset(buf,0,1024);
    }
    filedata->direction = -direction;
    if (direction  == -1)
    {
        position *= -1;
    }
    filedata->markPosition = position;
    memcpy(buf,x_buf,1024);
    //qDebug() << "count = " << filedata->readingsNum;
    //qDebug() << buf;
//    if (filedata->fileType == SIMPLE)
//    {
        //3+13+13+12+9+11,
//        long x,y;
        sscanf(buf+61,"%ld %ld",&x,&y);
        filedata->startX = QString::number(x);
        filedata->startY = QString::number(y);
        //qDebug() << "startLine = " << filedata->startX;
        //qDebug() << "startMark = " << filedata->startY;
//    }
//    else if (filedata->fileType == MAPPED)
//    {
//        double x,y;
//        sscanf(buf+3,"%lf %lf",&x,&y);
//        filedata->startX = QString("%1").arg(x,0,'f',2);
//        filedata->startY = QString("%1").arg(y,0,'f',2);
//        //qDebug() << "startX = " << filedata->startX;
//        //qDebug() << "startY = " << filedata->startY;
//    }
    tmp = (QString::fromLocal8Bit(buf)).mid(29);
    filedata->startTime = tmp.left(8);
    filedata->startDate = tmp.mid(12,8);
    //qDebug() << "startTime = " << filedata->startTime;
    //qDebug() << "startDate = " << filedata->startDate;
}

void FileDataInfo::gpsDataCheck(QFile *file, FileData *filedata, char *lastbuf)
{
    filedata->surveyMode = 1;//CONTINUOUS

    QString tmp = (QString::fromLocal8Bit(lastbuf)).mid(29);
    filedata->endTime = tmp.left(8);
    filedata->endDate = tmp.mid(12,8);

    char buf[1024];
    char x_buf[1024];
    filedata->readingsNum = 0;
    int direction = 1;
    int position = 0;
    double maxLon = -361.0;
    double minLon = 361.0;
    double maxLat = -361.0;
    double minLat = 361.0;
    while (1)
    {
        int ret = file->readLine(buf, sizeof(buf));
        if (ret == -1)
        {
            break;
        }

        int type = 0;
        sscanf(buf,"%d",&type);
        int point = 0;
        sscanf(buf+85,"%d",&point);
        if (type == 0)
        {
            filedata->readingsNum++;
            double a,b,lon,lat;
            sscanf(buf+1,"%lf %lf %lf %lf",&a,&b,&lon,&lat);
            if (lon > maxLon)
            {
                maxLon = lon;
            }
            if (lon < minLon)
            {
                minLon = lon;
            }
            if (lat > maxLat)
            {
                maxLat = lat;
            }
            if (lat < minLat)
            {
                minLat = lat;
            }
        }
        else if (point == 1 || point == 5 || point == 7)
        {
            direction *= -1;
        }
        else
        {
            position += direction;
        }
        memcpy(x_buf,buf,1024);
        memset(buf,0,1024);
    }
    filedata->direction = -direction;
    if (direction  == -1)
    {
        position *= -1;
    }
    filedata->markPosition = position;
    memcpy(buf,x_buf,1024);


    filedata->endX = QString::number(maxLon,'f',8);
    filedata->endY = QString::number(maxLat,'f',8);

    filedata->startX = QString::number(minLon,'f',8);
    filedata->startY = QString::number(minLat,'f',8);

    tmp = (QString::fromLocal8Bit(buf)).mid(29);
    filedata->startTime = tmp.left(8);
    filedata->startDate = tmp.mid(12,8);
}

void FileDataInfo::discreteDataCheck(QFile *file, FileData *filedata, char *lastbuf)
{
    Q_UNUSED(lastbuf);
    filedata->surveyMode = 2;//DISCRETE
    char buf[1024];
    if (filedata->fileType == SIMPLE)
    {
        //3+13+13+12+9+11,
        file->readLine(buf, sizeof(buf));
        long x,y;
        sscanf(buf+61,"%ld %ld",&x,&y);
        filedata->endX = QString::number(x);
        filedata->endY = QString::number(y);
        //qDebug() << "endX = " << filedata->endX;
        //qDebug() << "endY = " << filedata->endY;
    }
    QString tmp = (QString::fromLocal8Bit(buf)).mid(29);
    filedata->endTime = tmp.left(8);
    filedata->endDate = tmp.mid(12,8);
    //qDebug() << "endTime = " << filedata->endTime;
    //qDebug() << "endDate = " << filedata->endDate;

    filedata->readingsNum = 1;
    int direction = 1;
    int position = 0;
    while (1)
    {
        if (!file->canReadLine())
        {
            break;
        }
        file->readLine(buf, sizeof(buf));
        //qDebug() << buf;
        int type = 0;
        sscanf(buf,"%d",&type);
        int point = 0;
        sscanf(buf+85,"%d",&point);
        if (type == 0)
        {
            filedata->readingsNum++;
        }
        else if (point == 1 || point == 5 || point == 7)
        {
            direction *= -1;
        }
        else
        {
            position += direction;
        }
    }
    filedata->direction = -direction;
    if (direction  == -1)
    {
        position *= -1;
    }
    filedata->markPosition = position;
    //qDebug() << "count = " << filedata->readingsNum;
    //qDebug() << buf;

    if (filedata->fileType == SIMPLE)
    {
        //3+13+13+12+9+11,
        long x,y;
        sscanf(buf+61,"%ld %ld",&x,&y);
        filedata->startX = QString::number(x);
        filedata->startY = QString::number(y);
        //qDebug() << "startX = " << filedata->startX;
        //qDebug() << "startY = " << filedata->startY;
    }
    tmp = (QString::fromLocal8Bit(buf)).mid(29);
    filedata->startTime = tmp.left(8);
    filedata->startDate = tmp.mid(12,8);
    //qDebug() << "startTime = " << filedata->startTime;
    //qDebug() << "startDate = " << filedata->startDate;
}

int FileDataInfo::setFileDataWidget(int index, FileDataWidget *w)
{
    if (data->find(index) == data->end())
    {
        w->setNextPosotion(0);
        w->setDirection(0);
        return -1;
    }
    w->setEndDate(data->value(index)->endDate);
    w->setEndTime(data->value(index)->endTime);
    w->setEndX(data->value(index)->endX);
    w->setEndY(data->value(index)->endY);
    w->setStartDate(data->value(index)->startDate);
    w->setStartTime(data->value(index)->startTime);
    w->setStartX(data->value(index)->startX);
    w->setStartY(data->value(index)->startY);

    w->setFileType(data->value(index)->fileType);
    w->setSurveyMode(data->value(index)->surveyMode);

    w->setReadings(QString::number(data->value(index)->readingsNum));
    //w->setReadings("9999999");
    w->setFileSize(QString::number(data->value(index)->filesize));
    //w->setFileSize("9999999");
    w->setNextPosotion(data->value(index)->markPosition);
    w->setDirection(data->value(index)->direction);

    return data->value(index)->fileType;
}

void FileDataInfo::setTransferStatus(int index, bool flag)
{
    transferStatus->insert(index,flag);
}

bool FileDataInfo::getTransferStatus(int index)
{
    return (transferStatus->value(index));
}
