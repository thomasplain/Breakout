#include <cmath>
#include "Vec2D.h"

float Vec2D::get_x() const{
	return x;
}

void Vec2D::set_x(float f){
	x = f;
}

float Vec2D::get_y() const{
	return y;
}

void Vec2D::set_y(float f){
	y = f;
}

// Returns length of vector
float Vec2D::magnitude() const{
	return sqrt(x*x + y*y);
}

// Returns unit vector pointing in same direction
const IVec& Vec2D::normalise() const{
	Vec2D temp(x/magnitude(), y/magnitude());
	Vec2D& tr = temp;
	return tr;
}

// Returns vector rotated by 90 degrees
const IVec& Vec2D::normal() const{
	Vec2D temp(-y, x);
	Vec2D& tr = temp;
	return tr;
}

float Vec2D::dot(const IVec& v) const{
	return x * v.get_x() + y * v.get_y();
}

const IVec& Vec2D::project(IVec& axis) const{
	float dotp = dot(axis);
	float weight = axis.magnitude();
	Vec2D direction = axis.normalise();
	float projx = direction.get_x() * dotp / weight;
	float projy = direction.get_y() * dotp / weight;
	Vec2D temp(projx, projy);
	Vec2D &tr = temp;
	return tr;
}

const IVec& Vec2D::operator*(const IVec& v1){
	Vec2D temp(x * v1.get_x(), y * v1.get_y());
	Vec2D& tr = temp;
	return tr;
}

const IVec& Vec2D::operator+(const IVec& v1){
	Vec2D temp(x + v1.get_x(), y + v1.get_y());
	Vec2D& tr = temp;
	return tr;
}

const IVec& Vec2D::operator-(const IVec& v1){
	Vec2D temp(x - v1.get_x(), y - v1.get_y());
	Vec2D& tr = temp;
	return tr;
}

const IVec& Vec2D::operator*=(const IVec& v1){
//	Vec2D temp;
//	if (this == &v1) temp = Vec2D(x*x, y*y);
//	else temp = Vec2D(x * v1.get_x(), y * v1.get_y());
//	Vec2D& tr = temp;
//	return tr;
	*this = *this * v1;
	return *this;
}

const IVec& Vec2D::operator+=(const IVec& v1){
//	Vec2D temp;
//	if (this == &v1) temp = Vec2D(2 * x, 2 * y);
//	else temp = *this + v1;
//	Vec2D& tr = temp;
//	return tr;
	*this = *this + v1;
	return *this;
}

const IVec& Vec2D::operator-=(const IVec& v1){
//	Vec2D temp;
//	if (this == &v1) temp = Vec2D(0, 0);
//	else temp = *this - v1;
//	Vec2D& tr = temp;
//	return tr;
	*this = *this - v1;
	return *this;
}
