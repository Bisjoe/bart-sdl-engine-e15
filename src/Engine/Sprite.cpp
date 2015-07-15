#include "Sprite.h"

Sprite::Sprite()
	: texture(nullptr)
	, dstRect(nullptr)
	, isVisible(true)
{
	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
}

Sprite::Sprite(std::string path)
	: texture(nullptr)
	, dstRect(nullptr)
	, isVisible(true)
{
	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;

	SetTexture(&path);
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(std::string* path)
{
	texture = Engine::GetInstance()->GetResources()->GetTexture(path);

	if (texture)
	{
		SDL_QueryTexture(texture, 0, 0, &dstRect->w, &dstRect->h);
	}
}

void Sprite::Start()
{

}

void Sprite::Update()
{
	int i = 5;
}

void Sprite::Draw()
{
	if (isVisible)
	{
		if (texture)
		{
			SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), texture, 0, dstRect);
		}
	}
}

void Sprite::Stop()
{

}
