#include "definemapmenu.h"
#include "ui_definemapmenu.h"
#include <QGridLayout>
#include <QHBoxLayout>

DefineMapMenu::DefineMapMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DefineMapMenu)
{
    ui->setupUi(this);

    QVector<QString> *data1 = new QVector<QString>;
    data1->append(QString::fromUtf8("双向"));
    data1->append(QString::fromUtf8("单向"));
    directionModeLabel = new ScrollTextLabel(2,data1,this);
    directionModeLabel->setScrollOver(true);
    directionModeLabel->setFocusPolicy(Qt::StrongFocus);

    LLxDataLabel = new NumEntryLabel(0.0,0.0,500.0,this);
    LLyDataLabel = new NumEntryLabel(0.0,0.0,500.0,this);
    URxDataLabel = new NumEntryLabel(100.0,0.0,500.0,this);
    URyDataLabel = new NumEntryLabel(100.0,0.0,500.0,this);

    QVector<QString> *data2 = new QVector<QString>;
    data2->append(QString::fromUtf8("Y"));
    data2->append(QString::fromUtf8("X"));
    parallelAxisLabel = new ScrollTextLabel(2,data2,this);
    parallelAxisLabel->setScrollOver(true);
    parallelAxisLabel->setFocusPolicy(Qt::StrongFocus);

    spaceLineDataLabel = new NumEntryLabel(10.0,1.0,50.0,this);
    spaceMarkDataLabel = new NumEntryLabel(10.0,1.0,50.0,this);

    QGridLayout *mainLayout = new QGridLayout(ui->centralwidget);
    mainLayout->addWidget(ui->titleLabel,0,0,1,3,Qt::AlignHCenter);

    QHBoxLayout *directionLayout = new QHBoxLayout();
    directionLayout->addWidget(directionModeLabel);
    directionLayout->addWidget(ui->directionSurveyLabel);

    mainLayout->addLayout(directionLayout,1,0,1,3,Qt::AlignHCenter);
    mainLayout->addWidget(ui->LLDisplayLabel,2,0,1,3,Qt::AlignHCenter);

    QHBoxLayout *LLdataLayout = new QHBoxLayout();
    LLdataLayout->addWidget(ui->spaceLabel,3);
    LLdataLayout->addWidget(ui->LLxDisplayLabel);
    LLdataLayout->addWidget(LLxDataLabel,2);
    LLdataLayout->addWidget(ui->LLyDisplayLabel);
    LLdataLayout->addWidget(LLyDataLabel,2);
    LLdataLayout->addWidget(ui->spaceLabel2,3);

    mainLayout->addLayout(LLdataLayout,3,1,1,1);
    mainLayout->addWidget(ui->URDisplayLabel,4,0,1,3,Qt::AlignHCenter);

    QHBoxLayout *URdataLayout = new QHBoxLayout();
    URdataLayout->addWidget(ui->spaceLabel3,3);
    URdataLayout->addWidget(ui->URxDisplayLabel);
    URdataLayout->addWidget(URxDataLabel,2);
    URdataLayout->addWidget(ui->URyDisplayLabel);
    URdataLayout->addWidget(URyDataLabel,2);
    URdataLayout->addWidget(ui->spaceLabel4,3);

    mainLayout->addLayout(URdataLayout,5,1,1,1);

    QHBoxLayout *parallelLayout = new QHBoxLayout();
    parallelLayout->addWidget(ui->parallelDisplayLabel);
    parallelLayout->addWidget(parallelAxisLabel);
    parallelLayout->addWidget(ui->parallelAxisDisplayLabel);

    mainLayout->addLayout(parallelLayout,6,0,1,3,Qt::AlignHCenter);

    QHBoxLayout *spaceLineLayout = new QHBoxLayout();
    spaceLineLayout->addWidget(ui->spaceLabel5,3);
    spaceLineLayout->addWidget(ui->spaceLineDisplayLabel);
    spaceLineLayout->addWidget(spaceLineDataLabel,2);
    spaceLineLayout->addWidget(ui->spaceLabel6,3);

    mainLayout->addLayout(spaceLineLayout,7,0,1,3,Qt::AlignHCenter);

    QHBoxLayout *spaceMarkLayout = new QHBoxLayout();
    spaceMarkLayout->addWidget(ui->spaceLabel7,3);
    spaceMarkLayout->addWidget(ui->spaceMarkDisplayLabel);
    spaceMarkLayout->addWidget(spaceMarkDataLabel,2);
    spaceMarkLayout->addWidget(ui->spaceLabel8,3);

    mainLayout->addLayout(spaceMarkLayout,8,0,1,3,Qt::AlignHCenter);
    mainLayout->addWidget(ui->doneEnteringInfoButton,9,1,1,1,Qt::AlignHCenter);
    mainLayout->addWidget(ui->currentTime,10,0,1,3,Qt::AlignLeft);


    setText();
}

