#pragma once
#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif

#include <iostream>
#include "Controller.h"


/*This is the main function that runs the program.*/
int main()
{
	srand((unsigned)time(nullptr));
	
	Controller gameRun("Levels.txt");//building the foundation of the game.
	gameRun.gamePlay();
	

	return 0;
}



