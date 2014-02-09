#include <../include/age_geometric.h>
#include <../include/amainattribute.h>
namespace AGE2D
{
AGE_Geometric::AGE_Geometric()
{

}

AGE_Geometric::~AGE_Geometric()
{
    //delete m_vboId;
}

GLuint * AGE_Geometric::getVboId()
{
    return m_vboId;
}

void AGE_Geometric::initializeAll()
{
    initializeGLFunctions();
    glGenBuffers(2,m_vboId);
}

void AGE_Geometric::initRectGeometric()
{
    VertexData vertices[] ={
	{AGE_Vector3D(0,0,0),AGE_Vector2D((double)m_leftTopX/(double)m_imageWidth , (double)m_leftTopY/(double)m_imageHeight)},
	{AGE_Vector3D(m_width,0,0),AGE_Vector2D((double)m_rightBottonX/(double)m_imageWidth , (double)m_leftTopY/(double)m_imageHeight)},
	{AGE_Vector3D(m_width,m_height,0),AGE_Vector2D((double)m_rightBottonX/(double)m_imageWidth,(double)m_rightBottonY/(double)m_imageHeight)},
	{AGE_Vector3D(0,m_height,0),AGE_Vector2D((double)m_leftTopX/m_imageWidth,(double)m_rightBottonY/m_imageHeight)}
    };


    GLushort indices[] = {
	  0,1,2,3//一个面
    };

    glBindBuffer(GL_ARRAY_BUFFER,m_vboId[0]);
    glBufferData(GL_ARRAY_BUFFER,4*sizeof(VertexData),vertices,GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_vboId[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,5*sizeof(GLushort),indices,GL_STATIC_DRAW);

}

void AGE_Geometric::setWidth(int w)
{
    m_width = w;
    initRectGeometric();
}

void AGE_Geometric::setHeight(int h)
{
    m_height = h;
    initRectGeometric();
}

int AGE_Geometric::width()
{
    return m_width;
}

int AGE_Geometric::height()
{
    return m_height;

}

void AGE_Geometric::setShowRect(int x1, int y1, int x2, int y2)
{
    m_leftTopX = x1;
    m_leftTopY = y1;
    m_rightBottonX = x2;
    m_rightBottonY = y2;
    m_width = m_rightBottonX-m_leftTopX;
    m_width = m_rightBottonY-m_leftTopY;
    initRectGeometric();
}

void AGE_Geometric::initParameter(int width, int height, int imageWidth,int imageHeight, int x1, int y1, int x2, int y2)
{
    m_width = width;
    m_height = height;
    m_imageWidth = imageWidth;
    m_imageHeight = imageHeight;
    m_leftTopX = x1;
    m_leftTopY = y1;
    m_rightBottonX = x2;
    m_rightBottonY = y2;
    m_vboId = new GLuint[2];
    initializeAll();
    initRectGeometric();
}

}
