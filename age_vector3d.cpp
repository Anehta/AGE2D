#include "age_vector3d.h"
#include <age_vector2d.h>
#include <age_vector4d.h>
#include <age_point.h>
#include <age_pointf.h>

AGE_Vector3D::AGE_Vector3D()
{
}

AGE_Vector3D::AGE_Vector3D(const AGE_Point &point)
{
    setX(point.x());
    setY(point.y());
}

AGE_Vector3D::AGE_Vector3D(const AGE_PointF &point)
{
    setX(point.x());
    setY(point.y());
    setZ(0);
}

AGE_Vector3D::AGE_Vector3D(const AGE_Vector2D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(0);
}

AGE_Vector3D::AGE_Vector3D(const AGE_Vector2D &vector, float zpos)
{
    setX(vector.x());
    setY(vector.y());
    setZ(zpos);

}

AGE_Vector3D::AGE_Vector3D(const AGE_Vector4D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(0);
}
