#include "../include/age_layer.h"
#include <stdlib.h>
using namespace std;
namespace AGE2D{
ALayer::ALayer()
{
	this->m_type=LAYER_ENTITY;
	this->m_parent=NULL;
}

ALayer::ALayer(ASprite *spritePointer)
{
	this->m_type=LAYER_ENTITY;
	this->m_parent=NULL;
    addChild(spritePointer);
}

void ALayer::addChild(ASprite *spritePointer)
{
	AScene *scene =m_parent;
    if(m_parent)
	{
		scene->insertBaseEntity (spritePointer);
		spritePointer->m_parent=this;
        m_spriteList.push_back(spritePointer);
	}
}

void ALayer::setName(string new_name)
{
	if(m_parent)
	{
		AScene *scene=m_parent;
		scene->updateBaseEntity (this->name (),new_name);
	}
    this->identity_name=new_name;
}

AScene *ALayer::parent()
{
	return m_parent;
}

void ALayer::renderLayer()
{
    for(list<ASprite*>::iterator alpha_it = m_spriteList.begin();
	alpha_it != m_spriteList.end();)
    {
	if((*alpha_it)->isDeath == true)
	{
        ASprite *temp = *alpha_it;
        temp->release();
        delete temp;
	    alpha_it = m_spriteList.erase(alpha_it);
	}
	else
	{
	    ASprite * temp = *alpha_it;
	    temp->action();
	    temp->render();
	    alpha_it++;
	}
    }

    //qDebug()<<m_spriteList.size();
}

void ALayer::action()
{

}

}
