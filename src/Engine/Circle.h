#ifndef CIRCLE_H
#define CIRCLE_H

#include "Rectangle.h"

class Circle {
private:
	float x, y, r;
public:
	//Ctro Dtor
	Circle();
	~Circle();
	Circle(const float x, const float y, const float radius);
	Circle(const Vector2D* const center, const float radius);
	//Getters Inline
	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetRadiusSq() const { return r*r; }
	float GetRadius() const { return r; }
	//Setters Inline
	void SetPosition(const Vector2D* const vect) { x = vect->x; y = vect->y; }
	void SetPosition(const float x, const float y) { this->x = x; this->y = y; }
	//Method
	bool Contains(const float x, const float y) const;
	bool Contains(const Vector2D* const point);
	void MoveBy(const Vector2D* const vect);
	void MoveBy(const float x, const float y);
	bool CollidesWith(const Circle* const circ) const;
	bool CollidesWith(const Rectangle* const rect) const;
};

#endif