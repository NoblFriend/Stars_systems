#include "Solids.h"

Solid::Solid (Vector2 coord, double m, double r, Vector2 v, double omega, COLORREF color, const char* name)
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

void Solid::calculate_v (Vector2 a, double t_scale)
{
	v_ = v_ + a*t_scale;
}

void Solid::calculate_coord (double t_scale)
{

	coord_ = coord_ + v_ * t_scale;
}

void Solid::draw_v(Vector2 scale, Vector2 origin) const
{
	Graphics::get()->drawVector(v_*scale*1e6, coord_*scale + origin, 1, color_);
}

void Solid::draw (Vector2 scale, Vector2 origin) const
{
	Graphics::drawEllipse(coord_*scale + origin,scale * 1000 * r_ + Vector2{1, 1}, color_);
	//this->draw_v(scale, origin);
}

Universe::Universe (int size)
	:	t_(0),
		solids_(size)
{
	solids_.clear();
}

void Universe::add (Solid& s)
{
	solids_.push_back(s);
}

void Universe::calculate (double t_scale)
{
	for (size_t i = 0; i < solids_.size(); i++)
	{
		for (size_t j = i+1; j < solids_.size(); j++)
		{
			Vector2 r = solids_[j].coord_ - solids_[i].coord_;
			double len = ~r;
			double len3 = len * len * len;
			solids_[i].calculate_v(r*(global_consts::G*solids_[j].m_ / len3), t_scale);
			solids_[j].calculate_v(r*(-global_consts::G*solids_[i].m_ / len3), t_scale);
		}
		solids_[i].calculate_coord(t_scale);
	}
	t_ += t_scale;
}

void Universe::showtime () const 
{
	char str[50] = "";
	sprintf_s(str, "%lf", t_/Y);
	Graphics::get()->drawText ({ 50, 50 }, str, Graphics::get()->colorRGB(255, 255, 255));
}

void Universe::draw (Vector2 origin, Vector2 scale, bool showt) const
{
	Graphics::get()->begin();
	Graphics::get()->clear();
	for (size_t i = 0; i < solids_.size(); i++)
	{
		solids_[i].draw(scale, origin);
	}
	if (showt) showtime();
	Graphics::get()->end();
}