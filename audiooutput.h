#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H

#include <math.h>

#include <QAudioOutput>
#include <QByteArray>
#include <QIODevice>
#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QTimer>
#include <QMutex>
#include <QDebug>
#include "common.h"

class Generator : public QIODevice
{
    Q_OBJECT

public:
    Generator(const QAudioFormat &format, qint64 durationUs, int sampleRate, QObject *parent);
//    Generator();
    ~Generator();

    void start();
    void stop();

    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
    qint64 bytesAvailable() const;
    void generateData(const QAudioFormat &format, qint64 durationUs, int sampleRate);
private:


private:
    qint64 m_pos;
    QByteArray m_buffer;
    QMutex mutex;
};

class AudioOutput : public QObject
{
    Q_OBJECT

    SINGLETON(AudioOutput)

public:
    void initializeAudio();
    void createAudioOutput();

    void stopAudioOutput();

signals:

public slots:
    bool volumeChangedSlot(int value);////音量变化
    bool hzChangedSlot(int value);////基础频率变化

    void changeHz(double v);
    void resetVolume(int value);
    void resetHz(int value);

    void start();
    void stop();
    void pause();

    void onTimeOut();

private:
    QAudioDeviceInfo m_device;
    Generator *m_generator;
    QAudioOutput *m_audioOutput;
    QAudioFormat m_format;

    QByteArray m_buffer;
    QTimer *timer;

    int RateHz;
    int Seconds;
    int m_volume;
//    int hzPernT;

    bool work;

};

#endif // AUDIOOUTPUT_H
