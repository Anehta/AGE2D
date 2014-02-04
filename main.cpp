#include "age_system.h"
#include <mylayer.h>
#include <age_scene.h>
#include <age_eventmgr.h>
#include <age_sprite.h>

int main(int argc, char *argv[])
{
	AGE_System::Init (argc,argv);

	MyLayer layer;
	layer.initResource();

	AGE_EventMgr mylistenerManager;
	mylistenerManager.addMouseListener (&layer);

	AGE_Scene scene;
	scene.setListenerManager(&mylistenerManager);

    AGE_Texture texture;
    texture.loadFile(":/3.png");

    //AGE_Sprite *sprite = new AGE_Sprite(&texture);
    scene.addLayer(&layer);
	scene.activate();

    return AGE_System::Go();
}
