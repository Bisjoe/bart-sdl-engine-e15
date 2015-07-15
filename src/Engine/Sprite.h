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
	void SetVisible(bool isVisible){ this->isVisible = isVisible; }
	void SetTexture(std::string* path);

protected:
	void Start();
	void Update();
	void Draw();
	void Stop();

	SDL_Rect* dstRect;
	
private:
	bool isVisible;
	SDL_Texture* texture;

};

