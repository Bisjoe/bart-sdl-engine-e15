#include <iostream>
#include "Engine.h"

#include "Frog.h"

int main(int argc, char* args[])
{
	Engine::GetInstance()->Init();

	// Créer nos objets

	Sprite* s1 = new Sprite("Images/Hello.bmp");
	s1->SetPosition(100, 100);

	Frog* frog = new Frog();
	frog->SetPosition(300, 300);

	Engine::GetInstance()->Start();

	//delete c1;
	//delete s1;

	return 0;
}



