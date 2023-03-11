#include "endlinemessage.h"
#include "ui_endlinemessage.h"
#include "macro.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QMouseEvent>

EndLineMessage::EndLineMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndLineMessage)
{
    ui->setupUi(this);
    spectrogramplot = NULL;

    mainLayout = new QHBoxLayout();

    QVBoxLayout *messageLayout = new QVBoxLayout();

    QHBoxLayout *lineData = new QHBoxLayout();
    lineData->addWidget(ui->lineLabel,1,Qt::AlignRight);
    lineData->addWidget(ui->lineDataLabel,1,Qt::AlignLeft);

    QHBoxLayout *markData = new QHBoxLayout();
    markData->addWidget(ui->markLabel,1,Qt::AlignRight);
    markData->addWidget(ui->markDataLabel,1,Qt::AlignLeft);

    messageLayout->addWidget(ui->message1,1,Qt::AlignHCenter);
    messageLayout->addWidget(ui->message2,1,Qt::AlignHCenter);
    messageLayout->addLayout(lineData,1);
    messageLayout->addLayout(markData,1);
    messageLayout->addWidget(ui->message3,1,Qt::AlignHCenter);
    messageLayout->addWidget(ui->message4,1,Qt::AlignHCenter);
    messageLayout->addWidget(ui->message5,1,Qt::AlignHCenter);
    messageLayout->addWidget(ui->message6,1,Qt::AlignHCenter);
    messageLayout->addWidget(ui->message7,1,Qt::AlignHCenter);
    messageLayout->addWidget(ui->message8,1,Qt::AlignHCenter);

    mainLayout->addLayout(messageLayout);

    setLayout(mainLayout);

    cursorPosFlag = true;
}

EndLineMessage::~EndLineMessage()
{
    delete ui;
}

void EndLineMessage::setLineAndMark(long line, long mark)
{
    ui->lineDataLabel->setText(QString::number(line));
    ui->markDataLabel->setText(QString::number(mark));
}

void EndLineMessage::menuStart(QString gridFilePath, short type)
{
    if (spectrogramplot == NULL)
    {
        spectrogramplot = new SpectrogramPlot(gridFilePath,type);
        if (spectrogramplot->setflag)
        {
            setTextDown(0);
            mainLayout->addWidget(spectrogramplot);
        }
        else
        {
            setTextDown(1);
            delete spectrogramplot;
            spectrogramplot = NULL;
        }
    }
}

void EndLineMessage::setGpsPos(double lon, double lat)
{
    if (spectrogramplot == NULL)
    {
        return;
    }
    double mapLonMin = spectrogramplot->axisInterval(QwtPlot::xBottom).minValue();
    double mapLatMin = spectrogramplot->axisInterval(QwtPlot::yLeft).minValue();
    double mapLonMax = spectrogramplot->axisInterval(QwtPlot::xBottom).maxValue();
    double mapLatMax = spectrogramplot->axisInterval(QwtPlot::yLeft).maxValue();
    double lonRange = mapLonMax - mapLonMin;
    double latRange = mapLatMax - mapLatMin;
/*
//    qDebug() << "ymax " << spectrogramplot->axisInterval(QwtPlot::yLeft).maxValue();
//    qDebug() << "ymin " << spectrogramplot->axisInterval(QwtPlot::yLeft).minValue();
   // lat = 31.5639;
*/
    double xOffset = ((lon-mapLonMin) / lonRange) * spectrogramplot->canvas()->width();
    double yOffset = ((mapLatMax-lat) / latRange) * spectrogramplot->canvas()->height();

    if (xOffset < 1)
    {
        xOffset = 1;
    }
    else if (xOffset > spectrogramplot->canvas()->width()-1 )
    {
        xOffset = spectrogramplot->canvas()->width()-1;
    }

    if (yOffset < 1)
    {
        yOffset = 1;
    }
    else if (yOffset > spectrogramplot->canvas()->height()-1 )
    {
        yOffset = spectrogramplot->canvas()->height()-1;
    }

    ui->lineDataLabel->setText(QString::number(lon,'f',8));
    ui->markDataLabel->setText(QString::number(lat,'f',8));

    if (cursorPosFlag != true)
    {
        return;
    }
    QCursor::setPos(this->frameGeometry().left() + spectrogramplot->frameGeometry().left()+spectrogramplot->canvas()->geometry().left() + xOffset,
                    this->frameGeometry().top() + spectrogramplot->frameGeometry().top()+spectrogramplot->canvas()->geometry().top() + yOffset);
/*
//    qDebug()<< "left " << spectrogramplot->get_d_spectrogram()->boundingRect().left();
//    qDebug()<< "right " << spectrogramplot->get_d_spectrogram()->boundingRect().right();
//    qDebug()<< "bottom " << spectrogramplot->get_d_spectrogram()->boundingRect().bottom();
//    qDebug()<< "top " << spectrogramplot->get_d_spectrogram()->boundingRect().top();
//    qDebug()<< "mapLatMin " << QString::number(mapLatMin,'f',6);
//    qDebug()<< "mapLatMax " << QString::number(mapLatMax,'f',6);
//    qDebug() << "right - left " << spectrogramplot->canvas()->geometry().right() - spectrogramplot->canvas()->geometry().left();
//    qDebug() << "width " << spectrogramplot->canvas()->width();
*/

}

