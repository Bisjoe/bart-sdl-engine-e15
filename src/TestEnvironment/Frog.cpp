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
	// Obtain keyboard direction
	Vector2D dir = {
		cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_UP) &&				
		(!cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_LEFT) || 
		!cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_RIGHT))? -1 : 0 +    // X
		cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_DOWN) &&
		(!cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_LEFT) ||
		!cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_RIGHT)) ? 1 : 0
		,
		cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_LEFT) ? -1 : 0 +			// Y
		cEngine->GetInput()->IsKeyPressed(SDL_SCANCODE_RIGHT) ? 1 : 0
	};

	if (Normalize(&dir))
		SetPosition(Add(&GetPosition(), &Scale(&dir, speed)));
	
}