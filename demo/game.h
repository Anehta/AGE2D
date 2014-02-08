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
//管理整个游戏的资源
class Game : public QGLFunctions
{
public:
	static Game * single();
	static void Init();
	AGE_Texture *getBullet_texture() const;
	void setBullet_texture(AGE_Texture *value);

    AGE_Texture *getDiamond_texture() const;
    void setDiamond_texture(AGE_Texture *value);

	AGE_Scene *getGameScene() const;
	void setGameScene(AGE_Scene *value);

    Hero * getHero() const;

private:
	Game();
	static Game *game;

	AGE_EventMgr * event_mgr;
	//AGE_Texture * hero_texture;
	AGE_Texture * back_ground_texture;
	AGE_Texture * bullet_texture;
    AGE_Texture * diamod_texture;
    AGE_Audio *background_music;
    Gamescene * game_scene;

    BackGround * back_ground_actor;
	Hero * hero;

    QGLShaderProgram *m_program;

    void testShaderProgram();
};

#endif // GAME_H
