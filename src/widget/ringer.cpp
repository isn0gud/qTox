#include "ringer.h"
#include "src/audio.h"

#include <QFile>


Ringer::Ringer(QObject *parent) : QObject(parent)
{
    ringing = false;
    timer = 0;

}

Ringer::~Ringer()
{
    delete timer;

}

void Ringer::start()
{
    if (timer == 0) {
        timer = new QTimer(this);
    }
    playRingSound();
    connect(timer,&QTimer::timeout, this, &Ringer::playRingSound);
    //TODO: magic value! better get length of sound sample
    timer->start(5000);

}

void Ringer::stop()
{
    if (timer != 0) {
        timer->stop();
    }
    emit stopped();
}

void Ringer::playRingSound()
{
    static QFile sndFile1(":audio/ToxicIncomingCall.pcm"); // for whatever reason this plays slower/downshifted from what any other program plays the file as... but whatever
    static QByteArray sndData1;
    if (sndData1.isEmpty())
    {
        sndFile1.open(QIODevice::ReadOnly);
        sndData1 = sndFile1.readAll();
        sndFile1.close();
    }

    Audio::playMono16Sound(sndData1);
}

