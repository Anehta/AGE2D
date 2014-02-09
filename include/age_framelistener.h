#ifndef AGE_FRAMELISTENER_H
#define AGE_FRAMELISTENER_H


namespace AGE2D {
class AGE_FrameListener
{
public:
	 AGE_FrameListener();
	virtual void beforeFrameRender();
	virtual void afterFrameRender();
};

}

#endif // AGE_FRAMELISTENER_H
