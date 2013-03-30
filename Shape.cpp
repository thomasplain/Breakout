#include "Shape.h"

bool collision(const Shape& s1, const Shape& s2){
	if (!s1.collision_check(s2)) return false;
	if (!s2.collision_check(s1)) return false;
	return true;
}

Vec2D nudge(Shape& s1, Shape& s2){
	Vec2D nv1 = s1.nudge(s2);
	Vec2D nv2 = s2.nudge(s1);
	return (nv1.magnitude() < nv2.magnitude()) ?  nv1 : nv2;
}
