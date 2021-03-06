#pragma once

#include "Common.h"
#include "Component.h"
#include "Resources.h"
#include "Input.h"
#include "SDL_ttf.h"


#define cEngine Engine::GetInstance()
#define cInput cEngine->GetInput()

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

	
	void Init(int width = DEFAULT_WINDOW_WIDTH, int height = DEFAULT_WINDOW_HEIGHT);
	void Start();
	void Stop();
	Input* GetInput(){ return inputs; }

private:

	void Run();
	void Update();
	void Draw();

	Resources* mResources;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	SDL_Event* mEvent;
	Input* inputs;

	bool mIsInitialized;
}; 

