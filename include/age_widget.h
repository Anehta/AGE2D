#ifndef AGEWIDGET_H
#define AGEWIDGET_H

#include <QGLWidget>
#include <QGLFunctions>
#include <QGLShaderProgram>
#include <QBasicTimer>
#include <QMatrix4x4>
#include <QQuaternion>
#include <../include/age_geometric.h>
#include <../include/age_texture.h>
#include <../include/age_keyboardevent.h>
#include <../include/age_mouseinfo.h>
#include <../include/age_baselistener.h>

class AGE_KeyBoardEvent;
class AGE_MouseInfo;

class AGE_Widget : public QGLWidget ,QGLFunctions
{
    Q_OBJECT
public:
    AGE_Widget(QWidget *parent = 0);
    ~AGE_Widget();

protected:
    virtual void display();
    virtual void initResources();
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    virtual void keyReleaseEvent(QKeyEvent * event);
    virtual void keyPressEvent (QKeyEvent *event);
private:
    QBasicTimer m_timer;
    QMatrix4x4 projection;
    AGE_KeyBoardEvent m_keyBoardEvent;
    AGE_MouseInfo m_mouseEvent;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void timerEvent(QTimerEvent *);
};

#endif // AGEWIDGET_H
