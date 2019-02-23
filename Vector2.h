#pragma once
#include <cmath>
#include <vector>
#include "Graphics.h"

typedef long double l_double;

struct Vector2
{

	l_double x_;
	l_double y_;

	Vector2(l_double x, l_double y);
	Vector2();

	bool isin (std::pair<Vector2, Vector2> range);
	void draw (Vector2 origin, Vector2 scale);
	friend Vector2 operator+ (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator- (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator* (const Vector2& v1, const l_double& d);
	friend Vector2 operator* (const Vector2& p1, const Vector2& p2);
	friend Vector2 operator/ (const Vector2& p1, const Vector2& p2);
	friend l_double operator~ (const Vector2& v);
};