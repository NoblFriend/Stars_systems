#include "Solids.h"

Solid::Solid (Vector2 coord, l_double m, l_double r, Vector2 v, l_double omega, COLORREF color, const char* name)
	:	coord_(coord),
		m_(m),
		r_(r),
		v_(v),
		omega_(omega),
		color_(color),
		name_(name)
{}

Solid::Solid ()
	:	m_(0),
		v_({ 0,0 }),
		coord_({ 0,0 }),
		r_(0),
		color_(Graphics::get()->colorRGB(0,0,0)),
		name_("")
{}

void Solid::calculate_v (Vector2 a, l_double t_scale)
{
	v_ = v_ + a*t_scale;
}

void Solid::calculate_coord (l_double t_scale)
{

	coord_ = coord_ + v_ * t_scale;
}

void Solid::draw (l_double scale, Point origin)
{
	Graphics::get()->drawPoint(Point{ (double)coord_.x_, (double)coord_.y_ }*scale + origin, r_*scale*1000 + 1, color_);
}

Universe::Universe (int size, l_double scale)
	:	t_(0),
		solids_(size),
		scale_(scale)
{
	solids_.clear();
}

void Universe::add (Solid& s)
{
	solids_.push_back(s);
}

void Universe::calculate (l_double t_scale)
{
	for (size_t i = 0; i < solids_.size(); i++)
	{
		for (size_t j = i+1; j < solids_.size(); j++)
		{
			Vector2 r = solids_[j].coord_ - solids_[i].coord_;
			l_double len = ~r;
			l_double len3 = len * len * len;
			solids_[i].calculate_v(r*(global_consts::G*solids_[j].m_ / len3), t_scale);
			solids_[j].calculate_v(r*(-global_consts::G*solids_[i].m_ / len3), t_scale);
		}
		solids_[i].calculate_coord(t_scale);
	}
	t_ += t_scale;
}

void Universe::showtime ()
{
	char str[50] = "";
	sprintf_s(str, "%lf", t_/Y);
	Graphics::get()->drawText ({ 50, 50 }, str, Graphics::get()->colorRGB(255, 255, 255));
}

void Universe::draw (Point origin, bool showt)
{
	Graphics::get()->begin();
	Graphics::get()->clear();
	for (size_t i = 0; i < solids_.size(); i++)
	{
		solids_[i].draw(scale_, origin);
	}
	if (showt) showtime();
	Graphics::get()->end();
}