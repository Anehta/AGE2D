#ifndef HERO_H
#define HERO_H
#include "../include/age_sprite.h"
#include "../include/age_texture.h"
#include "../include/age_keylistener.h"
#include "../include/age_accumulator.h"
class Hero :public AGE_Sprite,public AGE_KeyListener
{
public:
	Hero();
	virtual void onKeyRelease(QKeyEvent * event);
	virtual void onKeyPress (QKeyEvent *event);
	virtual void action();
protected:
	bool is_in_the_boundary(double x, double y);
	AGE_Texture* m_texture;
	bool turn_left;
	bool turn_right;
	bool fore_ward;
	bool back_ward;
	bool sneak;
	bool is_firing;
	AGE_Accumulator *fire_cd;
};


#endif // HERO_H
