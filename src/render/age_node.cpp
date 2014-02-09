#include <../include/AGE2D.h>

namespace AGE2D
{
AGE_Node::~AGE_Node()
{

}

AGE_Node::AGE_Node()
{
}

void AGE_Node::setX(float x)
{
    m_x = x;
}

void AGE_Node::setY(float y)
{
    m_y = y;
}

void AGE_Node::setScale(float value)
{
    m_scale = value;
}

float AGE_Node::getX()
{
    return m_x;
}

float AGE_Node::getY()
{
    return m_y;
}

float AGE_Node::getScale()
{
    return m_scale;
}

QMatrix4x4 AGE_Node::getMatrix()
{
    QMatrix4x4 temp;
    temp.translate(m_x,m_y,0);
    //m_matrix.scale(m_scale);
    return temp;
}

}
