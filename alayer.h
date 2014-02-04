#ifndef ALAYER_H
#define ALAYER_H
#include <list>

class AScene;
class ASprite;

class ALayer
{
public:
    ALayer();
    ALayer(ASprite * spritePointer);
    void addChild(ASprite * spritePointer);
    friend class AScene;
protected:
    virtual void action();
private:
    std::list<ASprite *> m_spriteList;
    void renderLayer();
};

#endif // ALAYER_H
