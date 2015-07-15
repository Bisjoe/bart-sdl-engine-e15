#include "Car.h"

std::string Car::CAR_RED_PATH = "Images/car-red.bmp";
std::string Car::CAR_BLUE_PATH = "Images/car-blue.bmp";
std::string Car::CAR_GREEN_PATH = "Images/car-green.bmp";

Car::Car()
{
}

Car::Car(CAR_TYPE type)
{
	switch (type)
	{
	case Car::RED:
		SetTexture(&CAR_RED_PATH);
		break;
	case Car::GREEN:
		SetTexture(&CAR_GREEN_PATH);
		break;
	case Car::BLUE:
		SetTexture(&CAR_BLUE_PATH);
		break;
	default:
		break;
	}
}

Car::~Car()
{
}
