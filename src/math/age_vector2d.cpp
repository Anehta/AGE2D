#include <../include/AGE2D.h>

namespace AGE2D
{
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
}

