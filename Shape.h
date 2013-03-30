#ifndef SHAPE_H
#define SHAPE_H

#include "LineSeg.h"
#include "Vec2D.h"

class Shape{
	public:
		virtual Vec2D get_centre() const = 0;
		virtual LineSeg project(const Vec2D& axis) const = 0;
		virtual void move(Vec2D& v) = 0;
		virtual void rotate(float angle) = 0;
		virtual bool collision_check(const Shape& s) const = 0;
		virtual bool isVertex(const Vec2D& v) const = 0;
		virtual Vec2D nudge(const Shape& s) const = 0;
//		virtual void collision_response(Shape& s) = 0;
//		virtual void collision_response(Vec2D& v) = 0;
		virtual Vec2D get_nearest(const Vec2D point) const = 0;
};

bool collision(const Shape& s1, const Shape& s2);
Vec2D nudge(Shape& s1, Shape& s2);

#endif //SHAPE_H
