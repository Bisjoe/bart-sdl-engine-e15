#pragma once

#include "Sprite.h"
#include "Engine.h"

#define FROG_PATH "Images/Hello.bmp"

class Frog :
	public Sprite
{
public:
	Frog();
	~Frog();

protected:
	void Update();

private:
	float currentPosX;
	static const float speed;

	bool isPressed;
};

