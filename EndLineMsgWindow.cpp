#include "EndLineMsgWindow.h"
#include "ui_EndLineMsgWindow.h"
#include "macro.h"
#include <QMouseEvent>
#include <QApplication>

#define CROSSMARK 0
#define CIRCLEMARK 1

EndLineMsgWindow::EndLineMsgWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndLineMsgWindow)
{
    ui->setupUi(this);

    spectrogramplot = NULL;
    lineLabel = new QLabel(this);
    lineDataLabel = new QLabel(this);
    markLabel = new QLabel(this);
    markDataLabel = new QLabel(this);
    message1 = new QLabel(this);
    message2 = new QLabel(this);
    message3 = new QLabel(this);
    message4 = new QLabel(this);
    message5 = new QLabel(this);
    message6 = new QLabel(this);
    message7 = new QLabel(this);
    message8 = new QLabel(this);

    mainLayout = new QHBoxLayout(ui->centralwidget);

    QVBoxLayout *messageLayout = new QVBoxLayout();

    QVBoxLayout *lineData = new QVBoxLayout();
    lineData->addWidget(lineLabel,1);
    lineData->addWidget(lineDataLabel,1);

    QVBoxLayout *markData = new QVBoxLayout();
    markData->addWidget(markLabel,1);
    markData->addWidget(markDataLabel,1);

    messageLayout->addWidget(message1,1);
    messageLayout->addWidget(message2,1);
    messageLayout->addLayout(lineData,1);
    messageLayout->addLayout(markData,1);
    messageLayout->addWidget(message3,1);
    messageLayout->addWidget(message4,1);
    messageLayout->addWidget(message5,1);
    messageLayout->addWidget(message6,1);
    messageLayout->addWidget(message7,1);
    messageLayout->addWidget(message8,1);

//    message1->setVisible(false);
//    message2->setVisible(false);
//    message3->setVisible(false);
//    message4->setVisible(false);
//    message5->setVisible(false);
//    message6->setVisible(false);
//    message7->setVisible(false);
//    message8->setVisible(false);
//    lineLabel->setVisible(false);
//    lineDataLabel->setVisible(false);
//    markLabel->setVisible(false);
//    markDataLabel->setVisible(false);
    mainLayout->addLayout(messageLayout,1);

    plot_type = 0;

   // setLayout();

    crossImage = new QLabel(this);
    crossImage->resize(57,57);
    crossImage->setPixmap(QPixmap(":/src/cross.png"));
    crossImage->setVisible(false);

//    circleImage = new QLabel(this);
//    circleImage->resize(57,57);
//    circleImage->setPixmap(QPixmap(":/src/circle.png"));
//    circleImage->setVisible(false);
}

EndLineMsgWindow::~EndLineMsgWindow()
{
    delete ui;
}

void EndLineMsgWindow::closephase()
{
    if (spectrogramplot != NULL)
    {
        disconnect(spectrogramplot->getPlotZoomer(),SIGNAL(zoomed(QRectF)),
                this,SLOT(zoomChanged(QRectF)));
        mainLayout->removeWidget(spectrogramplot);
        delete spectrogramplot;
        spectrogramplot = NULL;
    }
    QCursor::setPos(this->width(),this->height());

}

void EndLineMsgWindow::setLineAndMark(long line, long mark)
{
    lineDataLabel->setText(QString::number(line));
    markDataLabel->setText(QString::number(mark));
}

void EndLineMsgWindow::menuStart(QString gridFilePath, short type, double LLx, double LLy, double URx, double URy)
{
    if (spectrogramplot == NULL)
    {
        plot_type = type;
        crossImage->setVisible(false);
//        circleImage->setVisible(false);
        spectrogramplot = new SpectrogramPlot(gridFilePath,plot_type,LLx,LLy,URx,URy);
        if (spectrogramplot->setflag)
        {
            setTextDown(0);
            mainLayout->addWidget(spectrogramplot,3);

            connect(spectrogramplot->getPlotZoomer(),SIGNAL(zoomed(QRectF)),
                    this,SLOT(zoomChanged(QRectF)));

            initPos();
        }
        else
        {
            setTextDown(1);
            delete spectrogramplot;
            spectrogramplot = NULL;

        }
    }
}

void EndLineMsgWindow::setGpsPos(double lon, double lat)
{
    if (spectrogramplot == NULL)
    {
        return;
    }
    lineDataLabel->setText(QString::number(lon,'f',8));
    markDataLabel->setText(QString::number(lat,'f',8));

    markPos(lon, lat, CROSSMARK);
}

void EndLineMsgWindow::setTextUp(int typeUp)
{
    if (typeUp == 0)
    {
        message1->setText(QString::fromUtf8("已到达行末。"));
        message2->setText(QString::fromUtf8("当前调查位置:"));
        lineLabel->setText(QString::fromUtf8("LINE:"));
        markLabel->setText(QString::fromUtf8("MARK:"));
        message3->setText(QString::fromUtf8("按ESC键返回。"));
        message4->setText(QString::fromUtf8(" "));
    }
    else if (typeUp == 1)
    {
        message1->setText(QString::fromUtf8("当前调查已结束。"));
        message2->setText(QString::fromUtf8("当前探头位置:"));
        lineLabel->setText(QString::fromUtf8("经  度:"));
        markLabel->setText(QString::fromUtf8("纬  度:"));
        message3->setText(QString::fromUtf8("按ESC键返回。"));
        message4->setText(QString::fromUtf8(" "));
    }
}

