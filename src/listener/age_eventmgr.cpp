#include "../include/age_eventmgr.h"
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
using namespace std;

namespace  AGE2D {
AEventMgr::AEventMgr()
{

}

void AEventMgr::addListener(ABaseListener * baseListener)
{
    ABaseListener* p =dynamic_cast<ABaseListener*>(baseListener);
    if(p != NULL)
	listenerList.push_back(p);
    qDebug()<<"addListener";
}

void AEventMgr::addFrameListener(AFrameListener *a)
{
	AFrameListener* p =dynamic_cast<AFrameListener*>(a);
	if(p != NULL)
		m_frame_listener_list.push_back(p);
}

void AEventMgr::addMouseListener(AMouseListener *a)
{
	AMouseListener* p =dynamic_cast<AMouseListener*>(a);
	if(p != NULL)
		m_mouse_listener_list.push_back(p);


}

void AEventMgr::addKeyListener(AKeyListener *a)
{
	AKeyListener* p =dynamic_cast<AKeyListener*>(a);
	if(p != NULL)
		m_key_listener_list.push_back(p);
}



void AEventMgr::run()
{
    for(list<ABaseListener *>::iterator alpha_it = listenerList.begin();
	alpha_it != listenerList.end();
	++alpha_it)
    {
	ABaseListener * temp = * alpha_it;
	temp->handleListener();
    }
}

void AEventMgr::mouseMoveEvent(QMouseEvent *mouse)
{

    for(list<AMouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	alpha_it != m_mouse_listener_list.end();
	++alpha_it)
    {
	AMouseListener *  temp = * alpha_it;
	AMouseInfo info;
    info.setMouseX (mouse->x()/*-ASystem::GetWidthOffset()*/);
    info.setMouseY (ASystem::GetHeight ()-mouse->y()/*+ASystem::GetHeightOffset()*/);
	temp->onMouseMove(info);
    }
}

void AEventMgr::mousePressEvent(QMouseEvent *mouse)
{
	for(list<AMouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	    alpha_it != m_mouse_listener_list.end();
	    ++alpha_it)
	{
	    AMouseListener *  temp = * alpha_it;
	    AMouseInfo info;
	    info.setMouseX (mouse->x());
	    info.setMouseY (ASystem::GetHeight ()-mouse->y());
	    qDebug()<<info.getMouseY ();
	    temp->onMousePress(info);
	}
}

void AEventMgr::mouseReleaseEvent(QMouseEvent *mouse)
{
	for(list<AMouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	    alpha_it != m_mouse_listener_list.end();
	    ++alpha_it)
	{
	    AMouseListener *  temp = * alpha_it;
	    AMouseInfo info;
	info.setMouseX (mouse->x());
	info.setMouseY (ASystem::GetHeight() -mouse->y());
	    temp->onMouseRelease(info);
	}
}

void AEventMgr::keyReleaseEvent(QKeyEvent *a)
{
	for(list<AKeyListener *>::iterator alpha_it = m_key_listener_list.begin();
	    alpha_it != m_key_listener_list.end();
	    ++alpha_it)
	{
	    AKeyListener *  temp = * alpha_it;
	    temp->onKeyRelease (a);
	}
}


void AEventMgr::keyPressEvent(QKeyEvent * a)
{
	for(list<AKeyListener *>::iterator alpha_it = m_key_listener_list.begin();
	    alpha_it != m_key_listener_list.end();
	    ++alpha_it)
	{
		AKeyListener *  temp = * alpha_it;
		temp->onKeyPress (a);
	}
}

std::list<ABaseListener *> * AEventMgr::getList()
{
    return &listenerList;
}

}
