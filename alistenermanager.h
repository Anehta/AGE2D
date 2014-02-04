#ifndef ALISTENERMANAGER_H
#define ALISTENERMANAGER_H
#include <list>

class ABaseListener;
class AScene;
class QMouseEvent;

class AListenerManager
{
public:
    AListenerManager();
    void addListener(ABaseListener *);
    friend class AGE2DWidget;
    std::list<ABaseListener *> * getList();
protected:
    virtual void run();
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void keyPressEvent();
private:
    std::list<ABaseListener *> listenerList;
};

#endif // ALISTENERMANAGER_H
