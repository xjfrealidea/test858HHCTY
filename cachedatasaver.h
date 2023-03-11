#ifndef CACHEDATASAVER_H
#define CACHEDATASAVER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>

class CacheDataSaver : public QObject
{
    Q_OBJECT
public:
    explicit CacheDataSaver(QObject *parent = 0);
    ~CacheDataSaver();

public:
    void start();
    void stop();

    QString getFilePathName();

public slots:
    void onDataCollected(QByteArray data);

private:
    QFile *m_saveFile;
    QTextStream *m_saver;

    QString filePathName;

};

#endif // CACHEDATASAVER_H
