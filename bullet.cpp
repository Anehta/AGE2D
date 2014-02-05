#include "bullet.h"
#include <age_system.h>
#include <stdlib.h>
AGE_AnimationSet * Bullet::animation_set=NULL;
Bullet::Bullet()
{
}

Bullet::Bullet(AGE_Texture * texture)
{
	if(!Bullet::animation_set)
	{
		animation_set=new AGE_AnimationSet(":/test.xml");
	}
    bindTexture(texture);
    this->bindAnimationSet (Bullet::animation_set);
    acc=new  AGE_Accumulator(0,1.5,0.5,true);
}

void Bullet::action()
{
    acc->step ();
    this->animate("move",acc->currentValue (),true);

    this->setY((this->getY()+1));
    if(this->getY() >= 480)
    {
        this->destroy();
    }
}
