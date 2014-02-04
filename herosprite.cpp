#include "herosprite.h"

HeroSprite::HeroSprite()
{
}

HeroSprite::HeroSprite(AGE_Texture *texture)
{
    bindTexture(texture);
}


void HeroSprite::action()
{
    static int s = 0;
    this->setPivotOffset(this->width()/2,this->height()/2);
}

void HeroSprite::getLayer(AGE_Layer *layer)
{
    m_layer = layer;
}
