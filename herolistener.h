#ifndef HEROLISTENER_H
#define HEROLISTENER_H

#include <aeventlistener.h>
#include <herosprite.h>

class HeroSprite;
class ALayer;

class HeroListener : public AEventListener
{
public:
    HeroListener();
    HeroListener(HeroSprite * sprite);
    void setHeroSprite(HeroSprite * sprite);
    void setLayer(ALayer *);
    bool isFire();
protected:
    void mouseMoveEvent(QMouseEvent * mouse);
    void mousePressEvent(QMouseEvent * mouse);
    void mouseReleaseEvent(QMouseEvent *mouse);
private:
    HeroSprite * m_sprite;
    bool isPress = false;
    bool canMove = false;
    ALayer * layer;
};
#endif // HEROLISTENER_H
