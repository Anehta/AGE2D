#ifndef ASPRITE_H
#define ASPRITE_H

#include <QGLShaderProgram>
#include <anode.h>
#include <ageometric.h>
#include <atexture2d.h>
#include <memory>

class ALayer;
class ATexture2D;
class AGeometric;
class ANode;

class ASprite : public ANode,protected QGLFunctions
{
public:
    ~ASprite();
    friend class ALayer;
    ASprite();
    ASprite(ATexture2D *);
    void setShowRect(float lx,float ly,float rx,float ry);
    void bindTexture(ATexture2D * fuckyou);
    void bindTexture(int textureId);
    int getTextureId();
    void loadShaderProgram(QGLShaderProgram *);
    void initGeometric();

    void setPivotOffset(float x_offset,float y_offset); //Set the axis
    void rotate(float angle);

    float leftTopX();
    float rightTopX();
    float leftBottonX();
    float rightBottonX();
    float leftTopY();
    float rightTopY();
    float leftBottonY();
    float rightBottonY();

    float width();
    float height();

    void destroy();

    void setWidth(float);
    void setHeight(float);
    //friend class ALayer;
protected:
    virtual void action();
private:
    void render();
    void computeMatrix();
    QGLShaderProgram *m_program;
    GLuint m_texId = 0;
    AGeometric m_geometric;
    ATexture2D m_texture;
    float mx_offset,my_offset;
    float m_angle;

    bool isDeath = false;
    bool isNeedRealTime = false;
    void bindDefalutProgram();
    void initializeAll();
    void deleteThis();
    float m_leftTopX = 0;
    float m_leftTopY = 0;
    float m_rightTopX = 0;
    float m_rightTopY = 0;
    float m_leftBottonX = 0;
    float m_leftBottonY = 0;
    float m_rightBottonX = 0;
    float m_rightBottonY = 0;

};

#endif // ASPRITE_H
