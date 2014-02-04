#include "apolygon.h"
#include <math.h>
#include <QVector3D>
#include <QDebug>

using namespace std;
#define EPSILON 0.00001

APolygon::APolygon()
{
}

void APolygon::addPoint(double x, double y)
{
    m_pointList.push_back(QVector2D(x,y));
}

int APolygon::pointInPolygon(QVector2D poPoint)
{
        //计算该点向左方向的射线与各个边的交点个数
        int nCount = 0;
        double X = poPoint.x();
        double Y = poPoint.y();
    qDebug()<<"x is :"<<X<<" y is :"<<Y;
    qDebug()<<"the polygon is";
    for(std::vector<QVector2D>::iterator it = m_pointList.begin();
        it!= m_pointList.end();
        ++it)
    {
        qDebug()<<"x is :"<<it->x()<<" y is :"<<it->y();
    }
        int nFlag = 0;

        for(std::vector<QVector2D>::iterator it = m_pointList.begin();
        it!= m_pointList.end();
            ++it)
        {
        if(it!=m_pointList.end()-1)
        {
            nFlag = IsIntersectAnt(X,Y,it->x(),it->y(),
                (it+1)->x(),(it+1)->y());
        }
        else
        {
            nFlag = IsIntersectAnt(X,Y,it->x(),it->y(),
                (m_pointList.begin())->x(),(m_pointList.begin())->y());
        }

        qDebug()<<"the flag"<<nFlag;
                if (nCount < 0)
                {
                    return 2;   //点在边上
        }
                nCount += nFlag;
        }

        if (nCount % 2 == 1)   //点在多边形内
        {
            return 1;
        }
        else
            return 0;
}

int APolygon::IsIntersectAnt(double x, double y, double X1, double Y1, double X2, double Y2)
{

    QVector2D  far_point(1000,1000);
    QVector2D touch_point(x,y);
    QVector2D line_point1(X1,Y1);
    QVector2D line_point2(X2,Y2);
    QVector3D line_1=line_point2 -line_point1;
    QVector3D line_2=far_point -line_point1;
    QVector3D line_3=touch_point - line_point1;

    QVector3D cross_product_1=QVector3D::crossProduct (line_2,line_1);
    QVector3D cross_product_2=QVector3D::crossProduct (line_3,line_1);
    int result1=cross_product_1.z ()*cross_product_2.z ();


     line_1=far_point -touch_point;
     line_2=line_point1 -touch_point;
     line_3=line_point2 - touch_point;
     cross_product_1=QVector3D::crossProduct (line_2,line_1);
     cross_product_2=QVector3D::crossProduct (line_3,line_1);
     int result2=cross_product_1.z ()*cross_product_2.z ();

     if(result2<-EPSILON&& result1<-EPSILON)//相互跨立,所以线段相交
     {
         return 1;
     }
     else if(fabs(result1)<EPSILON ||fabs(result2)<EPSILON ) //点在线上
     {
         return -1;
     }
     else
     {
         return 0;
     }

}

int APolygon::pointInPolygon2(QVector2D poPoint)
{
    QVector3D p(poPoint.x(),poPoint.y(),0);
    for(std::vector<QVector2D>::iterator it = m_pointList.begin();
        it!= m_pointList.end()-1;
        ++it);
}
