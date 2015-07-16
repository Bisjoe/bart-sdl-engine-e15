#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

struct Vector2D {
	float x, y;
};

struct Vector3D {
	float x, y, z;
};

const float PI = 3.1415926535897f;
const double EPSILON = 0.0001;

//Vector 2D
Vector2D Add(const Vector2D* const left, const Vector2D* const right);
Vector2D Substract(const Vector2D* const left, const Vector2D* const right);
Vector2D Scale(const Vector2D* const vect, const float scale);
void MoveBy(const Vector2D* const by, Vector2D* toMove);
float GetPolarAngleDeg(const Vector2D* const vect);
float AngleBetweenDeg(const Vector2D* const left, const Vector2D* const right);
float Length(const Vector2D* const vect);
float LengthSq(const Vector2D* const vect);
bool Normalize(Vector2D* vect);
void ScaleBy(Vector2D* vect, const float scale);
Vector2D GetVectorByAngleDeg(const float angle);
bool Equals(const Vector2D* const left, const Vector2D* const right);


//Vector 3D
Vector3D Add(const Vector3D* const left, const Vector3D* const right);
Vector3D Substract(const Vector3D* const left, const Vector3D* const right);
Vector3D Scale(const Vector3D* const vect, const float scale);
float Dot(const Vector3D* const left, const Vector3D* const right);
Vector3D CrossLH(const Vector3D* const left, const Vector3D* const right);
Vector3D CrossRH(const Vector3D* const left, const Vector3D* const right);
void MoveBy(const Vector3D* const by, Vector3D* toMove);
float Length(const Vector3D* const vect);
float LengthSq(const Vector3D* const vect);
bool Normalize(Vector3D* vect);
void ScaleBy(Vector3D* vect, const float scale);
bool Equals(const Vector3D* const left, const Vector3D* const right);


#endif