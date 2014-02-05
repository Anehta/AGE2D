#ifndef AGE_ANIMATIONSET_H
#define AGE_ANIMATIONSET_H
#include <list>
#include <age_animation.h>
#include <QDomDocument>
#include <qstring.h>
class AGE_AnimationSet
{
public:
	AGE_AnimationSet(QString fileName);
	AGE_Animation * findAnimation(QString animationName);
protected:
void addAnimationFromFile(AGE_Animation * animation,QDomElement node);
    list <AGE_Animation> m_animationlist;
};

#endif // AGE_ANIMATIONSET_H
