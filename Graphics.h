#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include "Vector2.h"


class Graphics
{
private:
	static Graphics* Graphics__;
public:
	Graphics ();
	static Graphics* get();
	static void Create (Vector2 p);
	static void begin();
	static void end();
	static void clear();
	static double sleep(int t);
	static double getFPS ();
	static void drawVector(Vector2 v, Vector2 origin, double thickness, COLORREF color);
	static void drawPoint(Vector2 p, double thickness, COLORREF color);
	static void drawEllipse (Vector2 p, Vector2 r, COLORREF color);
	static void drawLine(Vector2 p1, Vector2 p2, double thickness, COLORREF color);
	static void drawRectangle(Vector2 p1, Vector2 p2, double thickness, COLORREF color);
	static void drawText(Vector2 p, std::string text, COLORREF color);
	COLORREF lowerBrightness (COLORREF color, double k);
	COLORREF colorRGB (double r, double g, double b);
   ~Graphics ();
};
