#include "GpsInfoWeight.h"
#include "ui_GpsInfoWeight.h"
#include <QGridLayout>
GpsInfoWeight::GpsInfoWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GpsInfoWeight)
{
    ui->setupUi(this);

    ui->solstatlabel->setText(QString::fromUtf8("sol解状态:"));
    ui->postypelabel->setText(QString::fromUtf8("定位或定速类型:"));

    ui->solstatlabel->setVisible(false);
    ui->solstattext->setVisible(false);

    solstatindex = -1;
    postypeindex = -1;

    QGridLayout *mainLayout = new QGridLayout(this);

  //  mainLayout->addWidget(ui->solstatlabel,0,0,1,1);
  //  mainLayout->addWidget(ui->solstattext,0,1,2,2);
  //  mainLayout->addWidget(ui->spacelabel1,1,0,1,1);
    mainLayout->addWidget(ui->lonlabel,0,0,1,1);
  //  mainLayout->addWidget(ui->lontext,0,1,1,2);
    mainLayout->addWidget(ui->latlabel,1,0,1,1);
  //  mainLayout->addWidget(ui->lattext,1,1,1,2);
    mainLayout->addWidget(ui->postypelabel,2,0,1,1);
    mainLayout->addWidget(ui->postypetext,3,0,1,1);
  //  mainLayout->addWidget(ui->spacelabel2,3,0,1,1);
    ui->lontext->setVisible(false);
    ui->lattext->setVisible(false);
    ui->spacelabel1->setVisible(false);
    ui->spacelabel2->setVisible(false);

    ui->lonlabel->setText(QString::fromUtf8("经度:"));
    ui->latlabel->setText(QString::fromUtf8("纬度:"));
    ui->lonlabel->setVisible(false);
    ui->latlabel->setVisible(false);
}

GpsInfoWeight::~GpsInfoWeight()
{
    delete ui;
}

void GpsInfoWeight::setSolstattext()
{
    QString str = "";
    switch(solstatindex)
    {
    case 0:
        str = QString::fromUtf8("已解算");
        break;
    case 1:
        str = QString::fromUtf8("观测不足");
        break;
    case 2:
        str = QString::fromUtf8("未收敛");
        break;
    case 3:
        str = QString::fromUtf8("参数矩阵异常");
        break;
    case 4:
        str = QString::fromUtf8("协方差跟踪超距离(>1000米)");
        break;
    case 5:
        str = QString::fromUtf8("测试距离超限(3次距离>10km)");
        break;
    case 6:
        str = QString::fromUtf8("自冷启动后未收敛");
        break;
    case 7:
        str = QString::fromUtf8("高程或速度超限");
        break;
    case 8:
        str = QString::fromUtf8("方差超限");
        break;
    case 9:
        str = QString::fromUtf8("残差过大");
        break;
    case 13:
        str = QString::fromUtf8("大残差导致定位不可靠");
        break;
    case 18:
        str = QString::fromUtf8("输入FIX POSITION命令后固定解等待中");
        break;
    case 19:
        str = QString::fromUtf8("输入FIX POSITION命令后固定解无效");
        break;
    case 20:
        str = QString::fromUtf8("未授权");
        break;
    case 99:
        str = QString::fromUtf8("");
        break;
    default:
        str = QString::fromUtf8("无效状态码");
        break;
    }
    ui->solstattext->setText(str);
}

void GpsInfoWeight::setPostypetext()
{
    QString str = "";
    switch(postypeindex)
    {
    case 0:
        str = QString::fromUtf8("无解");
        break;
    case 1:
        str = QString::fromUtf8("FIX POSITION命令后位置固定");
        break;
    case 2:
        str = QString::fromUtf8("FIX HEIGHT/AUTO命令后位置固定");
        break;
    case 8:
        str = QString::fromUtf8("瞬时多普勒解算速度");
        break;
    case 16:
        str = QString::fromUtf8("单点解");
        break;
    case 17:
        str = QString::fromUtf8("伪距差分解");
        break;
    case 18:
        str = QString::fromUtf8("经WAAS修正数据的解算值");
        break;
    case 19:
        str = QString::fromUtf8("无新观测值下卡尔曼滤波预测");
        break;
    case 20:
        str = QString::fromUtf8("OMNISTAR VBS位置");
        break;
    case 32:
        str = QString::fromUtf8("浮动L1模糊解");
        break;
    case 33:
        str = QString::fromUtf8("浮动无电离层模糊解");
        break;
    case 34:
        str = QString::fromUtf8("浮动窄带模糊解");
        break;
    case 48:
        str = QString::fromUtf8("整周L1模糊解");
        break;
    case 50:
        str = QString::fromUtf8("整周窄带模糊解");
        break;
    case 64:
        str = QString::fromUtf8("OmniSTAR HP位置");
        break;
    case 65:
        str = QString::fromUtf8("OmniSTAR XP或G2位置");
        break;
    case 68:
        str = QString::fromUtf8("TerraStar-C解算正在收敛中");
        break;
    case 69:
        str = QString::fromUtf8("TerraStar-C解算收敛");
        break;
    case 70:
        str = QString::fromUtf8("解算精度在UAL操作极限内");
        break;
    case 71:
        str = QString::fromUtf8("解算精度超出UAL操作极限，但仍在警告线内");
        break;
    case 72:
        str = QString::fromUtf8("解算精度超出UAL极限");
        break;
    case 77:
        str = QString::fromUtf8("TerraStar-L解正在收敛中");
        break;
    case 78:
        str = QString::fromUtf8("TerraStar-L解收敛");
        break;
/*    case 0:
        str = QString::fromUtf8("定位不可用或无效");
        break;
    case 1:
        str = QString::fromUtf8("单点定位");
        break;
    case 2:
        str = QString::fromUtf8("伪距差分或SBAS定位");
        break;
    case 4:
        str = QString::fromUtf8("RTK固定解");
        break;
    case 5:
        str = QString::fromUtf8("RTK浮点解");
        break;
    case 6:
        str = QString::fromUtf8("惯导定位");
        break;
    case 7:
        str = QString::fromUtf8("用户设定位置");
        break;*/
    default:
        str = QString::fromUtf8("无效状态码");
        break;
    }
    ui->postypetext->setText(str);
}

void GpsInfoWeight::setLonText(double lon)
{
    ui->lontext->setText(QString::number(lon,'f',6));
}

void GpsInfoWeight::setLatText(double lat)
{
    ui->lattext->setText(QString::number(lat,'f',6));
}

void GpsInfoWeight::setGpsStatus( int solstatindex,  int postypeindex)
{
    setSolstatindex(solstatindex);
    setPostypeindex(postypeindex);
}
