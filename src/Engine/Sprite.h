#pragma once

#include "Component.h"
#include "Engine.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(std::string path);
	virtual ~Sprite();

	void SetPosition(int x, int y){ dstRect->x = x; dstRect->y = y; }

protected:
	void Start();
	void Update();
	void Draw();
	void Stop();

	SDL_Rect* dstRect;

private:
	SDL_Texture* texture;
	
};

