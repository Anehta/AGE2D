#ifndef HEROSPRITE_H
#define HEROSPRITE_H

#include <age_sprite.h>
#include <age_eventlistener.h>
#include <age_layer.h>
#include <bullet.h>

class AGE_Texture;
class HeroListener;
class QMouseEvent;

class HeroSprite : public AGE_Sprite
{
public:
    HeroSprite();
    HeroSprite(AGE_Texture * texture);
    void getLayer(AGE_Layer * m_layer);
protected:
    void action();
private:
    AGE_Layer * m_layer;
};

#endif // HEROSPRITE_H
