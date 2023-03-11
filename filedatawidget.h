#ifndef FILEDATAWIDGET_H
#define FILEDATAWIDGET_H

#include <QWidget>
#include <QString>
//#define SIMPLE 0
//#define MAPPED 1
//#define BASE 2

namespace Ui {
class FileDataWidget;
}

class FileDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileDataWidget(QWidget *parent = 0);
    ~FileDataWidget();
    void setUi();

    void setStartTime(QString start);
    void setEndTime(QString end);
    void setStartDate(QString start);
    void setEndDate(QString end);
    void setStartX(QString start);
    void setEndX(QString end);
    void setStartY(QString start);
    void setEndY(QString end);
    void setFileSize(QString size);
    void setReadings(QString readings);

    QString getEndX();

    void setNextPosotion(long position);
    long getNextPosition();
    void setDirection(int direction);
    int getDirection();

    void setFileType(int type);
    int getFileType();
    void setSurveyMode(int mode);
    int getSurveyMode();

private:
    Ui::FileDataWidget *ui;
    int fileType;
    int surveyMode;
    long position;
    int direction;
};

#endif // FILEDATAWIDGET_H
