#include "gamescene.h"
#include "diamond.h"
#include "game.h"

Gamescene::Gamescene()
{

}

void Gamescene::init()
{

}

void Gamescene::action()
{
    static float value = 0;
    static bool fuck = true;

    if(fuck)
    {
        value += 0.005;
        if(value >1)
        {
            fuck = false;
        }
    }
    else
    {
        value -= 0.005;
        if(value <=0.005)
        {
            fuck = true;
        }
    }

    ASystem::GetWidget()->setWindowOpacity(value);
    /*if(value%2 == 1)
    {
        Diamond * fucker = new Diamond(Game::single()->getDiamond_texture());
        fucker->setX(rand()%ASystem::GetWidth());
        fucker->setY(ASystem::GetHeight()+10);
        Game::single()->getGameScene()->layer(1)->addChild(fucker);
    }*/
}
