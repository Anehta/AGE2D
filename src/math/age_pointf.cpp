#include <../include/AGE2D.h>

namespace AGE2D
{
AGE_PointF::AGE_PointF()
{
}

AGE_PointF::AGE_PointF(float x,float y)
{
    setX(x);
    setY(y);
}

AGE_PointF::AGE_PointF(const AGE_Point point)
{
    setX(point.x());
    setY(point.y());
}

}
