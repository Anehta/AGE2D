#ifndef ANODE_H
#define ANODE_H
#include <QMatrix4x4>

namespace AGE2D {
class ANode
{
public:
    ANode();
    ~ANode();
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
}


#endif // ANODE_H
