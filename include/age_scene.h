#ifndef ASCENE_H
#define ASCENE_H

#include <list>

#include <../include/age_baselistener.h>
#include "age_layer.h"
#include "age_widget.h"
#include "age_eventmgr.h"
namespace AGE2D
{
class AGE_Layer;
class AGE_EventMgr;
class AGE_Scene
{
public:
    AGE_Scene();
    void activate(); //set it to currentscene
    int addLayer(AGE2D::AGE_Layer *pointer);
    int addLayer();

    AGE_Layer * layer(int handle);
    void setListenerManager(AGE_EventMgr * listenerManager);
    AGE_EventMgr * eventMgr();
    friend class AGE_Widget;

protected:
    virtual void action();
private:
    std::list<AGE_Layer *>m_layerList;
    AGE_EventMgr * m_listenerManager;
    void renderScene();
};
}


#endif // ASCENE_H
