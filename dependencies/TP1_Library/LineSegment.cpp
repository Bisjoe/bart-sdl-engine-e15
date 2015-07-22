#include "LineSegment.h"

//Default Ctor creating a null vector
LineSegment::LineSegment() 
	: from({ 0.f, 0.f })
	, to({0.f, 0.f})
	, normal({0.f, 0.f})
{
	std::cout << "Vecteur Null" << std::endl;
}

//Default Dtor
LineSegment::~LineSegment() {

}

//Ctor with float
//Create Segment from 2 pairs of coordinate
//Starting at from(fromx, fromY) and ending at to(toX, toY)
LineSegment::LineSegment(const float fromX, const float fromY, const float toX, const float toY) 
	: from ({ fromX, fromY })
	, to({ toX, toY })
{
	Vector2D temp = Substract(&to, &from);
	if (Normalize(&temp)) {
		normal = temp;
	} else {
		normal = { 0.f, 0.f };
		std::cout << "Vecteur Null" << std::endl;
	}
}

//Ctor with Vector2D
//Create Segment from 2 given Vector2D
LineSegment::LineSegment(const Vector2D* const from, const Vector2D* const to) 
{
	this->from = (*from);
	this->to = (*to);
	Vector2D temp = Substract(to, from);
	if (Normalize(&temp)) {
		normal = temp;
	}
	else {
		normal = { 0.f, 0.f };
		std::cout << "Vecteur Null" << std::endl;
	}
}

//Returns true if segment intersects with other segment
bool LineSegment::IntersectsWith(const LineSegment* const seg) {
	bool intersect = false;
	float rTop = (from.y - seg->from.y)*(seg->to.x - seg->from.x) - (from.x - seg->from.x)*(seg->to.y - seg->from.y);
	float sTop = (from.y - seg->from.y)*(to.x - from.x) - (from.x - seg->from.x)*(to.y - seg->from.y);
	float rsBot = (to.x - from.x)*(seg->to.y - seg->from.y) - (to.y - from.y)*(seg->to.x - seg->from.x);
	//If rsBot (denominator) is 0 segments are parallel
	if (rsBot != 0) {
		float r = rTop / rsBot;
		float s = sTop / rsBot;
		bool rIsGood = (r >= 0) && (r <= 1);
		bool sIsGood = (s >= 0) && (s <= 1);
		intersect = rIsGood && sIsGood;
	//If rTop (Numerator) is 0 too they are colinear
	} else if (rTop == 0) {
		intersect = true;
	//otherwise parallel not touching
	} else {
		intersect = false;
	}
	return intersect;
}