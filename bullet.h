#ifndef BULLET_H
#define BULLET_H

#include <age_sprite.h>
#include <age_spriteactor.h>
#include <age_animationset.h>
#include <age_accumulator.h>
class Bullet : public AGE_SpriteActor
{
public:
    Bullet();
    Bullet(AGE_Texture *);
protected:
    void action();
    AGE_Accumulator * acc;
private:
    double a;
    static AGE_AnimationSet * animation_set;
};

#endif // BULLET_H
