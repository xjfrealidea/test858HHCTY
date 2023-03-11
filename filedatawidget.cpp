#include "filedatawidget.h"
#include "ui_filedatawidget.h"
#include "filedatainfo.h"
FileDataWidget::FileDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileDataWidget)
{

}

FileDataWidget::~FileDataWidget()
{
    delete ui;
}

void FileDataWidget::setUi()
{
    ui->setupUi(this);
}

void FileDataWidget::setStartTime(QString start)
{
    ui->startTimeLabal->setText(start);
}

void FileDataWidget::setEndTime(QString end)
{
    ui->endTimeLabel->setText(end);
}

void FileDataWidget::setStartDate(QString start)
{
    ui->startDateLabel->setText(start);
}

void FileDataWidget::setEndDate(QString end)
{
    ui->endDateLabel->setText(end);
}

void FileDataWidget::setStartX(QString start)
{
    ui->startXLabel->setText(start);
}

void FileDataWidget::setEndX(QString end)
{
    ui->endXLabel->setText(end);
}

void FileDataWidget::setStartY(QString start)
{
    ui->startYLabel->setText(start);
}

void FileDataWidget::setEndY(QString end)
{
    ui->endYLabel->setText(end);
}

void FileDataWidget::setFileSize(QString size)
{
    ui->fileSizeDataLabel->setText(size+QString("B"));
}

void FileDataWidget::setReadings(QString readings)
{
    ui->readingsDataLabel->setText(readings+QString::fromUtf8("个"));
}

QString FileDataWidget::getEndX()
{
    return ui->endXLabel->text();
}

void FileDataWidget::setNextPosotion(long position)
{
    this->position = position;
}

long FileDataWidget::getNextPosition()
{
    return position;
}

void FileDataWidget::setDirection(int direction)
{
    this->direction = direction;
}

int FileDataWidget::getDirection()
{
    return direction;
}

void FileDataWidget::setFileType(int type)
{
    fileType = type;
    if (fileType == SIMPLE)
    {
        ui->xLabel->setText(QString::fromLocal8Bit("LINE"));
        ui->yLabel->setText(QString::fromLocal8Bit("MARK"));
    }
    else if (fileType == MAPPED)
    {
        ui->xLabel->setText(QString::fromLocal8Bit("LON"));
        ui->yLabel->setText(QString::fromLocal8Bit("LAT"));
    }
    else if (fileType == DRAW)
    {
        ui->xLabel->setText(QString::fromLocal8Bit("LINE"));
        ui->yLabel->setText(QString::fromLocal8Bit("MARK"));
    }
    else if (fileType == BASE)
    {

    }
}

int FileDataWidget::getFileType()
{
    return fileType;
}

void FileDataWidget::setSurveyMode(int mode)
{
    surveyMode = mode;
}

int FileDataWidget::getSurveyMode()
{
    return surveyMode;
}
