#ifndef ANODE_H
#define ANODE_H



namespace AGE2D {
class AMatrix4x4;
class ANode
{
public:
    ANode();
    ~ANode();
    virtual AMatrix4x4 getMatrix();
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
