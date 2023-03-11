#include "cachedatasaver.h"
#include <QDateTime>
#include <QApplication>
#include <QDir>
#include <QDebug>

CacheDataSaver::CacheDataSaver(QObject *parent) : QObject(parent)
{
    m_saveFile = NULL;
    m_saver = NULL;
}

CacheDataSaver::~CacheDataSaver()
{
    stop();
}

void CacheDataSaver::start()
{
    if(m_saveFile == NULL)
    {

        QString path = QApplication::applicationDirPath() + "/data/";
        QDir().mkpath(path);

        //QString fileName = "FILE_" + QString::number(file) + "_"+ QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss") + ".txt";
        QString fileName = "cache"+ QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss")+".txt";
        filePathName = path + fileName;

        m_saveFile = new QFile(filePathName);
        m_saveFile->open(QIODevice::ReadWrite);
        m_saveFile->seek(m_saveFile->size());

        m_saver = new QTextStream(m_saveFile);
    }
}

void CacheDataSaver::stop()
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

QString CacheDataSaver::getFilePathName()
{
    return filePathName;
}

void CacheDataSaver::onDataCollected(QByteArray data)
{
    if(m_saveFile != NULL)
    {
        *m_saver<< data.data() << " " <<QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz")<<'\r'<<'\n';
        (*m_saveFile).flush();
    }
}

