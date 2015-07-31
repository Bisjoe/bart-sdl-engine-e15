#pragma once

#include "Common.h"

class Resources
{

public:
	
	Resources();
	Resources(SDL_Renderer* renderer);
	~Resources();

	SDL_Texture* GetTexture(std::string* path);
	TTF_Font* GetFont(const std::string & path, int size);
	
private:
	SDL_Renderer* renderer;
	SDL_Texture* LoadTexture(const char* filepath);
	TTF_Font* LoadFonts(const std::string& path, int size);

	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, TTF_Font*> loadedFonts;

};

