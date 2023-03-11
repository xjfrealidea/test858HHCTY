#ifndef MAGNETMENU_H
#define MAGNETMENU_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QKeyEvent>
#include "sreachmode.h"
#include "systemsetupmenu.h"
#include "simplemenu.h"
#include "datatransfermenu.h"
#include "mappedmenu.h"
#include <QLabel>
#include "timeeditdialog.h"
#include "transferdialog.h"
#include "drawmenu.h"
#include "basemenu.h"

namespace Ui {
class MagnetMenu;
}

class MagnetMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MagnetMenu(QWidget *parent = 0);
    ~MagnetMenu();

    void setMemoryUsed();
    void updateexe();
    void updateini();
    void updateqss();
    void exportStnData();
    void exportGirdData();

Q_SIGNALS:
    void sreachStart();
    void simpleMenuStart();
    void mappedStart();
    void drawMenuStart();

    void baseMenuStart();

    void setMemoryUsedLabel(QString);

public Q_SLOTS:
    void magnatShow();
    void timeLabelPress();
    void timeLabelFocusOut(int type);

protected:
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void on_setupButton_clicked();
    void sreachModeClose();
    void systemSetupMenuClose();
    void simpleModeClose();
    void dataTransferMenuClose();
    void mappedModeClose();
    void drawModeClose();
    void baseMenuClose();

    void on_sreachButton_clicked();

    void on_simpleButton_clicked();

    void on_transferButton_clicked();

    void on_mappedButton_clicked();

    void on_drawButton_clicked();

    void on_baseButton_clicked();

private:
    Ui::MagnetMenu *ui;

    SreachMode *sreachMode; //搜索模式
//    SystemSetupMenu *systemSetupMenu;
    SimpleMenu *simpleMenu; //简单搜索 菜单
    MappedMenu *mappedMenu; //地图搜索 菜单
    DataTransferMenu *dataTransferMenu; //数据传输管理 菜单

    DrawMenu *drawMenu;//绘图调查模式
    BaseMenu *baseMenu;//基准站模式

  //  TimeEditDialog *timeEdit;
    transferDialog *transferdialog;

    double memoryUsed;
};

#endif // MAGNETMENU_H
