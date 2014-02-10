#include <../include/age_widget.h>
#include <../include/age_staticattribute.h>
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
AWidget::AWidget(QWidget *)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer))
{
    setFixedSize(640,480);
}

AWidget::~AWidget()
{

}

void AWidget::initializeGL()
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

void AWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);

    projection.setToIdentity();
    qDebug()<<"widget:"<<w<<"height:"<<h;
    static int wi = w, he = h;

    projection.ortho(0,wi,0,he,-1,1);

    ASystem::m_widthOffset = w-wi;
    ASystem::m_heightOffset = h-he;

    qDebug()<<ASystem::GetWidthOffset();
    qDebug()<<ASystem::GetHeightOffset();
    setViewPortMatrix(projection);
}

void AWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //setViewPortMatrix(projection);
    display();

}

void AWidget::timerEvent(QTimerEvent *)
{
	clock_t time_temp = clock();
    updateGL();
    setTimeStep(clock()-time_temp+15);
}

void AWidget::display()
{
    AScene * temp = getCurrentScene();

    if(temp != NULL)
    {
	temp->renderScene();
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->run();
	}
    }

}

void AWidget::initResources()
{

}

void AWidget::mouseMoveEvent(QMouseEvent * mouse)
{
    this->setMouseTracking(true);
    AScene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->mouseMoveEvent(mouse);
	}
    }
}

void AWidget::mousePressEvent(QMouseEvent *mouse)
{
    AScene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->mousePressEvent(mouse);
	}

    }
}

void AWidget::mouseReleaseEvent(QMouseEvent *mouse)
{
    AScene * temp = getCurrentScene();
    if(temp != NULL)
    {
	if(temp->m_listenerManager != NULL)
	{
	    temp->m_listenerManager->mouseReleaseEvent(mouse);
	}

    }
}

void AWidget::mouseDoubleClickEvent(QMouseEvent *mouse)
{
    setCurrentMouseEvent(mouse);

}

void AWidget::keyReleaseEvent(QKeyEvent *event)
{
	AScene * temp = getCurrentScene();
	if(temp != NULL)
	{
	    if(temp->m_listenerManager != NULL)
	    {
		temp->m_listenerManager->keyReleaseEvent (event);
	    }

	}
}

void AWidget::keyPressEvent(QKeyEvent *event)
{
	AScene * temp = getCurrentScene();
	if(temp != NULL)
	{
	    if(temp->m_listenerManager != NULL)
	    {
		temp->m_listenerManager->keyPressEvent (event);
	    }

	}
}
}

