#ifndef VEC2D_H
#define VEC2D_H

#include <iostream>

class Vec2D{
	protected:
		float x;
		float y;
	public:
		Vec2D(const float i = 0, const float j = 0) : x(i), y(j){}
		Vec2D(const Vec2D& v){
			y = v.get_y();
			x = v.get_x();
		}

		float get_x() const;
		void set_x(float f);
		
		float get_y() const;
		void set_y(float f);

		float magnitude() const;
		const Vec2D normalise() const;
		const Vec2D normal() const;
		float dot(const Vec2D v) const;
		Vec2D project(Vec2D axis) const;
		void rotate(float angle);

		const Vec2D operator*(const Vec2D& v1) const;
		const Vec2D operator*(float f) const;
		const Vec2D operator+(const Vec2D& v1) const;
		const Vec2D operator-(const Vec2D& v1) const;
		
		const Vec2D operator*=(const Vec2D& v1);
		const Vec2D operator*=(const float& f);
		const Vec2D operator+=(const Vec2D& v1);
		const Vec2D operator-=(const Vec2D& v1);	

		const bool operator==(const Vec2D& v1);
		const bool operator!=(const Vec2D& v1);
		const bool operator<(const Vec2D& v1);
		const bool operator<=(const Vec2D& v1);
		const bool operator>(const Vec2D& v1);
		const bool operator>=(const Vec2D& v1);

		friend std::ostream& operator<<(std::ostream& o, const Vec2D& v);
};

#endif //VEC2D_H
