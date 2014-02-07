#include <../include/AGE2D.h>

AGE_Vector4D::AGE_Vector4D()
{

}

AGE_Vector4D::AGE_Vector4D(const QVector4D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(vector.z());
    setW(vector.w());
}

AGE_Vector4D::AGE_Vector4D(float xpos, float ypos, float zpos, float wpos)
{
    setX(xpos);
    setY(ypos);
    setZ(zpos);
    setW(wpos);
}

AGE_Vector4D::AGE_Vector4D(const AGE_Point &point)
{
    setX(point.x());
    setY(point.y());
    setZ(0);
    setW(0);
}

AGE_Vector4D::AGE_Vector4D(const AGE_PointF &point)
{
    setX(point.x());
    setY(point.y());
    setZ(0);
    setW(0);
}

AGE_Vector4D::AGE_Vector4D(const AGE_Vector2D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(0);
    setW(0);
}

AGE_Vector4D::AGE_Vector4D(const AGE_Vector2D &vector,float zpos,float wpos)
{
    setX(vector.x());
    setY(vector.y());
    setZ(zpos);
    setW(wpos);
}

AGE_Vector4D::AGE_Vector4D(const AGE_Vector3D &vector)
{
    setX(vector.x());
    setY(vector.y());
    setZ(vector.z());
    setW(0);
}

AGE_Vector4D::AGE_Vector4D(const AGE_Vector3D &vector,float wpos)
{
    setX(vector.x());
    setY(vector.y());
    setZ(vector.z());
    setW(wpos);
}
