#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QThread *parent = 0);
    void go();
protected:
    void run();

signals:

public slots:
};

#endif // MYTHREAD_H
