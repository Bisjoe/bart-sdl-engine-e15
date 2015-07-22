#include "Rectangle.h"

//Default Ctor, Rectangle "null"
Rectangle::Rectangle() 
	: x(0.f)
	, y(0.f)
	, width(0.f)
	, height(0.f)
{

}

//Default Dtor
Rectangle::~Rectangle() {

}

//Ctor with Top-Left coordinate and width and height
Rectangle::Rectangle(const float x, const float y, const float width, const float height)
	: x(x)
	, y(y)
	, width(abs(width))
	, height(abs(height))
{
	
}

//Ctor with Top-Left vector and bottom right vector
Rectangle::Rectangle(const Vector2D* const topLeft, const Vector2D* const btmRight) {
	//Check if Top-Left is really left
	if (topLeft->x <= btmRight->x) {
		this->x = topLeft->x;
		this->width = btmRight->x - topLeft->x;
	} else {
		this->x = btmRight->x;
		this->width = topLeft->x - btmRight->x;
	}
	//Check if Top-Left is really top
	if (topLeft->y <= btmRight->y) {
		this->y = topLeft->y;
		this->height = btmRight->y - topLeft->y;
	} else {
		this->y = btmRight->y;
		this->height = topLeft->y - btmRight->y;
	}
}

//Move top-left coordinate of rectangle to vector
void Rectangle::MoveBy(const Vector2D* const vect) {
	MoveBy(vect->x, vect->y);
}

//Move top-left coordinate of rectangle to new coordinate
void Rectangle::MoveBy(const float x, const float y) {
	SetPosition(GetX() + x, GetY() + y);
}

//Returns true if colliding with another rectangle
bool Rectangle::CollidesWith(const Rectangle* const rect) const {
	bool temp = false;
	//Check if at least 1 corner of both rectangle is inside the other
	temp = Contains(rect->GetX(), rect->GetY()) ||
		   Contains(rect->GetX() + rect->GetWidth(), rect->GetY()) ||
		   Contains(rect->GetX(), rect->GetY() + rect->GetHeight()) ||
		   Contains(rect->GetX() + rect->GetWidth(), rect->GetY() + rect->GetHeight()) ||
		   rect->Contains(GetX(), GetY()) ||
		   rect->Contains(GetX() + GetWidth(), GetY()) ||
		   rect->Contains(GetX(), GetY() + GetHeight()) ||
		   rect->Contains(GetX() + GetWidth(), GetY() + GetHeight());
	return temp;
}

//Returns true if coordinates are in the rectangle
bool Rectangle::Contains(const float x, const float y) const {
	bool xIn = (x >= GetX()) && (x <= (GetX() + GetWidth()));
	bool yIn = (y >= GetY()) && (y <= (GetY() + GetHeight())); 
	return xIn && yIn;
}

//Returns true if vector is in the rectangle
bool Rectangle::Contains(const Vector2D* const point) const {
	return Contains(point->x, point->y);
}