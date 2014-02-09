#ifndef AGE_VECTOR3D_H
#define AGE_VECTOR3D_H

#include <QVector3D>
#include "age_point.h"
#include "age_pointf.h"
#include "age_vector2d.h"
#include "age_vector4d.h"
namespace AGE2D{

class AGE_Vector3D : public QVector3D
{
public:
    AGE_Vector3D();
    AGE_Vector3D(float,float,float);
    AGE_Vector3D(const AGE_Point &point);
    AGE_Vector3D(const AGE_PointF &point);
    AGE_Vector3D(const AGE_Vector2D & vector);
    AGE_Vector3D(const AGE_Vector2D & vector,float zpos);
    AGE_Vector3D(const AGE_Vector4D & vector);
};
}


#endif // AGE_VECTOR3D_H
