#ifndef BASEDOWNMENUWIDGET_H
#define BASEDOWNMENUWIDGET_H

#include <QWidget>
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "scrollnumlistlabel.h"


namespace Ui {
class BaseDownMenuWidget;
}

class BaseDownMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseDownMenuWidget(QWidget *parent = 0);
    ~BaseDownMenuWidget();
    void setSurveyMode(int type);
    int getSurveyMode();

    int getSaveMode();
    int getBaud();

    void setNextLine(QString endX);
    void setDefaultLine();

    void setNextLabelVisable(bool flag);
    void setCycleTimeLabelVisable(bool flag);

    int getCycleTime();

public slots:
    void surveyModeChanged();
    void cycleTimeChanged();

signals:
    void startclicked();

private slots:
    void on_startButton_clicked();

private:
    Ui::BaseDownMenuWidget *ui;

    ScrollTextLabel *surveyModeDateLabel;
    ScrollNumListLabel *cycleTimeDataLabel;
    ScrollTextLabel *saveModeDateLabel;

    ScrollNumListLabel *BaudDataLabel;

    QLabel *continuous;
    QLabel *discrete;

    int surveyMode;
};

#endif // BASEDOWNMENUWIDGET_H
