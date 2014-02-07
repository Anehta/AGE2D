#ifndef AGE_ANIMATION_H
#define AGE_ANIMATION_H
#include <qt>
#include <vector>
#include <../include/age_frame.h>
#include <qstring.h>
using namespace std;
class AGE_Animation
{
public:
	AGE_Animation(QString name);
	void addFrame(AGE_Frame frame);
	QString getName();
	int totalFrames();
	AGE_Frame getFrame(int index);
protected:
	QString name;
	vector<AGE_Frame> m_list;
};

#endif // AGE_ANIMATION_H
