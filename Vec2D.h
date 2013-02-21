#ifndef VEC2D_H
#define VEC2D_H

#include "IVec.h"

class Vec2D : public IVec {
	protected:
		float x;
		float y;
	public:
		Vec2D(float i = 0, float j = 0) : x(i), y(j){}
		Vec2D(const IVec& v){
			x = v.get_x();
			y = v.get_y();
		}

		float get_x() const;
		void set_x(float f);
		
		float get_y() const;
		void set_y(float f);

		float magnitude();
		IVec& normalise();
		IVec& normal();
		float dot(IVec& v);
		IVec& project(IVec& axis);

		IVec& operator*(IVec& v1);
		IVec& operator+(IVec& v1);
		IVec& operator-(IVec& v1);
		
		IVec& operator*=(IVec& v1);
		IVec& operator+=(IVec& v1);
		IVec& operator-=(IVec& v1);	
};

#endif //VEC2D_H
