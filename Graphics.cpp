#include "C:\Program Files (x86)\TX\TXLib.h"
#include "Graphics.h"

Graphics* Graphics::Graphics_ = NULL;

bool Point::isin (std::pair<Point, Point> range)
{
 if (((x >= range.first.x && x <= range.second.x) || (x <= range.first.x && x >= range.second.x)) &&
     ((y >= range.first.y && y <= range.second.y) || (y <= range.first.y && y >= range.second.y)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Graphics::Graphics ()
{
}

Graphics * Graphics::get()
{
	return Graphics_;
}

void Graphics::Create(Point p)
{
	static Graphics graphics;
	Graphics_ = &graphics;
	txCreateWindow ( p.x, p.y, true );
}

void Graphics::begin()
{
	txBegin ();
}

void Graphics::end()
{
	txEnd ();
}

void Graphics::clear()
{
	COLORREF c = txGetFillColor();
	txSetFillColor(TX_BLACK);
	txClear();
	txSetFillColor(c);
}

double Graphics::sleep(int t)
{
	return txSleep(t);
}

double Graphics::getFPS()
{
	return txGetFPS();
}

void Graphics::drawPoint(Point p, double thickness, COLORREF color)
{
	txSetColor (color, thickness);
	txCircle (p.x, txGetExtentY() - p.y, 1);
}

void DrawLine (double x1, double y1, double x2, double y2)
{
	txSetColor (TX_WHITE, 4);
	std::cout << " p1.x = " << x1;
	std::cout << " p1.y = " << y1;
	std::cout << " p2.x = " << x2;
	std::cout << " p2.y = " << y2 << '\n';
	txLine (x1, y1, x2, y2);
	txCircle (x1, y1, 10);
	txCircle (x2, y2, 10);
}

void Graphics::drawLine(Point p1, Point p2, double thickness, COLORREF color)
{

	txSetColor (color, thickness);

	txLine (p1.x, txGetExtentY() - p1.y, p2.x, txGetExtentY() - p2.y);
}

void Graphics::drawRectangle(Point p1, Point p2, double thickness, COLORREF color)
{
	txSetColor (color, thickness);
	int a = txGetExtentY();
	txLine (p1.x, a - p1.y, p1.x, a - p2.y);
	txLine (p1.x, a - p2.y, p2.x, a - p2.y);
	txLine (p2.x, a - p2.y, p2.x, a - p1.y);
	txLine (p2.x, a - p1.y, p1.x, a - p1.y);
}

void Graphics::drawText(Point p, std::string text, COLORREF color)
{
	txSetColor (color);
	txTextOut(p.x, txGetExtentY() - p.y, text.c_str());
}

COLORREF Graphics::lowerBrightness (COLORREF color, double k)
{
	return RGB(txExtractColor(color, TX_RED)*k,txExtractColor(color, TX_GREEN)*k,txExtractColor(color, TX_BLUE)*k);
}

COLORREF Graphics::colorRGB(double r, double g, double b)
{
	return RGB(r, g, b);
}

Graphics::~Graphics()
{

}


Point operator+(const Point & p1, const Point & p2)
{
	Point p;
	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	return p;
}

Point operator-(const Point & p1, const Point & p2)
{
	Point p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}

Point operator/(const Point & p1, const Point & p2)
{
	Point p;
	p.x = p1.x / p2.x;
	p.y = p1.y / p2.y;
	return p;
}

Point operator*(const Point & p1, const Point & p2)
{
	Point p;
	p.x = p1.x * p2.x;
	p.y = p1.y * p2.y;
	return p;
}

Point operator*(const Point & p1, double d)
{
	Point p;
	p.x = p1.x*d;
	p.y = p1.y*d;
	return p;
}
