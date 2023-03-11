#ifndef DATASAVER_H
#define DATASAVER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>
#define SIMPLE 0
#define MAPPED 1
#define DRAW 2
#define BASE 3

struct Cache
{
    int type;
    QString data;
};

class DataSaver : public QObject
{
	Q_OBJECT

public:
    DataSaver(int index, int type, int hzrate = 0,QObject *parent = NULL);
	~DataSaver();

signals:
    void setPerLineNum(int*);

public:
	void start();
	void stop();

    void gridStart();
    void gridStop();
    QString getGridTextPath();

    void continueStart();
    void loadFileData();
    void writeInFileCache();

public slots:
//    void onDataCollected(QByteArray data);
    void onDataCollected(QString);
    void gridDataSave(QString);


private:
    QFile *m_saveFile;
    QTextStream *m_saver;

    QFile *gridFile;
    QTextStream *grid_Saver;

    int index;
    int type;
    int hzrate;

    int perLineNum[100];
    QVector<Cache> filecache;
};

#endif // DATASAVER_H
