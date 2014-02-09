#ifndef APOLYGON_H
#define APOLYGON_H

#include <list>
#include <vector>
#include <../include/AGE2D.h>

namespace AGE2D
{
class AGE_Vector2D;
class AGE_Polygon
{
public:
    AGE_Polygon();
    int pointInPolygon(AGE_Vector2D);
    int pointInPolygon2(AGE_Vector2D);
    void addPoint(double x,double y);
private:
    std::vector<AGE_Vector2D> m_pointList;
    int IsIntersectAnt(double x,double y,double X1,double Y1,double X2,double Y2);
};

}

#endif // APOLYGON_H
