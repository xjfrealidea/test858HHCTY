#ifndef Plot_H
#define Plot_H

#include <QWidget>
#include <QPixmap>
#include <vector>
#include <stack>
#include <QPen>
#include "datacache.h"
#include <QDebug>
#include <QMap>
using namespace std;

enum
{
    DEFAULT = 33,
    CUSTOM
};

class Plot;

////// 曲线信息类 //////
class Graph
{
public:
    Graph(Plot* plot) : m_plot(plot), m_dataCache(NULL), m_name("Graph"), m_pen(QPen(Qt::white)){}
    ~Graph(void) {}


    void setDataCache(DataCache* cache) { if(m_dataCache!=NULL){m_dataCache->disattach(m_plot);} m_dataCache = cache; m_dataCache->attach(m_plot); }
    void removeDataCache() {m_dataCache->disattach(m_plot);}
    DataCache *dataCache() { return m_dataCache; }

    void setBegin(DataCache::iterator begin) { m_begin = begin; }
    DataCache::iterator begin() { return m_begin; }
    void setEnd(DataCache::iterator end) { m_end = end; }
    DataCache::iterator end() { return m_end; }

    void setName(QString name) { m_name = name; }
    QString name() { return m_name; }

    void setPen(QPen pen) { m_pen = pen; }
    QPen pen() { return m_pen; }

    bool canDraw() { return !m_dataCache->isEmpty(); }



private:
    Plot* m_plot;            // 曲线绘制部件
    DataCache* m_dataCache;  // 曲线数据
    DataCache::iterator m_begin;
    DataCache::iterator m_end;
    QString m_name;          // 曲线名称
    QPen m_pen;              // 曲线画笔
};

////// 绘图控件类 //////
class Plot : public QWidget
{
    Q_OBJECT
public:
    explicit Plot(QWidget *parent = 0);

    void setGridMargins(int left, int top, int right, int bottom);
    void setGrid(int rows, int columns) { m_gridRows = rows; m_gridColumns = columns; }
    void setTitle(QString title) { m_title = title; }
    void setYAxisAutoRangeEnabled(bool enabled) { m_yAxisAutoRangeEnabled = enabled; }
    void setYAxisRange(double min, double max) { m_yAxisMin = min; m_yAxisMax = max; }
    void setYAxisScalePrecision(int precision) { m_yAxisScalePrecision = precision; }
    void setYAxisScaleOnLeft(bool onLeft) { m_yAxisScaleOnLeft = onLeft; }
    void setThresholdEnabled(bool enabled) { m_thresholdEnabled = enabled; }
    void setThresholdUp(double thresholdUp) { m_thresholdUp = thresholdUp; }
    void setThresholdDown(double thresholdDown) { m_thresholdDown = thresholdDown; }
//    void setZoomX(double zoomX) { m_zoomX = zoomX; update(); }
//    void setZoomY(double zoomY) { m_zoomY = zoomY; update(); }
//    void setZoomXUp() { if(m_zoomX*1.5<10){m_zoomX *= 1.5;} update(); }
//    void setZoomXDown() { if(m_zoomX/1.5>0.05){m_zoomX /= 1.5;} update(); }
//    void setZoomYUp() { if(m_zoomY*1.5<5){m_zoomY *= 1.5;} update(); }
//    void setZoomYDown() { if(m_zoomY/1.5>0.01){m_zoomY /= 1.5;} update(); }
    bool setZoomX(int idx);
    bool setZoomY(int idx);
    bool setZoomXUp();
    bool setZoomXDown();
    bool setZoomYUp();
    bool setZoomYDown();

    void Play(){m_isMove = true;}

    void MoveLeft() ;
    void MoveRight() ;
    void MoveLeftPage() ;
    void MoveRightPage() ;

    int getDataCntOfPage() { return m_dataCntOfPage; }
    void addGraph();
    Graph* graph(int index);

//    void setCenterTrace() {centerTrace = true; update();}
    void setCenterTrace();
    void setDefault(int mode) {defaultMode = mode; update();}
    int getDefault() {return defaultMode;}

