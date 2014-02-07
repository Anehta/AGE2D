#ifndef ASPRITEACTOR_H
#define ASPRITEACTOR_H
#include <../include/age_sprite.h>
#include <set>
#include <QString>
#include <list>
#include <../include/age_animation.h>
#include <QDomDocument>
#include <../include/age_animationset.h>
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
    void bindAnimationSet(AGE_AnimationSet * animation_set);
protected:
    void addAnimationFromFile(AGE_Animation * animation,QDomElement node);
    void action();
     AGE_AnimationSet * m_animation_set;
    list <AGE_Animation> m_animationlist;
};

#endif // ASPRITEACTOR_H
