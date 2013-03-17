#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape{
	protected:
		float height, width;
		float angle;
		Vec2D centre;
		Vec2D corners[4];
	public:
		Square(Vec2D c, float h = 1, float w = 1, float a = 0);
		~Square() {}

		virtual Vec2D get_centre() { return centre; }
//		virtual bool isVertex(const Vec2D& v);
		virtual void rotate(float pangle){
			angle += pangle;
		}
		virtual LineSeg project(const Vec2D& axis);
		virtual void move(Vec2D& v){
			centre += v;
		}
		virtual bool collision_check(Shape& s);
		virtual Vec2D get_nearest(Vec2D);
};

#endif //SQUARE_H
