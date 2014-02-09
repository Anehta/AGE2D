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
    background_music = new AAudio(":/123.mp3",0);
    background_music->setVolume(100);
    background_music->audio();
    background_music->play();

    back_ground_texture =new ATexture(":/background.png");
    bullet_texture=new ATexture (":/bullet.png");
    game_scene=new Gamescene();
    diamod_texture = new ATexture(":/diamond.png");

    game_scene->setListenerManager (new AEventMgr());
	hero=new Hero();
	game_scene->eventMgr ()->addKeyListener (hero);

    back_ground_actor =new BackGround;
	back_ground_actor->bindTexture (back_ground_texture);
    back_ground_actor->setX(-100);
    back_ground_actor->setY(-100);
    back_ground_actor->loadShaderProgram(m_program);

    game_scene->eventMgr()->addKeyListener(back_ground_actor);

    game_scene->addLayer (new ALayer());
	game_scene->layer (1)->addChild (back_ground_actor);
	game_scene->layer (2)->addChild (hero);
	game_scene->activate ();
}

AScene *Game::getGameScene() const
{
	return game_scene;
}

void Game::setGameScene(AScene *)
{
    //game_scene = value;
}

ATexture *Game::getBullet_texture() const
{
	return bullet_texture;
}

void Game::setBullet_texture(ATexture *value)
{
	bullet_texture = value;
}

ATexture *Game::getDiamond_texture() const
{
    return diamod_texture;
}

void Game::setDiamond_texture(ATexture *value)
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
