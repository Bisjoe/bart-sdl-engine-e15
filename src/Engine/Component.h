#pragma once

#include "Common.h"

class Component
{
	friend class Engine;

public:
	Component();
	virtual ~Component();

protected:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Stop();

private:
	static std::vector<Component*> components;
};