void EndLineMsgWindow::setTextDown(int typeDown)
{
    message5->setText(QString::fromUtf8("————————————"));
    if (typeDown == 0)
    {
        message6->setText(QString::fromUtf8(""));
        message7->setText(QString::fromUtf8(""));
        message8->setText(QString::fromUtf8(""));
    }
    else if (typeDown == 1)
    {
        message6->setText(QString::fromUtf8("数据采集不足，"));
        message7->setText(QString::fromUtf8("无法进行绘制。"));
        message8->setText(QString::fromUtf8(" "));
    }
    else if (typeDown == 2)
    {
        message6->setText(QString::fromUtf8("深度估计: ") + QString::number(posh));
        message7->setText(QString::fromUtf8("定  位x: ") + QString::number(posx));
        message8->setText(QString::fromUtf8("定  位y: ") + QString::number(posy));
    }
    else if (typeDown == 3)
    {
        message6->setText(QString::fromUtf8(" "));
        message7->setText(QString::fromUtf8("定  位x: ") + QString::number(posx));
        message8->setText(QString::fromUtf8("定  位y: ") + QString::number(posy));
    }
}

void EndLineMsgWindow::zoomChanged(QRectF rect)
{
    if (spectrogramplot != NULL /*&& 1 == plot_type*/)
    {
        spectrogramplot->getRasterData()->recheckMaxMinValue(rect.right(),rect.left(),rect.top(),rect.bottom(),plot_type);
        double max_value = spectrogramplot->getRasterData()->max_value;
        double min_value = spectrogramplot->getRasterData()->min_value;

        QList<double> contourLevels;

        for ( double level = min_value; level <= max_value; level += ((max_value- min_value)/20) )
        {
            contourLevels += level;
        }
        spectrogramplot->get_d_spectrogram()->setContourLevels( contourLevels );

        spectrogramplot->setAxisScale( QwtPlot::yRight, (int)min_value-1, (int)max_value+1);
        spectrogramplot->enableAxis( QwtPlot::yRight );

        const QwtInterval *zInterval = new QwtInterval((int)min_value-1, (int)max_value+1);
        spectrogramplot->setColorMap(SpectrogramPlot::RGBMap, zInterval);

        QCursor::setPos(this->width(),this->height());

    }
}

void EndLineMsgWindow::markPos(double x, double y, int type)
{
    if (spectrogramplot == NULL)
    {
        return;
    }

    double mapXMin = spectrogramplot->axisInterval(QwtPlot::xBottom).minValue();
    double mapYMin = spectrogramplot->axisInterval(QwtPlot::yLeft).minValue();
    double mapXMax = spectrogramplot->axisInterval(QwtPlot::xBottom).maxValue();
    double mapYMax = spectrogramplot->axisInterval(QwtPlot::yLeft).maxValue();
    double xRange = mapXMax - mapXMin;
    double yRange = mapYMax - mapYMin;

    double xOffset = ((x-mapXMin) / xRange) * spectrogramplot->canvas()->width();
    double yOffset = ((mapYMax-y) / yRange) * spectrogramplot->canvas()->height();

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

    if (CROSSMARK == type)
    {
        crossImage->setVisible(true);
        crossImage->setGeometry(this->frameGeometry().left()
                                + spectrogramplot->frameGeometry().left()
                                + spectrogramplot->canvas()->geometry().left()
                                + xOffset
                                - (crossImage->width() - 1) / 2,
                                this->frameGeometry().top()
                                + spectrogramplot->frameGeometry().top()
                                + spectrogramplot->canvas()->geometry().top()
                                + yOffset
                                - (crossImage->height() - 1) / 2,
                                crossImage->width(),
                                crossImage->height());
    }
    else if (CIRCLEMARK == type)
    {
//        circleImage->setVisible(true);
//        circleImage->setGeometry(this->frameGeometry().left()
//                                + spectrogramplot->frameGeometry().left()
//                                + spectrogramplot->canvas()->geometry().left()
//                                + xOffset
//                                - (circleImage->width() - 1) / 2,
//                                this->frameGeometry().top()
//                                + spectrogramplot->frameGeometry().top()
//                                + spectrogramplot->canvas()->geometry().top()
//                                + yOffset
//                                - (circleImage->height() - 1) / 2,
//                                circleImage->width(),
//                                circleImage->height());
    }
}

void EndLineMsgWindow::setMark()
{
    markPos(spectrogramplot->getRasterData()->posx, spectrogramplot->getRasterData()->posy, CROSSMARK);
}

void EndLineMsgWindow::initPos()
{/*
    qDebug() << spectrogramplot->getPlotZoomer()->zoomBase();
    qDebug() << spectrogramplot->getPlotZoomer()->zoomRect();*/

    QRectF ret1 = spectrogramplot->getPlotZoomer()->zoomBase();
//    QRectF ret2 = spectrogramplot->getPlotZoomer()->zoomBase();

    spectrogramplot->getRasterData()->recheckMaxMinValue(ret1.right(),ret1.left(),ret1.top(),ret1.bottom(),plot_type);
}

void EndLineMsgWindow::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e)
    emit menuClose();
}

void EndLineMsgWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_ESC || e->key() == KEY_ENDLINE)
    {
        closephase();
        this->close();
    }
    else if (e->key() == KEY_ENTER)
    {
        if (spectrogramplot != NULL)
        {
            setMark();
        }
    }
//    else if (e->key() == KEY_AUDIO)
//    {
//        spectrogramplot->setZoom(0);
//    }
}

void EndLineMsgWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    spectrogramplot->setZoom(0);
}

