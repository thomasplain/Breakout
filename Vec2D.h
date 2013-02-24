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
			y = v.get_y();
			x = v.get_x();
		}

		float get_x() const;
		void set_x(float f);
		
		float get_y() const;
		void set_y(float f);

		virtual float magnitude() const;
		virtual const IVec* normalise() const;
		virtual const IVec* normal() const;
		virtual float dot(const IVec* v) const;
		virtual IVec* project(IVec* axis) const;

		virtual const IVec& operator*(const IVec& v1);
		virtual const IVec& operator*(const float f) const;
		virtual const IVec& operator+(const IVec& v1);
		virtual const IVec& operator-(const IVec& v1);
		
		virtual const IVec& operator*=(const IVec& v1);
		virtual const IVec& operator+=(const IVec& v1);
		virtual const IVec& operator-=(const IVec& v1);	

		virtual const bool operator==(const IVec& v1);
		virtual const bool operator!=(const IVec& v1);
		virtual const bool operator<(const IVec& v1);
		virtual const bool operator<=(const IVec& v1);
		virtual const bool operator>(const IVec& v1);
		virtual const bool operator>=(const IVec& v1);
};

#endif //VEC2D_H
