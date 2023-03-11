#include "mythread.h"

MyThread::MyThread(QThread *parent) : QThread(parent)
{

}

void MyThread::go()
{
    run();
}

void MyThread::run()
{
    start();
//    exec();
}