DefineMapMenu::~DefineMapMenu()
{
    delete ui;
}

void DefineMapMenu::format()
{
    LLxDataLabel->setValue(0.0);
    LLyDataLabel->setValue(0.0);
    URxDataLabel->setValue(100.0);
    URyDataLabel->setValue(100.0);
    spaceLineDataLabel->setValue(2.0);
    spaceMarkDataLabel->setValue(20.0);
    directionModeLabel->setValue(1);
    parallelAxisLabel->setValue(1);
}

int DefineMapMenu::getDirectionMode()
{
    return directionModeLabel->getValue();
}

int DefineMapMenu::getParallelAxis()
{
    return parallelAxisLabel->getValue();
}

double DefineMapMenu::getLLxData()
{
    return LLxDataLabel->getValue();
}

double DefineMapMenu::getLLyData()
{
    return LLyDataLabel->getValue();
}

double DefineMapMenu::getURxData()
{
    return URxDataLabel->getValue();
}

double DefineMapMenu::getURyData()
{
    return URyDataLabel->getValue();
}

double DefineMapMenu::getSpaceLineData()
{
    return spaceLineDataLabel->getValue();
}

double DefineMapMenu::getSpaceMarkData()
{
    return spaceMarkDataLabel->getValue();
}

void DefineMapMenu::setText()
{
    ui->titleLabel->setText(QString::fromUtf8("地图设置菜单"));
    ui->directionSurveyLabel->setText(QString::fromUtf8("调查"));
    ui->LLDisplayLabel->setText(QString::fromUtf8("起始点位置："));
    ui->URDisplayLabel->setText(QString::fromUtf8("结束点位置："));
    ui->parallelDisplayLabel->setText(QString::fromUtf8("调查方向： 沿"));
    ui->parallelAxisDisplayLabel->setText(QString::fromUtf8("轴"));
    ui->spaceLineDisplayLabel->setText(QString::fromUtf8("测线间距："));
    ui->spaceMarkDisplayLabel->setText(QString::fromUtf8("测点间距："));
    ui->doneEnteringInfoButton->setText(QString::fromUtf8("确定"));

    setStyleSheet("QPushButton{font-size:28px;}"
                  "QPushButton{border-radius:5px;}"
                  "QPushButton{outline:none;}"
                  "QLabel{font-size:28px;}");
}

void DefineMapMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void DefineMapMenu::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_ESC)
    {
        this->close();
    }
    else if (e->key() == KEY_UP)
    {
        this->focusPreviousChild();
    }
    else if (e->key() == KEY_DOWN)
    {
        this->focusNextChild();
    }
    else  if (e->key() == KEY_ENTER)
    {
        QWidget *focus_w = this->focusWidget();
        if (!focus_w)
        {
            return;
        }
        QPushButton *btn = qobject_cast<QPushButton*>(focus_w);
        if (btn)
        {
            btn->click();
        }
    }
    else
    {

    }
}

void DefineMapMenu::on_doneEnteringInfoButton_clicked()
{
    this->close();
    update=true;
}

void DefineMapMenu::defineMenuShow()
{
    update=false;
}
