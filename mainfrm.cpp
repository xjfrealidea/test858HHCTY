#include <QtGui/QKeyEvent>
#include "mainfrm.h"
//#include "ui_mainfrm.h"
#include "dataanalyser.h"
#include "datacollector.h"
#include "macro.h"

MainFrm::MainFrm(QWidget *parent) :
    QWidget(parent)
{
    gridLayout = new QGridLayout(this);

    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);
    plot1 = new Plot(this);
    plot1->setObjectName(QStringLiteral("plot1"));
    gridLayout->addWidget(plot1,0,0);
    m_Plots.push_back(plot1);

//    plot1->setTitle("探头1(nT)");
    plot1->setTitle("");
    plot1->addGraph();
    plot1->setYAxisScalePrecision(2);
    plot1->setYAxisAutoRangeEnabled(true);
    //plot1->SetDataHz(50);
    plot1->graph(0)->setDataCache(DataAnalyser::instance().mGBData1);
//    plot1->graph(0)->setName("光泵数据1");
    plot1->graph(0)->setName("");
    plot1->graph(0)->setPen(QPen(Qt::green));

    deltaIndex = 0;
}

MainFrm::~MainFrm()
{
    plot1->graph(0)->removeDataCache();
}

bool MainFrm::setZoomX(int idx)
{
    return plot1->setZoomX(idx);
}

bool MainFrm::setZoomY(int idx)
{
    return plot1->setZoomY(idx);
}

bool MainFrm::setZoomXUp()
{
    return plot1->setZoomXUp();
}

bool MainFrm::setZoomXDown()
{
    return plot1->setZoomXDown();
}

bool MainFrm::setZoomYUp()
{
    return plot1->setZoomYUp();
}

bool MainFrm::setZoomYDown()
{
    return plot1->setZoomYDown();
}

void MainFrm::setCenterTrace()
{
    plot1->setCenterTrace();
}

void MainFrm::setDefaultMode(int mode)
{
    plot1->setDefault(mode);
}

int MainFrm::getDefaultMode()
{
    return plot1->getDefault();
}

//double MainFrm::getAverageValue(int index)
//{
//    return plot1->getAverageValue(index);
//}

double MainFrm::getDValue()
{
    return plot1->getDValue();
}

double MainFrm::getMaxValue()
{
    return plot1->getMaxValue();
}

double MainFrm::getMinValue()
{
    return plot1->getMinValue();
}

void MainFrm::keyPressEvent(QKeyEvent *e)
{
    Q_UNUSED(e);
}

void MainFrm::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
}

void MainFrm::deltaChangeSlot(int index)
{
    deltaIndex = index;
 /*   if (deltaIndex < 0)
    {
        deltaIndex = 2;
    }
    else if (deltaIndex > 2)
    {
        deltaIndex = 0;
    }
*/
    switch (deltaIndex)
    {
    case 1:
        plot1->graph(0)->setDataCache(DataAnalyser::instance().mGBData1);
        break;
    case 2:
        plot1->graph(0)->setDataCache(DataAnalyser::instance().mGBData2);
        break;
    case 3:
        plot1->graph(0)->setDataCache(DataAnalyser::instance().mGBData3);
        break;
    default:
        break;
    }
}
