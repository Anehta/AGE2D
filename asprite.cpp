#include <asprite.h>
#include <amainattribute.h>
#include <atexture2d.h>
#include <ageometric.h>
#include <anode.h>
#include <QMatrix4x4>
#include <memory>

using namespace std;

ASprite::~ASprite()
{
    glDeleteBuffers(2,m_geometric.getVboId()); //1
    delete m_geometric.getVboId(); //2
    //delete &m_geometric; //3
}

ASprite::ASprite()
{
    initializeAll();
}

ASprite::ASprite(ATexture2D * bigDick)
{
    bindTexture(bigDick);
    initializeAll();

}

void ASprite::action()
{

}

void ASprite::setShowRect(float lx, float ly, float rx, float ry)
{

}

void ASprite::deleteThis()
{

}

void ASprite::render()
{

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

    offset += sizeof(QVector3D);

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

void ASprite::computeMatrix()
{
    QMatrix4x4 viewMatrix = getViewPortMatrix() * getMatrix();

    QMatrix4x4 lbmatrix = viewMatrix;

    lbmatrix.translate(mx_offset,my_offset,0);
    lbmatrix.rotate(m_angle,0,0,1);
    lbmatrix.translate(-mx_offset,-my_offset,0);
    m_program->setUniformValue("mvp_matrix", lbmatrix);//set shader

    if(isNeedRealTime)
    {
        QMatrix4x4 ltmatrix = viewMatrix;
        QMatrix4x4 rbmatrix = viewMatrix;
        QMatrix4x4 rtmatrix = viewMatrix;

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



        QMatrix4x4 currentMatrix = getViewPortMatrix().inverted();
        QMatrix4x4 leftBottonMatrix =  currentMatrix * lbmatrix;
        QMatrix4x4 leftTopMatrix = currentMatrix * ltmatrix;
        QMatrix4x4 rightBottonMatrix = currentMatrix * rbmatrix;
        QMatrix4x4 rightTopMatrix = currentMatrix * rtmatrix;

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

void ASprite::bindDefalutProgram()
{
    m_program = getDefalutShaderProgram();
}

void ASprite::bindTexture(ATexture2D *fuckyou)
{
    initializeGLFunctions();
    m_texId = fuckyou->getTextureId();
    bindDefalutProgram();
    m_geometric.initRectGeometric(fuckyou->width(),fuckyou->height());
    initializeAll();
}

void ASprite::bindTexture(int textureId)
{
    m_texId = textureId;

}

int ASprite::getTextureId()
{
    return m_texId;
}

float ASprite::width()
{
    return m_geometric.width();
}

float ASprite::height()
{
    return m_geometric.height();
}

void ASprite::setWidth(float width)
{
    m_geometric.setWidth(width);
}

void ASprite::setHeight(float height)
{
    m_geometric.setHeight(height);
}

void ASprite::setPivotOffset(float x_offset, float y_offset)
{
    mx_offset = x_offset;
    my_offset = y_offset;
}

void ASprite::rotate(float angle)
{
    m_angle = angle;
}

void ASprite::initializeAll()
{
    setPivotOffset(0,0);
    rotate(0);
    setX(0);
    setY(0);
    setScale(0);

}


float ASprite::leftTopX()
{
    isNeedRealTime = true;
    return m_leftTopX;
}

float ASprite::rightTopX()
{
    isNeedRealTime = true;
    return m_rightTopX;
}

float ASprite::leftBottonX()
{
    isNeedRealTime = true;
    return m_leftBottonX;
}

float ASprite::rightBottonX()
{
    isNeedRealTime = true;
    return m_rightBottonX;
}

float ASprite::leftTopY()
{
    isNeedRealTime = true;
    return m_leftTopY;
}

float ASprite::rightTopY()
{
    isNeedRealTime = true;
    return m_rightTopY;
}

float ASprite::leftBottonY()
{
    isNeedRealTime = true;
    return m_leftBottonY;
}

float ASprite::rightBottonY()
{
    isNeedRealTime = true;
    return m_rightBottonY;
}

void ASprite::destroy()
{
    isDeath = true;
}