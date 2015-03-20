#include "ringer.h"
#include "src/audio.h"

#include <QFile>


Ringer::Ringer(QByteArray *sndData, QObject *parent) : QObject(parent)
{
    this->sndData = sndData;
}

Ringer::~Ringer()
{
}

void Ringer::start()
{
    Audio::playMono16Sound(*sndData, true);
}

void Ringer::stop()
{
    Audio::stopSound();
    emit stopped();
}

