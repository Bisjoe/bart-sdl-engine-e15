#pragma once

#include "Common.h"
#include "Component.h"
#include "Resources.h"

class Engine
{
#pragma region SINGLETON
public:
	static Engine* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Engine();
		}
		return instance;
	}

	static void Kill()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
private:
	Engine();
	Engine(const Engine& other){}
	~Engine();

	static Engine* instance;

	Engine& operator= (const Engine& other);
#pragma endregion
public:
	
	SDL_Renderer* GetRenderer() { return mRenderer; }
	Resources* GetResources() { return mResources; }

	void Init(int width, int height);
	void Start();
	void Stop();

private:

	void Run();
	void Update();
	void Draw();

	Resources* mResources;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	SDL_Event* mEvent;

	bool mIsInitialized;
}; 