    void resetZoom() {m_zoomX = 1.0; m_zoomY = 0.5; update();}

    void setStepFlag() {stepFlag = true; update();}

    double getDValue() {return max_read-min_read;}
    double getMaxValue() {return max_read;}
    double getMinValue() {return min_read;}

//    void setDataHz(int hz){m_DataHz = hz;m_xOfPoint = m_xOfPoint/m_DataHz;}

//    double getAverageValue(int index) {return m_average.value(index,-1);}

public slots:
    void onDataChanged();

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *);

private:
    void drawGrid(QPainter *painter);   // 绘制网格
    void drawTitle(QPainter *painter);  // 绘制标题
    void drawLines(QPainter *painter);  // 绘制线
    void drawYAxisScaleValue(QPainter *painter);    // 绘制Y轴刻度
    void drawXAxisScale(QPainter *painter);         // 绘制X轴（时间轴）刻度：刻度线和刻度值
    void drawThresholdLine(QPainter *painter);      // 绘制阀值线
    void drawDataHint(QPainter *painter);           // 绘制数据提示

    void getYAxisRange(double &max, double &min);    // Y轴范围：最大值或最小值为多条曲线一页数据中的最大值和最小值
    void MovePoint(int count);
    // 网格信息获取函数
    int getGridWidth() { return width()-m_gridLeft-m_gridRight; }  // 网格宽度，单位pixel
    int getGridHeight() { return height()-m_gridTop-m_gridBottom; } // 网格高度，单位pixel
    QRect getGridRect() { return QRect(m_gridLeft, m_gridTop, getGridWidth(), getGridHeight()); }
    double getGridRowStep() { return (double)getGridHeight()/m_gridRows; }      // 网格行步长，单位pixel
    double getGridColumnStep() { return (double)getGridWidth()/m_gridColumns; }   // 网格列步长，单位pixel

private:

//#pragma pack(2)

    bool     m_thresholdEnabled;    // 是否启动阀值功能
    bool     m_isShowDataHint;
    bool     m_isMove;              //播放
    bool     m_yAxisAutoRangeEnabled;     // 标记是否启动Y轴刻度范围自变化功能
    bool     m_yAxisScaleOnLeft;          // Y轴刻度显示在坐标系左边
    bool     stepFlag;
    bool     centerTrace;
//#pragma pack(8)
    int     defaultMode;

    int m_gridLeft;     // 网格的左边余白，单位pixel
    int m_gridTop;      // 网格的顶边余白，单位pixel
    int m_gridRight;    // 网格的右边余白，单位pixel
    int m_gridBottom;   // 网格的底边余白，单位pixel
    int m_gridRows;     // 网格行数
    int m_gridColumns;  // 网格列数


    int m_dataCntOfPage;        // 一页显示数据数目
    int      m_DataHz;              //数据频率
    int      m_yAxisScalePrecision;       // Y轴刻度显示精度：小数点后有效位数

    double   m_xOfPoint;        // 每个像素表示的点数，默认0.5
    double   m_yOfPoint;        // 每个像素表示的值，默认6.0
    double   m_zoomX;           // X轴（横轴）缩放，默认1.0
    double   m_zoomY;           // Y轴（纵轴）缩放，默认0.5
    double   m_yAxisMin;        // Y轴最小刻度值
    double   m_yAxisMax;        // Y轴最大刻度值
    double   m_xAxisMin;
    double   m_xAxisMax;

    double   m_thresholdUp;         // 上限阀值
    double   m_thresholdDown;       // 下线阀值

    double max_read;
    double min_read;

    double step;


    QPixmap m_gridPixmap;
    QPixmap m_bufferPixmap;
    QPoint  m_showDataHintPos;     // （可去掉）
    QString m_title;    // 标题

    vector<Graph*> m_graphs;   // 曲线
//    QMap<int, double> m_average; //平均值
    QVector<double> zoomList;
    int zoomXidx;
    int zoomYidx;
};
#endif // Plot_H
