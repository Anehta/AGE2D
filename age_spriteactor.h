#ifndef ASPRITEACTOR_H
#define ASPRITEACTOR_H
#include <age_sprite.h>
#include <set>
#include <QString>
#include <list>
#include <age_animation.h>
#include <QDomDocument>
using namespace std;
class AGE_SpriteActor : public AGE_Sprite
{
public:
    AGE_SpriteActor();
    AGE_SpriteActor(AGE_Texture *);
    ~AGE_SpriteActor();
    void animate(QString actionName,int frames,bool isCycle); //执行动作
    void addAnimation(AGE_Animation);
    void loadAnimationsFromFile(QString fileName);
protected:
    void addAnimationFromFile(AGE_Animation * animation,QDomElement node);
    void action();
    list <AGE_Animation> m_animationlist;
};

#endif // ASPRITEACTOR_H
