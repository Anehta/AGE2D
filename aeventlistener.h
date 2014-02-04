#ifndef AEVENTLISTENER_H
#define AEVENTLISTENER_H

#include <abaselistener.h>
#include <QMouseEvent>

class QMouseEvent;

class AEventListener : public ABaseListener
{
public:
    AEventListener();
    friend class AListenerManager;
protected:
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void keyPressEvent();
private:
    virtual void handleListener();
};

#endif // AEVENTLISTENER_H
