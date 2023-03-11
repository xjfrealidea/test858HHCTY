#ifndef FILEDATACACHE_H
#define FILEDATACACHE_H

#include <QObject>
#include "common.h"
#include <QMap>
#include <QVector>
#include <QString>
#include "datasaver.h"
#define READINGS 0
#define MARK 1
#define ENDLINE 2

class FileDataCache : public QObject
{
    Q_OBJECT

    SINGLETON(FileDataCache)

public:
    void setDataSaver(DataSaver *datasaver);
    void removeDataSaver();

    void checkLastLine(int type);

    void deleteLine();
    void goBackToLastPosition();

    void fileDataSave(int type);

    void markReset();

    QVector<QString> *getFileCache() {return filecache;}
    int getMarkPosition(int index) {return markPosition[index];}
    int getLinePosition(int index) {return linePosition[index];}
    int getLineStartMark(int index) {return lineStartMark[index];}
    int getLineEndMark(int index) {return lineEndMark[index];}

    void makeSimpleGrid();
    void makeGpsGrid();
    void makeDrawGrid(double spaceX, double spaceY);
    QString getGridTextPath();

    void setRangeOfLon(double max, double min) {max_gps_lon = max; min_gps_lon = min;}
    void setRangeOfLat(double max, double min) {max_gps_lat = max; min_gps_lat = min;}

signals:
    //void saveSignal(QString endline);

public slots:
    void getData(int type, QString dataStr);
    //void dataSave(QString endline);

private:
    DataSaver *datasaver;

    QVector<QString> *filecache;

    int markPosition[200];
    int linePosition[100];
    int lineStartMark[100];
    int lineEndMark[100];
    int markCount;
    int lineCount;
    int pointCount;

    double max_gps_lon;
    double min_gps_lon;
    double max_gps_lat;
    double min_gps_lat;
};

#endif // FILEDATACACHE_H
