#ifndef BULLET_H
#define BULLET_H
#include "../include/age_spriteactor.h"
using namespace AGE2D;
class Bullet:public AGE_SpriteActor
{
public:
	Bullet(AGE_Vector2D pos, double slope, double speed,bool is_turn_right);
	virtual void action();
private:
	double slope;
	double speed;
	bool is_turn_right;
	bool out_of_the_boundary(double x,double y);
};

#endif // BULLET_H
