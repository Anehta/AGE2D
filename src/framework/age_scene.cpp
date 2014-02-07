#include <../include/AGE2D.h>

using namespace std;


AGE_Scene::AGE_Scene()
{
    m_listenerManager = NULL;
    addLayer(new AGE_Layer()); //default layer,the id is 1
}

void AGE_Scene::activate()
{
    setCurrentScene(this);
}

//add a default layer & return the handle ID
int AGE_Scene::addLayer()
{
	AGE_Layer *layerPointer =new AGE_Layer();
    m_layerList.push_back(layerPointer);
    return m_layerList.size ();
}


int AGE_Scene::addLayer (AGE_Layer * pointer)
{
	m_layerList.push_back(pointer);
	return m_layerList.size ();
}

AGE_Layer *AGE_Scene::layer(int handle)
{
	list<AGE_Layer *> :: iterator i=m_layerList.begin ();
    int count=1;
	for(;count!=handle;++i,++count);
	return (*i);
}

void AGE_Scene::renderScene()
{
    for(list<AGE_Layer *>::iterator alpha_it = m_layerList.begin();
        alpha_it != m_layerList.end();
        ++alpha_it)
    {
        AGE_Layer * temp = *alpha_it;
        temp->renderLayer();
        temp->action();
    }

    action();
}

void AGE_Scene::action()
{

}

void AGE_Scene::setListenerManager(AGE_EventMgr * listenerManager)
{
	m_listenerManager = listenerManager;
}

AGE_EventMgr *AGE_Scene::eventMgr()
{
	return m_listenerManager;
}
