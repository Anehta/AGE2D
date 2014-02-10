#ifndef ASPRITE_H
#define ASPRITE_H

#include <QGLShaderProgram>
#include <../include/age_node.h>
#include <../include/age_geometric.h>
#include <../include/age_texture.h>
#include <../include/age_baseentity.h>
#include <memory>
#include "age_layer.h"
#include "age_texture.h"
#include "age_geometric.h"
#include "age_node.h"
#include "age_vector2d.h"

namespace AGE2D {
class ALayer;
class ASprite : public ANode,protected QGLFunctions,public ABaseEntity
{
public:
    ~ASprite();
    friend class ALayer;
    ASprite();
    ASprite(ATexture *);
    void setShowRect(float lx,float ly,float rx,float ry);
    void setShowDet(int row,int col,int gridWidth,int gridHeigth);

    void bindTexture(ATexture * fuckyou);
    void bindTexture(int textureId,int width,int height);
    int getTextureId();
    void loadShaderProgram(QGLShaderProgram *);
    void initGeometric();

    void setPivotOffset(float x_offset,float y_offset); //Set the axis
    void rotate(float angle);

    float leftTopX();
    float leftTopY();
    AVector2D leftTop();

    float rightTopX();
    float rightTopY();
    AVector2D rightTop();

    float leftBottonX();
    float leftBottonY();
    AVector2D leftBotton();

    float rightBottonX();
    float rightBottonY();
    AVector2D rightBotton();

    float middleX();
    float middleY();
    AVector2D middle();

    float width();
    float height();
    AVector2D size();
    void destroy();
    QGLShaderProgram *getShaderProgram();
    void setWidth(float);
    void setHeight(float);

    ALayer * parent();

    virtual void setName(std::string new_name);

    //friend class ALayer;
protected:
    ALayer * m_parent;
    virtual void action();
    virtual void shaderAction();
    virtual void release();
    virtual void render();
    AGeometric m_geometric;
    void initializeAll();
private:
    void computeMatrix();
    QGLShaderProgram *m_program;
    GLuint m_texId = 0;

    ATexture m_texture;
    float mx_offset,my_offset;
    float m_angle;

    bool isDeath = false;
    bool isNeedRealTime = false;
    void bindDefalutProgram();
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
}


#endif // ASPRITE_H
