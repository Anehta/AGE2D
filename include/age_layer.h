#ifndef ALAYER_H
#define ALAYER_H
#include <list>

class AGE_Scene;
class AGE_Sprite;

class AGE_Layer
{
public:
    AGE_Layer();
    AGE_Layer(AGE_Sprite * spritePointer);
    void addChild(AGE_Sprite * spritePointer);
    friend class AGE_Scene;
protected:
    virtual void action();
private:
    std::list<AGE_Sprite *> m_spriteList;
    void renderLayer();
};

#endif // ALAYER_H
