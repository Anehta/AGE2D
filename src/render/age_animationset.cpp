#include <../include/AGE2D.h>
#include <qfile.h>
AGE_AnimationSet::AGE_AnimationSet(QString fileName)
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

AGE_Animation *AGE_AnimationSet::findAnimation(QString animationName)
{
	for(list<AGE_Animation>::iterator i= m_animationlist.begin ();i!=m_animationlist.end ();i++)
	{
		if(i->getName ().compare (animationName)==0)//找寻指定的animation
		{
			return &(*i);
		}
	}
}

void AGE_AnimationSet::addAnimationFromFile(AGE_Animation *animation, QDomElement node)
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
