#ifndef MAINFRM_H
#define MAINFRM_H

#include <QWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include "plot.h"

class MainFrm : public QWidget
{
    Q_OBJECT

public:
    explicit MainFrm(QWidget *parent = 0);
    QGridLayout *gridLayout;
    Plot *plot1;

    vector<Plot*> m_Plots;
    ~MainFrm();

    bool setZoomX(int idx);
    bool setZoomY(int idx);
    bool setZoomXUp();
    bool setZoomXDown();
    bool setZoomYUp();
    bool setZoomYDown();

    void setCenterTrace();

    void setDefaultMode(int mode);
    int getDefaultMode();

//    double getAverageValue(int index);
    double getDValue();
    double getMaxValue();
    double getMinValue();

public slots:
    void deltaChangeSlot(int index);

protected:
    void paintEvent(QPaintEvent *) override;
//    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent(QKeyEvent *e);

    //void onDataAnalyseFinished();
//    void removePlot(Plot *plot);
private:
    int deltaIndex;
};

#endif // MAINFRM_H
