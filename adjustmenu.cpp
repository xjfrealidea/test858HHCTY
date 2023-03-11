#include "adjustmenu.h"
#include "ui_adjustmenu.h"
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "systemdetail.h"
#include "widgetshowtype.h"
#include "macro.h"
#include <QMainWindow>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

AdjustMenu::AdjustMenu(int type, QWidget *parent) :
    QWidget(parent),
//    ui(new Ui::AdjustMenu),
    menuType(type)
{
//    ui->setupUi(this);

//    DETAIL detail = SystemDetail::instance().getDetail();

    masterVolumeLabel = new ScrollNumLabel(9,this);
    masterVolumeLabel->setAction(&(SystemDetail::setMasterVolume));
    connect(masterVolumeLabel,SIGNAL(textChanged()),
            this,SLOT(masterVolumeChanged()));

    wooweeVolumeLabel = new ScrollNumLabel(9,this);
    wooweeVolumeLabel->setAction(&(SystemDetail::setWooweeVolume));
    connect(wooweeVolumeLabel,SIGNAL(textChanged()),
            this,SLOT(wooweeVolumeChanged()));

    wooweeLevelLabel = new ScrollNumLabel(9,this);
    wooweeLevelLabel->setAction(&(SystemDetail::setWooweeSensitivity));
    connect(wooweeLevelLabel,SIGNAL(textChanged()),
            this,SLOT(wooweeLevelChanged()));

    QVector<double> *zoomList = new QVector<double>;
    zoomList->push_back(0.05);
    zoomList->push_back(0.1);
    zoomList->push_back(0.25);
    zoomList->push_back(0.5);
    zoomList->push_back(1.0);
    zoomList->push_back(1.5);
    zoomList->push_back(2.0);
    zoomList->push_back(3.0);
    zoomList->push_back(5.0);
    xScaleLabel = new ScrollNumListLabel(9,zoomList,this);
    xScaleLabel->setAction(&(SystemDetail::setRdngsScreen));
    connect(xScaleLabel,SIGNAL(textChanged()),
            this,SLOT(xScaleChanged()));

    yScaleLabel = new ScrollNumListLabel(9,zoomList,this);
    yScaleLabel->setAction(&(SystemDetail::setFullScale));
    connect(yScaleLabel,SIGNAL(textChanged()),
            this,SLOT(yScaleChanged()));

    editLineMarkButton = new QPushButton(this);
    editLineMarkButton->setText(QString::fromUtf8("测量点编辑"));
    editLineMarkButton->setStyleSheet("QPushButton:focus{background-color:red;}"
                                     "QPushButton{font-size:28px;}"
                                     "QPushButton{outline:none;}");
    connect(editLineMarkButton,SIGNAL(clicked(bool)),
            this,SLOT(onEditLineMarkButtonClicked()));

    resetScaleButton = new QPushButton(this);
    resetScaleButton->setText(QString::fromUtf8("默认坐标轴倍率"));
    resetScaleButton->setStyleSheet("QPushButton:focus{background-color:red;}"
                                     "QPushButton{font-size:28px;}"
                                     "QPushButton{outline:none;}");

    if (menuType == 1)
    {
        editLineMarkButton->setVisible(false);
    }
    else if (menuType == 2)
    {
        editLineMarkButton->setVisible(true);
    }

    init();

    display = nullptr;
}

AdjustMenu::~AdjustMenu()
{
    delete ui;
}

void AdjustMenu::setDetail()
{
    DETAIL detail = SystemDetail::instance().getDetail();

    masterVolumeLabel->formatValue(detail.masterVolume);
    wooweeVolumeLabel->formatValue(detail.wooweeVolume);
    wooweeLevelLabel->formatValue(detail.wooweeSensitivity);
    yScaleLabel->formatValue(detail.fullScale);
    xScaleLabel->formatValue(detail.rdngsScreen);
}

void AdjustMenu::setDisplay(MainFrm *display)
{
    this->display = display;
}

void AdjustMenu::setMenuFocus()
{
    this->masterVolumeLabel->setFocus();
}

