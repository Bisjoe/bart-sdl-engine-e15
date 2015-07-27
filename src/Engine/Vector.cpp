#include "Vector.h"

//========================================VECTOR 2D========================================
//---------------------------------------------
//--- Returns a Vector2D r = (x1+x2, y1+y2) ---
//---------------------------------------------
Vector2D Add(const Vector2D* const left, const Vector2D* const right) {
	Vector2D rep;
	rep.x = left->x + right->x;
	rep.y = left->y + right->y;
	return rep;
}

//---------------------------------------------
//--- Returns a Vector2D r = (x1-x2, y1-y2) ---
//---------------------------------------------
Vector2D Substract(const Vector2D* const left, const Vector2D* const right) {
	Vector2D rep;
	rep.x = left->x - right->x;
	rep.y = left->y - right->y;
	return rep;
}

//--------------------------------------------
//--- Return a Vector2D r = (x * k, y * k) ---
//--------------------------------------------
Vector2D Scale(const Vector2D* const vect, const float scale) {
	Vector2D rep;
	rep.x = vect->x * scale;
	rep.y = vect->y * scale;
	return rep;
}

//--------------------------------------------------------------
//--- Changes Vector2D toMove for toMove(x + by.x, y + by.y) ---
//--- Using Add() ----------------------------------------------
//--------------------------------------------------------------
void MoveBy(const Vector2D* const by, Vector2D* toMove) {
	(*toMove) = Add(toMove, by);
}

//------------------------------------------------
//--- Return the angle of Vector2D from X-axis ---
//--- Using AngleBetweenDeg() --------------------
//------------------------------------------------
float GetPolarAngleDeg(const Vector2D* const vect) {
	Vector2D vecX = { 1.f, 0.f };
	float tempAngle = AngleBetweenDeg(vect, &vecX);
	//If Vector.Y is negative, changes angle for Counter-Clockwise angle
	if (vect->y < 0.f) {
		tempAngle = 360.f - tempAngle;
	}
	return tempAngle;
}

//---------------------------------------
//--- Return Angle between 2 Vector2D ---
//---------------------------------------
//--- angle =   dotprod  / normprod -----
//--- Cos­O = (u(dot)v)/(||u||*||v||) ----
//---------------------------------------
float AngleBetweenDeg(const Vector2D* const left, const Vector2D* const right) {
	float deg = 0.f;
	//--- dotprod = (u(dot)v) ---
	float dotprod = (left->x * right->x) + (left->y * right->y);
	float normU = Length(left);
	float normV = Length(right);
	//If Length neither length is Null
	if (normU != 0.f && normV != 0.f) {
		float angle = dotprod / (normU * normV);
		float rad = acosf(angle);
		//Radian to Degrees
		deg = rad * 180 / PI;
	}
	return deg;
}

//---------------------------------
//--- Return length of Vector2D ---
//--- Using LengthSq() ------------
//---------------------------------
float Length(const Vector2D* const vect) {
	return sqrt(LengthSq(vect));
}

//----------------------------------
//--- Return length² of Vector2D ---
//----------------------------------
float LengthSq(const Vector2D* const vect) {
	return pow(vect->x, 2) + pow(vect->y, 2);
}

//----------------------------------------------------------
//--- Change Vector2D to parallel Vector2D with length 1 ---
//--- Return true if done, false if vector is null ---------
//--- Using Length() ---------------------------------------
//----------------------------------------------------------
bool Normalize(Vector2D* vect) {
	float norme = Length(vect);
	//If Vector isn't Null
	if (norme != 0.f) {
		vect->x /= norme;
		vect->y /= norme;
	}
	return norme != 0.f;
}

//------------------------------------------------
//--- Changes Vector2D for vect (x * k, y * k) ---
//--- Using Scale() ------------------------------
//------------------------------------------------
void ScaleBy(Vector2D* vect, const float scale) {
	(*vect) = Scale(vect, scale);
}

//------------------------------------------------------
//--- Returns unit Vector2D (length of 1) from Angle ---
//--- r = (cos0, sin0) /* 0 = angle */ -----------------
//------------------------------------------------------
Vector2D GetVectorByAngleDeg(const float angle) {
	Vector2D temp;
	temp.x = cosf(angle);
	temp.y = sinf(angle);
	return temp;
}

//---------------------------------------------------------------
//--- Compare 2 Vector2D with EPSILON ---------------------------
//--- Return true if (x1 == x2) and (y1 == y2) (With EPSILON) ---
//---------------------------------------------------------------
bool Equals(const Vector2D* const left, const Vector2D* const right) {
	return (abs(left->x - right->x) <= EPSILON) && abs(left->y - right->y) <= EPSILON;
}

