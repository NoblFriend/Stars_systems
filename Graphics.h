#pragma once

#include <Windows.h>
#include <string>
#include <iostream>

struct Point
{
	double x;
	double y;
	bool isin (std::pair<Point, Point> range);
};

Point operator + ( const Point &p1, const Point &p2 );
Point operator - ( const Point &p1, const Point &p2 );
Point operator / ( const Point &p1, const Point &p2 );
Point operator * ( const Point &p1, const Point &p2 );

class Graphics
{
private:
	static Graphics* Graphics_;
public:
	Graphics ();
	static Graphics* get();
	static void Create (Point p);
	static void begin();
	static void end();
	static void clear();
	static void drawPoint(Point p, double thickness, COLORREF color);
	static void drawLine(Point p1, Point p2, double thickness, COLORREF color);
	static void drawRectangle(Point p1, Point p2, double thickness, COLORREF color);
	static void drawText(Point p, std::string text);
	COLORREF lowerBrightness (COLORREF color, double k);
	COLORREF colorRGB (double r, double g, double b);
   ~Graphics ();
};
