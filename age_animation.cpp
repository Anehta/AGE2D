#include "age_animation.h"
#include <qdebug.h>
AGE_Animation::AGE_Animation(QString name)
{
	this->name=name;
    //qDebug()<<"the animation name is "<<name;
}

void AGE_Animation::addFrame(AGE_Frame frame)
{
	this->m_list.push_back (frame);
    //qDebug()<<"new frame is add to "<<name<<"bottom left"<<frame.bottomLeft ()<<"top right"<<frame.topRight ();
}

QString AGE_Animation::getName()
{
	return name;
}

int AGE_Animation::totalFrames()
{
	return this->m_list.size ();
}

AGE_Frame AGE_Animation::getFrame(int index)
{
	return this->m_list[index];
}
