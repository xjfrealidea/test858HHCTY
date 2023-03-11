#ifndef ENDLINEMESSAGE_H
#define ENDLINEMESSAGE_H

#include <QDialog>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QString>
#include "spectrogramplot.h"
#include <QHBoxLayout>
#include <QMouseEvent>

namespace Ui {
class EndLineMessage;
}

class EndLineMessage : public QDialog
{
    Q_OBJECT

public:
    explicit EndLineMessage(QWidget *parent = 0);
    ~EndLineMessage();

signals:
    void menuClose();

public Q_SLOTS:
    void setLineAndMark(long line,long mark);
    void menuStart(QString gridFilePath, short type);
    void setGpsPos(double lon, double lat);

    void setTextUp(int typeUp);
    void setTextDown(int typeDown);

    void setCursorPosFlag(bool flag) {cursorPosFlag = flag;}

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::EndLineMessage *ui;

    QHBoxLayout *mainLayout;
    SpectrogramPlot *spectrogramplot;

    bool cursorPosFlag;
};

#endif // ENDLINEMESSAGE_H
