#ifndef SIMPLEDOWNMENUWIDGET_H
#define SIMPLEDOWNMENUWIDGET_H

#include <QWidget>
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "scrollnumlistlabel.h"
#define EMPTY 0
#define CONTINUOUS 1
#define DISCRETE 2
#define MAPPEDMENU 3

namespace Ui {
class SimpleDownMenuWidget;
}

class SimpleDownMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleDownMenuWidget(QWidget *parent = 0);
    ~SimpleDownMenuWidget();
    void setSurveyMode(int type);
    int getSurveyMode();

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
    Ui::SimpleDownMenuWidget *ui;

    ScrollTextLabel *surveyModeDateLabel;
    ScrollNumListLabel *cycleTimeDataLabel;

    QLabel *continuous;
    QLabel *discrete;

    int surveyMode;
};

#endif // SIMPLEDOWNMENUWIDGET_H
