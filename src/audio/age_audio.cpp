#include "../include/age_audio.h"
#include "../include/age_regexp.h"

AAudio::AAudio(QString audName)
{
    Init();
    this->audName = audName;
    audio();
}

AAudio::AAudio(QString audName,int mods)
{
    Init();
    this->mods = mods;
    this->audName = audName;
    audio();
}

void AAudio::audio()
{
    if(mods == 0)
    {

           QString pattern("(.*)/(.*.(mp3|mp4|ogg|flac|wav|ape|vqf|aac|mid|md|asf|m4a|aac|wma))");
           QFile f(this->audName);
           abcd = new ARegExp(pattern,audName);
           audName =abcd->getexitstr();
           delete abcd;
           f.copy(QDir::currentPath()+"/"+this->audName);
           this->medialist->addMedia(QUrl::fromLocalFile(QDir::currentPath()+"/"+this->audName));
       }
    else
    {
        this->medialist->addMedia(QUrl(this->audName));
    }
    this->medialist->setCurrentIndex(1);
    this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    this->music->setPlaylist(medialist);
}

void AAudio::play()
{
    music->play();
}

void AAudio::stop()
{
    music->stop();
}

void AAudio::pause()
{
    music->pause();
}

void AAudio::setLoopORnot(bool loopORnot)
{
    this->loopORnot=loopORnot;
    if(this->loopORnot == true)
        this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    else this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
}

void AAudio::setObjectName(QString objName)
{
    this->objName=objName;
    this->music->setObjectName(this->objName);
}

void AAudio::setVolume(int Volume)
{
    this->Volume = Volume;
    this->music->setVolume(this->Volume);
}

QString AAudio::getObjectName()
{
    return this->objName;
}

QString AAudio::getAudioName()
{
    return this->audName;
}

int AAudio::getVolume()
{
    return this->Volume;
}

bool AAudio::getLoopORnot()
{
    return this->loopORnot;
}

AAudio::~AAudio()
{
    delete this->music;
    delete this->medialist;
}
