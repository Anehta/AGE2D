#ifndef ASPRITE_H
#define ASPRITE_H

#include <QGLShaderProgram>
#include <../include/age_node.h>
#include <../include/age_geometric.h>
#include <../include/age_texture.h>
#include <memory>
#include "age_layer.h"
#include "age_texture.h"
#include "age_geometric.h"
#include "age_node.h"

namespace AGE2D {
class AGE_Sprite : public AGE_Node,protected QGLFunctions
{
public:
    ~AGE_Sprite();
    friend class AGE_Layer;
    AGE_Sprite();
    AGE_Sprite(AGE_Texture *);
    void setShowRect(float lx,float ly,float rx,float ry);
    void setShowDet(int row,int col,int gridWidth,int gridHeigth);


    void bindTexture(AGE_Texture * fuckyou);
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
    float middleX();
    float middleY();

    float width();
    float height();

    void destroy();
    QGLShaderProgram *getShaderProgram();
    void setWidth(float);
    void setHeight(float);
    //friend class ALayer;

protected:
    virtual void action();
    virtual void shaderAction();
    AGE_Geometric m_geometric;
    void initializeAll();

private:
    void render();
    void computeMatrix();
    QGLShaderProgram *m_program;
    GLuint m_texId = 0;

    AGE_Texture m_texture;
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
