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

		virtual Vec2D get_centre() const { return centre; }
		virtual Vec2D get_corner(int i) const { return corners[i % 4]; }
		virtual bool isVertex(const Vec2D& v) const;
		virtual Vec2D nudge(const Shape& s) const;
		virtual void rotate(float pangle){
			angle += pangle;
		}
		virtual LineSeg project(const Vec2D& axis) const;
		virtual void move(Vec2D& v){
			centre += v;
		}
		virtual bool collision_check(const Shape& s) const;
		virtual Vec2D get_nearest(const Vec2D point) const;
};

#endif //SQUARE_H
