#include <../include/AGE2D.h>
#include <memory>
#include <QGLShader>

using namespace std;

namespace AGE2D
{
AGE_Sprite::~AGE_Sprite()
{
    glDeleteBuffers(2,m_geometric.getVboId()); //1
    delete m_geometric.getVboId(); //2
    //delete &m_geometric; //3
}

AGE_Sprite::AGE_Sprite()
{
    initializeAll();
}

AGE_Sprite::AGE_Sprite(AGE_Texture * bigDick)
{
    bindTexture(bigDick);
    initializeAll();
}

void AGE_Sprite::action()
{

}

void AGE_Sprite::setShowRect(float lx, float ly, float rx, float ry)
{
    m_geometric.setShowRect(lx,ly,rx,ry);
}

void AGE_Sprite::setShowDet(int col, int row, int gridWidth, int gridHeigth)
{
    m_geometric.setShowRect(gridWidth*row,gridHeigth*col,
			    gridWidth*row+gridWidth,gridHeigth*col+gridHeigth);
}

void AGE_Sprite::deleteThis()
{

}

void AGE_Sprite::render()
{
    m_program->bind();
    shaderAction();

    glDepthMask(GL_FALSE);

    computeMatrix();

    GLuint * vboId = m_geometric.getVboId();

    glBindBuffer(GL_ARRAY_BUFFER,vboId[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboId[1]);
    quintptr offset = 0;
    glBindTexture(GL_TEXTURE_2D, m_texId);

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = m_program->attributeLocation("a_position");
    m_program->enableAttributeArray(vertexLocation);
    glVertexAttribPointer(vertexLocation,3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(AGE_Vector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = m_program->attributeLocation("a_texcoord");
    m_program->enableAttributeArray(texcoordLocation);
    glVertexAttribPointer(texcoordLocation, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);


    m_program->setUniformValue("source",0);
    glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_SHORT, 0);

    glDepthMask(GL_TRUE);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

}

void AGE_Sprite::computeMatrix()
{
    //m_program->bind();
    AGE_Matrix4x4 viewMatrix = getViewPortMatrix() * getMatrix();

    AGE_Matrix4x4 lbmatrix = viewMatrix;

    lbmatrix.translate(mx_offset,my_offset,0);
    lbmatrix.rotate(m_angle,0,0,1);
    lbmatrix.translate(-mx_offset,-my_offset,0);
    m_program->setUniformValue("mvp_matrix", lbmatrix);//set shader

    if(isNeedRealTime)
    {
	AGE_Matrix4x4 ltmatrix = viewMatrix;
	AGE_Matrix4x4 rbmatrix = viewMatrix;
	AGE_Matrix4x4 rtmatrix = viewMatrix;

	//ltmatrix.translate(0,m_geometric.height(),0);
	//rbmatrix.translate(m_geometric.width(),0,0);
	//rtmatrix.translate(m_geometric.width(),m_geometric.height(),0);
	//ltmatrix.translate(0,-m_geometric.height(),0);

	ltmatrix.translate(mx_offset,my_offset,0);
	ltmatrix.rotate(m_angle,0,0,1);
	ltmatrix.translate(-mx_offset,-my_offset,0);
	ltmatrix.translate(0,m_geometric.height(),0);

	rbmatrix.translate(mx_offset,my_offset,0);
	rbmatrix.rotate(m_angle,0,0,1);
	rbmatrix.translate(-mx_offset,-my_offset,0);
	rbmatrix.translate(m_geometric.width(),0,0);

	rtmatrix.translate(mx_offset,my_offset,0);
	rtmatrix.rotate(m_angle,0,0,1);
	rtmatrix.translate(-mx_offset,-my_offset,0);
	rtmatrix.translate(m_geometric.width(),m_geometric.height(),0);

	AGE_Matrix4x4 currentMatrix = getViewPortMatrix().inverted();
	AGE_Matrix4x4 leftBottonMatrix =  currentMatrix * lbmatrix;
	AGE_Matrix4x4 leftTopMatrix = currentMatrix * ltmatrix;
	AGE_Matrix4x4 rightBottonMatrix = currentMatrix * rbmatrix;
	AGE_Matrix4x4 rightTopMatrix = currentMatrix * rtmatrix;

	float lbx = leftBottonMatrix.row(0).w();
	float lby = leftBottonMatrix.row(1).w();

	m_leftBottonX = lbx;
	m_leftBottonY = lby;

	float ltx = leftTopMatrix.row(0).w();
	float lty = leftTopMatrix.row(1).w();

	m_leftTopX = ltx;
	m_leftTopY = lty;

	float rbx = rightBottonMatrix.row(0).w();
	float rby = rightBottonMatrix.row(1).w();

	m_rightBottonX = rbx;
	m_rightBottonY = rby;

	float rtx = rightTopMatrix.row(0).w();
	float rty = rightTopMatrix.row(1).w();

	m_rightTopX = rtx;
	m_rightTopY = rty;
    }

}

void AGE_Sprite::bindDefalutProgram()
{
    m_program = getDefalutShaderProgram();
}

void AGE_Sprite::bindTexture(AGE_Texture *fuckyou)
{
    initializeGLFunctions();
    m_texId = fuckyou->getTextureId();
    bindDefalutProgram();
    m_geometric.initParameter(fuckyou->width(),fuckyou->height(),
			      fuckyou->width(),fuckyou->height(),
			      0,0,
			      fuckyou->width(),fuckyou->height());
    initializeAll();
}

void AGE_Sprite::bindTexture(int textureId)
{
    m_texId = textureId;

}

int AGE_Sprite::getTextureId()
{
    return m_texId;
}

float AGE_Sprite::width()
{
    return m_geometric.width();
}

float AGE_Sprite::height()
{
    return m_geometric.height();
}

void AGE_Sprite::setWidth(float width)
{
    m_geometric.setWidth(width);
}

void AGE_Sprite::setHeight(float height)
{
    m_geometric.setHeight(height);
}

void AGE_Sprite::setPivotOffset(float x_offset, float y_offset)
{
    mx_offset = x_offset;
    my_offset = y_offset;
}

void AGE_Sprite::rotate(float angle)
{
    m_angle = angle;
}

void AGE_Sprite::initializeAll()
{
    setPivotOffset(0,0);
    rotate(0);
    setX(0);
    setY(0);
    setScale(0);
}


float AGE_Sprite::leftTopX()
{
    isNeedRealTime = true;
    return m_leftTopX;
}

float AGE_Sprite::rightTopX()
{
    isNeedRealTime = true;
    return m_rightTopX;
}

float AGE_Sprite::leftBottonX()
{
    isNeedRealTime = true;
    return m_leftBottonX;
}

float AGE_Sprite::rightBottonX()
{
    isNeedRealTime = true;
    return m_rightBottonX;
}

float AGE_Sprite::leftTopY()
{
    isNeedRealTime = true;
    return m_leftTopY;
}

float AGE_Sprite::rightTopY()
{
    isNeedRealTime = true;
    return m_rightTopY;
}

float AGE_Sprite::leftBottonY()
{
    isNeedRealTime = true;
    return m_leftBottonY;
}

float AGE_Sprite::rightBottonY()
{
    isNeedRealTime = true;
    return m_rightBottonY;
}

void AGE_Sprite::destroy()
{
    isDeath = true;
}

float AGE_Sprite::middleX()
{
    return getX()+width()/2;
}

float AGE_Sprite::middleY()
{
    return getY()+height()/2;
}

void AGE_Sprite::loadShaderProgram(QGLShaderProgram * program)
{
    m_program = program;
}

QGLShaderProgram * AGE_Sprite::getShaderProgram()
{
    return m_program;
}

void AGE_Sprite::shaderAction()
{

}
}

