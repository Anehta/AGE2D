#include <../include/AGE2D.h>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QKeyEvent>
#include <list>
//#include <iostream>
#include <ctime>
#include <QFont>
#include <QDebug>

using namespace std;

namespace AGE2D
{
AGE_Widget::AGE_Widget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer))
{
    setWindowTitle("fucker");
    setFixedSize(640,480);
}

AGE_Widget::~AGE_Widget()
{

}

void AGE_Widget::initializeGL()
{
    setCurrentScene(NULL);
    initializeGLFunctions();

    qglClearColor(Qt::black);

    //glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    initDefalutShaderProgram();
    initResources();
    m_timer.start(15, this);
}

void AGE_Widget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);

    projection.setToIdentity();
    qDebug()<<"widget:"<<w<<"height:"<<h;
    static int wi = w, he = h;

    projection.ortho(0,wi,0,he,-1,1);

    AGE_System::m_widthOffset = w-wi;
    AGE_System::m_heightOffset = h-he;

    qDebug()<<AGE_System::GetWidthOffset();
    qDebug()<<AGE_System::GetHeightOffset();
    setViewPortMatrix(projection);
}

void AGE_Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //setViewPortMatrix(projection);
    display();
}

void AGE_Widget::timerEvent(QTimerEvent *)
{
	clock_t time_temp = clock();
    updateGL();
    setTimeStep(clock()-time_temp+15);
}

void AGE_Widget::display()
{
    AGE_Scene * temp = getCurrentScene();

    if(temp != NULL)
    {
	temp->renderScene();
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->run();
	}
    }

}

void AGE_Widget::initResources()
{

}

void AGE_Widget::mouseMoveEvent(QMouseEvent * mouse)
{
    this->setMouseTracking(true);
    AGE_Scene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->mouseMoveEvent(mouse);
	}
    }
}

void AGE_Widget::mousePressEvent(QMouseEvent *mouse)
{
    AGE_Scene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->mousePressEvent(mouse);
	}

    }
}

void AGE_Widget::mouseReleaseEvent(QMouseEvent *mouse)
{
    AGE_Scene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->mouseReleaseEvent(mouse);
	}

    }
}

void AGE_Widget::mouseDoubleClickEvent(QMouseEvent *mouse)
{
    setCurrentMouseEvent(mouse);

}

void AGE_Widget::keyReleaseEvent(QKeyEvent *event)
{
	AGE_Scene * temp = getCurrentScene();
	if(temp != NULL)
	{
	    if(temp->m_listenerManager != NULL)
	    {
		temp->m_listenerManager->keyReleaseEvent (event);
	    }

	}
}

void AGE_Widget::keyPressEvent(QKeyEvent *event)
{
	AGE_Scene * temp = getCurrentScene();
	if(temp != NULL)
	{
	    if(temp->m_listenerManager != NULL)
	    {
		temp->m_listenerManager->keyPressEvent (event);
	    }

	}
}
}

