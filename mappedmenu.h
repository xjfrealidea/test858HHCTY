#ifndef MAPPEDMENU_H
#define MAPPEDMENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "scrollnumlabel.h"
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "mappedmode.h"
#include "filedatainfo.h"
#include "simpledownmenuwidget.h"

namespace Ui {
class MappedMenu;
}

class MappedMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MappedMenu(QWidget *parent = 0);
    ~MappedMenu();

Q_SIGNALS:
    void changeSpeed(int);
    void menuClose();
    void mappedStart(int file, int type,long line,long markposition,int direction);

    void sendCommand(QString cmd);

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void startclicked();
    void mappedModeClose();
    void mappedMenuStart();
    void checkFileStatus();
    void changeFileDataWidget();

private:
    Ui::MappedMenu *ui;

    MappedMode *mappedMode;
    QStackedWidget *filedata;
    FileDataWidget *spaceWidget;
    FileDataWidget *fileDataWidget;
    SimpleDownMenuWidget *downMenuwidget;

    ScrollNumLabel *fileNumLabel;

    QString cmd;
};

#endif // MAPPEDMENU_H
