#pragma once

#include "Common.h"

class Resources
{
public:
	Resources();
	Resources(SDL_Renderer* renderer);
	~Resources();

	SDL_Texture* GetTexture(std::string path);

private:
	SDL_Texture* LoadTexture(const char* filepath);

	SDL_Renderer* renderer;
	std::map<std::string, SDL_Texture*> textures;

};

