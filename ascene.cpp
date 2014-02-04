#include "ascene.h"
#include <alayer.h>
#include <amainattribute.h>

using namespace std;


AScene::AScene()
{
    m_listenerManager = NULL;
    addLayer(new ALayer()); //default layer,the id is 1
}

void AScene::activate()
{
    setCurrentScene(this);
}

//add a default layer & return the handle ID
int AScene::addLayer()
{
	ALayer *layerPointer =new ALayer();
    m_layerList.push_back(layerPointer);
    return m_layerList.size ();
}


int AScene::addLayer (ALayer * pointer)
{
	m_layerList.push_back(pointer);
	return m_layerList.size ();
}

ALayer *AScene::layer(int handle)
{
	list<ALayer *> :: iterator i=m_layerList.begin ();
	int count=0;
	for(;count!=handle;++i,++count);
	return (*i);
}

void AScene::renderScene()
{
    for(list<ALayer *>::iterator alpha_it = m_layerList.begin();
        alpha_it != m_layerList.end();
        ++alpha_it)
    {
        ALayer * temp = *alpha_it;
        temp->renderLayer();
        temp->action();
    }
}

void AScene::action()
{

}

void AScene::setListenerManager(AListenerManager * listenerManager)
{
    m_listenerManager = listenerManager;
}
