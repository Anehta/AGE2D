#include "bullet.h"
#include <age_system.h>

Bullet::Bullet()
{
}

Bullet::Bullet(AGE_Texture * texture)
{
    bindTexture(texture);
    this->loadAnimationsFromFile(":/test.xml");
    a =0;
}

void Bullet::action()
{
    a+=0.05;
    this->animate("move",a,true);

    this->setY((this->getY()+1));
    if(this->getY() >= 480)
    {
        this->destroy();
    }
}
