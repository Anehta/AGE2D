#ifndef ALISTENERMANAGER_H
#define ALISTENERMANAGER_H
#include <list>
#include <age_framelistener.h>
#include <age_mouselistener.h>

class AGE_BaseListener;
class AGE_Scene;
class QMouseEvent;

class AGE_EventMgr
{
public:
    AGE_EventMgr();
    void addListener(AGE_BaseListener *);
    void addFrameListener(AGE_FrameListener * a);
    void addMouseListener(AGE_MouseListener * a);
    friend class AGE_Widget;
    std::list<AGE_BaseListener *> * getList();
protected:
    virtual void run();
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

    virtual void keyPressEvent();
private:
    std::list<AGE_BaseListener *> listenerList;
    std::list<AGE_MouseListener *> m_mouse_listener_list;
    std::list<AGE_FrameListener *> m_frame_listener_list;
};

#endif // ALISTENERMANAGER_H
