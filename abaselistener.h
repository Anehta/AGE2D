#ifndef ABASELISTENER_H
#define ABASELISTENER_H

class AListenerManager;
class QMouseEvent;
class ABaseListener
{
public:
    ABaseListener();
    friend class AListenerManager;
    friend class AGE2DWidget;
protected:
    void handleListener();
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void keyPressEvent();
private:
};

#endif // ABASELISTENER_H