//========================================VECTOR 3D========================================
//----------------------------------------------------
//--- Returns a Vector3D r = (x1+x2, y1+y2, z1+z2) ---
//----------------------------------------------------
Vector3D Add(const Vector3D* const left, const Vector3D* const right) {
	Vector3D temp;
	temp.x = left->x + right->x;
	temp.y = left->y + right->y;
	temp.z = left->z + right->z;
	return temp;
}

//----------------------------------------------------
//--- Returns a Vector3D r = (x1-x2, y1-y2, z1-z2) ---
//----------------------------------------------------
Vector3D Substract(const Vector3D* const left, const Vector3D* const right) {
	Vector3D temp;
	temp.x = left->x - right->x;
	temp.y = left->y - right->y;
	temp.z = left->z - right->z;
	return temp;
}

//-------------------------------------------------
//--- Returns a Vector3D r = (x1*k, y1*k, z1*k) ---
//-------------------------------------------------
Vector3D Scale(const Vector3D* const vect, const float scale) {
	Vector3D temp;
	temp.x = vect->x * scale;
	temp.y = vect->y * scale;
	temp.z = vect->z * scale;
	return temp;
}

//---------------------------------------------------
//--- Return DotProduct of 2 Vector2D ---------------
//--- dotprod = (x1 * x2) + (y1 * y2) + (z1 * z2) ---
//---------------------------------------------------
float Dot(const Vector3D* const left, const Vector3D* const right) {
	return (left->x * right->x) + (left->y * right->y) + (left->z * right->z);
}

//-------------------------------------------------------
//--- Returns Vector3D as Cross Product of 2 Vector3D ---
//--- Vector3D r = u x v --------------------------------
//--- Using CrossRH -------------------------------------
//-------------------------------------------------------
//########## Warning : For Left-Handed System ###########
//-------------------------------------------------------
Vector3D CrossLH(const Vector3D* const left, const Vector3D* const right) {
	Vector3D temp = CrossRH(left, right);
	//Changes orientation of Z
	temp.z *= -1;
	return temp;
}

//-------------------------------------------------------
//--- Returns Vector3D as Cross Product of 2 Vector3D ---
//--- Vector3D r = u x v --------------------------------
//--- r = |y1  z1| - |x1  z1| + |x1  y1| ----------------
//---     |y2  z2|   |x2  z2|   |x2  y2| ----------------
//--- r =   (x)    ,   -(y)   ,    (z)   ----------------
//-------------------------------------------------------
//########## Warning : For Right-Handed System ##########
//-------------------------------------------------------
Vector3D CrossRH(const Vector3D* const left, const Vector3D* const right) {
	Vector3D temp;
	temp.x = (left->y * right->z) - (right->y * left->z);
	temp.y = -((left->x * right->z) - (right->x * left->z));
	temp.z = (left->x * right->y) - (right->x * left->y);
	return temp;
}

//------------------------------------------------------------------------
//--- Changes Vector2D toMove for toMove(x + by.x, y + by.y, z + by.z) ---
//--- Using Add() --------------------------------------------------------
//------------------------------------------------------------------------
void MoveBy(const Vector3D* const by, Vector3D* toMove) {
	(*toMove) = Add(toMove, by);
}

//---------------------------------
//--- Return length of Vector3D ---
//--- Using LengthSq() ------------
//---------------------------------
float Length(const Vector3D* const vect) {
	return sqrt(LengthSq(vect));
}

//----------------------------------
//--- Return length² of Vector3D ---
//----------------------------------
float LengthSq(const Vector3D* const vect) {
	return pow(vect->x, 2) + pow(vect->y, 2) + pow(vect->z, 2);
}

//----------------------------------------------------------
//--- Change Vector3D to parallel Vector3D with length 1 ---
//--- Return true if done, false if vector is null ---------
//--- Using Length() ---------------------------------------
//----------------------------------------------------------
bool Normalize(Vector3D* vect) {
	float norme = Length(vect);
	//If Vector3D isn't Null
	if (norme != 0.f) {
		vect->x /= norme;
		vect->y /= norme;
		vect->z /= norme;
	}
	return norme != 0.f;
}

//-------------------------------------------------------
//--- Changes Vector3D for vect (x * k, y * k, z * k) ---
//--- Using Scale() -------------------------------------
//-------------------------------------------------------
void ScaleBy(Vector3D* vect, const float scale) {
	(*vect) = Scale(vect, scale);
}

//--------------------------------------------------------------------------------------------------
//--- Compare 2 Vector3D using EPSILON -------------------------------------------------------------
//--- Return true if ((x1 ± Epsilon) == x2) and ((y1 ± EPSILON) == y2) and ((z1 ± EPSILON == z2) ---
//--- EPSILON set at 0.0001 ------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
bool Equals(const Vector3D* const left, const Vector3D* const right) {
	return (abs(left->x - right->x) <= EPSILON) && abs(left->y - right->y) <= EPSILON && abs(left->z - right->z) <= EPSILON;
}
