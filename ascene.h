#ifndef ASCENE_H
#define ASCENE_H

#include <list>

#include <abaselistener.h>

class ALayer;
class AGE2DWidget;
class AListenerManager;

class AScene
{
public:
    AScene();
    void activate(); //set it to currentscene
    int addLayer(ALayer *pointer);
    int addLayer();
    ALayer * layer(int handle);
    void setListenerManager(AListenerManager * listenerManager);
    friend class AGE2DWidget;

protected:
    virtual void action();
private:
    std::list<ALayer *>m_layerList;
    AListenerManager * m_listenerManager;
    void renderScene();
};

#endif // ASCENE_H
