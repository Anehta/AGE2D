#ifndef AGE_KEYLISTENER_H
#define AGE_KEYLISTENER_H

#include <QKeyEvent>
class AGE_KeyListener
{
public:
	AGE_KeyListener();
	virtual void onKeyRelease(QKeyEvent * event);
	virtual void onKeyPress (QKeyEvent *event);
};

#endif // AGE_KEYLISTENER_H
