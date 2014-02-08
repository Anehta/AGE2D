#include "../include/age_audio.h"

AGE_Audio::AGE_Audio(QString audName)
{
    Init();
    this->audName = audName;
    audio();
}

AGE_Audio::AGE_Audio(QString audName,int mods)
{
    Init();
    this->mods = mods;
    this->audName = audName;
    audio();
}

void AGE_Audio::audio()
{
    if(mods == 0)
    {
        QFile f(this->audName);
        f.copy(QDir::currentPath()+"/"+this->audName.remove(":/"));
        this->medialist->addMedia(QUrl::fromLocalFile(QDir::currentPath()+"/"+this->audName.remove(":/")));
    }
    else
    {
        this->medialist->addMedia(QUrl(this->audName));
    }
    this->medialist->setCurrentIndex(1);
    this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    this->music->setPlaylist(medialist);
}

void AGE_Audio::play()
{
    music->play();
}

void AGE_Audio::stop()
{
    music->stop();
}

void AGE_Audio::pause()
{
    music->pause();
}

void AGE_Audio::setLoopORnot(bool loopORnot)
{
    this->loopORnot=loopORnot;
    if(this->loopORnot == true)
        this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    else this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
}

void AGE_Audio::setObjectName(QString objName)
{
    this->objName=objName;
    this->music->setObjectName(this->objName);
}

void AGE_Audio::setVolume(int Volume)
{
    this->Volume = Volume;
    this->music->setVolume(this->Volume);
}

QString AGE_Audio::getObjectName()
{
    return this->objName;
}

QString AGE_Audio::getAudioName()
{
    return this->audName;
}

int AGE_Audio::getVolume()
{
    return this->Volume;
}

bool AGE_Audio::getLoopORnot()
{
    return this->loopORnot;
}

AGE_Audio::~AGE_Audio()
{
    delete this->music;
    delete this->medialist;
}
