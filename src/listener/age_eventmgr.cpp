#include "../include/age_eventmgr.h"
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
using namespace std;

namespace  AGE2D {
AGE_EventMgr::AGE_EventMgr()
{

}

void AGE_EventMgr::addListener(AGE_BaseListener * baseListener)
{
    AGE_BaseListener* p =dynamic_cast<AGE_BaseListener*>(baseListener);
    if(p != NULL)
	listenerList.push_back(p);
    qDebug()<<"addListener";
}

void AGE_EventMgr::addFrameListener(AGE_FrameListener *a)
{
	AGE_FrameListener* p =dynamic_cast<AGE_FrameListener*>(a);
	if(p != NULL)
		m_frame_listener_list.push_back(p);
}

void AGE_EventMgr::addMouseListener(AGE_MouseListener *a)
{
	AGE_MouseListener* p =dynamic_cast<AGE_MouseListener*>(a);
	if(p != NULL)
		m_mouse_listener_list.push_back(p);


}

void AGE_EventMgr::addKeyListener(AGE_KeyListener *a)
{
	AGE_KeyListener* p =dynamic_cast<AGE_KeyListener*>(a);
	if(p != NULL)
		m_key_listener_list.push_back(p);
}



void AGE_EventMgr::run()
{
    for(list<AGE_BaseListener *>::iterator alpha_it = listenerList.begin();
	alpha_it != listenerList.end();
	++alpha_it)
    {
	AGE_BaseListener * temp = * alpha_it;
	temp->handleListener();
    }
}

void AGE_EventMgr::mouseMoveEvent(QMouseEvent *mouse)
{

    for(list<AGE_MouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	alpha_it != m_mouse_listener_list.end();
	++alpha_it)
    {
	AGE_MouseListener *  temp = * alpha_it;
	AGE_MouseInfo info;
    info.setMouseX (mouse->x()/*-AGE_System::GetWidthOffset()*/);
    info.setMouseY (AGE_System::GetHeight ()-mouse->y()/*+AGE_System::GetHeightOffset()*/);
	temp->onMouseMove(info);
    }
}

void AGE_EventMgr::mousePressEvent(QMouseEvent *mouse)
{
	for(list<AGE_MouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	    alpha_it != m_mouse_listener_list.end();
	    ++alpha_it)
	{
	    AGE_MouseListener *  temp = * alpha_it;
	    AGE_MouseInfo info;
	    info.setMouseX (mouse->x());
	    info.setMouseY (AGE_System::GetHeight ()-mouse->y());
	    qDebug()<<info.getMouseY ();
	    temp->onMousePress(info);
	}
}

void AGE_EventMgr::mouseReleaseEvent(QMouseEvent *mouse)
{
	for(list<AGE_MouseListener *>::iterator alpha_it = m_mouse_listener_list.begin();
	    alpha_it != m_mouse_listener_list.end();
	    ++alpha_it)
	{
	    AGE_MouseListener *  temp = * alpha_it;
	    AGE_MouseInfo info;
	info.setMouseX (mouse->x());
	info.setMouseY (AGE_System::GetHeight() -mouse->y());
	    temp->onMouseRelease(info);
	}
}

void AGE_EventMgr::keyReleaseEvent(QKeyEvent *a)
{
	for(list<AGE_KeyListener *>::iterator alpha_it = m_key_listener_list.begin();
	    alpha_it != m_key_listener_list.end();
	    ++alpha_it)
	{
	    AGE_KeyListener *  temp = * alpha_it;
	    temp->onKeyRelease (a);
	}
}


void AGE_EventMgr::keyPressEvent(QKeyEvent * a)
{
	for(list<AGE_KeyListener *>::iterator alpha_it = m_key_listener_list.begin();
	    alpha_it != m_key_listener_list.end();
	    ++alpha_it)
	{
		AGE_KeyListener *  temp = * alpha_it;
		temp->onKeyPress (a);
	}
}

std::list<AGE_BaseListener *> * AGE_EventMgr::getList()
{
    return &listenerList;
}

}
