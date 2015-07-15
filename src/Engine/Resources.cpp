#include "Resources.h"

Resources::Resources()
{
}

Resources::Resources(SDL_Renderer* renderer)
	: renderer(renderer)
{
}

Resources::~Resources()
{
}

SDL_Texture* Resources::GetTexture(std::string* path)
{
	if (textures[*path] == nullptr)
	{
		textures[*path] = LoadTexture((*path).c_str());
	}
	return textures[*path];
}

SDL_Texture* Resources::LoadTexture(const char* filepath)
{
	SDL_Texture* image = nullptr;
	image = IMG_LoadTexture(renderer, filepath);
	if (image == nullptr)
	{
		printf("Unable to load image: %s! %s\n", filepath, SDL_GetError());
	}
	return image;
}
