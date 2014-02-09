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
	AATexture *getBullet_texture() const;
	void setBullet_texture(AATexture *value);

    AATexture *getDiamond_texture() const;
    void setDiamond_texture(AATexture *value);

	AScene *getGameScene() const;
	void setGameScene(AScene *value);

    Hero * getHero() const;

private:
	Game();
	static Game *game;

	AEventMgr * event_mgr;
	//AATexture * hero_texture;
	AATexture * back_ground_texture;
	AATexture * bullet_texture;
    AATexture * diamod_texture;
    AAudio *background_music;
    Gamescene * game_scene;

    BackGround * back_ground_actor;
	Hero * hero;

    QGLShaderProgram *m_program;

    void testShaderProgram();
};

#endif // GAME_H