void EndLineMessage::setTextUp(int typeUp)
{
    if (typeUp == 0)
    {
        ui->message1->setText(QString::fromUtf8("已到达当前调查行的末尾。"));
        ui->message2->setText(QString::fromUtf8("当前调查位置:"));
        ui->lineLabel->setText(QString::fromUtf8("LINE:"));
        ui->markLabel->setText(QString::fromUtf8("MARK:"));
        ui->message3->setText(QString::fromUtf8("按ESC键清除本消息。"));
        ui->message4->setText(QString::fromUtf8("之后按MARK键开始下一行采集。"));
    }
    else if (typeUp == 1)
    {
        ui->message1->setText(QString::fromUtf8("当前调查已结束。"));
        ui->message2->setText(QString::fromUtf8("当前探头位置:"));
        ui->lineLabel->setText(QString::fromUtf8("经  度:"));
        ui->markLabel->setText(QString::fromUtf8("纬  度:"));
        ui->message3->setText(QString::fromUtf8("按ESC键清除本消息。"));
        ui->message4->setText(QString::fromUtf8("之后按MARK键继续采集数据。"));
    }
}

void EndLineMessage::setTextDown(int typeDown)
{
    ui->message5->setText(QString::fromUtf8("—————————————————"));
    if (typeDown == 0)
    {
        ui->message6->setText(QString::fromUtf8(""));
        ui->message7->setText(QString::fromUtf8(""));
        ui->message8->setText(QString::fromUtf8(""));
    }
    else if (typeDown == 1)
    {
        ui->message6->setText(QString::fromUtf8("当前采集数据不足，"));
        ui->message7->setText(QString::fromUtf8("无法进行绘制。"));
        ui->message8->setText(QString::fromUtf8("请继续采集数据"));
    }
}

void EndLineMessage::closeEvent(QCloseEvent *e)
{
    if (spectrogramplot != NULL)
    {
        mainLayout->removeWidget(spectrogramplot);
        delete spectrogramplot;
        spectrogramplot = NULL;
    }
    emit menuClose();
}

void EndLineMessage::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_ESC)
    {
        this->close();
    }
    elseif (e->key() == KEY_AUDIO)
    {
        QMouseEvent eventPress(QEvent::MouseButtonPress,QCursor::pos(),Qt::RightButton,Qt::RightButton,Qt::NoModifier);
        QApplication::sendEvent(this,&eventPress);

        QMouseEvent eventRelease(QEvent::MouseButtonRelease,QCursor::pos(),Qt::RightButton,Qt::RightButton,Qt::NoModifier);
        QApplication::sendEvent(this,&eventRelease);
    }
}

void EndLineMessage::mousePressEvent(QMouseEvent *e)
{
    if (e->KeyPress == Qt::RightButton)
    {
        qDebug() << "mouse right press";
    }

}

void EndLineMessage::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->KeyPress == Qt::RightButton)
    {
        qDebug() << "mouse right release";
    }
}
