#include "../AI/ai.h"
#include "../include/age_vector2d.h"
#include "../include/age_system.h"
#include "../include/age_layer.h"
#include "../include/age_scene.h"
#include <qdebug.h>
#include "game.h"
#define MAX_X 1080
#define MAX_Y 1920


Ai::Ai()
{
    InIt();
    this->AI= new ATexture(":/image/AI.png");
    this->bindTexture(AI);
    this->setPos(AVector2D(0,0));
    this->setWidth(150);
    this->setHeight(150);
    this->fire_cd= new AAccumulator(0,3,0.01,false);
    this->AiCd = new AAccumulator(0,10,0.01,false);
    this->AiNum = new AAccumulator(0,5,1,false);
    this->stayTime = new AAccumulator(0,5,0.01,false);
}

int Ai::getRand(int s)
{
    srand((unsigned) time(NULL));
    return rand() % s;
}

void Ai::AiIn(int x,int y)
{
    this->inX = x;
    this->inY = y;
}

void Ai::AiOut(int x,int y)
{
    this->outX = x;
    this->outY = y;
}

void Ai::AiStay()
{
    this->stayX = getRand(MAX_X);
    this->stayY = getRand(MAX_Y);
}

void Ai::action()
{
        if(this->inX > this->stayX)
        {
            this->setX((float)this->inX - 1);
            this->inX--;
            qDebug()<<this->inX<<this->inY<<endl;
        }
         if(this->inX < this->stayX)
        {
            this->setX((float)this->inX + 1);
            this->inX++;
            qDebug()<<this->inX<<this->inY<<endl;
        }
        if(this->inY > this->stayY)
        {
            this->setY((float)this->inY - 1);
            this->inY--;
            qDebug()<<this->inX<<this->inY<<endl;
        }
        if(this->inY < this->stayY)
        {
            this->setY((float)this->inY + 1);
            this->inY++;
            qDebug()<<this->inX<<this->inY<<endl;
        }
        if(this->inX == this->stayX && this->inY == this->stayY)
        {
            this->inX = this->stayX;
            this->inY = this->stayY;
            qDebug()<<this->inX<<this->inY<<endl;
            this->setY((float)this->inY);
            this->setX((float)this->inX);
            stayTime->step(ASystem::TimeStep());
            fire_cd->step (ASystem::TimeStep());
            AScene * game_scene=Game::single ()->getGame_scene();
            ParticleLauncher(game_scene->layer(2),Game::single()->getBullet_texture(),5,AVector2D(this->getX(),this->getY()),
                             AVector2D(100,100),AVector2D(0,0),AColor(1,1,1),
                             AColor(0,1,1),0,300,1,0,4,AVector2D(0,-2),10);

            if(fire_cd->isTouched ())
            {
                fire_cd->rewind ();
                if(is_firing)
                {
                    game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15,this->middleY()-15),1,0.5,true));
                    game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15-50,this->middleY()-15-50),1,0.5,true));
                    game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15+50,this->middleY()-15-50),1,0.5,true));
                    game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15-25,this->middleY()-15-75),1,0.5,true));
                    game_scene->layer (2)->addChild (new Bullet(AVector2D(this->middleX()-15+25,this->middleY()-15-75),1,0.5,true));
                }
            }
            if(stayTime->isTouched())
            {
                this->stayX = this->outX;
                this->stayY = this->outY;
            }
        }
        if(this->inX == this->outX && this->inY == this->outY)
        {
            this->destroy();
        }
}

ATexture *Ai::getAi_texture() const
{
    return AI;
}

void Ai::setAi_texture(ATexture *value)
{
    AI = value;
}
