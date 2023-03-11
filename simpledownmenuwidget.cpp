#include "simpledownmenuwidget.h"
#include "ui_simpledownmenuwidget.h"
#include <QVector>

SimpleDownMenuWidget::SimpleDownMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleDownMenuWidget)
{
    ui->setupUi(this);

    QVector<QString> *data = new QVector<QString>;
    data->append(QString::fromUtf8("连续模式"));
    data->append(QString::fromUtf8("离散模式"));
    surveyModeDateLabel = new ScrollTextLabel(2,data,this);
    surveyModeDateLabel->setScrollOver(true);
    surveyModeDateLabel->setFocusPolicy(Qt::StrongFocus);
    surveyModeDateLabel->setVisible(false);
    connect(surveyModeDateLabel,SIGNAL(textChanged()),
            this,SLOT(surveyModeChanged()));
    surveyModeDateLabel->move(ui->nextLineDataLabel->x(),ui->surveyModeLabel->y());

    QVector<double> *cycleVec = new QVector<double>;
    cycleVec->push_back(1.0);
    cycleVec->push_back(5.0);
    cycleVec->push_back(10.0);
    cycleVec->push_back(20.0);
    cycleVec->push_back(50.0);
    cycleVec->push_back(100.0);
    cycleTimeDataLabel = new ScrollNumListLabel(6,cycleVec,this);
    cycleTimeDataLabel->setFocusPolicy(Qt::StrongFocus);
    cycleTimeDataLabel->move(ui->nextLineDataLabel->x(),ui->cycleTimeLabel->y());
    ui->cycleTimeUnitLabel->move(cycleTimeDataLabel->x()+(1.5*cycleTimeDataLabel->width()),ui->cycleTimeLabel->y());
    connect(cycleTimeDataLabel,SIGNAL(textChanged()),
            this,SLOT(cycleTimeChanged()));

    ui->startButton->setFocusPolicy(Qt::StrongFocus);
    ui->startButton->setStyleSheet("QPushButton:focus{border: 2px solid;border-color: black;border-radius:8px;"
                                   "color:rgb(255,255,255);"
                                   "background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgb(70,70,70),stop:1 rgb(110,110,110));}"
                                   "QPushButton{outline:none;}");
    this->setTabOrder(surveyModeDateLabel,cycleTimeDataLabel);
    this->setTabOrder(cycleTimeDataLabel,ui->startButton);
}

SimpleDownMenuWidget::~SimpleDownMenuWidget()
{
    delete ui;
}

void SimpleDownMenuWidget::setSurveyMode(int type)
{
    if (type == EMPTY)
    {
        surveyModeDateLabel->setVisible(true);
        surveyModeDateLabel->setlock(false);
        surveyModeDateLabel->setValue(1);
        surveyMode = 0;
        setCycleTimeLabelVisable(true);
        cycleTimeDataLabel->setValue(6);
        ui->startButton->setText(QString::fromUtf8("开始采集"));
        ui->startButton->setEnabled(true);
        return;
    }

    if (type == CONTINUOUS)
    {
        surveyModeDateLabel->setVisible(true);
        surveyModeDateLabel->setlock(true);
        surveyModeDateLabel->setValue(1);
        surveyMode = 1;
        setCycleTimeLabelVisable(true);
        cycleTimeDataLabel->setValue(6);
        ui->startButton->setText(QString::fromUtf8("继续采集"));
        return;
    }

    if (type == DISCRETE)
    {
        surveyModeDateLabel->setVisible(true);
        surveyModeDateLabel->setlock(true);
        surveyModeDateLabel->setValue(2);
        setCycleTimeLabelVisable(false);
        surveyMode = 2;
        ui->startButton->setText(QString::fromUtf8("继续采集"));
        return;
    }

    if (type == MAPPEDMENU)
    {
        surveyModeDateLabel->setVisible(true);
        surveyModeDateLabel->setlock(true);
        surveyModeDateLabel->setValue(1);
        setCycleTimeLabelVisable(true);
        cycleTimeDataLabel->setValue(6);
        surveyMode = 1;
        ui->startButton->setText(QString::fromUtf8("开始采集"));
        return;
    }
}

int SimpleDownMenuWidget::getSurveyMode()
{
    if (surveyMode == 0)
    {
        return surveyModeDateLabel->getValue();
    }
    return surveyMode;
}

void SimpleDownMenuWidget::setNextLine(QString endX)
{
    long y = endX.toLong() + 1;
    ui->nextLineDataLabel->setText(QString::number(y));
}

void SimpleDownMenuWidget::setDefaultLine()
{
    ui->nextLineDataLabel->setText("0");
}

void SimpleDownMenuWidget::setNextLabelVisable(bool flag)
{
    ui->nextLineLabel->setVisible(flag);
    ui->nextMarkLabel->setVisible(flag);
    ui->nextLineDataLabel->setVisible(flag);
    ui->nextMarkDataLabel->setVisible(flag);
}

void SimpleDownMenuWidget::setCycleTimeLabelVisable(bool flag)
{
    ui->cycleTimeLabel->setVisible(flag);
    ui->cycleTimeUnitLabel->setVisible(flag);
    this->cycleTimeDataLabel->setVisible(flag);
}

int SimpleDownMenuWidget::getCycleTime()
{
    if (surveyModeDateLabel->getValue() == 1)//连续
    {
        return cycleTimeDataLabel->getValue();
    }
    else//离散
    {
        return 100;
    }
}

void SimpleDownMenuWidget::surveyModeChanged()
{
    int ret = surveyModeDateLabel->getValue();
    if (1 == ret)
    {
        setCycleTimeLabelVisable(true);
    }
    else
    {
        setCycleTimeLabelVisable(false);
    }
}

void SimpleDownMenuWidget::cycleTimeChanged()
{

}

void SimpleDownMenuWidget::on_startButton_clicked()
{
    emit startclicked();
}
