#ifndef VEC2D_H
#define VEC2D_H

#include "IVec.h"

class Vec2D : public IVec {
	protected:
		float x;
		float y;
	public:
		Vec2D(const float i = 0, const float j = 0) : x(i), y(j){}
		Vec2D(const IVec& v){
			x = v.get_x();
			y = v.get_y();
		}

		float get_x() const;
		void set_x(float f);
		
		float get_y() const;
		void set_y(float f);

		float magnitude() const;
		const IVec& normalise() const;
		const IVec& normal() const;
		float dot(const IVec& v) const;
		const IVec& project(IVec& axis) const;

		const IVec& operator*(const IVec& v1);
		const IVec& operator+(const IVec& v1);
		const IVec& operator-(const IVec& v1);
		
		const IVec& operator*=(const IVec& v1);
		const IVec& operator+=(const IVec& v1);
		const IVec& operator-=(const IVec& v1);	
};

#endif //VEC2D_H
