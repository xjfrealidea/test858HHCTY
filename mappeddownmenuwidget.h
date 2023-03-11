#ifndef MAPPEDDOWNMENUWIDGET_H
#define MAPPEDDOWNMENUWIDGET_H

#include <QWidget>
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "scrollnumlistlabel.h"


namespace Ui {
class MappedDownMenuWidget;
}

class MappedDownMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MappedDownMenuWidget(QWidget *parent = 0);
    ~MappedDownMenuWidget();

    void setSurveyMode(int type);
    int getSurveyMode();

    void setCycleTimeLabelVisable(bool flag);

    int getCycleTime();

    void setBeginMenu(bool flag);

    void setDefaultLine();

public slots:
    void surveyModeChanged();
    void cycleTimeChanged();

signals:
    void defineclicked();
    void startclicked();

private slots:
    void on_defineButton_clicked();

    void on_startButton_clicked();

private:
    Ui::MappedDownMenuWidget *ui;

    ScrollTextLabel *surveyModeDateLabel;
    ScrollNumListLabel *cycleTimeDataLabel;

    QLabel *continuous;
    QLabel *discrete;

    int surveyMode;
};

#endif // MAPPEDDOWNMENUWIDGET_H
