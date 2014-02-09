#ifndef ALAYER_H
#define ALAYER_H
#include <list>
#include "age_scene.h"
#include "age_sprite.h"
#include <qglfunctions.h>

namespace AGE2D {

class ASprite;
class ALayer : public QGLFunctions
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
}


#endif // ALAYER_H
