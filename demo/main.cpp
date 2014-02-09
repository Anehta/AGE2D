#include "../include/age_system.h"
#include <../include/age_scene.h>
#include <../include/age_eventmgr.h>
#include <../include/age_sprite.h>

#include "game.h"

int main(int argc, char *argv[])
{
    ASystem::Init (argc,argv);
	Game::Init ();
    return ASystem::Go();
}
