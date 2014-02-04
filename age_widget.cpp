#include "age_widget.h"
#include "amainattribute.h"
#include <age_scene.h>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QKeyEvent>
#include <age_eventmgr.h>
#include <list>
#include <age_baselistener.h>
//#include <iostream>
#include <ctime>
#include <QFont>
#include <age_system.h>

using namespace std;

AGE_Widget::AGE_Widget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer))
{

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
    glViewport(0, 0,w,h);

    projection.setToIdentity();

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
    clock_t time_temp = clock();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //setViewPortMatrix(projection);

    display();

    setCurrentTimeFram(clock()-time_temp);

}

void AGE_Widget::timerEvent(QTimerEvent *)
{
    updateGL();
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
    //qDebug()<<mouse->x()<<" "<<mouse->y();
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
