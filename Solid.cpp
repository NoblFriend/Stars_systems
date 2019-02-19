#include "Solids.h"

Solid::Solid (l_double m, Vector2 v, Vector2 coord, COLORREF color)
	:	m_(m),
		v_(v),
		coord_(coord),
		color_(color)
{}

Solid::Solid ()
	:	m_(0),
		v_({ 0,0 }),
		coord_({ 0,0 })
{}

void Solid::calculate_v (Vector2 a, l_double t_scale)
{
	v_ = v_ + a*t_scale;
}

void Solid::calculate_coord (l_double t_scale)
{

	coord_ = coord_ + v_ * t_scale;
}

void Solid::draw ()
{
	Graphics::get()->drawPoint({ (double)coord_.x_, (double)coord_.y_ }, 8, color_);
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

void Universe::calculate (l_double t_scale)
{
	for (size_t i = 0; i < solids_.size(); i++)
	{
		for (size_t j = i+1; j < solids_.size(); j++)
		{
			Vector2 r = solids_[j].coord_ - solids_[i].coord_;
			l_double len = ~r;
			l_double len3 = len * len * len;
			solids_[i].calculate_v(r*(G*solids_[j].m_ / len3), t_scale);
			solids_[j].calculate_v(r*(-G*solids_[i].m_ / len3), t_scale);
		}
		solids_[i].calculate_coord(t_scale);
	}
	t_ += t_scale;
}

void Universe::draw ()
{
	Graphics::get()->begin();
	Graphics::get()->clear();
	for (size_t i = 0; i < solids_.size(); i++)
	{
		solids_[i].draw();
	}
	Graphics::get()->end();
}