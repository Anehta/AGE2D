#include <../include/AGE2D.h>

AGE_Vector3D::AGE_Vector3D()
{
}

AGE_Vector3D::AGE_Vector3D(float x, float y, float z)
{
    setX(x);
    setY(y);
    setZ(z);
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
