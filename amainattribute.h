#ifndef AVIEWPORTMATRIX_H
#define AVIEWPORTMATRIX_H

#include <QGLShaderProgram>
#include <age_eventmgr.h>
#include <age_vector2d.h>
#include <age_vector3d.h>
#include <age_matrix4x4.h>

class AGE_Scene;
class AGE_KeyBoardEvent;
class AGE_MouseInfo;

struct VertexData
{
    AGE_Vector3D postion;
    AGE_Vector2D texture;
};

AGE_Matrix4x4 getViewPortMatrix();
void setViewPortMatrix(AGE_Matrix4x4);

QGLShaderProgram * getDefalutShaderProgram();
void initDefalutShaderProgram();

AGE_Scene * getCurrentScene();
void setCurrentScene(AGE_Scene * fuckyourasshole);

QKeyEvent * getCurrentKeyEvent();
QMouseEvent* getCurrentMouseEvent();
void setCurrentKeyEvent(QKeyEvent * keyboardEvent);
void setCurrentMouseEvent(QMouseEvent * mouseEvent);
void setCurrentTimeFram(int time);
int getCurrentTimeFram();
#endif // AVIEWPORTMATRIX_H
