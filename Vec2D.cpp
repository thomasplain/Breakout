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

float Vec2D::project(IVec& axis) const{
	return dot(axis) / axis.magnitude();
}

const IVec& Vec2D::operator*(const IVec& v1){
	Vec2D temp(x * v1.get_x(), y * v1.get_y());
	Vec2D& tr = temp;
	return tr;
}

const IVec& Vec2D::operator*(const float f) const{
	Vec2D temp(x * f, y * f);
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
	*this = *this * v1;
	return *this;
}

const IVec& Vec2D::operator+=(const IVec& v1){
	*this = *this + v1;
	return *this;
}

const IVec& Vec2D::operator-=(const IVec& v1){
	*this = *this - v1;
	return *this;
}

const bool Vec2D::operator==(const IVec& v1){
	if (x == v1.get_x() && y == v1.get_y()) return true;
	return false;
}

const bool Vec2D::operator!=(const IVec& v1){
	return !(*this == v1);
}

const bool Vec2D::operator<(const IVec& v1){
	if (find_quadrant(this) < find_quadrant(&v1)) return true;
	if (magnitude() < v1.magnitude()) return true;
	return false;
}

const bool Vec2D::operator<=(const IVec& v1){
	return !(*this > v1);
}

const bool Vec2D::operator>(const IVec& v1){
	if (find_quadrant(this) > find_quadrant(&v1)) return true;
	if (magnitude() > v1.magnitude()) return true;
	return false;
}

const bool Vec2D::operator>=(const IVec& v1){
	return !(*this < v1);
}
