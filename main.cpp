#include <vector>
#include "Solids.h"
#include <Windows.h>
#include <stdlib.h>
#include <ctime>
#include "Consts.h"
#define _USE_MATH_DEFINES 
#include <math.h>
#include "View.h"

void translate (View* view)
{
	if (GetAsyncKeyState('Q'))
	{
		view->scale({ 1.01, 1.01 });
	}
	if (GetAsyncKeyState('E'))
	{
		view->scale({ 1 / 1.01, 1 / 1.01 });
	}
	if (GetAsyncKeyState('W'))
	{
		view->translate({ 0, 1 });
		
	}
	if (GetAsyncKeyState('S'))
	{
		view->translate({ 0, -1 });
	}
	if (GetAsyncKeyState('A'))
	{
		view->translate({1, 0});
	}
	if (GetAsyncKeyState('D'))
	{
		view->translate({ -1, 0 });
	}
}


int main()
{
	Vector2 windowSize = { GetSystemMetrics(SM_CXSCREEN)*0.85, GetSystemMetrics(SM_CYSCREEN)*0.85 };
	srand(int(time(NULL)));
	Graphics::get()->Create(windowSize);
	Universe universe (6);
	Solid sun		({ 0.0,     0.0 }, 1.989E30, 1*SR/20, { 0,       0 }, 0,		         RGB(255, 255,   0), "");
	Solid mercury	({ 0.38*AU, 0.0 }, 0.055*EM, 2440E3,  { 0, 47.87E3 }, 2*M_PI /(0.241*Y), RGB(255,   0, 120), "");
	Solid venus		({ 0.72*AU, 0.0 }, 0.815*EM, 6052E3,  { 0, 35.02E3 }, 2*M_PI /(0.615*Y), RGB(  0, 255, 255), "");
	Solid earth		({ 1.00*AU, 0.0 }, 1.0*EM,   1*ER,	  { 0, 29.76E3 }, 2*M_PI /(Y),	     RGB(  0, 255,   0), "");
	Solid mars		({ 1.52*AU, 0.0 }, 0.107*EM, 3397E3,  { 0, 24.13E3 }, 2*M_PI /(1.88*Y),  RGB(255,   0,   0), "");
	Solid jupiter	({ 5.20*AU, 0.0 }, 317.8*EM, 71490E3, { 0, 13.07E3 }, 2*M_PI /(11.85*Y), RGB(255, 100, 100), "");
	universe.add(sun);
	universe.add(mercury);
	universe.add(venus);
	universe.add(earth);
	universe.add(mars);
	universe.add(jupiter);

	View view (windowSize * 0.5, windowSize * 0.5, { windowSize.x_ / (AU * 11), windowSize.x_ / (AU * 11) });
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		translate(&view);
		view.draw(universe, true);
		for (int i = 0; i < universe.solids_.size(); i++)
		{
			//universe.solids_[i].draw_v(view.scale_, view.origin_);
		}
		double FPS = Graphics::get()->getFPS();
		double t_scale = (FPS == 0) ? 0 : 1 / (FPS*10);
		int count = 1000;
		for (int i = 0; i < count; i++)
		{
			universe.calculate(Y*t_scale/count);
		}
	}
	/*std::vector<double> r(universe.solids_.size());

	for (size_t i = 0; i < universe.solids_.size(); i++)
	{
		r[i] = universe.solids_[i].coord_.x_;
	}

	for (double t = 0; !GetAsyncKeyState(VK_ESCAPE); t+=M_PI*1E7*Graphics::get()->sleep(10)/1000)
	{
		for (size_t i = 0; i < universe.solids_.size(); i++)
		{
			universe.solids_[i].coord_ = { cos(t* universe.solids_[i].omega_)*r[i], sin(t* universe.solids_[i].omega_)*r[i]};
		}
		universe.draw(windowSize*0.5);
	}*/
	std::cout << "Just relax, all is good!";
	return 0;
}