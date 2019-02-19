#include <vector>
#include "Solids.h"
#include <Windows.h>
#include <stdlib.h>
#include <ctime>

int main()
{
	srand(int(time(NULL)));
	Graphics::get()->Create({ 1400, 700 });
	Universe univ (2);
	//Solid s1 (50000.0, { 0, 0 }, { 600,300 }, Graphics::get()->colorRGB(255, 0,0));
	//Solid s2 (50000, { -50, 0 }, { 600,200 }, Graphics::get()->colorRGB(0, 0, 255));
	Solid s3 (210000.0, { 0, 0 }, { 600,400 }, Graphics::get()->colorRGB(255, 0, 0));
	Solid s2 (1.0, { 22, 0 }, { 600,110 }, Graphics::get()->colorRGB(0, 0, 255));

	Solid s1 (800.0, { 35, 0 }, { 600,120 }, Graphics::get()->colorRGB(0, 255, 0));
	Solid s4 (1000.0, { 47, 0 }, { 600,240 }, Graphics::get()->colorRGB(0, 255, 0));
	univ.add(s1);
	univ.add(s2);
	univ.add(s3);
	univ.add(s4);
	/*for (int i = 0; i < 200; i++)
	{
		l_double m = 1000;
		l_double v_x = (rand() % 10 * rand() % 10 - 70)/4;
		l_double v_y = (rand() % 10 * rand() % 10 - 70)/4;
		Solid s (m, { v_x, v_y }, { rand() % 1100 + 100, rand() % 400 + 100 }, Graphics::get()->colorRGB(0, 255, 0));
		univ.add (s);
	}*/
	for (int i = 1; i >0; i++)
	{
		univ.calculate(0.04);
		univ.draw();
		Sleep(0);
	}
	std::cout << "End";
	return 0;
}