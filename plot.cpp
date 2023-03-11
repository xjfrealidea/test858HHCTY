#include "plot.h"
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <math.h>
#include <QFontMetrics>
#include <QTime>
#include <QDebug>
#include "systemdetail.h"
#include <QFont>

Plot::Plot(QWidget *parent) :
    QWidget(parent),
    m_thresholdEnabled(false),
    m_isShowDataHint(false),
    m_isMove(true),
    m_yAxisAutoRangeEnabled(true),
    m_yAxisScaleOnLeft(true),
    m_gridLeft(80),
    m_gridTop(30),
    m_gridRight(50),
    m_gridBottom(30),
    m_gridRows(4),
    m_gridColumns(22),
    m_DataHz(1),
    m_yAxisScalePrecision(0),
    m_xOfPoint(0.5),
    m_yOfPoint(6),
//    m_zoomX(1.0),
//    m_zoomY(0.5),
    m_thresholdUp(0.25),
    m_thresholdDown(-0.25),
    m_showDataHintPos(QPoint(0,0)),
    m_title("Plot")

{
    setMouseTracking(false);
    //flag = false;
    max_read = -1;
    min_read = -1;
    step = 25;
    stepFlag = false;
    m_yAxisMax = -1;
    m_yAxisMin = 9999999;
    centerTrace = false;

    zoomList.push_back(0.05);
    zoomList.push_back(0.1);
    zoomList.push_back(0.25);
    zoomList.push_back(0.5);
    zoomList.push_back(1.0);
    zoomList.push_back(1.5);
    zoomList.push_back(2.0);
    zoomList.push_back(3.0);
    zoomList.push_back(5.0);

    zoomXidx = 4;
    zoomYidx = 4;
    m_zoomX = zoomList.value(zoomXidx);
    m_zoomY = zoomList.value(zoomYidx);
}

void Plot::addGraph()
{
    m_graphs.push_back(new Graph(this));
}

void Plot::onDataChanged()
{
    if(m_isMove)
    {
        for(int idx = 0; idx < m_graphs.size(); ++idx)
        {
            DataCache::iterator begin, end;
            end = m_graphs[idx]->dataCache()->last();
            begin = end - getDataCntOfPage();
            m_graphs[idx]->setBegin(begin);
            m_graphs[idx]->setEnd(end);
        }
    }

    if(m_yAxisAutoRangeEnabled)
    {
        getYAxisRange(m_yAxisMax, m_yAxisMin);
        max_read = m_yAxisMax;
        min_read = m_yAxisMin;
        m_yAxisMax = m_yAxisMax + 0.5;
        m_yAxisMin = m_yAxisMin - 0.5;
    }

    m_yOfPoint = (m_yAxisMax-m_yAxisMin) / getGridHeight();

    update();
}
void Plot::MoveLeft()
{
    MovePoint((int)(0-m_dataCntOfPage*0.1));
}
void Plot::MoveRight()
{
    MovePoint((int)(m_dataCntOfPage*0.1));
}
void Plot::MoveLeftPage()
{
    MovePoint(0-m_dataCntOfPage);
}
void Plot::MoveRightPage()
{
    MovePoint(m_dataCntOfPage);
}
void Plot::MovePoint(int count)
{
    m_isMove = false;
    for(int idx = 0; idx < m_graphs.size(); ++idx)
    {
        DataCache::iterator begin, end;
        begin =  m_graphs[idx]->begin() + count;

        end   = begin + getDataCntOfPage();
        if(begin > 0)
        {
            m_graphs[idx]->setBegin(begin);
            m_graphs[idx]->setEnd(end);
        }
    }

    if(m_yAxisAutoRangeEnabled)
    {
        getYAxisRange(m_yAxisMax, m_yAxisMin);
        max_read = m_yAxisMax;
        min_read = m_yAxisMin;
        m_yAxisMax = m_yAxisMax + 0.5;
        m_yAxisMin = m_yAxisMin - 0.5;
    }
    m_yOfPoint = (m_yAxisMax-m_yAxisMin) / getGridHeight();

    update();
}
void Plot::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);
    m_gridPixmap = QPixmap(size());
    m_gridPixmap.fill(Qt::white);
    QPainter painter(&m_gridPixmap);
    painter.translate(m_gridLeft, m_gridTop);

    // 绘制网格
    painter.setPen(Qt::gray);
    // 绘制水平网格
    double gridRowStep = getGridRowStep();
    int gridWidth = getGridWidth();
    for(int row = 0; row <= m_gridRows; ++row)
    {
        painter.drawLine(QPointF(0, row*gridRowStep), QPointF(gridWidth, row*gridRowStep));
    }
    // 绘制垂直网格
    double gridColumnStep = getGridColumnStep();
    int gridHeight = getGridHeight();
    for(int column = 0; column <= m_gridColumns; ++column)
    {
        painter.drawLine(QPoint(column*gridColumnStep, 0), QPoint(column*gridColumnStep, gridHeight));
    }

    // 绘制坐标轴
    painter.setPen(Qt::black);
    painter.drawLine(0, 0, 0, gridHeight);
    painter.drawLine(0, gridHeight, gridWidth, gridHeight);

    m_dataCntOfPage = getGridWidth()/(m_xOfPoint*m_zoomX);
}

