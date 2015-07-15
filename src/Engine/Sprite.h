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

	float GetPosX() const { return posX; }
	float GetPosY() const { return posY; }

	void SetVisible(bool isVisible){ this->isVisible = isVisible; }
	void SetTexture(std::string* path);
	void SetPosition(float x, float y) { posX = x; posY = y; dstRect->x = x; dstRect->y = y; }

protected:
	void Start();
	void Update();
	void Draw();
	void Stop();

	SDL_Rect* dstRect;
	float posX;
	float posY;

private:
	bool isVisible;
	SDL_Texture* texture;

};

