#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <QVBoxLayout>
#include <qmath.h>
#include <qendian.h>
#include "settings.h"
#include "audiooutput.h"
#include <QDebug>

#define PUSH_MODE_LABEL "Enable push mode"
#define PULL_MODE_LABEL "Enable pull mode"
#define SUSPEND_LABEL   "Suspend playback"
#define RESUME_LABEL    "Resume playback"
#define VOLUME_LABEL    "Volume:"

const int DurationSeconds = 1;
const int DataSampleRateHz = 44100;
const int BufferSize      = 32768;

extern bool audioWork;
    int hzPernT;

AudioOutput::AudioOutput()
    :   m_device(QAudioDeviceInfo::defaultOutputDevice())
    ,   m_generator(NULL)
    ,   m_audioOutput(NULL)
    ,   m_buffer(BufferSize, 0)
{
    initializeAudio();
}

void AudioOutput::initializeAudio()
{
    audioWork = false;
    m_volume = 5;
    hzPernT = 10;

    RateHz = Settings::instance()["AUDIO/RateHz"].toInt();
    Seconds = Settings::instance()["AUDIO/Seconds"].toInt();

    RateHz = 3000;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),
            this,SLOT(onTimeOut()));

    m_format.setSampleRate(DataSampleRateHz);
    m_format.setChannelCount(1);
    m_format.setSampleSize(16);
    m_format.setCodec("audio/pcm");
    m_format.setByteOrder(QAudioFormat::LittleEndian);
    m_format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info(m_device);
    if (!info.isFormatSupported(m_format)) {
        qWarning() << "Default format not supported - trying to use nearest";
        m_format = info.nearestFormat(m_format);
    }

    m_generator = new Generator(m_format, DurationSeconds*Seconds, 1, this);
    m_audioOutput = new QAudioOutput(m_device, m_format, this);
    m_audioOutput->setVolume(qreal(m_volume*11/99.0f));

    //createAudioOutput();
//    timer->start(500);
}

void AudioOutput::createAudioOutput()
{
    if (m_generator)
    {
        work = true;
        m_generator->start();
        m_audioOutput->start(m_generator);
    }
}

void AudioOutput::stopAudioOutput()
{
    if (m_generator)
    {
        work = false;
        m_audioOutput->stop();
        //m_generator->stop();

    }
}

AudioOutput::~AudioOutput()
{
    if (m_generator != nullptr)
    {
        delete m_generator;
    }
    if (m_audioOutput != nullptr)
    {
        delete m_audioOutput;
    }
    if (timer != nullptr)
    {
        delete timer;
    }
}

bool AudioOutput::volumeChangedSlot(int value)
{
    if (!audioWork)
    {
        return false;
    }
    if (m_volume+value > -1 && m_volume+value < 10)
    {
        m_volume+=value;
    }
    else
    {
        return false;
    }
    if (m_audioOutput)
    {
        m_audioOutput->setVolume(qreal(m_volume*11/99.0f));
//        qDebug() << "setVolume " << m_volume;
        return true;
    }
    return false;
}

bool AudioOutput::hzChangedSlot(int value)
{
    if (!audioWork)
    {
        return false;
    }
    if (hzPernT+value > 0 && hzPernT+value < 10)
    {
        hzPernT+=value;
//        qDebug() << "set Hz per nT " << hzPernT;
        return true;
    }
    else
    {
        return false;
    }
}

void AudioOutput::changeHz(double v)
{
    if (false == audioWork)
    {
        return;
    }

//    m_generator->generateData(m_format, DurationSeconds*Seconds, RateHz+(int)(v*hzPernT));
    m_generator->generateData(m_format, DurationSeconds*Seconds, (int)(v*hzPernT));
}

void AudioOutput::resetVolume(int value)
{
    m_volume = value;
}

void AudioOutput::resetHz(int value)
{
    RateHz = value;
}

void AudioOutput::start()
{/*
    m_generator->generateData(m_format, DurationSeconds*Seconds, RateHz);*/
    createAudioOutput();
}

