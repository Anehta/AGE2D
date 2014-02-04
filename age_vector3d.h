#ifndef AGE_VECTOR3D_H
#define AGE_VECTOR3D_H

#include <QVector3D>
class AGE_Point;
class AGE_PointF;
class AGE_Vector2D;
class AGE_Vector4D;

class AGE_Vector3D : public QVector3D
{
public:
    AGE_Vector3D();
    AGE_Vector3D(const AGE_Point &point);
    AGE_Vector3D(const AGE_PointF &point);
    AGE_Vector3D(const AGE_Vector2D & vector);
    AGE_Vector3D(const AGE_Vector2D & vector,float zpos);
    AGE_Vector3D(const AGE_Vector4D & vector);
};

#endif // AGE_VECTOR3D_H
