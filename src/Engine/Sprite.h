#pragma once
#include "Common.h"
#include "Component.h"
#include "Engine.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite::Sprite(float x, float y);
	Sprite(std::string path);
	virtual ~Sprite();

	float GetX() const { return x; }
	float GetY() const { return y; }
	Vector2D GetPosition() const { return { x, y }; }
	Vector2D GetSize() const { return{ dstRect->w, dstRect->h }; }
	bool GetVisible(){ return isVisible; }

	void SetVisible(bool isVisible){ this->isVisible = isVisible; }
	void SetTexture(std::string* path);
	void SetTexture(SDL_Texture* tex);

	void SetPosition(float x, float y) { this->x = x; this->y = y; dstRect->x = (int)x; dstRect->y = (int)y; }
	void SetPosition(Vector2D &v){ SetPosition(v.x, v.y); }

protected:
	void Start();
	void Update();
	void Draw();
	void Stop();

	bool isVisible;

private:
	
	float x;
	float y;

	SDL_Rect* dstRect;
	SDL_Texture* texture;

};

