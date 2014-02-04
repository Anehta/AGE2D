#include "age_vector2d.h"
#include <age_vector2d.h>
#include <age_vector3d.h>
#include <age_vector4d.h>
#include <age_point.h>
#include <age_pointf.h>

AGE_Vector2D::AGE_Vector2D()
{
}

AGE_Vector2D::AGE_Vector2D(const AGE_Point &point)
{
    setX(point.x());
    setY(point.y());
}

AGE_Vector2D::AGE_Vector2D(const AGE_Vector3D &vector)
{
    setX(vector.x());
    setY(vector.y());
}

AGE_Vector2D::AGE_Vector2D(const AGE_Vector4D &vector)
{
    setX(vector.x());
    setY(vector.y());
}

AGE_Vector2D::AGE_Vector2D(float xpos, float ypos)
{
    setX(xpos);
    setY(ypos);
}
