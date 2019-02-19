#pragma once

#include <vector>
#include "Vector2.h"
#include "Graphics.h"

struct Solid
{
	l_double m_;
	Vector2 v_;
	Vector2 coord_;
	COLORREF color_;

	Solid (l_double m, Vector2 v, Vector2 coord, COLORREF color);
	Solid();
	void calculate_v (Vector2 a, l_double t_scale);
	void calculate_coord (l_double t_scale);
	void draw ();
};

class Universe
{
private:
	l_double t_;
	std::vector<Solid> solids_;
	const l_double G = 1.67;
public:
	Universe (int size);
	void add (Solid& s);
	void calculate (l_double t_scale);
	void draw();
};