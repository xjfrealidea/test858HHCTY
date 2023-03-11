#include "basedownmenuwidget.h"
#include "ui_basedownmenuwidget.h"
#include <QVector>
#define EMPTY 0
#define CONTINUOUS 1
#define DISCRETE 2
#define MAPPEDMENU 3
BaseDownMenuWidget::BaseDownMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseDownMenuWidget)
{
    ui->setupUi(this);

    QVector<QString> *data = new QVector<QString>;
    data->append(QString::fromUtf8("连 续"));
    data->append(QString::fromUtf8("外触发"));
    surveyModeDateLabel = new ScrollTextLabel(2,data,this);
    surveyModeDateLabel->setScrollOver(true);
    surveyModeDateLabel->setFocusPolicy(Qt::StrongFocus);
    surveyModeDateLabel->setVisible(false);
    connect(surveyModeDateLabel,SIGNAL(textChanged()),
            this,SLOT(surveyModeChanged()));
    surveyModeDateLabel->move(ui->surveyModeLabel->x()+ui->surveyModeLabel->width(),ui->surveyModeLabel->y());

    QVector<QString> *data1 = new QVector<QString>;
    data1->append(QString::fromUtf8("仅本地保存"));
    data1->append(QString::fromUtf8("仅发送至PC"));
    data1->append(QString::fromUtf8("本地保存且发送至PC"));
    saveModeDateLabel = new ScrollTextLabel(3,data,this);
    saveModeDateLabel->setScrollOver(true);
    saveModeDateLabel->setFocusPolicy(Qt::StrongFocus);
    saveModeDateLabel->setVisible(false);
    connect(saveModeDateLabel,SIGNAL(textChanged()),
            this,SLOT(surveyModeChanged()));
    saveModeDateLabel->move(ui->surveyModeLabel->x()+ui->surveyModeLabel->width(),ui->saveModeLabel->y());

    QVector<double> *cycleVec = new QVector<double>;
    cycleVec->push_back(1.0);
    cycleVec->push_back(5.0);
    cycleVec->push_back(10.0);
    cycleVec->push_back(20.0);
    cycleVec->push_back(50.0);
    cycleVec->push_back(100.0);
    cycleTimeDataLabel = new ScrollNumListLabel(6,cycleVec,this);
    cycleTimeDataLabel->setFocusPolicy(Qt::StrongFocus);
    cycleTimeDataLabel->move(surveyModeDateLabel->x(),ui->cycleTimeLabel->y());
    ui->cycleTimeUnitLabel->move(cycleTimeDataLabel->x()+(1.5*cycleTimeDataLabel->width()),ui->cycleTimeLabel->y());
    connect(cycleTimeDataLabel,SIGNAL(textChanged()),
            this,SLOT(cycleTimeChanged()));

    QVector<double> *baudValue = new QVector<double>;
    baudValue->push_back(9600);
    baudValue->push_back(115200);
    BaudDataLabel = new ScrollNumListLabel(2,baudValue,this);
    BaudDataLabel->setFocusPolicy(Qt::StrongFocus);
    BaudDataLabel->move(surveyModeDateLabel->x(),ui->BaudLabel->y());

    ui->startButton->setFocusPolicy(Qt::StrongFocus);
    ui->startButton->setStyleSheet("QPushButton:focus{border: 2px solid;border-color: black;border-radius:8px;"
                                   "color:rgb(255,255,255);"
                                   "background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgb(70,70,70),stop:1 rgb(110,110,110));}"
                                   "QPushButton{outline:none;}");
    this->setTabOrder(surveyModeDateLabel,cycleTimeDataLabel);
    this->setTabOrder(cycleTimeDataLabel,ui->startButton);
}

BaseDownMenuWidget::~BaseDownMenuWidget()
{
    delete ui;
}

void BaseDownMenuWidget::setSurveyMode(int type)
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
/*
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
    }*/
}

int BaseDownMenuWidget::getSurveyMode()
{
    if (surveyMode == 0)
    {
        return surveyModeDateLabel->getValue();
    }
    return surveyMode;
}

int BaseDownMenuWidget::getSaveMode()
{
    return saveModeDateLabel->getValue();
}

int BaseDownMenuWidget::getBaud()
{
    return BaudDataLabel->getValue();
}

void BaseDownMenuWidget::setNextLine(QString endX)
{
    long y = endX.toLong() + 1;
}

void BaseDownMenuWidget::setDefaultLine()
{

}

void BaseDownMenuWidget::setNextLabelVisable(bool flag)
{

}

void BaseDownMenuWidget::setCycleTimeLabelVisable(bool flag)
{
    ui->cycleTimeLabel->setVisible(flag);
    ui->cycleTimeUnitLabel->setVisible(flag);
    this->cycleTimeDataLabel->setVisible(flag);
}

int BaseDownMenuWidget::getCycleTime()
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

void BaseDownMenuWidget::surveyModeChanged()
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

void BaseDownMenuWidget::cycleTimeChanged()
{

}

void BaseDownMenuWidget::on_startButton_clicked()
{
    emit startclicked();
}
