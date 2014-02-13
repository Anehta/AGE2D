#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "../include/age_scene.h"
#include "../include/age_texture.h"
#include "../include/age_sprite.h"

using namespace AGE2D;

class MenuScene : public AScene,public AMouseListener,public AKeyListener
{
public:
    MenuScene();

protected:
    void action();
    void onMouseMove(AMouseInfo info); //鼠标事件管理器
    void onMousePress(AMouseInfo info);
    void onMouseRelease(AMouseInfo info);

private:
    /*texture*/
    ATexture * menuCircle_texture;
    ATexture * menuFrame_texture;
    ATexture * menuBackGround_texture;

    /*button sprite*/
    ASprite * menu_game_button_sprite;
    ASprite * menu_achievement_button_sprite;
    ASprite * menu_set_button_sprite;
    /*effect sprite*/
    ASprite * menuFrame_sprite;
    ASprite * menuBackGround_sprite;

    float background_rotate;
    float botton_rotate;
    bool isPress;
    float mouseX;
    float mouseY;

    void initResource();
    void initActor();
    void initData();
};

#endif // MENUSCENE_H
