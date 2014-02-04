#include "mylayer.h"
#include <herosprite.h>
#include <age_eventmgr.h>
#include <bullet.h>
#include <age_system.h>

MyLayer::MyLayer()
{
    initResource();
}

void MyLayer::initResource()
{
    texture = new AGE_Texture;
    backGroundTexture = new AGE_Texture;

    texture->loadFile(":/3.png");
    backGroundTexture->loadFile(":/2.png");

    AGE_SpriteActor * sprite = new AGE_SpriteActor;
    AGE_Sprite * backsprite = new AGE_Sprite;
    backsprite->bindTexture(backGroundTexture);
    sprite->bindTexture(texture);
    this->addChild(backsprite);
    this->addChild(sprite);
}

void MyLayer::action()
{
    if(isPress)
    {
        for(int i=0 ; i<1;i++)
        {
            //qDebug()<<"time_info:"<<(double)AGE_System::timeFram()/1000;
            Bullet * sprite = new Bullet(texture);
            sprite->setX(mousex-sprite->width()/2 );
            sprite->setY(mousey-sprite->width()/2 );
            this->addChild(sprite);
            sprite = NULL;
            static int s = 0;
            s++;
        }
    }
}

void MyLayer::onMouseMove(AGE_MouseInfo  mouse)
{
    mousex = mouse.getMouseX ();
    mousey =  mouse.getMouseY();
}

void MyLayer::onMousePress(AGE_MouseInfo  mouse)
{
    isPress = true;
}

void MyLayer::onMouseRelease(AGE_MouseInfo  mouse)
{
    isPress = false;
}
