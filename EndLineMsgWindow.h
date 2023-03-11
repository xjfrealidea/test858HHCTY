#ifndef ENDLINEMSGWINDOW_H
#define ENDLINEMSGWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QString>
#include "spectrogramplot.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class EndLineMsgWindow;
}

class EndLineMsgWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndLineMsgWindow(QWidget *parent = 0);
    ~EndLineMsgWindow();

    void closephase();

signals:
    void menuClose();

public Q_SLOTS:
    void setLineAndMark(long line,long mark);
    void menuStart(QString gridFilePath, short type, double LLx=0.0, double LLy=0.0, double URx=0.0, double URy=0.0);
    void setGpsPos(double lon, double lat);

    void setTextUp(int typeUp);
    void setTextDown(int typeDown);

    void zoomChanged(QRectF rect);

    void markPos(double x, double y, int type);
    void setMark();

    void initPos();
protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mouseDoubleClickEvent(QMouseEvent *e);

private:
    Ui::EndLineMsgWindow *ui;

    QHBoxLayout *mainLayout;
    SpectrogramPlot *spectrogramplot;

    QLabel *lineLabel;
    QLabel *lineDataLabel;
    QLabel *markLabel;
    QLabel *markDataLabel;
    QLabel *message1;
    QLabel *message2;
    QLabel *message3;
    QLabel *message4;
    QLabel *message5;
    QLabel *message6;
    QLabel *message7;
    QLabel *message8;

    int plot_type;

    QLabel *crossImage;
    QLabel *circleImage;

    double posx;
    double posy;
    double posh;
};

#endif // ENDLINEMSGWINDOW_H
