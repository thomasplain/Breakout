#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
	protected:
		Vec2D centre;
		float radius;
	public:
		Circle(Vec2D v, float r = 1) : centre(v), radius(r) {}
		virtual Vec2D get_centre() const { return centre; }
		virtual float get_radius() const { return radius; }
		virtual LineSeg project(const Vec2D& axis);
		virtual void move(Vec2D& v){ centre += v; }
		virtual void rotate(float angle) {}
		virtual bool collision_check(Shape& s);
		virtual bool isVertex(const Vec2D& v);
//		virtual void collision_response(Shape& s) = 0;
//		virtual void collision_response(Vec2D& v) = 0;
		virtual Vec2D get_nearest(Vec2D point);
};

#endif //CIRCLE_H
