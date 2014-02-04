#ifndef AGEWIDGET_H
#define AGEWIDGET_H

#include <QGLWidget>
#include <QGLFunctions>
#include <QGLShaderProgram>
#include <QBasicTimer>
#include <QMatrix4x4>
#include <QQuaternion>
#include <ageometric.h>
#include <atexture2d.h>
#include <akeyboardevent.h>
#include <amouseevent.h>
#include <abaselistener.h>

class AKeyBoardEvent;
class AMouseEvent;

class AGE2DWidget : public QGLWidget ,QGLFunctions
{
    Q_OBJECT
public:
    AGE2DWidget(QWidget *parent = 0);
    ~AGE2DWidget();

protected:
    virtual void display();
    virtual void initResources();
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent *);
private:
    QBasicTimer m_timer;
    QMatrix4x4 projection;
    AKeyBoardEvent m_keyBoardEvent;
    AMouseEvent m_mouseEvent;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void timerEvent(QTimerEvent *);
};

#endif // AGEWIDGET_H
