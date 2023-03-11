#ifndef BASEMENU_H
#define BASEMENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "scrollnumlabel.h"
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "basemode.h"
#include "filedatainfo.h"
#include "basedownmenuwidget.h"

namespace Ui {
class BaseMenu;
}

class BaseMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit BaseMenu(QWidget *parent = 0);
    ~BaseMenu();

Q_SIGNALS:
    void changeSpeed(int);
    void menuClose();
    void baseStart(int file, int type,long line,long markposition,int direction);

    void sendCommand(QString cmd);

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void startclicked();
    void baseModeClose();
    void baseMenuStart();
    void checkFileStatus();
    void changeFileDataWidget();

private:
    Ui::BaseMenu *ui;

    BaseMode *baseMode;
    QStackedWidget *filedata;
    FileDataWidget *spaceWidget;
    FileDataWidget *fileDataWidget;
    BaseDownMenuWidget *downMenuwidget;

    ScrollNumLabel *fileNumLabel;

    QString cmd;
};

#endif // BASEMENU_H
