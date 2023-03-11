#ifndef ADJUSTMENU_H
#define ADJUSTMENU_H

#include <QWidget>
#include "scrollnumlabel.h"
#include "numentrylabel.h"
#include "scrollnumlistlabel.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include "mainfrm.h"

namespace Ui {
class AdjustMenu;
}

class AdjustMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdjustMenu(int type, QWidget *parent = 0);
    ~AdjustMenu();

    void init();

    void setDetail();

    void setDisplay(MainFrm *display);
    void setMenuFocus();

Q_SIGNALS:
    void menuClose();
    void editLineMarkLabelClicked();
    void centerTraceLabelClicked();

    void masterVolumeChanged(int);
    void wooweeVolumeChanged(int);
    void wooweeLevelChanged(int);
    void xScaleChanged(int);
    void yScaleChanged(int);

public slots:

private slots:
    void masterVolumeChanged();
    void wooweeVolumeChanged();
    void wooweeLevelChanged();
    void xScaleChanged();
    void yScaleChanged();

    void onEditLineMarkButtonClicked();
    void onResetScaleButtonClicked();

private:
    Ui::AdjustMenu *ui;

    int menuType;
    ScrollNumLabel *masterVolumeLabel;
    ScrollNumLabel *wooweeVolumeLabel;
    ScrollNumLabel *wooweeLevelLabel;
    ScrollNumListLabel *xScaleLabel;
    ScrollNumListLabel *yScaleLabel;
    NumEntryLabel *cycleTimeDataLabel;

    QPushButton *resetScaleButton;
    QPushButton *editLineMarkButton;

    MainFrm *display;

    bool format;
};

#endif // ADJUSTMENU_H
