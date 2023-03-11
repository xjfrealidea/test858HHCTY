#include "datasaver.h"
#include <QDateTime>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include "filedatacache.h"
#include <cstring>
#include "filedatainfo.h"

#define READINGS 0
#define MARK 1
#define ENDLINE 2

DataSaver::DataSaver(int index, int type, int hzrate, QObject *parent):
    QObject(parent),
    index(index),
    type(type),
    hzrate(hzrate)

{
	m_saveFile = NULL;
	m_saver = NULL;

    gridFile = NULL;
    grid_Saver = NULL;
}

DataSaver::~DataSaver()
{

}

void DataSaver::start()
{
	if(m_saveFile == NULL)
	{

		QString path = QApplication::applicationDirPath() + "/data/";
		QDir().mkpath(path);

        //QString fileName = "FILE_" + QString::number(index) + "_"+ QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss") + ".txt";
        QString fileName = "FILE_" + QString::number(index) + ".stn";
		QString filePathName = path + fileName;


		m_saveFile = new QFile(filePathName);
        m_saveFile->open(QIODevice::WriteOnly);
        m_saver = new QTextStream(m_saveFile);
        *m_saver<< "99 " << type << " " << hzrate <<'\r'<<'\n';
        (*m_saveFile).flush();


    }
}

void DataSaver::continueStart()
{
    if(m_saveFile == NULL)
    {
        QString path = QApplication::applicationDirPath() + "/data/";
        QDir().mkpath(path);

        //QString fileName = "FILE_" + QString::number(index) + "_"+ QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss") + ".txt";
        QString fileName = "FILE_" + QString::number(index) + ".stn";
        QString filePathName = path + fileName;

        m_saveFile = new QFile(filePathName);
        m_saveFile->open(QIODevice::ReadOnly);
        m_saver = new QTextStream(m_saveFile);

        //load file data
        loadFileData();
        writeInFileCache();
        m_saveFile->close();
        delete m_saver;
        m_saveFile->open(QIODevice::WriteOnly);
        m_saver = new QTextStream(m_saveFile);
        *m_saver<< "99 " << type << " " << hzrate <<'\r'<<'\n';
    }
}

void DataSaver::loadFileData()
{
    memset(perLineNum,-1,sizeof(int) * 100);
    int line = -1;
    int mark = 0;
    QString buf;
    buf = m_saver->readLine();
    //qDebug() << buf;
     while (1)
     {
         if   (m_saver->atEnd())
         {
             break;
         }
         buf = m_saver->readLine();
         int type = buf.left(3).toInt();
         //qDebug() << type;
         Cache cache;
         cache.data = buf;
         if (type == 3)
         {
             type = buf.right(3).toInt();
             //qDebug() << type;
             if (type == 1 || type == 5 || type == 7)
             {
                 //qDebug() << "endline" << type;
                 //FileDataCache::instance().getData(ENDLINE,buf);
                 cache.type = ENDLINE;
                 if (line != -1)
                 {
                      perLineNum[line] = mark;
                 }
                 line++;
                 mark = 0;
             }
             else
             {
                 //qDebug() << "mark" << type;
                 //FileDataCache::instance().getData(MARK,buf);
                 cache.type = MARK;
                 mark++;
             }
         }
         else
         {
             //qDebug() << "readings" << type;
             //FileDataCache::instance().getData(READINGS,buf);
             cache.type = READINGS;
         }
         filecache.push_back(cache);
     }
     //qDebug() << buf;
     perLineNum[line] = mark;
     int i = 0;
     for (;i < line;i++)
     {
         if (!(i < line - i))
         {
             break;
         }
         perLineNum[i] = perLineNum[i] + perLineNum[line-i];
         perLineNum[line-i] = perLineNum[i] - perLineNum[line-i];
         perLineNum[i] = perLineNum[i] - perLineNum[line-i];
     }
     emit setPerLineNum(perLineNum);
}

void DataSaver::writeInFileCache()
{
    while (filecache.size() > 0)
    {
        Cache cache = filecache.takeLast();
        FileDataCache::instance().getData(cache.type,cache.data);
        //qDebug() << "cache.type="<<cache.type;
    }
}

void DataSaver::stop()
{
    if(m_saveFile != NULL)
    {
        m_saveFile->close();
        delete m_saveFile;
        m_saveFile = NULL;
        delete m_saver;
        m_saver = NULL;
    }

}

void DataSaver::gridStart()
{
    if(gridFile == NULL)
    {
        QString path = QApplication::applicationDirPath() + "/data/";
        QDir().mkpath(path);

        QString fileName = "grid_" + QString::number(index) + ".txt";
        QString filePathName = path + fileName;
        gridFile = new QFile(filePathName);
        gridFile->open(QIODevice::WriteOnly);
        grid_Saver = new QTextStream(gridFile);
    }
}

void DataSaver::gridStop()
{
    if(gridFile != NULL)
    {
        gridFile->close();
        delete gridFile;
        gridFile = NULL;
        delete grid_Saver;
        grid_Saver = NULL;
    }
}

QString DataSaver::getGridTextPath()
{
    QString path = QApplication::applicationDirPath() + "/data/";
    QDir().mkpath(path);

    QString fileName = "grid_" + QString::number(index) + ".txt";
    QString filePathName = path + fileName;
    return filePathName;
}

void DataSaver::onDataCollected(QString str)
{
    FileDataInfo::instance().setTransferStatus(index,false);

    *m_saver<<str<<'\r'<<'\n';
    (*m_saveFile).flush();
}

void DataSaver::gridDataSave(QString str)
{
    *grid_Saver<<str<<'\r'<<'\n';
    (*gridFile).flush();
    //qDebug() << str;
}
