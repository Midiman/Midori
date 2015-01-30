#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"

int main(int argc, char* argv[])
{
	Game game(argc, argv);
	
	if( game.Init() ) {
		game.Run();
		game.End();
	}

	return 0;
}
