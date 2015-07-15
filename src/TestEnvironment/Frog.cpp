#include "Frog.h"

const float Frog::speed = 0.5;

Frog::Frog()
	: Sprite(FROG_PATH)
	, currentPosX(0.f)
{
}

Frog::~Frog()
{
}

void Frog::Update()
{
	currentPosX += speed;
	dstRect->x = currentPosX;
}