#ifndef ANODE_H
#define ANODE_H
#include <QMatrix4x4>

class AGE_Node
{
public:
    AGE_Node();
    ~AGE_Node();
    virtual QMatrix4x4 getMatrix();
    virtual void setX(float x);
    virtual void setY(float y);
    virtual void setScale(float value);
    virtual float getX();
    virtual float getY();
    virtual float getScale();
private:
    float m_x;
    float m_y;
    float m_scale;
};

#endif // ANODE_H
