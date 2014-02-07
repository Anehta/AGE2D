#include <../include/AGE2D.h>
using namespace std;

AGE_Layer::AGE_Layer()
{

}

AGE_Layer::AGE_Layer(AGE_Sprite *spritePointer)
{
    addChild(spritePointer);
}

void AGE_Layer::addChild(AGE_Sprite *spritePointer)
{
    m_spriteList.push_back(spritePointer);
}

void AGE_Layer::renderLayer()
{
    for(list<AGE_Sprite*>::iterator alpha_it = m_spriteList.begin();
        alpha_it != m_spriteList.end();)
    {
        if((*alpha_it)->isDeath == true)
        {
            delete (*alpha_it);
            alpha_it = m_spriteList.erase(alpha_it);
        }
        else
        {
            AGE_Sprite * temp = *alpha_it;
            temp->action();
            temp->render();
            alpha_it++;
        }
    }
   // qDebug()<<m_spriteList.size();
}

void AGE_Layer::action()
{

}
