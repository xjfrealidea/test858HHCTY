#ifndef SIMPLEMENU_H
#define SIMPLEMENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "scrollnumlabel.h"
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "simplemode.h"
#include "filedatainfo.h"
#include "simpledownmenuwidget.h"

namespace Ui {
class SimpleMenu;
}

class SimpleMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimpleMenu(QWidget *parent = 0);
    ~SimpleMenu();

Q_SIGNALS:
    void changeSpeed(int);
    void menuClose();
    void simpleStart(int file, int type,long line,long markposition,int direction);

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void startclicked();
    void simpleModeClose();
    void simpleMenuStart();
    void checkFileStatus();
    void changeFileDataWidget();

private:
    Ui::SimpleMenu *ui;

    SimpleMode *simpleMode;
    QStackedWidget *filedata;
    FileDataWidget *spaceWidget;
    FileDataWidget *fileDataWidget;
    SimpleDownMenuWidget *downMenuwidget;

    ScrollNumLabel *fileNumLabel;
};

#endif // SIMPLEMENU_H
