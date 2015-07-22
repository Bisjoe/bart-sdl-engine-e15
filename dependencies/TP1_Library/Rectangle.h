#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector.h"

class Rectangle {
private:
	float x, y, width, height;
public:
	//Ctor Dtor
	Rectangle();
	~Rectangle();
	Rectangle(const float x, const float y, const float width, const float height);
	Rectangle(const Vector2D* const topLeft, const Vector2D* const btmRight);
	//Getters Inline
	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetWidth() const { return width; }
	float GetHeight() const { return height; }
	//Setters Inline
	void SetPosition(const Vector2D* const vect) { x = vect->x; y = vect->y; }
	void SetPosition(const float x, const float y) { this->x = x, this->y = y; }
	void SetWidth(const float w) { this->width = w; }
	void SetHeight(const float h) { this->height = h; }
	//Method
	bool Contains(const float x, const float y) const;
	bool Contains(const Vector2D* const point) const;
	void MoveBy(const Vector2D* const vect);
	void MoveBy(const float x, const float y);
	bool CollidesWith(const Rectangle* const rect) const;
};

#endif