void Plot::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    m_dataCntOfPage = getGridWidth()/(m_xOfPoint*m_zoomX);
    m_bufferPixmap = QPixmap(size());
    m_bufferPixmap.fill(Qt::white);
    QPainter painter(&m_bufferPixmap);

    drawGrid(&painter);    // 绘制网格
    drawTitle(&painter);   // 绘制标题

    if(m_graphs.size()>0)
        if(graph(0)->dataCache()->GetCount()>0)
        {
            drawLines(&painter);   // 绘制线条
            drawYAxisScaleValue(&painter);  // 绘制Y轴（值轴）刻度值
//            drawXAxisScale(&painter);       // 绘制X轴（时间轴）刻度：刻度线和刻度值
            if(m_thresholdEnabled)
            {
                drawThresholdLine(&painter);    // 绘制阀值线
            }
            if(m_isShowDataHint)
            {
                drawDataHint(&painter);         // 绘制数据提示
            }
        }

    QPainter painter2(this);
    painter2.drawPixmap(0, 0, m_bufferPixmap);
}

void Plot::drawGrid(QPainter *painter)
{
    painter->drawPixmap(0, 0, m_gridPixmap);
}

void Plot::drawTitle(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::black);
    QFont font;
    font.setPixelSize(15);
    painter->setFont(font);
    painter->drawText(QRect(0,5,width(),m_gridTop), Qt::AlignLeft|Qt::AlignVCenter, m_title +QString().sprintf("          波动:  %.2f\n", (max_read - min_read)));
    painter->restore();
}
                                        //double   m_xOfPoint;        // 每个像素表示的点数，默认0.5
                                        //double   m_yOfPoint;        // 每个像素表示的值，默认6.0
                                        //double   m_zoomX;           // X轴（横轴）缩放，默认1.0
                                        //double   m_zoomY;           // Y轴（纵轴）缩放，默认1.0
                                        //double   m_yAxisMin;        // Y轴最小刻度值
                                        //double   m_yAxisMax;        // Y轴最大刻度值
void Plot::drawLines(QPainter *painter)
{
    painter->save();
    painter->translate(m_gridLeft, m_gridTop);
    for(int ix = 0; ix < m_graphs.size(); ++ix)
    {
        Graph *tmpGraph = graph(ix);
        if(!tmpGraph->dataCache()->isEmpty())
        {
            painter->setPen(tmpGraph->pen());
            QPainterPath linePath;
            DataCache::iterator iter = tmpGraph->begin();
            linePath.moveTo(0, ((*iter).value-(m_yAxisMax + m_yAxisMin)/2)/m_yOfPoint * m_zoomY + getGridHeight()/2);

            int count = 0;
            while((iter++) != tmpGraph->end())
            {
                count++;
                double x = count * m_xOfPoint * m_zoomX;
                double y = ((*iter).value-(m_yAxisMax + m_yAxisMin)/2)/m_yOfPoint * m_zoomY + getGridHeight()/2;
                linePath.lineTo(x, qBound(0.0,y,(double)getGridHeight()));
                //qBound()取三个值中中间的值作为返回值
            }
            painter->setPen(QPen(Qt::black,3));
            painter->drawPath(linePath);
        }
    }
    painter->restore();
}

