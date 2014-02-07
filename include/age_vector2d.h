#ifndef AGE_VECTOR2D_H
#define AGE_VECTOR2D_H

#include <QVector2D>

class AGE_Point;
class AGE_PointF;
class AGE_Vector3D;
class AGE_Vector4D;

class AGE_Vector2D : public QVector2D
{
public:
    AGE_Vector2D();
    AGE_Vector2D(float xpos,float ypos);
    AGE_Vector2D(const AGE_Point &point);
    AGE_Vector2D(const AGE_Vector3D &vector);
    AGE_Vector2D(const AGE_Vector4D &vector);
};

#endif // AGE_VECTOR2D_H
