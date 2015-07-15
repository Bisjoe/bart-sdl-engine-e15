#pragma once

#include "Obstacle.h"

class Car :
	public Obstacle
{
public:
	enum CAR_TYPE {RED, GREEN, BLUE};

	Car();
	Car(CAR_TYPE type);
	~Car();

private:
	static std::string CAR_RED_PATH;
	static std::string CAR_BLUE_PATH;
	static std::string CAR_GREEN_PATH;
};

