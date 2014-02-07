#include "game.h"
#include "../include/age_layer.h"
#include <QGLFunctions>

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
    testShaderProgram();
    back_ground_texture =new AGE_Texture(":/background.png");
    bullet_texture=new AGE_Texture (":/bullet.png");
    game_scene=new Gamescene();
    diamod_texture = new AGE_Texture(":/diamond.png");

	game_scene->setListenerManager (new AGE_EventMgr());
	hero=new Hero();
	game_scene->eventMgr ()->addKeyListener (hero);

    back_ground_actor =new BackGround;
	back_ground_actor->bindTexture (back_ground_texture);
    back_ground_actor->setX(-100);
    back_ground_actor->setY(-100);
    back_ground_actor->loadShaderProgram(m_program);

    game_scene->eventMgr()->addKeyListener(back_ground_actor);

	game_scene->addLayer (new AGE_Layer());
	game_scene->layer (1)->addChild (back_ground_actor);
	game_scene->layer (2)->addChild (hero);
	game_scene->activate ();
}
AGE_Scene *Game::getGameScene() const
{
	return game_scene;
}

void Game::setGameScene(AGE_Scene *value)
{
    //game_scene = value;
}

AGE_Texture *Game::getBullet_texture() const
{
	return bullet_texture;
}

void Game::setBullet_texture(AGE_Texture *value)
{
	bullet_texture = value;
}

AGE_Texture *Game::getDiamond_texture() const
{
    return diamod_texture;
}

void Game::setDiamond_texture(AGE_Texture *value)
{
    diamod_texture = value;
}

Hero* Game::getHero() const
{
    return hero;
}

void Game::testShaderProgram()
{

    m_program = new QGLShaderProgram();

    if(!m_program->addShaderFromSourceFile(QGLShader::Vertex,":/vshader.glsl"))
    {
        qDebug()<<"failed to init DefalutShaderProgram ---Vertex";
        return;
    }

    if(!m_program->addShaderFromSourceFile(QGLShader::Fragment,":/fshader.glsl"))
    {
        qDebug()<<"failed to init DefalutShaderProgram ---Fragment";
        return;
    }

    if(!m_program->link())
    {
        qDebug()<<"failed to init DefaultShaderProgram --- link";
        return;
    }

    /*if(!m_program->bind())
    {
        qDebug()<<"failed to init DefalutShaderProgram ---bind";
        return;
    }*/

   // m_program->removeAllShaders();
}
