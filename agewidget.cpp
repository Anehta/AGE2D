#include "agewidget.h"
#include "amainattribute.h"
#include <ascene.h>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QKeyEvent>
#include <alistenermanager.h>
#include <list>
#include <abaselistener.h>
//#include <iostream>
#include <ctime>

using namespace std;

AGE2DWidget::AGE2DWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer))
{

}

AGE2DWidget::~AGE2DWidget()
{

}

void AGE2DWidget::initializeGL()
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

void AGE2DWidget::resizeGL(int w, int h)
{
    glViewport(0, 0,w,h);

    projection.setToIdentity();

    static int wi = w, he = h;

    projection.ortho(0,w,0,h,-1,1);

    setViewPortMatrix(projection);
}

void AGE2DWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setViewPortMatrix(projection);

    clock_t clock();
    display();
}

void AGE2DWidget::timerEvent(QTimerEvent *)
{
    updateGL();
}

void AGE2DWidget::display()
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

void AGE2DWidget::initResources()
{

}

void AGE2DWidget::mouseMoveEvent(QMouseEvent * mouse)
{
    //qDebug()<<mouse->x()<<" "<<mouse->y();
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

void AGE2DWidget::mousePressEvent(QMouseEvent *mouse)
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

void AGE2DWidget::mouseReleaseEvent(QMouseEvent *mouse)
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

void AGE2DWidget::mouseDoubleClickEvent(QMouseEvent *mouse)
{
    setCurrentMouseEvent(mouse);

}