void Plot::drawYAxisScaleValue(QPainter *painter)
{
    painter->save();

    double yAxisScaleStep = 1.0/m_zoomY *(m_yAxisMax-m_yAxisMin)/m_gridRows; // Y轴刻度步长
    double gridRowStep = getGridRowStep();
    double startStep = (m_yAxisMax+m_yAxisMin)/2-m_gridRows/2 *yAxisScaleStep;
    for(int i = 0; i<=m_gridRows; i++)
    {
        double scaleValue = startStep+i*yAxisScaleStep;    // 起始值暂为m_yAxisMin
        QString scaleValueText = QString("%1").arg(scaleValue, 0, 'f', m_yAxisScalePrecision);// m_yAxisScalePrecision Y轴刻度显示精度：小数点后有效位数

        painter->setPen(Qt::black);
        QFont font;
        font.setPixelSize(15);
        painter->setFont(font);
        int offset = 10;
        if(m_yAxisScaleOnLeft)
        {
            painter->drawText(0, m_gridTop-gridRowStep/2+i*gridRowStep, m_gridLeft-offset, gridRowStep, Qt::AlignRight|Qt::AlignVCenter, scaleValueText);
            //qDebug()<<"True"<<__LINE__<<__FILE__;
        }else
        {
            painter->drawText(width()-m_gridLeft+offset, m_gridTop-gridRowStep/2+i*gridRowStep, m_gridLeft, gridRowStep, Qt::AlignLeft|Qt::AlignVCenter, scaleValueText);
          //  qDebug()<<"False"<<__LINE__<<__FILE__;
        }
    }

    painter->restore();
}

void Plot::drawXAxisScale(QPainter *painter)
{
    int tmp = 0;
    if(m_graphs.size() > 0 && !m_graphs[0]->dataCache()->isEmpty())//m_graphs 曲线类容器
    {
        int count = 0;
        DataCache::iterator iter = m_graphs[0]->begin();
        while((iter++) != m_graphs[0]->end())
        {
            count++;
            tmp = (int)(100/(m_xOfPoint*m_zoomX));
           // qDebug()<<tmp<<__LINE__<<__FILE__;
            if(tmp < 1)
            {
                return;
            }
            if((iter % tmp) == 0)
            {
                int X = (int)(count * m_xOfPoint * m_zoomX) + m_gridLeft;
                int Y = height()-m_gridTop;
                painter->setPen(Qt::black);
                painter->drawLine(X, Y, X, Y+5);
                int msecs = (*iter).key;
                QString timeStr = QTime(0,0).addMSecs(msecs).toString("hh:mm:ss");
                painter->drawText(X, Y+5, 200, 20, Qt::AlignLeft, timeStr);
            }
        }
    }
}

void Plot::drawThresholdLine(QPainter *painter)
{
    painter->save();

    painter->translate(m_gridLeft, m_gridTop);
    painter->setPen(QColor(150,150,150));

    int x1,y1,x2,y2;
    // 绘制上限阀值线
    x1 = 0;
    y1 = (m_thresholdUp-m_yAxisMin)/m_yOfPoint*m_zoomY;
    x2 = getGridWidth();
    y2 = y1;
    painter->drawLine(x1, y1, x2, y2);
    // 绘制下限阀值线
    y1 = (m_thresholdDown-m_yAxisMin)/m_yOfPoint*m_zoomY;
    y2 = y1;
    painter->drawLine(x1, y1, x2, y2);

    painter->restore();
}

