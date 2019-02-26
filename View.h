#pragma once
#include "Graphics.h"
#include "Solids.h" 

struct View
{
	Vector2 center_;
	Vector2 origin_;
	Vector2 scale_;
	const Vector2* movingOrigin_;

	View (Vector2 center, Vector2 origin, Vector2 scale);

	void scale (Vector2 dscale);
	void translate (Vector2 dorigin);
	void setMovingOrigin (const Solid& solid);
	void draw (const Universe& univ, bool showt);
	
};