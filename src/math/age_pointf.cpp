#include <../include/AGE2D.h>

namespace AGE2D
{
APointF::APointF()
{
}

APointF::APointF(float x,float y)
{
    setX(x);
    setY(y);
}

APointF::APointF(const APoint point)
{
    setX(point.x());
    setY(point.y());
}

}
