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

	float GetX() const { return x; }
	float GetY() const { return y; }

	void SetVisible(bool isVisible){ this->isVisible = isVisible; }
	void SetTexture(std::string* path);
	void SetPosition(float x, float y) { this->x = x; this->y = y; dstRect->x = x; dstRect->y = y; }

protected:
	void Start();
	void Update();
	void Draw();
	void Stop();

private:

	bool isVisible;
	float x;
	float y;

	SDL_Rect* dstRect;
	SDL_Texture* texture;

};

