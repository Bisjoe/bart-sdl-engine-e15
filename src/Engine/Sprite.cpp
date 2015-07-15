#include "Sprite.h"

Sprite::Sprite()
	: texture(nullptr)
	, dstRect(nullptr)
{
}

Sprite::Sprite(std::string path)
{
	texture = Engine::GetInstance()->GetResources()->GetTexture(path);

	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
	SDL_QueryTexture(texture, 0, 0, &dstRect->w, &dstRect->h);
}

Sprite::~Sprite()
{
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
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), texture, 0, dstRect);
}

void Sprite::Stop()
{

}
