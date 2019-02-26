#pragma once
#include <cmath>
#include <vector>


struct Vector2
{

	double x_;
	double y_;

	Vector2(double x, double y);
	Vector2();

	bool isin (std::pair<Vector2, Vector2> range);
	friend Vector2 operator+ (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator- (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator* (const Vector2& v1, const double& d);
	friend Vector2 operator* (const Vector2& p1, const Vector2& p2);
	friend Vector2 operator/ (const Vector2& p1, const Vector2& p2);
	friend double operator~ (const Vector2& v);
};