#include "mappeddownmenuwidget.h"
#include "ui_mappeddownmenuwidget.h"
#include <QVector>
#define EMPTY 0
#define CONTINUOUS 1
#define DISCRETE 2
#define MAPPEDMENU 3
#define DRAW 4
#define BASE 5

MappedDownMenuWidget::MappedDownMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MappedDownMenuWidget)
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
    surveyModeDateLabel->move(ui->surveyModeLabel->x()+ui->surveyModeLabel->width(),ui->surveyModeLabel->y());

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

    ui->defineButton->setText(QString::fromUtf8("地图设置"));

    ui->defineButton->setFocusPolicy(Qt::StrongFocus);
    ui->defineButton->setStyleSheet("QPushButton:focus{border: 2px solid;border-color: black;border-radius:8px;"
                                   "color:rgb(255,255,255);"
                                   "background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgb(70,70,70),stop:1 rgb(110,110,110));}"
                                   "QPushButton{outline:none;}");
    ui->startButton->setFocusPolicy(Qt::StrongFocus);
    ui->startButton->setStyleSheet("QPushButton:focus{border: 2px solid;border-color: black;border-radius:8px;"
                                   "color:rgb(255,255,255);"
                                   "background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgb(70,70,70),stop:1 rgb(110,110,110));}"
                                   "QPushButton{outline:none;}");

    //setBeginMenu(false);
    setTabOrder(surveyModeDateLabel,ui->defineButton);
    setTabOrder(ui->defineButton,ui->startButton);



    ui->atLabel->setVisible(false);
    ui->xLabel->setVisible(false);
    ui->yLabel->setVisible(false);
    ui->goingLabel->setVisible(false);

}

MappedDownMenuWidget::~MappedDownMenuWidget()
{
    delete ui;
}

void MappedDownMenuWidget::setSurveyMode(int type)
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

    this->setVisible(false);
//    surveyModeDateLabel->setVisible(false);
//    setCycleTimeLabelVisable(false);

//    if (type == DRAW)
//    {
//        surveyModeDateLabel->setVisible(true);
//        surveyModeDateLabel->setlock(true);
//        surveyModeDateLabel->setValue(1);
//        surveyMode = 1;
//        setCycleTimeLabelVisable(true);
//        cycleTimeDataLabel->setValue(1);
//        ui->startButton->setText(QString::fromUtf8("继续采集"));
//        return;
//    }
}

int MappedDownMenuWidget::getSurveyMode()
{
    if (surveyMode == 0)
    {
        return surveyModeDateLabel->getValue();
    }
    return surveyMode;
}

void MappedDownMenuWidget::setCycleTimeLabelVisable(bool flag)
{
    ui->cycleTimeLabel->setVisible(flag);
    ui->cycleTimeUnitLabel->setVisible(flag);
    this->cycleTimeDataLabel->setVisible(flag);
}

int MappedDownMenuWidget::getCycleTime()
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

void MappedDownMenuWidget::setBeginMenu(bool flag)
{
    ui->startButton->setVisible(flag);
//    ui->atLabel->setVisible(flag);
//    ui->xLabel->setVisible(flag);
//    ui->yLabel->setVisible(flag);
//    ui->goingLabel->setVisible(flag);

}

void MappedDownMenuWidget::setDefaultLine()
{

}

void MappedDownMenuWidget::surveyModeChanged()
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

void MappedDownMenuWidget::cycleTimeChanged()
{

}

void MappedDownMenuWidget::on_defineButton_clicked()
{
    emit defineclicked();
}

void MappedDownMenuWidget::on_startButton_clicked()
{
    emit startclicked();
}
