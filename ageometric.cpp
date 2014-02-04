#include "ageometric.h"
#include <QVector3D>
#include <QVector2D>

struct VertexData
{
    QVector3D postion;
    QVector2D texture;
};

AGeometric::AGeometric()
{
    m_vboId = new GLuint[2];
    initializeAll();
}

AGeometric::~AGeometric()
{
    //delete m_vboId;
}

GLuint * AGeometric::getVboId()
{
    return m_vboId;
}

void AGeometric::initializeAll()
{
    initializeGLFunctions();
    glGenBuffers(2,m_vboId);
}

void AGeometric::initRectGeometric(int width,int height)
{
    m_width = width;
    m_height = height;

    VertexData vertices[] ={
        {QVector3D(0,0,0),QVector2D(0,0)},
        {QVector3D(m_width,0,0),QVector2D(1,0)},
        {QVector3D(m_width,m_height,0),QVector2D(1,1)},
        {QVector3D(0,m_height,0),QVector2D(0,1)}
    };


    GLushort indices[] = {
          0,1,2,3//一个面
    };

    glBindBuffer(GL_ARRAY_BUFFER,m_vboId[0]);
    glBufferData(GL_ARRAY_BUFFER,4*sizeof(VertexData),vertices,GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_vboId[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,5*sizeof(GLushort),indices,GL_STATIC_DRAW);

}

void AGeometric::setWidth(int w)
{
    m_width = w;
    //initRectGeometric(m_width,m_height);
}

void AGeometric::setHeight(int h)
{
    m_height = h;
    //initRectGeometric(m_width,m_height);
}

int AGeometric::width()
{
    return m_width;
}

int AGeometric::height()
{
    return m_height;
}
