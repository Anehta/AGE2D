#ifndef GAME_H
#define GAME_H
#include "../include/age_texture.h"
#include "../include/age_scene.h"
#include "../include/age_spriteactor.h"
#include "../include/age_eventmgr.h"
#include "../include/age_audio.h"
#include <QGLShaderProgram>
#include <menu/menuscene.h>

using namespace AGE2D;
//管理整个游戏的资源
class Game : public QGLFunctions
{
public:
	static Game * single();
	static void Init();

private:
	Game();
	static Game *game;
    MenuScene * menu;
	AEventMgr * event_mgr;
};

#endif // GAME_H
