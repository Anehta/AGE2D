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
    value++;
    if(value%2 == 1)
    {
        Diamond * fucker = new Diamond(Game::single()->getDiamond_texture());
        fucker->setX(rand()%ASystem::GetWidth());
        fucker->setY(ASystem::GetHeight()+10);
        Game::single()->getGameScene()->layer(1)->addChild(fucker);
    }
}
