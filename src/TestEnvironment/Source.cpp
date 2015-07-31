#include <iostream>
#include "Engine.h"

#include "Game.h"

int main(int argc, char* args[])
{
	Engine::GetInstance()->Init();

	Game* game = new Game();

	Engine::GetInstance()->Start();

	delete game;

	return 0;
}