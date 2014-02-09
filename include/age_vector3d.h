#ifndef AVECTOR3D_H
#define AVECTOR3D_H

#include <QVector3D>
#include "age_point.h"
#include "age_pointf.h"
#include "age_vector2d.h"
#include "age_vector4d.h"
namespace AGE2D{

class AVector3D : public QVector3D
{
public:
    AVector3D();
    AVector3D(float,float,float);
    AVector3D(const APoint &point);
    AVector3D(const APointF &point);
    AVector3D(const AVector2D & vector);
    AVector3D(const AVector2D & vector,float zpos);
    AVector3D(const AVector4D & vector);
};
}


#endif // AVECTOR3D_H
