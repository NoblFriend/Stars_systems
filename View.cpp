#include "View.h" 

View::View (Vector2 center, Vector2 origin, Vector2 scale)
	:	center_(center),
		origin_(origin),
		scale_(scale),
		movingOrigin_(nullptr)
{}

void View::scale( Vector2 dscale)
{
	origin_ = (origin_ - center_)* dscale + center_;
	scale_ = scale_ * dscale;
}

void View::translate(Vector2 dorigin)
{
	origin_ = origin_ - dorigin;
	
}

void View::setMovingOrigin (const Solid& solid)
{
	movingOrigin_ = &solid.coord_;

}

void View::draw (const Universe& 

univ, bool showt)
{
	if (movingOrigin_) univ.draw(*movingOrigin_, scale_, showt);
	else
	{
		univ.draw(origin_, scale_, showt);
	}
}
