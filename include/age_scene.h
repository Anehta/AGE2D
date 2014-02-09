#ifndef ASCENE_H
#define ASCENE_H

#include <list>

#include <../include/age_baselistener.h>
#include "age_layer.h"
#include "age_widget.h"
#include "age_eventmgr.h"
namespace AGE2D
{
class ALayer;
class AEventMgr;
class AScene
{
public:
    AScene();
    void activate(); //set it to currentscene
    int addLayer(AGE2D::ALayer *pointer);
    int addLayer();

    ALayer * layer(int handle);
    void setListenerManager(AEventMgr * listenerManager);
    AEventMgr * eventMgr();
    friend class AWidget;

protected:
    virtual void action();
private:
    std::list<ALayer *>m_layerList;
    AEventMgr * m_listenerManager;
    void renderScene();
};
}


#endif // ASCENE_H
