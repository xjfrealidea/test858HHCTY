#ifndef SYSTEMDETAIL_H
#define SYSTEMDETAIL_H
#include <QObject>

typedef struct detail
{
    short masterVolume;
    short wooweeVolume;
    int wooweeSensitivity;
    int qcVolume;
    float qcLevel;
    short fullScale;
    short rdngsScreen;
    float cycleTime;
}DETAIL;


class SystemDetail : public QObject
{
    Q_OBJECT
public:
    static SystemDetail &instance();
    DETAIL &getDetail();

    void changeMasterVolume(short change);
    void changeWooweeVolume(short change);
    void changeWooweeSensitivity(int change);
    void changeQcVolume(int change);
    void changeQcLevel(double change);
    void changeFullScale(int change);
    void changeRdngsScreen(int change);
    void changeCycleTime(double change);

    static void setMasterVolume(int value);
    static void setWooweeVolume(int value);
    static void setWooweeSensitivity(int value);
    static void setQcVolume(int value);
    static void setQcLevel(double value);
    static void setFullScale(int value);
    static void setRdngsScreen(int value);
    static void setCycleTime(double value);

signals:
    void fullScaleChanged();

private:
    SystemDetail(QObject *parent = 0);

    DETAIL detail;
};

#endif // SYSTEMDETAIL_H
