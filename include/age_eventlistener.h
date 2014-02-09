#ifndef AEVENTLISTENER_H
#define AEVENTLISTENER_H

#include <../include/age_baselistener.h>
#include <QMouseEvent>
namespace AGE2D {

class AGE_EventListener : public AGE_BaseListener
{
public:
    AGE_EventListener();
    friend class AGE_EventMgr;
protected:
    virtual void onMouseMove(QMouseEvent *);
    virtual void onMousePress(QMouseEvent *);
    virtual void onMouseRelease(QMouseEvent *);
    virtual void onKeyPress();
private:
    virtual void handleListener();
};
}


#endif // AEVENTLISTENER_H
