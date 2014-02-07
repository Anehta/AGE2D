#include "bullet.h"
#include "game.h"
#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "qdebug.h"
Bullet::Bullet(AGE_Vector2D pos,double slope,double speed,bool is_turn_right)
{
	this->bindTexture (Game::single ()->getBullet_texture ());
	this->slope=slope;
	this->speed=speed;
	this->setX (pos.x ());
	this->setY (pos.y ());
	this->is_turn_right=is_turn_right;
}

bool Bullet::out_of_the_boundary(double x,double y)
{
	if(x +this->width ()<0 &&
	   y+this->height ()<=0 &&
	   x>AGE_System::GetWidth () &&
	  y>AGE_System::GetHeight ()
	   )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Bullet::action()
{

    AGE_Vector2D vec(speed*AGE_System::timeStep (),speed*AGE_System::timeStep ());

	if(!is_turn_right)
	{
        vec.setX (-1*vec.x ()*(1-slope));
	}
	else
	{
        vec.setX (vec.x ()*(1-slope));
	}

    this->setX (this->getX ()+vec.x ());
    this->setY (this->getY ()+vec.y ()+2);

    if(out_of_the_boundary(this->getX (),this->getY ()))
	{
        this->destroy ();
    }

}
