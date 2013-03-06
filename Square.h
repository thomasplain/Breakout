#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape{
	protected:
		float height, width;
		Vec2D centre;
		float orientation;
	public:
		virtual Vec2D get_centre() { return centre; }
		virtual LineSeg project(Vec2D& axis);
		virtual void move(Vec2D& v);
		virtual void rotate(float f);
		virtual bool collision_check(Shape& s);
};

#endif //SQUARE_H
