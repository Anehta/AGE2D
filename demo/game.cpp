#include "game.h"
#include "../include/age_layer.h"
#include <QGLFunctions>
#include "../include/age_baseentity.h"
Game * Game::game;

Game *Game::single()
{
	return game;
}

void Game::Init()
{
    game= new Game();
}

Game::Game()
{
    ASystem::SetSize(1080,1920);
    ASystem::GetWidget()->setWindowTitle("AGE");
    menu = new MenuScene();
    menu->activate();
}
