#include "age_spriteactor.h"


#include <QDomDocument>
#include <qfile.h>
#include <qdebug.h>
#include <age_vector2d.h>
AGE_SpriteActor::AGE_SpriteActor()
{
    initializeAll();
}

AGE_SpriteActor::AGE_SpriteActor(AGE_Texture * bigDick)
{
    bindTexture(bigDick);
    initializeAll();
}

AGE_SpriteActor::~AGE_SpriteActor()
{
	initializeGLFunctions();
    glDeleteBuffers(2,m_geometric.getVboId()); //1
    delete m_geometric.getVboId(); //2
}

void AGE_SpriteActor::addAnimation(AGE_Animation)
{

}

void AGE_SpriteActor::animate(QString actionName, int frames, bool isCycle)
{

	AGE_Animation* animation=m_animation_set->findAnimation (actionName);
	if(isCycle)
	{
		frames=frames%(animation->totalFrames ());
	}
	AGE_Frame frame=animation->getFrame (frames);
	this->setShowRect (frame.bottomLeft ().x (),frame.bottomLeft ().y (),
			   frame.topRight ().x (),frame.topRight ().y ()
			   );
}

void AGE_SpriteActor::loadAnimationsFromFile(QString fileName)
{

QFile file(fileName);
 QDomDocument doc("superdick");
file.open( QIODevice::ReadOnly );
doc.setContent (&file);
 file.close();
   QDomElement root = doc.documentElement();//获得根节点

   //遍历添加animation
   QDomElement child=root.firstChildElement ();
   while(!child.isNull ())
   {
	   AGE_Animation animation(child.attribute (QString("name")));
	   addAnimationFromFile (&animation,child);
	   m_animationlist.push_back (animation);
	   child=child.nextSiblingElement ();
   }
}

void AGE_SpriteActor::bindAnimationSet(AGE_AnimationSet *animation_set)
{
	this->m_animation_set=animation_set;
}

void AGE_SpriteActor::addAnimationFromFile(AGE_Animation *animation, QDomElement node)
{
	//加入帧
	QDomElement child =node.firstChildElement ();
	while(!child.isNull ())
	{

		QDomElement rect=child.firstChildElement ();
		//左下角
		double bl_x= rect.attribute (QString("x")).toDouble ();
		double bl_y= rect.attribute (QString("y")).toDouble ();
		AGE_Vector2D bl(bl_x,bl_y);
        //qDebug()<<" bottom left is"<<bl;

		rect=rect.nextSiblingElement ();
		//右上角
		double tr_x=rect.attribute (QString("x")).toDouble ();
		double tr_y=rect.attribute (QString("y")).toDouble ();
		AGE_Vector2D tr(tr_x,tr_y);
        //qDebug()<<" top right is"<<tr;
		//添加一帧
		animation->addFrame(AGE_Frame(bl,tr));
		child=child.nextSiblingElement ();
	}
}

void AGE_SpriteActor::action()
{

}
