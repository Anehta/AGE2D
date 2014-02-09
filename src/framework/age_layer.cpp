#include <../include/AGE2D.h>
using namespace std;
namespace AGE2D{
ALayer::ALayer()
{

}

ALayer::ALayer(ASprite *spritePointer)
{
    addChild(spritePointer);
}

void ALayer::addChild(ASprite *spritePointer)
{
    m_spriteList.push_back(spritePointer);
}

void ALayer::renderLayer()
{
    for(list<ASprite*>::iterator alpha_it = m_spriteList.begin();
	alpha_it != m_spriteList.end();)
    {
	if((*alpha_it)->isDeath == true)
	{
	    delete (*alpha_it);
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
   // qDebug()<<m_spriteList.size();
}

void ALayer::action()
{

}

}
