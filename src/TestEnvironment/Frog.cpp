#include "Frog.h"

const float Frog::speed = 0.5;

#define cEngine Engine::GetInstance()

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
	//Movement inputs for the frog
	Vector2D dir = {
		cInput->IsKeyPressed(SDL_SCANCODE_LEFT) &&
		(!cInput->IsKeyPressed(SDL_SCANCODE_UP) &&
		!cInput->IsKeyPressed(SDL_SCANCODE_DOWN)) ? -1 : 0 + // for X movements
		cInput->IsKeyPressed(SDL_SCANCODE_RIGHT) &&
		(!cInput->IsKeyPressed(SDL_SCANCODE_UP)) &&
		!cInput->IsKeyPressed(SDL_SCANCODE_DOWN) ? 1 : 0
		,
		cInput->IsKeyPressed(SDL_SCANCODE_UP) ? -1 : 0 + // for Y movements
		cInput->IsKeyPressed(SDL_SCANCODE_DOWN) ? 1 : 0
	};

	if (Normalize(&dir))
	{
		SetPosition(Add(&GetPosition(), &Scale(&dir, speed)));
	}
}