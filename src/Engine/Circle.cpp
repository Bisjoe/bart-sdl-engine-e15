#include "Circle.h"

//Default Ctor, Circle "null"
Circle::Circle() 
	: x(0.f)
	, y(0.f)
	, r(0.f)
{

}

//Default Dtor
Circle::~Circle() {

}

//Ctor with center coordinate and radius
Circle::Circle(const float x, const float y, const float radius)
	: x(x)
	, y(y)
	, r(abs(radius))
{

}

//Ctor with center vector and radius
Circle::Circle(const Vector2D* const center, const float radius)
	: x(center->x)
	, y(center->y)
	, r(abs(radius))
{

}

//Change center coordinate to vector
void Circle::MoveBy(const Vector2D* const vect) {
	MoveBy(vect->x, vect->y);
}

//Change center coordinate to new coordinate
void Circle::MoveBy(const float x, const float y) {
	SetPosition(GetX() + x, GetY() + y);
}

//Returns true if Circle collides with other circle
bool Circle::CollidesWith(const Circle* const circ) const {
	Vector2D temp = { circ->GetX() - GetX(), circ->GetY() - GetY() };
	bool isColliding = LengthSq(&temp) <= (GetRadius() + circ->GetRadius());
	return isColliding;
}

//Return true if coordinate is inside Circle
bool Circle::Contains(const float x, const float y) const {
	Vector2D temp;
	temp.x = x - GetX();
	temp.y = y - GetY();
	bool isIn = LengthSq(&temp) <= GetRadiusSq();
	return isIn;
}

//Return true if vector is inside Circle
bool Circle::Contains(const Vector2D* const point) {
	return Contains(point->x, point->y);
}

//Return true if collides with a rectangle
bool Circle::CollidesWith(const Rectangle* const rect) const {
	bool check;
	//Get half the width and half the height to calculate from center
	float rHalfx = rect->GetWidth() / 2;
	float rHalfy = rect->GetHeight() / 2;
	//Get absolute dist between centers so calculations for every quadrant isn't necessary
	float cDistx = abs(GetX() - (rect->GetX() + rHalfx));
	float cDisty = abs(GetY() - (rect->GetY() + rHalfy));
	//If rect is too far away from circle for any collision being possible
	if (cDistx > (rHalfx + GetRadius()) || cDisty > (rHalfy + GetRadius())) {
		check = false;
	//If rect is close enough to circle so collision is inevitable
	} else if (cDistx <= rHalfx || cDisty <= rHalfy) {
		check = true;
	//If circle and rect just barely touch each other on a single point
	} else {
		float cornerDistSq = pow((cDistx - rHalfx), 2) + pow((cDisty - rHalfy), 2);
		check = cornerDistSq <= GetRadiusSq();
	}
	return check;
}