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
const Vec2D Vec2D::normalise() const{
	return Vec2D(x/magnitude(), y/magnitude());
}

// Returns vector rotated by 90 degrees
const Vec2D Vec2D::normal() const{
	return Vec2D(-y, x);
}

float Vec2D::dot(const Vec2D v) const{
	return x * v.get_x() + y * v.get_y();
}

Vec2D Vec2D::project(Vec2D axis) const{
	float scale = dot(axis)/axis.magnitude();
	Vec2D direction(axis.normalise());
	direction *= scale;
	return direction;
}

void Vec2D::rotate(float angle){
	float xtemp = x * cos(angle) + y * sin(angle);
	float ytemp = -x * sin(angle) + y * cos(angle);
	x = xtemp;
	y = ytemp;
}

const Vec2D Vec2D::operator*(const Vec2D& v1) const{
	return	Vec2D(x * v1.get_x(), y * v1.get_y());
}

const Vec2D Vec2D::operator*(float f) const{
	return Vec2D(x * f, y * f);
}

const Vec2D Vec2D::operator+(const Vec2D& v1) const{
	return	Vec2D(x + v1.get_x(), y + v1.get_y());
}

const Vec2D Vec2D::operator-(const Vec2D& v1) const{
	return	Vec2D(x - v1.get_x(), y - v1.get_y());
}

const Vec2D Vec2D::operator*=(const Vec2D& v1){
	*this = *this * v1;
	return *this;
}

const Vec2D Vec2D::operator*=(const float& f){
	*this = *this * f;
	return *this;
}
const Vec2D Vec2D::operator+=(const Vec2D& v1){
	*this = *this + v1;
	return *this;
}

const Vec2D Vec2D::operator-=(const Vec2D& v1){
	*this = *this - v1;
	return *this;
}

const bool Vec2D::operator==(const Vec2D& v1){
	if (x == v1.get_x() && y == v1.get_y()) return true;
	return false;
}

const bool Vec2D::operator!=(const Vec2D& v1){
	return !(*this == v1);
}

const bool Vec2D::operator<(const Vec2D& v1){
	if (y < v1.get_y()) return true;
	if (y == v1.get_y() && x < v1.get_x()) return true;
	return false;
}

const bool Vec2D::operator<=(const Vec2D& v1){
	return !(*this > v1);
}

const bool Vec2D::operator>(const Vec2D& v1){
	if (y > v1.get_y()) return true;
	if (y == v1.get_y() && x > v1.get_x()) return true;
	return false;
}

const bool Vec2D::operator>=(const Vec2D& v1){
	return !(*this < v1);
}

std::ostream& operator<<(std::ostream& o, const Vec2D& v){
	o << "x = " << v.x << std::endl;
	o << "y = " << v.y << std::endl;
	return o;
}
