#include "Engine.h"

Engine* Engine::instance = nullptr;

Engine::Engine()
	: mIsInitialized(false)
	, mWindow(nullptr)
	, mRenderer(nullptr) 
	, mEvent(nullptr)
{ 
}

Engine::~Engine()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	delete mEvent;
	delete mResources;
}

void Engine::Init(int width = DEFAULT_WINDOW_WIDTH, int height = DEFAULT_WINDOW_HEIGHT)
{
	mIsInitialized = true;

	mEvent = new SDL_Event();

	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		mIsInitialized = false;
	}
	else
	{
		std::stringstream ss;
		ss << DEFAULT_WINDOW_TITLE << "MyGameName";

		// Create the window frame
		mWindow = SDL_CreateWindow(ss.str().c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_SHOWN);

		// Validate that a window has been created
		if (mWindow == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			mIsInitialized = false;
		}
		else
		{
			mRenderer = SDL_CreateRenderer(mWindow, -1,
				SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

			if (mRenderer == nullptr)
			{
				printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
				mIsInitialized = false;
			}
			else
			{
				// dependancie injection
				mResources = new Resources(mRenderer);
			}
		}
	}
}

void Engine::Start()
{
	std::vector<Component*>::const_iterator iter;
	for (iter = Component::components.begin();
		iter != Component::components.end(); iter++)
	{
		(*iter)->Start();
	}

	Run();
}

void Engine::Stop()
{
	std::vector<Component*>::const_iterator iter;
	for (iter = Component::components.begin();
		iter != Component::components.end(); iter++)
	{
		(*iter)->Stop();
	}
}

void Engine::Run()
{
	bool mQuit = false;

	while (!mQuit)
	{
		while (SDL_PollEvent(mEvent) != 0)
		{
			switch (mEvent->type)
			{
			case SDL_QUIT:
				mQuit = true;
				break;
			case SDL_KEYDOWN:
				if (mEvent->key.keysym.sym == SDLK_ESCAPE)
				{
					mQuit = true;
					break;
				}
			}
		}

		Update();
		Draw();
	}

	Stop();
}

void Engine::Update()
{
	std::vector<Component*>::const_iterator iter;
	for (iter = Component::components.begin();
		iter != Component::components.end(); iter++)
	{
		(*iter)->Update();
	}
}

void Engine::Draw()
{
	SDL_RenderClear(mRenderer);

	std::vector<Component*>::const_iterator iter;
	for (iter = Component::components.begin();
		iter != Component::components.end(); iter++)
	{
		(*iter)->Draw();
	}

	SDL_RenderPresent(mRenderer);
}


