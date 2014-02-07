#ifndef DIAMOND_H
#define DIAMOND_H
#include "../include/AGE2D.h"

class Diamond : public AGE_Sprite
{
public:
    Diamond();
    Diamond(AGE_Texture * tex);
    bool out_of_the_boundary(double x,double y);
protected:
    virtual void action();

private:
    int r = rand()%5;
};

#endif // DIAMOND_H
