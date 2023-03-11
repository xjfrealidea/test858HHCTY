#ifndef DRAWMENU_H
#define DRAWMENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "scrollnumlabel.h"
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "drawmode.h"
#include "filedatainfo.h"
#include "mappeddownmenuwidget.h"
#include "definemapmenu.h"

namespace Ui {
class DrawMenu;
}

class DrawMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawMenu(QWidget *parent = 0);
    ~DrawMenu();


    typedef struct
    {
        int surveyDirection;
        int parallelAxis;
        double LLx;
        double LLy;
        double URx;
        double URy;
        double spaceLine;
        double spaceMark;
    }DEFINEDATA;

Q_SIGNALS:
    void changeSpeed(int);
    void menuClose();
    void drawStart(int file, int type,long line,long markposition, DEFINEDATA data);

    void defineMenuShow();

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void startclicked();
    void drawModeClose();
    void drawMenuStart();
    void checkFileStatus();
    void changeFileDataWidget();

    void defineclicked();

private:
    Ui::DrawMenu *ui;

    DrawMode *drawMode;
    QStackedWidget *filedata;
    FileDataWidget *spaceWidget;
    FileDataWidget *fileDataWidget;
    MappedDownMenuWidget *downMenuwidget;
    DefineMapMenu *defineMapMenu;

    ScrollNumLabel *fileNumLabel;

    DEFINEDATA defineDate;
};

#endif // DRAWMENU_H
