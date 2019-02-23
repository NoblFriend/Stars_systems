#pragma once

#include <vector>
#include "Vector2.h"
#include "Graphics.h"
#include "Consts.h"

struct Solid
{
	Vector2 coord_;
	l_double m_;
	l_double r_;
	Vector2 v_;
	l_double omega_;
	COLORREF color_;
	const char* name_ = "";

	Solid (Vector2 coord, l_double m, l_double r, Vector2 v, l_double omega, COLORREF color, const char* name);
	Solid();
	void calculate_v (Vector2 a, l_double t_scale);
	void calculate_coord (l_double t_scale);
	void draw (Vector2 scale, Vector2 origin) const;
};

struct Universe
{
	l_double t_;
	std::vector<Solid> solids_;

	Universe (int size);
	void add (Solid& s);
	void calculate (l_double t_scale);
	void showtime () const;
	void draw(Vector2 origin, Vector2 scale, bool showt) const;
};