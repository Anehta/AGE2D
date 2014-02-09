#include <../include/AGE2D.h>
#include <QMouseEvent>
#include <QKeyEvent>

namespace AGE2D
{
AMatrix4x4 viewPortMatrix;
QGLShaderProgram *program;
AScene * scenePointer;
QKeyEvent * keyBoardEvent = NULL;
QMouseEvent * mouseEvent = NULL;    //注意这里NULL
AWidget * m_widget = NULL;

AWidget * getCurrentWidget()
{
    return m_widget;
}

void setCurrentWidget(AWidget * widget)
{
    m_widget = widget;
}

double time_temp;
AMatrix4x4 getViewPortMatrix()
{
    return viewPortMatrix;
}

void setViewPortMatrix(AMatrix4x4 matrix)
{
    viewPortMatrix = matrix;
}

QGLShaderProgram * getDefalutShaderProgram()
{
	return program;
}

void initDefalutShaderProgram()
{
    setlocale(LC_NUMERIC, "C");
    program = new QGLShaderProgram();
    char vhs[] =
	    "uniform mat4 mvp_matrix;\n"
	    "attribute vec4 a_position;\n"
	    "attribute vec2 a_texcoord;\n"
	    "varying vec2 v_texCoord;\n"
	    "void main()\n"
	    "{\n"
		"gl_Position = mvp_matrix * a_position;\n"
		"v_texCoord = a_texcoord;\n"
	    "}";
    char fsh[] =
	    "uniform sampler2D source;\n"
	    "uniform lowp float qt_Opacity;\n"
	    "varying vec2 v_texCoord;\n"

	    "void main()\n"
	    "{\n"
		"gl_FragColor = texture2D(source, v_texCoord);\n"
	    "}\n"
	    ;

    if(!program->addShaderFromSourceCode(QGLShader::Vertex,vhs))
    {
	qDebug()<<"failed to init DefalutShaderProgram ---Vertex";
	return;
    }

    if(!program->addShaderFromSourceCode(QGLShader::Fragment,fsh))
    {
	qDebug()<<"failed to init DefalutShaderProgram ---Fragment";
	return;
    }

    /*if(!program->addShaderFromSourceFile(QGLShader::Vertex,":/vshader.glsl"))
    {
	qDebug()<<"failed to init DefalutShaderProgram ---Vertex";
	return;
    }

    if(!program->addShaderFromSourceFile(QGLShader::Fragment,":/fshader.glsl"))
    {
	qDebug()<<"failed to init DefalutShaderProgram ---Fragment";
	return;
    }*/

    if(!program->link())
    {
	qDebug()<<"failed to init DefaultShaderProgram --- link";
	return;
    }

    if(!program->bind())
    {
	qDebug()<<"failed to init DefalutShaderProgram ---bind";
	return;
    }

    setlocale(LC_ALL, "");
}

AScene * getCurrentScene()
{
    return scenePointer;
}

void setCurrentScene(AScene * fuckyourasshole)
{
    scenePointer = fuckyourasshole;
}

QKeyEvent * getCurrentKeyEvent()
{
    return keyBoardEvent;
}

QMouseEvent* getCurrentMouseEvent()
{
    return mouseEvent;
}

void setCurrentKeyEvent(QKeyEvent * s_keyboardEvent)
{
    keyBoardEvent = s_keyboardEvent;
}

void setCurrentMouseEvent(QMouseEvent * s_mouseEvent)
{
    mouseEvent = s_mouseEvent;
}

void setTimeStep(int time)
{
    time_temp = time;
}

int getTimeStep()
{
    return time_temp;
}
}

