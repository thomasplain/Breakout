#ifndef SHAPE_H
#define SHAPE_H

#include "LineSeg.h"
#include "Vec2D.h"

class Shape{
	public:
		virtual Vec2D get_centre() = 0;
		virtual LineSeg project(const Vec2D& axis) = 0;
		virtual void move(Vec2D& v) = 0;
		virtual void rotate(float angle) = 0;
		virtual bool collision_check(Shape& s) = 0;
		virtual bool isVertex(const Vec2D& v) = 0;
//		virtual void collision_response(Shape& s) = 0;
//		virtual void collision_response(Vec2D& v) = 0;
		virtual Vec2D get_nearest(Vec2D point) = 0;
};

bool collision_check(Shape& s1, Shape& s2);

#endif //SHAPE_H
