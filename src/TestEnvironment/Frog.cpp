#include "Frog.h"

const float Frog::speed = 0.5;

Frog::Frog()
	: Sprite(FROG_PATH)
	, currentPosX(0.f)
	, isPressed(false)
{
}

Frog::~Frog()
{
}

void Frog::Update()
{

	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_UP))
	{
		std::cout << "key pressed" << std::endl;
	}

	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_UP))
	{
		std::cout << "key held" << std::endl;
	}

	SetPosition(GetX() + speed, GetY());
}