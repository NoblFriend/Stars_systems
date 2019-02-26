#define _CRT_SECURE_NO_WARNINGS
#include "C:\Program Files (x86)\TX\TXLib.h"
#include "Graphics.h"

time_t StartTime = time(NULL); 

Graphics* Graphics::Graphics__ = NULL;

Graphics::Graphics ()
{
}

Graphics * Graphics::get()
{
	return Graphics__;
}

void Graphics::Create(Vector2 p)
{
	static Graphics graphics;
	Graphics__ = &graphics;
	txCreateWindow ( p.x_, p.y_, true );
}

void Graphics::begin()
{
	txBegin ();
}

void Graphics::end()
{
	txEnd ();
	if (GetKeyState(VK_CAPITAL) & 1)
	{
		static int n = 0;
		char name[70] = "";
		time (&StartTime);
		struct tm * timeinfo = localtime (&StartTime);
		strftime(name, sizeof(name), "bmp\\Screen_%F_%H-%M-%S_", timeinfo);
		char fname[sizeof(name)] = "";
		sprintf_s(fname, "%s%05d.bmp", name, n++);
		printf("(%s)\n", fname);
		txSaveImage(fname)asserted;
	}
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

void Graphics::drawVector (Vector2 v, Vector2 origin, double thickness, COLORREF color)
{
	Graphics::get()->drawLine(origin, v + origin, thickness, color);
	Graphics::get()->drawPoint(v + origin, 5*thickness, color);
}

void Graphics::drawPoint(Vector2 p, double thickness, COLORREF color)
{
	txSetColor (color, thickness);
	txCircle (p.x_, txGetExtentY() - p.y_, 1);
}

void Graphics::drawEllipse(Vector2 p, Vector2 r, COLORREF color)
{
	txSetColor (color);
	txSetFillColor (color);
	txEllipse(p.x_ - r.x_, p.y_ - r.y_, p.x_ + r.x_, p.y_ + r.y_);
}

void DrawLine (double x1, double y1, double x2, double y2)
{
	txSetColor (TX_WHITE, 4);
	std::cout << " p1.x_ = " << x1;
	std::cout << " p1.y_ = " << y1;
	std::cout << " p2.x_ = " << x2;
	std::cout << " p2.y_ = " << y2 << '\n';
	txLine (x1, y1, x2, y2);
	txCircle (x1, y1, 10);
	txCircle (x2, y2, 10);
}

void Graphics::drawLine(Vector2 p1, Vector2 p2, double thickness, COLORREF color)
{

	txSetColor (color, thickness);

	txLine (p1.x_, txGetExtentY() - p1.y_, p2.x_, txGetExtentY() - p2.y_);
}

void Graphics::drawRectangle(Vector2 p1, Vector2 p2, double thickness, COLORREF color)
{
	txSetColor (color, thickness);
	int a = txGetExtentY();
	txLine (p1.x_, a - p1.y_, p1.x_, a - p2.y_);
	txLine (p1.x_, a - p2.y_, p2.x_, a - p2.y_);
	txLine (p2.x_, a - p2.y_, p2.x_, a - p1.y_);
	txLine (p2.x_, a - p1.y_, p1.x_, a - p1.y_);
}

void Graphics::drawText(Vector2 p, std::string text, COLORREF color)
{
	txSetColor (color);
	txTextOut(p.x_, txGetExtentY() - p.y_, text.c_str());
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