void AdjustMenu::masterVolumeChanged()
{
    emit masterVolumeChanged(masterVolumeLabel->getValue());
}

void AdjustMenu::wooweeVolumeChanged()
{
    emit wooweeVolumeChanged(wooweeVolumeLabel->getValue());
}

void AdjustMenu::wooweeLevelChanged()
{
    emit wooweeLevelChanged(wooweeLevelLabel->getValue());
}

void AdjustMenu::xScaleChanged()
{
    emit xScaleChanged(xScaleLabel->getIndex());
}

void AdjustMenu::yScaleChanged()
{
    emit yScaleChanged(yScaleLabel->getIndex());
}

void AdjustMenu::onEditLineMarkButtonClicked()
{
    emit editLineMarkLabelClicked();
}

void AdjustMenu::onResetScaleButtonClicked()
{
//    emit centerTraceLabelClicked();
    display->setCenterTrace();
    xScaleLabel->formatValue(5);
    yScaleLabel->formatValue(4);
}

void AdjustMenu::init()
{
    QHBoxLayout *mastervolumeLayoutH = new QHBoxLayout();
    QLabel *label1 = new QLabel(this);
    label1->setText(QString::fromUtf8("主音量"));
    mastervolumeLayoutH->addWidget(label1,0,Qt::AlignRight);
    mastervolumeLayoutH->addWidget(masterVolumeLabel,0,Qt::AlignLeft);

    QHBoxLayout *wooweevolumeLayoutH = new QHBoxLayout();
    QLabel *label2 = new QLabel(this);
    label2->setText(QString::fromUtf8("提示音音量"));
    wooweevolumeLayoutH->addWidget(label2,1,Qt::AlignRight);
    wooweevolumeLayoutH->addWidget(wooweeVolumeLabel,1,Qt::AlignLeft);

    QHBoxLayout *wooweeLevelLayoutH = new QHBoxLayout();
    QLabel *label3 = new QLabel(this);
    label3->setText(QString::fromUtf8("提示音水平"));
    wooweeLevelLayoutH->addWidget(label3,1,Qt::AlignRight);
    wooweeLevelLayoutH->addWidget(wooweeLevelLabel,1,Qt::AlignLeft);

    QHBoxLayout *xscaleLayoutH = new QHBoxLayout();
    QLabel *label4 = new QLabel(this);
    label4->setText(QString::fromUtf8("横轴倍率"));
    xscaleLayoutH->addWidget(label4,1,Qt::AlignRight);
    xscaleLayoutH->addWidget(xScaleLabel,1,Qt::AlignLeft);

    QHBoxLayout *yscaleLayoutH = new QHBoxLayout();
    QLabel *label5 = new QLabel(this);
    label5->setText(QString::fromUtf8("纵轴倍率"));
    yscaleLayoutH->addWidget(label5,1,Qt::AlignRight);
    yscaleLayoutH->addWidget(yScaleLabel,1,Qt::AlignLeft);

    QHBoxLayout *editPointLayoutH = new QHBoxLayout();
    editPointLayoutH->addWidget(editLineMarkButton,1,Qt::AlignHCenter);

    QHBoxLayout *resetscaleLayoutH = new QHBoxLayout();
    resetscaleLayoutH->addWidget(resetScaleButton,1,Qt::AlignHCenter);

    QVBoxLayout *mainLayoutV = new QVBoxLayout();
    mainLayoutV->addStretch(1);
    mainLayoutV->addLayout(mastervolumeLayoutH);
    mainLayoutV->addStretch(1);
    mainLayoutV->addLayout(wooweevolumeLayoutH);
    mainLayoutV->addLayout(wooweeLevelLayoutH);
    mainLayoutV->addStretch(1);
    mainLayoutV->addLayout(xscaleLayoutH);
    mainLayoutV->addLayout(yscaleLayoutH);
    mainLayoutV->addStretch(1);
    mainLayoutV->addLayout(editPointLayoutH);
    mainLayoutV->addLayout(resetscaleLayoutH);

    this->setLayout(mainLayoutV);
}
