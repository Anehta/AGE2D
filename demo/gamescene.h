#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../include/AGE2D.h"
using namespace AGE2D;
class Gamescene : public AGE_Scene
{
public:
    Gamescene();
    void init();

protected:
    void action();

private:
    int value = 0;
};

#endif // GAMESCENE_H
