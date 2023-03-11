#ifndef TIMELABEL_H
#define TIMELABEL_H

#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QString>
#include <cstring>
using namespace std;

class TimeLabel : public QLabel
{
    Q_OBJECT
public:
    explicit TimeLabel(QWidget *parent = 0);

signals:

public slots:
    void setCurrentTime();
private:
    QTimer *timer;


};

#endif // TIMELABEL_H
