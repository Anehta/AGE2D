#include "anode.h"

ANode::~ANode()
{

}

ANode::ANode()
{
}

void ANode::setX(float x)
{
    m_x = x;
}

void ANode::setY(float y)
{
    m_y = y;
}

void ANode::setScale(float value)
{
    m_scale = value;
}

float ANode::getX()
{
    return m_x;
}

float ANode::getY()
{
    return m_y;
}

float ANode::getScale()
{
    return m_scale;
}

QMatrix4x4 ANode::getMatrix()
{
    QMatrix4x4 temp;
    temp.translate(m_x,m_y,0);
    //m_matrix.scale(m_scale);
    return temp;
}
