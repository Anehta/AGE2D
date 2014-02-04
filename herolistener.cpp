#include "herolistener.h"
#include <QDebug>
#include <QVector2D>
#include <apolygon.h>
#include <alayer.h>

HeroListener::HeroListener()
{

}

HeroListener::HeroListener(HeroSprite *sprite)
{
    setHeroSprite(sprite);
}

void HeroListener::setHeroSprite(HeroSprite *sprite)
{
    m_sprite = sprite;
}

void HeroListener::mouseMoveEvent(QMouseEvent *mouse)
{
    if(isPress)
    {   
            m_sprite->setX(mouse->x()-m_sprite->width()/2);
            m_sprite->setY(480-mouse->y()-m_sprite->height()/2);
    }
}

void HeroListener::mousePressEvent(QMouseEvent *mouse)
{
    //isPress = true;
    APolygon heroPolygon;
    heroPolygon.addPoint(m_sprite->leftBottonX(),m_sprite->leftBottonY());
    heroPolygon.addPoint(m_sprite->leftTopX(),m_sprite->leftTopY());
    heroPolygon.addPoint(m_sprite->rightTopX(),m_sprite->rightTopY());
    heroPolygon.addPoint(m_sprite->rightBottonX(),m_sprite->rightBottonY());

    if(heroPolygon.pointInPolygon(QVector2D(mouse->x(),480-mouse->y())))
    {
        isPress = true;
    }
}


void HeroListener::mouseReleaseEvent(QMouseEvent *)
{
    isPress = false;
    canMove = false;
}

void HeroListener::setLayer(ALayer * layer)
{
    this->layer = layer;
}

bool HeroListener::isFire()
{
    return isPress;
}
