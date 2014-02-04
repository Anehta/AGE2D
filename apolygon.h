#ifndef APOLYGON_H
#define APOLYGON_H
#include <list>
#include <QVector2D>
#include <vector>

class APolygon
{
public:
    APolygon();
    int pointInPolygon(QVector2D);
    int pointInPolygon2(QVector2D);
    void addPoint(double x,double y);
private:
    std::vector<QVector2D> m_pointList;
    int IsIntersectAnt(double x,double y,double X1,double Y1,double X2,double Y2);
};

#endif // APOLYGON_H
