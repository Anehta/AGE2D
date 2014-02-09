#ifndef AGE_VECTOR4D_H
#define AGE_VECTOR4D_H

#include <QVector4D>
#include "age_vector2d.h"
#include "age_vector3d.h"
#include "age_point.h"
#include "age_pointf.h"
namespace AGE2D
{
class AGE_Point;
class AGE_PointF;
class AGE_Vector2D;
class AGE_Vector3D;
class AGE_Vector4D : public QVector4D
{
public:
    AGE_Vector4D();
    AGE_Vector4D(const QVector4D & vector);
    AGE_Vector4D(float xpos,float ypos,float zpos,float wpos);
    AGE_Vector4D(const AGE_Point & point);
    AGE_Vector4D(const AGE_PointF & point);
    AGE_Vector4D(const AGE_Vector2D & vector);
    AGE_Vector4D(const AGE_Vector2D &vector,float zpos,float wpos);
    AGE_Vector4D(const AGE_Vector3D &vector);
    AGE_Vector4D(const AGE_Vector3D &vector,float wpos);
};
}


#endif // AGE_VECTOR4D_H
