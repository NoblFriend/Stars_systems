#include "Vector2.h"

Vector2::Vector2 (l_double x, l_double y)
	:	x_(x),
		y_(y)
{}


Vector2::Vector2 ()
	:	x_(0),
		y_(0)
{}

bool Vector2::isin (std::pair<Vector2, Vector2> range)
{
	if (((x_ >= range.first.x_ && x_ <= range.second.x_) || (x_ <= range.first.x_ && x_ >= range.second.x_)) &&
		((y_ >= range.first.y_ && y_ <= range.second.y_) || (y_ <= range.first.y_ && y_ >= range.second.y_)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Vector2::draw (Vector2 origin, Vector2 scale)
{
	Graphics::get()->drawLine(origin, ((*this)*scale)+origin, 1, Graphics::get()->colorRGB(255, 255, 255));
	Graphics::get()->drawPoint(((*this)*scale) + origin, 5, Graphics::get()->colorRGB(255, 255, 255));
}

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

Vector2 operator* (const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x_ * v2.x_, v1.y_ * v2.y_);
}

Vector2 operator/ (const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x_ / v2.x_, v1.y_ / v2.y_);
}

l_double operator~ (const Vector2& v)
{
	return sqrt(v.x_*v.x_ + v.y_*v.y_);
}