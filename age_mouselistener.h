#ifndef AGE_MOUSELISTENER_H
#define AGE_MOUSELISTENER_H

#include "age_mouseinfo.h"

class AGE_MouseListener
{
	friend class AGE_EventMgr;
public:
	AGE_MouseListener();
protected:

	virtual void onMouseRelease(AGE_MouseInfo info);
	virtual void onMousePress(AGE_MouseInfo info);
	virtual void onMouseMove(AGE_MouseInfo info);
};

#endif // AGE_MOUSELISTENER_H
