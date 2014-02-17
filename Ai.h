#ifndef AI_H
#include "../include/age_sprite.h"
#include "../include/age_texture.h"
#include "../include/age_accumulator.h"
#include "../include/age_audio.h"
#include "../include/age_framelistener.h"
#include "../include/age_frame.h"
#include "particle.h"
#include "particlelauncher.h"
#include <time.h>
#define AI_H
//1080*1920
using namespace AGE2D;
class Ai :public ASprite,public AFrameListener
{
protected:
     ATexture* AI;
     QString name;
     AAccumulator *fire_cd;
     AAccumulator *AiNum;
     AAccumulator *stayTime;
     AAccumulator *AiCd;
     bool is_firing;
     int from;
     int inX;
     int inY;
     int outX;
     int outY;
     int stayX;
     int stayY;
public:
    Ai();
    void InIt()
    {
        from = 0;
        inX = 0;
        inY = 0;
        outX = 0;
        outY = 0;
        stayX = 0;
        stayY = 0;
        is_firing = false;
    }
    int getRand(int s);
    void action();
    void AiIn(int x,int y);
    void AiStay();
    void AiOut(int x,int y);
    ATexture *getBullet_texture() const;
    void setBullet_texture(ATexture *value);
    ATexture *getAi_texture() const;
    void setAi_texture(ATexture *value);
};

#endif // AI_H
