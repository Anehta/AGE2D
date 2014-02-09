#ifndef AGE_VECTOR2D_H
#define AGE_VECTOR2D_H

#include <QVector2D>
#include "age_point.h"
#include "age_pointf.h"
#include "age_vector3d.h"
#include "age_vector4d.h"
namespace AGE2D {

class AGE_Vector2D : public QVector2D
{
public:
    AGE_Vector2D();
    AGE_Vector2D(float xpos,float ypos);
    AGE_Vector2D(const AGE_Point &point);
    AGE_Vector2D(const AGE_Vector3D &vector);
    AGE_Vector2D(const AGE_Vector4D &vector);
};
}


#endif // AGE_VECTOR2D_H
