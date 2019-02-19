#include "Vector2.h"

Vector2::Vector2 (l_double x, l_double y)
	:	x_(x),
		y_(y)
{}

Vector2::Vector2 (int x, int y)
	:	x_(x),
		y_(y)
{}

Vector2::Vector2 ()
	:	x_(0),
		y_(0)
{}

Vector2 operator+ (const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x_ + v2.x_, v1.y_ + v2.y_);
}

Vector2 operator- (const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x_ - v2.x_, v1.y_ - v2.y_);
}

Vector2 operator* (const Vector2& v1, const l_double& d)
{
	return Vector2(v1.x_*d, v1.y_*d);
}

l_double operator~ (const Vector2& v)
{
	return sqrt(v.x_*v.x_ + v.y_*v.y_);
}