void AudioOutput::stop()
{
    stopAudioOutput();
}

void AudioOutput::pause()
{
    if (m_generator)
    {
        if (work)
        {
            stopAudioOutput();
        }
        else
        {
            createAudioOutput();
        }
    }
}

void AudioOutput::onTimeOut()
{
    if (audioWork == false)
    {
        stopAudioOutput();
    }
    else
    {
//        changeHz();
    }
}

Generator::Generator(const QAudioFormat &format,
                     qint64 durationUs,
                     int sampleRate,
                     QObject *parent)
    :   QIODevice(parent)
    ,   m_pos(0)
{
    if (format.isValid())
        generateData(format, durationUs, sampleRate);
}

Generator::~Generator()
{

}

void Generator::start()
{
    open(QIODevice::ReadOnly);
}

void Generator::stop()
{
    m_pos = 0;
    close();
}

void Generator::generateData(const QAudioFormat &format, qint64 durationUs, int sampleRate)
{
    const int channelBytes = format.sampleSize() / 8;
//    const int sampleBytes = format.channelCount() * channelBytes;
    //88200
    qint64 length = (format.sampleRate() * format.channelCount() * (format.sampleSize() / 8));

//    Q_ASSERT(length % sampleBytes == 0);
//    Q_UNUSED(sampleBytes) // suppress warning in release builds

    mutex.lock();

    int sampleIndex = 0;
//sampleRate 变化量*系数  门限 20
    double singlecycle = abs(sampleRate) / (20.0);//单周期长度
//    qDebug() << "sampleRate " << sampleRate;
//    qDebug() << "singlecycle " << singlecycle;



    int i = 1025;
    int j = (11025 / singlecycle);
    j += j%2;
    if (j < 2756)
    {
        j = 2756;
    }
    if (j > 33075)
    {
        j = 33075;
    }
//    qDebug() << "j " << j;

    m_buffer.resize((i+j)*2);
    unsigned char *ptr = reinterpret_cast<unsigned char *>(m_buffer.data());

    while (i)
    {
        const qreal x = qSin(2 * M_PI * 1000 * qreal(sampleIndex % format.sampleRate()) / format.sampleRate());
        qint16 value = static_cast<qint16>(x * 32767);
//        const qreal x = sampleRate;
//        qint16 value = static_cast<qint16>(32767);
        qToLittleEndian<qint16>(value, ptr);

        ptr += channelBytes;//
        length -= channelBytes;//
        i--;
        ++sampleIndex;
    }

    while (j)
    {
        qToLittleEndian<qint16>(0, ptr);

        ptr += channelBytes;
        length -= channelBytes;
        j--;
    }
    mutex.unlock();
}

qint64 Generator::readData(char *data, qint64 len)
{
    qint64 total = 0;
    mutex.lock();
    if (!m_buffer.isEmpty())
    {
//        while (len - total - m_buffer.size() > 0)
//        {
//            memcpy(data + total, m_buffer.constData(), m_buffer.size());
//            total += m_buffer.size();
//        }
        while (len - total > 0) {
            qint64 chunk;
            if ((m_buffer.size() - m_pos) > 0)
            {
                chunk = qMin((m_buffer.size() - m_pos), len - total);
            }
            else
            {
                chunk = len - total;
            }
            memcpy(data + total, m_buffer.constData() + m_pos, chunk);
            m_pos = (m_pos + chunk) % m_buffer.size();
            total += chunk;
        }
    }
    mutex.unlock();
    return total;

//    if (!m_buffer.isEmpty()) {
//    while (len - total > 0) {
//        const qint64 chunk = qMin((m_buffer.size() - m_pos), len - total);
//        memcpy(data + total, m_buffer.constData() + m_pos, chunk);
//        m_pos = (m_pos + chunk) % m_buffer.size();
//        total += chunk;
//    }
//    }
}

qint64 Generator::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data);
    Q_UNUSED(len);

    return 0;
}

qint64 Generator::bytesAvailable() const
{
    return m_buffer.size() + QIODevice::bytesAvailable();
}
