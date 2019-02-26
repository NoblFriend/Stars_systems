#pragma once

#include <vector>
#include "Vector2.h"
#include "Graphics.h"
#include "Consts.h"

struct Solid
{
	Vector2 coord_;
	double m_;
	double r_;
	Vector2 v_;
	double omega_;
	COLORREF color_;
	const char* name_ = "";

	Solid (Vector2 coord, double m, double r, Vector2 v, double omega, COLORREF color, const char* name);
	Solid();
	void calculate_v (Vector2 a, double t_scale);
	void calculate_coord (double t_scale);
	void draw_v(Vector2 scale, Vector2 origin) const;
	void draw (Vector2 scale, Vector2 origin) const;
};

struct Universe
{
	double t_;
	std::vector<Solid> solids_;

	Universe (int size);
	void add (Solid& s);
	void calculate (double t_scale);
	void showtime () const;
	void draw(Vector2 origin, Vector2 scale, bool showt) const;
};