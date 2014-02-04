#ifndef BULLET_H
#define BULLET_H

#include <age_sprite.h>
#include <age_spriteactor.h>

class Bullet : public AGE_SpriteActor
{
public:
    Bullet();
    Bullet(AGE_Texture *);
protected:
    void action();

private:
    double a;
};

#endif // BULLET_H
