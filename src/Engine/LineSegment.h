#ifndef SEGMENT_H
#define SEGMENT_H

#include "Vector.h"

class LineSegment {
private:
	Vector2D from;
	Vector2D to;
	Vector2D normal;
public:
	LineSegment();
	~LineSegment();
	LineSegment(const float fromX, const float fromY, const float toX, const float toY);
	LineSegment(const Vector2D* const from, const Vector2D* const to);
	Vector2D GetFromPoint() const { return from; }
	Vector2D GetToPoint() const { return to; }
	Vector2D GetNormal() const { return normal; }
	// BONUS
	bool IntersectsWith(const LineSegment* const seg);
};


#endif