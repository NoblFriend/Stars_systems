#pragma once
#include <cmath>

typedef long double l_double;

struct Vector2
{

	l_double x_;
	l_double y_;

	Vector2(l_double x, l_double y);
	Vector2();

	friend Vector2 operator+ (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator- (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator* (const Vector2& v1, const l_double& d);
	friend l_double operator~ (const Vector2& v);
};