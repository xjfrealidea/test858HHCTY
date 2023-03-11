#ifndef GPSINFOWEIGHT_H
#define GPSINFOWEIGHT_H

#include <QWidget>

namespace Ui {
class GpsInfoWeight;
}

class GpsInfoWeight : public QWidget
{
    Q_OBJECT

public:
    explicit GpsInfoWeight(QWidget *parent = 0);
    ~GpsInfoWeight();

    void setSolstattext();
    void setPostypetext();
    void setSolstatindex( int inx) { solstatindex = inx; setSolstattext();}
    void setPostypeindex( int inx) { postypeindex = inx; setPostypetext();}

    void setLonText(double lon);
    void setLatText(double lat);

public slots:
    void setGpsStatus( int solstatindex, int postypeindex);

private:
    Ui::GpsInfoWeight *ui;

    int solstatindex;
    int postypeindex;
};

#endif // GPSINFOWEIGHT_H