void Plot::drawDataHint(QPainter *painter)
{
    painter->save();

    int hintPosXInGrid = m_showDataHintPos.x() - m_gridLeft;
    DataCache::iterator dataHintIter;

    QString dataHint = "时间:";
    for(int idx = 0; idx < m_graphs.size(); ++idx)
    {
        Graph* tmpGraph = graph(idx);
        QString graphName = tmpGraph->name();
        if(idx == 0)
        {
            dataHintIter = tmpGraph->begin() + (int)(hintPosXInGrid/(m_xOfPoint*m_zoomX));
            int msecs = (*dataHintIter).key;
            QString timeStr = QTime(0,0).addMSecs(msecs).toString("hh:mm:ss:zzz");
            dataHint += timeStr;
            dataHint += "\n";
        }
        dataHint += graphName;
        dataHint += QString().sprintf(":%.4f\n", (*dataHintIter).value);
    }

    QFontMetrics fm(painter->font());
    int dataHintShowWidth = fm.width(dataHint)/(1+ m_graphs.size());
    int dataHintShowHeight = fm.height()*(1+ m_graphs.size());

    int offset = 20;

    painter->setPen(Qt::black);
    QRect dataHintRect;
    if(m_showDataHintPos.x() < (width()-m_gridRight-dataHintShowWidth))
    {
        dataHintRect.setX(m_showDataHintPos.x()+offset);
    }
    else
    {
        dataHintRect.setX(m_showDataHintPos.x()-dataHintShowWidth-offset);
    }

    if(m_showDataHintPos.y() < (height()-m_gridBottom-dataHintShowHeight))
    {
        dataHintRect.setY(m_showDataHintPos.y());
    }
    else
    {
        dataHintRect.setY(m_showDataHintPos.y()-dataHintShowHeight);
    }

    dataHintRect.setWidth(dataHintShowWidth+offset);
    dataHintRect.setHeight(dataHintShowHeight+offset);
    painter->drawText(dataHintRect, Qt::AlignLeft|Qt::AlignTop, dataHint);

    painter->restore();
}

void Plot::setGridMargins(int left, int top, int right, int bottom)
{
    m_gridLeft = left;
    m_gridTop = top;
    m_gridRight = right;
    m_gridBottom = bottom;
}

bool Plot::setZoomX(int idx)
{
    if ((idx > -1) && (idx < zoomList.size()) )
    {
        zoomXidx = idx;
        m_zoomX = zoomList.value(zoomXidx);
        update();
        return true;
    }
    return false;
}

bool Plot::setZoomY(int idx)
{
    if ((idx > -1) && (idx < zoomList.size()) )
    {
        zoomYidx = idx;
        m_zoomY = zoomList.value(zoomYidx);
        update();
        return true;
    }
    return false;
}

bool Plot::setZoomXUp()
{
    if (((zoomXidx+1) > -1) && ((zoomXidx+1) < zoomList.size()) )
    {
        zoomXidx++;
        m_zoomX = zoomList.value(zoomXidx);
        qDebug() << "zoomx " << m_zoomX;
        update();
        return true;
    }
    return false;
}

bool Plot::setZoomXDown()
{
    if (((zoomXidx-1) > -1) && ((zoomXidx-1) < zoomList.size()) )
    {
        zoomXidx--;
        m_zoomX = zoomList.value(zoomXidx);
        qDebug() << "zoomx " << m_zoomX;
        update();
        return true;
    }
    return false;
}

bool Plot::setZoomYUp()
{
    if (((zoomYidx+1) > -1) && ((zoomYidx+1) < zoomList.size()) )
    {
        zoomYidx++;
        m_zoomY = zoomList.value(zoomYidx);
        qDebug() << "zoomy " << m_zoomY;
        update();
        return true;
    }
    return false;
}

bool Plot::setZoomYDown()
{
    if (((zoomYidx-1) > -1) && ((zoomYidx-1) < zoomList.size()) )
    {
        zoomYidx--;
        m_zoomY = zoomList.value(zoomYidx);
        qDebug() << "zoomy " << m_zoomY;
        update();
        return true;
    }
    return false;
}

void Plot::getYAxisRange(double &max, double &min)
{
    if(m_graphs.size() > 0 && !m_graphs[0]->dataCache()->isEmpty())
    {
        max = min = (*(m_graphs[0]->begin())).value;

        for(int ix = 0; ix < m_graphs.size(); ++ix)
        {
            DataCache::iterator iter = m_graphs[ix]->begin();
//            double valuesum = 0.0;
//            int count = 0;
            while((iter++) != m_graphs[ix]->end())
            {
                if((*iter).value > max)
                {
                    max = (*iter).value;
                }

                if((*iter).value < min)
                {
                    min = (*iter).value;
                }
//                valuesum += (*iter).value;
//                count++;
            }
//            double average = valuesum/count;
//            m_average.insert(ix, average);
        }
    }
}

Graph* Plot::graph(int index)
{
    if(index < 0 || index > m_graphs.size()-1)
    {
        return NULL;
    }
    return m_graphs[index];
}

void Plot::setCenterTrace()
{
    setZoomX(4);
    setZoomY(4);
    update();
}
