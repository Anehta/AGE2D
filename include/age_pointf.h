#ifndef AGE_POINTF_H
#define AGE_POINTF_H

#include <QPointF>
#include <../include/AGE2D.h>

class AGE_PointF : public QPointF
{
public:
    AGE_PointF();
    AGE_PointF(float x,float y);
    AGE_PointF(const AGE_Point point);
};

#endif // AGE_POINTF_H
