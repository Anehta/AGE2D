#ifndef GAME_H
#define GAME_H
#include "../include/age_texture.h"
#include "../include/age_scene.h"
#include "../include/age_spriteactor.h"
#include "../include/age_eventmgr.h"
#include "../include/age_audio.h"

#include "hero.h"
#include "background.h"
#include <QGLShaderProgram>
#include <gamescene.h>

using namespace AGE2D;
//管理整个游戏的资源
class Game : public QGLFunctions
{
public:
	static Game * single();
	static void Init();
    ATexture *getBullet_texture() const;
    void setBullet_texture(ATexture *value);

    ATexture *getDiamond_texture() const;
    void setDiamond_texture(ATexture *value);

	AScene *getGameScene() const;
	void setGameScene(AScene *value);

    Hero * getHero() const;

private:
	Game();
	static Game *game;

	AEventMgr * event_mgr;
    //ATexture * hero_texture;
    ATexture * back_ground_texture;
    ATexture * bullet_texture;
    ATexture * diamod_texture;
    AAudio *background_music;

    Gamescene * game_scene;

    BackGround * back_ground_actor;
	Hero * hero;

    QGLShaderProgram *m_program;

    void testShaderProgram();
};

#endif // GAME_H
