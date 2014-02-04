#ifndef MYLAYER_H
#define MYLAYER_H
#include <age_layer.h>
#include <age_eventlistener.h>
#include <age_texture.h>
#include <age_mouselistener.h>
#include <age_vector2d.h>

class MyLayer : public AGE_Layer,public AGE_MouseListener
{
public:
    MyLayer();
    void initResource();
protected:
    void onMouseMove(AGE_MouseInfo);
    void onMousePress(AGE_MouseInfo );
    void onMouseRelease(AGE_MouseInfo);
    void action();
private:
     AGE_Texture * texture;
     AGE_Texture * backGroundTexture;
    bool isPress = false;
    float mousex = 0;
    float mousey = 0;
};


#endif // MYLAYER_H
