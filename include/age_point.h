#ifndef AGE_POINT_H
#define AGE_POINT_H

#include <QPoint>

namespace AGE2D{
class AGE_Point : public QPoint
{
public:
    AGE_Point();
    AGE_Point(int x,int y);
};
}


#endif // AGE_POINT_H
