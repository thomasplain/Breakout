#ifndef IVEC_H
#define IVEC_H

#include <iostream>

class IVec {
	public:
		virtual float get_x() const = 0;
		virtual void set_x(float f) = 0;
		
		virtual float get_y() const = 0;
		virtual void set_y(float f) = 0;

		virtual float magnitude() = 0;
		virtual IVec& normalise() = 0;
		virtual IVec& normal() = 0;
		virtual float dot(IVec& v) = 0;
		virtual IVec& project(IVec& axis) = 0;

		virtual IVec& operator*(IVec& v1) = 0;
		virtual IVec& operator+(IVec& v1) = 0;
		virtual IVec& operator-(IVec& v1) = 0;
		
		virtual IVec& operator*=(IVec& v1) = 0;
		virtual IVec& operator+=(IVec& v1) = 0;
		virtual IVec& operator-=(IVec& v1) = 0;
		
		friend std::ostream& operator<<(std::ostream& o, IVec& v);

};
#endif
