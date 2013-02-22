#ifndef IVEC_H
#define IVEC_H

#include <iostream>

class IVec {
	public:
		virtual float get_x() const = 0;
		virtual void set_x(float f) = 0;
		
		virtual float get_y() const = 0;
		virtual void set_y(float f) = 0;

		virtual float magnitude() const = 0;
		virtual const IVec& normalise() const = 0;
		virtual const IVec& normal() const = 0;
		virtual float dot(const IVec& v) const = 0;
		virtual float project(IVec& axis) const = 0;

		virtual const IVec& operator*(const IVec& v1) = 0;
		virtual const IVec& operator*(const float f) const = 0;
		virtual const IVec& operator+(const IVec& v1) = 0;
		virtual const IVec& operator-(const IVec& v1) = 0;
		
		virtual const IVec& operator*=(const IVec& v1) = 0;
		virtual const IVec& operator+=(const IVec& v1) = 0;
		virtual const IVec& operator-=(const IVec& v1) = 0;
		
		virtual const bool operator==(const IVec& v1) = 0;
		virtual const bool operator!=(const IVec& v1) = 0;
		virtual const bool operator<(const IVec& v1) = 0;
		virtual const bool operator<=(const IVec& v1) = 0;
		virtual const bool operator>(const IVec& v1) = 0;
		virtual const bool operator>=(const IVec& v1) = 0;
		
		friend std::ostream& operator<<(std::ostream& o, const IVec& v);

};

int find_quadrant(const IVec* v);
#endif
