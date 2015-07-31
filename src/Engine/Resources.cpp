#include "Resources.h"
Resources::Resources()
{
}

Resources::Resources(SDL_Renderer* renderer)
	:renderer(renderer)
{

}

Resources::~Resources()
{
}

TTF_Font* Resources::GetFont(const std::string & path, int size)
{
	std::map<std::string, TTF_Font*>::iterator itFont = loadedFonts.begin();
	std::stringstream ss;
	ss << path << "_" << size;
	if (loadedFonts[ss.str()] == nullptr)
	{
		loadedFonts[ss.str()] = LoadFonts(path, size);
	}
	return loadedFonts[ss.str()];
}
TTF_Font* Resources::LoadFonts(const std::string& path, int size)
{
	TTF_Font* loadedFont = TTF_OpenFont(path.c_str(), size);
	if (!loadedFont)
	{
		std::cout << "Failed to load font: " << path << " -- " << TTF_GetError();
	}
	return loadedFont;
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
